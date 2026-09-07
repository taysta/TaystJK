---
title: "com_maxfpsUnfocused"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_maxfpsUnfocused`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_maxfpsUnfocused` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/qcommon/common.cpp:1757](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1757) |
| `1` | Enabled. | [codemp/qcommon/common.cpp:1757](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1757) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`7b1256ba0a46`](https://github.com/taysta/TaystJK/commit/7b1256ba0a46789986383567f76fa9717b39cfb4)
- Upstream registration evidence: [shared/sys/sys_main.cpp:166](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/shared/sys/sys_main.cpp#L166)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [shared/sys/sys_main.cpp:176](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_main.cpp#L176) (Cvar_Get)
- behavior: [codemp/qcommon/common.cpp:1757](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1757)
- behavior: [codemp/qcommon/common.cpp:1758](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1758)
