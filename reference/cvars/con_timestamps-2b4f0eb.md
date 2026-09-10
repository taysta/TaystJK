---
title: "con_timestamps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_timestamps`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Draw local timestamps in console and condump output.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Feature family | Console |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Selects the code path tested for value 0. | [codemp/client/cl_console.cpp:935](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L935) |
| `2` | Selects the code path tested for value 2. | [codemp/client/cl_console.cpp:935](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L935) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`20de49f4fe92`](https://github.com/mvdevs/jk2mv/commit/20de49f4fe92499c5efd12bcbb785c8ac7179f1d) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2016-06-01`, integrated `2016-06-12`)
- TaystJK integration evidence: [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3)
- Origin pull request: [#155](https://github.com/taysta/TaystJK/pull/155)
- Matching squash bullet: `add con_timestamps 2 to disable timestamps in the notify lines only`
- Upstream registration evidence: [src/client/cl_console.cpp:407](https://github.com/mvdevs/jk2mv/blame/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_console.cpp#L407)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits jk2mv. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-06-01` | — | `2016-06-12` | [`20de49f4fe92`](https://github.com/mvdevs/jk2mv/commit/20de49f4fe92499c5efd12bcbb785c8ac7179f1d) | Ultimate origin |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-09` | — | `2024-02-08` | [`01697e61fe58`](https://github.com/JACoders/OpenJK/commit/01697e61fe586e31591dd236e1d4441c92f41a8a) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-09` | — | `2024-02-19` | [`49adb7447c9f`](https://github.com/SomaZ/OpenJK/commit/49adb7447c9f4766a9024f55ad44bb5bf8a21b07) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-27` | [2024-02-19](https://github.com/taysta/TaystJK/pull/155) | `2024-02-27` | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-27` | — | `2024-02-27` | [`61b1b328accf`](https://github.com/videoP/jaPRO/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:667](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L667) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:399](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L399)
- behavior: [codemp/client/cl_console.cpp:935](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L935)
- behavior: [codemp/client/cl_console.cpp:1157](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1157)
- behavior: [codemp/client/cl_console.cpp:615](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L615)
- upstream-documentation: [CVARS.rst:161](https://github.com/mvdevs/jk2mv/blame/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L161)
