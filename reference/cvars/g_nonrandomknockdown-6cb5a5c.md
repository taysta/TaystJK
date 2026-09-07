---
title: "g_nonRandomKnockdown"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_nonRandomKnockdown`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

1=Nonrandom knockdowns based on forcepoints. 2=Pseudorandom with less variance. 3=Nonrandom based on viewangle of target. 4=Random based on viewangle of target.

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
| `1` | Nonrandom knockdowns based on forcepoints. | [docs/japro_docs.md:49](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L49) |
| `2` | Pseudorandom with less variance. | [docs/japro_docs.md:49](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L49) |
| `3` | Nonrandom based on viewangle of target. | [docs/japro_docs.md:49](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L49) |
| `4` | Random based on viewangle of target. | [docs/japro_docs.md:49](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L49) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`9e71abca2edb`](https://github.com/taysta/TaystJK/commit/9e71abca2edbffca1dff9dc2a1d1ba659b914566)
- Upstream registration evidence: [codemp/game/g_xcvar.h:209](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L209)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:230](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L230) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:5645](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L5645)
- behavior: [codemp/game/g_active.c:5652](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L5652)
- behavior: [codemp/game/g_active.c:5659](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L5659)
- behavior: [codemp/game/g_active.c:5682](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L5682)
- behavior: [codemp/game/g_active.c:5703](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L5703)
- documentation: [docs/japro_docs.md:49](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L49)
