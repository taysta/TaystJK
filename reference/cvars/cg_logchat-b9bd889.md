---
title: "cg_logChat"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_logChat`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_logChat` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `8` | Enables the `JAPRO_CHATLOG_CENTERPRINT` code path. | [codemp/cgame/cg_local.h:163](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_local.h#L163) |
| `1` | Enables the `JAPRO_CHATLOG_ENABLE` code path. | [codemp/cgame/cg_local.h:159](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_local.h#L159) |
| `4` | Enables the `JAPRO_CHATLOG_OLDTIMESTAMP` code path. | [codemp/cgame/cg_local.h:161](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_local.h#L161) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`f1b9b895897d`](https://github.com/taysta/TaystJK/commit/f1b9b895897d19abcc7cfba7f63015a627e80df2)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:157](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L157)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:186](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L186) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_consolecmds.c:1929](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1929)
- behavior: [codemp/cgame/cg_draw.c:10656](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L10656)
- behavior: [codemp/cgame/cg_main.c:2718](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_main.c#L2718)
- behavior: [codemp/cgame/cg_main.c:3123](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_main.c#L3123)
- behavior: [codemp/cgame/cg_servercmds.c:1640](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_servercmds.c#L1640)
