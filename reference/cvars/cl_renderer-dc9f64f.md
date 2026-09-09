---
title: "cl_renderer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_renderer`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Which renderer library to use

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `DEFAULT_RENDER_LIBRARY` |
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-16`, integrated `2013-04-16`)
- Upstream registration evidence: [code/client/cl_main.cpp:1091](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_main.cpp#L1091)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/eternalcodes/EternalJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/SomaZ/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/taysta/TaystJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/videoP/jaPRO/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/jkanewmod/NewJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-16` | — | `2013-04-16` | [`714c868b42c6`](https://github.com/JKSunny/EternalJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5a749fad2760`](https://github.com/JACoders/OpenJK/commit/5a749fad2760671bc6b5ad41afae1ab6ba585434)<br>Modular renderer system for SP complete. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7c6d1d70a178`](https://github.com/JACoders/OpenJK/commit/7c6d1d70a17866d84cc1bd5a15b823959109b4f7)<br>Compiles under Final/Release now. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af2ba72c3838`](https://github.com/JACoders/OpenJK/commit/af2ba72c383847626e26a6bc3447acbbd571d189)<br>Added a #define for default renderer name, as per Xycaleth's request | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `high` |
| `2013-05-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8a0da9518a63`](https://github.com/JACoders/OpenJK/commit/8a0da9518a635e84b214da5b7c80cf32ceca8808)<br>Merge pull request #242 from xycaleth/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2013-07-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`0494d56559bb`](https://github.com/JACoders/OpenJK/commit/0494d56559bb0e31a7c986081da318aa8ec18547)<br>Moved default renderer name into a #define. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2023-09-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`239e59ac4807`](https://github.com/taysta/TaystJK/commit/239e59ac48079dfa845a5e865e4562be3b4be9ba)<br>Remove vm protection from cl_renderer cvar | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2023-10-14` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`aa48e28a7d4f`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) · [PR #26](https://github.com/taysta/TaystJK/pull/26)<br>Merge pull request #26 from taysta/rend2menu | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:2744](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2744) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2748](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2748)
- behavior: [codemp/client/cl_main.cpp:2746](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2746)
- behavior: [codemp/ui/ui_main.c:6241](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6241)
- behavior: [codemp/ui/ui_main.c:6369](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6369)
- behavior: [codemp/client/cl_main.cpp:2751](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2751)
