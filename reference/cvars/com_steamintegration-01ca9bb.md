---
title: "com_steamIntegration"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_steamIntegration`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Enables automatic Steam API integration (requires a steam_api64.dll to be in GameData)

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `engine-shared` | `—` | `!defined(DEDICATED) && defined(_WIN64)` |
| `1` | `engine-shared` | `—` | `!defined(DEDICATED) && else(defined(_WIN64))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`df21cc35f5ef`](https://github.com/taysta/TaystJK/commit/df21cc35f5ef9cb78a9003abf7c5ab1acbe31dfe)
- Upstream registration evidence: [codemp/qcommon/common.cpp:1237](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/common.cpp#L1237)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/common.cpp:1452](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1452) (Cvar_Get); condition `!defined(DEDICATED) && defined(_WIN64)`
- registration: [codemp/qcommon/common.cpp:1454](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1454) (Cvar_Get); condition `!defined(DEDICATED) && else(defined(_WIN64))`
- behavior: [shared/sys/sys_win32.cpp:740](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L740)
- behavior: [shared/sys/sys_win32.cpp:742](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L742)
