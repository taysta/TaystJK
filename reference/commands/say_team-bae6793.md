---
title: "say_team"
layout: reference
nav_exclude: true
search_exclude: false
---

# `say_team`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `say_team [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:373](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_consolecmds.c#L373)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3a01147d3902`](https://github.com/JACoders/OpenJK/commit/3a01147d39020af50c7d7f3a9851e43d93df4ab1)<br>[MP] Correct BOF fixes in g_cmds.c | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c6e3f0479ac0`](https://github.com/JACoders/OpenJK/commit/c6e3f0479ac048e838ac002351fab307f726fa4d)<br>[MP] Meta: Remove unnecessary comments and names | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9e070231c388`](https://github.com/eternalcodes/EternalJK/commit/9e070231c3888d26d3283769d0cdb8adf243fb5c)<br>Chat token cleanup+add chat tokens to print local time (Artemis) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c2f4269d3aed`](https://github.com/eternalcodes/EternalJK/commit/c2f4269d3aedd19c9ff1844ad419fb5313052aa4)<br>Allow chat tokens in PMs (now takes target name as argument on base) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2020-03-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`79d3bd1da8fb`](https://github.com/eternalcodes/EternalJK/commit/79d3bd1da8fb9ebfd6e37aa2c445b1bb820bf69c)<br>Add %P% chattoken for ping. | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2492](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2492) (cgame command table)
- registration: [codemp/cgame/cg_consolecmds.c:2589](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2589) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9039](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L9039) (game command table)
- handler: [codemp/cgame/cg_consolecmds.c:2311](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2311)
- handler: [codemp/game/g_cmds.c:2379](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L2379)
