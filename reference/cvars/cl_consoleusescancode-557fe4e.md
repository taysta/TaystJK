---
title: "cl_consoleUseScanCode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_consoleUseScanCode`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Use native console key detection

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
| `0` | Disabled. | [shared/sdl/sdl_input.cpp:401](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L401) |
| `1` | Enabled. | [shared/sdl/sdl_input.cpp:401](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L401) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`0a65fd6a7237`](https://github.com/JACoders/OpenJK/commit/0a65fd6a7237f66369e2b3a339b633e0e5f42be3) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2016-09-11`, integrated `2016-09-11`)
- TaystJK integration evidence: [`13791f7ad4fe`](https://github.com/taysta/TaystJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f)
- Upstream registration evidence: [code/client/cl_main.cpp:1283](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_main.cpp#L1283)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2016-09-11` | — | `2016-09-11` | [`0a65fd6a7237`](https://github.com/JACoders/OpenJK/commit/0a65fd6a7237f66369e2b3a339b633e0e5f42be3) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2016-09-11` | — | `2016-09-11` | [`0a65fd6a7237`](https://github.com/SomaZ/OpenJK/commit/0a65fd6a7237f66369e2b3a339b633e0e5f42be3) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-09-11` | — | `2016-09-30` | [`13791f7ad4fe`](https://github.com/eternalcodes/EternalJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-09-11` | — | `2016-09-30` | [`13791f7ad4fe`](https://github.com/taysta/TaystJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-09-11` | — | `2016-09-30` | [`13791f7ad4fe`](https://github.com/videoP/jaPRO/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-09-11` | — | `2016-09-30` | [`13791f7ad4fe`](https://github.com/JKSunny/EternalJK/commit/13791f7ad4fee5f2c6fa10b7aaed10212d26ac0f) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-09-11` | — | `2016-11-08` | [`3d1e756f138e`](https://github.com/jkanewmod/NewJK/commit/3d1e756f138e65123d762d5adbbb142b69b02286) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-19` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) · [PR #140](https://github.com/taysta/TaystJK/pull/140)<br>Openjk update (#140) | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3403](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3403) (Cvar_Get)
- behavior: [shared/sdl/sdl_input.cpp:401](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L401)
- behavior: [shared/sdl/sdl_input.cpp:888](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L888)
