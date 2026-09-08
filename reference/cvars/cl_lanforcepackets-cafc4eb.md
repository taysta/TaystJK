---
title: "cl_lanForcePackets"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_lanForcePackets`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_lanForcePackets` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`0bf217273755`](https://github.com/JACoders/OpenJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) on `2013-10-15` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Matching squash bullet: `cl_lanForcePackets. When set to 0 (default is 1) the cl_maxpackets setting`
- Upstream registration evidence: [codemp/client/cl_main.cpp:2817](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2817)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-10-15` | [`0bf217273755`](https://github.com/JACoders/OpenJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-10-15` | [`0bf217273755`](https://github.com/eternalcodes/EternalJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-10-15` | [`0bf217273755`](https://github.com/SomaZ/OpenJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-10-15` | [`0bf217273755`](https://github.com/taysta/TaystJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-10-15` | [`0bf217273755`](https://github.com/videoP/jaPRO/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-10-15` | [`0bf217273755`](https://github.com/jkanewmod/NewJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-10-15` | [`0bf217273755`](https://github.com/JKSunny/EternalJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3393](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3393) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1515](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1515)
