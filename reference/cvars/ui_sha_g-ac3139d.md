---
title: "ui_sha_g"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_sha_g`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_sha_g` in the ui module. Consult the cited behavior reads before relying on values not listed here.

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
| In-game menu | Yes — [ingame_strafehelper.menu:141](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_strafehelper.menu#L141), [ingame_strafehelper.menu:161](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_strafehelper.menu#L161), [ingame_strafehelper.menu:184](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_strafehelper.menu#L184) |
| Default | `255` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`6d7bc5b9ec68`](https://github.com/eternalcodes/EternalJK/commit/6d7bc5b9ec6885510f41f500aa62bb0da1a0e770) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2015-04-11`, integrated `2015-04-11`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:151](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L151)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-11` | — | `2015-04-11` | [`6d7bc5b9ec68`](https://github.com/eternalcodes/EternalJK/commit/6d7bc5b9ec6885510f41f500aa62bb0da1a0e770) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-11` | — | `2015-04-11` | [`6d7bc5b9ec68`](https://github.com/taysta/TaystJK/commit/6d7bc5b9ec6885510f41f500aa62bb0da1a0e770) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-11` | — | `2015-04-11` | [`6d7bc5b9ec68`](https://github.com/videoP/jaPRO/commit/6d7bc5b9ec6885510f41f500aa62bb0da1a0e770) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-11` | — | `2015-04-11` | [`6d7bc5b9ec68`](https://github.com/JKSunny/EternalJK/commit/6d7bc5b9ec6885510f41f500aa62bb0da1a0e770) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af03fc05496`](https://github.com/eternalcodes/EternalJK/commit/2af03fc054963a7aaac766707e09e810c77f3a0c)<br>UI code to change cg_strafeHelperActiveColor RGBA values in realtime. Thanks Raz0r! :) | Changed an exact bound cvar-variable reference. `codemp/ui/ui_cvar.c` | `medium` |
| `2015-04-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b987d21b2dd1`](https://github.com/eternalcodes/EternalJK/commit/b987d21b2dd1f5794d6f3112bced14743609323d)<br>Loda's fix for cg_strafeHelperActiveColor, less bloat. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_cvar.c`, `codemp/ui/ui_xcvar.h` | `medium` |
| `2016-09-30` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`5b7d8d89e02c`](https://github.com/videoP/jaPRO/commit/5b7d8d89e02c9852395b59575bcd07dde759a368)<br>Remove japro support | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_cvar.c`, `codemp/ui/ui_xcvar.h` | `high` |
| `2017-12-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b0b6ee187247`](https://github.com/videoP/jaPRO/commit/b0b6ee1872471eaed87e815be25d7926199c1181)<br>Revert "Remove japro support" | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_cvar.c`, `codemp/ui/ui_xcvar.h` | `high` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_cvar.c` | `high` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:153](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L153) (XCVAR_DEF)
- behavior: [codemp/ui/ui_cvar.c:91](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_cvar.c#L91)
- behavior: [codemp/cgame/cg_cvar.c:122](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_cvar.c#L122)
