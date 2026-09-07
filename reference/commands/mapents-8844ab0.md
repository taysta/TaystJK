---
title: "mapents"
layout: reference
nav_exclude: true
search_exclude: false
---

# `mapents`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_MapEnts_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `mapents <save/load> <name>` |
| Cheat protected | Yes |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_CHEAT`, `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`8e611875909c`](https://github.com/taysta/TaystJK/commit/8e611875909cd31f071e85a89ed2c5a9a2743b7d)
- Upstream registration evidence: [codemp/game/g_cmds.c:8943](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_cmds.c#L8943)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/game/g_cmds.c:8998](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8998) (game command table)
- handler: [codemp/game/g_cmds.c:8230](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8230)
