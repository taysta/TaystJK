---
title: "cvar_restart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cvar_restart`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Resetart the cvar sub-system

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `cvar_restart` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/cvar.cpp:893](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/cvar.cpp#L893)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3b9054288cb6`](https://github.com/JACoders/OpenJK/commit/3b9054288cb68485297a53f60e618d7ffb6d16ae)<br>Some FS/CVar/Security fixes.  Causes issues right now. | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f7058dcb5644`](https://github.com/JACoders/OpenJK/commit/f7058dcb56443a3ddc7425eeb2d538a866a06a8c)<br>Add cvar_modified command, improve cvarlist command | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`82badfabf174`](https://github.com/JACoders/OpenJK/commit/82badfabf174a20512a5c895b58af25eade3e972)<br>Massive SP upgrade patch. Merges the console overhaul to SP. Fixes extension functions in SP. Rename qport to net_qport in SP. Remove alt-tab diasabler from SP. Fixed up command buffer code in SP. Fixed up configs loading on startup in SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2013-09-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`306554cc03e7`](https://github.com/JACoders/OpenJK/commit/306554cc03e7e0f4f536fc5b7e5b93d97e2671f3)<br>Display default status when printing cvar from cvar<enter> or print <cvar>. Fixed r_primitives so that it only is 0...3 range in normal use. Updated r_fullscreen to be correct in rd-dedicated. Add file completion to exec/execq. Add cvarname completion to vstr. | Changed the registered command handler. `codemp/qcommon/qcommon.h` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/cvar.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1645](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1645) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1449](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1449)
