---
title: "cg_fovViewmodelAdjust"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_fovViewmodelAdjust`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Shifts viewmodels down above cg_fov 90

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`004c73dcfeb3`](https://github.com/taysta/TaystJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d)
- Upstream registration evidence: [code/cgame/cg_main.cpp:459](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/cgame/cg_main.cpp#L459)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:307](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L307) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_weapons.c:865](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L865)
