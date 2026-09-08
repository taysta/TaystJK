---
title: "cl_filterGames"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_filterGames`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

List of fs_game to filter (space separated)

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `MBII MBIIOpenBeta` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`47e33dfb6fd5`](https://github.com/taysta/TaystJK/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) on `2023-11-28` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#53](https://github.com/taysta/TaystJK/pull/53)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3409](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3409)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The TaystJK integration evidence credits openjk as an immediate port source, but taystjk has an earlier dated introduction and remains the ultimate origin.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-28` | [`47e33dfb6fd5`](https://github.com/taysta/TaystJK/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-28` | [`47e33dfb6fd5`](https://github.com/videoP/jaPRO/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-08` | [`58ad339799e4`](https://github.com/JACoders/OpenJK/commit/58ad339799e46a1ba2ee7b3218d6937f6582f29a) | Later project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Later project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-openjk">OpenJK</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) · [PR #141](https://github.com/taysta/TaystJK/pull/141)<br>Patch stitching (#141) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2024-05-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3beb186e7772`](https://github.com/taysta/TaystJK/commit/3beb186e7772b05e693b96c2d831dd1c1e888fb2) · [PR #197](https://github.com/taysta/TaystJK/pull/197)<br>Autodl fixup (#197) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3409](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3409) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:3750](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3750)
- behavior: [codemp/client/cl_main.cpp:3759](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3759)
