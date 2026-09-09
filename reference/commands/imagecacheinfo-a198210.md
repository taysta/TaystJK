---
title: "imagecacheinfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `imagecacheinfo`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `RE_RegisterImages_Info_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `imagecacheinfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1293](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1293)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_image.cpp`, `codemp/rd-vanilla/tr_init.cpp` and 1 more | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4c9c53371d37`](https://github.com/JACoders/OpenJK/commit/4c9c53371d376092854590e8fb6d402d2c10c7d6)<br>Fixed some more unresolved externals (for the modular renderer) | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_image.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-11-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d02c4d6eaf69`](https://github.com/JACoders/OpenJK/commit/d02c4d6eaf695605f69f72390bfb801cc15c403e)<br>[MP] Clean up some unused code, defines, includes | Changed the registered command handler. `codemp/rd-vanilla/tr_image.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`39731cf76033`](https://github.com/JACoders/OpenJK/commit/39731cf760335057266d63ae5306d1c015497863)<br>[MP] Replaced a good chunk of Com_Printf usage in the renderer with ri->Printf. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_image.cpp`, `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-06-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`333d0ace79e0`](https://github.com/JACoders/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458)<br>[MP] Moved console commands in the renderer to an array to avoid forgetting to remove commands at shutdowns. Also refactored maxpolys/maxpolyverts initialization. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aee78667221a`](https://github.com/JACoders/OpenJK/commit/aee78667221a7fbd237f53ee142582a2581ed0b3)<br>[SP] Move renderer command registration into a linear table. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed the registered command handler. `codemp/rd-vanilla/tr_image.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`22e66aeb32fc`](https://github.com/taysta/TaystJK/commit/22e66aeb32fca7ac91de70bc3474e4d23f38a8fa) · [PR #315](https://github.com/taysta/TaystJK/pull/315)<br>Merge pull request #315 from taysta/vk-up | Changed the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:1601](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1601) (renderer command table)
- handler: [codemp/rd-vanilla/tr_image.cpp:849](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_image.cpp#L849)
