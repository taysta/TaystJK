---
title: "r_lightmap"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_lightmap`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_lightmap` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/rd-vanilla/tr_bsp.cpp:211](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L211) |

## Flags

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
- Upstream registration evidence: [code/renderer/tr_init.cpp:1205](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1205)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_bsp.cpp` and 3 more | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16007a014e0b`](https://github.com/JACoders/OpenJK/commit/16007a014e0ba10d7b4b7295e38ac7d1e315fcbc)<br>19 externals left to fix in the SP modular renderer, doing a push/pull break here | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`83d2ef4ac09a`](https://github.com/eternalcodes/EternalJK/commit/83d2ef4ac09a6b0d18f5ffff11929c3b4c835166)<br>Unlock all cheat-protected renderer cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`34634e7dbad8`](https://github.com/taysta/TaystJK/commit/34634e7dbad8c67aa20c146c2a53fe0dd93159a9)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-08-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e6191dc834e0`](https://github.com/eternalcodes/EternalJK/commit/e6191dc834e02202926adc8c5c873901d58ea27c)<br>Removed cheat protection for r_fullbright and r_lightmap as requested by pivot | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2016-08-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b09c476bd587`](https://github.com/eternalcodes/EternalJK/commit/b09c476bd587e785ce38645b6d962c66b562032e)<br>Revert "Removed cheat protection for r_fullbright and r_lightmap as requested by pivot" | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2016-08-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f2992e8e7911`](https://github.com/eternalcodes/EternalJK/commit/f2992e8e7911c91185f7c7dc24cb4851e8808bd2)<br>Fixed: Removed cheat protection for r_fullbright and r_lightmap Requested by pivot | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5)<br>Merge pull request #1 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `high` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp`, `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_local.h`, `codemp/rd-vulkan/vk_shade_geometry.cpp` | `high` |
| `2022-02-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`507a46dfc17d`](https://github.com/taysta/TaystJK/commit/507a46dfc17d8d55b8bd13918a2522467fd24683)<br>Collection of code cleanup and refactoring. Plus recent quake3e changes | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp` | `medium` |
| `2022-02-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`723c24a13050`](https://github.com/JKSunny/EternalJK/commit/723c24a130509bedc156847c5dbc4b5bf39ed0fb)<br>Vulkan: Fixed entity wall clipping & refactor fastsky color for performance | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_shade_geometry.cpp` | `high` |
| `2023-09-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a435f91de078`](https://github.com/taysta/TaystJK/commit/a435f91de078325de74408f44053240448efe1b4)<br>Merge remote-tracking branch 'SunnyJK/master' into ojkupdate | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_bsp.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2023-10-17` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c5ce242c0498`](https://github.com/taysta/TaystJK/commit/c5ce242c04981c0c5f84a6b498cb387962dcdd8a)<br>Merge remote-tracking branch 'SunnyJK/master' | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_shade_geometry.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_bsp.cpp`, `shared/rd-rend2/tr_local.h`, `shared/rd-rend2/tr_shade.cpp` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9693491bc25a`](https://github.com/taysta/TaystJK/commit/9693491bc25abec6748a229e858aaa613db03064) · [PR #346](https://github.com/taysta/TaystJK/pull/346)<br>Merge pull request #346 from taysta/rend2-cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:405](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/tr_init.cpp#L405) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1654](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1654) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1714](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1714) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:876](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L876) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:211](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L211)
- behavior: [codemp/rd-vanilla/tr_bsp.cpp:250](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_bsp.cpp#L250)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:416](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L416)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1644](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1644)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1725](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1725)
