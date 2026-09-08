---
title: "execq"
layout: reference
nav_exclude: true
search_exclude: false
---

# `execq`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Execute a script file without displaying a message

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `execq [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`e5d695df5bef`](https://github.com/JACoders/OpenJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) on `2013-07-11` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`649941d04db2`](https://github.com/taysta/TaystJK/commit/649941d04db2a0d5581825824a3b88a3912f3185)
- Upstream registration evidence: [code/qcommon/cmd.cpp:807](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cmd.cpp#L807)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2, newjk; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-07-11` | [`e5d695df5bef`](https://github.com/JACoders/OpenJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-07-11` | [`e5d695df5bef`](https://github.com/SomaZ/OpenJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-07-11` | [`e5d695df5bef`](https://github.com/jkanewmod/NewJK/commit/e5d695df5bef26c04d12e33d8488209ca1acd2ac) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-20` | [`649941d04db2`](https://github.com/eternalcodes/EternalJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-20` | [`649941d04db2`](https://github.com/taysta/TaystJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-20` | [`649941d04db2`](https://github.com/videoP/jaPRO/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-20` | [`649941d04db2`](https://github.com/JKSunny/EternalJK/commit/649941d04db2a0d5581825824a3b88a3912f3185) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/qcommon/cmd.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cmd.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/cmd.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cmd.cpp:1212](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L1212) (Cmd_AddCommand)
- handler: [codemp/qcommon/cmd.cpp:412](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cmd.cpp#L412)
