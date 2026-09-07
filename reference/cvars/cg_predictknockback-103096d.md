---
title: "cg_predictKnockback"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_predictKnockback`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Predict self-inflicted rocket-jump knockback clientside (racemode only). Use with cg_simulatedProjectiles 1.

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
| `0` | Knockback is not predicted (default) | [codemp/ui/ui_xdocs.h:601](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L601) |
| `1` | Predict and apply rocket-jump knockback | [codemp/ui/ui_xdocs.h:601](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L601) |
| `2` | Verbose trajectory/timing logging (fire, detect, render, clear, actual) | [codemp/ui/ui_xdocs.h:601](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L601) |
| `3` | Maximum logging; adds forward-trace detection and per-command injection | [codemp/ui/ui_xdocs.h:603](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L603) |
| `4` | Damage/distance logging only (trajectory spam suppressed) | [codemp/ui/ui_xdocs.h:604](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L604) |
| `5` | Impulse/injection logging; adds per-command injection trace | [codemp/ui/ui_xdocs.h:605](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L605) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:193](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L193) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:3415](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L3415)
- behavior: [codemp/cgame/cg_event.c:3422](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L3422)
- behavior: [codemp/cgame/cg_event.c:3442](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L3442)
- behavior: [codemp/cgame/cg_event.c:3493](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L3493)
- behavior: [codemp/cgame/cg_event.c:3500](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L3500)
- documentation: [codemp/ui/ui_xdocs.h:600](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L600)
