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
| `HTTP` | Download from the server's advertised HTTP endpoint. | [codemp/client/cl_main.cpp:1547](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1547) |
| `UDP` | Use the legacy in-protocol UDP download path. | [codemp/client/cl_main.cpp:1549](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1549) |

## Flags

- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) on `2015-03-19` in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>
- TaystJK integration evidence: [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d)
- Pull request: [#169](https://github.com/taysta/TaystJK/pull/169)
- Matching squash bullet: `[HTTP-AutoDL] Libmongoose 7 port from jk2mv`
- Upstream registration evidence: [src/client/cl_main.cpp:2960](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_main.cpp#L2960)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits jk2mv.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2015-03-19` | [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-03-21` | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-03-21` | [`2a5ea5d885dc`](https://github.com/videoP/jaPRO/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) | Later project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3411](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3411) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1557](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1557)
- behavior: [codemp/client/cl_main.cpp:1547](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1547)
- behavior: [codemp/client/cl_main.cpp:1549](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1549)
