---
title: "r_sdlDriver"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_sdlDriver`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_sdlDriver` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-12-22`, integrated `2015-02-07`)
- Upstream registration evidence: [shared/sdl/sdl_window.cpp:735](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/shared/sdl/sdl_window.cpp#L735)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/eternalcodes/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/SomaZ/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/taysta/TaystJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/videoP/jaPRO/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/jkanewmod/NewJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-12-22` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JKSunny/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-03-25` | — | `2016-03-28` | [`59313f7414a1`](https://github.com/mvdevs/jk2mv/commit/59313f7414a1b36711f04c54e4fdebcca51e1400) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2025-04-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) · [PR #228](https://github.com/taysta/TaystJK/pull/228)<br>Update built in SDL version for windows to 2.32.4 (#228) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `shared/sdl/sdl_window.cpp` | `medium` |

## Evidence

- registration: [shared/sdl/sdl_window.cpp:793](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L793) (Cvar_Get)
- behavior: [shared/sdl/sdl_window.cpp:719](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L719)
- behavior: [shared/sdl/sdl_window.cpp:721](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L721)
