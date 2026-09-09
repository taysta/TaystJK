---
title: "cg_cameraFPS"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_cameraFPS`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Sets the emulated frame rate used to make third-person camera damping frame-rate independent. Values below 15 select the original JK2/JKA multiplayer damping path; values of 15 or more use the time-adjusted path, with the original response reproduced when the actual frame rate matches this value.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_camera.menu:111](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_camera.menu#L111) |
| Default | `125` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `<15` | Use the original frame-rate-dependent JK2/JKA multiplayer camera damping. | [codemp/cgame/cg_view.c:541](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L541) |
| `>=15` | Use frame-rate-independent damping based on this emulated frame rate. | [codemp/cgame/cg_view.c:514](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L514) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- TaystJK integration evidence: [`18a8e8c9a528`](https://github.com/taysta/TaystJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. An identifier-adjacent source/commit/PR line explicitly credits jk2mv.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-01-14` | — | `2019-01-14` | [`18a8e8c9a528`](https://github.com/eternalcodes/EternalJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-01-14` | — | `2019-01-14` | [`18a8e8c9a528`](https://github.com/taysta/TaystJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-01-14` | — | `2019-01-14` | [`18a8e8c9a528`](https://github.com/videoP/jaPRO/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-01-14` | — | `2019-01-14` | [`18a8e8c9a528`](https://github.com/JKSunny/EternalJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7bd5df22796d`](https://github.com/eternalcodes/EternalJK/commit/7bd5df22796d79cd2d117f49cca0d65375f1624d)<br>Prevent camera from jerking when toggling cg_thirdPerson/strafeHelper settings | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:133](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L133) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_snapshot.c:233](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_snapshot.c#L233)
- behavior: [codemp/cgame/cg_view.c:514](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L514)
- behavior: [codemp/cgame/cg_view.c:879](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L879)
- behavior: [codemp/cgame/cg_view.c:529](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L529)
- behavior: [codemp/cgame/cg_view.c:521](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L521)
