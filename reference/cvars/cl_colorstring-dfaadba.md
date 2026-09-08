---
title: "cl_colorString"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_colorString`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Bit value of selected colors in colorString, configure chat colors with /colorstring

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`9888b3f266ed`](https://github.com/eternalcodes/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) on `2016-03-21` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:3345](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3345)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-21` | [`9888b3f266ed`](https://github.com/eternalcodes/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-21` | [`9888b3f266ed`](https://github.com/taysta/TaystJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-21` | [`9888b3f266ed`](https://github.com/videoP/jaPRO/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-21` | [`9888b3f266ed`](https://github.com/JKSunny/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`665f3efab959`](https://github.com/eternalcodes/EternalJK/commit/665f3efab959840835590f67831876f2548ef418)<br>colorstring: saved code Forgot to save this code before pushing last commit | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b11b87c457d9`](https://github.com/eternalcodes/EternalJK/commit/b11b87c457d96f2571cea6ace8d33f934bff20ad)<br>CL_RandomizeColors: Don't randomize if only 1 color is selected | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6a99a7571a97`](https://github.com/eternalcodes/EternalJK/commit/6a99a7571a975cfc3a6697c0c41b839c65780198)<br>Improved /colorName + bugfixes /colorName works the same way as /colorString examples: /colorName -1 will remove all color from your name /colorName 10 will use all colors on your name /colorName 1 2 5 6 will color your name red, green, cyan, and magenta | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`cc95a484132f`](https://github.com/eternalcodes/EternalJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)<br>Added cvar cl_afkTimeUnfocused, Added Cvar/Cmd descriptions This will allow you to set the amount of minutes to autorename to afk while the jka window is unfocused or minimized. The default is 1 minute. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)<br>Implement Blackwolf's Discord Integration | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268)<br>chat styles | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3444](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3444) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:3037](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3037)
- behavior: [codemp/client/cl_main.cpp:3106](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3106)
- behavior: [codemp/client/cl_main.cpp:3132](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3132)
- behavior: [codemp/client/cl_main.cpp:3144](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3144)
- behavior: [codemp/client/cl_main.cpp:2438](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2438)
