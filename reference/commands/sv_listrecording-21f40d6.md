---
title: "sv_listrecording"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_listrecording`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Lists demos being recorded

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `sv_listrecording` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`724b58ba6bf5`](https://github.com/taysta/TaystJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:2052](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/server/sv_ccmds.cpp#L2052)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2349](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2349) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:1730](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1730)
