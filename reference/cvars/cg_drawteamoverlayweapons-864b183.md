---
title: "cg_drawTeamOverlayWeapons"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawTeamOverlayWeapons`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Draw each player's current weapon on the team overlay

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Weapon icons are not drawn | [codemp/ui/ui_xdocs.h:149](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L149) |
| `1` | Weapon icons are drawn | [codemp/ui/ui_xdocs.h:149](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L149) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`d6c87b2e66e9`](https://github.com/taysta/TaystJK/commit/d6c87b2e66e925c9dd76a528f7830560343b011b) on `2022-05-12` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:56](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L56)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2022-05-12` | [`d6c87b2e66e9`](https://github.com/taysta/TaystJK/commit/d6c87b2e66e925c9dd76a528f7830560343b011b) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2022-05-12` | [`d6c87b2e66e9`](https://github.com/videoP/jaPRO/commit/d6c87b2e66e925c9dd76a528f7830560343b011b) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2026-08-06` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`17085eaeadd0`](https://github.com/taysta/TaystJK/commit/17085eaeadd029b670346330588de005c6c41158) · [PR #356](https://github.com/taysta/TaystJK/pull/356)<br>Merge pull request #356 from taysta/teamoverlay3 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/ui/ui_xdocs.h` | `high` |
| `2026-08-06` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`82170607810e`](https://github.com/taysta/TaystJK/commit/82170607810e21c8d5ee7356cfbfec1e216443c7) · [PR #357](https://github.com/taysta/TaystJK/pull/357)<br>Merge pull request #357 from taysta/overlay3 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:56](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L56) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:6706](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6706)
- behavior: [codemp/cgame/cg_draw.c:6165](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6165)
- behavior: [codemp/cgame/cg_draw.c:6257](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6257)
- behavior: [codemp/cgame/cg_draw.c:6513](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6513)
- behavior: [codemp/ui/ui_xdocs.h:149](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L149)
- documentation: [codemp/ui/ui_xdocs.h:149](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L149)
