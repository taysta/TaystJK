---
title: "loadmod"
layout: reference
nav_exclude: true
search_exclude: false
---

# `loadmod`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Restart the renderer (with specified mod folder) - or change the resolution

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `loadmod <folder name>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`52629011eedc`](https://github.com/taysta/TaystJK/commit/52629011eedcd855f9e2cf108c6d386d137ecda9)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3382](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3382)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3481](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3481) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:1302](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1302)
