---
title: "r_ext_multisample_default_fb"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_ext_multisample_default_fb`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_ext_multisample_default_fb` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sdl/sdl_window.cpp:475](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L475) |
| `1` | Enabled. | [shared/sdl/sdl_window.cpp:475](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L475) |

## Flags

- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`6e3d3eaa047c`](https://github.com/SomaZ/OpenJK/commit/6e3d3eaa047c277835344b7cdba8429e6c070cb5) in <span class="label ref-origin ref-origin-rend2">rend2</span> (content authored `2025-02-10`, integrated `2025-02-10`)
- TaystJK integration evidence: [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad)
- Origin pull request: [#217](https://github.com/taysta/TaystJK/pull/217)
- Upstream registration evidence: [shared/sdl/sdl_window.cpp:759](https://github.com/SomaZ/OpenJK/blame/788c19e97f02c0b68db29d63060305b6ad1580e5/shared/sdl/sdl_window.cpp#L759)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2025-02-10` | — | `2025-02-10` | [`6e3d3eaa047c`](https://github.com/SomaZ/OpenJK/commit/6e3d3eaa047c277835344b7cdba8429e6c070cb5) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-15` | [2025-04-07](https://github.com/taysta/TaystJK/pull/217) | `2025-04-15` | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-15` | — | `2025-04-15` | [`c98ecf977bd3`](https://github.com/videoP/jaPRO/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

## Evidence

- registration: [shared/sdl/sdl_window.cpp:817](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L817) (Cvar_Get)
- behavior: [shared/sdl/sdl_window.cpp:475](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L475)
- behavior: [codemp/rd-rend2/tr_init.cpp:1498](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1498)
- behavior: [codemp/rd-vanilla/tr_init.cpp:1640](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1640)
