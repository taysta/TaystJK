---
title: "g_fixPlayerCollision"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixPlayerCollision`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixPlayerCollision` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/bg_slidemove.c:857](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_slidemove.c#L857) |
| `1` | Enabled. | [codemp/game/bg_slidemove.c:857](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_slidemove.c#L857) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2020-06-14`, integrated `2020-06-14`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:242](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L242)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2020-06-14` | — | `2020-06-14` | [`fb24d6a98965`](https://github.com/eternalcodes/EternalJK/commit/fb24d6a989657d508aa3c722e53dc203d6327e69) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2020-06-14` | — | `2020-06-14` | [`fb24d6a98965`](https://github.com/taysta/TaystJK/commit/fb24d6a989657d508aa3c722e53dc203d6327e69) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2020-06-14` | — | `2020-06-14` | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2020-06-14` | — | `2020-06-14` | [`fb24d6a98965`](https://github.com/JKSunny/EternalJK/commit/fb24d6a989657d508aa3c722e53dc203d6327e69) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/bg_slidemove.c`, `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:241](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L241) (XCVAR_DEF)
- behavior: [codemp/game/bg_slidemove.c:857](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_slidemove.c#L857)
- behavior: [codemp/game/g_cmds.c:8518](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8518)
- behavior: [codemp/game/g_cvar.c:95](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cvar.c#L95)
