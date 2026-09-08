---
title: "cvarlist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cvarlist`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Show all cvars

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `cvarlist [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/cvar.cpp:892](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/cvar.cpp#L892)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`393874137c54`](https://github.com/JACoders/OpenJK/commit/393874137c54b70b27856e62013bd283059ef6e0)<br>First batch of changes from Ensi | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3b9054288cb6`](https://github.com/JACoders/OpenJK/commit/3b9054288cb68485297a53f60e618d7ffb6d16ae)<br>Some FS/CVar/Security fixes.  Causes issues right now. | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f7058dcb5644`](https://github.com/JACoders/OpenJK/commit/f7058dcb56443a3ddc7425eeb2d538a866a06a8c)<br>Add cvar_modified command, improve cvarlist command | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`43f3e8eb7a4c`](https://github.com/JACoders/OpenJK/commit/43f3e8eb7a4cc8916f17ab1921f8d6824be9ec29)<br>Fixed missing space in cvarlist command between the flags and the cvar name. | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`82badfabf174`](https://github.com/JACoders/OpenJK/commit/82badfabf174a20512a5c895b58af25eade3e972)<br>Massive SP upgrade patch. Merges the console overhaul to SP. Fixes extension functions in SP. Rename qport to net_qport in SP. Remove alt-tab diasabler from SP. Fixed up command buffer code in SP. Fixed up configs loading on startup in SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2015-06-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f614bc372a41`](https://github.com/taysta/TaystJK/commit/f614bc372a41cca80c0e1e401d584a57318bd495)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a7d79c1070c0`](https://github.com/eternalcodes/EternalJK/commit/a7d79c1070c0429cf664dcf3390623aca9b7bc77)<br>support nm help messages | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ecb970dc07a5`](https://github.com/eternalcodes/EternalJK/commit/ecb970dc07a57ab77b3cf1a7e7b32cc4d7fa658c)<br>small tweak to last commit | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`32ba4e2d9ad9`](https://github.com/eternalcodes/EternalJK/commit/32ba4e2d9ad9194ec35d3e9ba3c865957c3567c0)<br>better coding of nm help messages | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1642](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1642) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1225](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1225)
