---
title: "fx_physics"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fx_physics`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Controls physics applied to FX system particles - 0: Disable all FX physics - 1: use non-expensive physics only - 2: Use flags in the fx file (Default behavior) - 3: Force expensive physics on all particles

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable all FX physics. | [codemp/client/FxUtil.cpp:117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L117) |
| `1` | Use non-expensive physics only. | [codemp/client/FxUtil.cpp:117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L117) |
| `2` | Use flags in the fx file (Default behavior). | [codemp/client/FxUtil.cpp:117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L117) |
| `3` | Force expensive physics on all particles. | [codemp/client/FxUtil.cpp:117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L117) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`19466a3a3b87`](https://github.com/taysta/TaystJK/commit/19466a3a3b879d8acaeab1f784d6d9d9a60ec153)
- Upstream registration evidence: [codemp/client/FxUtil.cpp:96](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/client/FxUtil.cpp#L96)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/client/FxUtil.cpp:117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L117) (Cvar_Get)
- behavior: [codemp/client/FxPrimitives.cpp:228](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxPrimitives.cpp#L228)
- behavior: [codemp/client/FxPrimitives.cpp:230](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxPrimitives.cpp#L230)
