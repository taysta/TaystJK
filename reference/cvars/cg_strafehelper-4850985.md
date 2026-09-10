---
title: "cg_strafeHelper"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_strafeHelper`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Configure with the /strafehelper command

## At a glance

| Field | Value |
|:--|:--|
| Category | Movement & race |
| Feature family | Strafe helper |
| Module | `cgame` |
| Also registered in | `cgame`, `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L323) |
| In-game menu | No |
| Default | `3008` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `16384` | Enables the `SHELPER_CROSSHAIR` code path. | [codemp/cgame/hud_strafehelper.h:76](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.h#L76) |
| `2` | Enables the `SHELPER_UPDATED` code path. | [codemp/cgame/hud_strafehelper.h:63](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.h#L63) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `3008` | `cgame` | `—` | `always` |
| `3008` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-04-19`, integrated `2018-04-19`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:83](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L83)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/taysta/TaystJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/videoP/jaPRO/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/JKSunny/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-04-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d10c9257cd3c`](https://github.com/eternalcodes/EternalJK/commit/d10c9257cd3ca6037b1a1bbca886e0df1b9fa184)<br>Changed cg_strafeHelper default in UI | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f1415e13d7eb`](https://github.com/eternalcodes/EternalJK/commit/f1415e13d7eb6e3903d0230f18d5edef8c26672e)<br>Fixed mac compile+disable camera damping with strafehelper enabled | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c62f8345fd64`](https://github.com/eternalcodes/EternalJK/commit/c62f8345fd64e9cb8891582ed3d6c26270a21144)<br>Tweak accelmeter alignment/position | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293)<br>cosmetics | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ead7c2c37109`](https://github.com/eternalcodes/EternalJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06)<br>cg_speedometersettings -> cg_speedometer defaults to off cg_speedometer 1 = normal speedometer like ppl would expect | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b6764d0171e`](https://github.com/eternalcodes/EternalJK/commit/0b6764d0171edd446ef75464ad2edeaaead40e92)<br>cg_showpos | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2019-01-14` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`18a8e8c9a528`](https://github.com/taysta/TaystJK/commit/18a8e8c9a528dd540dddee52ae2376a7c05a5e47)<br>FPS independent camera damping (cg_cameraFPS from fau's SaberMod) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7bd5df22796d`](https://github.com/eternalcodes/EternalJK/commit/7bd5df22796d79cd2d117f49cca0d65375f1624d)<br>Prevent camera from jerking when toggling cg_thirdPerson/strafeHelper settings | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2021-01-08` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`01b3eca4d752`](https://github.com/eternalcodes/EternalJK/commit/01b3eca4d752cc3f53f4c8c43c333b204a93f5ad)<br>jittery 3rd person strafeline fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-10-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`4c57705c4f1b`](https://github.com/taysta/TaystJK/commit/4c57705c4f1b0bbe31e15bcddf95a61401e4aa6d)<br>wsw accel hud | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2023-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fe7a86d0fc89`](https://github.com/taysta/TaystJK/commit/fe7a86d0fc89a22cd46207bf7d49780721e4f20f) · [PR #10](https://github.com/taysta/TaystJK/pull/10)<br>Merge pull request #10 from taysta/dynamic-format-tables | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-11-02` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1d83811e8ebc`](https://github.com/taysta/TaystJK/commit/1d83811e8ebc205a6d46481f6a9006ee2da181ae)<br>[EternalJK/Bucky] Add the rest of the xdocs defines and include the documentation file, improve xdocs help text. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2023-11-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a0faccba9b0f`](https://github.com/taysta/TaystJK/commit/a0faccba9b0f2aa6c902d11de9a24ee2baf0b871) · [PR #38](https://github.com/taysta/TaystJK/pull/38)<br>Merge pull request #38 from taysta/strafehelper-patch | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2025-09-30` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`f1257e1b118e`](https://github.com/videoP/jaPRO/commit/f1257e1b118eeec6fafca5f45979a63b0f40fd16) · [PR #260](https://github.com/taysta/TaystJK/pull/260)<br>Strafehelper tweaks (#260) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `high` |
| `2026-02-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d5aa0d6c8b70`](https://github.com/taysta/TaystJK/commit/d5aa0d6c8b70de0cb6b99ee228b2097216bbe333) · [PR #289](https://github.com/taysta/TaystJK/pull/289)<br>Merge pull request #289 from taysta/movement-keys | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2026-06-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ee86ea605ac4`](https://github.com/taysta/TaystJK/commit/ee86ea605ac4c0356f892a91721cd922306169df) · [PR #333](https://github.com/taysta/TaystJK/pull/333)<br>Merge pull request #333 from taysta/shelper-fixes | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:109](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L109) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:162](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L162) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:1962](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L1962)
- behavior: [codemp/cgame/cg_draw.c:7872](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L7872)
- behavior: [codemp/cgame/cg_draw.c:9197](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L9197)
- behavior: [codemp/cgame/cg_view.c:567](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L567)
- behavior: [codemp/cgame/cg_view.c:621](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L621)
- documentation: [codemp/ui/ui_xdocs.h:323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L323)
