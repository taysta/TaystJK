---
title: "cg_snapHudRgba2"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_snapHudRgba2`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Color for two keys pressed

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `127 127 127 38` |
| Value type | `color` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) on `2024-03-02` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#46](https://github.com/taysta/TaystJK/pull/46)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:439](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L439)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-03-02` | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-03-02` | [`1d4c081cb762`](https://github.com/videoP/jaPRO/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:439](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L439) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_cvar.c:143](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_cvar.c#L143)
- behavior: [codemp/ui/ui_xdocs.h:554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L554)
- documentation: [codemp/ui/ui_xdocs.h:554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L554)
