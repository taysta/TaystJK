---
title: "cl_colorStringCount"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_colorStringCount`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_colorStringCount` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_main.cpp:3117](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3117) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:3117](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3117) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`9888b3f266ed`](https://github.com/eternalcodes/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-03-21`, integrated `2016-03-21`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3346](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3346)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-21` | — | `2016-03-21` | [`9888b3f266ed`](https://github.com/eternalcodes/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-21` | — | `2016-03-21` | [`9888b3f266ed`](https://github.com/taysta/TaystJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-21` | — | `2016-03-21` | [`9888b3f266ed`](https://github.com/videoP/jaPRO/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-21` | — | `2016-03-21` | [`9888b3f266ed`](https://github.com/JKSunny/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6a99a7571a97`](https://github.com/eternalcodes/EternalJK/commit/6a99a7571a975cfc3a6697c0c41b839c65780198)<br>Improved /colorName + bugfixes /colorName works the same way as /colorString examples: /colorName -1 will remove all color from your name /colorName 10 will use all colors on your name /colorName 1 2 5 6 will color your name red, green, cyan, and magenta | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)<br>Implement Blackwolf's Discord Integration | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)<br>chat styles | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3445](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3445) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:3117](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3117)
- behavior: [codemp/client/cl_main.cpp:3161](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3161)
- behavior: [codemp/client/cl_main.cpp:3190](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3190)
- behavior: [codemp/client/cl_main.cpp:3194](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3194)
- behavior: [codemp/client/cl_main.cpp:3203](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3203)
