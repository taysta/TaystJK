/*
 * JKBot throughput benchmark timers (simulator only). See README.md in this directory.
 *
 * With jkbot_bench 1 (P1-BEN-01/02), counts:
 *   - each STEP's wall time on CLOCK_MONOTONIC (lockstep.cpp: SV_Frame, the agents' client
 *     frames and the export), and the game frames run;
 *   - the time spent in Ghoul2: every G2API_* entry of the renderer's export table (re) is wrapped,
 *     and re is how the server reaches Ghoul2: the original game module's G_G2_* syscalls
 *     (SV_G2API_*), a rebuilt module's import table, and SV_Trace's Ghoul2 collision. Only the
 *     outermost call is timed.
 * The wrappers only time and forward: the arguments and results are the renderer's own.
 *
 *   jkbot_bench_report   prints "jkbot_bench steps= frames= wall_ns= g2_ns= g2_calls= timer_ns="
 *                        for the counts since the last report, then zeroes them; timer_ns is the
 *                        cost of one clock read, so the timers' own share can be bounded
 * The bridge prints the same line when the env disconnects.
 */
#ifdef JKBOT_AGENT

#include <time.h>

#include "server/server.h"
#include "jkbot_agent.h"

static cvar_t *jkbot_bench;
static int64_t benchSteps, benchFrames, benchWallNs, benchG2Ns, benchG2Calls;
static int g2Depth;

int64_t JKBot_BenchNow( void ) {
#ifdef __linux__
	struct timespec ts;
	clock_gettime( CLOCK_MONOTONIC, &ts );
	return (int64_t)ts.tv_sec * 1000000000 + ts.tv_nsec;
#else
	return 0;
#endif
}

static qboolean Enabled( void ) {
	return (qboolean)( jkbot_bench && jkbot_bench->integer );
}

void JKBot_BenchStep( int64_t start ) {
	if ( Enabled() ) {
		benchWallNs += JKBot_BenchNow() - start;
		benchSteps++;
	}
}

void JKBot_BenchGameFrame( void ) {
	if ( Enabled() ) {
		benchFrames++;
	}
}

// ---- Ghoul2 API wrappers ----

namespace {

struct G2Timer {
	int64_t start;
	G2Timer() : start( g2Depth++ == 0 && Enabled() ? JKBot_BenchNow() : 0 ) {}
	~G2Timer() {
		if ( --g2Depth == 0 && start ) {
			benchG2Ns += JKBot_BenchNow() - start;
			benchG2Calls++;
		}
	}
};

refexport_t renderer;  // the renderer's own table
refexport_t wrapped;  // what re points at

template <typename F> struct Timed;
template <typename R, typename... A> struct Timed<R (*)( A... )> {
	typedef R ( *Fn )( A... );
	template <Fn refexport_t::*M> static R Call( A... a ) {
		G2Timer t;
		return ( renderer.*M )( a... );
	}
};

}  // namespace

