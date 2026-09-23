---
title: "entityinfo"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `entityinfo`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_EntityInfo_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-02-04 in [`675e97128`](https://github.com/taysta/TaystJK/commit/675e97128f486095bc24289cf0610badfd8130fd) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `entityinfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`675e97128f48`](https://github.com/videoP/jaPRO/commit/675e97128f486095bc24289cf0610badfd8130fd) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-01-31`, integrated `2018-02-05`)
- Upstream registration evidence: [codemp/game/g_svcmds.c:1671](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_svcmds.c#L1671)
- Attribution method: `shared-earliest-commit-module-lineage`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; module lineage selects japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-01-31` | — | `2018-02-05` | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-01-31` | — | `2018-02-05` | [`675e97128f48`](https://github.com/taysta/TaystJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-01-31` | — | `2018-02-05` | [`675e97128f48`](https://github.com/videoP/jaPRO/commit/675e97128f486095bc24289cf0610badfd8130fd) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-01-31` | — | `2018-02-05` | [`675e97128f48`](https://github.com/JKSunny/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared integration commit |

## Evidence

- registration: [codemp/game/g_svcmds.c:1672](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L1672) (game-console command table)
- handler: [codemp/game/g_svcmds.c:308](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L308)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
