---
title: "+button15"
layout: reference
nav_exclude: true
search_exclude: false
---

# `+button15`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Button 15

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `+button15` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-24`, integrated `2013-04-24`)
- TaystJK integration evidence: [`c9c6ab99fdd2`](https://github.com/taysta/TaystJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)
- Upstream registration evidence: [code/client/cl_input.cpp:1027](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_input.cpp#L1027)
- Attribution method: `shared-integration-explicit-credit`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-24` | — | `2013-04-24` | [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-24` | — | `2013-04-24` | [`3e986be9ab0d`](https://github.com/SomaZ/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-24` | — | `2013-04-24` | [`3e986be9ab0d`](https://github.com/jkanewmod/NewJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-24` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-24` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/taysta/TaystJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-24` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/videoP/jaPRO/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-24` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/JKSunny/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8d3ea7d2b755`](https://github.com/JACoders/OpenJK/commit/8d3ea7d2b755ed3d1a48e7681e2952d488205170)<br>Support up to 32 buttons in single player.  Commands registered for 0-15 for now. Buttons 0-8 are just aliases for the existing buttons. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_input.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_input.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_input.cpp:1779](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1779) (input command table)
- handler: [codemp/client/cl_input.cpp:795](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L795)
