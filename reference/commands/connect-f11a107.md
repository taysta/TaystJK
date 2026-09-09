---
title: "connect"
layout: reference
nav_exclude: true
search_exclude: false
---

# `connect`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Connect to a server

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `connect [server]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2681](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_main.cpp#L2681)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`393874137c54`](https://github.com/JACoders/OpenJK/commit/393874137c54b70b27856e62013bd283059ef6e0)<br>First batch of changes from Ensi | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`883d63a45910`](https://github.com/JACoders/OpenJK/commit/883d63a459109ae2881d854bd63a9b89a1415ae2)<br>Buffer overflow in CL_Rcon_f + Send full untokenized string | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5f3773fca327`](https://github.com/JACoders/OpenJK/commit/5f3773fca32711be4d3bc3b69ee95eaf0ebd38c9)<br>Removed cd key stuff from miscellaneous files | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_main.cpp` | `high` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_main.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_main.cpp` | `high` |
| `2013-07-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cccf3136bac2`](https://github.com/JACoders/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5)<br>Merge pull request #324 from deepy/master | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`aca8a3445035`](https://github.com/JACoders/OpenJK/commit/aca8a344503520d6704304cd8ed0d87715577b99)<br>Demoname completion for MP. Rcon command completion for MP. Fixed map command completion having some weird stuff in it. Display "Key  " in grey before keynames when doing /bind <TAB>. Display "File " in grey before filenames when doing /map <TAB> or others with filename completion. Fixed /bind key displaying bind <KEY> = "" as opposed to "<KEY>" is not bound when unbound sometimes. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-11-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d599e706c7ff`](https://github.com/JACoders/OpenJK/commit/d599e706c7ff985572ce00a7657abf0353a4dc82)<br>[MP] Merge cl_reconnectArgs from ioq3. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-11-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2e90f9c19be1`](https://github.com/JACoders/OpenJK/commit/2e90f9c19be1a2b74a1ac71f8ff0dcdadfa3103c)<br>[MP] Removed leftover delayFreeVM references. Init lastTime to 0 in Com_Frame. Bring back ERR_NEED_CD handling just for conformity sake. Init the jakey randomizer first thing in Com_Init. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2024-03-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) · [PR #169](https://github.com/taysta/TaystJK/pull/169)<br>HTTP Auto Download (Server + Client) (#169) | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a6f521232afb`](https://github.com/taysta/TaystJK/commit/a6f521232afba109e20275bac4a71369ba5b5ae1) · [PR #311](https://github.com/taysta/TaystJK/pull/311)<br>Merge pull request #311 from taysta/bone-conversion | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3484](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3484) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:1137](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1137)
