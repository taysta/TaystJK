---
title: "g_validateCosmetics"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_validateCosmetics`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_validateCosmetics` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_client.c:2574](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2574) |
| `1` | Enabled. | [codemp/game/g_client.c:2574](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2574) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`ae722af274c8`](https://github.com/taysta/TaystJK/commit/ae722af274c85a80aea9b1fc67f1b540d107e66d)
- Upstream registration evidence: [codemp/game/g_xcvar.h:305](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L305)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/game/g_xcvar.h:326](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L326) (XCVAR_DEF)
- behavior: [codemp/game/g_client.c:2574](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2574)
- behavior: [codemp/game/g_client.c:3236](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L3236)
- behavior: [codemp/game/g_cvar.c:593](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cvar.c#L593)
- behavior: [codemp/game/g_client.c:2238](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2238)
- behavior: [codemp/game/g_client.c:2575](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2575)
