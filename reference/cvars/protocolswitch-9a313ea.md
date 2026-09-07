---
title: "protocolswitch"
layout: reference
nav_exclude: true
search_exclude: false
---

# `protocolswitch`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Sets protocol based on server info response

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Selects the code path tested for value 0. | [codemp/client/cl_main.cpp:1783](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1783) |
| `2` | Selects the code path tested for value 2. | [codemp/client/cl_main.cpp:335](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L335) |

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_NORESTART` — preserved across cvar restart
- `CVAR_PROTECTED` — protected from unsafe remote changes
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Commit evidence: [`a983fa494fee`](https://github.com/taysta/TaystJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

## Evidence

- registration: [codemp/client/cl_main.cpp:3335](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3335) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:335](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L335)
- behavior: [codemp/client/cl_main.cpp:1783](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1783)
- behavior: [codemp/client/cl_main.cpp:1794](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1794)
- behavior: [codemp/qcommon/files.cpp:4170](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L4170)
- behavior: [codemp/cgame/cg_main.c:3173](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_main.c#L3173)
