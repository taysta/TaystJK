---
title: "g_autoQuit"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_autoQuit`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_autoQuit` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_main.c:3566](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3566) |
| `1` | Enabled. | [codemp/game/g_main.c:3566](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3566) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-10-09`, integrated `2018-10-10`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:312](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/game/g_xcvar.h#L312)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/taysta/TaystJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/videoP/jaPRO/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-09` | — | `2018-10-10` | [`2af38213b793`](https://github.com/JKSunny/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:318](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L318) (XCVAR_DEF)
- behavior: [codemp/game/g_main.c:3566](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3566)
- behavior: [codemp/game/g_main.c:3567](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L3567)
