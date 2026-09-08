---
title: "cg_killMessage"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_killMessage`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Print a kill message on the screen when you kill someone

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Kill messages won't be printed | [codemp/ui/ui_xdocs.h:205](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L205) |
| `1` | Kill messages will be printed, showing score and placement in FFA mode (Base behavior) | [codemp/ui/ui_xdocs.h:205](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L205) |
| `2` | Kill messages will be printed, without score or current place in FFA mode | [codemp/ui/ui_xdocs.h:207](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L207) |
| `3` | Kill messages will be placed higher on the screen than normal | [codemp/ui/ui_xdocs.h:208](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L208) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) on `2018-09-03` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:68](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L68)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/eternalcodes/EternalJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/JKSunny/EternalJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-06-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d47618c07ab1`](https://github.com/eternalcodes/EternalJK/commit/d47618c07ab163f3f8549c78e8a26165c7a70877)<br>Fix kill centerprint messages cutting off long player names+CG_Obituary cleanup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |
| `2019-06-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`903ec12f6de8`](https://github.com/eternalcodes/EternalJK/commit/903ec12f6de8636d8fbe82126b228c8c93edab02)<br>cg_killMessage 2 will hide "Xnd place with points" line from kill messages | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |
| `2023-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c734b5f2ee4`](https://github.com/taysta/TaystJK/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) · [PR #13](https://github.com/taysta/TaystJK/pull/13)<br>Merge pull request #13 from taysta/killfeed | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9ab5d982d35b`](https://github.com/taysta/TaystJK/commit/9ab5d982d35b63227680f36dfb5c402264a0ddfe) · [PR #256](https://github.com/taysta/TaystJK/pull/256)<br>Merge pull request #256 from VincentMarnier/fix_killfeed | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:71](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L71) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:290](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L290)
- behavior: [codemp/cgame/cg_event.c:334](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L334)
- behavior: [codemp/cgame/cg_event.c:337](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L337)
- behavior: [codemp/cgame/cg_event.c:335](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_event.c#L335)
- behavior: [codemp/ui/ui_xdocs.h:205](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L205)
- documentation: [codemp/ui/ui_xdocs.h:205](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L205)
