---
title: "developer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `developer`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Developer mode

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `game` |
| Also registered in | `game`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/game/g_ICARUScb.c:300](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_ICARUScb.c#L300) |

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence
- `CVAR_TEMP` — temporary and not archived

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-shared` | `—` | `always` |
| `0` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:413](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L413)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_ICARUScb.c`, `codemp/game/g_main.c`, `codemp/game/g_target.c` and 2 more | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61779788b020`](https://github.com/JACoders/OpenJK/commit/61779788b0207e43c974b10b79dfba4709369636)<br>Botlib improvements. Moved some botlib headers to the botlib folder | Changed an exact bound cvar-variable reference. `codemp/botlib/be_interface.h`, `codemp/botlib/botlib.h` | `medium` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_scene.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/qcommon/vm.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2014-04-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6474d6681d8`](https://github.com/JACoders/OpenJK/commit/f6474d6681d8b080595fe18d4056c23b5cbfbffa)<br>[MP] Clean up VM handling | Changed an exact bound cvar-variable reference. `codemp/qcommon/vm.cpp` | `medium` |
| `2014-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ab07009afb3`](https://github.com/JACoders/OpenJK/commit/5ab07009afb306f2852a97caedf4eaab8774c743)<br>[SP] Fix compiler warnings | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp` | `medium` |
| `2014-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bd4918823180`](https://github.com/JACoders/OpenJK/commit/bd49188231804450a0c258270a21678dc659ba08)<br>[JK2] Fix compiler warnings | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_system.h` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `code/qcommon/common.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2016-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0efc3164f2c4`](https://github.com/eternalcodes/EternalJK/commit/0efc3164f2c42a426d8d316c6347ea74395fb694)<br>Upgrade to SDL 2.0.4 | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_hints.h`, `lib/SDL2/include/SDL_system.h` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/ui/ui_syscalls.c` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/server/sv_challenge.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7f47620dbcbe`](https://github.com/eternalcodes/EternalJK/commit/7f47620dbcbe31a136df62264ebb2f387d502145)<br>Merge remote-tracking branch 'upstream/master' | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_hints.h` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c`, `codemp/game/sqlite3.c`, `codemp/server/sv_main.cpp` | `high` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_syscalls.c` | `medium` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6882abccd6c`](https://github.com/eternalcodes/EternalJK/commit/f6882abccd6cf19d533c41723245bf0a08dde3e0)<br>start/stop svrecording msg only if developer | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d5b95947d04f`](https://github.com/videoP/jaPRO/commit/d5b95947d04f3fb485bbfccb41c5ecadd1587946)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c` | `high` |
| `2018-10-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`648e091780ed`](https://github.com/eternalcodes/EternalJK/commit/648e091780ed44c67abe7577cb22573226a854a9)<br>never wanted this | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2019-12-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8acb78983579`](https://github.com/eternalcodes/EternalJK/commit/8acb78983579e007ac1718f027361b783ee7c33b)<br>Fix client defaulting to onboard graphics on laptops with discrete GPUs. | Changed an exact bound cvar-variable reference. `shared/sys/sys_win32.cpp` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)<br>Merge pull request #97 from aufau/ratelimiter | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_scene.cpp` | `medium` |
| `2022-02-23` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3f911a1ac75c`](https://github.com/taysta/TaystJK/commit/3f911a1ac75ca1afb4c179684bfa1e84d490df6d)<br>Upgrade SDL to version 2.0.12 & Fix Github actions compiler errors by Tayst | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_sensor.h` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |
| `2024-03-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) · [PR #169](https://github.com/taysta/TaystJK/pull/169)<br>HTTP Auto Download (Server + Client) (#169) | Changed an exact bound cvar-variable reference. `lib/mongoose/include/mongoose.h`, `lib/mongoose/mongoose.c` | `medium` |
| `2025-04-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) · [PR #228](https://github.com/taysta/TaystJK/pull/228)<br>Update built in SDL version for windows to 2.32.4 (#228) | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_hints.h`, `lib/SDL2/include/SDL_system.h` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:62](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L62) (XCVAR_DEF)
- registration: [codemp/qcommon/common.cpp:1386](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1386) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2108](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2108)
- behavior: [codemp/client/cl_main.cpp:2264](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2264)
- behavior: [codemp/client/cl_main.cpp:3774](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3774)
- behavior: [codemp/game/g_ICARUScb.c:300](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_ICARUScb.c#L300)
- behavior: [codemp/game/g_active.c:1368](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L1368)
