---
title: "con_notifylines"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_notifylines`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Max number of console lines to print in top left

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Feature family | Console |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `3` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`012a635e93ad`](https://github.com/eternalcodes/EternalJK/commit/012a635e93ad5338bf9d24fb8401b400176d1431) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-09-11`, integrated `2018-09-11`)
- Upstream registration evidence: [codemp/client/cl_console.cpp:533](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L533)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-11` | — | `2018-09-11` | [`012a635e93ad`](https://github.com/eternalcodes/EternalJK/commit/012a635e93ad5338bf9d24fb8401b400176d1431) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-11` | — | `2018-09-11` | [`012a635e93ad`](https://github.com/taysta/TaystJK/commit/012a635e93ad5338bf9d24fb8401b400176d1431) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-11` | — | `2018-09-11` | [`012a635e93ad`](https://github.com/videoP/jaPRO/commit/012a635e93ad5338bf9d24fb8401b400176d1431) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-11` | — | `2018-09-11` | [`012a635e93ad`](https://github.com/JKSunny/EternalJK/commit/012a635e93ad5338bf9d24fb8401b400176d1431) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_console.cpp:651](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L651) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:924](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L924)
