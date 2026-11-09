/*
===========================================================================
Copyright (C) 2026, TaystJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

// snd_voice.cpp -- positional VoIP voice streams
//
// Each talking entity gets a stream of mono 16-bit samples at VOIP_RATE.
// Streams are played at the entity's position by both sound backends and
// drive the existing FACE_TALK lip sync through s_entityWavVol.
//
// cl_voip.cpp feeds decoded network voice (and the local loopback test) in
// through S_Voip_Write.

#include "snd_local.h"

#define VOIP_RATE				VOIP_SAMPLE_RATE
#define VOIP_RING_SAMPLES		65536			// ~1.4 s at 48 kHz, must be a power of two
#define VOIP_RING_MASK			(VOIP_RING_SAMPLES - 1)
#define VOIP_MAX_STREAMS		MAX_CLIENTS
#define VOIP_IDLE_MSEC			1000			// stream is released this long after it ran dry
#define VOIP_TALKING_MSEC		300				// still "talking" (lips at rest, -1) this long after data stops
#define VOIP_LIPSYNC_WINDOW		1024			// samples measured around the play position
#define VOIP_LIPSYNC_MIN_PEAK	24.0f			// floor for the level reference so room noise stays shut-mouthed
#define VOIP_LIPSYNC_DECAY_MSEC	3000.0f

#ifdef USE_OPENAL
#define VOIP_AL_MAX_BUFFERS		128
#define VOIP_AL_MIN_CHUNK		480				// 10 ms; smaller writes wait for more data
#endif

extern int			s_entityWavVol[MAX_GENTITIES];
extern vec3_t		s_entityPosition[MAX_GENTITIES];
extern int			listener_number;
extern matrix3_t	listener_axis;
extern int			s_soundtime;
extern int			s_UseOpenAL;
extern cvar_t		*s_mixPreStep;
extern cvar_t		*s_lip_threshold_1;
extern cvar_t		*s_lip_threshold_2;
extern cvar_t		*s_lip_threshold_3;
extern cvar_t		*s_lip_threshold_4;

typedef struct voipStream_s {
	qboolean	active;
	int			entnum;
	short		ring[VOIP_RING_SAMPLES];
	int64_t		writePos;			// total samples written
	int			lastWriteTime;		// Sys_Milliseconds of the last write
	voipSource_t source;			// from the latest write

	// software mixer: native sample anchorPos plays at dma sample time anchorTime
	qboolean	dmaAnchored;
	int64_t		dmaAnchorPos;
	int			dmaAnchorTime;

	// lip sync level reference, like sfx_t::fVolRange but decaying
	float		peak;
	int			peakTime;

#ifdef USE_OPENAL
	ALuint		alSource;
	qboolean	alHasSource;
	int			alSlotID;
	int64_t		alQueuedPos;
	struct {
		ALuint	buffer;
		int64_t	startPos;
	} alQueue[VOIP_AL_MAX_BUFFERS];
	int			alQueueHead;
	int			alQueueCount;
#endif
} voipStream_t;

static voipStream_t	*s_voipStreams;		// [VOIP_MAX_STREAMS], allocated in S_Voip_Init
static int			s_voipListener = -1;
static vec3_t		s_voipListenerOrigin;

static cvar_t		*s_voipVolume;
static cvar_t		*s_voipRange;
static cvar_t		*s_voipFullRange;
static cvar_t		*s_voipLatency;

/*
===============================================================================

Streams

===============================================================================
*/

static int S_Voip_LatencySamples(int rate)
{
	return (int)(Com_Clamp(0.0f, 1.0f, s_voipLatency->value) * rate);
}

static voipStream_t *S_Voip_FindStream(int entnum)
{
	for (int i = 0; i < VOIP_MAX_STREAMS; i++)
	{
		if (s_voipStreams[i].active && s_voipStreams[i].entnum == entnum)
			return &s_voipStreams[i];
	}
	return NULL;
}

#ifdef USE_OPENAL
static void S_Voip_ALUnqueueProcessed(voipStream_t *vs)
{
	ALint processed = 0;

	alGetSourcei(vs->alSource, AL_BUFFERS_PROCESSED, &processed);
	while (processed-- > 0 && vs->alQueueCount > 0)
	{
		ALuint buffer;
		alSourceUnqueueBuffers(vs->alSource, 1, &buffer);
		alDeleteBuffers(1, &buffer);
		vs->alQueueHead = (vs->alQueueHead + 1) % VOIP_AL_MAX_BUFFERS;
		vs->alQueueCount--;
	}
}

