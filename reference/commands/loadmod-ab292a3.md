---
title: "loadmod"
layout: reference
nav_exclude: true
search_exclude: false
---

# `loadmod`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Restart the renderer (with specified mod folder) - or change the resolution

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
| In-game menu | Yes — [setup.menu:3136](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/setup.menu#L3136) |
| Syntax | `loadmod <folder name>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`04db4f373079`](https://github.com/eternalcodes/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-02-15`, integrated `2018-02-25`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3382](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3382)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-02-15` | — | `2018-02-25` | [`04db4f373079`](https://github.com/eternalcodes/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-02-15` | — | `2018-02-25` | [`04db4f373079`](https://github.com/taysta/TaystJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-02-15` | — | `2018-02-25` | [`04db4f373079`](https://github.com/videoP/jaPRO/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-02-15` | — | `2018-02-25` | [`04db4f373079`](https://github.com/JKSunny/EternalJK/commit/04db4f3730791a1497dc2c2df47a2a3d7b1ec704) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_main.cpp:3481](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3481) (Cmd_AddCommand)
- handler: [codemp/client/cl_main.cpp:1302](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L1302)
