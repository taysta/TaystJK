---
title: "kicknum"
layout: reference
nav_exclude: true
search_exclude: false
---

# `kicknum`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Kick a user from the server by userid

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `kicknum <client number>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9344b45fc2d8`](https://github.com/JACoders/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-07`, integrated `2013-04-07`)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1961](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1961)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/JACoders/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/eternalcodes/EternalJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/SomaZ/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/taysta/TaystJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/videoP/jaPRO/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/jkanewmod/NewJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | — | `2013-04-07` | [`9344b45fc2d8`](https://github.com/JKSunny/EternalJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)<br>Added files from jediAcademy source dump. Does not compile. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c6e3f0479ac0`](https://github.com/JACoders/OpenJK/commit/c6e3f0479ac048e838ac002351fab307f726fa4d)<br>[MP] Meta: Remove unnecessary comments and names | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`73e537fdea26`](https://github.com/JACoders/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b)<br>[MP] Port ioq3 engine based ban code. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2320](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2320) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:580](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L580)
