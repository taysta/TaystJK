---
title: "net_dropsim"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_dropsim`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `net_dropsim` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_TEMP` — temporary and not archived

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`7b1256ba0a46`](https://github.com/taysta/TaystJK/commit/7b1256ba0a46789986383567f76fa9717b39cfb4)
- Upstream registration evidence: [codemp/qcommon/net_ip.cpp:894](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/net_ip.cpp#L894)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:910](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L910) (Cvar_Get)
- behavior: [codemp/qcommon/net_ip.cpp:1035](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L1035)
- behavior: [codemp/qcommon/net_ip.cpp:1038](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L1038)
