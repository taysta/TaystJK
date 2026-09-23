---
title: "slotnext"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `slotnext`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_PrevWeaponSlot_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2024-02-28 in [`baa02905f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `slotnext` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2023-12-27`, PR opened `2024-02-03`, integrated `2024-02-27`)
- Origin pull request: [#130](https://github.com/taysta/TaystJK/pull/130)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2480](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2480)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-12-27` | [2024-02-03](https://github.com/taysta/TaystJK/pull/130) | `2024-02-27` | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-12-27` | — | `2024-02-27` | [`baa02905f40f`](https://github.com/videoP/jaPRO/commit/baa02905f40f33652a2ae326fe55ece2642169c1) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2480](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L2480) (cgame command table)
- handler: [codemp/cgame/cg_weapons.c:2081](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_weapons.c#L2081)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
