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

- Ultimate-origin introduction: [`e0d1076c4507`](https://github.com/JKSunny/EternalJK/commit/e0d1076c45074dc00d0defa0c089a18a731021a8) on `2023-10-26` in <span class="label ref-origin ref-origin-vulkan">Vulkan</span>
- TaystJK integration evidence: [`85114c9abfce`](https://github.com/taysta/TaystJK/commit/85114c9abfce0a2c70681224b30ef0bafac2a186)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:941](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L941)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2023-10-26` | [`e0d1076c4507`](https://github.com/JKSunny/EternalJK/commit/e0d1076c45074dc00d0defa0c089a18a731021a8) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-27` | [`85114c9abfce`](https://github.com/taysta/TaystJK/commit/85114c9abfce0a2c70681224b30ef0bafac2a186) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-27` | [`85114c9abfce`](https://github.com/videoP/jaPRO/commit/85114c9abfce0a2c70681224b30ef0bafac2a186) | Later project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:942](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L942) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_pipelines.cpp:1518](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_pipelines.cpp#L1518)
