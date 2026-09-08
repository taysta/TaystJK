---
title: "addFavorite"
layout: reference
nav_exclude: true
search_exclude: false
---

# `addFavorite`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Add server to favorites

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `addFavorite [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`fcc89fdf6fcb`](https://github.com/JACoders/OpenJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) on `2014-06-28` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:2870](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2870)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/JACoders/OpenJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/eternalcodes/EternalJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/SomaZ/OpenJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/taysta/TaystJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/videoP/jaPRO/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/jkanewmod/NewJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-06-28` | [`fcc89fdf6fcb`](https://github.com/JKSunny/EternalJK/commit/fcc89fdf6fcbf169f22e9ed77cd632d8637a3dbf) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d0b29886a80d`](https://github.com/eternalcodes/EternalJK/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede)<br>Move "afk" cmd from cgame to client | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e6ed053d8fa5`](https://github.com/eternalcodes/EternalJK/commit/e6ed053d8fa547a4e09b11d6708074bdc121edd4)<br>Improved Afk code | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3467](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3467) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:2974](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2974)
