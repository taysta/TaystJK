---
title: "cg_drawScoreY"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawScoreY`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Vertical offset for score counter on HUD

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
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`4e5065dabda1`](https://github.com/taysta/TaystJK/commit/4e5065dabda1ea838fc9aa8bb9eaccaa161770fc) on `2026-06-01` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#309](https://github.com/taysta/TaystJK/pull/309)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:86](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L86)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-06-01` | [`4e5065dabda1`](https://github.com/taysta/TaystJK/commit/4e5065dabda1ea838fc9aa8bb9eaccaa161770fc) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-06-01` | [`4e5065dabda1`](https://github.com/videoP/jaPRO/commit/4e5065dabda1ea838fc9aa8bb9eaccaa161770fc) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:86](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L86) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:2221](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L2221)
- behavior: [codemp/cgame/cg_draw.c:2230](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L2230)
- behavior: [codemp/ui/ui_xdocs.h:275](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L275)
- documentation: [codemp/ui/ui_xdocs.h:275](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L275)
