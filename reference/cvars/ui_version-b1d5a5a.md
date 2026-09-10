---
title: "ui_version"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_version`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Used by UI in the in-game "about" menu

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_about.menu:267](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_about.menu#L267) |
| Default | `Info_ValueForKey(info, "version")` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`e4ececfdb4d1`](https://github.com/eternalcodes/EternalJK/commit/e4ececfdb4d1033473d6f502615964281530d401) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-10-04`, integrated `2018-10-04`)
- Upstream registration evidence: [codemp/cgame/cg_servercmds.c:235](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_servercmds.c#L235)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-04` | — | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/eternalcodes/EternalJK/commit/e4ececfdb4d1033473d6f502615964281530d401) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-04` | — | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/taysta/TaystJK/commit/e4ececfdb4d1033473d6f502615964281530d401) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-04` | — | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/videoP/jaPRO/commit/e4ececfdb4d1033473d6f502615964281530d401) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-04` | — | `2018-10-04` | [`e4ececfdb4d1`](https://github.com/JKSunny/EternalJK/commit/e4ececfdb4d1033473d6f502615964281530d401) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_servercmds.c:236](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L236) (implicit Cvar_Set)
- behavior: [codemp/ui/ui_main.c:3364](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L3364)
- behavior: [assets/japro/ui/jamp/menudef.h:346](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/menudef.h#L346)
- behavior: [codemp/ui/menudef.h:346](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/menudef.h#L346)
- behavior: [codemp/ui/ui_main.c:3084](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L3084)
- behavior: [codemp/ui/ui_main.c:3087](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L3087)
