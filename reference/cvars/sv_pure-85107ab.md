---
title: "sv_pure"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_pure`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Pure server

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_client.cpp:776](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L776) |
| `1` | Enabled. | [codemp/server/sv_client.cpp:776](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L776) |

## Flags

- `CVAR_SYSTEMINFO` — replicated in systeminfo

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_init.cpp:840](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_init.cpp#L840)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_model.cpp`, `codemp/rd-vanilla/tr_model.cpp` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fb1edd965e6d`](https://github.com/JACoders/OpenJK/commit/fb1edd965e6d3439809b8a982e6cd8217adabb23)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `codemp/server/sv_init.cpp` | `high` |
| `2013-07-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e849d8d3e345`](https://github.com/JACoders/OpenJK/commit/e849d8d3e3450fa01a06b1eeafe24e8b60257dd8)<br>Add pure status to getinfo. | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_model.cpp`, `codemp/rd-vanilla/tr_model.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b51b0fa7b1e2`](https://github.com/JACoders/OpenJK/commit/b51b0fa7b1e24a207774315953e8d1696c1e8783)<br>[MP] Changing sv_pure to default to off. It doesn't really protect against anything, if you really need it on, it should be set so in your server cfg. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1ba18ae105e7`](https://github.com/JACoders/OpenJK/commit/1ba18ae105e7e1b3f9751b4893e7295e2fae475f)<br>Fix warning for signed cvar flags | Changed an exact bound cvar-variable reference. `codemp/qcommon/qcommon.h` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2014-05-06` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8d7dc58a750e`](https://github.com/JACoders/OpenJK/commit/8d7dc58a750e0733b156d58d6db1f4f3e5089735)<br>[MP] Remove bots and pure status from getinfo responses for time being. | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2014-08-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1a545e105e79`](https://github.com/JACoders/OpenJK/commit/1a545e105e794f9a2f9edc4e5248a3bfa4537ce4)<br>Added back x86.dll suffixes in file opening | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fcd9fc4710f0`](https://github.com/JACoders/OpenJK/commit/fcd9fc4710f0d285ab7467e9f0a7a6778ac69d0a)<br>[MP] Misc fixes and cleanup. | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `codemp/server/sv_client.cpp`, `shared/sys/sys_win32.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_model.cpp`, `codemp/rd-vanilla/tr_model.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`08ec047719aa`](https://github.com/eternalcodes/EternalJK/commit/08ec047719aa8e4b8e613dbda5bb225d52d34870)<br>Set sv_pure 0 on local client when loading a map with /map or /devmap | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`22e66aeb32fc`](https://github.com/taysta/TaystJK/commit/22e66aeb32fca7ac91de70bc3474e4d23f38a8fa) · [PR #315](https://github.com/taysta/TaystJK/pull/315)<br>Merge pull request #315 from taysta/vk-up | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1001](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1001) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:776](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L776)
- behavior: [codemp/server/sv_client.cpp:957](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L957)
- behavior: [codemp/server/sv_client.cpp:1750](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1750)
- behavior: [codemp/server/sv_client.cpp:1768](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1768)
- behavior: [codemp/server/sv_init.cpp:701](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L701)
