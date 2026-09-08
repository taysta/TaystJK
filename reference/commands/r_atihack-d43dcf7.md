---
title: "r_atihack"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_atihack`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `R_AtiHackToggle_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `r_atihack` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1285](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1285)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4c9c53371d37`](https://github.com/JACoders/OpenJK/commit/4c9c53371d376092854590e8fb6d402d2c10c7d6)<br>Fixed some more unresolved externals (for the modular renderer) | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-09-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`306554cc03e7`](https://github.com/JACoders/OpenJK/commit/306554cc03e7e0f4f536fc5b7e5b93d97e2671f3)<br>Display default status when printing cvar from cvar<enter> or print <cvar>. Fixed r_primitives so that it only is 0...3 range in normal use. Updated r_fullscreen to be correct in rd-dedicated. Add file completion to exec/execq. Add cvarname completion to vstr. | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-12-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f5c2af345b66`](https://github.com/JACoders/OpenJK/commit/f5c2af345b66162ccae5f712f5f3e78fc9a9dcf3)<br>[MP] r_swapInterval requires CVAR_LATCH with SDL. | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2014-06-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`333d0ace79e0`](https://github.com/JACoders/OpenJK/commit/333d0ace79e0f070c7308e26ad3262a10c0b6458)<br>[MP] Moved console commands in the renderer to an array to avoid forgetting to remove commands at shutdowns. Also refactored maxpolys/maxpolyverts initialization. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aee78667221a`](https://github.com/JACoders/OpenJK/commit/aee78667221a7fbd237f53ee142582a2581ed0b3)<br>[SP] Move renderer command registration into a linear table. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`be875666ac5d`](https://github.com/eternalcodes/EternalJK/commit/be875666ac5d4aa150d79ca1d7e0b060609fdc28)<br>/clearRemaps command | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9e7eaec5c4cf`](https://github.com/eternalcodes/EternalJK/commit/9e7eaec5c4cf17d9edf4c1d9e3fea57e49fb7658)<br>/remapSky command | Changed the registered command handler. `codemp/rd-vanilla/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:1599](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1599) (renderer command table)
- handler: [codemp/rd-vanilla/tr_init.cpp:1556](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1556)
