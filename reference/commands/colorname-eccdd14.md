---
title: "colorname"
layout: reference
nav_exclude: true
search_exclude: false
---

# `colorname`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Color name

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `colorname` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`f1977d50a205`](https://github.com/eternalcodes/EternalJK/commit/f1977d50a205135abc2d0dbcb63cd176d080a624) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-03-11`, integrated `2016-03-11`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3403](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3403)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-11` | — | `2016-03-11` | [`f1977d50a205`](https://github.com/eternalcodes/EternalJK/commit/f1977d50a205135abc2d0dbcb63cd176d080a624) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-11` | — | `2016-03-11` | [`f1977d50a205`](https://github.com/taysta/TaystJK/commit/f1977d50a205135abc2d0dbcb63cd176d080a624) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-11` | — | `2016-03-11` | [`f1977d50a205`](https://github.com/videoP/jaPRO/commit/f1977d50a205135abc2d0dbcb63cd176d080a624) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-11` | — | `2016-03-11` | [`f1977d50a205`](https://github.com/JKSunny/EternalJK/commit/f1977d50a205135abc2d0dbcb63cd176d080a624) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5a4be08b3711`](https://github.com/eternalcodes/EternalJK/commit/5a4be08b371106fc1753aea334adfc56317de22a)<br>CL_RandomizeColors bugfix | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6a99a7571a97`](https://github.com/eternalcodes/EternalJK/commit/6a99a7571a975cfc3a6697c0c41b839c65780198)<br>Improved /colorName + bugfixes /colorName works the same way as /colorString examples: /colorName -1 will remove all color from your name /colorName 10 will use all colors on your name /colorName 1 2 5 6 will color your name red, green, cyan, and magenta | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`cc95a484132f`](https://github.com/eternalcodes/EternalJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)<br>Added cvar cl_afkTimeUnfocused, Added Cvar/Cmd descriptions This will allow you to set the amount of minutes to autorename to afk while the jka window is unfocused or minimized. The default is 1 minute. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3502](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3502) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:3157](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3157)
