---
title: "g_saberDisable"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_saberDisable`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Configured with /saberDisable command.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | No blue | [codemp/game/g_local.h:296](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L296) |
| `32` | Desann only | [codemp/game/g_local.h:301](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L301) |
| `64` | Tavion only | [codemp/game/g_local.h:302](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L302) |
| `2` | No yellow | [codemp/game/g_local.h:297](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L297) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-11-21`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:202](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L202)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-11-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-11-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-11-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-11-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |
| `2023-12-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bf81a8695ce`](https://github.com/videoP/jaPRO/commit/0bf81a8695ceaa3768496dfd4fe4e3a157016086)<br>Since jaPRO added MV_OCPM and MV_TRIBES after MV_COOP_JKA, we have to shuffle some things around. MV_COOP was originally designed to support multiple additional physics than just jka, but this never panned out. Need to revert this change if that design ever makes a comeback. | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |
| `2024-01-17` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c3293a76c178`](https://github.com/taysta/TaystJK/commit/c3293a76c1788eb104373f84a58a0219e5098bf5) · [PR #100](https://github.com/taysta/TaystJK/pull/100)<br>conc sniper uses energy like phase rifle, mortar  FX tweak, bounce strength (#100) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0683da475d2a`](https://github.com/videoP/jaPRO/commit/0683da475d2a4eda63a78a006bd7976adbcf7e85)<br>[jaPRO/Tribes] Fixup tribes check | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:201](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L201) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:3482](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L3482)
- behavior: [codemp/game/g_active.c:3505](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L3505)
- behavior: [codemp/game/g_active.c:3508](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L3508)
- behavior: [codemp/game/g_active.c:3512](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L3512)
- behavior: [codemp/game/g_active.c:3516](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L3516)
- documentation: [docs/japro_docs.md:21](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L21)
