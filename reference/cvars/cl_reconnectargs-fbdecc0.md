---
title: "cl_reconnectArgs"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_reconnectArgs`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Arguments provided when last connecting to a server

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2026-06-01 in [`a6f521232`](https://github.com/taysta/TaystJK/commit/a6f521232afba109e20275bac4a71369ba5b5ae1) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`e65d1a743959`](https://github.com/JACoders/OpenJK/commit/e65d1a743959a81d839c06809d39505d57fa90ec) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2025-10-09`, integrated `2026-05-12`)
- TaystJK integration evidence: [`a6f521232afb`](https://github.com/taysta/TaystJK/commit/a6f521232afba109e20275bac4a71369ba5b5ae1)
- Origin pull request: [#311](https://github.com/taysta/TaystJK/pull/311)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2836](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2836)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2025-10-09` | — | `2026-05-12` | [`e65d1a743959`](https://github.com/JACoders/OpenJK/commit/e65d1a743959a81d839c06809d39505d57fa90ec) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-10-09` | [2026-06-01](https://github.com/taysta/TaystJK/pull/311) | `2026-06-01` | [`a6f521232afb`](https://github.com/taysta/TaystJK/commit/a6f521232afba109e20275bac4a71369ba5b5ae1) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-10-09` | — | `2026-06-01` | [`a6f521232afb`](https://github.com/videoP/jaPRO/commit/a6f521232afba109e20275bac4a71369ba5b5ae1) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2025-10-09` | — | `2026-07-12` | [`1a738058a2d2`](https://github.com/SomaZ/OpenJK/commit/1a738058a2d285c185315c480d30ac90cafe4968) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3415](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_main.cpp#L3415) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1126](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_main.cpp#L1126)
- behavior: [codemp/client/cl_main.cpp:1130](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_main.cpp#L1130)
- behavior: [codemp/client/cl_main.cpp:1149](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_main.cpp#L1149)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
