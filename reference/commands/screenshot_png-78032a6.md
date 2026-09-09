---
title: "screenshot_png"
layout: reference
nav_exclude: true
search_exclude: false
---

# `screenshot_png`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `R_ScreenShotPNG_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `screenshot_png [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`333d0ace79e0`](https://github.com/JACoders/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-16`, integrated `2014-06-23`)
- Upstream registration evidence: [code/rd-vanilla/tr_init.cpp:1482](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/rd-vanilla/tr_init.cpp#L1482)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/JACoders/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/eternalcodes/EternalJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/SomaZ/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/taysta/TaystJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/videoP/jaPRO/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/jkanewmod/NewJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-16` | — | `2014-06-23` | [`333d0ace79e0`](https://github.com/JKSunny/EternalJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-12-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e753a88166bb`](https://github.com/JACoders/OpenJK/commit/e753a88166bb25b7f4f113096135215c956f5541)<br>[SP] Move the image and screenshot code closer to MP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`39731cf76033`](https://github.com/JACoders/OpenJK/commit/39731cf760335057266d63ae5306d1c015497863)<br>[MP] Replaced a good chunk of Com_Printf usage in the renderer with ri->Printf. | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aee78667221a`](https://github.com/JACoders/OpenJK/commit/aee78667221a7fbd237f53ee142582a2581ed0b3)<br>[SP] Move renderer command registration into a linear table. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `high` |
| `2021-06-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9d252184aa3b`](https://github.com/taysta/TaystJK/commit/9d252184aa3bdc2ba7e83ee8606a6c343007c510)<br>Pointer asterisk repositioning and spacing for readability | Changed the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2023-11-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`546c6253be69`](https://github.com/taysta/TaystJK/commit/546c6253be697b3ae1e3286c900edeb356319c0f)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed the registered command handler. `shared/rd-rend2/tr_local.h` | `medium` |
| `2024-02-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) · [PR #141](https://github.com/taysta/TaystJK/pull/141)<br>Patch stitching (#141) | Changed the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1457](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1457) (renderer command table)
- registration: [codemp/rd-vanilla/tr_init.cpp:1596](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1596) (renderer command table)
- registration: [codemp/rd-vulkan/tr_init.cpp:748](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L748) (renderer command table)
- handler: [codemp/rd-rend2/tr_init.cpp:1037](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1037)
- handler: [codemp/rd-vanilla/tr_init.cpp:1224](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1224)
