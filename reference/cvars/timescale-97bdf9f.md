---
title: "timescale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `timescale`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `timescale` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame`, `game`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence
- `CVAR_SYSTEMINFO` — replicated in systeminfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `cgame` | `—` | `always` |
| `1` | `engine-shared` | `—` | `always` |
| `1` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:414](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L414)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_main.c`, `codemp/cgame/cg_players.c` and 3 more | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp`, `codemp/server/sv_snapshot.cpp` | `high` |
| `2013-04-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e)<br>Replaces jpeg-6 with jpeg-8c.  Adds AVI write support from ioquake3.  (jpeg update was required) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_backend.cpp`, `codemp/rd-vanilla/tr_scene.cpp` | `high` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_backend.cpp`, `codemp/rd-vanilla/tr_scene.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c`, `codemp/game/NPC_AI_Jedi.c`, `codemp/game/NPC_utils.c` and 2 more | `medium` |
| `2013-10-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9ed72420609f`](https://github.com/JACoders/OpenJK/commit/9ed72420609f27901f50909430fb8cfc01a03842)<br>[MP] Removed legacy MAC_STATIC define that wasn't even defined as anything anymore. | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_backend.cpp` | `medium` |
| `2013-10-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`0bf217273755`](https://github.com/JACoders/OpenJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3)<br>[MP] Merged critical fixes (ioquake/ioq3@f725b23) for snapshot floating point imprecision from ioq3 that were missing. | Changed an exact bound cvar-variable reference. `codemp/server/sv_snapshot.cpp` | `medium` |
| `2013-10-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b0d61035c755`](https://github.com/JACoders/OpenJK/commit/b0d61035c755ae1921291fd23abc5053e0eb4d2c)<br>[MP] Plausible fix from q3mme/ent for avi record sync issues. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2013-11-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`22badd6b5cf9`](https://github.com/JACoders/OpenJK/commit/22badd6b5cf9e3a29b933b0f2b09d7c127d96506)<br>[MP] Try ioq3's version of the video record desync fix. Though technically its not any different. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2014-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ab07009afb3`](https://github.com/JACoders/OpenJK/commit/5ab07009afb306f2852a97caedf4eaab8774c743)<br>[SP] Fix compiler warnings | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp` | `medium` |
| `2014-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bd4918823180`](https://github.com/JACoders/OpenJK/commit/bd49188231804450a0c258270a21678dc659ba08)<br>[JK2] Fix compiler warnings | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e6464f352161`](https://github.com/JACoders/OpenJK/commit/e6464f35216195f7b292a711470ebd9feb268279)<br>[Shared] Rename min/max macro to Q_min/Q_max | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `code/qcommon/common.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2016-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`13791f7ad4fe`](https://github.com/taysta/TaystJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_backend.cpp`, `codemp/rd-vanilla/tr_scene.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h`, `codemp/qcommon/common.cpp` | `high` |
| `2018-01-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6ff91fb53dc7`](https://github.com/eternalcodes/EternalJK/commit/6ff91fb53dc7cb933e2645b13a90b5a66eb6cc12)<br>Fix timescale warning | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2018-01-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9bd4d2c1d19d`](https://github.com/eternalcodes/EternalJK/commit/9bd4d2c1d19d2fa7651861646c613d75e8909377)<br>Merge ec-/Quake3e@ef0b139 | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2018-10-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c648f59e6b35`](https://github.com/eternalcodes/EternalJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1)<br>hibernate redo | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`32fd320e90d7`](https://github.com/eternalcodes/EternalJK/commit/32fd320e90d7ea31d6989579d22cac223f87a273)<br>pause demo playback when menu open | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2019-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ab57b189a8e1`](https://github.com/eternalcodes/EternalJK/commit/ab57b189a8e1d725927c5c448184bb536b7e71e2)<br>Fix FPS drop from disintegrating corpse smoke at high FPS | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp`, `codemp/rd-vulkan/tr_scene.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp`, `codemp/rd-vulkan/tr_scene.cpp`, `codemp/rd-vulkan/vk_shade_geometry.cpp` | `high` |
| `2021-06-09` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`75ddc3278292`](https://github.com/taysta/TaystJK/commit/75ddc32782922a4e08644eb0da225b0994a9e938)<br>Reverted  RE_UploadCinematic to vanilla | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp` | `medium` |
| `2024-05-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`829a59ad0875`](https://github.com/videoP/jaPRO/commit/829a59ad08755dee1f62049d9a03be252668e47a) · [PR #200](https://github.com/taysta/TaystJK/pull/200)<br>[jaPRO] Fixup clang compiler warnings (#200) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_trigger.c`, `codemp/game/g_xcvar.h` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:389](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L389) (XCVAR_DEF)
- registration: [codemp/game/g_xcvar.h:181](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L181) (XCVAR_DEF)
- registration: [codemp/qcommon/common.cpp:1468](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1468) (Cvar_Get)
- behavior: [codemp/cgame/cg_view.c:3116](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L3116)
- behavior: [codemp/cgame/cg_view.c:3117](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L3117)
- behavior: [codemp/cgame/cg_view.c:3119](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L3119)
- behavior: [codemp/cgame/cg_view.c:3124](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L3124)
- behavior: [codemp/client/cl_cgame.cpp:879](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L879)
