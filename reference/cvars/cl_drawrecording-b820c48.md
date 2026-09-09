---
title: "cl_drawRecording"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_drawRecording`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_drawRecording` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/client/cl_scrn.cpp:404](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L404) |
| `2` | Selects the code path tested for value 2. | [codemp/client/cl_scrn.cpp:406](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L406) |
| `3` | Selects the code path tested for value 3. | [codemp/client/cl_scrn.cpp:408](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L408) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`dac8819e51c0`](https://github.com/JACoders/OpenJK/commit/dac8819e51c00b048db00f88fef5d8b3555623fa) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2016-01-22`, integrated `2017-07-30`)
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2819](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2819)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: openjk retains origin because content authorship and PR submission predate the project that merged the work first. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-01-18` | — | `2016-01-18` | [`63ca54299bfe`](https://github.com/mvdevs/jk2mv/commit/63ca54299bfe036a1e9681bbb5ce112009b38526) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2016-01-22` | — | `2017-07-30` | [`dac8819e51c0`](https://github.com/JACoders/OpenJK/commit/dac8819e51c00b048db00f88fef5d8b3555623fa) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2016-01-22` | — | `2017-07-30` | [`dac8819e51c0`](https://github.com/SomaZ/OpenJK/commit/dac8819e51c00b048db00f88fef5d8b3555623fa) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-01-22` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/eternalcodes/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-01-22` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-01-22` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/videoP/jaPRO/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-01-22` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/JKSunny/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-04-22` | — | `2016-04-22` | [`e477e3d3e1e5`](https://github.com/jkanewmod/NewJK/commit/e477e3d3e1e54d27129011d663ff2feaac5d6ed9) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64b989e1984b`](https://github.com/eternalcodes/EternalJK/commit/64b989e1984bc8a20a348a8e0a4bd4d46801f523)<br>Add batch script to create VS2017 projects. Fixed minor build error with cl_drawRecording. | Changed an exact bound cvar-variable reference. `codemp/client/client.h` | `medium` |
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9563d0aead75`](https://github.com/eternalcodes/EternalJK/commit/9563d0aead75f983215abf2012824ecafa12a8f3)<br>More options for drawing demo recording text (0-5) | Changed an exact bound cvar-variable reference. `codemp/client/cl_scrn.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)<br>chat styles | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3395](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3395) (Cvar_Get)
- behavior: [codemp/client/cl_scrn.cpp:399](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L399)
- behavior: [codemp/client/cl_scrn.cpp:404](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L404)
- behavior: [codemp/client/cl_scrn.cpp:406](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L406)
- behavior: [codemp/client/cl_scrn.cpp:408](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L408)
- behavior: [codemp/client/cl_scrn.cpp:410](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_scrn.cpp#L410)
