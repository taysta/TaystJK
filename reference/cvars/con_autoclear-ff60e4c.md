---
title: "con_autoclear"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_autoclear`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Automatically clear console input on close

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_console.cpp:76](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L76) |
| `1` | Enabled. | [codemp/client/cl_console.cpp:76](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L76) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f8564ad61037`](https://github.com/JACoders/OpenJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) on `2013-09-02` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [code/client/cl_console.cpp:420](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_console.cpp#L420)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/JACoders/OpenJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/eternalcodes/EternalJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/SomaZ/OpenJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/taysta/TaystJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/videoP/jaPRO/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/jkanewmod/NewJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-09-02` | [`f8564ad61037`](https://github.com/JKSunny/EternalJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-09-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`24a6cf41baac`](https://github.com/JACoders/OpenJK/commit/24a6cf41baac7bf296027c37343fef8b0fcf0b74)<br>(SP) Add con_autoclear cvar, defaults to 1. Disable this if you want the console input content to remain after the console closes. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:660](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L660) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:76](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L76)
