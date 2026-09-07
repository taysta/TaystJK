---
title: "sv_httpServerPort"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_httpServerPort`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Configures the HTTP auto-download endpoint. A numeric value selects the built-in web server's port; a value beginning with http:// advertises that external base URL instead.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `mixed` |
| Confidence | `high` |
| Default | `0` |
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Commit evidence: [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d)
- Pull request: [#169](https://github.com/taysta/TaystJK/pull/169)
- Matching squash bullet: `[HTTP-AutoDL] Libmongoose 7 port from jk2mv`
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

## Evidence

- registration: [codemp/server/sv_init.cpp:761](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L761) (Cvar_Get)
- behavior: [codemp/server/sv_init.cpp:764](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L764)
- behavior: [codemp/server/sv_main.cpp:580](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L580)
- behavior: [codemp/server/sv_init.cpp:765](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L765)
- behavior: [codemp/server/sv_init.cpp:767](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L767)
- behavior: [codemp/server/sv_main.cpp:581](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L581)
