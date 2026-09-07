---
title: "whitelistip"
layout: reference
nav_exclude: true
search_exclude: false
---

# `whitelistip`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Add IP to the whitelist

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `whitelistip <ip>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`aa53d2d4b1a3`](https://github.com/taysta/TaystJK/commit/aa53d2d4b1a373dd7e71d9cca8b6e862d4359fa7)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1992](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_ccmds.cpp#L1992)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2358](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2358) (Cmd_AddCommand)
- handler: [codemp/server/sv_ccmds.cpp:2273](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2273)
