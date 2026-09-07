---
title: "r_bloom_threshold_mode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_bloom_threshold_mode`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

Color extraction mode: 0: (r|g|b) >= threshold 1: (r + g + b ) / 3 >= threshold 2: luma(r, g, b) >= threshold

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | (r|g|b) >= threshold. | [codemp/rd-vulkan/tr_init.cpp:942](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L942) |
| `1` | (r + g + b ) / 3 >= threshold. | [codemp/rd-vulkan/tr_init.cpp:942](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L942) |
| `2` | Luma(r, g, b) >= threshold. | [codemp/rd-vulkan/tr_init.cpp:942](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L942) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Commit evidence: [`e0d1076c4507`](https://github.com/taysta/TaystJK/commit/e0d1076c45074dc00d0defa0c089a18a731021a8)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:941](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L941)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits vulkan.

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:942](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L942) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_pipelines.cpp:1518](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_pipelines.cpp#L1518)
