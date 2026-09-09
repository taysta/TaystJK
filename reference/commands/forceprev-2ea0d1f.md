---
title: "forceprev"
layout: reference
nav_exclude: true
search_exclude: false
---

# `forceprev`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_PrevForcePower_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [controls.menu:2518](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/controls.menu#L2518), [ingame_controls.menu:2146](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_controls.menu#L2146) |
| Syntax | `forceprev` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_consolecmds.cpp:251](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_consolecmds.cpp#L251)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_consolecmds.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/cgame/cg_main.c` | `medium` |
| `2013-11-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2f3e89e2e75`](https://github.com/JACoders/OpenJK/commit/b2f3e89e2e75b4d6dc3d3bb0a04a0610aab20d2d)<br>[MP] Improve cg_consolecmds and cg_servercmds to use bsearch. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2013-11-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f9e6edda7daf`](https://github.com/JACoders/OpenJK/commit/f9e6edda7daf210976bb97b058e3512d21982e4a)<br>[SP] Improve cg_consolecmds and cg_servercmds to use bsearch. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_consolecmds.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1ba18ae105e7`](https://github.com/JACoders/OpenJK/commit/1ba18ae105e7e1b3f9751b4893e7295e2fae475f)<br>Fix warning for signed cvar flags | Changed the registered command handler. `codemp/cgame/cg_main.c` | `medium` |
| `2014-03-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cfeb246ffcce`](https://github.com/JACoders/OpenJK/commit/cfeb246ffcce3105e835a8043c5770ce92cc7783)<br>[JK2SP] Merging in some fixes and cleanup from JASP cgame/game code. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_consolecmds.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_consolecmds.cpp`, `codeJK2/cgame/cg_consolecmds.cpp` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7f89e408e24d`](https://github.com/eternalcodes/EternalJK/commit/7f89e408e24db297110b4ab3f952a52f33a55ddf)<br>CGame Fix CG_Set2DRatio | Changed the registered command handler. `codemp/cgame/cg_local.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed the registered command handler. `codemp/cgame/cg_local.h` | `high` |
| `2019-01-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`90d4e33a7b87`](https://github.com/eternalcodes/EternalJK/commit/90d4e33a7b87125fb159d57f44b0496ad4e9f5e5)<br>Remap forceNext to amTeleMark and forcePrev to amTele in racemode. | Changed the registered command handler. `codemp/cgame/cg_main.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`343ee985acb1`](https://github.com/eternalcodes/EternalJK/commit/343ee985acb180b57cd5a0bbba52bf8655dfb9be)<br>Allow forceNext/forcePrev to set telemarks in spec. | Changed the registered command handler. `codemp/cgame/cg_main.c` | `medium` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed the registered command handler. `codemp/cgame/cg_main.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c635b474e0de`](https://github.com/eternalcodes/EternalJK/commit/c635b474e0de31387dbfa74438cc4b3866174148)<br>cgame updates for coop defrag | Changed the registered command handler. `codemp/cgame/cg_main.c` | `medium` |
| `2023-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fe7a86d0fc89`](https://github.com/taysta/TaystJK/commit/fe7a86d0fc89a22cd46207bf7d49780721e4f20f) · [PR #10](https://github.com/taysta/TaystJK/pull/10)<br>Merge pull request #10 from taysta/dynamic-format-tables | Changed the registered command handler. `codemp/cgame/cg_local.h` | `medium` |
| `2023-12-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bf81a8695ce`](https://github.com/videoP/jaPRO/commit/0bf81a8695ceaa3768496dfd4fe4e3a157016086)<br>Since jaPRO added MV_OCPM and MV_TRIBES after MV_COOP_JKA, we have to shuffle some things around. MV_COOP was originally designed to support multiple additional physics than just jka, but this never panned out. Need to revert this change if that design ever makes a comeback. | Changed the registered command handler. `codemp/cgame/cg_main.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2453](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2453) (cgame command table)
- handler: [codemp/cgame/cg_main.c:3389](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L3389)
