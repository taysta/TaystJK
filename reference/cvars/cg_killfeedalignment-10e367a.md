---
title: "cg_killfeedAlignment"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_killfeedAlignment`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Align the killfeed

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
| `0` | Align items to the right | [codemp/ui/ui_xdocs.h:530](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L530) |
| `1` | Align items to the left | [codemp/ui/ui_xdocs.h:530](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L530) |
| `2` | Align items to the center | [codemp/ui/ui_xdocs.h:531](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L531) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`0c734b5f2ee4`](https://github.com/taysta/TaystJK/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) on `2023-10-05` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#13](https://github.com/taysta/TaystJK/pull/13)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:430](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L430)
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
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:430](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L430) (XCVAR_DEF)
- behavior: [codemp/cgame/hud_obituary.c:41](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_obituary.c#L41)
- behavior: [codemp/ui/ui_xdocs.h:530](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L530)
- documentation: [codemp/ui/ui_xdocs.h:530](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L530)
