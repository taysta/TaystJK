---
title: "g_fixGroundStab"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixGroundStab`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

1=Groundstabs damage players on ground. 2=Groundstabs damage players on ground but with reduced damage.

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
| `1` | Groundstabs damage players on ground. | [docs/japro_docs.md:18](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L18) |
| `2` | Groundstabs damage players on ground but with reduced damage. | [docs/japro_docs.md:18](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L18) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`e41a31afa6bb`](https://github.com/taysta/TaystJK/commit/e41a31afa6bb228f032615656a75faa953e238db)
- Upstream registration evidence: [codemp/game/g_xcvar.h:177](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L177)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:198](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L198) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:8330](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8330)
- behavior: [codemp/game/g_cmds.c:8332](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8332)
- behavior: [codemp/game/w_saber.c:4298](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/w_saber.c#L4298)
- behavior: [codemp/game/w_saber.c:4332](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/w_saber.c#L4332)
- behavior: [codemp/game/w_saber.c:4344](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/w_saber.c#L4344)
- documentation: [docs/japro_docs.md:18](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L18)
