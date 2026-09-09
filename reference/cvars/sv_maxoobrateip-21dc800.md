---
title: "sv_maxOOBRateIP"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_maxOOBRateIP`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Maximum rate of handling incoming server commands per IP address

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_main.cpp:740](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L740) |
| `1` | Enabled. | [codemp/server/sv_main.cpp:740](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L740) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-04-27`, integrated `2020-05-15`)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1021](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_init.cpp#L1021)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/taysta/TaystJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/videoP/jaPRO/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/JKSunny/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Shared integration commit |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2020-08-21` | — | `2020-08-21` | [`962f3198371a`](https://github.com/JACoders/OpenJK/commit/962f3198371a9c44093253cd04999155ac6a657f) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2020-08-21` | — | `2020-08-21` | [`962f3198371a`](https://github.com/SomaZ/OpenJK/commit/962f3198371a9c44093253cd04999155ac6a657f) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`701070354c7c`](https://github.com/eternalcodes/EternalJK/commit/701070354c7ca1e7bb1847d74b1710d23c52369f)<br>Fix OOB IP rate limiter breaking non-dedicated servers | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1052](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1052) (Cvar_Get)
- behavior: [codemp/server/sv_main.cpp:740](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L740)
- behavior: [codemp/server/sv_main.cpp:741](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L741)
