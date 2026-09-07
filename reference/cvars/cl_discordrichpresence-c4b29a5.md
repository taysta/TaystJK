---
title: "cl_discordRichPresence"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_discordRichPresence`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Allow/disallow sharing current game information on Discord profile status

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
| `0` | Disabled. | [codemp/client/cl_discordrpc.cpp:152](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L152) |
| `1` | Enabled. | [codemp/client/cl_discordrpc.cpp:152](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L152) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`1bcb29af6443`](https://github.com/taysta/TaystJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3360](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3360)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3459](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3459) (Cvar_Get); condition `defined(DISCORD) && !defined(_DEBUG)`
- behavior: [codemp/client/cl_discordrpc.cpp:152](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L152)
- behavior: [codemp/client/cl_discordrpc.cpp:225](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L225)
- behavior: [codemp/client/cl_discordrpc.cpp:246](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L246)
- behavior: [codemp/client/cl_discordrpc.cpp:474](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L474)
- behavior: [codemp/client/cl_discordrpc.cpp:485](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L485)
