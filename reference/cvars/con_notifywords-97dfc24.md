---
title: "con_notifywords"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_notifywords`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Notifies you when defined words are mentioned

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`d1ec3b6ad84c`](https://github.com/eternalcodes/EternalJK/commit/d1ec3b6ad84cb2c40217effe83d0c01916c8fe08) on `2018-02-25` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_console.cpp:543](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L543)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-02-25` | [`d1ec3b6ad84c`](https://github.com/eternalcodes/EternalJK/commit/d1ec3b6ad84cb2c40217effe83d0c01916c8fe08) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-02-25` | [`d1ec3b6ad84c`](https://github.com/taysta/TaystJK/commit/d1ec3b6ad84cb2c40217effe83d0c01916c8fe08) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-02-25` | [`d1ec3b6ad84c`](https://github.com/videoP/jaPRO/commit/d1ec3b6ad84cb2c40217effe83d0c01916c8fe08) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-02-25` | [`d1ec3b6ad84c`](https://github.com/JKSunny/EternalJK/commit/d1ec3b6ad84cb2c40217effe83d0c01916c8fe08) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-01-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0d37a09aa77f`](https://github.com/eternalcodes/EternalJK/commit/0d37a09aa77f4fcdd7ac4911933f9a5622233039)<br>Console/Chat field: Ctrl+A clears field and copies contents to clipboard. | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:661](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L661) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:586](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L586)
- behavior: [codemp/client/cl_cgame.cpp:591](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L591)
- behavior: [codemp/client/cl_main.cpp:2399](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2399)
- behavior: [codemp/client/cl_main.cpp:2450](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2450)
- behavior: [codemp/client/cl_main.cpp:2451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2451)
