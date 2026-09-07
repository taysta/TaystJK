---
title: "r_vbo_models"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_vbo_models`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

Cache ghoul2 and md3 model surfaces

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
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/vk_init.cpp:512](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L512) |
| `1` | Enabled. | [codemp/rd-vulkan/vk_init.cpp:512](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L512) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Commit evidence: [`9d7cf09661c0`](https://github.com/taysta/TaystJK/commit/9d7cf09661c0c22f23f918430447ae00685bfd03)
- Matching squash bullet: `Added &#96;r_vbo_models&#96; cvar to control GPU caching for Ghoul2 (player) and MD3 models`
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:962](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L962)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits vulkan.

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:963](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L963) (Cvar_Get); condition `defined(USE_VBO)`
- behavior: [codemp/rd-vulkan/vk_init.cpp:512](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L512)
- behavior: [codemp/rd-vulkan/vk_info.cpp:472](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_info.cpp#L472)
