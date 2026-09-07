---
title: "g_hookStrength"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_hookStrength`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Speed that grapple pulls you at

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `800` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`7c2f3f9f235c`](https://github.com/taysta/TaystJK/commit/7c2f3f9f235c27a6f47bfcf279b4ec8d60916712)
- Upstream registration evidence: [codemp/game/g_xcvar.h:224](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L224)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:245](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L245) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:5674](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L5674)
- behavior: [codemp/game/bg_pmove.c:5724](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L5724)
- behavior: [codemp/cgame/cg_servercmds.c:264](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_servercmds.c#L264)
- documentation: [docs/japro_docs.md:60](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L60)
