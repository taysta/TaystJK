---
title: "g_newVehicleDamageScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_newVehicleDamageScale`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_newVehicleDamageScale` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`3567d72d98c5`](https://github.com/videoP/jaPRO/commit/3567d72d98c5b41549e76ef6e4841bb14c318fba) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2023-12-28`, integrated `2023-12-28`)
- Origin pull request: [#64](https://github.com/taysta/TaystJK/pull/64)
- Matching squash bullet: `g_newVehicleDamageScale`
- Upstream registration evidence: [codemp/game/g_xcvar.h:289](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L289)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-12-28` | [2023-12-28](https://github.com/taysta/TaystJK/pull/64) | `2023-12-28` | [`3567d72d98c5`](https://github.com/taysta/TaystJK/commit/3567d72d98c5b41549e76ef6e4841bb14c318fba) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-12-28` | — | `2023-12-28` | [`3567d72d98c5`](https://github.com/videoP/jaPRO/commit/3567d72d98c5b41549e76ef6e4841bb14c318fba) | Ultimate origin |

## Evidence

- registration: [codemp/game/g_xcvar.h:288](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L288) (XCVAR_DEF)
- behavior: [codemp/game/bg_slidemove.c:466](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_slidemove.c#L466)
- behavior: [codemp/game/bg_slidemove.c:473](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_slidemove.c#L473)
