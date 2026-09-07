---
title: "con_notifyvote"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_notifyvote`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Notifies you when someone calls a vote

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
| `0` | Disabled. | [codemp/client/cl_cgame.cpp:622](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L622) |
| `1` | Enabled. | [codemp/client/cl_cgame.cpp:622](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L622) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`7f33b45b0043`](https://github.com/taysta/TaystJK/commit/7f33b45b0043eead70fc5b12a4881352fa0c1f8a)
- Upstream registration evidence: [codemp/client/cl_console.cpp:545](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L545)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits eternaljk.

## Evidence

- registration: [codemp/client/cl_console.cpp:663](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L663) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:622](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L622)
