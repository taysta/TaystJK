---
title: "cl_ratioFix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_ratioFix`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Widescreen aspect ratio correction

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `cgame`, `engine-client`, `renderer`, `ui` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/rd-common/tr_font.cpp:1458](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1458) |
| `2` | Selects the code path tested for value 2. | [codemp/rd-common/tr_font.cpp:1461](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1461) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `cgame` | `—` | `always` |
| `1` | `engine-client` | `—` | `always` |
| `1` | `renderer` | `rd-rend2` | `always` |
| `1` | `renderer` | `rd-vanilla` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |
| `1` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`753e8dcbd4a0`](https://github.com/taysta/TaystJK/commit/753e8dcbd4a0c36291db8ec7f18da4f1094bf3d1)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:143](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L143) (XCVAR_DEF)
- registration: [codemp/client/cl_main.cpp:3442](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3442) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1696](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1696) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1743](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1743) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:905](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L905) (Cvar_Get)
- registration: [codemp/ui/ui_xcvar.h:37](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L37) (XCVAR_DEF)
- behavior: [codemp/client/cl_main.cpp:2422](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2422)
- behavior: [codemp/rd-common/tr_font.cpp:1458](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1458)
- behavior: [codemp/rd-common/tr_font.cpp:1461](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1461)
- behavior: [codemp/rd-common/tr_font.cpp:1760](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1760)
- behavior: [codemp/rd-common/tr_font.cpp:1764](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1764)
