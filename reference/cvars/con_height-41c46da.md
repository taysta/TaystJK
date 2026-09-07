---
title: "con_height"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_height`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Adjust the height of the console

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0.5` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`87a349344ecc`](https://github.com/taysta/TaystJK/commit/87a349344ecc309b53f4c5cc37f58a070b0d114e)
- Upstream registration evidence: [code/client/cl_console.cpp:421](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_console.cpp#L421)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_console.cpp:664](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L664) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1244](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1244)
