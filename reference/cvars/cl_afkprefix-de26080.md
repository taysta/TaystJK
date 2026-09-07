---
title: "cl_afkPrefix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_afkPrefix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Prefix to add to player name when AFK

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `[AFK]` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`14445ff9c18f`](https://github.com/taysta/TaystJK/commit/14445ff9c18f6e2fb94b8ce3f54f2b00a6a35435)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3352](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3352)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3451) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2368](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2368)
- behavior: [codemp/client/cl_main.cpp:2367](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2367)
- behavior: [codemp/client/cl_main.cpp:3003](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3003)
