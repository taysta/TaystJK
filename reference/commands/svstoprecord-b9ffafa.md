---
title: "svstoprecord"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svstoprecord`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Stop recording a server-side demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `svstoprecord [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`44d5666875f3`](https://github.com/JACoders/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-01-27`, integrated `2014-01-27`)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1984](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1984)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/JACoders/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/eternalcodes/EternalJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/SomaZ/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/taysta/TaystJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/videoP/jaPRO/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/jkanewmod/NewJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-27` | — | `2014-01-27` | [`44d5666875f3`](https://github.com/JKSunny/EternalJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2344](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2344) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:1672](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L1672)
- documentation: [docs/japro_docs.md:395](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L395)
