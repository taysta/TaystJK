---
title: "cl_downloadOverlay"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_downloadOverlay`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Draw download info overlay

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
| `0` | Disabled. | [codemp/client/cl_main.cpp:1541](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1541) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:1541](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1541) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) on `2023-11-28` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#52](https://github.com/taysta/TaystJK/pull/52)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3408](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3408)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-28` | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-28` | [`596ae40cc9aa`](https://github.com/videoP/jaPRO/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-04-07` | [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) | Later project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Later project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3408](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3408) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1541](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1541)
- behavior: [codemp/client/cl_main.cpp:1687](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1687)
