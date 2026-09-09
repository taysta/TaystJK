---
title: "cg_fovAspectAdjust"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_fovAspectAdjust`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Fixed skyportal issue

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_view.c:1424](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1424) |
| `1` | Enabled. | [codemp/cgame/cg_view.c:1424](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1424) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-05-03`, integrated `2013-05-11`)
- Upstream registration evidence: [code/cgame/cg_main.cpp:355](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/cgame/cg_main.cpp#L355)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/eternalcodes/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/SomaZ/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/taysta/TaystJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/videoP/jaPRO/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/jkanewmod/NewJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-05-03` | — | `2013-05-11` | [`f203e799b14c`](https://github.com/JKSunny/EternalJK/commit/f203e799b14c0716833793eed611c272111c3cb6) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2013-08-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`142bd8696935`](https://github.com/JACoders/OpenJK/commit/142bd869693538ab6e10d52a6e5d7df631a7d479)<br>Adds cg_fovAspectAdjust to SP. Waiting on viewmodel fov changes because, SP uses 80 as the starting number for viewmodel fov scaling. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp` | `medium` |
| `2014-03-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cfeb246ffcce`](https://github.com/JACoders/OpenJK/commit/cfeb246ffcce3105e835a8043c5770ce92cc7783)<br>[JK2SP] Merging in some fixes and cleanup from JASP cgame/game code. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3)<br>Merge pull request #3 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_view.c`, `codemp/cgame/cg_weapons.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_view.c`, `codemp/cgame/cg_weapons.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8a080da0044d`](https://github.com/eternalcodes/EternalJK/commit/8a080da0044d95468ad40bf52e86c270603c46df)<br>Fixed flashing health tic on JK2 HUD | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2019-06-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`96fd54d4bc38`](https://github.com/eternalcodes/EternalJK/commit/96fd54d4bc38f21aa828a1cfda03dbf6b972ea18)<br>Remove unused CG_CalcFovFromX function, move CG_ZoomDown/Up_f functions | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2023-09-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cc60756b1504`](https://github.com/taysta/TaystJK/commit/cc60756b1504046d18284d1775106d6f4bef9bec)<br>Also aspect correct the fov in skybox portals (#1142) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2023-12-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`6bde009fdf0a`](https://github.com/taysta/TaystJK/commit/6bde009fdf0a5536f8e2754d38dc05f1b08b07d9)<br>Remove some redundant code | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:305](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L305) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_view.c:1424](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1424)
- behavior: [codemp/cgame/cg_view.c:2002](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L2002)
- behavior: [codemp/cgame/cg_weapons.c:887](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L887)
