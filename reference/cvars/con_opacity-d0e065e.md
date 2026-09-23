---
title: "con_opacity"
layout: reference
generated: true
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
| Category | Engine & diagnostics |
| Feature family | Console |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2014-03-30 in [`37a07abc8`](https://github.com/taysta/TaystJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame_setup.menu:3338](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame_setup.menu#L3338) |
| Default | `1.0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`4e834782a30a`](https://github.com/JACoders/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-03-30`, integrated `2014-03-30`)
- TaystJK integration evidence: [`37a07abc8b26`](https://github.com/taysta/TaystJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7)
- Upstream registration evidence: [code/client/cl_console.cpp:419](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_console.cpp#L419)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, rend2, newjk; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-03-30` | — | `2014-03-30` | [`4e834782a30a`](https://github.com/JACoders/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-03-30` | — | `2014-03-30` | [`4e834782a30a`](https://github.com/SomaZ/OpenJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-03-30` | — | `2014-03-30` | [`4e834782a30a`](https://github.com/jkanewmod/NewJK/commit/4e834782a30ae72e380c4497c5aaaf67b9c3b96a) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-03-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/eternalcodes/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-03-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/taysta/TaystJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-03-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/videoP/jaPRO/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-03-30` | — | `2014-03-30` | [`37a07abc8b26`](https://github.com/JKSunny/EternalJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7) | Other project appearance |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2023-02-26` | — | `2023-02-26` | [`94a4cbd57201`](https://github.com/mvdevs/jk2mv/commit/94a4cbd57201ce09506dd3c00c89c6c556e91d61) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-03-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`37a07abc8b26`](https://github.com/JACoders/OpenJK/commit/37a07abc8b262a30c24397b17c3ada0c16b5bcd7)<br>[MP] Console no longer uses frac in determining opacity. Renamed the cvar for this fix and set its default value to 1.0 to mimic basejka MP. SetColor call now sets RGB to 1.0f instead of 0.0f, as it should. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:658](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_console.cpp#L658) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1060](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_console.cpp#L1060)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
