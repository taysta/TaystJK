---
title: "cl_afkTimeUnfocused"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_afkTimeUnfocused`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Minutes to autorename to afk while unfocused/minimized

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `5` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`cc95a484132f`](https://github.com/taysta/TaystJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3354](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3354)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3453](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3453) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1397](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1397)
