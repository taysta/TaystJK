---
title: "cl_coloredTextShadows"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_coloredTextShadows`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Toggle JK2 1.02-style colored text shadows

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
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
| `0` | Disabled. | [codemp/rd-common/tr_font.cpp:1625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1625) |
| `1` | Enabled. | [codemp/rd-common/tr_font.cpp:1625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1625) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`82c74a03d641`](https://github.com/taysta/TaystJK/commit/82c74a03d641380e7724758570852e848c97231e)
- Upstream registration evidence: [codemp/rd-common/tr_font.cpp:1740](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/rd-common/tr_font.cpp#L1740)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/rd-common/tr_font.cpp:1844](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1844) (Cvar_Get)
- behavior: [codemp/rd-common/tr_font.cpp:1625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1625)
