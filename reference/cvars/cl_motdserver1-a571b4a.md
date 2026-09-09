---
title: "cl_motdServer1"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_motdServer1`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `UPDATE_SERVER_NAME` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`3a70129c5dd2`](https://github.com/JACoders/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-05-17`, integrated `2014-05-17`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2743](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2743)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/JACoders/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/eternalcodes/EternalJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/SomaZ/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/taysta/TaystJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/videoP/jaPRO/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/jkanewmod/NewJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-05-17` | — | `2014-05-17` | [`3a70129c5dd2`](https://github.com/JKSunny/EternalJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_main.cpp:3313](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3313) (Cvar_Get)
