---
title: "r_DynamicGlowAllStages"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_DynamicGlowAllStages`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

In Vanilla certain glow stages are skipped, render those anyway

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/tr_shader.cpp:3510](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_shader.cpp#L3510) |
| `1` | Enabled. | [codemp/rd-vulkan/tr_shader.cpp:3510](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_shader.cpp#L3510) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`3e62987235a8`](https://github.com/JKSunny/EternalJK/commit/3e62987235a820df146da90520b73b6fb3844bfe) in <span class="label ref-origin ref-origin-vulkan">Vulkan</span> (content authored `2023-09-03`, integrated `2023-09-03`)
- TaystJK integration evidence: [`a435f91de078`](https://github.com/taysta/TaystJK/commit/a435f91de078325de74408f44053240448efe1b4)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:794](https://github.com/JKSunny/EternalJK/blame/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L794)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2023-09-03` | — | `2023-09-03` | [`3e62987235a8`](https://github.com/JKSunny/EternalJK/commit/3e62987235a820df146da90520b73b6fb3844bfe) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-09-03` | — | `2023-09-24` | [`a435f91de078`](https://github.com/taysta/TaystJK/commit/a435f91de078325de74408f44053240448efe1b4) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-09-03` | — | `2023-09-24` | [`a435f91de078`](https://github.com/videoP/jaPRO/commit/a435f91de078325de74408f44053240448efe1b4) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:795](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L795) (Cvar_Get)
- behavior: [codemp/rd-vulkan/tr_shader.cpp:3510](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_shader.cpp#L3510)
