---
title: "Feature flags"
layout: reference
parent: "Development"
nav_order: 4
description: "The serverinfo key a game module uses to tell TaystJK clients which optional features it supports, and the userinfo key clients use to tell the server what they can parse."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Server mod author guide</p>

# Feature flags

<p class="page-lede">TaystJK gates some client-side features on recognising the server as JA+ or jaPRO. <code>taystJKinfo</code> is how any other game module opts in to them individually, without pretending to be either, and <code>taystJKcgflags</code> is how the client tells the server which extended commands it can read.</p>
</div>

## The problem it solves

Several client features need the server to behave compatibly because they change movement
prediction, draw something the server also decides, or extend a server command. Rather than
run them everywhere and desync or misread the command, the client checks which mod the
server is running and enables them only where it knows they work. The ordering that check
uses, and what it costs you, is described on
[mod compatibility](/TaystJK/install/mod-compatibility/).

If your module supports one of these features but is not JA+ or jaPRO, that check would
turn it off. `taystJKinfo` is the override.

A server flag alone is not enough when a feature changes the layout of a command the server
sends. Every client reads serverinfo, including older TaystJK builds and other clients that
do not know the flag, and those would misread the new layout. For those features the client
also advertises support through [`taystJKcgflags`](#client-capabilities-taystjkcgflags), and
the server sends the extended layout only to clients that advertise it.

## Setting it

Put the bitmask in your serverinfo under the key `taystJKinfo`. The client reads it from the
gamestate on connect, and again whenever the serverinfo changes, so you can change flags while
the server runs
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_servercmds.c#L250)):

```c
Info_SetValueForKey( info, "taystJKinfo", va( "%i", flags ) );
```

Set only the bits you have actually implemented. A client that trusts a flag you do not
honour can mispredict or parse a server command with the wrong layout, which is worse for
the player than the feature being absent.

[A worked example](https://github.com/taysta/TaystJK/commit/79a50c73cbd1e1e8faf9f612049d8a206798a85c)
against OpenJK's game module, on the `ojk-cgflags` branch, shows the interface: declaring
every bit, setting `taystJKinfo`, and reading `taystJKcgflags` back from each client. It sets
every flag to show the declarations and does not implement the features behind them. Your
module should set only the bits it implements; [scoreboard deaths](#scoreboard-deaths) shows
what that one needs.

## The bits

Defined in
[`bg_public.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_public.h#L550):

| Bit | Value | Constant | Means |
|--:|--:|:--|:--|
| 0 | 1 | `TAYSTJK_INFO_RGBSABERS` | Sabers may use colours beyond the stock set. |
| 1 | 2 | `TAYSTJK_INFO_BLACKSABERS` | The black saber colour is permitted. |
| 2 | 4 | `TAYSTJK_INFO_FLIPKICK` | Flip kicks are supported. |
| 3 | 8 | `TAYSTJK_INFO_GRAPPLE` | The grapple hook behaves as JA+'s ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/4cca97d97551d2fda974e7fe7d5693f21900a2f3/codemp/game/bg_pmove.c#L15608)). Client builds from before 24 October 2026 ignore it. |
| 4 | 16 | `TAYSTJK_INFO_FIXROLL_1` | Rolling while using force grip. |
| 5 | 32 | `TAYSTJK_INFO_FIXROLL_2` | The above, plus chaining rolls. |
| 6 | 64 | `TAYSTJK_INFO_FIXROLL_3` | JK2-style rolling. |
| 7 | 128 | `TAYSTJK_INFO_SCORE_DEATHS` | The server appends each player's deaths to the `scores` command for clients that advertise support. See [scoreboard deaths](#scoreboard-deaths). |

The three roll bits are alternatives, not levels to combine. The client
tests them from 3 downwards and takes the first that matches
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_pmove.c#L314)).

## Client capabilities: `taystJKcgflags`

The TaystJK cgame registers `taystJKcgflags` as a read-only userinfo cvar, so it reaches the
server in the connect string and in every userinfo update
([`cg_xcvar.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_xcvar.h#L457)).
The cgame sets it to the capabilities it supports when it loads
([`cg_cvar.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_cvar.c#L288)),
and resets it to `0` when it shuts down, so a different cgame loaded later in the same
session does not inherit the claim
([`cg_main.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_main.c#L3339)).

Defined in
[`bg_public.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_public.h#L559):

| Bit | Value | Constant | Means |
|--:|--:|:--|:--|
| 0 | 1 | `TAYSTJK_CGFLAG_SCORE_DEATHS` | The cgame reads a deaths field appended to each player record in `scores`. |

Read it in `ClientUserinfoChanged`, which runs on connect and whenever the client sends new
userinfo:

```c
s = Info_ValueForKey( userinfo, "taystJKcgflags" );
client->pers.taystJKcgflags = atoi( s );
```

A missing key reads as `0`, which is the correct answer for every client that is not a
current TaystJK build. The value can change after connect: the cgame registers the cvar when
it loads, after the initial connect on a fresh start, and the client then sends updated
userinfo. Check the stored value each time you build a command rather than caching a decision
at connect.

If you maintain a fork of the TaystJK cgame that changes what any of these features parse, do
not reuse `taystJKcgflags` or its bits. Register your own userinfo cvar with its own bit
namespace, so servers never mistake your client for one with the stock behaviour.

### Scoreboard deaths

`TAYSTJK_INFO_SCORE_DEATHS` extends the `scores` command, so it needs both halves:

1. Set bit 7 in `taystJKinfo`. A client that sees it reads 15 integers per player instead of
   the stock 14
   ([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_servercmds.c#L63)).
2. In `DeathmatchScoreboardMessage`, append the deaths only when the client receiving the
   command advertises `TAYSTJK_CGFLAG_SCORE_DEATHS`. Every other client gets the stock
   14-field record.

```c
qboolean sendDeaths = (ent->client->pers.taystJKcgflags & TAYSTJK_CGFLAG_SCORE_DEATHS) ? qtrue : qfalse;

// after formatting the stock 14 fields into entry
if ( sendDeaths )
	j += Com_sprintf( entry + j, sizeof( entry ) - j, " %i", cl->ps.persistant[PERS_KILLED] );
```

The deaths field goes last, after captures. Do not send it to a client that has not advertised
the capability: older TaystJK builds and other clients read 14 fields per player, take the
deaths as the next player's client number, and misalign every record after it.

With the deaths supplied, the client's
[`cg_scoreDeaths`](/TaystJK/reference/cvars/cg_scoredeaths-67a5132/) treats your server as it
treats JA+ and jaPRO: `1` and `2` show the server's count, and `3` still shows the client's own
count
([`cg_scoreboard.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_scoreboard.c#L189)).

## How the client uses a flag

Each feature in the bit table checks for its flag next to the JA+ and jaPRO checks. RGB
sabers are typical: they are allowed on JA+ and above, or when your flag is set
([`cg_players.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_players.c#L6063)).

Flags can also change behaviour on recognised JA+ and jaPRO servers. In the roll selection
above, `FIXROLL_3` is tested before the server's roll-2 or roll-1 option, so
advertising it takes precedence over either lower mode
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_pmove.c#L314)).
Keep the advertised flags consistent with the server's actual movement rules and options.

## Verifying it

Run `serverinfo` in the server console, or `rcon serverinfo` from a client, and check the
key is there with the value you set. A player can see the same thing with `configstrings`
while connected: the first entry is the serverinfo
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_main.cpp#L3481)). `serverinfo` itself only works where
the server is running. If the key is missing, the client never got it and nothing that depends
on it will work, so fix that before looking at the feature.

For a capability, run `dumpuser <player>` on the server console. A current TaystJK client
connected to the server lists `taystJKcgflags` with a non-zero value. A player can check their
own with `userinfo`, but only while connected: the cvar does not exist until the cgame has
loaded, and reads `0` again after disconnecting.
