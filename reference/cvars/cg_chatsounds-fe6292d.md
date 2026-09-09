---
title: "cg_chatSounds"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_chatSounds`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Play sound when chat messages are received

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
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:388](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L388) |
| In-game menu | Yes — [ingame_setup.menu:4600](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L4600) |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Don't play chat sounds | [codemp/ui/ui_xdocs.h:388](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L388) |
| `1` | Play chat sounds for all messages | [codemp/ui/ui_xdocs.h:388](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L388) |
| `2` | Play chat sounds for private and team messages only | [codemp/ui/ui_xdocs.h:389](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L389) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:118](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L118)
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
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`180b40ba0cc1`](https://github.com/eternalcodes/EternalJK/commit/180b40ba0cc1327c8eb50f2e15e94d60541ecfb8)<br>Chatbox/cgame chatlog code cleanup. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7810594c683a`](https://github.com/eternalcodes/EternalJK/commit/7810594c683a50d643a0075ef3f9cd6473dd9ae6)<br>cg_chatSounds 2 will only beep for private and team messages | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_servercmds.c`, `codemp/ui/ui_xdocs.h` | `medium` |
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`88ad023daf23`](https://github.com/eternalcodes/EternalJK/commit/88ad023daf2331e142902f8a284717f15bbee648)<br>Fix cg_chatSounds 2 setting | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:121](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L121) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_servercmds.c:1715](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1715)
- behavior: [codemp/cgame/cg_servercmds.c:1736](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1736)
- behavior: [codemp/cgame/cg_draw.c:9722](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L9722)
- behavior: [codemp/cgame/cg_servercmds.c:1721](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1721)
- behavior: [codemp/cgame/cg_servercmds.c:1738](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1738)
- documentation: [codemp/ui/ui_xdocs.h:388](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L388)