#define JKB_G2API_ENTRIES \
	X( G2API_AddBolt ) \
	X( G2API_AddBoltSurfNum ) \
	X( G2API_AddSurface ) \
	X( G2API_AnimateG2ModelsRag ) \
	X( G2API_AttachEnt ) \
	X( G2API_AttachG2Model ) \
	X( G2API_AttachInstanceToEntNum ) \
	X( G2API_AbsurdSmoothing ) \
	X( G2API_BoltMatrixReconstruction ) \
	X( G2API_BoltMatrixSPMethod ) \
	X( G2API_CleanEntAttachments ) \
	X( G2API_CleanGhoul2Models ) \
	X( G2API_ClearAttachedInstance ) \
	X( G2API_CollisionDetect ) \
	X( G2API_CollisionDetectCache ) \
	X( G2API_CopyGhoul2Instance ) \
	X( G2API_CopySpecificG2Model ) \
	X( G2API_DetachG2Model ) \
	X( G2API_DoesBoneExist ) \
	X( G2API_DuplicateGhoul2Instance ) \
	X( G2API_FreeSaveBuffer ) \
	X( G2API_GetAnimFileName ) \
	X( G2API_GetAnimFileNameIndex ) \
	X( G2API_GetAnimRange ) \
	X( G2API_GetBoltMatrix ) \
	X( G2API_GetBoneAnim ) \
	X( G2API_GetBoneIndex ) \
	X( G2API_GetGhoul2ModelFlags ) \
	X( G2API_GetGLAName ) \
	X( G2API_GetModelName ) \
	X( G2API_GetParentSurface ) \
	X( G2API_GetRagBonePos ) \
	X( G2API_GetSurfaceIndex ) \
	X( G2API_GetSurfaceName ) \
	X( G2API_GetSurfaceOnOff ) \
	X( G2API_GetSurfaceRenderStatus ) \
	X( G2API_GetTime ) \
	X( G2API_Ghoul2Size ) \
	X( G2API_GiveMeVectorFromMatrix ) \
	X( G2API_HasGhoul2ModelOnIndex ) \
	X( G2API_HaveWeGhoul2Models ) \
	X( G2API_IKMove ) \
	X( G2API_InitGhoul2Model ) \
	X( G2API_IsGhoul2InfovValid ) \
	X( G2API_IsPaused ) \
	X( G2API_ListBones ) \
	X( G2API_ListSurfaces ) \
	X( G2API_LoadGhoul2Models ) \
	X( G2API_LoadSaveCodeDestructGhoul2Info ) \
	X( G2API_OverrideServerWithClientData ) \
	X( G2API_PauseBoneAnim ) \
	X( G2API_PrecacheGhoul2Model ) \
	X( G2API_RagEffectorGoal ) \
	X( G2API_RagEffectorKick ) \
	X( G2API_RagForceSolve ) \
	X( G2API_RagPCJConstraint ) \
	X( G2API_RagPCJGradientSpeed ) \
	X( G2API_RemoveBolt ) \
	X( G2API_RemoveBone ) \
	X( G2API_RemoveGhoul2Model ) \
	X( G2API_RemoveGhoul2Models ) \
	X( G2API_RemoveSurface ) \
	X( G2API_ResetRagDoll ) \
	X( G2API_SaveGhoul2Models ) \
	X( G2API_SetBoltInfo ) \
	X( G2API_SetBoneAngles ) \
	X( G2API_SetBoneAnglesIndex ) \
	X( G2API_SetBoneAnglesMatrix ) \
	X( G2API_SetBoneAnglesMatrixIndex ) \
	X( G2API_SetBoneAnim ) \
	X( G2API_SetBoneAnimIndex ) \
	X( G2API_SetBoneIKState ) \
	X( G2API_SetGhoul2ModelFlags ) \
	X( G2API_SetGhoul2ModelIndexes ) \
	X( G2API_SetLodBias ) \
	X( G2API_SetNewOrigin ) \
	X( G2API_SetRagDoll ) \
	X( G2API_SetRootSurface ) \
	X( G2API_SetShader ) \
	X( G2API_SetSkin ) \
	X( G2API_SetSurfaceOnOff ) \
	X( G2API_SetTime ) \
	X( G2API_SkinlessModel ) \
	X( G2API_StopBoneAngles ) \
	X( G2API_StopBoneAnglesIndex ) \
	X( G2API_StopBoneAnim ) \
	X( G2API_StopBoneAnimIndex ) \
	X( G2API_GetNumGoreMarks ) \
	X( G2API_AddSkinGore ) \
	X( G2API_ClearSkinGore ) \

refexport_t *JKBot_BenchWrapRef( refexport_t *ref ) {
	renderer = *ref;
	wrapped = *ref;
#define X( name ) wrapped.name = &Timed<decltype( renderer.name )>::template Call<&refexport_t::name>;
	JKB_G2API_ENTRIES
#undef X
	return &wrapped;
}

// ---- report ----

static double TimerNs( void ) {
	const int n = 100000;
	const int64_t t0 = JKBot_BenchNow();
	int64_t sink = 0;
	for ( int i = 0; i < n; i++ ) {
		sink += JKBot_BenchNow();
	}
	const int64_t t1 = JKBot_BenchNow();
	return sink ? (double)( t1 - t0 ) / n : 0.0;
}

void JKBot_BenchReport( void ) {
	Com_Printf( "jkbot_bench steps=%lld frames=%lld wall_ns=%lld g2_ns=%lld g2_calls=%lld timer_ns=%.1f\n",
		(long long)benchSteps, (long long)benchFrames, (long long)benchWallNs, (long long)benchG2Ns,
		(long long)benchG2Calls, TimerNs() );
	benchSteps = benchFrames = benchWallNs = benchG2Ns = benchG2Calls = 0;
}

void JKBot_BenchInit( void ) {
	jkbot_bench = Cvar_Get( "jkbot_bench", "0", 0, "JKBot throughput timers: STEP wall time and Ghoul2 API time (agent builds only)" );
	Cmd_AddCommand( "jkbot_bench_report", JKBot_BenchReport, "JKBot: print and zero the throughput timers (agent builds only)" );
}

#endif // JKBOT_AGENT
