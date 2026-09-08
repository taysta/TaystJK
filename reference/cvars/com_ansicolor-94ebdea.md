---
title: "com_ansiColor"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_ansiColor`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_ansiColor` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sys/con_tty.cpp:509](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/con_tty.cpp#L509) |
| `1` | Enabled. | [shared/sys/con_tty.cpp:509](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/con_tty.cpp#L509) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) on `2015-02-07` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/qcommon/common.cpp:1264](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/common.cpp#L1264)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/eternalcodes/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/SomaZ/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/taysta/TaystJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/videoP/jaPRO/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/jkanewmod/NewJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JKSunny/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `high` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1487](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1487) (Cvar_Get); condition `!defined(_WIN32)`
- behavior: [shared/sys/con_tty.cpp:509](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/con_tty.cpp#L509)
