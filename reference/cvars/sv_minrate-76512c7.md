---
title: "sv_minRate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_minRate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Min bandwidth rate allowed on server. Use 0 for unlimited.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
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
| `0` | Disabled. | [codemp/server/sv_snapshot.cpp:773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L773) |
| `1` | Enabled. | [codemp/server/sv_snapshot.cpp:773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L773) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`6aba69055e45`](https://github.com/taysta/TaystJK/commit/6aba69055e4591b7ac96eee8b40322cbf4a681b4)
- Upstream registration evidence: [codemp/server/sv_init.cpp:961](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L961)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits openjk.

## Evidence

- registration: [codemp/server/sv_init.cpp:992](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L992) (Cvar_Get)
- behavior: [codemp/server/sv_snapshot.cpp:773](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L773)
- behavior: [codemp/server/sv_snapshot.cpp:774](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L774)
- behavior: [codemp/server/sv_snapshot.cpp:777](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L777)
- behavior: [codemp/server/sv_client.cpp:1218](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L1218)
- behavior: [codemp/server/sv_main.cpp:1099](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L1099)
