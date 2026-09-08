---
title: "cg_debugGun"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_debugGun`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_debugGun` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_weapons.c:898](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L898) |
| `1` | Enabled. | [codemp/cgame/cg_weapons.c:898](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L898) |

## Flags

- `CVAR_CHEAT` — requires cheats

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) on `2013-04-07` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:77](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/cgame/cg_xcvar.h#L77)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/eternalcodes/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/SomaZ/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/taysta/TaystJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/videoP/jaPRO/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/jkanewmod/NewJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JKSunny/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:296](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L296) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_weapons.c:898](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L898)
- behavior: [codemp/cgame/cg_weapons.c:900](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L900)
