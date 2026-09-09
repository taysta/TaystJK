---
title: "cg_chatBoxCutOffLength"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatBoxCutOffLength`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Width of a line in the chatbox before breaking to a new one

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:232](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L232) |
| In-game menu | No |
| Default | `350` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `350` | jaPRO cutoff length | [codemp/ui/ui_xdocs.h:232](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L232) |
| `550` | baseJKA default | [codemp/ui/ui_xdocs.h:232](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L232) |
| `640` | Maximum | [codemp/ui/ui_xdocs.h:232](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L232) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:76](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L76)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-03` | — | `2018-09-03` | [`bdcd618c6771`](https://github.com/eternalcodes/EternalJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | — | `2018-09-03` | [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | — | `2018-09-03` | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-03` | — | `2018-09-03` | [`bdcd618c6771`](https://github.com/JKSunny/EternalJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-11-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3f8c6153ba79`](https://github.com/taysta/TaystJK/commit/3f8c6153ba79060a24c3fb5f4cf7e1af9bf8d77f)<br>Change CG_Text_Width to use trap->ext.R_FontStrLenPixels/use the only feature in the wonderful OpenJK mod API | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2018-12-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f3e570ad8f2e`](https://github.com/eternalcodes/EternalJK/commit/f3e570ad8f2efce123122d4376379e9984a00a7c)<br>Fix chatbox word wrap with colored strings. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbc6e7872c2b`](https://github.com/eternalcodes/EternalJK/commit/dbc6e7872c2b238f2515cd52cbd5f6cd6f303f93)<br>Add g_gametype description to xdocs (Artemis) | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`caa8f274580f`](https://github.com/JKSunny/EternalJK/commit/caa8f274580f151f8472d987144146ca02430d3f)<br>Merge remote-tracking branch 'JKSunny/features/Emojis' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2020-08-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3ea9b3c38f7b`](https://github.com/eternalcodes/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704)<br>cg_chatBoxShowCutoff + emoji crash+whitespacing fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:79](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L79) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10752](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10752)
- behavior: [codemp/cgame/cg_draw.c:10756](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10756)
- behavior: [codemp/cgame/cg_draw.c:10768](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10768)
- behavior: [codemp/cgame/cg_draw.c:10795](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10795)
- behavior: [codemp/cgame/cg_draw.c:10925](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10925)
- documentation: [codemp/ui/ui_xdocs.h:232](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L232)
