---
title: "cg_logChat"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_logChat`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_logChat` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `8` | Enables the `JAPRO_CHATLOG_CENTERPRINT` code path. | [codemp/cgame/cg_local.h:163](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L163) |
| `1` | Enables the `JAPRO_CHATLOG_ENABLE` code path. | [codemp/cgame/cg_local.h:159](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L159) |
| `4` | Enables the `JAPRO_CHATLOG_OLDTIMESTAMP` code path. | [codemp/cgame/cg_local.h:161](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L161) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`f1b9b895897d`](https://github.com/eternalcodes/EternalJK/commit/f1b9b895897d19abcc7cfba7f63015a627e80df2) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2015-11-18`, integrated `2015-11-18`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:157](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L157)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-11-18` | — | `2015-11-18` | [`f1b9b895897d`](https://github.com/eternalcodes/EternalJK/commit/f1b9b895897d19abcc7cfba7f63015a627e80df2) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-11-18` | — | `2015-11-18` | [`f1b9b895897d`](https://github.com/taysta/TaystJK/commit/f1b9b895897d19abcc7cfba7f63015a627e80df2) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-11-18` | — | `2015-11-18` | [`f1b9b895897d`](https://github.com/videoP/jaPRO/commit/f1b9b895897d19abcc7cfba7f63015a627e80df2) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-11-18` | — | `2015-11-18` | [`f1b9b895897d`](https://github.com/JKSunny/EternalJK/commit/f1b9b895897d19abcc7cfba7f63015a627e80df2) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3deebad9ad1c`](https://github.com/eternalcodes/EternalJK/commit/3deebad9ad1c35afca75293469e744639ed0e636)<br>Revert "Added chat logs from japp" | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2018-12-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`328d55f0062f`](https://github.com/eternalcodes/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f)<br>Chatlog options configurable with /chatlog | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_main.c`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`180b40ba0cc1`](https://github.com/eternalcodes/EternalJK/commit/180b40ba0cc1327c8eb50f2e15e94d60541ecfb8)<br>Chatbox/cgame chatlog code cleanup. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_main.c`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c55cb9d28c23`](https://github.com/eternalcodes/EternalJK/commit/c55cb9d28c231c78a01be32ad62094f7f67f9c4f)<br>Engine chat logging - don't log "end log" message until something has been logged | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_main.c` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7810594c683a`](https://github.com/eternalcodes/EternalJK/commit/7810594c683a50d643a0075ef3f9cd6473dd9ae6)<br>cg_chatSounds 2 will only beep for private and team messages | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:186](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L186) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_consolecmds.c:1929](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1929)
- behavior: [codemp/cgame/cg_draw.c:10656](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10656)
- behavior: [codemp/cgame/cg_main.c:2718](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L2718)
- behavior: [codemp/cgame/cg_main.c:3123](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L3123)
- behavior: [codemp/cgame/cg_servercmds.c:1640](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L1640)
