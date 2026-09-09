---
title: "r_environmentMapping"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_environmentMapping`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_environmentMapping` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vanilla/tr_shade.cpp:1482](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1482) |
| `1` | Enabled. | [codemp/rd-vanilla/tr_shade.cpp:1482](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1482) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `renderer` | `rd-vanilla` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-24`, integrated `2013-04-24`)
- Upstream registration evidence: [code/rd-vanilla/tr_init.cpp:1680](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/rd-vanilla/tr_init.cpp#L1680)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/eternalcodes/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/SomaZ/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/taysta/TaystJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/videoP/jaPRO/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/jkanewmod/NewJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-24` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JKSunny/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2017-09-26` | — | `2017-09-27` | [`27e6c03d2847`](https://github.com/mvdevs/jk2mv/commit/27e6c03d28479603c38481ae51110769f8c71162) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-11-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4c354bf32268`](https://github.com/JACoders/OpenJK/commit/4c354bf3226847d16206ad1c5f7bdc7b14f750ba)<br>[SP] Add r_environmentMapping to enable/disable environment mapping effects (for performance on low-end machines) | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:1642](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1642) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:793](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L793) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1482](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1482)
