---
title: "g_allowVote"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_allowVote`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>toggleVote</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Controls `g_allowVote` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `-1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`toggleVote`](/TaystJK/reference/commands/togglevote-397b6ff/) |

## Bits

Use [`toggleVote`](/TaystJK/reference/commands/togglevote-397b6ff/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own. [The labels come from the source table](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_svcmds.c#L1410).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Capturelimit | — |
| 1 | `2` | Clientkick | — |
| 2 | `4` | Forcespec | — |
| 3 | `8` | Fraglimit | — |
| 4 | `16` | g_doWarmup | — |
| 5 | `32` | g_gametype | — |
| 6 | `64` | kick | — |
| 7 | `128` | map | — |
| 8 | `256` | map_restart | — |
| 9 | `512` | nextmap | — |
| 10 | `1024` | sv_maxteamsize | — |
| 11 | `2048` | timelimit | — |
| 12 | `4096` | vstr | — |
| 13 | `8192` | poll | — |
| 14 | `16384` | pause | — |
| 15 | `32768` | score_restart | — |
## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:380](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L380)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2013-10-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`872159cb6796`](https://github.com/JACoders/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821)<br>[MP] Rewrote callvote to be far more robust | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2013-10-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`99f68a293fef`](https://github.com/JACoders/OpenJK/commit/99f68a293fef762f6c6cf8ee76e2b0e21811c7c3)<br>[MP] Fixed a few issues with vote code from previous commits. Tweaked the team vote code to be a simplified but similar version of the new callvote code. Added g_allowTeamVote, defaulted to 1 cvar to toggle team voting. | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb3ed393a5fb`](https://github.com/JACoders/OpenJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5)<br>[MP] Add toggleallowvote server command for easy toggling of g_allowVote bit options. | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_svcmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:71](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_xcvar.h#L71) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:3110](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_cmds.c#L3110)
- behavior: [codemp/game/g_cmds.c:3252](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_cmds.c#L3252)
- behavior: [codemp/game/g_cmds.c:3280](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_cmds.c#L3280)
- behavior: [codemp/game/g_svcmds.c:1434](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_svcmds.c#L1434)
- behavior: [codemp/game/g_cmds.c:3141](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_cmds.c#L3141)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
