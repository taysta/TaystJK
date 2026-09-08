---
title: "ja_guid"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ja_guid`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Client GUID

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM` — read-only after registration
- `CVAR_USERINFO` — sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`cccf3136bac2`](https://github.com/JACoders/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) on `2013-07-17` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:750](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L750)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/JACoders/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/eternalcodes/EternalJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/SomaZ/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/taysta/TaystJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/videoP/jaPRO/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/jkanewmod/NewJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-07-17` | [`cccf3136bac2`](https://github.com/JKSunny/EternalJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4e06149aed8a`](https://github.com/JACoders/OpenJK/commit/4e06149aed8a297e21f63b61bda5aad9c4ec6de0)<br>Store the guid in client persistant for future uses. | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d5970a9804aa`](https://github.com/videoP/jaPRO/commit/d5970a9804aad8ebe9bd8989c4e9e2354b627667)<br>Merge branch 'master' into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `high` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:877](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L877) (Cvar_Get)
- registration: [codemp/client/cl_main.cpp:890](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L890) (Cvar_Get)
- behavior: [codemp/game/g_client.c:2841](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2841)
- behavior: [codemp/client/cl_main.cpp:97](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L97)
- behavior: [codemp/client/cl_main.cpp:98](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L98)
- behavior: [codemp/client/cl_main.cpp:880](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L880)
- behavior: [codemp/client/cl_main.cpp:882](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L882)
