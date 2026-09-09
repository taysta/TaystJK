---
title: "g_unlaggedProjectileTolerance"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_unlaggedProjectileTolerance`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_unlaggedProjectileTolerance` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `135` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`41c7e75be47a`](https://github.com/videoP/jaPRO/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2023-12-21`, integrated `2023-12-21`)
- Origin pull request: [#57](https://github.com/taysta/TaystJK/pull/57)
- Upstream registration evidence: [codemp/game/g_xcvar.h:278](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L278)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-12-21` | [2023-12-21](https://github.com/taysta/TaystJK/pull/57) | `2023-12-21` | [`41c7e75be47a`](https://github.com/taysta/TaystJK/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-12-21` | — | `2023-12-21` | [`41c7e75be47a`](https://github.com/videoP/jaPRO/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9e120086add8`](https://github.com/videoP/jaPRO/commit/9e120086add83f23befd7186ece215c286b943c8) · [PR #71](https://github.com/taysta/TaystJK/pull/71)<br>Japro update (#71) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `high` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:277](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L277) (XCVAR_DEF)
- behavior: [codemp/game/g_missile.c:385](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_missile.c#L385)
- behavior: [codemp/game/g_missile.c:1439](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_missile.c#L1439)
- behavior: [codemp/game/g_missile.c:386](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_missile.c#L386)
- behavior: [codemp/game/g_missile.c:1440](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_missile.c#L1440)
- behavior: [codemp/cgame/cg_weapons.c:2476](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L2476)
