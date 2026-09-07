---
title: "cl_allowEnterCompletion"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_allowEnterCompletion`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Enables autocomplete when pressing enter

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L858) |
| `1` | Enabled. | [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L858) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`d23425fac341`](https://github.com/taysta/TaystJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3224](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/client/cl_main.cpp#L3224)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/client/cl_main.cpp:3364](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3364) (Cvar_Get)
- behavior: [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L858)
