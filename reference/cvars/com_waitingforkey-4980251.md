---
title: "com_waitingForKey"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_waitingForKey`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_waitingForKey` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Input & controls |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sdl/sdl_input.cpp:203](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L203) |
| `1` | Enabled. | [shared/sdl/sdl_input.cpp:203](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L203) |

## Flags

- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`a1ee9793b45d`](https://github.com/taysta/TaystJK/commit/a1ee9793b45d409840c6b75b3da75fdebca685a2) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2025-04-26`, PR opened `2025-04-21`, integrated `2025-04-26`)
- Origin pull request: [#225](https://github.com/taysta/TaystJK/pull/225)
- Upstream registration evidence: [shared/sdl/sdl_input.cpp:201](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L201)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-26` | [2025-04-21](https://github.com/taysta/TaystJK/pull/225) | `2025-04-26` | [`a1ee9793b45d`](https://github.com/taysta/TaystJK/commit/a1ee9793b45d409840c6b75b3da75fdebca685a2) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-26` | — | `2025-04-26` | [`a1ee9793b45d`](https://github.com/videoP/jaPRO/commit/a1ee9793b45d409840c6b75b3da75fdebca685a2) | Shared integration commit |

## Evidence

- registration: [shared/sdl/sdl_input.cpp:201](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L201) (Cvar_Get)
- registration: [shared/sys/sys_main.cpp:181](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L181) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:203](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L203)
- behavior: [codemp/ui/ui_shared.c:1480](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L1480)
- behavior: [codemp/ui/ui_shared.c:4389](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L4389)
- behavior: [codemp/ui/ui_shared.c:4449](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L4449)
- behavior: [codemp/ui/ui_shared.c:5286](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L5286)
