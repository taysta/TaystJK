---
title: "cl_colorStringRandom"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_colorStringRandom`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Randomness of the colors changing, higher numbers are less random

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`9888b3f266ed`](https://github.com/taysta/TaystJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3347](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3347)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3446](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3446) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:3142](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3142)
