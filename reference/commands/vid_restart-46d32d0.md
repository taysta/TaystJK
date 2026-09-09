---
title: "vid_restart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `vid_restart`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Restart the renderer - or change the resolution

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `vid_restart` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_main.cpp:1283](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_main.cpp#L1283)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e)<br>Replaces jpeg-6 with jpeg-8c.  Adds AVI write support from ioquake3.  (jpeg update was required) | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-07-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5c4285a08d12`](https://github.com/JACoders/OpenJK/commit/5c4285a08d12f913520bb58d769ec00bd48c8acc)<br>Fix #254 - no more crashes when calling Com_Error! | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-11-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2e90f9c19be1`](https://github.com/JACoders/OpenJK/commit/2e90f9c19be1a2b74a1ac71f8ff0dcdadfa3103c)<br>[MP] Removed leftover delayFreeVM references. Init lastTime to 0 in Com_Frame. Bring back ERR_NEED_CD handling just for conformity sake. Init the jakey randomizer first thing in Com_Init. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `codemp/client/cl_main.cpp` | `high` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5)<br>Merge pull request #1 from Bucky21659/master | Changed the registered command handler. `codemp/client/cl_main.cpp` | `high` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`04db4f373079`](https://github.com/eternalcodes/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704)<br>/loadmod command | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-05-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`97745ce2823e`](https://github.com/eternalcodes/EternalJK/commit/97745ce2823e9cb6f7ab683fcfe765cea40540ca)<br>Move fs_restart to files.cpp - now usable in dedicated servers. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3480](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3480) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:1323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1323)
