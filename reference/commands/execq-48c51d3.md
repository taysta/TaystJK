---
title: "execq"
layout: reference
nav_exclude: true
search_exclude: false
---

# `execq`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Execute a script file without displaying a message

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `execq [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`649941d04db2`](https://github.com/eternalcodes/EternalJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2013-04-05`, integrated `2014-01-20`)
- Upstream registration evidence: [codemp/qcommon/cmd.cpp:1018](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/cmd.cpp#L1018)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: eternaljk retains origin because content authorship and PR submission predate the project that merged the work first. The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-05` | — | `2014-01-20` | [`649941d04db2`](https://github.com/eternalcodes/EternalJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-05` | — | `2014-01-20` | [`649941d04db2`](https://github.com/taysta/TaystJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-05` | — | `2014-01-20` | [`649941d04db2`](https://github.com/videoP/jaPRO/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-05` | — | `2014-01-20` | [`649941d04db2`](https://github.com/JKSunny/EternalJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Shared integration commit |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-07-11` | — | `2013-07-11` | [`e5d695df5bef`](https://github.com/JACoders/OpenJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-07-11` | — | `2013-07-11` | [`e5d695df5bef`](https://github.com/SomaZ/OpenJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-07-11` | — | `2013-07-11` | [`e5d695df5bef`](https://github.com/jkanewmod/NewJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e5d695df5bef`](https://github.com/JACoders/OpenJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac)<br>Merged some MP fixes to cmd code for SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cmd.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/qcommon/cmd.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cmd.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cmd.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cmd.cpp:1212](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cmd.cpp#L1212) (Cmd_AddCommand)
- handler: [codemp/qcommon/cmd.cpp:412](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cmd.cpp#L412)
