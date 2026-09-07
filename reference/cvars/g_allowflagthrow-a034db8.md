---
title: "g_allowFlagThrow"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_allowFlagThrow`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Allow use of /throwflag command.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`6c739c8869c2`](https://github.com/taysta/TaystJK/commit/6c739c8869c2b4d423de48632c20b508fa9d5e91)
- Upstream registration evidence: [codemp/game/g_xcvar.h:165](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L165)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:186](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L186) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:5750](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L5750)
- behavior: [codemp/game/g_combat.c:694](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_combat.c#L694)
- behavior: [codemp/game/g_combat.c:6344](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_combat.c#L6344)
- behavior: [codemp/game/g_items.c:2555](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_items.c#L2555)
- behavior: [codemp/game/g_items.c:2901](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_items.c#L2901)
- documentation: [docs/japro_docs.md:7](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L7)
