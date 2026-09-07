---
title: "g_tweakSaber"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_tweakSaber`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Configured with /tweakSaber command.

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
| `16` | CLIENT - also remove backwards run slowdown like jk2 | [codemp/game/g_local.h:277](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L277) |
| `128` | Enables the `ST_EASYBACKSLASH` code path. | [codemp/game/g_local.h:280](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L280) |
| `64` | Enables the `ST_FIXED_SABERSWITCH` code path. | [codemp/game/g_local.h:279](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L279) |
| `256` | Enables the `ST_JK2RDFA` code path. | [codemp/game/g_local.h:281](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L281) |
| `32` | Enables the `ST_NO_REDCHAIN` code path. | [codemp/game/g_local.h:278](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L278) |
| `2048` | Enables the `ST_SPINBACKSLASH` code path. | [codemp/game/g_local.h:284](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L284) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`5a9bd98fd669`](https://github.com/taysta/TaystJK/commit/5a9bd98fd669dbf16324a2047936a52f49f3ff46)
- Upstream registration evidence: [codemp/game/g_xcvar.h:172](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L172)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:193](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L193) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:8387](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8387)
- behavior: [codemp/game/bg_panimate.c:2701](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_panimate.c#L2701)
- behavior: [codemp/game/bg_pmove.c:4465](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L4465)
- behavior: [codemp/game/bg_pmove.c:6227](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L6227)
- behavior: [codemp/game/bg_pmove.c:9055](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L9055)
- documentation: [docs/japro_docs.md:13](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L13)