static void S_Voip_ALRelease(voipStream_t *vs)
{
	if (!vs->alHasSource)
		return;

	alSourceStop(vs->alSource);
	S_Voip_ALUnqueueProcessed(vs);
	alSourcei(vs->alSource, AL_BUFFER, 0);
	while (vs->alQueueCount > 0)
	{
		alDeleteBuffers(1, &vs->alQueue[vs->alQueueHead].buffer);
		vs->alQueueHead = (vs->alQueueHead + 1) % VOIP_AL_MAX_BUFFERS;
		vs->alQueueCount--;
	}
	alDeleteSources(1, &vs->alSource);
	vs->alHasSource = qfalse;
}
#endif

static void S_Voip_ReleaseStream(voipStream_t *vs)
{
#ifdef USE_OPENAL
	S_Voip_ALRelease(vs);
#endif
	vs->active = qfalse;
}

static voipStream_t *S_Voip_AllocStream(int entnum)
{
	voipStream_t *vs = NULL;

	for (int i = 0; i < VOIP_MAX_STREAMS; i++)
	{
		if (!s_voipStreams[i].active)
		{
			vs = &s_voipStreams[i];
			break;
		}
	}

	if (!vs)
		return NULL;

	vs->active = qtrue;
	vs->entnum = entnum;
	vs->writePos = 0;
	vs->lastWriteTime = Sys_Milliseconds();
	vs->dmaAnchored = qfalse;
	vs->peak = VOIP_LIPSYNC_MIN_PEAK;
	vs->peakTime = vs->lastWriteTime;

#ifdef USE_OPENAL
	vs->alHasSource = qfalse;
	vs->alQueuedPos = 0;
	vs->alQueueHead = 0;
	vs->alQueueCount = 0;
	vs->alSlotID = -1;

	if (s_UseOpenAL)
	{
		alGetError();
		alGenSources(1, &vs->alSource);
		if (alGetError() != AL_NO_ERROR)
		{
			Com_DPrintf("S_Voip: no free OpenAL source for entity %i\n", entnum);
			vs->active = qfalse;
			return NULL;
		}
		vs->alHasSource = qtrue;

		// distance falloff is applied through AL_GAIN so both backends sound the same;
		// OpenAL only does direction (and HRTF when enabled)
		alSourcef(vs->alSource, AL_ROLLOFF_FACTOR, 0.0f);
		alSourcei(vs->alSource, AL_LOOPING, AL_FALSE);
		alSourcef(vs->alSource, AL_GAIN, 0.0f);
	}
#endif

	return vs;
}

// Current play position in native samples, or -1 when nothing is playing yet.
static int64_t S_Voip_PlayPos(voipStream_t *vs)
{
#ifdef USE_OPENAL
	if (s_UseOpenAL)
	{
		if (!vs->alHasSource || !vs->alQueueCount)
			return -1;

		ALint state = AL_STOPPED;
		ALint offset = 0;
		alGetSourcei(vs->alSource, AL_SOURCE_STATE, &state);
		if (state != AL_PLAYING)
			return -1;
		alGetSourcei(vs->alSource, AL_SAMPLE_OFFSET, &offset);
		return vs->alQueue[vs->alQueueHead].startPos + offset;
	}
#endif

	if (!vs->dmaAnchored || !dma.speed)
		return -1;
	if (s_soundtime < vs->dmaAnchorTime)
		return -1;
	return vs->dmaAnchorPos + ((int64_t)(s_soundtime - vs->dmaAnchorTime) * VOIP_RATE) / dma.speed;
}

void S_Voip_Write(int entnum, const short *samples, int count, const voipSource_t *source)
{
	voipStream_t *vs;

	if (!s_voipStreams || entnum < 0 || entnum >= MAX_GENTITIES || count <= 0)
		return;

	vs = S_Voip_FindStream(entnum);
	if (!vs)
	{
		vs = S_Voip_AllocStream(entnum);
		if (!vs)
			return;
	}

	if (!s_UseOpenAL && dma.speed)
	{
		// Start (or restart after running dry) a little ahead of what the mixer repaints,
		// so the first samples aren't cut and network jitter has some slack.
		const int64_t playPos = S_Voip_PlayPos(vs);
		const qboolean ranDry = (qboolean)(!vs->dmaAnchored || playPos >= vs->writePos);
		const qboolean tooFarBehind = (qboolean)(playPos >= 0 && vs->writePos - playPos > VOIP_RING_SAMPLES / 2);
		const qboolean timeWrapped = (qboolean)(vs->dmaAnchored && vs->dmaAnchorTime - s_soundtime > dma.speed * 2);

		if (ranDry || tooFarBehind || timeWrapped)
		{
			if (vs->dmaAnchored)
				Com_DPrintf("S_Voip: entity %i %s, restarting playback\n", entnum, ranDry ? "ran dry" : "drifted");
			vs->dmaAnchored = qtrue;
			vs->dmaAnchorPos = vs->writePos;
			vs->dmaAnchorTime = s_soundtime
				+ (int)(s_mixPreStep->value * dma.speed)
				+ S_Voip_LatencySamples(dma.speed);
		}
	}

	if (count > VOIP_RING_SAMPLES)
	{
		samples += count - VOIP_RING_SAMPLES;
		count = VOIP_RING_SAMPLES;
	}

	for (int i = 0; i < count; i++)
		vs->ring[(vs->writePos + i) & VOIP_RING_MASK] = samples[i];

	vs->writePos += count;
	vs->lastWriteTime = Sys_Milliseconds();

	if (source)
	{
		vs->source = *source;
	}
	else
	{
		memset(&vs->source, 0, sizeof(vs->source));
		vs->source.range = -1.0f;
	}
}

