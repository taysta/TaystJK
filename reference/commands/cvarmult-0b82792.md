---
title: "cvarMult"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cvarMult`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Multiply a value to a cvar

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `cvarMult <variable> <value>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`55d9184d89f7`](https://github.com/JACoders/OpenJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2016-03-22`, integrated `2016-03-22`)
- TaystJK integration evidence: [`c9c6ab99fdd2`](https://github.com/taysta/TaystJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)
- Upstream registration evidence: [codemp/qcommon/cvar.cpp:1605](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/cvar.cpp#L1605)
- Attribution method: `shared-integration-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2016-03-22` | — | `2016-03-22` | [`55d9184d89f7`](https://github.com/JACoders/OpenJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2016-03-22` | — | `2016-03-22` | [`55d9184d89f7`](https://github.com/SomaZ/OpenJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-03-22` | — | `2016-03-22` | [`55d9184d89f7`](https://github.com/jkanewmod/NewJK/commit/55d9184d89f7a5d260af5a486f02fe1afd3f6c16) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/taysta/TaystJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/videoP/jaPRO/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-22` | — | `2016-03-24` | [`c9c6ab99fdd2`](https://github.com/JKSunny/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62) | Other project appearance |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1631](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1631) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1116](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1116)
