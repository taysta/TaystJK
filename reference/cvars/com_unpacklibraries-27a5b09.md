---
title: "com_unpackLibraries"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_unpackLibraries`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_unpackLibraries` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
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
| `0` | Disabled. | [shared/sys/sys_main.cpp:493](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L493) |
| `1` | Enabled. | [shared/sys/sys_main.cpp:493](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L493) |

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0)
- Origin pull request: [#52](https://github.com/taysta/TaystJK/pull/52)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: openjk retains origin because content authorship and PR submission predate the project that merged the work first. An identifier-adjacent source/commit/PR line explicitly credits eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-06` | [2023-11-07](https://github.com/JACoders/OpenJK/pull/1185) | `2024-04-07` | [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-06` | [2023-11-27](https://github.com/taysta/TaystJK/pull/52) | `2023-11-28` | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-06` | — | `2023-11-28` | [`596ae40cc9aa`](https://github.com/videoP/jaPRO/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-06` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

## Evidence

- registration: [shared/sys/sys_main.cpp:179](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L179) (Cvar_Get)
- behavior: [shared/sys/sys_main.cpp:493](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L493)
- behavior: [shared/sys/sys_main.cpp:575](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L575)
