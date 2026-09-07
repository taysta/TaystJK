---
title: "delaycancel"
layout: reference
nav_exclude: true
search_exclude: false
---

# `delaycancel`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Cancels pending millisecond-based delay entries whose command text contains the supplied text. An empty string matches every pending delay.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `delaycancel <text>` |
| Cheat protected | No |

## Arguments and gating

Arguments: `text`.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`fe25979e3fb5`](https://github.com/taysta/TaystJK/commit/fe25979e3fb58eb466ef4ba82680bb684588bf0f)
- Upstream registration evidence: [codemp/qcommon/cmd.cpp:1187](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/qcommon/cmd.cpp#L1187)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits newjk.

## Evidence

- registration: [codemp/qcommon/cmd.cpp:1219](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L1219) (Cmd_AddCommand)
- handler: [codemp/qcommon/cmd.cpp:114](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L114)
