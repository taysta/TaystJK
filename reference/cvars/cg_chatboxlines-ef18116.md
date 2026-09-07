---
title: "cg_chatBoxLines"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxLines`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

This would be called chatBoxHeight if baseJKA didn't use that

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `5` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`aba934621843`](https://github.com/taysta/TaystJK/commit/aba9346218436974329e85cbedbe5a7022651e14)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:63](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L63)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:76](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L76) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10949](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10949)
- behavior: [codemp/cgame/cg_draw.c:10986](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10986)
- behavior: [codemp/cgame/cg_draw.c:11002](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L11002)
