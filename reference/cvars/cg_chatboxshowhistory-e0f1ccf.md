---
title: "cg_chatBoxShowHistory"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxShowHistory`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Shows past messages when console is open

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled (baseJKA behavior) | [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217) |
| `1` | Enabled | [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`afb2b659104b`](https://github.com/taysta/TaystJK/commit/afb2b659104bbb636e81388544c43de1bb129028)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:61](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L61)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:74](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L74) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10980)
- behavior: [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217)
- documentation: [codemp/ui/ui_xdocs.h:217](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L217)
