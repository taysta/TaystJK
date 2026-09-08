---
title: "con_opacity"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_opacity`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Opacity of console background

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1.0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`4e834782a30a`](https://github.com/JACoders/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) on `2014-03-30` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`37a07abc8b26`](https://github.com/taysta/TaystJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7)
- Upstream registration evidence: [code/client/cl_console.cpp:419](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_console.cpp#L419)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2, newjk; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-03-30` | [`4e834782a30a`](https://github.com/JACoders/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-03-30` | [`4e834782a30a`](https://github.com/SomaZ/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-03-30` | [`4e834782a30a`](https://github.com/jkanewmod/NewJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-03-30` | [`37a07abc8b26`](https://github.com/eternalcodes/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-03-30` | [`37a07abc8b26`](https://github.com/taysta/TaystJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-03-30` | [`37a07abc8b26`](https://github.com/videoP/jaPRO/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-03-30` | [`37a07abc8b26`](https://github.com/JKSunny/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Later project appearance |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2023-02-26` | [`94a4cbd57201`](https://github.com/mvdevs/jk2mv/commit/94a4cbd57201ce09506dd3c00c89c6c556e91d61) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-03-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`37a07abc8b26`](https://github.com/JACoders/OpenJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7)<br>[MP] Console no longer uses frac in determining opacity. Renamed the cvar for this fix and set its default value to 1.0 to mimic basejka MP. SetColor call now sets RGB to 1.0f instead of 0.0f, as it should. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:658](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L658) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1060](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1060)
