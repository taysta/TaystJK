---
title: "Server-side demos"
layout: reference
nav_order: 3
parent: "Server hosting"
description: "Record demos on the dedicated server itself, including a rolling pre-record buffer and the jaPRO game module's automatic race demos."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# Server-side demos

<p class="page-lede">The dedicated server can record demos of any player, on demand or retroactively, independently of anything the players do.</p>
</div>

## Recording commands

The recording commands exist only in the dedicated build
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_ccmds.cpp#L2343)):

| Command | Does |
|:--|:--|
| `svrecord` | Start recording |
| `svstoprecord` | Stop recording |
| `sv_listrecording` | List what is currently being recorded |
| `svrenamedemo` | Rename a recorded demo |
| `svdemometa` | Attach a metadata entry for one player: clientnum, key, value |
| `svdemoclearmeta` | Clear one player's metadata |
| `svdemoclearprerecord` | Discard one player's buffered pre-record data |

Demos are written under `demos/` in the server's game directory.

## Automatic race demos

TaystJK's bundled jaPRO game module can record race runs by itself when `sv_autoRaceDemo` is
on, and the Docker image's [`server.cfg`](/TaystJK/server-hosting/bundled-configs/) turns it
on. Each run by a player logged in to an account is recorded into `demos/temp/`
([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L1489)), and a run that sets that player's
personal best on the course is kept as `demos/races/<account>/<account>-<course>-<style>`
([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2104)). Keep an eye on disk space on a busy
race server.

## Pre-recording

The problem with recording on demand is that the interesting thing has already happened by
the time you type the command. Pre-recording keeps a rolling buffer so a demo can be
started *retroactively*.

```text
seta sv_demoPreRecord 1
seta sv_demoPreRecordTime 15
```

`sv_demoPreRecordTime` is how many seconds are kept. A demo can only begin from a full
snapshot, so the server periodically stores one; `sv_demoPreRecordKeyframeDistance` controls
how often, in seconds. A larger gap costs less memory and coarsens how far back a demo can
actually start. `sv_demoPreRecordBots` extends the buffer to bots, which is off by default
because it is usually wasted work.

Buffering runs per connected client, so the memory cost scales with your player count as
well as with the time window. Raise `sv_demoPreRecordTime` deliberately.

`sv_demoWriteMeta` controls whether the metadata set by `svdemometa` and by the game
module is written into the demo. It is on by default and invisible to ordinary playback;
the shipped `server.cfg` turns it off.
