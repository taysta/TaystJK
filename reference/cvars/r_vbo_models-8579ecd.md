---
title: "r_vbo_models"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_vbo_models`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Cache ghoul2 and md3 model surfaces

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/vk_init.cpp:512](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_init.cpp#L512) |
| `1` | Enabled. | [codemp/rd-vulkan/vk_init.cpp:512](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_init.cpp#L512) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`f88d0ccd696d`](https://github.com/JKSunny/EternalJK/commit/f88d0ccd696dd70a37e46638d7790a68196e773e) in <span class="label ref-origin ref-origin-vulkan">Vulkan</span> (content authored `2025-07-18`, integrated `2025-07-18`)
- TaystJK integration evidence: [`cc93ec8c4139`](https://github.com/taysta/TaystJK/commit/cc93ec8c413928bdfb94db470566c1ec44d88903)
- Origin pull request: [#251](https://github.com/taysta/TaystJK/pull/251)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:962](https://github.com/JKSunny/EternalJK/blame/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L962)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits vulkan.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2025-07-18` | — | `2025-07-18` | [`f88d0ccd696d`](https://github.com/JKSunny/EternalJK/commit/f88d0ccd696dd70a37e46638d7790a68196e773e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-07-18` | [2025-08-06](https://github.com/taysta/TaystJK/pull/251) | `2025-08-08` | [`cc93ec8c4139`](https://github.com/taysta/TaystJK/commit/cc93ec8c413928bdfb94db470566c1ec44d88903) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-07-18` | — | `2025-08-08` | [`cc93ec8c4139`](https://github.com/videoP/jaPRO/commit/cc93ec8c413928bdfb94db470566c1ec44d88903) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2026-01-09` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`f18b5091e2f3`](https://github.com/taysta/TaystJK/commit/f18b5091e2f3a466208128976b4344f839a6c1e4) · [PR #286](https://github.com/taysta/TaystJK/pull/286)<br>Merge pull request #286 from taysta/vk-update | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:963](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L963) (Cvar_Get); condition `defined(USE_VBO)`
- behavior: [codemp/rd-vulkan/vk_init.cpp:512](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_init.cpp#L512)
- behavior: [codemp/rd-vulkan/vk_info.cpp:472](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_info.cpp#L472)
