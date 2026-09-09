---
title: "demo_restart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `demo_restart`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Restarts the current or last-played demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `demo_restart` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Ultimate-origin introduction: [`4e0ab9f26795`](https://github.com/jkanewmod/NewJK/commit/4e0ab9f26795b5583a9d7974f9279d04eec90fb9) in <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> (content authored `2018-09-14`, integrated `2018-09-14`)
- TaystJK integration evidence: [`94672e48ece0`](https://github.com/taysta/TaystJK/commit/94672e48ece0771144723030e011e2443c68a435)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3316](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/client/cl_main.cpp#L3316)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2018-09-14` | — | `2018-09-14` | [`4e0ab9f26795`](https://github.com/jkanewmod/NewJK/commit/4e0ab9f26795b5583a9d7974f9279d04eec90fb9) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-07-26` | — | `2019-07-26` | [`94672e48ece0`](https://github.com/eternalcodes/EternalJK/commit/94672e48ece0771144723030e011e2443c68a435) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-07-26` | — | `2019-07-26` | [`94672e48ece0`](https://github.com/taysta/TaystJK/commit/94672e48ece0771144723030e011e2443c68a435) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-07-26` | — | `2019-07-26` | [`94672e48ece0`](https://github.com/videoP/jaPRO/commit/94672e48ece0771144723030e011e2443c68a435) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-07-26` | — | `2019-07-26` | [`94672e48ece0`](https://github.com/JKSunny/EternalJK/commit/94672e48ece0771144723030e011e2443c68a435) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ef1406f7b8e2`](https://github.com/eternalcodes/EternalJK/commit/ef1406f7b8e25ac2c79eaaf7d12bc49bef2b84b7)<br>whatever | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1ab293e3c1a8`](https://github.com/eternalcodes/EternalJK/commit/1ab293e3c1a88fdb2dca532d9525681905ec04c6)<br>don't care about this nerd shit just enjoy video games | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`803dc5fc991f`](https://github.com/eternalcodes/EternalJK/commit/803dc5fc991fe94dbc3371ef8cef2117a53dab4b)<br>joe mamma | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`825d63b114ab`](https://github.com/eternalcodes/EternalJK/commit/825d63b114abfecc502c4136dc3ce4dad0e0841a)<br>Fix demo_restart+fix bugs in demo commands from 1.00 demo support | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3475](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3475) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:631](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L631)
