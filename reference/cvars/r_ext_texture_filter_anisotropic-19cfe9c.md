---
title: "r_ext_texture_filter_anisotropic"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_ext_texture_filter_anisotropic`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Disable/enable anisotropic texture filtering

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `16` |
| Value type | `float` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `16` | `renderer` | `rd-dedicated` | `always` |
| `16` | `renderer` | `rd-rend2` | `always` |
| `16` | `renderer` | `rd-vanilla` | `always` |
| `16` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Commit evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1100](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1100)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:325](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L325) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1502](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1502) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1638](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1638) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:791](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L791) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_image.cpp:94](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_image.cpp#L94)
- behavior: [codemp/rd-vanilla/tr_image.cpp:107](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_image.cpp#L107)
- behavior: [codemp/rd-vanilla/tr_image.cpp:760](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_image.cpp#L760)
- behavior: [codemp/rd-vanilla/tr_init.cpp:493](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L493)
- behavior: [codemp/rd-vanilla/tr_init.cpp:502](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L502)
