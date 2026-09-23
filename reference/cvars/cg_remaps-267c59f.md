---
title: "cg_remaps"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cg_remaps`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Show or hide serverside remaps

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-09-03 in [`bdcd618c6`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | Yes: [codemp/ui/ui_xdocs.h:431](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L431) |
| In-game menu | Yes: [ingame_setup.menu:3531](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/assets/japro/ui/jamp/ingame_setup.menu#L3531) |
| Default | `1` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Don't show remaps | [codemp/ui/ui_xdocs.h:431](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L431) |
| `1` | Show remaps | [codemp/ui/ui_xdocs.h:432](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L432) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:126](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L126)
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
| `2020-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c4b88abcfd76`](https://github.com/eternalcodes/EternalJK/commit/c4b88abcfd7678f9186ebec0c20ac98dc986d6b5)<br>cosmetic unlock integration? (loda) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:129](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_xcvar.h#L129) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_servercmds.c:468](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_servercmds.c#L468)
- behavior: [codemp/cgame/cg_servercmds.c:470](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_servercmds.c#L470)
- behavior: [codemp/cgame/cg_servercmds.c:1782](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_servercmds.c#L1782)
- behavior: [codemp/ui/ui_xdocs.h:431](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L431)
- documentation: [codemp/ui/ui_xdocs.h:431](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_xdocs.h#L431)
- documentation: [docs/japro_docs.md:460](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/docs/japro_docs.md#L460)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
