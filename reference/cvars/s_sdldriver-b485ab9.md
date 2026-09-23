---
title: "s_sdlDriver"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `s_sdlDriver`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `s_sdlDriver` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2025-04-26 in [`44d85df90`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- TaystJK integration evidence: [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885)
- Origin pull request: [#228](https://github.com/taysta/TaystJK/pull/228)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-26` | [2025-04-26](https://github.com/taysta/TaystJK/pull/228) | `2025-04-26` | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-26` | — | `2025-04-26` | [`44d85df90f4b`](https://github.com/videoP/jaPRO/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2025-04-26` | — | `2025-05-02` | [`b582d130d846`](https://github.com/JKSunny/EternalJK/commit/b582d130d846430bccf02ed3993d027c510bdefc) | Other project appearance |

## Evidence

- registration: [shared/sdl/sdl_sound.cpp:168](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sdl/sdl_sound.cpp#L168) (Cvar_Get)
- behavior: [shared/sdl/sdl_sound.cpp:171](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sdl/sdl_sound.cpp#L171)
- behavior: [shared/sdl/sdl_sound.cpp:173](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sdl/sdl_sound.cpp#L173)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
