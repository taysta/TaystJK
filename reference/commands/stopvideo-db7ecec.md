---
title: "stopvideo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `stopvideo`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Stop avi recording

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `stopvideo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) on `2013-04-13` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:2894](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2894)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/eternalcodes/EternalJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/SomaZ/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/taysta/TaystJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/videoP/jaPRO/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/jkanewmod/NewJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-13` | [`66642f7cd25a`](https://github.com/JKSunny/EternalJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-10-27` | [`bf4971ea0c0b`](https://github.com/mvdevs/jk2mv/commit/bf4971ea0c0bd55531047f8e8c4de709a0d64b56) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cccf3136bac2`](https://github.com/JACoders/OpenJK/commit/cccf3136bac26ff9af1548fbb98fa127947f31f5)<br>Merge pull request #324 from deepy/master | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2014-06-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fcc89fdf6fcb`](https://github.com/JACoders/OpenJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf)<br>[MP] Added addFavorite command to add the current or specified server to your favourites. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3498](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3498) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:2969](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2969)
