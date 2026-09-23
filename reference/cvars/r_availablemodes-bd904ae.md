---
title: "r_availableModes"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_availableModes`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>).</p>

Controls `r_availableModes` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2015-02-07 in [`a7c43677a`](https://github.com/taysta/TaystJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM`: read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-12-22`, integrated `2015-02-07`)
- Upstream registration evidence: [shared/sdl/sdl_window.cpp:756](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/shared/sdl/sdl_window.cpp#L756)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

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
| `2016-02-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c0330fa17b25`](https://github.com/videoP/jaPRO/commit/c0330fa17b25177146ae2b941c623e08e6d81813)<br>Merge branch 'master' into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `shared/sdl/sdl_window.cpp` | `high` |

## Evidence

- registration: [shared/sdl/sdl_window.cpp:818](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/sdl/sdl_window.cpp#L818) (Cvar_Get)
- behavior: [shared/sdl/sdl_window.cpp:321](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/sdl/sdl_window.cpp#L321)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
