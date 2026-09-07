---
title: "cl_downloadPrompt"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_downloadPrompt`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Confirm pk3 downloads from the server

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`f536ef9da5b7`](https://github.com/taysta/TaystJK/commit/f536ef9da5b7fa622af43e33e7b9a1425b0f4ae5)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2833](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2833)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3407](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3407) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1592](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1592)
- behavior: [codemp/client/cl_main.cpp:1555](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1555)
