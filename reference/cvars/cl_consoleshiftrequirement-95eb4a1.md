---
title: "cl_consoleShiftRequirement"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_consoleShiftRequirement`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Require shift key to be pressed for native console key detection

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
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
| `0` | Disabled. | [shared/sdl/sdl_input.cpp:269](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L269) |
| `1` | Enabled. | [shared/sdl/sdl_input.cpp:269](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L269) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- TaystJK integration evidence: [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207)
- Origin pull request: [#140](https://github.com/taysta/TaystJK/pull/140)
- Matching squash bullet: `[Shared] Replace CARET shift check when using cl_consoleUseScanCode with a check for cl_consoleShiftRequirement.`
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-03` | — | `2024-02-08` | [`01697e61fe58`](https://github.com/JACoders/OpenJK/commit/01697e61fe586e31591dd236e1d4441c92f41a8a) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-03` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-19` | [2024-02-09](https://github.com/taysta/TaystJK/pull/140) | `2024-02-19` | [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-19` | — | `2024-02-19` | [`b6f5ff52cbac`](https://github.com/videoP/jaPRO/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3404](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3404) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:269](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L269)
