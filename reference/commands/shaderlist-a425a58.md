---
title: "shaderlist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `shaderlist`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `R_ShaderList_f` in the renderer module.

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
| Syntax | `shaderlist` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1280](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1280)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_init.cpp`, `codemp/rd-vanilla/tr_local.h` and 1 more | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4c9c53371d37`](https://github.com/JACoders/OpenJK/commit/4c9c53371d376092854590e8fb6d402d2c10c7d6)<br>Fixed some more unresolved externals (for the modular renderer) | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp`, `codemp/rd-vanilla/tr_shader.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`39731cf76033`](https://github.com/JACoders/OpenJK/commit/39731cf760335057266d63ae5306d1c015497863)<br>[MP] Replaced a good chunk of Com_Printf usage in the renderer with ri->Printf. | Changed the registered command handler. `codemp/rd-vanilla/tr_shader.cpp` | `medium` |
| `2014-06-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`333d0ace79e0`](https://github.com/JACoders/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458)<br>[MP] Moved console commands in the renderer to an array to avoid forgetting to remove commands at shutdowns. Also refactored maxpolys/maxpolyverts initialization. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-07-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8c7cdd8ee135`](https://github.com/JACoders/OpenJK/commit/8c7cdd8ee135e1f3d94832f5a5bb4d7f9a228d48)<br>[MP] Revert 80f12fa97d4050cce9f9c1f5fb4e6c0f5d14cced. Apply several commits from ioq3's shader parser / COM_Parse fixes that were still missing. Remove deferLoad variable from ded and vanilla renderer tr_shader.cpp | Changed the registered command handler. `codemp/rd-vanilla/tr_shader.cpp` | `medium` |
| `2015-01-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`326f534c872d`](https://github.com/JACoders/OpenJK/commit/326f534c872d11aabb1ad333009e8fca09e8757b)<br>[MP] Handle lines starting with # as a deprecated comments in shaders. Fixes #271 | Changed the registered command handler. `codemp/rd-vanilla/tr_shader.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aee78667221a`](https://github.com/JACoders/OpenJK/commit/aee78667221a7fbd237f53ee142582a2581ed0b3)<br>[SP] Move renderer command registration into a linear table. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed the registered command handler. `codemp/rd-vanilla/tr_shader.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed the registered command handler. `codemp/rd-vulkan/tr_local.h`, `codemp/rd-vulkan/vk_debug.cpp` | `high` |
| `2021-06-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9d252184aa3b`](https://github.com/taysta/TaystJK/commit/9d252184aa3bdc2ba7e83ee8606a6c343007c510)<br>Pointer asterisk repositioning and spacing for readability | Changed the registered command handler. `codemp/rd-vulkan/vk_debug.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed the registered command handler. `shared/rd-rend2/tr_local.h`, `shared/rd-rend2/tr_shader.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1453](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1453) (renderer command table)
- registration: [codemp/rd-vanilla/tr_init.cpp:1592](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1592) (renderer command table)
- registration: [codemp/rd-vulkan/tr_init.cpp:744](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L744) (renderer command table)
- handler: [codemp/rd-vanilla/tr_shader.cpp:3802](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shader.cpp#L3802)
