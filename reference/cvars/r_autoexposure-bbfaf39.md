---
title: "r_autoExposure"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_autoExposure`

<span class="label ref-origin ref-origin-rend2">rend2</span>

Disable/enable auto exposure

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
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
| `0` | Disabled. | [shared/rd-rend2/tr_backend.cpp:3220](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3220) |
| `1` | Enabled. | [shared/rd-rend2/tr_backend.cpp:3220](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3220) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`be06f7907494`](https://github.com/taysta/TaystJK/commit/be06f7907494174027a3113859d824d951739db0)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1513](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1513)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits rend2.

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1548](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1548) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_backend.cpp:3220](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3220)
- behavior: [shared/rd-rend2/tr_shade.cpp:1881](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1881)
- behavior: [codemp/ui/ui_main.c:6245](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6245)
- behavior: [codemp/ui/ui_main.c:6416](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6416)
