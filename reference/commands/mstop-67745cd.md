---
title: "mstop"
layout: reference
nav_exclude: true
search_exclude: false
---

# `mstop`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Simulates the operating system stop-media key. Registered only in Windows builds.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `mstop` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`10e206dae50c`](https://github.com/taysta/TaystJK/commit/10e206dae50cb6f933eb2a246559e37dfede227a)
- Upstream registration evidence: [codemp/qcommon/common.cpp:1221](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/qcommon/common.cpp#L1221)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits newjk.

## Evidence

- registration: [codemp/qcommon/common.cpp:1410](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1410) (Cmd_AddCommand); condition `defined(_WIN32)`
- handler: [codemp/qcommon/common.cpp:527](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L527)