void S_Voip_ClearStreams(void)
{
	if (!s_voipStreams)
		return;

	for (int i = 0; i < VOIP_MAX_STREAMS; i++)
	{
		if (s_voipStreams[i].active)
			S_Voip_ReleaseStream(&s_voipStreams[i]);
	}
}

void S_Voip_Respatialize(int entityNum, const vec3_t head)
{
	s_voipListener = entityNum;
	VectorCopy(head, s_voipListenerOrigin);
}

// Plays centred at full volume: our own view entity, or spectator chat.
static qboolean S_Voip_AtListener(const voipStream_t *vs)
{
	return (qboolean)(vs->source.nonSpatial || vs->entnum == s_voipListener);
}

// The entity's lerped position while it's in our snapshot, otherwise where
// the server says the speaker is.
static const float *S_Voip_Origin(const voipStream_t *vs)
{
	return vs->source.useOrigin ? vs->source.origin : s_entityPosition[vs->entnum];
}

static float S_Voip_DistanceGain(const voipStream_t *vs)
{
	if (S_Voip_AtListener(vs))
		return 1.0f;

	const float dist = Distance(S_Voip_Origin(vs), s_voipListenerOrigin);
	const float full = Q_max(0.0f, s_voipFullRange->value);
	// the server's relay range wins so voices fade out right where it stops sending
	const float range = vs->source.range >= 0.0f ? vs->source.range : s_voipRange->value;

	if (range <= 0.0f)
		return 1.0f;		// no proximity, everyone at full volume
	if (dist <= full)
		return 1.0f;
	if (dist >= range || range <= full)
		return 0.0f;

	const float frac = 1.0f - (dist - full) / (range - full);
	return frac * frac;
}

static qboolean S_Voip_StreamIdle(voipStream_t *vs, int now)
{
	if (now - vs->lastWriteTime < VOIP_IDLE_MSEC)
		return qfalse;

#ifdef USE_OPENAL
	if (s_UseOpenAL)
		return (qboolean)(S_Voip_PlayPos(vs) < 0);
#endif

	return (qboolean)(S_Voip_PlayPos(vs) >= vs->writePos);
}

/*
===============================================================================

Software mixer

===============================================================================
*/

void S_Voip_PaintChannels(portable_samplepair_t *paint, int start, int end)
{
	if (!s_voipStreams || !dma.speed)
		return;

	const int voipVol = (int)(volume->value * s_volumeVoice->value * s_voipVolume->value * 256);
	if (voipVol <= 0)
		return;

	for (int i = 0; i < VOIP_MAX_STREAMS; i++)
	{
		voipStream_t *vs = &s_voipStreams[i];

		if (!vs->active || !vs->dmaAnchored)
			continue;

		// spatialize like S_SpatializeOrigin, but with the voip falloff
		float lscale = 1.0f, rscale = 1.0f;
		const float gain = S_Voip_DistanceGain(vs);

		if (gain <= 0.0f)
			continue;

		if (!S_Voip_AtListener(vs) && vs->entnum != listener_number && dma.channels > 1)
		{
			vec3_t dir;
			VectorSubtract(S_Voip_Origin(vs), listener_origin, dir);
			VectorNormalize(dir);
			const float dot = -DotProduct(listener_axis[1], dir);
			rscale = Q_max(0.0f, s_separation->value + (1.0f - s_separation->value) * dot);
			lscale = Q_max(0.0f, s_separation->value - (1.0f - s_separation->value) * dot);
		}

		const int leftvol = (int)(255 * gain * lscale) * voipVol;
		const int rightvol = (int)(255 * gain * rscale) * voipVol;

		for (int t = Q_max(start, vs->dmaAnchorTime); t < end; t++)
		{
			const int64_t num = (int64_t)(t - vs->dmaAnchorTime) * VOIP_RATE;
			const int64_t pos = vs->dmaAnchorPos + num / dma.speed;

			if (pos >= vs->writePos)
				break;
			if (pos < vs->writePos - VOIP_RING_SAMPLES)
				continue;

			// linear interpolation from VOIP_RATE to the output rate
			int sample = vs->ring[pos & VOIP_RING_MASK];
			if (pos + 1 < vs->writePos)
			{
				const int frac = (int)(((num % dma.speed) << 8) / dma.speed);
				sample += ((vs->ring[(pos + 1) & VOIP_RING_MASK] - sample) * frac) >> 8;
			}

			// 64-bit: s_voipVolume above 1 can overflow sample * vol
			paint[t - start].left += (int)(((int64_t)sample * leftvol) >> 8);
			paint[t - start].right += (int)(((int64_t)sample * rightvol) >> 8);
		}
	}
}

