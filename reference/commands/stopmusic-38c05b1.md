---
title: "stopmusic"
layout: reference
nav_exclude: true
search_exclude: false
---

# `stopmusic`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Stops all music

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `stopmusic` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`6af6b30a2658`](https://github.com/taysta/TaystJK/commit/6af6b30a26589bf375b01c5d1e1a0490fb3c9074)
- Upstream registration evidence: [code/client/snd_dma.cpp:480](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/snd_dma.cpp#L480)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/snd_dma.cpp:494](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L494) (Cmd_AddCommand)
- handler: [codemp/client/snd_dma.cpp:3780](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L3780)
