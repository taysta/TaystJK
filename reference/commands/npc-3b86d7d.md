---
title: "NPC"
layout: reference
nav_exclude: true
search_exclude: false
---

# `NPC`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Removed cheat for admin //meh let us npc kill all from spec

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `NPC [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`98a4386bfce2`](https://github.com/taysta/TaystJK/commit/98a4386bfce29da46eed286ffeccce53a85362d8)
- Upstream registration evidence: [code/cgame/cg_consolecmds.cpp:303](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/cgame/cg_consolecmds.cpp#L303)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2587](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2587) (forwarded client command table)
- registration: [codemp/cgame/cg_consolecmds.c:2632](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2632) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9013](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L9013) (game command table)
- handler: [codemp/game/NPC_spawn.c:4291](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/NPC_spawn.c#L4291)
