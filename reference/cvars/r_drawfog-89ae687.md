---
title: "r_drawfog"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_drawfog`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Controls fog rendering. The Vulkan registration documents 0 as disabled, 1 as software fog, and 2 as hardware fog; the same cvar is registered by vanilla, rend2, Vulkan, and the dedicated renderer stub.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `mixed` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `2` |
| Value type | `enum` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable fog. | [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L871) |
| `1` | Use software fog. | [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L871) |
| `2` | Use hardware fog. | [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L871) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `2` | `renderer` | `rd-dedicated` | `always` |
| `2` | `renderer` | `rd-rend2` | `always` |
| `2` | `renderer` | `rd-vanilla` | `always` |
| `2` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1204](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1204)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_init.cpp` and 4 more | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16007a014e0b`](https://github.com/JACoders/OpenJK/commit/16007a014e0ba10d7b4b7295e38ac7d1e315fcbc)<br>19 externals left to fix in the SP modular renderer, doing a push/pull break here | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_shade.cpp` | `medium` |
| `2014-05-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`773fdcef0610`](https://github.com/JACoders/OpenJK/commit/773fdcef0610150c766a2cd83aa3144d77b66cdf)<br>[JK2SP] Fix yavin_swamp by removing GL fog when compiling the renderer for JK2. Also sets r_drawfog to 1 for JK2 mode instead of 2. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`83d2ef4ac09a`](https://github.com/eternalcodes/EternalJK/commit/83d2ef4ac09a6b0d18f5ffff11929c3b4c835166)<br>Unlock all cheat-protected renderer cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`34634e7dbad8`](https://github.com/taysta/TaystJK/commit/34634e7dbad8c67aa20c146c2a53fe0dd93159a9)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5)<br>Merge pull request #1 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `high` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h`, `codemp/rd-vulkan/tr_quicksprite.cpp` and 2 more | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_quicksprite.cpp`, `codemp/rd-vulkan/tr_shade.cpp` and 2 more | `high` |
| `2022-02-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`723c24a13050`](https://github.com/JKSunny/EternalJK/commit/723c24a130509bedc156847c5dbc4b5bf39ed0fb)<br>Vulkan: Fixed entity wall clipping & refactor fastsky color for performance | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_shade_geometry.cpp` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_glsl.cpp`, `shared/rd-rend2/tr_local.h`, `shared/rd-rend2/tr_shade.cpp` and 1 more | `medium` |
| `2025-04-15` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) · [PR #217](https://github.com/taysta/TaystJK/pull/217)<br>Rend2 update (#217) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_glsl.cpp` | `medium` |
| `2025-08-08` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`cc93ec8c4139`](https://github.com/taysta/TaystJK/commit/cc93ec8c413928bdfb94db470566c1ec44d88903) · [PR #251](https://github.com/taysta/TaystJK/pull/251)<br>Merge pull request #251 from taysta/vk-update | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/vk_init.cpp`, `codemp/rd-vulkan/vk_local.h` and 1 more | `medium` |
| `2026-01-09` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`f18b5091e2f3`](https://github.com/taysta/TaystJK/commit/f18b5091e2f3a466208128976b4344f839a6c1e4) · [PR #286](https://github.com/taysta/TaystJK/pull/286)<br>Merge pull request #286 from taysta/vk-update | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_vbo_surfacesprites.cpp` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9693491bc25a`](https://github.com/taysta/TaystJK/commit/9693491bc25abec6748a229e858aaa613db03064) · [PR #346](https://github.com/taysta/TaystJK/pull/346)<br>Merge pull request #346 from taysta/rend2-cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:404](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/tr_init.cpp#L404) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1653](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1653) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1713](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1713) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:871](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L871) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_quicksprite.cpp:87](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_quicksprite.cpp#L87)
- behavior: [codemp/rd-vanilla/tr_quicksprite.cpp:130](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_quicksprite.cpp#L130)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:648](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L648)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1000](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1000)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:1882](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shade.cpp#L1882)
