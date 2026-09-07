---
title: "svdemometa"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svdemometa`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Sets a new metadata entry for server-side demos for one player. Call with clientnum, metakey, [data]

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `svdemometa [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Commit evidence: [`0a8dab604488`](https://github.com/taysta/TaystJK/commit/0a8dab604488c26430fa13f1c2ebd0e1ab4ac11b)
- Attribution method: `first-addition-in-registration-file-history`
- Attribution confidence: `medium`
- Notes: The first exact-name addition in the current registration file is a TaystJK commit; all configured upstream heads were also checked.

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2345](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2345) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:2166](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L2166)
- documentation: [docs/japro_docs.md:396](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L396)
