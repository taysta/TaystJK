---
title: "sv_flushbans"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_flushbans`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Removes all bans and exceptions

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `sv_flushbans` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`9c68d9f362bc`](https://github.com/taysta/TaystJK/commit/9c68d9f362bcfafb08c6c08101c80eb5028a5eef)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1991](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1991)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2357](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2357) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:1075](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1075)
