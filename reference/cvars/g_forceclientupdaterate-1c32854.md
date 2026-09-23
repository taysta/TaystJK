---
title: "g_forceClientUpdateRate"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_forceClientUpdateRate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_forceClientUpdateRate` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2013-08-29 in [`77fa05762`](https://github.com/taysta/TaystJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `250` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_NONE`: fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`77fa05762176`](https://github.com/JACoders/OpenJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-08-28`, integrated `2013-08-28`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:100](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L100)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/JACoders/OpenJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/eternalcodes/EternalJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/SomaZ/OpenJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/taysta/TaystJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/videoP/jaPRO/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/jkanewmod/NewJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-08-28` | — | `2013-08-28` | [`77fa05762176`](https://github.com/JKSunny/EternalJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:98](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_xcvar.h#L98) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:6072](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_active.c#L6072)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
