---
title: "svrecord"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svrecord`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Record a server-side demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `svrecord [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`44d5666875f3`](https://github.com/JACoders/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) on `2014-01-27` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1983](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1983)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/JACoders/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/eternalcodes/EternalJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/SomaZ/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/taysta/TaystJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/videoP/jaPRO/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/jkanewmod/NewJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-27` | [`44d5666875f3`](https://github.com/JKSunny/EternalJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7395fda4ab6c`](https://github.com/JACoders/OpenJK/commit/7395fda4ab6cae0ca9ca98e68b60f52093622fff)<br>[MP] Fixed some unused variable warnings from svdemo merge. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fde9de23e2ad`](https://github.com/JACoders/OpenJK/commit/fde9de23e2ad96b11d590d659a44b7892f6c601a)<br>Merge pull request #481 from dpadgett/svdemo | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`43f3802e74f9`](https://github.com/JACoders/OpenJK/commit/43f3802e74f91f5a42ab13524d0c6b17d1e593de)<br>[MP] Fix incorrect filesize with SV_DemoFilename. | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `high` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6882abccd6c`](https://github.com/eternalcodes/EternalJK/commit/f6882abccd6cf19d533c41723245bf0a08dde3e0)<br>start/stop svrecording msg only if developer | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)<br>Merge pull request #97 from aufau/ratelimiter | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2023-06-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) · [PR #2](https://github.com/taysta/TaystJK/pull/2)<br>Merge pull request #2 from TomArrow/taysternal | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2343](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2343) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:2086](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2086)
- documentation: [docs/japro_docs.md:394](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L394)
