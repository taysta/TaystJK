---
title: "cg_newFont"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_newFont`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Uses a different font for the chat

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:212](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L212) |
| In-game menu | No |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Use the base font | [codemp/ui/ui_xdocs.h:212](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L212) |
| `1` | Use the new font | [codemp/ui/ui_xdocs.h:212](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L212) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:69](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L69)
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
| `2020-05-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`caa8f274580f`](https://github.com/JKSunny/EternalJK/commit/caa8f274580f151f8472d987144146ca02430d3f)<br>Merge remote-tracking branch 'JKSunny/features/Emojis' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ea53d3689287`](https://github.com/eternalcodes/EternalJK/commit/ea53d36892876a6a13184e6dfa84655185e48ab5)<br>Chatbox Emoji improvements+refactoring+cleanup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:72](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L72) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10831](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10831)
- behavior: [codemp/cgame/cg_draw.c:10833](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10833)
- behavior: [codemp/cgame/cg_draw.c:10883](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10883)
- behavior: [codemp/cgame/cg_draw.c:11038](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L11038)
- behavior: [codemp/cgame/cg_draw.c:10827](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10827)
- documentation: [codemp/ui/ui_xdocs.h:212](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L212)
