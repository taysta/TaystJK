---
title: "cl_currentServerIP"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_currentServerIP`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `loopback` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `loopback` | `engine-client` | `—` | `always` |
| `serverString` | `engine-client` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-17`, integrated `2013-04-18`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:690](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L690)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/eternalcodes/EternalJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/SomaZ/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/taysta/TaystJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/videoP/jaPRO/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/jkanewmod/NewJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-17` | — | `2013-04-18` | [`9e15fadfd9b4`](https://github.com/JKSunny/EternalJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_main.cpp:816](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L816) (implicit Cvar_Set)
- registration: [codemp/client/cl_main.cpp:1208](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1208) (implicit Cvar_Set)
