---
title: "cl_renderer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_renderer`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Which renderer library to use

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `DEFAULT_RENDER_LIBRARY` |
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`c6d09e4f8184`](https://github.com/taysta/TaystJK/commit/c6d09e4f8184af3b247044827f37d47f4fe665f7)
- Upstream registration evidence: [code/client/cl_main.cpp:1091](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_main.cpp#L1091)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:2744](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2744) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2748](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2748)
- behavior: [codemp/client/cl_main.cpp:2746](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2746)
- behavior: [codemp/ui/ui_main.c:6241](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6241)
- behavior: [codemp/ui/ui_main.c:6369](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6369)
- behavior: [codemp/client/cl_main.cpp:2751](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2751)
