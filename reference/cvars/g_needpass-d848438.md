---
title: "g_needpass"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_needpass`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Server needs password to join

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_client.c:2863](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2863) |
| `1` | Enabled. | [codemp/game/g_client.c:2863](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2863) |

## Flags

- `CVAR_ROM` — read-only after registration
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-server` | `—` | `always` |
| `0` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:352](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L352)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_main.c` | `medium` |
| `2013-09-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b8ba30ff20dc`](https://github.com/JACoders/OpenJK/commit/b8ba30ff20dc16d9a85288dda6c18d77bff73858)<br>Fix mistyped serverinfo cvars. Changed bg_altFighterControl to CVAR_SYSTEMINFO. Precache weapons on map_restart if g_weaponDisable changes. Fixes #376 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6c6472650cc`](https://github.com/eternalcodes/EternalJK/commit/f6c6472650ccd08fb0d010755094ab09ca8aced7)<br>Discord RPC integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:122](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L122) (XCVAR_DEF)
- registration: [codemp/server/sv_init.cpp:977](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L977) (Cvar_Get)
- behavior: [codemp/game/g_client.c:2863](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2863)
- behavior: [codemp/server/sv_main.cpp:550](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L550)
- behavior: [codemp/client/cl_cgame.cpp:220](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L220)
- behavior: [codemp/cgame/cg_servercmds.c:323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L323)
- behavior: [codemp/game/g_main.c:3285](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3285)
