---
title: "cl_reconnectArgs"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_reconnectArgs`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Arguments provided when last connecting to a server

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`d599e706c7ff`](https://github.com/taysta/TaystJK/commit/d599e706c7ff985572ce00a7657abf0353a4dc82)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2836](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2836)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3413) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1124](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1124)
- behavior: [codemp/client/cl_main.cpp:1128](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1128)
- behavior: [codemp/client/cl_main.cpp:1147](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1147)
