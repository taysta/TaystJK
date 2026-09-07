---
title: "cl_consoleKeys"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_consoleKeys`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Which keys are used to toggle the console

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `~ &#96; 0x7e 0x60 0xb2` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`85490e13e6f5`](https://github.com/taysta/TaystJK/commit/85490e13e6f5427ea06f5a56237a3c7c2aec5bcf)
- Upstream registration evidence: [code/client/cl_main.cpp:1282](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_main.cpp#L1282)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits openjk.

## Evidence

- registration: [codemp/client/cl_main.cpp:3402](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3402) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:124](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L124)
- behavior: [shared/sdl/sdl_input.cpp:118](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L118)
- behavior: [shared/sdl/sdl_input.cpp:123](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L123)
- behavior: [shared/sdl/sdl_input.cpp:127](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L127)
