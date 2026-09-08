---
title: "cg_drawCrosshairNamesColours"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawCrosshairNamesColours`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Selects crosshair-name coloring. Zero strips player color codes and uses green for allies and red for enemies; one preserves name color codes and starts from white.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `mixed` |
| Confidence | `high` |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Use green/red ally/enemy colors and sanitize name color codes. | [codemp/cgame/cg_draw.c:9530](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9530) |
| `1` | Preserve color codes in player names. | [codemp/cgame/cg_draw.c:9596](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9596) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `cgame` | `—` | `always` |
| `1` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`24fb55d23bfe`](https://github.com/taysta/TaystJK/commit/24fb55d23bfe18d3bcc3315232b310469cd23705)
- Pull request: [#281](https://github.com/taysta/TaystJK/pull/281)
- Matching squash bullet: `Add cg_drawCrosshairNamesColours toggle:`
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-12-11` | [`24fb55d23bfe`](https://github.com/taysta/TaystJK/commit/24fb55d23bfe18d3bcc3315232b310469cd23705) | Additional dated evidence |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-12-11` | [`24fb55d23bfe`](https://github.com/videoP/jaPRO/commit/24fb55d23bfe18d3bcc3315232b310469cd23705) | Additional dated evidence |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:275](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L275) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:41](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L41) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:9530](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9530)
- behavior: [codemp/cgame/cg_draw.c:9587](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9587)
- behavior: [codemp/cgame/cg_draw.c:9594](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9594)
- behavior: [codemp/cgame/cg_draw.c:9604](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9604)
- behavior: [codemp/ui/ui_xdocs.h:595](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L595)
- documentation: [codemp/ui/ui_xdocs.h:595](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L595)
