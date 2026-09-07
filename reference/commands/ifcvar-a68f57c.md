---
title: "ifCvar"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ifCvar`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

Tests a cvar against conditions in order and executes the command belonging to the first match. Conditions support literal string equality; numeric $=, $!=, $>, $<, $>= and $<= comparisons; $contains; $beginswith/$startswith; $endswith; $else; and values read from another cvar with a leading $. The argument count includes the command itself.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `ifCvar <cvar> <setting> <argument-count> <command...> [<setting> <argument-count> <command...> ...]` |
| Cheat protected | No |

## Arguments and gating

Arguments: `cvar`, `setting`, `argument-count`, `command`, `...`.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`fe25979e3fb5`](https://github.com/taysta/TaystJK/commit/fe25979e3fb58eb466ef4ba82680bb684588bf0f)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits newjk.

## Evidence

- registration: [codemp/qcommon/common.cpp:1426](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1426) (Cmd_AddCommand)
- handler: [codemp/qcommon/common.cpp:346](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L346)
