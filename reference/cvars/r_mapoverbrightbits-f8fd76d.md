---
title: "r_mapOverBrightBits"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_mapOverBrightBits`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_mapOverBrightBits` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2013-04-16 in [`cefb950a8`](https://github.com/taysta/TaystJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vanilla/tr_bsp.cpp:105](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vanilla/tr_bsp.cpp#L105) |
| `1` | Enabled. | [codemp/rd-vanilla/tr_bsp.cpp:105](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vanilla/tr_bsp.cpp#L105) |

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-rend2` | `always` |
| `0` | `renderer` | `rd-vanilla` | `always` |
| `0` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`cefb950a82f7`](https://github.com/JACoders/OpenJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-17`, integrated `2013-04-17`)
- Upstream registration evidence: [code/rd-vanilla/tr_init.cpp:1540](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/rd-vanilla/tr_init.cpp#L1540)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/JACoders/OpenJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/eternalcodes/EternalJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/SomaZ/OpenJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/taysta/TaystJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/videoP/jaPRO/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/jkanewmod/NewJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-17` | — | `2013-04-17` | [`cefb950a82f7`](https://github.com/JKSunny/EternalJK/commit/cefb950a82f7161ea280010aaebc9ab8bce17003) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1a0acea5b795`](https://github.com/JACoders/OpenJK/commit/1a0acea5b795b79781a21b18029721d2f3917be1)<br>Port r_mapOverBrightBits over to SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-03-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d9f4ab9f4bf7`](https://github.com/JACoders/OpenJK/commit/d9f4ab9f4bf797b6ce8300d7d375a9d6187e427c)<br>Potential fix for issue #624 | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_bsp.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp`, `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp` | `high` |
| `2022-02-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`507a46dfc17d`](https://github.com/taysta/TaystJK/commit/507a46dfc17d8d55b8bd13918a2522467fd24683)<br>Collection of code cleanup and refactoring. Plus recent quake3e changes | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_bsp.cpp`, `shared/rd-rend2/tr_local.h`, `shared/rd-rend2/tr_scene.cpp` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9693491bc25a`](https://github.com/taysta/TaystJK/commit/9693491bc25abec6748a229e858aaa613db03064) · [PR #346](https://github.com/taysta/TaystJK/pull/346)<br>Merge pull request #346 from taysta/rend2-cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1603](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-rend2/tr_init.cpp#L1603) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1659](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vanilla/tr_init.cpp#L1659) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:811](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L811) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:105](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vanilla/tr_bsp.cpp#L105)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:139](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vanilla/tr_bsp.cpp#L139)
- behavior: [codemp/rd-vulkan/tr_bsp.cpp:129](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_bsp.cpp#L129)
- behavior: [shared/rd-rend2/tr_bsp.cpp:111](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_bsp.cpp#L111)
- behavior: [shared/rd-rend2/tr_bsp.cpp:147](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_bsp.cpp#L147)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
