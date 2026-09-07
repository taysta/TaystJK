---
title: "DBInfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `DBInfo`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_DBInfo_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `DBInfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`459500d1612b`](https://github.com/taysta/TaystJK/commit/459500d1612b1e90491a6e58e23e02e503a2700f)
- Upstream registration evidence: [codemp/game/g_svcmds.c:1654](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_svcmds.c#L1654)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/game/g_svcmds.c:1669](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L1669) (game-console command table)
- handler: [codemp/game/g_account.c:3055](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L3055)
