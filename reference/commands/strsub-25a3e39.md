---
title: "strSub"
layout: reference
nav_exclude: true
search_exclude: false
---

# `strSub`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Executes a command after replacing text surrounded by dollar signs with the value of that cvar. A doubled dollar sign emits one literal dollar sign.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `strSub <command...>` |
| Cheat protected | No |

## Arguments and gating

Arguments: `command`.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`fe25979e3fb5`](https://github.com/taysta/TaystJK/commit/fe25979e3fb58eb466ef4ba82680bb684588bf0f)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits newjk.

## Evidence

- registration: [codemp/qcommon/common.cpp:1425](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1425) (Cmd_AddCommand)
- handler: [codemp/qcommon/common.cpp:433](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L433)
