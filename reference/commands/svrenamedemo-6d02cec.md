---
title: "svrenamedemo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svrenamedemo`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Rename a server-side demo

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `svrenamedemo [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`35964d09125f`](https://github.com/taysta/TaystJK/commit/35964d09125ffe6184b72f990dec93202a7971e3)
- Upstream registration evidence: [codemp/server/sv_ccmds.cpp:1311](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/server/sv_ccmds.cpp#L1311)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2348](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2348) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:1705](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1705)
- documentation: [docs/japro_docs.md:399](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L399)
