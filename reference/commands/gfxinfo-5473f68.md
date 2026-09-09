---
title: "gfxinfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `gfxinfo`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `GfxInfo_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `gfxinfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1289](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1289)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4c9c53371d37`](https://github.com/JACoders/OpenJK/commit/4c9c53371d376092854590e8fb6d402d2c10c7d6)<br>Fixed some more unresolved externals (for the modular renderer) | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2013-07-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a2f440ad1c7b`](https://github.com/JACoders/OpenJK/commit/a2f440ad1c7bb7639be536e484a60774e26b6cf9)<br>Merge branch 'master' of github.com:Razish/OpenJK | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`39731cf76033`](https://github.com/JACoders/OpenJK/commit/39731cf760335057266d63ae5306d1c015497863)<br>[MP] Replaced a good chunk of Com_Printf usage in the renderer with ri->Printf. | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fa917fa25d84`](https://github.com/JACoders/OpenJK/commit/fa917fa25d84ea5ffd3b1b968330464b18bc425d)<br>[MP] Fix #472 | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-06-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fa91ba821e9c`](https://github.com/JACoders/OpenJK/commit/fa91ba821e9cb85d983a5fc9d227017d7cd6a473)<br>[MP] Fix crash on startup if r_DynamicGlow is 2 | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-06-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`333d0ace79e0`](https://github.com/JACoders/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458)<br>[MP] Moved console commands in the renderer to an array to avoid forgetting to remove commands at shutdowns. Also refactored maxpolys/maxpolyverts initialization. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aee78667221a`](https://github.com/JACoders/OpenJK/commit/aee78667221a7fbd237f53ee142582a2581ed0b3)<br>[SP] Move renderer command registration into a linear table. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3df8f354dea3`](https://github.com/JACoders/OpenJK/commit/3df8f354dea3b493706e0cd072663fd54c596dcb)<br>[MP] Move startup call to gfxinfo to later so that overbright bits is displayed correctly | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-06-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f614bc372a41`](https://github.com/taysta/TaystJK/commit/f614bc372a41cca80c0e1e401d584a57318bd495)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`00588c8f6da8`](https://github.com/eternalcodes/EternalJK/commit/00588c8f6da89586c2b12a2cfe321eabe7071bd2)<br>Better fix for verbose/fs_debug logging option | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`02efd4150ed2`](https://github.com/eternalcodes/EternalJK/commit/02efd4150ed2e5954891f1bbea5b22a9af7d1c2b)<br>Only show GL_ GFX info if r_verbose is 1 https://github.com/eternalcodes/EternalJK/issues/65 Also possible fix for https://github.com/eternalcodes/EternalJK/issues/57 and https://github.com/eternalcodes/EternalJK/issues/49 | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `high` |
| `2021-10-24` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`bd3a458a8bb2`](https://github.com/JKSunny/EternalJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5)<br>Various fixes and upstream changes from Quake3e | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/vk_info.cpp`, `codemp/rd-vulkan/vk_local.h` | `high` |
| `2022-02-16` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`ac6f372267f1`](https://github.com/JKSunny/EternalJK/commit/ac6f372267f13a81d1a49d931ba88f7a96937cc2)<br>Vulkan: Fix repeating compiler warning for method: vk_set_object_name | Changed the registered command handler. `codemp/rd-vulkan/vk_local.h` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) · [PR #141](https://github.com/taysta/TaystJK/pull/141)<br>Patch stitching (#141) | Changed the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1459](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1459) (renderer command table)
- registration: [codemp/rd-vanilla/tr_init.cpp:1598](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1598) (renderer command table)
- registration: [codemp/rd-vulkan/tr_init.cpp:750](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L750) (renderer command table)
- handler: [codemp/rd-rend2/tr_init.cpp:1274](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1274)
