---
title: "com_priority"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_priority`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Duno, -1 = do nothing, 1 = low priority, 2 = normal priority, 3 = high priority? i guess??

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `-1` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `-1` | Do nothing. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |
| `1` | Low priority. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |
| `2` | Normal priority. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |
| `3` | High priority? i guess??. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_NORESTART` — preserved across cvar restart

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`20755a5d4be0`](https://github.com/taysta/TaystJK/commit/20755a5d4be00432747aa8b7c1b6cc746296995b)
- Upstream registration evidence: [codemp/qcommon/common.cpp:1278](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/common.cpp#L1278)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) (Cvar_Get); condition `defined(_WIN32)`
- behavior: [shared/sys/sys_win32.cpp:256](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L256)
- behavior: [shared/sys/sys_win32.cpp:261](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L261)
- behavior: [shared/sys/sys_win32.cpp:264](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L264)
- behavior: [shared/sys/sys_win32.cpp:267](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L267)
- behavior: [shared/sys/sys_win32.cpp:270](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L270)
