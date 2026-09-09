---
title: "cg_noRGBSabers"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_noRGBSabers`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_noRGBSabers` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_players.c:6061](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6061) |
| `1` | Enabled. | [codemp/cgame/cg_players.c:6061](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6061) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:340](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L340)
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
| `2018-09-09` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3a666309b2fb`](https://github.com/eternalcodes/EternalJK/commit/3a666309b2fbf626fb606973cb1e8a7221d34872)<br>Fix black sabers | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d6357a63bc5d`](https://github.com/eternalcodes/EternalJK/commit/d6357a63bc5dc9347d729d3ca14742eaf66422c6)<br>Fixed black sabers | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2020-06-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a43a3418a405`](https://github.com/eternalcodes/EternalJK/commit/a43a3418a40564fc48038585ad6054b6df79dba2)<br>Fix NPC console spam+fix cg_drawHitBox on local player | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`36723927b9d2`](https://github.com/taysta/TaystJK/commit/36723927b9d211e22dbe7b9719a8b9dd10d1830b) · [PR #254](https://github.com/taysta/TaystJK/pull/254)<br>Merge pull request #254 from taysta/feature-flags | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:342](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L342) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_players.c:6061](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6061)
- behavior: [codemp/cgame/cg_players.c:6064](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6064)
- behavior: [codemp/cgame/cg_players.c:6066](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6066)
- behavior: [codemp/cgame/cg_players.c:6059](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6059)
