---
title: "which"
layout: reference
nav_exclude: true
search_exclude: false
---

# `which`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Determines which search path a file was loaded from

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `which <file>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`924f4bc4fbf3`](https://github.com/JACoders/OpenJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-12-24`, integrated `2013-12-24`)
- Upstream registration evidence: [code/qcommon/files.cpp:2953](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/files.cpp#L2953)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/JACoders/OpenJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/eternalcodes/EternalJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/SomaZ/OpenJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/taysta/TaystJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/videoP/jaPRO/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/jkanewmod/NewJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-12-24` | — | `2013-12-24` | [`924f4bc4fbf3`](https://github.com/JKSunny/EternalJK/commit/924f4bc4fbf3bbb84b6347d594d3f5daf475accb) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2017-03-21` | — | `2017-05-21` | [`7cfae89649be`](https://github.com/mvdevs/jk2mv/commit/7cfae89649bede30767270ffdbb9471cb52cb2f3) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/qcommon/files.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2018-02-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8a3b2a103496`](https://github.com/eternalcodes/EternalJK/commit/8a3b2a103496fd2963486763c68b24c22dec3da3)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed the registered command handler. `codemp/qcommon/files.cpp` | `medium` |
| `2018-04-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ae94795c1054`](https://github.com/eternalcodes/EternalJK/commit/ae94795c1054dce8a4b8aa1dffabe45afaf09550)<br>Ignore searchpaths outside of base/EternalJK, fs_globalcfg 0 can be set | Changed the registered command handler. `codemp/qcommon/files.cpp` | `high` |
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed the registered command handler. `codemp/qcommon/files.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed the registered command handler. `codemp/qcommon/files.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/files.cpp:4008](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4008) (Cmd_AddCommand)
- handler: [codemp/qcommon/files.cpp:3267](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3267)
