---
title: "fs_basepath"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_basepath`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

(Read Only) Location for game files

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `Sys_DefaultInstallPath()` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/files_console.cpp:684](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/files_console.cpp#L684)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_console.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61779788b020`](https://github.com/JACoders/OpenJK/commit/61779788b0207e43c974b10b79dfba4709369636)<br>Botlib improvements. Moved some botlib headers to the botlib folder | Changed an exact bound cvar-variable reference. `codemp/botlib/be_interface.cpp`, `codemp/botlib/botlib.h` | `medium` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_qgl.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c2bb91dfb8d0`](https://github.com/JACoders/OpenJK/commit/c2bb91dfb8d0d702af9714e4163a8b580f26e2b2)<br>Added the Ghoul 2 crap to the SP modular renderer. Next up: more unresolved symbols and RMG. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_qgl.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_pc.cpp`, `codemp/unix/linux_qgl.c` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2013-06-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`459595e52ce6`](https://github.com/JACoders/OpenJK/commit/459595e52ce61e349d20390986ad20fa39ccc5a6)<br>Merge pull request #296 from redsaurus/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-07-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`37b78893128f`](https://github.com/JACoders/OpenJK/commit/37b78893128fa392b4a6308a8e2d782cf565649d)<br>Sys_DefaultBasePath no longer exists @redsaurus, not even on windows. Why did you put this back here? | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-07-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e91df181bd96`](https://github.com/JACoders/OpenJK/commit/e91df181bd962a7a2408f5c5b2868a2550344f58)<br>Revert "Sys_DefaultBasePath no longer exists @redsaurus, not even on windows." | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-07-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a1bbd5558365`](https://github.com/JACoders/OpenJK/commit/a1bbd55583652e9078ea58e555526f8c16120425)<br>Ported some filesystem changes from MP to SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_qgl.cpp` | `medium` |
| `2013-11-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3cd6879507ff`](https://github.com/JACoders/OpenJK/commit/3cd6879507ff807896562e9fa6256295dc4a2c7e)<br>[SP] Clean up renderer files, removed ununsed files | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_qgl.cpp` | `medium` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)<br>[MP] Migrate files code to a single file. Use long instead of int in some file functions. Security to prevent mods from manipulating dll/so/dylib/pk3. Don't include client.h in every case. | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c`, `codemp/qcommon/files.cpp` | `medium` |
| `2015-01-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c00c4904efbe`](https://github.com/JACoders/OpenJK/commit/c00c4904efbeca1152d105f386a8584d4b76ecb8)<br>[SP] Refactored files code to single file. Breaks compat with older jagame/jospgame modules and older renderer modules for SP/JKS2SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp`, `code/qcommon/files_console.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `shared/sys/sys_main.cpp`, `shared/sys/sys_unix.cpp`, `shared/sys/sys_win32.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp`, `code/win32/win_qgl.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2016-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`13791f7ad4fe`](https://github.com/taysta/TaystJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_qgl.cpp` | `medium` |
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`bc1b6d1d879b`](https://github.com/eternalcodes/EternalJK/commit/bc1b6d1d879b9992c6b07399fd78e6d4761959ad)<br>Remove LoadSPGameDll | Changed an exact bound cvar-variable reference. `shared/sys/sys_main.cpp` | `medium` |
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3911](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3911) (Cvar_Get)
- behavior: [codemp/qcommon/files.cpp:968](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L968)
- behavior: [codemp/qcommon/files.cpp:1765](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L1765)
- behavior: [codemp/qcommon/files.cpp:3741](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3741)
- behavior: [codemp/qcommon/files.cpp:3745](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3745)
- behavior: [codemp/qcommon/files.cpp:3757](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3757)
