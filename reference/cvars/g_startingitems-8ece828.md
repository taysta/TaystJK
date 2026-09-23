---
title: "g_startingItems"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_startingItems`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>startingItems</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Configured with /startingItems command.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-01-01 in [`d9d510063`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`startingItems`](/TaystJK/reference/commands/startingitems-2ed82fa/) |

## Bits

Use [`startingItems`](/TaystJK/reference/commands/startingitems-2ed82fa/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own. [The labels come from the source table](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L1188).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 1 | `2` | Seeker | — |
| 2 | `4` | Shield | — |
| 3 | `8` | Bacta | — |
| 4 | `16` | Big Bacta | — |
| 5 | `32` | Binoculars | — |
| 6 | `64` | Sentry Gun | — |
| 7 | `128` | Jetpack | — |
| 8 | `256` | Health Dispenser | — |
| 9 | `512` | Ammo Dispenser | — |
| 10 | `1024` | E-WEB | — |
| 11 | `2048` | Cloak | — |
| 12 | `4096` | Ability to toggle /jetpack | — |
| 13 | `8192` | Start with armor in duel gametype | — |
| 14 | `16384` | Start with full armor in FFA | — |
| 15 | `32768` | Start with full health after each kill | — |
## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-01-11`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:275](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L275)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_combat.c` | `high` |
| `2024-01-06` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`668338988def`](https://github.com/videoP/jaPRO/commit/668338988def7a28cb6cfbf9ffb8d3848a391662) · [PR #79](https://github.com/taysta/TaystJK/pull/79)<br>Japro update (#79) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `high` |
| `2024-03-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9912f30e367f`](https://github.com/taysta/TaystJK/commit/9912f30e367f9857bb65dc3047f77fd1b325ad4b) · [PR #166](https://github.com/taysta/TaystJK/pull/166)<br>Japro update (#166) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:274](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_xcvar.h#L274) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:9017](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/ai_main.c#L9017)
- behavior: [codemp/game/g_client.c:3607](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_client.c#L3607)
- behavior: [codemp/game/g_client.c:3609](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_client.c#L3609)
- behavior: [codemp/game/g_client.c:3611](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_client.c#L3611)
- behavior: [codemp/game/g_client.c:3613](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_client.c#L3613)
- documentation: [docs/japro_docs.md:85](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/docs/japro_docs.md#L85)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
