---
title: "sv_hibernateTime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_hibernateTime`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Time after which server will enter hibernation mode

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- TaystJK integration evidence: [`987d8cc36a14`](https://github.com/taysta/TaystJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-12` | — | `2018-10-12` | [`987d8cc36a14`](https://github.com/eternalcodes/EternalJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-12` | — | `2018-10-12` | [`987d8cc36a14`](https://github.com/taysta/TaystJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-12` | — | `2018-10-12` | [`987d8cc36a14`](https://github.com/videoP/jaPRO/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-12` | — | `2018-10-12` | [`987d8cc36a14`](https://github.com/JKSunny/EternalJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ad37f1c112`](https://github.com/eternalcodes/EternalJK/commit/67ad37f1c11297fd91b800f65a74274c51c74c7b)<br>hibernation cleanup a lil? | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1066](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1066) (Cvar_Get)
- behavior: [codemp/server/sv_main.cpp:1208](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1208)
- behavior: [codemp/server/sv_main.cpp:1210](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1210)
