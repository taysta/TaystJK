---
title: "cl_downloadProtocol"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_downloadProtocol`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Reports the protocol selected for the active file download. The client sets this internal cvar to HTTP when the server advertised an HTTP endpoint and otherwise sets it to UDP.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
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

- Commit evidence: [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d)
- Pull request: [#169](https://github.com/taysta/TaystJK/pull/169)
- Matching squash bullet: `[HTTP-AutoDL] Libmongoose 7 port from jk2mv`
- Upstream registration evidence: [src/client/cl_main.cpp:2960](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_main.cpp#L2960)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

## Evidence

- registration: [codemp/client/cl_main.cpp:3411](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3411) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1557](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1557)
- behavior: [codemp/client/cl_main.cpp:1547](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1547)
- behavior: [codemp/client/cl_main.cpp:1549](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1549)
