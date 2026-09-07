---
title: "cl_chatStyleSuffix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_chatStyleSuffix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

String appended to send chat messages

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`986358853af6`](https://github.com/taysta/TaystJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3350](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3350)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3449](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3449) (Cvar_Get)
- behavior: [codemp/client/cl_keys.cpp:1027](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L1027)
- behavior: [codemp/client/cl_keys.cpp:1028](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_keys.cpp#L1028)
