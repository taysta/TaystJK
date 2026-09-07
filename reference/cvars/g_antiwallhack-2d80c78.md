---
title: "g_antiWallhack"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_antiWallhack`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Experimental anti wallhack code. Use the client plugin so it can tell the server where your camera position is, and if you use 3rd person.

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

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`63fdebe679da`](https://github.com/taysta/TaystJK/commit/63fdebe679da135f9254415a9aa39d12952a8f5b)
- Upstream registration evidence: [codemp/game/g_xcvar.h:271](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L271)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:292](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L292) (XCVAR_DEF); condition `_ANTIWALLHACK`
- behavior: [codemp/game/g_active.c:2415](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L2415)
- behavior: [codemp/game/g_active.c:2532](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L2532)
- behavior: [codemp/game/g_active.c:2416](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L2416)
- documentation: [docs/japro_docs.md:98](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L98)
