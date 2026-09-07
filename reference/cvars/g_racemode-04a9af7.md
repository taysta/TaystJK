---
title: "g_raceMode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_raceMode`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

0=Noracemode, 1=forcedracemode, 2=player can toggle race mode with /racecommand.

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
| `0` | Noracemode. | [docs/japro_docs.md:121](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L121) |
| `1` | Forcedracemode. | [docs/japro_docs.md:121](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L121) |
| `2` | Player can toggle race mode with /racecommand. | [docs/japro_docs.md:121](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L121) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`1be74bd54668`](https://github.com/taysta/TaystJK/commit/1be74bd546680491e9a1b679ac7a4eec40e23460)
- Upstream registration evidence: [codemp/game/g_xcvar.h:300](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L300)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:321](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L321) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:3764](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L3764)
- behavior: [codemp/game/g_client.c:3167](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L3167)
- behavior: [codemp/game/g_client.c:3169](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L3169)
- behavior: [codemp/game/g_client.c:4242](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L4242)
- behavior: [codemp/game/g_client.c:4244](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L4244)
- documentation: [docs/japro_docs.md:121](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L121)
