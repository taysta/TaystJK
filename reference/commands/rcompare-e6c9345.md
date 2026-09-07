---
title: "rCompare"
layout: reference
nav_exclude: true
search_exclude: false
---

# `rCompare`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_DFCompare_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `rCompare <username> <style (optional)> <current season (optional - example: s) <page (optional)>. This displays the courses that the specified user has defeated you on` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`90d3c68f2da9`](https://github.com/taysta/TaystJK/commit/90d3c68f2da918f353b24bff60e49066dd018806)
- Pull request: [#84](https://github.com/taysta/TaystJK/pull/84)
- Matching squash bullet: `rCompare command`
- Upstream registration evidence: [codemp/game/g_cmds.c:8967](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_cmds.c#L8967)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_cmds.c:9022](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L9022) (game command table)
- handler: [codemp/game/g_account.c:5993](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L5993)
