---
title: "r_centerWindow"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_centerWindow`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_centerWindow` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer`, `engine-shared` |
| Renderer | `rd-dedicated` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-dedicated` | `always` |
| `1` | `engine-shared` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-05-06`, integrated `2013-05-11`)
- Upstream registration evidence: [codemp/rd-dedicated/tr_init.cpp:349](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-dedicated/tr_init.cpp#L349)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/eternalcodes/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/SomaZ/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/taysta/TaystJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/videoP/jaPRO/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/jkanewmod/NewJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-05-06` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/JKSunny/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-03-25` | — | `2016-03-28` | [`59313f7414a1`](https://github.com/mvdevs/jk2mv/commit/59313f7414a1b36711f04c54e4fdebcca51e1400) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `shared/sdl/sdl_window.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe)<br>Merge remote-tracking branch 'origin/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp`, `shared/sdl/sdl_window.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-dedicated/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_local.h` | `medium` |

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:348](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-dedicated/tr_init.cpp#L348) (Cvar_Get)
- registration: [shared/sdl/sdl_window.cpp:800](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L800) (Cvar_Get)
- behavior: [shared/sdl/sdl_window.cpp:423](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_window.cpp#L423)
