---
title: "playdemo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `playdemo`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Playback a demo

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `playdemo [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`6107f5fbcf59`](https://github.com/eternalcodes/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-04-26`, integrated `2018-04-26`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3372](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3372)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/eternalcodes/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/taysta/TaystJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/videoP/jaPRO/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/JKSunny/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-04-26` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`a983fa494fee`](https://github.com/taysta/TaystJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b)<br>8 years too late, basic multiprotocol/multiversion support. | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`94672e48ece0`](https://github.com/eternalcodes/EternalJK/commit/94672e48ece0771144723030e011e2443c68a435)<br>add demo_restart | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |
| `2019-07-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`825d63b114ab`](https://github.com/eternalcodes/EternalJK/commit/825d63b114abfecc502c4136dc3ce4dad0e0841a)<br>Fix demo_restart+fix bugs in demo commands from 1.00 demo support | Changed the registered command handler. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3471](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3471) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:554](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L554)
