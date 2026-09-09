---
title: "r_patchStitching"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_patchStitching`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Enable stitching of neighbouring patch surfaces

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vanilla/tr_bsp.cpp:1395](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L1395) |
| `1` | Enabled. | [codemp/rd-vanilla/tr_bsp.cpp:1395](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L1395) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `renderer` | `rd-dedicated` | `always` |
| `1` | `renderer` | `rd-rend2` | `always` |
| `1` | `renderer` | `rd-vanilla` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`540edeb67fd6`](https://github.com/JACoders/OpenJK/commit/540edeb67fd65cd08642fe4d324e3e49101755a4) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2024-02-09`, integrated `2024-02-09`)
- TaystJK integration evidence: [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417)
- Origin pull request: [#141](https://github.com/taysta/TaystJK/pull/141)
- Matching squash bullet: `replace PATCH_STITCHING preprocessor define with r_patchStitching cvar (#1199)`
- Upstream registration evidence: [codemp/rd-dedicated/tr_init.cpp:459](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-dedicated/tr_init.cpp#L459)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-09` | — | `2024-02-09` | [`540edeb67fd6`](https://github.com/JACoders/OpenJK/commit/540edeb67fd65cd08642fe4d324e3e49101755a4) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-09` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-10` | [2024-02-09](https://github.com/taysta/TaystJK/pull/141) | `2024-02-10` | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-10` | — | `2024-02-10` | [`ea0478621b05`](https://github.com/videoP/jaPRO/commit/ea0478621b0535dc6a6e5a22036237942e98c417) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2024-04-15` | — | `2024-04-15` | [`7aca5689c198`](https://github.com/JKSunny/EternalJK/commit/7aca5689c19804d87c1db70c83e9e3fb583988f4) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) · [PR #141](https://github.com/taysta/TaystJK/pull/141)<br>Patch stitching (#141) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-rend2/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` and 1 more | `medium` |
| `2024-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c7590dfd5fd2`](https://github.com/taysta/TaystJK/commit/c7590dfd5fd2f09108ad4d14d370cf7bafc0c9b2) · [PR #190](https://github.com/taysta/TaystJK/pull/190)<br>Upstream vulkan updates (#190) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:457](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/tr_init.cpp#L457) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1725](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1725) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1780](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1780) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:777](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L777) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:906](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L906) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:1395](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L1395)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:1401](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L1401)
- behavior: [codemp/rd-vulkan/tr_bsp.cpp:1684](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_bsp.cpp#L1684)
- behavior: [codemp/rd-vulkan/tr_bsp.cpp:1690](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_bsp.cpp#L1690)
- behavior: [shared/rd-rend2/tr_bsp.cpp:2421](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_bsp.cpp#L2421)
