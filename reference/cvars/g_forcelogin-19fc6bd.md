---
title: "g_forceLogin"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_forceLogin`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

1=Force players to login in order to be ingame. 2=also block them from chatting until logging in. 3=also block them from renaming until logging in.

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

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Force players to login in order to be ingame. | [docs/japro_docs.md:125](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L125) |
| `2` | Also block them from chatting until logging in. | [docs/japro_docs.md:125](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L125) |
| `3` | Also block them from renaming until logging in. | [docs/japro_docs.md:125](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L125) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`a363ea30521a`](https://github.com/taysta/TaystJK/commit/a363ea30521a30db37ce43c1311b6f736dc0416c)
- Upstream registration evidence: [codemp/game/g_xcvar.h:304](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L304)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:325](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L325) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:3759](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L3759)
- behavior: [codemp/game/g_client.c:2520](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2520)
- behavior: [codemp/game/g_cmds.c:1231](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L1231)
- behavior: [codemp/game/g_cmds.c:1247](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L1247)
- behavior: [codemp/game/g_cmds.c:1367](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L1367)
- documentation: [docs/japro_docs.md:125](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L125)
