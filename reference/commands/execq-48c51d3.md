---
title: "execq"
layout: reference
nav_exclude: true
search_exclude: false
---

# `execq`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Execute a script file without displaying a message

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `execq [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`649941d04db2`](https://github.com/taysta/TaystJK/commit/649941d04db2a0d5581825824a3b88a3912f3185)
- Upstream registration evidence: [code/qcommon/cmd.cpp:807](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cmd.cpp#L807)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/cmd.cpp:1212](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L1212) (Cmd_AddCommand)
- handler: [codemp/qcommon/cmd.cpp:412](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L412)