/*
===============================================================================

OpenAL

===============================================================================
*/

#ifdef USE_OPENAL
static void S_Voip_ALQueue(voipStream_t *vs, int now)
{
	static short chunk[VOIP_RING_SAMPLES];
	int64_t avail = vs->writePos - vs->alQueuedPos;

	if (avail > VOIP_RING_SAMPLES)
	{
		// fell behind the ring: skip to the newest data
		vs->alQueuedPos = vs->writePos - VOIP_RING_SAMPLES / 2;
		avail = vs->writePos - vs->alQueuedPos;
	}

	// batch tiny per-frame writes, unless the stream has paused
	if (avail <= 0 || (avail < VOIP_AL_MIN_CHUNK && now - vs->lastWriteTime < 50))
		return;
	if (vs->alQueueCount >= VOIP_AL_MAX_BUFFERS)
		return;

	for (int64_t i = 0; i < avail; i++)
		chunk[i] = vs->ring[(vs->alQueuedPos + i) & VOIP_RING_MASK];

	ALuint buffer;
	alGetError();
	alGenBuffers(1, &buffer);
	if (alGetError() != AL_NO_ERROR)
		return;
	alBufferData(buffer, AL_FORMAT_MONO16, chunk, (ALsizei)(avail * sizeof(short)), VOIP_RATE);
	alSourceQueueBuffers(vs->alSource, 1, &buffer);

	const int slot = (vs->alQueueHead + vs->alQueueCount) % VOIP_AL_MAX_BUFFERS;
	vs->alQueue[slot].buffer = buffer;
	vs->alQueue[slot].startPos = vs->alQueuedPos;
	vs->alQueueCount++;
	vs->alQueuedPos = vs->writePos;
}

void S_Voip_UpdateAL(void)
{
	if (!s_voipStreams)
		return;

	const int now = Sys_Milliseconds();
	const float voipVol = s_volumeVoice->value * s_voipVolume->value;

	for (int i = 0; i < VOIP_MAX_STREAMS; i++)
	{
		voipStream_t *vs = &s_voipStreams[i];

		if (!vs->active || !vs->alHasSource)
			continue;

		S_Voip_ALUnqueueProcessed(vs);
		S_Voip_ALQueue(vs, now);

		// position
		const qboolean atListener = S_Voip_AtListener(vs);
		if (atListener)
		{
			const ALfloat pos[3] = { 0.0f, 0.0f, 0.0f };
			alSourcei(vs->alSource, AL_SOURCE_RELATIVE, AL_TRUE);
			alSourcefv(vs->alSource, AL_POSITION, pos);
		}
		else
		{
			const float *origin = S_Voip_Origin(vs);
			const ALfloat pos[3] = { origin[0], origin[2], -origin[1] };
			alSourcei(vs->alSource, AL_SOURCE_RELATIVE, AL_FALSE);
			alSourcefv(vs->alSource, AL_POSITION, pos);
		}
		alSourcef(vs->alSource, AL_GAIN, S_Voip_DistanceGain(vs) * voipVol);
		S_AL_UpdateSourceEAX(vs->alSource, &vs->alSlotID, S_Voip_Origin(vs), atListener);

		// (re)start once enough is buffered, or the talker paused with a short tail
		ALint state = AL_STOPPED;
		alGetSourcei(vs->alSource, AL_SOURCE_STATE, &state);
		if (state != AL_PLAYING && vs->alQueueCount > 0)
		{
			const int64_t buffered = vs->alQueuedPos - vs->alQueue[vs->alQueueHead].startPos;
			if (buffered >= S_Voip_LatencySamples(VOIP_RATE) || now - vs->lastWriteTime > 100)
			{
				Com_DPrintf("S_Voip: entity %i starting playback (%i ms buffered)\n", vs->entnum, (int)(buffered * 1000 / VOIP_RATE));
				alSourcePlay(vs->alSource);
			}
		}
	}
}
#endif

