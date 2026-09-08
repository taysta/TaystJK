---
title: "cg_vehicleRange"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_vehicleRange`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Offset vehicle camera ranges (useful for ultrawide monitors)

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

- Ultimate-origin introduction: [`174a753ff414`](https://github.com/taysta/TaystJK/commit/174a753ff4143f03f7b6074675b1a63dac294dd6) on `2025-11-28` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#274](https://github.com/taysta/TaystJK/pull/274)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:367](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L367)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-11-28` | [`174a753ff414`](https://github.com/taysta/TaystJK/commit/174a753ff4143f03f7b6074675b1a63dac294dd6) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-11-28` | [`174a753ff414`](https://github.com/videoP/jaPRO/commit/174a753ff4143f03f7b6074675b1a63dac294dd6) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:367](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L367) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_view.c:423](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L423)
- behavior: [codemp/cgame/cg_view.c:424](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L424)
- behavior: [codemp/ui/ui_xdocs.h:583](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L583)
- documentation: [codemp/ui/ui_xdocs.h:583](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L583)
