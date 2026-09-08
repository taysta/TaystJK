---
title: "cg_lagometerX"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_lagometerX`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_lagometerX` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `48` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) on `2018-09-03` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:315](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L315)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/eternalcodes/EternalJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-03` | [`bdcd618c6771`](https://github.com/JKSunny/EternalJK/commit/bdcd618c67713b86946b720d791c382d3908d97c) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2026-02-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d5aa0d6c8b70`](https://github.com/taysta/TaystJK/commit/d5aa0d6c8b70de0cb6b99ee228b2097216bbe333) · [PR #289](https://github.com/taysta/TaystJK/pull/289)<br>Merge pull request #289 from taysta/movement-keys | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:317](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L317) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:7175](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L7175)
- behavior: [codemp/cgame/hud_strafehelper.c:1799](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L1799)
