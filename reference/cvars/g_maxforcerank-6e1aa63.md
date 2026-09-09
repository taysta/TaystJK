---
title: "g_maxForceRank"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_maxForceRank`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_maxForceRank` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `7` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `7` | `engine-server` | `—` | `always` |
| `7` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:260](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L260)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2013-04-14` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b718cfa3e332`](https://github.com/JACoders/OpenJK/commit/b718cfa3e33285ecb0d140dfb12218c67c7c8e08)<br>Jedi Master Force Rank is new default because... what? All servers set this \|: | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h`, `codemp/server/sv_init.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c`, `codemp/ui/ui_force.c`, `codemp/ui/ui_main.c` | `medium` |
| `2014-01-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cf34344d1cdc`](https://github.com/JACoders/OpenJK/commit/cf34344d1cdc86b2451d81307fb529496bd8110e)<br>Merge branch 'master' of github.com:JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`761e55fd73af`](https://github.com/JACoders/OpenJK/commit/761e55fd73af4c8f2b8e0b9daf10f91762839066)<br>[MP] Clean up forcepowers validation | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6c0c841b1025`](https://github.com/JACoders/OpenJK/commit/6c0c841b1025831c732d81261e0cad2fc4a66440)<br>[MP] Fix stack corruption after 761e55fd73 | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:118](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L118) (XCVAR_DEF)
- registration: [codemp/server/sv_init.cpp:971](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L971) (Cvar_Get)
- behavior: [codemp/game/w_force.c:164](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L164)
- behavior: [codemp/game/w_force.c:388](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L388)
- behavior: [codemp/game/w_force.c:395](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L395)
- behavior: [codemp/cgame/cg_info.c:309](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_info.c#L309)
- behavior: [codemp/game/w_force.c:241](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_force.c#L241)
