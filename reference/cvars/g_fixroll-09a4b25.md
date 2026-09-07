---
title: "g_fixRoll"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixRoll`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

1=JA+ style base roll. //2=Chainable roll. //3=JK2 style roll.

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
| `1` | JA+ style base roll. //. | [docs/japro_docs.md:50](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L50) |
| `2` | Chainable roll. //. | [docs/japro_docs.md:50](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L50) |
| `3` | JK2 style roll. | [docs/japro_docs.md:50](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L50) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`31381094ec52`](https://github.com/taysta/TaystJK/commit/31381094ec52112b6f9b73c109eb6c7aa9148c4e)
- Upstream registration evidence: [codemp/game/g_xcvar.h:210](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L210)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:231](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L231) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:8301](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L8301)
- behavior: [codemp/game/bg_pmove.c:8305](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L8305)
- behavior: [codemp/game/bg_pmove.c:11829](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L11829)
- behavior: [codemp/game/bg_pmove.c:12127](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L12127)
- behavior: [codemp/game/bg_pmove.c:12174](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L12174)
- documentation: [docs/japro_docs.md:50](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L50)
