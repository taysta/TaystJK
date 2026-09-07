---
title: "g_tweakForce"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_tweakForce`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Configured with /tweakForce command.

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
| `1048576` | Not really a forcetweak but no room in weapon tweaks! | [codemp/game/g_local.h:267](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L267) |
| `128` | Enables the `FT_FASTGRIP` code path. | [codemp/game/g_local.h:254](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L254) |
| `16` | Enables the `FT_FORCECOMBO` code path. | [codemp/game/g_local.h:251](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L251) |
| `262144` | Enables the `FT_NORAGEFIRERATE` code path. | [codemp/game/g_local.h:265](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L265) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`5a9bd98fd669`](https://github.com/taysta/TaystJK/commit/5a9bd98fd669dbf16324a2047936a52f49f3ff46)
- Upstream registration evidence: [codemp/game/g_xcvar.h:188](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L188)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:209](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L209) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:8079](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8079)
- behavior: [codemp/game/bg_pmove.c:11228](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L11228)
- behavior: [codemp/game/bg_pmove.c:12017](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L12017)
- behavior: [codemp/game/bg_pmove.c:12029](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L12029)
- behavior: [codemp/game/bg_pmove.c:14117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L14117)
- documentation: [docs/japro_docs.md:29](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L29)
