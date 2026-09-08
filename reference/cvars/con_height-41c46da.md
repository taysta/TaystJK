---
title: "con_height"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_height`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Fraction of a screen which should be occupied by in-game console.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0.5` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`65dc622f76c0`](https://github.com/mvdevs/jk2mv/commit/65dc622f76c096cff05f5eec64c0221e334ba94d) on `2016-05-27` in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>
- TaystJK integration evidence: [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207)
- Pull request: [#140](https://github.com/taysta/TaystJK/pull/140)
- Matching squash bullet: `[Shared] Add con_height cvar to set console height. Set to 0 to restore previous behaviour.`
- Upstream registration evidence: [src/client/cl_console.cpp:403](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_console.cpp#L403)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-05-27` | [`65dc622f76c0`](https://github.com/mvdevs/jk2mv/commit/65dc622f76c096cff05f5eec64c0221e334ba94d) | Ultimate origin |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-08` | [`01697e61fe58`](https://github.com/JACoders/OpenJK/commit/01697e61fe586e31591dd236e1d4441c92f41a8a) | Later project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-19` | [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-19` | [`b6f5ff52cbac`](https://github.com/videoP/jaPRO/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-19` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) · [PR #140](https://github.com/taysta/TaystJK/pull/140)<br>Openjk update (#140) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:664](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L664) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1244](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1244)
- upstream-documentation: [CVARS.rst:145](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L145)
