---
title: "com_bootlogo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_bootlogo`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Show intro movies

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/qcommon/common.cpp:1537](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1537) |
| `1` | Enabled. | [codemp/qcommon/common.cpp:1537](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1537) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9e2ed38faed0`](https://github.com/JACoders/OpenJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-07-27`, integrated `2013-07-27`)
- Upstream registration evidence: [code/qcommon/common.cpp:1154](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/common.cpp#L1154)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/JACoders/OpenJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/eternalcodes/EternalJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/SomaZ/OpenJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/taysta/TaystJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/videoP/jaPRO/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/jkanewmod/NewJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-07-27` | — | `2013-07-27` | [`9e2ed38faed0`](https://github.com/JKSunny/EternalJK/commit/9e2ed38faed06f59064add98791664ca02c82afa) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-04-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4210551db101`](https://github.com/JACoders/OpenJK/commit/4210551db101eb0f6e1cc69a79ef4e51924a4a3f)<br>[SP] Added com_affinity bit-flag to force which cores can be used | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ae9ed6a04d34`](https://github.com/eternalcodes/EternalJK/commit/ae9ed6a04d3429a5d602343a418a41c536d54dea)<br>Skip startup video | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1500](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1500) (Cvar_Get)
- behavior: [codemp/qcommon/common.cpp:1537](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1537)
