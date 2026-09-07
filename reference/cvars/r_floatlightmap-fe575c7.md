---
title: "r_floatLightmap"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_floatLightmap`

<span class="label ref-origin ref-origin-rend2">rend2</span>

Disable/enable HDR lightmap support

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
| `0` | Disabled. | [shared/rd-rend2/tr_extensions.cpp:710](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_extensions.cpp#L710) |
| `1` | Enabled. | [shared/rd-rend2/tr_extensions.cpp:710](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_extensions.cpp#L710) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`aad008288d68`](https://github.com/taysta/TaystJK/commit/aad008288d68e7a2f65a9a4e0fe594c5902d2cdf)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1505](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1505)
- Attribution method: `renderer-scope-and-upstream-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1540](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1540) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_extensions.cpp:710](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_extensions.cpp#L710)
- behavior: [codemp/ui/ui_main.c:6246](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6246)
- behavior: [codemp/ui/ui_main.c:6417](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6417)
