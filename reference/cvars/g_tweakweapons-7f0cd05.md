---
title: "g_tweakWeapons"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_tweakWeapons`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Configured with /tweakWeapons command

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
| `524288` | Enables the `WT_ANTI_VEHICLE` code path. | [codemp/game/g_local.h:213](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L213) |
| `67108864` | Enables the `WT_PROJ_SNIPER` code path. | [codemp/game/g_local.h:220](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L220) |
| `134217728` | Move this into g_tribesmode surely..? | [codemp/game/g_local.h:221](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L221) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`31381094ec52`](https://github.com/taysta/TaystJK/commit/31381094ec52112b6f9b73c109eb6c7aa9148c4e)
- Upstream registration evidence: [codemp/game/g_xcvar.h:197](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L197)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:218](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L218) (XCVAR_DEF)
- behavior: [codemp/game/NPC_AI_Jedi.c:6310](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/NPC_AI_Jedi.c#L6310)
- behavior: [codemp/game/NPC_spawn.c:1539](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/NPC_spawn.c#L1539)
- behavior: [codemp/game/ai_main.c:4639](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L4639)
- behavior: [codemp/game/ai_main.c:4653](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L4653)
- behavior: [codemp/game/ai_main.c:4657](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L4657)
- documentation: [docs/japro_docs.md:38](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L38)
