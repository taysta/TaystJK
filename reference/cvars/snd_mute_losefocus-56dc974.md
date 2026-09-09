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
| `0` | Disabled. | [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L1581) |
| `1` | Enabled. | [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L1581) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`ba0a05b38b4a`](https://github.com/eternalcodes/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-03-21`, integrated `2019-03-21`)
- Upstream registration evidence: [codemp/client/snd_dma.cpp:480](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/snd_dma.cpp#L480)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-21` | — | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/eternalcodes/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-21` | — | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/taysta/TaystJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-21` | — | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/videoP/jaPRO/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-21` | — | `2019-03-21` | [`ba0a05b38b4a`](https://github.com/JKSunny/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72) | Shared integration commit |

## Evidence

- registration: [codemp/client/snd_dma.cpp:480](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L480) (Cvar_Get)
- behavior: [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L1581)
- behavior: [shared/sdl/sdl_input.cpp:960](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L960)
- behavior: [shared/sdl/sdl_input.cpp:973](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L973)
