---
title: "r_fullbright"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_fullbright`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_fullbright` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `float` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

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
- Upstream registration evidence: [code/renderer/tr_init.cpp:1144](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1144)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-dedicated/tr_local.h`, `codemp/rd-dedicated/tr_shader.cpp` and 6 more | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16007a014e0b`](https://github.com/JACoders/OpenJK/commit/16007a014e0ba10d7b4b7295e38ac7d1e315fcbc)<br>19 externals left to fix in the SP modular renderer, doing a push/pull break here | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-11-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c5bd9aa1b5d6`](https://github.com/JACoders/OpenJK/commit/c5bd9aa1b5d651ce80d6ad9d28595ca39e47798c)<br>[SP] Adjusted renderer cvar defaults and flags | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`66a3ee395159`](https://github.com/JACoders/OpenJK/commit/66a3ee3951598dde11d9217d9851bf59b5b9b92e)<br>[MP] Fix some gcc warnings. Improve byte aliasing code | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_surface.cpp` | `medium` |
| `2015-11-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`83d2ef4ac09a`](https://github.com/eternalcodes/EternalJK/commit/83d2ef4ac09a6b0d18f5ffff11929c3b4c835166)<br>Unlock all cheat-protected renderer cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`34634e7dbad8`](https://github.com/taysta/TaystJK/commit/34634e7dbad8c67aa20c146c2a53fe0dd93159a9)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2016-08-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e6191dc834e0`](https://github.com/eternalcodes/EternalJK/commit/e6191dc834e02202926adc8c5c873901d58ea27c)<br>Removed cheat protection for r_fullbright and r_lightmap as requested by pivot | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2016-08-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b09c476bd587`](https://github.com/eternalcodes/EternalJK/commit/b09c476bd587e785ce38645b6d962c66b562032e)<br>Revert "Removed cheat protection for r_fullbright and r_lightmap as requested by pivot" | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2016-08-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f2992e8e7911`](https://github.com/eternalcodes/EternalJK/commit/f2992e8e7911c91185f7c7dc24cb4851e8808bd2)<br>Fixed: Removed cheat protection for r_fullbright and r_lightmap Requested by pivot | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2018-03-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f538ffd0c99f`](https://github.com/eternalcodes/EternalJK/commit/f538ffd0c99f5be9f68893f6abeebc6329e94351)<br>Fullbright skins in renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_light.cpp` | `medium` |
| `2018-03-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2441386f39c7`](https://github.com/eternalcodes/EternalJK/commit/2441386f39c79ebb891b653ff217077fbf528bbf)<br>renamed to RF_FULLBRIGHT+open cgame example (duel shell) | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_light.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a4f3d1afc0ba`](https://github.com/eternalcodes/EternalJK/commit/a4f3d1afc0ba600e2a76ed9b53c174432460a44b)<br>Fix RF_NOLOD on MD3s? | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_light.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_light.cpp`, `codemp/rd-vulkan/tr_local.h` and 2 more | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_local.h`, `codemp/rd-vulkan/tr_shader.cpp` | `high` |
| `2022-04-15` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`a781c5543017`](https://github.com/JKSunny/EternalJK/commit/a781c5543017fdc50f01161f0303fc68e03da38d)<br>Vulkan: Fix missing oneShotAnimMap & missing lightmap/vertexlight on certain surfaces | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_shader.cpp`, `codemp/rd-vulkan/vk_shade_geometry.cpp` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2023-12-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`6761cbabf991`](https://github.com/taysta/TaystJK/commit/6761cbabf9916a3a86385ec62212ac4a2c38efe1)<br>Merge remote-tracking branch 'SunnyJK/master' | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_light.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_backend.cpp`, `shared/rd-rend2/tr_bsp.cpp`, `shared/rd-rend2/tr_light.cpp` and 2 more | `medium` |
| `2025-04-15` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) · [PR #217](https://github.com/taysta/TaystJK/pull/217)<br>Rend2 update (#217) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_light.cpp` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9693491bc25a`](https://github.com/taysta/TaystJK/commit/9693491bc25abec6748a229e858aaa613db03064) · [PR #346](https://github.com/taysta/TaystJK/pull/346)<br>Merge pull request #346 from taysta/rend2-cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:357](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L357) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1602](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1602) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1666](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1666) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:818](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L818) (Cvar_Get)
- behavior: [codemp/rd-dedicated/tr_shader.cpp:2629](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_shader.cpp#L2629)
- behavior: [codemp/rd-vanilla/tr_light.cpp:144](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_light.cpp#L144)
- behavior: [codemp/rd-vanilla/tr_shade.cpp:237](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_shade.cpp#L237)
- behavior: [codemp/rd-vanilla/tr_shader.cpp:2908](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_shader.cpp#L2908)
- behavior: [codemp/rd-vanilla/tr_surface.cpp:284](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_surface.cpp#L284)
