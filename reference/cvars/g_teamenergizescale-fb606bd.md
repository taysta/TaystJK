---
title: "g_teamEnergizeScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_teamEnergizeScale`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Scale forcepoints given from team energize.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`0f8f5dc6e782`](https://github.com/taysta/TaystJK/commit/0f8f5dc6e782186802947a83e180a764488bd8a4)
- Upstream registration evidence: [codemp/game/g_xcvar.h:194](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L194)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:215](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L215) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:8564](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8564)
- behavior: [codemp/game/g_cmds.c:8565](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8565)
- behavior: [codemp/game/w_force.c:1454](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/w_force.c#L1454)
- behavior: [codemp/game/w_force.c:1458](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/w_force.c#L1458)
- behavior: [codemp/game/w_force.c:1462](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/w_force.c#L1462)
- documentation: [docs/japro_docs.md:35](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L35)
