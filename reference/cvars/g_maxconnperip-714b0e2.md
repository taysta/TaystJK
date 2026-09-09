---
title: "g_maxConnPerIP"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_maxConnPerIP`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_maxConnPerIP` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `3` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-07`, integrated `2013-04-07`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:118](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L118)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/eternalcodes/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/SomaZ/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/taysta/TaystJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/videoP/jaPRO/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/jkanewmod/NewJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JKSunny/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:117](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L117) (XCVAR_DEF)
- behavior: [codemp/game/g_client.c:2899](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2899)
- behavior: [codemp/game/g_client.c:2877](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2877)
