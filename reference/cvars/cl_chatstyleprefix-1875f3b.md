---
title: "cl_chatStylePrefix"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_chatStylePrefix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

String inserted before sent chat messages

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-06-13`, integrated `2019-06-13`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3349](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3349)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-06-13` | — | `2019-06-13` | [`986358853af6`](https://github.com/eternalcodes/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-06-13` | — | `2019-06-13` | [`986358853af6`](https://github.com/taysta/TaystJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-06-13` | — | `2019-06-13` | [`986358853af6`](https://github.com/videoP/jaPRO/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-06-13` | — | `2019-06-13` | [`986358853af6`](https://github.com/JKSunny/EternalJK/commit/986358853af67b06b0e3b1457f9a3f124cc70268) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_main.cpp:3448](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3448) (Cvar_Get)
- behavior: [codemp/client/cl_keys.cpp:1027](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L1027)
- behavior: [codemp/client/cl_keys.cpp:1028](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L1028)
