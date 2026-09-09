---
title: "cl_discordRichPresence"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_discordRichPresence`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Allow/disallow sharing current game information on Discord profile status

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
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_discordrpc.cpp:152](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L152) |
| `1` | Enabled. | [codemp/client/cl_discordrpc.cpp:152](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L152) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-03-19`, integrated `2019-03-19`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3360](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3360)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-19` | — | `2019-03-19` | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-19` | — | `2019-03-19` | [`1bcb29af6443`](https://github.com/taysta/TaystJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-19` | — | `2019-03-19` | [`1bcb29af6443`](https://github.com/videoP/jaPRO/commit/1bcb29af644349fd7a3acb14cc07ee634d168803) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-19` | — | `2019-03-19` | [`1bcb29af6443`](https://github.com/JKSunny/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad1655124ccf`](https://github.com/eternalcodes/EternalJK/commit/ad1655124ccf0e8663e0e33f02a8a9ffb9a275ff)<br>Discord lib handling cleanup | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`46ae589c3b8f`](https://github.com/eternalcodes/EternalJK/commit/46ae589c3b8f1ccdb105a4572bced18c1e12d671)<br>Show idle status (orange bubble) only when idle for 5+ minutes or if [AFK] tag has been set | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`580de0259290`](https://github.com/eternalcodes/EternalJK/commit/580de0259290c23ee3e410dc3772b373d118b3ff)<br>Discord status will show "Playing demo"/"Playing offline"/"Spectating on"/"Playing on" | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6c6472650cc`](https://github.com/eternalcodes/EternalJK/commit/f6c6472650ccd08fb0d010755094ab09ca8aced7)<br>Discord RPC integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6c98db92ff8c`](https://github.com/eternalcodes/EternalJK/commit/6c98db92ff8cf76433e303e2df90727a800c8ecd)<br>Remove pointless gametype argument from Discord status functions | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3459](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3459) (Cvar_Get); condition `defined(DISCORD) && !defined(_DEBUG)`
- behavior: [codemp/client/cl_discordrpc.cpp:152](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L152)
- behavior: [codemp/client/cl_discordrpc.cpp:225](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L225)
- behavior: [codemp/client/cl_discordrpc.cpp:246](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L246)
- behavior: [codemp/client/cl_discordrpc.cpp:474](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L474)
- behavior: [codemp/client/cl_discordrpc.cpp:485](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L485)
