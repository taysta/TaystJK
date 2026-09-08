---
title: "r_DynamicGlow"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_DynamicGlow`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Enable dynamic glow effect Requires \\r_fbo 1

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/rd-vanilla/tr_backend.cpp:2276](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L2276) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

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
- Upstream registration evidence: [code/renderer/tr_init.cpp:1102](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1102)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_backend.cpp` and 3 more | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16007a014e0b`](https://github.com/JACoders/OpenJK/commit/16007a014e0ba10d7b4b7295e38ac7d1e315fcbc)<br>19 externals left to fix in the SP modular renderer, doing a push/pull break here | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`39731cf76033`](https://github.com/JACoders/OpenJK/commit/39731cf760335057266d63ae5306d1c015497863)<br>[MP] Replaced a good chunk of Com_Printf usage in the renderer with ri->Printf. | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-06-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fa91ba821e9c`](https://github.com/JACoders/OpenJK/commit/fa91ba821e9cb85d983a5fc9d227017d7cd6a473)<br>[MP] Fix crash on startup if r_DynamicGlow is 2 | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp` | `high` |
| `2022-06-12` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`824d2e61015a`](https://github.com/taysta/TaystJK/commit/824d2e61015af8cb564b5ff8c20c4071dfa9d435)<br>Merge remote-tracking branch 'sunny/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/vk_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2023-10-17` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c5ce242c0498`](https://github.com/taysta/TaystJK/commit/c5ce242c04981c0c5f84a6b498cb387962dcdd8a)<br>Merge remote-tracking branch 'SunnyJK/master' | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_init.cpp` | `medium` |
| `2025-04-15` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) · [PR #217](https://github.com/taysta/TaystJK/pull/217)<br>Rend2 update (#217) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:326](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L326) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1507](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1507) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1643](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1643) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:794](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L794) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:521](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L521)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:1661](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L1661)
- behavior: [codemp/rd-vanilla/tr_backend.cpp:2276](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_backend.cpp#L2276)
- behavior: [codemp/rd-vanilla/tr_ghoul2.cpp:3814](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_ghoul2.cpp#L3814)
- behavior: [codemp/rd-vanilla/tr_init.cpp:1897](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1897)
