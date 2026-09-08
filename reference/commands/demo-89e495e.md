---
title: "demo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `demo`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Playback a demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `demo [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2672](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_main.cpp#L2672)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a377df76459`](https://github.com/JACoders/OpenJK/commit/4a377df76459fc8024997def204efae18246bb77)<br>Killserver improvements | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_main.cpp` | `high` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5a7da6a2c95c`](https://github.com/eternalcodes/EternalJK/commit/5a7da6a2c95cfd8c18b1ad508a9af3359820e0ff)<br>concat args for /demo command | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2018-04-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`98e5c2a48010`](https://github.com/eternalcodes/EternalJK/commit/98e5c2a48010c576340c61f85b857123fbd74b4c)<br>start of delete demo command+"delete demo" button in menu | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2018-04-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6107f5fbcf59`](https://github.com/eternalcodes/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847)<br>1.00 demo (*.dm_25) support, "playdemo" alias command | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2018-04-26` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`a983fa494fee`](https://github.com/taysta/TaystJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b)<br>8 years too late, basic multiprotocol/multiversion support. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`94672e48ece0`](https://github.com/eternalcodes/EternalJK/commit/94672e48ece0771144723030e011e2443c68a435)<br>add demo_restart | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`825d63b114ab`](https://github.com/eternalcodes/EternalJK/commit/825d63b114abfecc502c4136dc3ce4dad0e0841a)<br>Fix demo_restart+fix bugs in demo commands from 1.00 demo support | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3469](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3469) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L554)
