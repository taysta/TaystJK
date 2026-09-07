---
title: "addFavorite"
layout: reference
nav_exclude: true
search_exclude: false
---

# `addFavorite`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Add server to favorites

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `addFavorite [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`fcc89fdf6fcb`](https://github.com/taysta/TaystJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2870](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2870)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3467](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3467) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:2974](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2974)
