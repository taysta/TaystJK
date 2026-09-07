---
title: "sv_antiDST"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_antiDST`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Attempts to detect and kick players injecting or using DST

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_client.cpp:1278](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1278) |
| `1` | Enabled. | [codemp/server/sv_client.cpp:1278](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1278) |

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`953b37ce8fef`](https://github.com/taysta/TaystJK/commit/953b37ce8fefe7b3345243263f0334975ef59845)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1032](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_init.cpp#L1032)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_init.cpp:1071](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1071) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_client.cpp:1278](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1278)
- behavior: [codemp/server/sv_client.cpp:1462](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1462)
