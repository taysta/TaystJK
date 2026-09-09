---
title: "con_scale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_scale`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Scale console font relative to it's original size.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1.0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `0.2` through `10.0f` (numeric; Cvar_CheckRange) — [codemp/client/cl_console.cpp:656](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L656)

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `engine-client` | `—` | `always` |
| `1.0` | `engine-client` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`20de49f4fe92`](https://github.com/mvdevs/jk2mv/commit/20de49f4fe92499c5efd12bcbb785c8ac7179f1d) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2016-05-26`, integrated `2016-06-12`)
- TaystJK integration evidence: [`135f109285cb`](https://github.com/taysta/TaystJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a)
- Upstream registration evidence: [src/client/cl_console.cpp:406](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_console.cpp#L406)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-05-26` | — | `2016-06-12` | [`20de49f4fe92`](https://github.com/mvdevs/jk2mv/commit/20de49f4fe92499c5efd12bcbb785c8ac7179f1d) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-02-05` | — | `2018-02-05` | [`135f109285cb`](https://github.com/eternalcodes/EternalJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-02-05` | — | `2018-02-05` | [`135f109285cb`](https://github.com/taysta/TaystJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-02-05` | — | `2018-02-05` | [`135f109285cb`](https://github.com/videoP/jaPRO/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-02-05` | — | `2018-02-05` | [`135f109285cb`](https://github.com/JKSunny/EternalJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-09` | — | `2024-02-08` | [`01697e61fe58`](https://github.com/JACoders/OpenJK/commit/01697e61fe586e31591dd236e1d4441c92f41a8a) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-09` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`135f109285cb`](https://github.com/eternalcodes/EternalJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a)<br>Added con_scale from JK2MV. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3a6ec05fdfff`](https://github.com/eternalcodes/EternalJK/commit/3a6ec05fdfff276f21492b7aacf9822383c20e4b)<br>fix padding for console prompt carrots | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f57cbc3056a9`](https://github.com/eternalcodes/EternalJK/commit/f57cbc3056a9b8aa7cfefc66a972afb433468348)<br>ops | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2018-12-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b75dba021689`](https://github.com/eternalcodes/EternalJK/commit/b75dba021689302751549b7b04ec791b65ee1ea1)<br>Show formatted build date in console instead of "Beta" | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:655](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L655) (Cvar_Get)
- registration: [codemp/client/cl_console.cpp:666](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L666) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:595](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L595)
- behavior: [codemp/client/cl_console.cpp:656](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L656)
- upstream-documentation: [CVARS.rst:153](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L153)
