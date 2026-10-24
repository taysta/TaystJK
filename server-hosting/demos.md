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
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L2343)):

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

## Record a player

A server-side demo follows one player, so start by finding their client number. In the
server console, `status` lists everyone connected, and its `cl` column is the number the
recording commands take
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1196)).
To record player `3`:

```text
status
svrecord match-01 3
sv_listrecording
svstoprecord 3
```

`sv_listrecording` prints each running recording as its client number and demo name
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1735)).
This one is saved as `demos/match-01.dm_26`
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1776));
`26` is the protocol number, which `status` also prints on its `game` line
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1191)).
Recording to a name that already exists replaces that demo.

Both arguments are optional:

- Without a client number, `svrecord` records the first client, bots included, that is
  fully in the game and not already being recorded
  ([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L2112)).
  A number only counts after a name, so `svrecord 3` records a demo *named* `3` of
  whoever that is.
- Without a name as well, the demo gets a timestamped one such as
  `demo2026-09-28_14-05-00`
  ([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1752)).
- Without a client number, `svstoprecord` stops the first recording in client-number order
  ([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1684)),
  so give the number whenever more than one is running.

A player who is still connecting or loading cannot be recorded yet; the server answers
`Client is not active.`
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L2141)).

## Recording every player automatically

[`sv_autoDemo`](/TaystJK/reference/?q=sv_autoDemo) records a demo of every player without
anyone typing a command
([`sv_init.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_init.cpp#L1038)):

| Setting | Does |
|:--|:--|
| `sv_autoDemo 1` | Records one demo per player, from when they enter the game or the map loads until the map ends. Bots are skipped unless `sv_autoDemoBots` is `1`. |
| `sv_autoDemo 2` | Records only a spectating bot named `RECORDER`, and only while at least one human is on the server. Pair it with a game module that sends spectators every player's information, and one demo covers the whole match. |
| `sv_autoDemoMaxMaps` | Keeps the demos of this many maps and deletes older ones. `0` keeps everything. |

The demos go under `demos/autorecord/`, in a folder per day and per map, and each file is
named after the client number, player, map and time
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1929)).
The shipped `server.cfg` leaves `sv_autoDemo` off and sets `sv_autoDemoMaxMaps 50`, so turning
it on keeps the last fifty maps. Every player's demo is written for every map, so watch the
disk.

## Automatic race demos

TaystJK's bundled jaPRO game module can record race runs by itself when `sv_autoRaceDemo` is
on, and the Docker image's [`server.cfg`](/TaystJK/server-hosting/bundled-configs/) turns it
on. Each run by a player logged in to an account is recorded into `demos/temp/`
([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_trigger.c#L1489)), and a run that sets that player's
personal best on the course is kept as `demos/races/<account>/<account>-<course>-<style>`
([`g_account.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_account.c#L2104)). Keep an eye on disk space on a busy
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

With pre-recording on, `svrecord` starts the demo from the oldest full snapshot still
buffered for that player rather than from the moment you type it. If there is none yet, it
starts from the moment you type it, as it would without pre-recording
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_ccmds.cpp#L1827)).

Buffering runs per connected client, so the memory cost scales with your player count as
well as with the time window. Raise `sv_demoPreRecordTime` with that in mind.

`sv_demoWriteMeta` controls whether the metadata set by `svdemometa` and by the game
module is written into the demo. It is on by default and invisible to ordinary playback;
the shipped `server.cfg` turns it off.
