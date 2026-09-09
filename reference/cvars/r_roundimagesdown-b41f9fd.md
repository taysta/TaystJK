---
title: "r_roundImagesDown"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_roundImagesDown`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_roundImagesDown` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/vk_image.cpp:612](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_image.cpp#L612) |
| `1` | Enabled. | [codemp/rd-vulkan/vk_image.cpp:612](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_image.cpp#L612) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `renderer` | `rd-rend2` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) in <span class="label ref-origin ref-origin-rend2">rend2</span> (content authored `2013-10-08`, integrated `2023-10-03`)
- TaystJK integration evidence: [`c4a9c87ef0e3`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1488](https://github.com/SomaZ/OpenJK/blame/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1488)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`
- Notes: rend2 retains origin because content authorship and PR submission predate the project that merged the work first. The TaystJK integration evidence credits vulkan as an immediate port source, but rend2 has an earlier dated introduction and remains the ultimate origin. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-10-08` | — | `2023-10-03` | [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-10-08` | — | `2023-10-03` | [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/videoP/jaPRO/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1523](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1523) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:958](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L958) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_image.cpp:612](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_image.cpp#L612)
- behavior: [codemp/rd-vulkan/vk_image.cpp:615](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/vk_image.cpp#L615)
- behavior: [shared/rd-rend2/tr_image.cpp:1592](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_image.cpp#L1592)
- behavior: [shared/rd-rend2/tr_image.cpp:1594](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_image.cpp#L1594)
