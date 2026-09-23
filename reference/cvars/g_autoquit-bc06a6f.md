---
title: "g_autoQuit"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_autoQuit`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_autoQuit` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-10-10 in [`2af38213b`](https://github.com/taysta/TaystJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_main.c:3566](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L3566) |
| `1` | Enabled. | [codemp/game/g_main.c:3566](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L3566) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`2af38213b793`](https://github.com/videoP/jaPRO/commit/2af38213b793183fd6313a195d0f36ea3aa02196) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-10-09`, integrated `2018-10-10`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:319](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L319)
- Attribution method: `shared-earliest-commit-module-lineage`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; module lineage selects japro. The squash feature group broadly credits eternaljk, but non-identifier-specific credit does not override the japro game-module provider lineage.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/taysta/TaystJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/videoP/jaPRO/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/JKSunny/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:318](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_xcvar.h#L318) (XCVAR_DEF)
- behavior: [codemp/game/g_main.c:3566](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L3566)
- behavior: [codemp/game/g_main.c:3567](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L3567)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
