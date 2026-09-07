---
title: "unset_usercreated"
layout: reference
nav_exclude: true
search_exclude: false
---

# `unset_usercreated`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Unset all user generated cvars Use with caution!

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `unset_usercreated` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`28c72736b22b`](https://github.com/taysta/TaystJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42)
- Upstream registration evidence: [code/qcommon/cvar.cpp:1385](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cvar.cpp#L1385)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1641](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1641) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1384](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1384)
