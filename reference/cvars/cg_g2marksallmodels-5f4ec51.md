---
title: "cg_g2MarksAllModels"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_g2MarksAllModels`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Render marks on all G2 models

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-dedicated/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/G2_misc.cpp#L558) |
| `1` | Enabled. | [codemp/rd-dedicated/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/G2_misc.cpp#L558) |

## Flags

No cvar flags are registered at the cited site.

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-dedicated` | `defined(_G2_GORE)` |
| `0` | `renderer` | `rd-rend2` | `defined(_G2_GORE)` |
| `0` | `renderer` | `rd-vanilla` | `defined(_G2_GORE)` |
| `0` | `renderer` | `rd-vulkan` | `defined(_G2_GORE)` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/ghoul2/G2_misc.cpp:565](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/ghoul2/G2_misc.cpp#L565)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/G2_misc.cpp`, `codemp/rd-vanilla/G2_misc.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c2bb91dfb8d0`](https://github.com/JACoders/OpenJK/commit/c2bb91dfb8d0d702af9714e4163a8b580f26e2b2)<br>Added the Ghoul 2 crap to the SP modular renderer. Next up: more unresolved symbols and RMG. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/ghoul2/G2_misc.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/G2_misc.cpp`, `codemp/rd-vanilla/G2_misc.cpp` | `medium` |
| `2013-11-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3cd6879507ff`](https://github.com/JACoders/OpenJK/commit/3cd6879507ff807896562e9fa6256295dc4a2c7e)<br>[SP] Clean up renderer files, removed ununsed files | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/G2_misc.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/G2_misc.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/G2_misc.cpp`, `codemp/rd-vanilla/G2_misc.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/G2_misc.cpp`, `codemp/rd-vanilla/G2_misc.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/G2_misc.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/G2_misc.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/G2_misc.cpp:554](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/G2_misc.cpp#L554) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-dedicated/G2_misc.cpp:1503](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/G2_misc.cpp#L1503) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-rend2/G2_misc.cpp:545](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/G2_misc.cpp#L545) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-rend2/G2_misc.cpp:1485](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/G2_misc.cpp#L1485) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vanilla/G2_misc.cpp:554](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/G2_misc.cpp#L554) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vanilla/G2_misc.cpp:1504](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/G2_misc.cpp#L1504) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vulkan/G2_misc.cpp:562](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/G2_misc.cpp#L562) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vulkan/G2_misc.cpp:1568](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/G2_misc.cpp#L1568) (Cvar_Get); condition `defined(_G2_GORE)`
- behavior: [codemp/rd-dedicated/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/G2_misc.cpp#L558)
- behavior: [codemp/rd-dedicated/G2_misc.cpp:1507](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/G2_misc.cpp#L1507)
- behavior: [codemp/rd-rend2/G2_misc.cpp:549](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/G2_misc.cpp#L549)
- behavior: [codemp/rd-rend2/G2_misc.cpp:1489](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/G2_misc.cpp#L1489)
- behavior: [codemp/rd-vanilla/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/G2_misc.cpp#L558)
