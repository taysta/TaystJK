---
title: "g_fixTimerOOB"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixTimerOOB`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixTimerOOB` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
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

- Commit evidence: [`2f22cd92e0a9`](https://github.com/taysta/TaystJK/commit/2f22cd92e0a90713ee14c0385e9e1fc741ab00cc)
- Upstream registration evidence: [codemp/game/g_xcvar.h:332](https://github.com/videoP/jaPRO/blob/a48764f18226001c93680d7da6815b7d05c3784a/codemp/game/g_xcvar.h#L332)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/game/g_xcvar.h:353](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L353) (XCVAR_DEF)
- behavior: [codemp/game/g_trigger.c:1467](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_trigger.c#L1467)
- behavior: [codemp/game/g_trigger.c:1712](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_trigger.c#L1712)
