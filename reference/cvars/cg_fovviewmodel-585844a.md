---
title: "cg_fovViewmodel"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_fovViewmodel`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_fovViewmodel` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `80` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`004c73dcfeb3`](https://github.com/JACoders/OpenJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-08-04`, integrated `2013-08-04`)
- Upstream registration evidence: [code/cgame/cg_main.cpp:458](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/cgame/cg_main.cpp#L458)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/JACoders/OpenJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/eternalcodes/EternalJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/SomaZ/OpenJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/taysta/TaystJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/videoP/jaPRO/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/jkanewmod/NewJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-08-04` | — | `2013-08-04` | [`004c73dcfeb3`](https://github.com/JKSunny/EternalJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`52dd792e9a6d`](https://github.com/JACoders/OpenJK/commit/52dd792e9a6d06c1d7176069f62043a2974fa1cb)<br>[SP] Decoupled viewmodel FOV from view FOV. Added option to not lower viewmodel at high FOV values. Defaults to inheriting view FOV and lowering viewmodel like base. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp` | `medium` |
| `2014-01-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`0d4797fcd711`](https://github.com/JACoders/OpenJK/commit/0d4797fcd711d33ca630c0219038bf9883b229e3)<br>[SP] JK2: Added cvars from mp: cg_fovViewmodel, cg_fovViewmodelAdjust | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3)<br>Merge pull request #3 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8a080da0044d`](https://github.com/eternalcodes/EternalJK/commit/8a080da0044d95468ad40bf52e86c270603c46df)<br>Fixed flashing health tic on JK2 HUD | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:306](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L306) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_weapons.c:885](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L885)
- behavior: [codemp/cgame/cg_weapons.c:821](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L821)
