---
title: "con_notifylines"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_notifylines`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Max number of console lines to print in top left

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `3` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`012a635e93ad`](https://github.com/taysta/TaystJK/commit/012a635e93ad5338bf9d24fb8401b400176d1431)
- Upstream registration evidence: [codemp/client/cl_console.cpp:533](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L533)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_console.cpp:651](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L651) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:924](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L924)
