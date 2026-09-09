---
title: "afk"
layout: reference
nav_exclude: true
search_exclude: false
---

# `afk`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Rename to or from afk

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `afk` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`d0b29886a80d`](https://github.com/eternalcodes/EternalJK/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-03-05`, integrated `2016-03-05`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3401](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3401)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-05` | — | `2016-03-05` | [`d0b29886a80d`](https://github.com/eternalcodes/EternalJK/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-05` | — | `2016-03-05` | [`d0b29886a80d`](https://github.com/taysta/TaystJK/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-05` | — | `2016-03-05` | [`d0b29886a80d`](https://github.com/videoP/jaPRO/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-05` | — | `2016-03-05` | [`d0b29886a80d`](https://github.com/JKSunny/EternalJK/commit/d0b29886a80d60ad1ed079f29aa6cda560ebeede) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`71cc8ccbae52`](https://github.com/eternalcodes/EternalJK/commit/71cc8ccbae52c581c7e41a579d85b66e629b6878)<br>Add /colorstring command | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`09b3f68fcc6f`](https://github.com/eternalcodes/EternalJK/commit/09b3f68fcc6f09e1eceaf03dd9881005a74c2a53)<br>Automatic execution of afk cmd after x minutes Add cvar /cl_afkTime to adjust number of minutes | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e6ed053d8fa5`](https://github.com/eternalcodes/EternalJK/commit/e6ed053d8fa547a4e09b11d6708074bdc121edd4)<br>Improved Afk code | Changed the registered command handler. `codemp/client/cl_input.cpp`, `codemp/client/cl_main.cpp`, `codemp/client/client.h` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1cdc9fc78b3b`](https://github.com/eternalcodes/EternalJK/commit/1cdc9fc78b3b1980874dd25de036b23468ecfbf8)<br>Afk bugfix Accidentally deleted essential code in cl_input Added 5 second wait time before using afk cmd again. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ee1e5380b1db`](https://github.com/eternalcodes/EternalJK/commit/ee1e5380b1dbf34cc0a374d0522f71bcaac6db8c)<br>Execute afk on focus/unfocus | Changed the registered command handler. `shared/sdl/sdl_input.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b01a0a6ba02a`](https://github.com/eternalcodes/EternalJK/commit/b01a0a6ba02ad389f86be663857b77d164826c39)<br>Unfocus execute afk after 30 seconds | Changed the registered command handler. `shared/sdl/sdl_input.cpp` | `medium` |
| `2016-03-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b8696a7ad9f9`](https://github.com/eternalcodes/EternalJK/commit/b8696a7ad9f93b7dc3e4db632fbd16cf0e4b61f3)<br>Add chatlogs to engine raz0r's chatlog code re-purposed for engine | Changed the registered command handler. `codemp/client/client.h` | `medium` |
| `2016-03-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`844387592b09`](https://github.com/eternalcodes/EternalJK/commit/844387592b09da5ca3a2b0f2f69f0646cf04bc1e)<br>Reset afkTime when window is refocused | Changed the registered command handler. `shared/sdl/sdl_input.cpp` | `medium` |
| `2016-04-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`cc95a484132f`](https://github.com/eternalcodes/EternalJK/commit/cc95a484132f02cdf1f95e7abf47d49f809aa12f)<br>Added cvar cl_afkTimeUnfocused, Added Cvar/Cmd descriptions This will allow you to set the amount of minutes to autorename to afk while the jka window is unfocused or minimized. The default is 1 minute. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`652bd7e7bf18`](https://github.com/eternalcodes/EternalJK/commit/652bd7e7bf182e4e063ec9adb4294018f326345a)<br>define timestamp length, new prompt char, comments | Changed the registered command handler. `codemp/client/cl_input.cpp`, `codemp/client/cl_main.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c55cb9d28c23`](https://github.com/eternalcodes/EternalJK/commit/c55cb9d28c231c78a01be32ad62094f7f67f9c4f)<br>Engine chat logging - don't log "end log" message until something has been logged | Changed the registered command handler. `codemp/client/client.h` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8e7c210be049`](https://github.com/eternalcodes/EternalJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb)<br>Merge pull request #101 from eternalcodes/features/afkPrefix | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3500](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3500) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:3000](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3000)
