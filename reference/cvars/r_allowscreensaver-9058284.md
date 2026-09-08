---
title: "r_allowScreenSaver"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_allowScreenSaver`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_allowScreenSaver` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/sdl/sdl_window.cpp:724](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L724) |
| `1` | Enabled. | [shared/sdl/sdl_window.cpp:724](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L724) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- TaystJK integration evidence: [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885)
- Pull request: [#228](https://github.com/taysta/TaystJK/pull/228)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-26` | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) | Additional dated evidence |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-26` | [`44d85df90f4b`](https://github.com/videoP/jaPRO/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) | Additional dated evidence |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2025-05-02` | [`b582d130d846`](https://github.com/JKSunny/EternalJK/commit/b582d130d846430bccf02ed3993d027c510bdefc) | Additional dated evidence |

## Evidence

- registration: [shared/sdl/sdl_window.cpp:794](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L794) (Cvar_Get)
- behavior: [shared/sdl/sdl_window.cpp:724](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L724)
