---
title: "g_forceClientUpdateRate"
layout: reference
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
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `250` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`77fa05762176`](https://github.com/JACoders/OpenJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) on `2013-08-28` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:100](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L100)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-08-28` | [`77fa05762176`](https://github.com/JACoders/OpenJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-08-28` | [`77fa05762176`](https://github.com/eternalcodes/EternalJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-08-28` | [`77fa05762176`](https://github.com/SomaZ/OpenJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-08-28` | [`77fa05762176`](https://github.com/taysta/TaystJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-08-28` | [`77fa05762176`](https://github.com/videoP/jaPRO/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-08-28` | [`77fa05762176`](https://github.com/jkanewmod/NewJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-08-28` | [`77fa05762176`](https://github.com/JKSunny/EternalJK/commit/77fa05762176f6a8eb4d0a0063497df557471eb5) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:98](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L98) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:6072](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L6072)
