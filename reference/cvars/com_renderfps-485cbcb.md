---
title: "com_renderfps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_renderfps`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_renderfps` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_main.cpp:2480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2480) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:2480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2480) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3) on `2017-12-05` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/qcommon/common.cpp:1266](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/common.cpp#L1266)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-05` | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-05` | [`9207f1148bdd`](https://github.com/taysta/TaystJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-05` | [`9207f1148bdd`](https://github.com/videoP/jaPRO/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-05` | [`9207f1148bdd`](https://github.com/JKSunny/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9563d0aead75`](https://github.com/eternalcodes/EternalJK/commit/9563d0aead75f983215abf2012824ecafa12a8f3)<br>More options for drawing demo recording text (0-5) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/qcommon/common.cpp` | `high` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `high` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1484](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1484) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2480)
- behavior: [codemp/client/cl_scrn.cpp:386](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L386)
- behavior: [codemp/client/client.h:326](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/client.h#L326)
