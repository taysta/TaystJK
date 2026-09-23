---
title: "cl_filterGames"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_filterGames`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

List of fs_game to filter (space separated)

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2023-11-28 in [`47e33dfb6`](https://github.com/taysta/TaystJK/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `MBII MBIIOpenBeta` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`58ad339799e4`](https://github.com/JACoders/OpenJK/commit/58ad339799e46a1ba2ee7b3218d6937f6582f29a) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2024-02-08`, PR opened `2023-11-12`, integrated `2024-02-08`)
- TaystJK integration evidence: [`47e33dfb6fd5`](https://github.com/taysta/TaystJK/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae)
- Origin pull request: [#1188](https://github.com/JACoders/OpenJK/pull/1188)
- TaystJK integration pull request: [#53](https://github.com/taysta/TaystJK/pull/53)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2830](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2830)
- Attribution method: `curated-historical-attribution`
- Attribution confidence: `high`
- Notes: Daggolin authored cl_filterGames for OpenJK PR #1188, linked by TaystJK integration PR #53. OpenJK's later squash commit does not make the earlier TaystJK import the origin.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-09` | [2023-11-28](https://github.com/taysta/TaystJK/pull/53) | `2023-11-28` | [`47e33dfb6fd5`](https://github.com/taysta/TaystJK/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-09` | — | `2023-11-28` | [`47e33dfb6fd5`](https://github.com/videoP/jaPRO/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-08` | [2023-11-12](https://github.com/JACoders/OpenJK/pull/1188) | `2024-02-08` | [`58ad339799e4`](https://github.com/JACoders/OpenJK/commit/58ad339799e46a1ba2ee7b3218d6937f6582f29a) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-08` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ea0478621b05`](https://github.com/taysta/TaystJK/commit/ea0478621b0535dc6a6e5a22036237942e98c417) · [PR #141](https://github.com/taysta/TaystJK/pull/141)<br>Patch stitching (#141) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2024-05-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3beb186e7772`](https://github.com/taysta/TaystJK/commit/3beb186e7772b05e693b96c2d831dd1c1e888fb2) · [PR #197](https://github.com/taysta/TaystJK/pull/197)<br>Autodl fixup (#197) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3411](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3411) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:3754](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3754)
- behavior: [codemp/client/cl_main.cpp:3763](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3763)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
