---
title: "cg_drawTriggers"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cg_drawTriggers`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_drawTriggers` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | HUD & interface |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-09-03 in [`bdcd618c6`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_ents.c:385](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_ents.c#L385) |
| `1` | Enabled. | [codemp/cgame/cg_ents.c:385](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_ents.c#L385) |

## Flags

- `CVAR_NONE`: fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:236](https://github.com/videoP/jaPRO/blame/a4d22a138f1e055c8d8fe6109926dff84c4233a2/codemp/cgame/cg_xcvar.h#L236)
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
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:240](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_xcvar.h#L240) (XCVAR_DEF); condition `_DRAWTRIGGERS`
- behavior: [codemp/cgame/cg_ents.c:385](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_ents.c#L385)
- behavior: [codemp/cgame/cg_ents.c:391](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_ents.c#L391)
- behavior: [codemp/cgame/cg_ents.c:365](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_ents.c#L365)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f999cbc0912773164962d8be37737a31fe9ade8d"><code>f999cbc09127</code></a> on 2026-10-22. Anything merged after that is not reflected here.</p>
