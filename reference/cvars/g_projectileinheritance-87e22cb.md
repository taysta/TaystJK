---
title: "g_projectileInheritance"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_projectileInheritance`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Scale of forward player momentum gained by projectiles.

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
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`e41a31afa6bb`](https://github.com/taysta/TaystJK/commit/e41a31afa6bb228f032615656a75faa953e238db)
- Upstream registration evidence: [codemp/game/g_xcvar.h:203](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L203)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:224](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L224) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:8383](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8383)
- behavior: [codemp/game/ai_main.c:4715](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L4715)
- behavior: [codemp/game/g_cmds.c:8385](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8385)
- behavior: [codemp/game/ai_main.c:4718](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L4718)
- behavior: [codemp/game/g_missile.c:413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_missile.c#L413)
- documentation: [docs/japro_docs.md:43](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L43)
