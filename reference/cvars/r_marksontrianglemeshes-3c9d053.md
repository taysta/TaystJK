---
title: "r_marksOnTriangleMeshes"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_marksOnTriangleMeshes`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_marksOnTriangleMeshes` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
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
| `0` | Disabled. | [codemp/rd-vanilla/tr_marks.cpp:428](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_marks.cpp#L428) |
| `1` | Enabled. | [codemp/rd-vanilla/tr_marks.cpp:428](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_marks.cpp#L428) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-rend2` | `always` |
| `0` | `renderer` | `rd-vanilla` | `always` |
| `0` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`b858635e7298`](https://github.com/JACoders/OpenJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-03-18`, integrated `2014-03-18`)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1613](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-rend2/tr_init.cpp#L1613)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/JACoders/OpenJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/eternalcodes/EternalJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/SomaZ/OpenJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/taysta/TaystJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/videoP/jaPRO/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/jkanewmod/NewJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-03-18` | — | `2014-03-18` | [`b858635e7298`](https://github.com/JKSunny/EternalJK/commit/b858635e72986ef57c393eaf4e5c1cf4a07f9ca2) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1689](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1689) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1741](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1741) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:903](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L903) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_marks.cpp:428](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_marks.cpp#L428)
- behavior: [codemp/rd-vulkan/tr_marks.cpp:428](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_marks.cpp#L428)
- behavior: [shared/rd-rend2/tr_marks.cpp:436](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_marks.cpp#L436)
