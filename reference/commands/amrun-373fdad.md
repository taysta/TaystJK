---
title: "amrun"
layout: reference
nav_exclude: true
search_exclude: false
---

# `amrun`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

EMOTE

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `amrun` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c)
- Upstream registration evidence: [codemp/game/g_cmds.c:8844](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_cmds.c#L8844)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2498](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2498) (cgame command table)
- registration: [codemp/game/g_cmds.c:8899](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8899) (game command table)
- handler: [codemp/cgame/cg_consolecmds.c:1960](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1960)
- handler: [codemp/game/g_cmds.c:6651](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L6651)
