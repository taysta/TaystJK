---
title: "resetScores"
layout: reference
nav_exclude: true
search_exclude: false
---

# `resetScores`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Reset all player/team scores without having to reload the map.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `resetScores` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`4a597b71c92d`](https://github.com/taysta/TaystJK/commit/4a597b71c92df34eed0330023af0586118f0e19a)
- Upstream registration evidence: [codemp/game/g_svcmds.c:1685](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_svcmds.c#L1685)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/game/g_svcmds.c:1700](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L1700) (game-console command table)
- handler: [codemp/game/g_svcmds.c:554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L554)
- documentation: [docs/japro_docs.md:174](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L174)
