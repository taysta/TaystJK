---
title: "con_ratioFix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_ratioFix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Correct console background height, should probably disable for custom console backgrounds.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`952c06842ed0`](https://github.com/eternalcodes/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-10-21`, integrated `2018-10-21`)
- Upstream registration evidence: [codemp/client/cl_console.cpp:541](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_console.cpp#L541)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-21` | — | `2018-10-21` | [`952c06842ed0`](https://github.com/eternalcodes/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-21` | — | `2018-10-21` | [`952c06842ed0`](https://github.com/taysta/TaystJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-21` | — | `2018-10-21` | [`952c06842ed0`](https://github.com/videoP/jaPRO/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-21` | — | `2018-10-21` | [`952c06842ed0`](https://github.com/JKSunny/EternalJK/commit/952c06842ed0717365fb37927585d6498e7a77a0) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_console.cpp:659](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L659) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1069](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L1069)
