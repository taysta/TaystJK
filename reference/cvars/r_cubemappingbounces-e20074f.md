---
title: "r_cubeMappingBounces"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_cubeMappingBounces`

<span class="label ref-origin ref-origin-rend2">rend2</span>

Renders cubemaps multiple times to get reflections in reflections

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
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
| `0` | Disabled. | [shared/rd-rend2/tr_bsp.cpp:3304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_bsp.cpp#L3304) |
| `1` | Enabled. | [shared/rd-rend2/tr_bsp.cpp:3304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_bsp.cpp#L3304) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`79a3b345265e`](https://github.com/taysta/TaystJK/commit/79a3b345265e4f8149a4a36f5e50dfd7901dc7e8)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1528](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1528)
- Attribution method: `renderer-scope-and-upstream-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1563](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1563) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_bsp.cpp:3304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_bsp.cpp#L3304)
- behavior: [codemp/ui/ui_main.c:6249](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6249)
- behavior: [codemp/ui/ui_main.c:6420](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6420)
- behavior: [codemp/rd-rend2/tr_init.cpp:1564](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1564)
