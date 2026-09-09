---
title: "strafeHelper"
layout: reference
nav_exclude: true
search_exclude: false
---

# `strafeHelper`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_StrafeHelper_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Movement & race |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame.menu:972](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L972), [ingame_strafehelper.menu:32](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_strafehelper.menu#L32), [ingame_strafehelper.menu:52](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_strafehelper.menu#L52) |
| Syntax | `strafeHelper [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2509](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_consolecmds.c#L2509)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: japro retains origin because content authorship and PR submission predate the project that merged the work first. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/JKSunny/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | — | `2018-09-03` | [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | — | `2018-09-03` | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7bd5df22796d`](https://github.com/eternalcodes/EternalJK/commit/7bd5df22796d79cd2d117f49cca0d65375f1624d)<br>Prevent camera from jerking when toggling cg_thirdPerson/strafeHelper settings | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2023-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fe7a86d0fc89`](https://github.com/taysta/TaystJK/commit/fe7a86d0fc89a22cd46207bf7d49780721e4f20f) · [PR #10](https://github.com/taysta/TaystJK/pull/10)<br>Merge pull request #10 from taysta/dynamic-format-tables | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_atoms.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2509](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2509) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:1134](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1134)
