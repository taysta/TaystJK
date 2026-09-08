---
title: "com_priority"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_priority`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Duno, -1 = do nothing, 1 = low priority, 2 = normal priority, 3 = high priority? i guess??

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `-1` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `-1` | Do nothing. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |
| `1` | Low priority. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |
| `2` | Normal priority. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |
| `3` | High priority? i guess??. | [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_NORESTART` — preserved across cvar restart

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`20755a5d4be0`](https://github.com/eternalcodes/EternalJK/commit/20755a5d4be00432747aa8b7c1b6cc746296995b) on `2018-11-27` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/qcommon/common.cpp:1278](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/common.cpp#L1278)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-11-27` | [`20755a5d4be0`](https://github.com/eternalcodes/EternalJK/commit/20755a5d4be00432747aa8b7c1b6cc746296995b) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-11-27` | [`20755a5d4be0`](https://github.com/taysta/TaystJK/commit/20755a5d4be00432747aa8b7c1b6cc746296995b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-11-27` | [`20755a5d4be0`](https://github.com/videoP/jaPRO/commit/20755a5d4be00432747aa8b7c1b6cc746296995b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-11-27` | [`20755a5d4be0`](https://github.com/JKSunny/EternalJK/commit/20755a5d4be00432747aa8b7c1b6cc746296995b) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-11-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2340addf5998`](https://github.com/eternalcodes/EternalJK/commit/2340addf599800dd2518a4e4fc8d70873132da1b)<br>Don't set custom process priority by default | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `shared/sys/sys_win32.cpp` | `medium` |
| `2018-11-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`243d1eb42584`](https://github.com/eternalcodes/EternalJK/commit/243d1eb425847febc9b237b353828b487b424029)<br>Change com_priority print messages to dprints | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `shared/sys/sys_win32.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1496](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1496) (Cvar_Get); condition `defined(_WIN32)`
- behavior: [shared/sys/sys_win32.cpp:256](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L256)
- behavior: [shared/sys/sys_win32.cpp:261](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L261)
- behavior: [shared/sys/sys_win32.cpp:264](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L264)
- behavior: [shared/sys/sys_win32.cpp:267](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L267)
- behavior: [shared/sys/sys_win32.cpp:270](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L270)
