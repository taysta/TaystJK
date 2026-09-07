---
title: "cl_consoleUseScanCode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_consoleUseScanCode`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Use native console key detection

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sdl/sdl_input.cpp:401](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L401) |
| `1` | Enabled. | [shared/sdl/sdl_input.cpp:401](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L401) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`0a65fd6a7237`](https://github.com/taysta/TaystJK/commit/0a65fd6a7237f66369e2b3a339b633e0e5f42be3)
- Upstream registration evidence: [code/client/cl_main.cpp:1283](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_main.cpp#L1283)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits openjk.

## Evidence

- registration: [codemp/client/cl_main.cpp:3403](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3403) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:401](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L401)
- behavior: [shared/sdl/sdl_input.cpp:888](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L888)
