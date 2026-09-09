---
title: "cg_simulatedProjectiles"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_simulatedProjectiles`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Wether to use simulated projectiles so bullets appear instantly. Values > 1 don't draw the projectile right away.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:143](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L143)
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
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2023-12-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`06c84155e1fb`](https://github.com/videoP/jaPRO/commit/06c84155e1fb0b3aecfdffd9488d910345d80ea1) · [PR #65](https://github.com/taysta/TaystJK/pull/65)<br>Japro fixup (#65) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c` | `high` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:146](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L146) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_weapons.c:2758](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L2758)
- behavior: [codemp/cgame/cg_localents.c:1215](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_localents.c#L1215)
- behavior: [codemp/cgame/cg_weapons.c:2433](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L2433)
- behavior: [codemp/ui/ui_xdocs.h:600](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L600)
- documentation: [docs/japro_docs.md:479](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L479)
