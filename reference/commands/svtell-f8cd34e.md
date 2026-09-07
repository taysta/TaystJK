---
title: "svtell"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svtell`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Private message from the server to a user

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `svtell <client number> <text>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`03bba21225bb`](https://github.com/taysta/TaystJK/commit/03bba21225bbdfe484236d00966b6783bd2077a7)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1980](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1980)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2339](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2339) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:1259](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1259)
