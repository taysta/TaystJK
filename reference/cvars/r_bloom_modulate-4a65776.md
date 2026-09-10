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
| Category | Graphics & rendering |
| Feature family | Bloom |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
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
| `0` | Off (color = color, i.e. no changes). | [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L945) |
| `1` | By itself (color = color * color). | [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L945) |
| `2` | By intensity (color = color * luma(color)). | [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L945) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`e0d1076c4507`](https://github.com/JKSunny/EternalJK/commit/e0d1076c45074dc00d0defa0c089a18a731021a8) in <span class="label ref-origin ref-origin-vulkan">Vulkan</span> (content authored `2023-10-26`, integrated `2023-10-26`)
- TaystJK integration evidence: [`85114c9abfce`](https://github.com/taysta/TaystJK/commit/85114c9abfce0a2c70681224b30ef0bafac2a186)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:944](https://github.com/JKSunny/EternalJK/blame/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L944)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2023-10-26` | — | `2023-10-26` | [`e0d1076c4507`](https://github.com/JKSunny/EternalJK/commit/e0d1076c45074dc00d0defa0c089a18a731021a8) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-26` | — | `2023-10-27` | [`85114c9abfce`](https://github.com/taysta/TaystJK/commit/85114c9abfce0a2c70681224b30ef0bafac2a186) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-26` | — | `2023-10-27` | [`85114c9abfce`](https://github.com/videoP/jaPRO/commit/85114c9abfce0a2c70681224b30ef0bafac2a186) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:945](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L945) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_pipelines.cpp:1519](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_pipelines.cpp#L1519)
