---
title: "cg_duelSounds"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_duelSounds`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Enables/disables announcer/center print at the start of private duels

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Do not announce the start of duel | [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L413) |
| `1` | Announce and center print \"BEGIN\" (baseJKA behavior) | [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L413) |
| `2` | Announce, but do not center print | [codemp/ui/ui_xdocs.h:414](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L414) |
| `3` | Center print, but do not announce | [codemp/ui/ui_xdocs.h:415](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L415) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`8e774f08bc0d`](https://github.com/eternalcodes/EternalJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) on `2019-07-29` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:98](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L98)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-07-29` | [`8e774f08bc0d`](https://github.com/eternalcodes/EternalJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-07-29` | [`8e774f08bc0d`](https://github.com/taysta/TaystJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-07-29` | [`8e774f08bc0d`](https://github.com/videoP/jaPRO/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-07-29` | [`8e774f08bc0d`](https://github.com/JKSunny/EternalJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:124](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L124) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:1770](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L1770)
- behavior: [codemp/cgame/cg_event.c:1772](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L1772)
- behavior: [codemp/cgame/cg_event.c:1773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L1773)
- behavior: [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L413)
- documentation: [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L413)
