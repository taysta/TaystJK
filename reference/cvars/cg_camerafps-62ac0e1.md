---
title: "cg_cameraFPS"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_cameraFPS`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Sets the emulated frame rate used to make third-person camera damping frame-rate independent. Values below 15 select the original JK2/JKA multiplayer damping path; values of 15 or more use the time-adjusted path, with the original response reproduced when the actual frame rate matches this value.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `125` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `<15` | Use the original frame-rate-dependent JK2/JKA multiplayer camera damping. | [codemp/cgame/cg_view.c:541](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L541) |
| `>=15` | Use frame-rate-independent damping based on this emulated frame rate. | [codemp/cgame/cg_view.c:514](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L514) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Commit evidence: [`18a8e8c9a528`](https://github.com/taysta/TaystJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:133](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L133) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_snapshot.c:233](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_snapshot.c#L233)
- behavior: [codemp/cgame/cg_view.c:514](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L514)
- behavior: [codemp/cgame/cg_view.c:879](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L879)
- behavior: [codemp/cgame/cg_view.c:529](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L529)
- behavior: [codemp/cgame/cg_view.c:521](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L521)
