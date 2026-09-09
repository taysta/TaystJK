---
title: "cl_downloadProtocol"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_downloadProtocol`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Reports the protocol selected for the active file download. The client sets this internal cvar to HTTP when the server advertised an HTTP endpoint and otherwise sets it to UDP.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `HTTP` | Download from the server's advertised HTTP endpoint. | [codemp/client/cl_main.cpp:1547](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1547) |
| `UDP` | Use the legacy in-protocol UDP download path. | [codemp/client/cl_main.cpp:1549](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1549) |

## Flags

- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2015-03-19`, integrated `2015-03-19`)
- TaystJK integration evidence: [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d)
- Origin pull request: [#169](https://github.com/taysta/TaystJK/pull/169)
- Matching squash bullet: `[HTTP-AutoDL] Libmongoose 7 port from jk2mv`
- Upstream registration evidence: [src/client/cl_main.cpp:2960](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_main.cpp#L2960)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits jk2mv.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2015-03-19` | — | `2015-03-19` | [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-03-21` | [2024-03-07](https://github.com/taysta/TaystJK/pull/169) | `2024-03-21` | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-03-21` | — | `2024-03-21` | [`2a5ea5d885dc`](https://github.com/videoP/jaPRO/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3411](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3411) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1557](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1557)
- behavior: [codemp/client/cl_main.cpp:1547](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1547)
- behavior: [codemp/client/cl_main.cpp:1549](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1549)
