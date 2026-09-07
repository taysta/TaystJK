---
title: "r_renderScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_renderScale`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

Scaling mode to be used with custom render resolution: 0 - disabled 1 - nearest filtering, stretch to full size 2 - nearest filtering, preserve aspect ratio (black bars on sides) 3 - linear filtering, stretch to full size 4 - linear filtering, preserve aspect ratio (black bars on sides)

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
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/tr_init.cpp:967](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L967) |
| `1` | Nearest filtering, stretch to full size. | [codemp/rd-vulkan/tr_init.cpp:967](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L967) |
| `2` | Nearest filtering, preserve aspect ratio (black bars on sides). | [codemp/rd-vulkan/tr_init.cpp:967](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L967) |
| `3` | Linear filtering, stretch to full size. | [codemp/rd-vulkan/tr_init.cpp:967](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L967) |
| `4` | Linear filtering, preserve aspect ratio (black bars on sides). | [codemp/rd-vulkan/tr_init.cpp:967](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L967) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Commit evidence: [`c4a9c87ef0e3`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:966](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L966)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits vulkan.

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:967](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L967) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_init.cpp:39](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L39)
- behavior: [codemp/rd-vulkan/vk_init.cpp:70](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L70)
- behavior: [codemp/rd-vulkan/vk_init.cpp:339](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L339)
- behavior: [codemp/rd-vulkan/vk_init.cpp:41](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_init.cpp#L41)
- behavior: [codemp/rd-vulkan/tr_init.cpp:973](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L973)
