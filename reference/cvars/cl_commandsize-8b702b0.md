---
title: "cl_commandsize"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_commandsize`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_commandsize` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `64` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `64` | `cgame` | `—` | `always` |
| `64` | `engine-shared` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`748dc11dea5a`](https://github.com/eternalcodes/EternalJK/commit/748dc11dea5adc3a3f02fe88f7dc00197e482abe) on `2017-12-05` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:190](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L190)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-05` | [`748dc11dea5a`](https://github.com/eternalcodes/EternalJK/commit/748dc11dea5adc3a3f02fe88f7dc00197e482abe) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-05` | [`748dc11dea5a`](https://github.com/taysta/TaystJK/commit/748dc11dea5adc3a3f02fe88f7dc00197e482abe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-05` | [`748dc11dea5a`](https://github.com/videoP/jaPRO/commit/748dc11dea5adc3a3f02fe88f7dc00197e482abe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-05` | [`748dc11dea5a`](https://github.com/JKSunny/EternalJK/commit/748dc11dea5adc3a3f02fe88f7dc00197e482abe) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2020-05-15` | [`8ca268d5f911`](https://github.com/jkanewmod/NewJK/commit/8ca268d5f9111d39eeb7c6bc2bc446ebda1414b5) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3)<br>Merge pull request #3 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp`, `codemp/client/cl_input.cpp`, `codemp/qcommon/common.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_predict.c`, `codemp/cgame/cg_xcvar.h` and 3 more | `high` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_xcvar.h`, `codemp/qcommon/common.cpp` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:219](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L219) (XCVAR_DEF)
- registration: [codemp/qcommon/common.cpp:1485](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1485) (Cvar_Get)
- behavior: [codemp/cgame/cg_draw.c:7109](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L7109)
- behavior: [codemp/cgame/cg_predict.c:999](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_predict.c#L999)
- behavior: [codemp/client/cl_cgame.cpp:56](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L56)
- behavior: [codemp/client/cl_input.cpp:1448](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1448)
- behavior: [codemp/client/cl_input.cpp:1612](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1612)
