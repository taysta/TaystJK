---
title: "cl_drawRecording"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_drawRecording`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Selects one of the modes documented by JK2MV for `cl_drawRecording`.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | don't draw any demo recording indicator. | [CVARS.rst:135](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L135) |
| `1` | draw filename and demo size near the top of the screen. | [CVARS.rst:136](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L136) |
| `2` | draw red dot in the bottom left corner. | [CVARS.rst:137](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L137) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`63ca54299bfe`](https://github.com/mvdevs/jk2mv/commit/63ca54299bfe036a1e9681bbb5ce112009b38526) on `2016-01-18` in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [src/client/cl_main.cpp:2867](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_main.cpp#L2867)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`
- Notes: The TaystJK integration evidence credits openjk as an immediate port source, but jk2mv has an earlier dated introduction and remains the ultimate origin. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-01-18` | [`63ca54299bfe`](https://github.com/mvdevs/jk2mv/commit/63ca54299bfe036a1e9681bbb5ce112009b38526) | Ultimate origin |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-04-22` | [`e477e3d3e1e5`](https://github.com/jkanewmod/NewJK/commit/e477e3d3e1e54d27129011d663ff2feaac5d6ed9) | Later project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2017-07-30` | [`dac8819e51c0`](https://github.com/JACoders/OpenJK/commit/dac8819e51c00b048db00f88fef5d8b3555623fa) | Later project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2017-07-30` | [`dac8819e51c0`](https://github.com/SomaZ/OpenJK/commit/dac8819e51c00b048db00f88fef5d8b3555623fa) | Later project appearance |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/eternalcodes/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/videoP/jaPRO/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/JKSunny/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-openjk">OpenJK</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp`, `codemp/client/cl_scrn.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64b989e1984b`](https://github.com/eternalcodes/EternalJK/commit/64b989e1984bc8a20a348a8e0a4bd4d46801f523)<br>Add batch script to create VS2017 projects. Fixed minor build error with cl_drawRecording. | Changed an exact bound cvar-variable reference. `codemp/client/client.h` | `medium` |
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9563d0aead75`](https://github.com/eternalcodes/EternalJK/commit/9563d0aead75f983215abf2012824ecafa12a8f3)<br>More options for drawing demo recording text (0-5) | Changed an exact bound cvar-variable reference. `codemp/client/cl_scrn.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)<br>chat styles | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3395](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3395) (Cvar_Get)
- behavior: [codemp/client/cl_scrn.cpp:399](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L399)
- behavior: [codemp/client/cl_scrn.cpp:404](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L404)
- behavior: [codemp/client/cl_scrn.cpp:406](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L406)
- behavior: [codemp/client/cl_scrn.cpp:408](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L408)
- behavior: [codemp/client/cl_scrn.cpp:410](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L410)
- upstream-documentation: [CVARS.rst:135](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L135)
