---
title: "cg_predictKnockback"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Predict self-inflicted rocket-jump knockback clientside (racemode only). Use with cg_simulatedProjectiles 1."
---

# `cg_predictKnockback`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Predict self-inflicted rocket-jump knockback clientside (racemode only). Use with cg_simulatedProjectiles 1.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | Gameplay & combat |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-09-03 in [`bdcd618c6`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | Yes: [codemp/ui/ui_xdocs.h:613](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L613) |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Knockback is not predicted (default) | [codemp/ui/ui_xdocs.h:614](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L614) |
| `1` | Predict and apply rocket-jump knockback | [codemp/ui/ui_xdocs.h:614](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L614) |
| `2` | Verbose trajectory/timing logging (fire, detect, render, clear, actual) | [codemp/ui/ui_xdocs.h:614](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L614) |
| `3` | Maximum logging; adds forward-trace detection and per-command injection | [codemp/ui/ui_xdocs.h:616](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L616) |
| `4` | Damage/distance logging only (trajectory spam suppressed) | [codemp/ui/ui_xdocs.h:617](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L617) |
| `5` | Impulse/injection logging; adds per-command injection trace | [codemp/ui/ui_xdocs.h:618](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L618) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:190](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L190)
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
| `2023-12-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`06c84155e1fb`](https://github.com/videoP/jaPRO/commit/06c84155e1fb0b3aecfdffd9488d910345d80ea1) · [PR #65](https://github.com/taysta/TaystJK/pull/65)<br>Japro fixup (#65) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c` | `high` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c`, `codemp/cgame/cg_localents.c`, `codemp/cgame/cg_predict.c` and 2 more | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:193](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_xcvar.h#L193) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:3415](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_event.c#L3415)
- behavior: [codemp/cgame/cg_event.c:3422](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_event.c#L3422)
- behavior: [codemp/cgame/cg_event.c:3442](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_event.c#L3442)
- behavior: [codemp/cgame/cg_event.c:3493](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_event.c#L3493)
- behavior: [codemp/cgame/cg_event.c:3500](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/cgame/cg_event.c#L3500)
- documentation: [codemp/ui/ui_xdocs.h:613](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/ui/ui_xdocs.h#L613)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/b35ed06fec41c53644352743c6b199a5d5d500f3"><code>b35ed06fec41</code></a> on 2026-09-27. Anything merged after that is not reflected here.</p>
