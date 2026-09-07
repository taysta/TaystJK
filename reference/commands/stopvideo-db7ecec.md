---
title: "stopvideo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `stopvideo`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Stop avi recording

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `stopvideo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`66642f7cd25a`](https://github.com/taysta/TaystJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2894](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2894)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3498](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3498) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:2969](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2969)
