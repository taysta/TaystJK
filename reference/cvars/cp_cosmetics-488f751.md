---
title: "cp_cosmetics"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cp_cosmetics`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cp_cosmetics` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_USERINFO` — sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`7778371e9614`](https://github.com/taysta/TaystJK/commit/7778371e96142ef5afaea5c030ea863c9462d2aa)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:178](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L178)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:207](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L207) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_consolecmds.c:1639](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1639)
- behavior: [codemp/cgame/cg_consolecmds.c:1720](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1720)
- behavior: [codemp/cgame/cg_consolecmds.c:1731](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1731)
- behavior: [codemp/cgame/cg_consolecmds.c:1741](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1741)
- behavior: [codemp/cgame/cg_consolecmds.c:1746](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1746)
