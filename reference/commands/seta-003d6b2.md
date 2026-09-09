---
title: "seta"
layout: reference
nav_exclude: true
search_exclude: false
---

# `seta`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Set a cvar and apply archive flag

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `seta <variable> <value>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/cvar.cpp:890](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/cvar.cpp#L890)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3b9054288cb6`](https://github.com/JACoders/OpenJK/commit/3b9054288cb68485297a53f60e618d7ffb6d16ae)<br>Some FS/CVar/Security fixes.  Causes issues right now. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb0894c030b3`](https://github.com/JACoders/OpenJK/commit/bb0894c030b34fa681134d7b54a00987c898b766)<br>Mega improvmements to SP's startup variable support from MP. (init-only cvars work correctly) Mega improvmements to SP's cvar code from MP: - Cvars use hash lookup now. - Max Cvars bumped to 2048. - Using ! in a bind on a cvar is correct now. - print <variable> command for printing info. (same as /cvarname but useful for when cmd+cvar clash) - unset <variable> un-sets a cvar entirely if its user created. - cleaned up set/sets/seta/setu - /cvarname <with args> now will accept all args instead of just the first - toggle cmd improved - cvar range checking code added (though not much actually uses it yet) - latched+cheat cvar escaping fixed - cheat cvars aren't hidden from cvarlist anymore - Possibly a few other misc things I missed. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f7058dcb5644`](https://github.com/JACoders/OpenJK/commit/f7058dcb56443a3ddc7425eeb2d538a866a06a8c)<br>Add cvar_modified command, improve cvarlist command | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`82badfabf174`](https://github.com/JACoders/OpenJK/commit/82badfabf174a20512a5c895b58af25eade3e972)<br>Massive SP upgrade patch. Merges the console overhaul to SP. Fixes extension functions in SP. Rename qport to net_qport in SP. Remove alt-tab diasabler from SP. Fixed up command buffer code in SP. Fixed up configs loading on startup in SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2013-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b12414718708`](https://github.com/JACoders/OpenJK/commit/b1241471870888d0e2b7c2613dadcd5da8761ae2)<br>[MP] Improve cvar code a bit further.  Based mostly on zturtleman/spearmint@778bce425a2e6b6860e9d5ec4c7fc736311f9351. With some changes for legacy support still (and extra cvars that should be allowed in mods, if the mods were incorrectly setting them). And also some other misc stuff related to OpenJK specific. | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `high` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1625](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1625) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1068](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1068)
