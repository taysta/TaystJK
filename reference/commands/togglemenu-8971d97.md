---
title: "togglemenu"
layout: reference
nav_exclude: true
search_exclude: false
---

# `togglemenu`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Show/hide the menu

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `togglemenu` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`1f9cf0163591`](https://github.com/JACoders/OpenJK/commit/1f9cf01635910b78ad1af62040288550e5901368) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-02-01`, integrated `2014-02-01`)
- TaystJK integration evidence: [`b276c56dd51c`](https://github.com/taysta/TaystJK/commit/b276c56dd51c9934657fe418620165990229e97f)
- Upstream registration evidence: [code/client/cl_console.cpp:434](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/client/cl_console.cpp#L434)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, rend2, newjk; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-02-01` | — | `2014-02-01` | [`1f9cf0163591`](https://github.com/JACoders/OpenJK/commit/1f9cf01635910b78ad1af62040288550e5901368) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-02-01` | — | `2014-02-01` | [`1f9cf0163591`](https://github.com/SomaZ/OpenJK/commit/1f9cf01635910b78ad1af62040288550e5901368) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-02-01` | — | `2014-02-01` | [`1f9cf0163591`](https://github.com/jkanewmod/NewJK/commit/1f9cf01635910b78ad1af62040288550e5901368) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-02-01` | — | `2014-02-01` | [`b276c56dd51c`](https://github.com/eternalcodes/EternalJK/commit/b276c56dd51c9934657fe418620165990229e97f) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-02-01` | — | `2014-02-01` | [`b276c56dd51c`](https://github.com/taysta/TaystJK/commit/b276c56dd51c9934657fe418620165990229e97f) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-02-01` | — | `2014-02-01` | [`b276c56dd51c`](https://github.com/videoP/jaPRO/commit/b276c56dd51c9934657fe418620165990229e97f) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-02-01` | — | `2014-02-01` | [`b276c56dd51c`](https://github.com/JKSunny/EternalJK/commit/b276c56dd51c9934657fe418620165990229e97f) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:678](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L678) (Cmd_AddCommand)
- handler: [codemp/client/cl_console.cpp:88](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L88)
