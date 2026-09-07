---
title: "cvarMult"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cvarMult`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Multiply a value to a cvar

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `cvarMult <variable> <value>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`55d9184d89f7`](https://github.com/taysta/TaystJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16)
- Upstream registration evidence: [codemp/qcommon/cvar.cpp:1605](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/cvar.cpp#L1605)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1631](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1631) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1116](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1116)
