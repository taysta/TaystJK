---
title: "cl_avi2GBLimit"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_avi2GBLimit`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_avi2GBLimit` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_avi.cpp:451](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L451) |
| `1` | Enabled. | [codemp/client/cl_avi.cpp:451](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L451) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`e0291062ce4a`](https://github.com/JACoders/OpenJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-04-21`, integrated `2014-04-21`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2761](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2761)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/JACoders/OpenJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/eternalcodes/EternalJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/SomaZ/OpenJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/taysta/TaystJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/videoP/jaPRO/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/jkanewmod/NewJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-04-21` | — | `2014-04-21` | [`e0291062ce4a`](https://github.com/JKSunny/EternalJK/commit/e0291062ce4afb88e725b51aa99a07148c96ba65) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_main.cpp:3330](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3330) (Cvar_Get)
- behavior: [codemp/client/cl_avi.cpp:451](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L451)
