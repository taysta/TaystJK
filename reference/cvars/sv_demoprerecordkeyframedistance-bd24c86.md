---
title: "sv_demoPreRecordKeyframeDistance"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_demoPreRecordKeyframeDistance`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

A demo can only start with a gamestate and full non-delta snapshot. How often should we save such a gamestate message? The shorter the distance, the more precisely the pre-record duration will be kept, but also the higher the RAM usage and regularity of non-delta frames being sent to the clients.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `5` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Commit evidence: [`ff998f1a0716`](https://github.com/taysta/TaystJK/commit/ff998f1a071619fa801f26568c92b61d5e92677d)
- Attribution method: `first-addition-in-registration-file-history`
- Attribution confidence: `medium`
- Notes: The first exact-name addition in the current registration file is a TaystJK commit; all configured upstream heads were also checked.

## Evidence

- registration: [codemp/server/sv_init.cpp:1059](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1059) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_snapshot.cpp:865](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L865)
- behavior: [codemp/server/sv_ccmds.cpp:1642](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1642)
- behavior: [codemp/server/server.h:140](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L140)
- behavior: [codemp/server/server.h:144](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L144)
- documentation: [docs/japro_docs.md:135](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L135)
