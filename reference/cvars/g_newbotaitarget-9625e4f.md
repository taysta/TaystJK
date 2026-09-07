---
title: "g_newBotAITarget"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_newBotAITarget`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

-2=Target closest excluding otherbots. -1=target closest. 0-31=target clientnum.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `-1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `-2` | Target closest excluding otherbots. | [docs/japro_docs.md:142](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L142) |
| `-1` | Target closest. 0. | [docs/japro_docs.md:142](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L142) |
| `31` | Target clientnum. | [docs/japro_docs.md:142](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L142) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`fde2770ff418`](https://github.com/taysta/TaystJK/commit/fde2770ff41872d4aa1bc70d427bb473f7a80f2a)
- Upstream registration evidence: [codemp/game/g_xcvar.h:320](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L320)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:341](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L341) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:1801](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L1801)
- behavior: [codemp/game/ai_main.c:8935](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8935)
- behavior: [codemp/game/ai_main.c:8973](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8973)
- behavior: [codemp/game/ai_main.c:8939](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8939)
- documentation: [docs/japro_docs.md:142](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L142)
