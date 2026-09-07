---
title: "g_flipKick"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_flipKick`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

1=JA+ style. 2=Floodprotected to one kick every 50ms. 3=JK2 style.

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | JA+ style. | [docs/japro_docs.md:48](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L48) |
| `2` | Floodprotected to one kick every 50ms. | [docs/japro_docs.md:48](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L48) |
| `3` | JK2 style. | [docs/japro_docs.md:48](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L48) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`fde2770ff418`](https://github.com/taysta/TaystJK/commit/fde2770ff41872d4aa1bc70d427bb473f7a80f2a)
- Upstream registration evidence: [codemp/game/g_xcvar.h:208](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L208)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:229](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L229) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:7832](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L7832)
- behavior: [codemp/game/ai_main.c:9022](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L9022)
- behavior: [codemp/game/bg_pmove.c:3865](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L3865)
- behavior: [codemp/game/bg_pmove.c:3870](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L3870)
- behavior: [codemp/game/bg_pmove.c:3876](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L3876)
- documentation: [docs/japro_docs.md:48](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L48)
