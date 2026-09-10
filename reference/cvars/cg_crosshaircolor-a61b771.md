---
title: "cg_crosshairColor"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_crosshairColor`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_crosshairColor` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Crosshair & aiming |
| Feature family | Crosshair |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0 0 0 255` |
| Value type | `color` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`3173474c4b67`](https://github.com/eternalcodes/EternalJK/commit/3173474c4b67cc9603582a8ddc4065ebd9e7c824) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-12-19`, integrated `2018-12-19`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:80](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L80)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-12-19` | — | `2018-12-19` | [`3173474c4b67`](https://github.com/eternalcodes/EternalJK/commit/3173474c4b67cc9603582a8ddc4065ebd9e7c824) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-12-19` | — | `2018-12-19` | [`3173474c4b67`](https://github.com/taysta/TaystJK/commit/3173474c4b67cc9603582a8ddc4065ebd9e7c824) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-12-19` | — | `2018-12-19` | [`3173474c4b67`](https://github.com/videoP/jaPRO/commit/3173474c4b67cc9603582a8ddc4065ebd9e7c824) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-12-19` | — | `2018-12-19` | [`3173474c4b67`](https://github.com/JKSunny/EternalJK/commit/3173474c4b67cc9603582a8ddc4065ebd9e7c824) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-01-14` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`18a8e8c9a528`](https://github.com/taysta/TaystJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47)<br>FPS independent camera damping (cg_cameraFPS from fau's SaberMod) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-02-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`aba934621843`](https://github.com/eternalcodes/EternalJK/commit/aba9346218436974329e85cbedbe5a7022651e14)<br>cg_chatBoxLines | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:104](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L104) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_cvar.c:83](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_cvar.c#L83)
