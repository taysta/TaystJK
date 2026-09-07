---
title: "unset"
layout: reference
nav_exclude: true
search_exclude: false
---

# `unset`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Unset a user generated cvar

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `unset <varname>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`3b9054288cb6`](https://github.com/taysta/TaystJK/commit/3b9054288cb68485297a53f60e618d7ffb6d16ae)
- Upstream registration evidence: [code/qcommon/cvar.cpp:1383](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cvar.cpp#L1383)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1639](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1639) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1363](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1363)
