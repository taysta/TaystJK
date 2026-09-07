---
title: "g_fixSlidePhysics"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixSlidePhysics`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

1=Fixed slide physics for NPCS. 2=Fixed slide physics for NPCs and players.

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
| `1` | Fixed slide physics for NPCS. | [docs/japro_docs.md:56](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L56) |
| `2` | Fixed slide physics for NPCs and players. | [docs/japro_docs.md:56](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L56) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`cf582ccd9b1f`](https://github.com/taysta/TaystJK/commit/cf582ccd9b1fdd94ca625c52c4ba63cf74e27481)
- Upstream registration evidence: [codemp/game/g_xcvar.h:219](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L219)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:240](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L240) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:6053](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L6053)
- behavior: [codemp/game/bg_pmove.c:6055](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L6055)
- behavior: [codemp/game/g_cmds.c:8514](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8514)
- behavior: [codemp/game/g_cmds.c:8516](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8516)
- behavior: [codemp/game/g_trigger.c:2460](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_trigger.c#L2460)
- documentation: [docs/japro_docs.md:56](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L56)
