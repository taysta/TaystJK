---
title: "cg_killSounds"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_killSounds`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Play a sound when you kill someone

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Don't play the kill sound (Base behavior) | [codemp/ui/ui_xdocs.h:402](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L402) |
| `1` | Play the kill sound | [codemp/ui/ui_xdocs.h:403](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L403) |
| `2` | Play the kill sound + midair kill sound | [codemp/ui/ui_xdocs.h:403](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L403) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`477910d22e11`](https://github.com/taysta/TaystJK/commit/477910d22e11f8e6a4967b7ea074bfb2de181a49)
- Pull request: [#168](https://github.com/taysta/TaystJK/pull/168)
- Matching squash bullet: `[jaPRO/Sounds] Guard new killsounds behind cvar cg_killSound 0 = off 1 = on 2 = on + midair sound, commented out developer print, made them louder`
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:126](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L126) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:277](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L277)
- behavior: [codemp/cgame/cg_event.c:276](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L276)
- behavior: [codemp/ui/ui_xdocs.h:402](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L402)
- documentation: [codemp/ui/ui_xdocs.h:402](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L402)
