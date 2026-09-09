---
title: "g_KOTH"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_KOTH`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_KOTH` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| `0` | Disabled. | [codemp/game/g_trigger.c:3342](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L3342) |
| `1` | Enabled. | [codemp/game/g_trigger.c:3342](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L3342) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-09-01`, integrated `2018-09-03`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:281](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/game/g_xcvar.h#L281)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-01` | — | `2018-09-03` | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-01` | — | `2018-09-03` | [`6e78add659de`](https://github.com/taysta/TaystJK/commit/6e78add659de33e4919f25aefad3e61546599f3c) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-01` | — | `2018-09-03` | [`6e78add659de`](https://github.com/videoP/jaPRO/commit/6e78add659de33e4919f25aefad3e61546599f3c) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-01` | — | `2018-09-03` | [`6e78add659de`](https://github.com/JKSunny/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ead4104a15bf`](https://github.com/eternalcodes/EternalJK/commit/ead4104a15bfbafa08eb7fa158aada57041a08a1)<br>Added func_timer spawnflag to only spawn in KOTH gametype | Changed an exact bound cvar-variable reference. `codemp/game/g_trigger.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_trigger.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:286](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L286) (XCVAR_DEF)
- behavior: [codemp/game/g_trigger.c:3342](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L3342)
- behavior: [codemp/game/g_trigger.c:2642](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L2642)
