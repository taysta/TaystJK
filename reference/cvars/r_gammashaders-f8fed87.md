---
title: "r_gammaShaders"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_gammaShaders`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Set gamma using pixel shaders inside the game window only.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vanilla/tr_init.cpp:718](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L718) |
| `1` | Enabled. | [codemp/rd-vanilla/tr_init.cpp:718](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L718) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `renderer` | `rd-vanilla` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`ead8e3618248`](https://github.com/JACoders/OpenJK/commit/ead8e36182483c48b624b7631ce0e37146054de7) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2015-07-25`, integrated `2015-07-25`)
- TaystJK integration evidence: [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)
- Upstream registration evidence: [codemp/rd-vanilla/tr_init.cpp:1575](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-vanilla/tr_init.cpp#L1575)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2015-07-25` | — | `2015-07-25` | [`ead8e3618248`](https://github.com/JACoders/OpenJK/commit/ead8e36182483c48b624b7631ce0e37146054de7) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2015-07-25` | — | `2015-07-25` | [`ead8e3618248`](https://github.com/SomaZ/OpenJK/commit/ead8e36182483c48b624b7631ce0e37146054de7) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2015-07-25` | — | `2015-07-25` | [`ead8e3618248`](https://github.com/jkanewmod/NewJK/commit/ead8e36182483c48b624b7631ce0e37146054de7) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-07-25` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/eternalcodes/EternalJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-07-25` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-07-25` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/videoP/jaPRO/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-07-25` | — | `2015-11-13` | [`5ef5d7214371`](https://github.com/JKSunny/EternalJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-01-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a2acfb6b9129`](https://github.com/eternalcodes/EternalJK/commit/a2acfb6b91293508500c339e92b2ee9033a9323b)<br>Merge pull request #11 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2025-04-15` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) · [PR #217](https://github.com/taysta/TaystJK/pull/217)<br>Rend2 update (#217) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:1641](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1641) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:792](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L792) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_init.cpp:718](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L718)
