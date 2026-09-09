---
title: "colorstring"
layout: reference
nav_exclude: true
search_exclude: false
---

# `colorstring`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Color say text

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `colorstring` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`71cc8ccbae52`](https://github.com/eternalcodes/EternalJK/commit/71cc8ccbae52c581c7e41a579d85b66e629b6878) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-03-10`, integrated `2016-03-11`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3402](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3402)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-10` | — | `2016-03-11` | [`71cc8ccbae52`](https://github.com/eternalcodes/EternalJK/commit/71cc8ccbae52c581c7e41a579d85b66e629b6878) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-10` | — | `2016-03-11` | [`71cc8ccbae52`](https://github.com/taysta/TaystJK/commit/71cc8ccbae52c581c7e41a579d85b66e629b6878) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-10` | — | `2016-03-11` | [`71cc8ccbae52`](https://github.com/videoP/jaPRO/commit/71cc8ccbae52c581c7e41a579d85b66e629b6878) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-10` | — | `2016-03-11` | [`71cc8ccbae52`](https://github.com/JKSunny/EternalJK/commit/71cc8ccbae52c581c7e41a579d85b66e629b6878) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f1977d50a205`](https://github.com/eternalcodes/EternalJK/commit/f1977d50a205135abc2d0dbcb63cd176d080a624)<br>Add /colorname | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5a4be08b3711`](https://github.com/eternalcodes/EternalJK/commit/5a4be08b371106fc1753aea334adfc56317de22a)<br>CL_RandomizeColors bugfix | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9888b3f266ed`](https://github.com/eternalcodes/EternalJK/commit/9888b3f266ed8f8e677cb904cc9e36ce78a524d6)<br>Improved colorstring You can now specify more than one color at once. e.g. /colorString 1 2 5 6 will enabled red, green, cyan, magenta, and disable the rest Disabled all colors with /colorString -1 Enable all colors with /colorString 10 Randomize colors bugfix cl_stringColors now renamed to cl_colorString, cl_colorStringRandom | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`665f3efab959`](https://github.com/eternalcodes/EternalJK/commit/665f3efab959840835590f67831876f2548ef418)<br>colorstring: saved code Forgot to save this code before pushing last commit | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6a99a7571a97`](https://github.com/eternalcodes/EternalJK/commit/6a99a7571a975cfc3a6697c0c41b839c65780198)<br>Improved /colorName + bugfixes /colorName works the same way as /colorString examples: /colorName -1 will remove all color from your name /colorName 10 will use all colors on your name /colorName 1 2 5 6 will color your name red, green, cyan, and magenta | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`cc95a484132f`](https://github.com/eternalcodes/EternalJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)<br>Added cvar cl_afkTimeUnfocused, Added Cvar/Cmd descriptions This will allow you to set the amount of minutes to autorename to afk while the jka window is unfocused or minimized. The default is 1 minute. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c55cb9d28c23`](https://github.com/eternalcodes/EternalJK/commit/c55cb9d28c231c78a01be32ad62094f7f67f9c4f)<br>Engine chat logging - don't log "end log" message until something has been logged | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2023-11-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`47e33dfb6fd5`](https://github.com/taysta/TaystJK/commit/47e33dfb6fd55a1ae75888b7a33f056a8aba91ae) · [PR #53](https://github.com/taysta/TaystJK/pull/53)<br>Merge pull request #53 from taysta/daggo-misc | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3501](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3501) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:3033](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3033)
