---
title: "cg_disruptorTeamColor"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_disruptorTeamColor`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Changes disruptor effects colors according to team

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
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:344](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L344) |
| In-game menu | Yes — [ingame_setup.menu:3800](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L3800) |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/fx_disruptor.c:191](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/fx_disruptor.c#L191) |
| `1` | Enabled. | [codemp/cgame/fx_disruptor.c:191](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/fx_disruptor.c#L191) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2022-04-05`, integrated `2022-04-20`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:420](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L420)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2022-04-05` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2022-04-05` | — | `2022-04-20` | [`1dd571383a0d`](https://github.com/videoP/jaPRO/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:420](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L420) (XCVAR_DEF)
- behavior: [codemp/cgame/fx_disruptor.c:191](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/fx_disruptor.c#L191)
- behavior: [codemp/ui/ui_xdocs.h:344](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L344)
- documentation: [codemp/ui/ui_xdocs.h:344](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L344)
