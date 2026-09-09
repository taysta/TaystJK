---
title: "r_aspectCorrectFonts"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_aspectCorrectFonts`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_aspectCorrectFonts` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/rd-common/tr_font.cpp:1458](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1458) |
| `2` | Selects the code path tested for value 2. | [codemp/rd-common/tr_font.cpp:1461](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1461) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-rend2` | `always` |
| `0` | `renderer` | `rd-vanilla` | `always` |
| `0` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`e00a7df65aac`](https://github.com/JACoders/OpenJK/commit/e00a7df65aac75b175b8dea40b9fc1f60ecdaf70) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2015-10-26`, integrated `2015-10-28`)
- TaystJK integration evidence: [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1619](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-rend2/tr_init.cpp#L1619)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2015-10-26` | — | `2015-10-28` | [`e00a7df65aac`](https://github.com/JACoders/OpenJK/commit/e00a7df65aac75b175b8dea40b9fc1f60ecdaf70) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2015-10-26` | — | `2015-10-28` | [`e00a7df65aac`](https://github.com/SomaZ/OpenJK/commit/e00a7df65aac75b175b8dea40b9fc1f60ecdaf70) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2015-10-26` | — | `2015-10-28` | [`e00a7df65aac`](https://github.com/jkanewmod/NewJK/commit/e00a7df65aac75b175b8dea40b9fc1f60ecdaf70) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-10-26` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/eternalcodes/EternalJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-10-26` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-10-26` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/videoP/jaPRO/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-10-26` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/JKSunny/EternalJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1695](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1695) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1742](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1742) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:904](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L904) (Cvar_Get)
- behavior: [codemp/rd-common/tr_font.cpp:1458](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1458)
- behavior: [codemp/rd-common/tr_font.cpp:1461](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1461)
- behavior: [codemp/rd-common/tr_font.cpp:1760](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1760)
- behavior: [codemp/rd-common/tr_font.cpp:1764](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1764)
- behavior: [codemp/rd-common/tr_font.cpp:1468](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1468)
