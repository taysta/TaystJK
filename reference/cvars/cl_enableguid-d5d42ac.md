---
title: "cl_enableGuid"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_enableGuid`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Enable GUID userinfo identifier

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
| `0` | Disabled. | [codemp/client/cl_main.cpp:868](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L868) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:868](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L868) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`bad3bbcc9ae6`](https://github.com/JACoders/OpenJK/commit/bad3bbcc9ae69fa8bd75fd760f20371226b50f95) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2015-09-05`, integrated `2015-11-19`)
- TaystJK integration evidence: [`d5970a9804aa`](https://github.com/taysta/TaystJK/commit/d5970a9804aad8ebe9bd8989c4e9e2354b627667)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2822](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2822)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, rend2, newjk; fork-lineage order selects openjk. The TaystJK integration evidence credits japro as an immediate port source, but openjk has an earlier dated introduction and remains the ultimate origin.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2015-09-05` | — | `2015-11-19` | [`bad3bbcc9ae6`](https://github.com/JACoders/OpenJK/commit/bad3bbcc9ae69fa8bd75fd760f20371226b50f95) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2015-09-05` | — | `2015-11-19` | [`bad3bbcc9ae6`](https://github.com/SomaZ/OpenJK/commit/bad3bbcc9ae69fa8bd75fd760f20371226b50f95) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2015-09-05` | — | `2015-11-19` | [`bad3bbcc9ae6`](https://github.com/jkanewmod/NewJK/commit/bad3bbcc9ae69fa8bd75fd760f20371226b50f95) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-09-05` | — | `2015-11-24` | [`d5970a9804aa`](https://github.com/eternalcodes/EternalJK/commit/d5970a9804aad8ebe9bd8989c4e9e2354b627667) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-09-05` | — | `2015-11-24` | [`d5970a9804aa`](https://github.com/taysta/TaystJK/commit/d5970a9804aad8ebe9bd8989c4e9e2354b627667) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-09-05` | — | `2015-11-24` | [`d5970a9804aa`](https://github.com/videoP/jaPRO/commit/d5970a9804aad8ebe9bd8989c4e9e2354b627667) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-09-05` | — | `2015-11-24` | [`d5970a9804aa`](https://github.com/JKSunny/EternalJK/commit/d5970a9804aad8ebe9bd8989c4e9e2354b627667) | Other project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-japro">jaPRO</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3398](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3398) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:868](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L868)
- behavior: [codemp/client/cl_main.cpp:3257](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3257)
