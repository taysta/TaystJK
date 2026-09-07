---
title: "cg_drawCrosshairNamesOpacity"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawCrosshairNamesOpacity`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Multiplies the target-name fade alpha by this opacity. Runtime use clamps the effective value to the inclusive range 0 through 1.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `cgame` | `—` | `always` |
| `1` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`24fb55d23bfe`](https://github.com/taysta/TaystJK/commit/24fb55d23bfe18d3bcc3315232b310469cd23705)
- Pull request: [#281](https://github.com/taysta/TaystJK/pull/281)
- Matching squash bullet: `Add cg_drawCrosshairNamesOpacity (0-1 float) to control name transparency`
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits eternaljk.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:274](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L274) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:40](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L40) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:9581](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9581)
- behavior: [codemp/ui/ui_xdocs.h:592](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L592)
- documentation: [codemp/ui/ui_xdocs.h:592](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L592)
