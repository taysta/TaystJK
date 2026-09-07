---
title: "fx_jk2"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fx_jk2`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Displays jk2 style projectile fx - 0: Disabled - 1: Enabled

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L119) |
| `1` | Enabled. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L119) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`8b353c2103fd`](https://github.com/taysta/TaystJK/commit/8b353c2103fd0d0f294f799e32de0d7dd164bb03)
- Pull request: [#219](https://github.com/taysta/TaystJK/pull/219)
- Matching squash bullet: `Refactor cl_jk2fx cvar into fx_jk2 - enabled jk2 projectiles fx`
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxUtil.cpp#L119) (Cvar_Get)
- behavior: [codemp/client/FxScheduler.cpp:464](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/FxScheduler.cpp#L464)
