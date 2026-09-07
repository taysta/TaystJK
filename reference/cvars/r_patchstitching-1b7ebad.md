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
| `0` | Disabled. | [codemp/rd-vanilla/tr_bsp.cpp:1395](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_bsp.cpp#L1395) |
| `1` | Enabled. | [codemp/rd-vanilla/tr_bsp.cpp:1395](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_bsp.cpp#L1395) |

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

- Commit evidence: [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417)
- Pull request: [#141](https://github.com/taysta/TaystJK/pull/141)
- Matching squash bullet: `replace PATCH_STITCHING preprocessor define with r_patchStitching cvar (#1199)`
- Upstream registration evidence: [codemp/rd-dedicated/tr_init.cpp:459](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-dedicated/tr_init.cpp#L459)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:457](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L457) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1725](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1725) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1780](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1780) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:777](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L777) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:906](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L906) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:1395](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_bsp.cpp#L1395)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:1401](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_bsp.cpp#L1401)
- behavior: [codemp/rd-vulkan/tr_bsp.cpp:1684](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_bsp.cpp#L1684)
- behavior: [codemp/rd-vulkan/tr_bsp.cpp:1690](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_bsp.cpp#L1690)
- behavior: [shared/rd-rend2/tr_bsp.cpp:2421](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_bsp.cpp#L2421)
