---
title: "g_fixTimerOOB"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixTimerOOB`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixTimerOOB` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2020-05-10`, integrated `2020-05-16`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:354](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L354)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2020-05-10` | — | `2020-05-16` | [`0bfdb71aee77`](https://github.com/eternalcodes/EternalJK/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2020-05-10` | — | `2020-05-16` | [`0bfdb71aee77`](https://github.com/taysta/TaystJK/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2020-05-10` | — | `2020-05-16` | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2020-05-10` | — | `2020-05-16` | [`0bfdb71aee77`](https://github.com/JKSunny/EternalJK/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d) | Shared integration commit |

## Evidence

- registration: [codemp/game/g_xcvar.h:353](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L353) (XCVAR_DEF)
- behavior: [codemp/game/g_trigger.c:1467](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L1467)
- behavior: [codemp/game/g_trigger.c:1712](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L1712)
