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
| Category | Audio & music |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L413) |
| In-game menu | No |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Do not announce the start of duel | [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L413) |
| `1` | Announce and center print \"BEGIN\" (baseJKA behavior) | [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L413) |
| `2` | Announce, but do not center print | [codemp/ui/ui_xdocs.h:414](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L414) |
| `3` | Center print, but do not announce | [codemp/ui/ui_xdocs.h:415](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L415) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`8e774f08bc0d`](https://github.com/eternalcodes/EternalJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-07-29`, integrated `2019-07-29`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:98](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L98)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-07-29` | — | `2019-07-29` | [`8e774f08bc0d`](https://github.com/eternalcodes/EternalJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-07-29` | — | `2019-07-29` | [`8e774f08bc0d`](https://github.com/taysta/TaystJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-07-29` | — | `2019-07-29` | [`8e774f08bc0d`](https://github.com/videoP/jaPRO/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-07-29` | — | `2019-07-29` | [`8e774f08bc0d`](https://github.com/JKSunny/EternalJK/commit/8e774f08bc0d3e98a127b1c2b8e90438e3e1580e) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:124](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L124) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:1770](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L1770)
- behavior: [codemp/cgame/cg_event.c:1772](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L1772)
- behavior: [codemp/cgame/cg_event.c:1773](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L1773)
- behavior: [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L413)
- documentation: [codemp/ui/ui_xdocs.h:413](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L413)
