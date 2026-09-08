---
title: "snd_mute_losefocus"
layout: reference
nav_exclude: true
search_exclude: false
---

# `snd_mute_losefocus`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Mute sound when game window is unfocused/minimized

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
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

- Ultimate-origin introduction: [`ba0a05b38b4a`](https://github.com/eternalcodes/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) on `2019-03-21` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/snd_dma.cpp:480](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/snd_dma.cpp#L480)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/eternalcodes/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/taysta/TaystJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/videoP/jaPRO/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/JKSunny/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Shared earliest lineage |

## Evidence

- registration: [codemp/client/snd_dma.cpp:480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L480) (Cvar_Get)
- behavior: [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L1581)
- behavior: [shared/sdl/sdl_input.cpp:960](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L960)
- behavior: [shared/sdl/sdl_input.cpp:973](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_input.cpp#L973)
