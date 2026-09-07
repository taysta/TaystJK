---
title: "sv_autoWhitelist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_autoWhitelist`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Save player IPs to allow them using server during DOS attack

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_client.cpp:586](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L586) |
| `1` | Enabled. | [codemp/server/sv_client.cpp:586](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L586) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`ce04b7b38caa`](https://github.com/taysta/TaystJK/commit/ce04b7b38caab99a4ab20099c0d76ed0708efdfb)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1015](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1015)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/server/sv_init.cpp:1053](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1053) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:586](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_client.cpp#L586)
