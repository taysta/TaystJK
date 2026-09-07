---
title: "r_bloom_modulate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_bloom_modulate`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

Modulate extracted color: 0: off (color = color, i.e. no changes) 1: by itself (color = color * color) 2: by intensity (color = color * luma(color))

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
| `0` | Off (color = color, i.e. no changes). | [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L945) |
| `1` | By itself (color = color * color). | [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L945) |
| `2` | By intensity (color = color * luma(color)). | [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L945) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Commit evidence: [`e0d1076c4507`](https://github.com/taysta/TaystJK/commit/e0d1076c45074dc00d0defa0c089a18a731021a8)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:944](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L944)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits vulkan.

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L945) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_pipelines.cpp:1519](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_pipelines.cpp#L1519)
