---
title: "cg_fovAspectAdjust"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_fovAspectAdjust`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Fixed skyportal issue

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_view.c:1424](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L1424) |
| `1` | Enabled. | [codemp/cgame/cg_view.c:1424](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L1424) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`ad3cbbd4ce17`](https://github.com/taysta/TaystJK/commit/ad3cbbd4ce17be90e17580975752128c5a5d9853)
- Upstream registration evidence: [code/cgame/cg_main.cpp:355](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/cgame/cg_main.cpp#L355)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:305](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L305) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_view.c:1424](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L1424)
- behavior: [codemp/cgame/cg_view.c:2002](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2002)
- behavior: [codemp/cgame/cg_weapons.c:887](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L887)
