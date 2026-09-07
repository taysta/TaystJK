---
title: "sv_snapShotDuelCull"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_snapShotDuelCull`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Snapshot-based duel isolation

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
| `0` | Disabled. | [codemp/server/duel_cull.cpp:102](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/duel_cull.cpp#L102) |
| `1` | Enabled. | [codemp/server/duel_cull.cpp:102](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/duel_cull.cpp#L102) |

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`7504815f10f9`](https://github.com/taysta/TaystJK/commit/7504815f10f917215457c6a228aa7b7c8e117192)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1024](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_init.cpp#L1024)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_init.cpp:1063](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1063) (Cvar_Get)
- behavior: [codemp/server/duel_cull.cpp:102](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/duel_cull.cpp#L102)
