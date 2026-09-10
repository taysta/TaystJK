---
title: "cg_cleanChatbox"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_cleanChatbox`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

1=Remove all colors from chat msgs, 2=Only remove color at begining of message

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Feature family | Chat box |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Remove all colors from chat msgs. | [docs/japro_docs.md:438](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L438) |
| `2` | Only remove color at begining of message. | [docs/japro_docs.md:438](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L438) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:239](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L239)
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
| `2018-10-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1f7372a12f75`](https://github.com/eternalcodes/EternalJK/commit/1f7372a12f75401e957309553276d10991aa7c10)<br>some clientside anti spam with cg_cleanchatbox | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2018-10-31` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`46a7d656b2da`](https://github.com/eternalcodes/EternalJK/commit/46a7d656b2da01c2204fc05839b8d6ec34a8d50b)<br>simplify cleanchatbox, add UU Media - Currently playing to filter | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2018-11-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3aede11696e8`](https://github.com/eternalcodes/EternalJK/commit/3aede11696e888af65c479dca846945e2b5bcd59)<br>redo cleanchatbox again | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`180b40ba0cc1`](https://github.com/eternalcodes/EternalJK/commit/180b40ba0cc1327c8eb50f2e15e94d60541ecfb8)<br>Chatbox/cgame chatlog code cleanup. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7810594c683a`](https://github.com/eternalcodes/EternalJK/commit/7810594c683a50d643a0075ef3f9cd6473dd9ae6)<br>cg_chatSounds 2 will only beep for private and team messages | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2020-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`88ad023daf23`](https://github.com/eternalcodes/EternalJK/commit/88ad023daf2331e142902f8a284717f15bbee648)<br>Fix cg_chatSounds 2 setting | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:242](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L242) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:10733](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10733)
- behavior: [codemp/cgame/cg_draw.c:10736](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10736)
- behavior: [codemp/cgame/cg_servercmds.c:1732](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1732)
- behavior: [codemp/cgame/cg_draw.c:10702](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10702)
- behavior: [codemp/cgame/cg_servercmds.c:1695](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1695)
- documentation: [docs/japro_docs.md:438](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L438)
