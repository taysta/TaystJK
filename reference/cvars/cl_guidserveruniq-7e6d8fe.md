---
title: "cl_guidServerUniq"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_guidServerUniq`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Use a unique guid value per server

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_main.cpp:1186](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1186) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:1186](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1186) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`cccf3136bac2`](https://github.com/JACoders/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-07-15`, integrated `2013-07-17`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2823](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2823)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/JACoders/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/eternalcodes/EternalJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/SomaZ/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/taysta/TaystJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/videoP/jaPRO/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/jkanewmod/NewJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-07-15` | — | `2013-07-17` | [`cccf3136bac2`](https://github.com/JKSunny/EternalJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3399](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3399) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1186](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1186)
