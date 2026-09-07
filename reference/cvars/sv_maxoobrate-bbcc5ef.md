---
title: "sv_maxOOBRate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_maxOOBRate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Maximum rate of handling incoming server commands

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1000` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`a84369bc60c3`](https://github.com/taysta/TaystJK/commit/a84369bc60c3348a381f5a36034d3f53a96d0c79)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1013](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1013)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_init.cpp:1051](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1051) (Cvar_Get)
- behavior: [codemp/server/sv_main.cpp:753](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L753)
- behavior: [codemp/server/sv_main.cpp:754](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L754)
