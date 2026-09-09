---
title: "se_language"
layout: reference
nav_exclude: true
search_exclude: false
---

# `se_language`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `se_language` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared`, `renderer`, `ui` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_setup.menu:4690](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L4690), [setup.menu:2994](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/setup.menu#L2994) |
| Default | `english` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_NORESTART` — preserved across cvar restart

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `english` | `engine-shared` | `—` | `always` |
| `english` | `renderer` | `rd-rend2` | `always` |
| `english` | `renderer` | `rd-vanilla` | `always` |
| `english` | `renderer` | `rd-vulkan` | `always` |
| `english` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/stringed_ingame.cpp:1169](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/stringed_ingame.cpp#L1169)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb29d3a516fb`](https://github.com/JACoders/OpenJK/commit/bb29d3a516fbc8f6dd8ca30864df3bd8b5ffea65)<br>Finished up most of the code now for the modular SP renderer. The things I need to fix still: - Some undefined externals - Some of the imports - The whole DLL import routine - Actual testing (???) Should be done by the end of this weekend, hopefully. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-07-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4f69181799b4`](https://github.com/JACoders/OpenJK/commit/4f69181799b4fd0e1ea338b332a2c7637978c2a7)<br>This is a combination of 5 commits. Removed platform.h, and got rid of various platform-specific typedefs. Removed references to platform.h | Changed an exact bound cvar-variable reference. `codemp/qcommon/stringed_ingame.cpp` | `medium` |
| `2013-07-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ee552c5b46e5`](https://github.com/JACoders/OpenJK/commit/ee552c5b46e542f9b56f9471d12eb6defe0ad763)<br>Merge pull request #328 from xycaleth/rd-common | Changed an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/game/ai_util.c`, `codemp/ui/ui_shared.c` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5cd41b41c941`](https://github.com/JACoders/OpenJK/commit/5cd41b41c941de081108a65bcffe81f41a77b876)<br>[MP] Port the xcvar stuff and clean up cvar usage in UI. Few minor tweaks in UI code for cleanup/was unused. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_shared.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd)<br>[MP] The cvar files for previous commit ... | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/qcommon/stringed_ingame.h` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/stringed_ingame.cpp`, `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`575a1b489075`](https://github.com/eternalcodes/EternalJK/commit/575a1b489075b00cfb45f8d588f9a665736eefdf)<br>Translate Discord print messages to English. | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_shared.c` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) · [PR #141](https://github.com/taysta/TaystJK/pull/141)<br>Patch stitching (#141) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/stringed_ingame.cpp:1178](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/stringed_ingame.cpp#L1178) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1727](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1727) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1626](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1626) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:779](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L779) (Cvar_Get)
- registration: [codemp/ui/ui_xcvar.h:50](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L50) (XCVAR_DEF)
- behavior: [codemp/qcommon/stringed_ingame.cpp:937](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/stringed_ingame.cpp#L937)
- behavior: [codemp/qcommon/stringed_ingame.cpp:1196](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/stringed_ingame.cpp#L1196)
- behavior: [codemp/qcommon/stringed_ingame.cpp:1199](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/stringed_ingame.cpp#L1199)
- behavior: [codemp/qcommon/stringed_ingame.cpp:1260](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/stringed_ingame.cpp#L1260)
- behavior: [codemp/qcommon/stringed_ingame.h:93](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/stringed_ingame.h#L93)
