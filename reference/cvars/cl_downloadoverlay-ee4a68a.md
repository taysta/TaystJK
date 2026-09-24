---
title: "cl_downloadOverlay"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_downloadOverlay`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Draw download info overlay

## At a glance

| Field | Value |
|:--|:--|
| Category | Files & downloads |
| Feature family | Downloads |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2023-11-29 in [`596ae40cc`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_main.cpp:1543](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L1543) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:1543](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L1543) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2023-11-11`, PR opened `2023-11-07`, integrated `2024-04-07`)
- TaystJK integration evidence: [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0)
- Origin pull request: [#1185](https://github.com/JACoders/OpenJK/pull/1185)
- TaystJK integration pull request: [#52](https://github.com/taysta/TaystJK/pull/52)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2834](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2834)
- Attribution method: `authored-pr-chronology+cross-project-pr-link`
- Attribution confidence: `high`
- Notes: openjk retains origin because content authorship and PR submission predate the project that merged the work first.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-11` | [2023-11-07](https://github.com/JACoders/OpenJK/pull/1185) | `2024-04-07` | [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-11` | [2023-11-27](https://github.com/taysta/TaystJK/pull/52) | `2023-11-28` | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-11` | — | `2023-11-28` | [`596ae40cc9aa`](https://github.com/videoP/jaPRO/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-11` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3410](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L3410) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1543](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L1543)
- behavior: [codemp/client/cl_main.cpp:1689](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/client/cl_main.cpp#L1689)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
