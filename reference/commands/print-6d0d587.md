---
title: "print"
layout: reference
nav_exclude: true
search_exclude: false
---

# `print`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Print cvar help

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `print <variable>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [code/qcommon/cvar.cpp:1369](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cvar.cpp#L1369)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | [`14cea1563762`](https://github.com/SomaZ/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | [`14cea1563762`](https://github.com/jkanewmod/NewJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2015-03-19` | [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3b9054288cb6`](https://github.com/JACoders/OpenJK/commit/3b9054288cb68485297a53f60e618d7ffb6d16ae)<br>Some FS/CVar/Security fixes.  Causes issues right now. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb0894c030b3`](https://github.com/JACoders/OpenJK/commit/bb0894c030b34fa681134d7b54a00987c898b766)<br>Mega improvmements to SP's startup variable support from MP. (init-only cvars work correctly) Mega improvmements to SP's cvar code from MP: - Cvars use hash lookup now. - Max Cvars bumped to 2048. - Using ! in a bind on a cvar is correct now. - print <variable> command for printing info. (same as /cvarname but useful for when cmd+cvar clash) - unset <variable> un-sets a cvar entirely if its user created. - cleaned up set/sets/seta/setu - /cvarname <with args> now will accept all args instead of just the first - toggle cmd improved - cvar range checking code added (though not much actually uses it yet) - latched+cheat cvar escaping fixed - cheat cvars aren't hidden from cvarlist anymore - Possibly a few other misc things I missed. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f7058dcb5644`](https://github.com/JACoders/OpenJK/commit/f7058dcb56443a3ddc7425eeb2d538a866a06a8c)<br>Add cvar_modified command, improve cvarlist command | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/cvar.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`82badfabf174`](https://github.com/JACoders/OpenJK/commit/82badfabf174a20512a5c895b58af25eade3e972)<br>Massive SP upgrade patch. Merges the console overhaul to SP. Fixes extension functions in SP. Rename qport to net_qport in SP. Remove alt-tab diasabler from SP. Fixed up command buffer code in SP. Fixed up configs loading on startup in SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1ba18ae105e7`](https://github.com/JACoders/OpenJK/commit/1ba18ae105e7e1b3f9751b4893e7295e2fae475f)<br>Fix warning for signed cvar flags | Changed the registered command handler. `codemp/qcommon/cvar.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cvar.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/cvar.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1615](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1615) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:997](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L997)
