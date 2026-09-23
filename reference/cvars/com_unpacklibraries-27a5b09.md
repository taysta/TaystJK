---
title: "com_unpackLibraries"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `com_unpackLibraries`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_unpackLibraries` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-11-29 in [`596ae40cc`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sys/sys_main.cpp:493](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L493) |
| `1` | Enabled. | [shared/sys/sys_main.cpp:493](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L493) |

## Flags

- `CVAR_INIT`: initialization/command-line setting
- `CVAR_PROTECTED`: protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2023-11-06`, PR opened `2023-11-07`, integrated `2024-04-07`)
- TaystJK integration evidence: [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0)
- Origin pull request: [#1185](https://github.com/JACoders/OpenJK/pull/1185)
- TaystJK integration pull request: [#52](https://github.com/taysta/TaystJK/pull/52)
- Upstream registration evidence: [shared/sys/sys_main.cpp:169](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/shared/sys/sys_main.cpp#L169)
- Attribution method: `authored-pr-chronology+cross-project-pr-link`
- Attribution confidence: `high`
- Notes: openjk retains origin because content authorship and PR submission predate the project that merged the work first.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-06` | [2023-11-07](https://github.com/JACoders/OpenJK/pull/1185) | `2024-04-07` | [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-06` | [2023-11-27](https://github.com/taysta/TaystJK/pull/52) | `2023-11-28` | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-06` | — | `2023-11-28` | [`596ae40cc9aa`](https://github.com/videoP/jaPRO/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-06` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

## Evidence

- registration: [shared/sys/sys_main.cpp:179](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L179) (Cvar_Get)
- behavior: [shared/sys/sys_main.cpp:493](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L493)
- behavior: [shared/sys/sys_main.cpp:575](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L575)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
