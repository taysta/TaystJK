---
title: "sv_autoRaceDemo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_autoRaceDemo`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Requires custom server executable with "svrecord" command.

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_trigger.c:1489](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_trigger.c#L1489) |
| `1` | Enabled. | [codemp/game/g_trigger.c:1489](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_trigger.c#L1489) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`080dc64a4b39`](https://github.com/taysta/TaystJK/commit/080dc64a4b395d42febca8dedda8f3836443fdc2)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits openjk.

## Evidence

- registration: [codemp/game/g_xcvar.h:335](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L335) (XCVAR_DEF)
- behavior: [codemp/game/g_trigger.c:1489](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_trigger.c#L1489)
- documentation: [docs/japro_docs.md:132](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L132)
