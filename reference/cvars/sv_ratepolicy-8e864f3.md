---
title: "sv_ratePolicy"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_ratePolicy`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Determines which policy of enforcement is used for client's \"rate\" cvar

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/server/sv_client.cpp:1206](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1206) |
| `2` | Selects the code path tested for value 2. | [codemp/server/sv_client.cpp:1211](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1211) |

## Enforced ranges

- `1` through `2` (integer; Cvar_CheckRange) — [codemp/server/sv_init.cpp:990](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L990)

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`6aba69055e45`](https://github.com/JACoders/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2017-05-16`, integrated `2017-05-16`)
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [codemp/server/sv_init.cpp:958](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L958)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2017-05-16` | — | `2017-05-16` | [`6aba69055e45`](https://github.com/JACoders/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2017-05-16` | — | `2017-05-16` | [`6aba69055e45`](https://github.com/SomaZ/OpenJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-05-16` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/eternalcodes/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-05-16` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-05-16` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/videoP/jaPRO/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-05-16` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/JKSunny/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |

## Evidence

- registration: [codemp/server/sv_init.cpp:989](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L989) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:1206](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1206)
- behavior: [codemp/server/sv_client.cpp:1211](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1211)
- behavior: [codemp/server/sv_main.cpp:1061](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1061)
- behavior: [codemp/server/sv_main.cpp:1081](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1081)
- behavior: [codemp/server/sv_main.cpp:1054](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L1054)
