---
title: "cl_discordRichPresenceSharePassword"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_discordRichPresenceSharePassword`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

If set, sends password to Discord friends who request to join your game

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`53b43cd32500`](https://github.com/taysta/TaystJK/commit/53b43cd32500dfc4544b7213f14e69064037acfb)
- Upstream registration evidence: [codemp/client/cl_discordrpc.cpp:382](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_discordrpc.cpp#L382)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_discordrpc.cpp:448](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L448) (Cvar_Get); condition `defined DISCORD && !(_DEBUG)`
- behavior: [codemp/client/cl_discordrpc.cpp:193](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L193)
