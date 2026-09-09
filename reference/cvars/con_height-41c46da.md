---
title: "con_height"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_height`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Adjust the height of the console

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

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2013-04-30`, PR opened `2024-02-09`, integrated `2024-02-19`)
- Origin pull request: [#140](https://github.com/taysta/TaystJK/pull/140)
- Matching squash bullet: `[Shared] Add con_height cvar to set console height. Set to 0 to restore previous behaviour.`
- Upstream registration evidence: [codemp/client/cl_console.cpp:664](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L664)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: taystjk retains origin because content authorship and PR submission predate the project that merged the work first.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-30` | [2024-02-09](https://github.com/taysta/TaystJK/pull/140) | `2024-02-19` | [`b6f5ff52cbac`](https://github.com/taysta/TaystJK/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-30` | — | `2024-02-19` | [`b6f5ff52cbac`](https://github.com/videoP/jaPRO/commit/b6f5ff52cbac9adf917e0db8078fba73a4a81207) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-05-27` | — | `2016-05-27` | [`65dc622f76c0`](https://github.com/mvdevs/jk2mv/commit/65dc622f76c096cff05f5eec64c0221e334ba94d) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-06` | — | `2024-02-08` | [`01697e61fe58`](https://github.com/JACoders/OpenJK/commit/01697e61fe586e31591dd236e1d4441c92f41a8a) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-06` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:664](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L664) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1244](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1244)
