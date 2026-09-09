---
title: "forcepowers"
layout: reference
nav_exclude: true
search_exclude: false
---

# `forcepowers`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Player forcepowers

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame`, `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `DEFAULT_FORCEPOWERS` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_USERINFO` — sent in the client's userinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `7-1-032330000000001333` | `engine-client` | `—` | `always` |
| `DEFAULT_FORCEPOWERS` | `cgame` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:1079](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L1079)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h`, `codemp/game/g_bot.c` and 2 more | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c`, `codemp/ui/ui_force.c` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`761e55fd73af`](https://github.com/JACoders/OpenJK/commit/761e55fd73af4c8f2b8e0b9daf10f91762839066)<br>[MP] Clean up forcepowers validation | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `medium` |
| `2015-06-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f614bc372a41`](https://github.com/taysta/TaystJK/commit/f614bc372a41cca80c0e1e401d584a57318bd495)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_local.h`, `codemp/game/w_force.c` | `high` |
| `2019-05-03` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`96cf7ecc01a1`](https://github.com/taysta/TaystJK/commit/96cf7ecc01a1c4aa7a7ae6a7ab1f5867c6b79bc9)<br>Port invalid userinfo crash in serverside engine (from JK2MV). | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93dfa66dc8e5`](https://github.com/videoP/jaPRO/commit/93dfa66dc8e5d49a7067d6f12818333e15366ead) · [PR #112](https://github.com/taysta/TaystJK/pull/112)<br>Japro updates (#112) | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:376](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L376) (XCVAR_DEF)
- registration: [codemp/client/cl_main.cpp:3420](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3420) (Cvar_Get)
- behavior: [codemp/game/w_force.c:232](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L232)
- behavior: [codemp/cgame/cg_players.c:2491](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L2491)
- behavior: [codemp/game/w_force.c:241](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L241)
- behavior: [codemp/game/w_force.c:243](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L243)
- behavior: [codemp/game/w_force.c:245](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L245)
