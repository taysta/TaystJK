---
title: "r_drawfog"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_drawfog`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Controls fog rendering. The Vulkan registration documents 0 as disabled, 1 as software fog, and 2 as hardware fog; the same cvar is registered by vanilla, rend2, Vulkan, and the dedicated renderer stub.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `mixed` |
| Confidence | `high` |
| Default | `2` |
| Value type | `enum` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable fog. | [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L871) |
| `1` | Use software fog. | [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L871) |
| `2` | Use hardware fog. | [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L871) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `2` | `renderer` | `rd-dedicated` | `always` |
| `2` | `renderer` | `rd-rend2` | `always` |
| `2` | `renderer` | `rd-vanilla` | `always` |
| `2` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Commit evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1204](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1204)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:404](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L404) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1653](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1653) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1713](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1713) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L871) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_quicksprite.cpp:87](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_quicksprite.cpp#L87)
- behavior: [codemp/rd-vanilla/tr_quicksprite.cpp:130](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_quicksprite.cpp#L130)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:648](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_shade.cpp#L648)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1000](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_shade.cpp#L1000)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1882](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_shade.cpp#L1882)
