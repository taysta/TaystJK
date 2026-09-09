---
title: "fs_cdpath"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_cdpath`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

(Read Only) Location for development files

## At a glance

| Field | Value |
|:--|:--|
| Category | Files & downloads |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
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
- Upstream registration evidence: [code/qcommon/files_console.cpp:683](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/files_console.cpp#L683)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_console.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_pc.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2013-07-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a1bbd5558365`](https://github.com/JACoders/OpenJK/commit/a1bbd55583652e9078ea58e555526f8c16120425)<br>Ported some filesystem changes from MP to SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-11-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ea310d93ce9f`](https://github.com/JACoders/OpenJK/commit/ea310d93ce9f2b47eccad3531ead43f1aba3e608)<br>[SP] Filesystem stuff from MP and cleanup. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files_pc.cpp` | `medium` |
| `2013-11-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3fb704dd3f4e`](https://github.com/JACoders/OpenJK/commit/3fb704dd3f4e6a71ad150cbc238bfa93eb17111f)<br>[MP] Remove useless function tied to cdpath, just use a blank string. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files_pc.cpp` | `medium` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)<br>[MP] Migrate files code to a single file. Use long instead of int in some file functions. Security to prevent mods from manipulating dll/so/dylib/pk3. Don't include client.h in every case. | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2015-01-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c00c4904efbe`](https://github.com/JACoders/OpenJK/commit/c00c4904efbeca1152d105f386a8584d4b76ecb8)<br>[SP] Refactored files code to single file. Breaks compat with older jagame/jospgame modules and older renderer modules for SP/JKS2SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp`, `code/qcommon/files_console.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`bc1b6d1d879b`](https://github.com/eternalcodes/EternalJK/commit/bc1b6d1d879b9992c6b07399fd78e6d4761959ad)<br>Remove LoadSPGameDll | Changed an exact bound cvar-variable reference. `shared/sys/sys_main.cpp` | `medium` |
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3910](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3910) (Cvar_Get)
- behavior: [codemp/qcommon/files.cpp:1765](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L1765)
- behavior: [codemp/qcommon/files.cpp:1768](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L1768)
- behavior: [codemp/qcommon/files.cpp:1786](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L1786)
- behavior: [codemp/qcommon/files.cpp:3737](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3737)
- behavior: [codemp/qcommon/files.cpp:3754](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3754)
