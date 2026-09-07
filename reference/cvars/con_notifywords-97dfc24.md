---
title: "con_notifywords"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_notifywords`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Notifies you when defined words are mentioned

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
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`22d8366b7d2a`](https://github.com/taysta/TaystJK/commit/22d8366b7d2a31aaf298f3391a73d5a30c5f0eae)
- Upstream registration evidence: [codemp/client/cl_console.cpp:543](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L543)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits eternaljk.

## Evidence

- registration: [codemp/client/cl_console.cpp:661](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L661) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:586](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L586)
- behavior: [codemp/client/cl_cgame.cpp:591](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L591)
- behavior: [codemp/client/cl_main.cpp:2399](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2399)
- behavior: [codemp/client/cl_main.cpp:2450](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2450)
- behavior: [codemp/client/cl_main.cpp:2451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2451)
