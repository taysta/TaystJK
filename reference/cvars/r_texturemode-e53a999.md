---
title: "r_textureMode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_textureMode`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_textureMode` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

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
| Default | `GL_LINEAR_MIPMAP_LINEAR` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `GL_LINEAR_MIPMAP_LINEAR` | `renderer` | `rd-rend2` | `always` |
| `GL_LINEAR_MIPMAP_LINEAR` | `renderer` | `rd-vanilla` | `always` |
| `GL_LINEAR_MIPMAP_LINEAR` | `renderer` | `rd-vulkan` | `always` |
| `GL_LINEAR_MIPMAP_NEAREST` | `renderer` | `rd-dedicated` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1167](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1167)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_cmds.cpp` and 2 more | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16007a014e0b`](https://github.com/JACoders/OpenJK/commit/16007a014e0ba10d7b4b7295e38ac7d1e315fcbc)<br>19 externals left to fix in the SP modular renderer, doing a push/pull break here | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-11-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c5bd9aa1b5d6`](https://github.com/JACoders/OpenJK/commit/c5bd9aa1b5d651ce80d6ad9d28595ca39e47798c)<br>[SP] Adjusted renderer cvar defaults and flags | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`39731cf76033`](https://github.com/JACoders/OpenJK/commit/39731cf760335057266d63ae5306d1c015497863)<br>[MP] Replaced a good chunk of Com_Printf usage in the renderer with ri->Printf. | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5)<br>Merge pull request #1 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-01-12` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`60132754c617`](https://github.com/videoP/jaPRO/commit/60132754c61719a97f300fa62cc77e55061f4c1e)<br>Merge remote-tracking branch 'Bucky21659/master' (#14) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2018-10-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c27f03202a2`](https://github.com/eternalcodes/EternalJK/commit/2c27f03202a2b11371544b9385b77f6867d677b3)<br>Added cvars to control sky color with r_fastSky 1 | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/tr_init.cpp` | `high` |
| `2021-10-24` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`bd3a458a8bb2`](https://github.com/JKSunny/EternalJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5)<br>Various fixes and upstream changes from Quake3e | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_info.cpp` | `high` |
| `2022-02-16` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`5ce497f25666`](https://github.com/JKSunny/EternalJK/commit/5ce497f2566623286479896ff9c01952cf0eb146)<br>Vulkan: linux & mac compiler warnings/errors cleanup. | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp` | `high` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`f80509edc116`](https://github.com/taysta/TaystJK/commit/f80509edc116450860516e051136a03c053f0818)<br>Merge branch 'master' of https://github.com/JKSunny/EternalJK | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cmds.cpp`, `codemp/rd-vulkan/vk_image.cpp`, `codemp/rd-vulkan/vk_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_cmds.cpp`, `shared/rd-rend2/tr_local.h` | `medium` |
| `2025-07-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`18138dc8d37d`](https://github.com/taysta/TaystJK/commit/18138dc8d37d27fc586d1fe501101c9f7c0d4229) · [PR #248](https://github.com/taysta/TaystJK/pull/248)<br>Merge pull request #248 from taysta/vk-update | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_init.cpp` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9693491bc25a`](https://github.com/taysta/TaystJK/commit/9693491bc25abec6748a229e858aaa613db03064) · [PR #346](https://github.com/taysta/TaystJK/pull/346)<br>Merge pull request #346 from taysta/rend2-cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:374](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/tr_init.cpp#L374) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1624](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1624) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1684](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1684) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:842](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L842) (Cvar_Get)
- behavior: [codemp/rd-rend2/tr_init.cpp:1198](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1198)
- behavior: [codemp/rd-rend2/tr_init.cpp:1201](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1201)
- behavior: [codemp/rd-rend2/tr_init.cpp:1325](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1325)
- behavior: [codemp/rd-vanilla/tr_cmds.cpp:398](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_cmds.cpp#L398)
- behavior: [codemp/rd-vanilla/tr_init.cpp:1358](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1358)
