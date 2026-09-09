---
title: "ui_RGBSkin"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_RGBSkin`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_RGBSkin` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_player.menu:399](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_player.menu#L399), [ingame_player.menu:422](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_player.menu#L422), [ingame_player.menu:450](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_player.menu#L450) |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`852cd1037427`](https://github.com/eternalcodes/EternalJK/commit/852cd10374272a0195a05ac15e9b69c2313ecaff) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-03-23`, integrated `2018-03-23`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:159](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L159)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-03-23` | — | `2018-03-23` | [`852cd1037427`](https://github.com/eternalcodes/EternalJK/commit/852cd10374272a0195a05ac15e9b69c2313ecaff) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-03-23` | — | `2018-03-23` | [`852cd1037427`](https://github.com/taysta/TaystJK/commit/852cd10374272a0195a05ac15e9b69c2313ecaff) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-03-23` | — | `2018-03-23` | [`852cd1037427`](https://github.com/videoP/jaPRO/commit/852cd10374272a0195a05ac15e9b69c2313ecaff) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-03-23` | — | `2018-03-23` | [`852cd1037427`](https://github.com/JKSunny/EternalJK/commit/852cd10374272a0195a05ac15e9b69c2313ecaff) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64c30d214890`](https://github.com/eternalcodes/EternalJK/commit/64c30d214890ebf8e957add24c6707858d8c7318)<br>Show name of selected model in profile menu+other improvements | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:161](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L161) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:8897](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8897)
- behavior: [codemp/ui/ui_main.c:8899](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8899)
- behavior: [codemp/ui/ui_main.c:8904](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8904)
- behavior: [codemp/ui/ui_main.c:8906](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8906)
- behavior: [codemp/ui/ui_main.c:8910](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8910)
