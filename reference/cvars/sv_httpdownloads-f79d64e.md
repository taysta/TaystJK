---
title: "sv_httpDownloads"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_httpDownloads`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Enables fast HTTP downloads for referenced PK3 files. When enabled, the server advertises either its built-in HTTP endpoint or the external URL configured by sv_httpServerPort to supporting clients.

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
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable HTTP auto-download advertising and stop the built-in HTTP server. | [codemp/server/sv_init.cpp:763](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L763) |
| `1` | Advertise HTTP downloads and start or redirect the HTTP endpoint. | [codemp/server/sv_init.cpp:763](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L763) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Commit evidence: [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d)
- Pull request: [#169](https://github.com/taysta/TaystJK/pull/169)
- Matching squash bullet: `[HTTP-AutoDL] Libmongoose 7 port from jk2mv`
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

## Evidence

- registration: [codemp/server/sv_init.cpp:760](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L760) (Cvar_Get)
- behavior: [codemp/server/sv_init.cpp:763](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L763)
- behavior: [codemp/server/sv_main.cpp:579](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L579)
- behavior: [codemp/server/sv_init.cpp:755](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L755)
- behavior: [codemp/client/cl_main.cpp:1707](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1707)
- behavior: [codemp/client/cl_main.cpp:1714](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1714)
