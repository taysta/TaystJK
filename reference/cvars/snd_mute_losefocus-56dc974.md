---
title: "snd_mute_losefocus"
layout: reference
nav_exclude: true
search_exclude: false
---

# `snd_mute_losefocus`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Mute sound when game window is unfocused/minimized

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L1581) |
| `1` | Enabled. | [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L1581) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`ba0a05b38b4a`](https://github.com/taysta/TaystJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72)
- Upstream registration evidence: [codemp/client/snd_dma.cpp:480](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/snd_dma.cpp#L480)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/snd_dma.cpp:480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L480) (Cvar_Get)
- behavior: [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L1581)
- behavior: [shared/sdl/sdl_input.cpp:960](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L960)
- behavior: [shared/sdl/sdl_input.cpp:973](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L973)