/*
===============================================================================

Lip sync

Same level buckets as S_CheckAmplitude: mean square of (sample >> 8) against
the level reference times s_threshold1..4.

===============================================================================
*/

static int S_Voip_LipLevel(voipStream_t *vs, int now)
{
	const int64_t playPos = S_Voip_PlayPos(vs);
	const int64_t oldest = Q_max((int64_t)0, vs->writePos - VOIP_RING_SAMPLES);
	int64_t from = playPos - VOIP_LIPSYNC_WINDOW / 2;
	int64_t to = playPos + VOIP_LIPSYNC_WINDOW / 2;

	if (playPos < 0 || playPos >= vs->writePos)
	{
		// between bursts: mouth at rest but still "talking" so the face doesn't idle
		return (now - vs->lastWriteTime < VOIP_TALKING_MSEC) ? -1 : 0;
	}

	from = Q_max(from, oldest);
	to = Q_min(to, vs->writePos);

	int total = 0, count = 0, blockPeak = 0;
	for (int64_t p = from; p < to; p += 8)
	{
		const int s = vs->ring[p & VOIP_RING_MASK] >> 8;
		total += s * s;
		blockPeak = Q_max(blockPeak, abs(s));
		count++;
	}
	if (!count)
		return -1;
	total /= count;

	// decaying peak so quiet talkers still open their mouths
	const float decay = Q_min(1.0f, (now - vs->peakTime) / VOIP_LIPSYNC_DECAY_MSEC);
	vs->peakTime = now;
	vs->peak -= vs->peak * decay;
	vs->peak = Q_max(vs->peak, (float)blockPeak);
	const float ref = Q_max(vs->peak, VOIP_LIPSYNC_MIN_PEAK);

	if (total < ref * s_lip_threshold_1->value)
		return -1;
	if (total < ref * s_lip_threshold_2->value)
		return 1;
	if (total < ref * s_lip_threshold_3->value)
		return 2;
	if (total < ref * s_lip_threshold_4->value)
		return 3;
	return 4;
}

// Called after the backend's own lip sync pass has rebuilt s_entityWavVol.
void S_Voip_UpdateLipSync(void)
{
	if (!s_voipStreams)
		return;

	const int now = Sys_Milliseconds();

	for (int i = 0; i < VOIP_MAX_STREAMS; i++)
	{
		voipStream_t *vs = &s_voipStreams[i];

		if (!vs->active)
			continue;

		if (S_Voip_StreamIdle(vs, now))
		{
			S_Voip_ReleaseStream(vs);
			continue;
		}

		const int level = S_Voip_LipLevel(vs, now);
		int *wavVol = &s_entityWavVol[vs->entnum];

		// a scripted voice sound on the same entity wins
		if (*wavVol <= 0 && level != 0)
			*wavVol = level;

		if (s_show->integer == 3 && level)
			Com_Printf("(%i) voip vol = %i gain %.2f\n", vs->entnum, level, S_Voip_DistanceGain(vs));
	}
}

/*
===============================================================================

Init / shutdown

===============================================================================
*/

void S_Voip_Init(void)
{
	s_voipVolume = Cvar_Get("s_voipVolume", "1.0", CVAR_ARCHIVE_ND, "Volume of other players' voice chat");
	Cvar_CheckRange(s_voipVolume, 0, 2, qfalse);
	s_voipRange = Cvar_Get("s_voipRange", "1200", CVAR_ARCHIVE_ND, "Distance at which local voice tests fade out (servers send their own range; 0 = no falloff)");
	s_voipFullRange = Cvar_Get("s_voipFullRange", "120", CVAR_ARCHIVE_ND, "Distance within which voice chat plays at full volume");
	s_voipLatency = Cvar_Get("s_voipLatency", "0.06", CVAR_ARCHIVE_ND, "Seconds of voice buffered before playback starts");

	if (!s_voipStreams)
		s_voipStreams = (voipStream_t *)Z_Malloc(sizeof(voipStream_t) * VOIP_MAX_STREAMS, TAG_SND_RAWDATA, qtrue);
}

void S_Voip_Shutdown(void)
{
	if (s_voipStreams)
	{
		S_Voip_ClearStreams();
		Z_Free(s_voipStreams);
		s_voipStreams = NULL;
	}
}
