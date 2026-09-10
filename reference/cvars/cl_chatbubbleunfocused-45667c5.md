---
title: "cl_chatBubbleUnfocused"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_chatBubbleUnfocused`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_chatBubbleUnfocused` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_input.cpp:1264](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1264) |
| `1` | Enabled. | [codemp/client/cl_input.cpp:1264](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1264) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`86f04849f381`](https://github.com/taysta/TaystJK/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-04-19`, PR opened `2026-04-18`, integrated `2026-04-19`)
- Origin pull request: [#302](https://github.com/taysta/TaystJK/pull/302)
- Upstream registration evidence: [codemp/client/cl_input.cpp:1834](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1834)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-04-19` | [2026-04-18](https://github.com/taysta/TaystJK/pull/302) | `2026-04-19` | [`86f04849f381`](https://github.com/taysta/TaystJK/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-04-19` | — | `2026-04-19` | [`86f04849f381`](https://github.com/videoP/jaPRO/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_input.cpp:1834](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1834) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1264](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1264)
