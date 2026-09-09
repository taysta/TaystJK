---
title: "con_opacity"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_opacity`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

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

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`37a07abc8b26`](https://github.com/eternalcodes/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2013-04-30`, integrated `2014-03-30`)
- Upstream registration evidence: [codemp/client/cl_console.cpp:540](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L540)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: eternaljk retains origin because content authorship and PR submission predate the project that merged the work first. The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/eternalcodes/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/taysta/TaystJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/videoP/jaPRO/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/JKSunny/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Shared integration commit |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-03-30` | — | `2014-03-30` | [`4e834782a30a`](https://github.com/JACoders/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-03-30` | — | `2014-03-30` | [`4e834782a30a`](https://github.com/SomaZ/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-03-30` | — | `2014-03-30` | [`4e834782a30a`](https://github.com/jkanewmod/NewJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Other project appearance |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2023-02-26` | — | `2023-02-26` | [`94a4cbd57201`](https://github.com/mvdevs/jk2mv/commit/94a4cbd57201ce09506dd3c00c89c6c556e91d61) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-03-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4e834782a30a`](https://github.com/JACoders/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a)<br>[SP] Console no longer uses frac in determining opacity. Renamed the cvar for this fix. SetColor call now sets RGB to 1.0f instead of 0.0f, as it should. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:658](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L658) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1060](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1060)
