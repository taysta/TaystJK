---
title: "cl_afkTime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_afkTime`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Minutes to autorename to afk, 0 to disable

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `10` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`09b3f68fcc6f`](https://github.com/taysta/TaystJK/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3353](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3353)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3452](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3452) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1390](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1390)
- behavior: [codemp/client/cl_input.cpp:1398](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1398)
