---
title: "g_allowVote"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_allowVote`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_allowVote` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `-1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:380](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L380)
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

- registration: [codemp/game/g_xcvar.h:71](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L71) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:3110](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L3110)
- behavior: [codemp/game/g_cmds.c:3252](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L3252)
- behavior: [codemp/game/g_cmds.c:3280](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L3280)
- behavior: [codemp/game/g_svcmds.c:1434](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L1434)
- behavior: [codemp/game/g_cmds.c:3141](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L3141)
