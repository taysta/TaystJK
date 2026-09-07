---
title: "cl_mouseAccelStyle"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_mouseAccelStyle`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Mouse accelration style (0:legacy, 1:QuakeLive)

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Legacy. | [codemp/client/cl_main.cpp:3355](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3355) |
| `1` | QuakeLive). | [codemp/client/cl_main.cpp:3355](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3355) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`ae0f733b9635`](https://github.com/taysta/TaystJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2780](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2780)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3355](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3355) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1100](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1100)
