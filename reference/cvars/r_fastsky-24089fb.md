---
title: "r_fastsky"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_fastsky`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_fastsky` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `10` | Selects the code path tested for value 10. | [codemp/rd-vanilla/tr_backend.cpp:490](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L490) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-dedicated` | `always` |
| `0` | `renderer` | `rd-rend2` | `always` |
| `0` | `renderer` | `rd-vanilla` | `always` |
| `0` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1162](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1162)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_backend.cpp` and 4 more | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16007a014e0b`](https://github.com/JACoders/OpenJK/commit/16007a014e0ba10d7b4b7295e38ac7d1e315fcbc)<br>19 externals left to fix in the SP modular renderer, doing a push/pull break here | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-10-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c27f03202a2`](https://github.com/eternalcodes/EternalJK/commit/2c27f03202a2b11371544b9385b77f6867d677b3)<br>Added cvars to control sky color with r_fastSky 1 | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c4dbdc2a6f8c`](https://github.com/eternalcodes/EternalJK/commit/c4dbdc2a6f8c589b1bfc42371df61781af8e9324)<br>Use colortable with r_fastsky setting instead of RGB values | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_backend.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp`, `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` and 2 more | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp`, `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/tr_main.cpp` and 2 more | `high` |
| `2022-02-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`507a46dfc17d`](https://github.com/taysta/TaystJK/commit/507a46dfc17d8d55b8bd13918a2522467fd24683)<br>Collection of code cleanup and refactoring. Plus recent quake3e changes | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp` | `medium` |
| `2022-02-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`723c24a13050`](https://github.com/JKSunny/EternalJK/commit/723c24a130509bedc156847c5dbc4b5bf39ed0fb)<br>Vulkan: Fixed entity wall clipping & refactor fastsky color for performance | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp`, `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/vk_init.cpp` | `high` |
| `2022-04-18` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`750ad57bb2b8`](https://github.com/JKSunny/EternalJK/commit/750ad57bb2b8e0fba43408a5c26d0a2c79c2935d)<br>Vulkan: Add missing skyboxportal if statements & some slight code cleanup | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_sky.cpp` | `high` |
| `2022-08-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`f860949a22ea`](https://github.com/taysta/TaystJK/commit/f860949a22eaf6065eaac2bae0275dd15de182ae)<br>Merge branch 'master' of https://github.com/JKSunny/EternalJK | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_backend.cpp`, `codemp/rd-vulkan/tr_cmds.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_backend.cpp`, `shared/rd-rend2/tr_local.h`, `shared/rd-rend2/tr_main.cpp` and 1 more | `medium` |
| `2024-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c7590dfd5fd2`](https://github.com/taysta/TaystJK/commit/c7590dfd5fd2f09108ad4d14d370cf7bafc0c9b2) · [PR #190](https://github.com/taysta/TaystJK/pull/190)<br>Upstream vulkan updates (#190) | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_main.cpp` | `medium` |
| `2025-04-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`af6ffb138de4`](https://github.com/taysta/TaystJK/commit/af6ffb138de4b9bfd4a32373103d7f703386baa1) · [PR #220](https://github.com/taysta/TaystJK/pull/220)<br>Vulkan update (#220) | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/tr_main.cpp`, `codemp/rd-vulkan/tr_sky.cpp` and 1 more | `medium` |
| `2025-12-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3bfd04758bfb`](https://github.com/taysta/TaystJK/commit/3bfd04758bfbb105151f2d3cdc3f3629330982f1) · [PR #284](https://github.com/taysta/TaystJK/pull/284)<br>Merge pull request #284 from taysta/upstream | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_main.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:367](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L367) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1619](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1619) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1677](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1677) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:835](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L835) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:479](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L479)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:487](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L487)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:490](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L490)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:502](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L502)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:508](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L508)
