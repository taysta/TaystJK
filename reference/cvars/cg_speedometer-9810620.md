---
title: "cg_speedometer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_speedometer`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Configure with the /speedometer command

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `64` | Enables the `SPEEDOMETER_ACCELMETER` code path. | [codemp/cgame/hud_strafehelper.h:90](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.h#L90) |
| `1` | Enables the `SPEEDOMETER_ENABLE` code path. | [codemp/cgame/hud_strafehelper.h:84](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.h#L84) |
| `8` | Enables the `SPEEDOMETER_JUMPDISTANCE` code path. | [codemp/cgame/hud_strafehelper.h:87](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.h#L87) |
| `4` | Enables the `SPEEDOMETER_JUMPHEIGHT` code path. | [codemp/cgame/hud_strafehelper.h:86](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.h#L86) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`ead7c2c37109`](https://github.com/videoP/jaPRO/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-03`, integrated `2018-11-04`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:46](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L46)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/eternalcodes/EternalJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/taysta/TaystJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/videoP/jaPRO/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-03` | — | `2018-11-04` | [`ead7c2c37109`](https://github.com/JKSunny/EternalJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b6764d0171e`](https://github.com/eternalcodes/EternalJK/commit/0b6764d0171edd446ef75464ad2edeaaead40e92)<br>cg_showpos | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-11-02` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1d83811e8ebc`](https://github.com/taysta/TaystJK/commit/1d83811e8ebc205a6d46481f6a9006ee2da181ae)<br>[EternalJK/Bucky] Add the rest of the xdocs defines and include the documentation file, improve xdocs help text. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2023-11-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a0faccba9b0f`](https://github.com/taysta/TaystJK/commit/a0faccba9b0f2aa6c902d11de9a24ee2baf0b871) · [PR #38](https://github.com/taysta/TaystJK/pull/38)<br>Merge pull request #38 from taysta/strafehelper-patch | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-12-30` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`136ead02a1e2`](https://github.com/taysta/TaystJK/commit/136ead02a1e2e6811b96d74b15fa1d8675ecdbe3)<br>XYZ velocity speedometer option | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2026-02-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d5aa0d6c8b70`](https://github.com/taysta/TaystJK/commit/d5aa0d6c8b70de0cb6b99ee228b2097216bbe333) · [PR #289](https://github.com/taysta/TaystJK/pull/289)<br>Merge pull request #289 from taysta/movement-keys | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:46](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L46) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:164](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L164) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:1962](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L1962)
- behavior: [codemp/cgame/hud_strafehelper.c:415](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L415)
- behavior: [codemp/cgame/hud_strafehelper.c:419](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L419)
- behavior: [codemp/cgame/hud_strafehelper.c:421](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L421)
- behavior: [codemp/cgame/hud_strafehelper.c:423](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L423)
- documentation: [codemp/ui/ui_xdocs.h:107](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L107)
