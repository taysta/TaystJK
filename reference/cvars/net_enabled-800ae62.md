---
title: "net_enabled"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_enabled`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `net_enabled` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0x01` | Enables the `NET_ENABLEV4` code path. | [codemp/qcommon/qcommon.h:116](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/qcommon.h#L116) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`cd5d3753f0a7`](https://github.com/taysta/TaystJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c)
- Upstream registration evidence: [codemp/qcommon/net_ip.cpp:858](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/net_ip.cpp#L858)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:874](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L874) (Cvar_Get)
- behavior: [codemp/qcommon/net_ip.cpp:844](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L844)
- behavior: [codemp/qcommon/net_ip.cpp:928](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L928)
- behavior: [codemp/qcommon/net_ip.cpp:971](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L971)
- behavior: [codemp/qcommon/net_ip.cpp:875](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L875)
- behavior: [codemp/qcommon/net_ip.cpp:876](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L876)
