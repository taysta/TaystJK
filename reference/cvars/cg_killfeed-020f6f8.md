---
title: "cg_killfeed"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_killfeed`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Draw a killfeed on the HUD

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable the HUD killfeed | [codemp/ui/ui_xdocs.h:524](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L524) |
| `1` | Draw killfeed HUD | [codemp/ui/ui_xdocs.h:524](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L524) |
| `2` | Draw killfeed HUD + console death messages | [codemp/ui/ui_xdocs.h:525](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L525) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`0c734b5f2ee4`](https://github.com/taysta/TaystJK/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) on `2023-10-05` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#13](https://github.com/taysta/TaystJK/pull/13)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:427](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L427)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-05` | [`0c734b5f2ee4`](https://github.com/taysta/TaystJK/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-05` | [`0c734b5f2ee4`](https://github.com/videoP/jaPRO/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-11-01` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`8b2ad42d2ad0`](https://github.com/taysta/TaystJK/commit/8b2ad42d2ad0d52f86bbe88e4f1361665c153f9c)<br>Fix various GCC warnings in CGAME. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9ab5d982d35b`](https://github.com/taysta/TaystJK/commit/9ab5d982d35b63227680f36dfb5c402264a0ddfe) · [PR #256](https://github.com/taysta/TaystJK/pull/256)<br>Merge pull request #256 from VincentMarnier/fix_killfeed | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:427](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L427) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:250](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L250)
- behavior: [codemp/cgame/cg_event.c:343](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L343)
- behavior: [codemp/cgame/cg_draw.c:11554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L11554)
- behavior: [codemp/cgame/cg_event.c:153](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L153)
- behavior: [codemp/ui/ui_xdocs.h:524](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L524)
- documentation: [codemp/ui/ui_xdocs.h:524](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L524)
