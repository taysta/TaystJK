---
title: "cg_scoreboardTime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_scoreboardTime`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Displays the local time on the scoreboard

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
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:190](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L190) |
| In-game menu | Yes — [ingame_setup.menu:4100](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L4100) |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_scoreboard.c:655](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_scoreboard.c#L655) |
| `1` | Enabled. | [codemp/cgame/cg_scoreboard.c:655](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_scoreboard.c#L655) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2022-04-03`, integrated `2022-04-20`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:69](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L69)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2022-04-03` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2022-04-03` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/videoP/jaPRO/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:69](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L69) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_scoreboard.c:655](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_scoreboard.c#L655)
- behavior: [codemp/ui/ui_xdocs.h:190](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L190)
- documentation: [codemp/ui/ui_xdocs.h:190](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L190)
