---
title: "g_startingWeapons"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_startingWeapons`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>startingWeapons</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Start with saber only default, fall back to melee if no saberattack

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
| Default | `8` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`startingWeapons`](/TaystJK/reference/commands/startingweapons-7252a71/) |

## Bits

Use [`startingWeapons`](/TaystJK/reference/commands/startingweapons-7252a71/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own. [The labels come from the source table](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_svcmds.c#L1120).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 1 | `2` | Stun Baton | — |
| 2 | `4` | Melee | — |
| 3 | `8` | Saber | — |
| 4 | `16` | Bryar Pistol | — |
| 5 | `32` | Blaster | — |
| 6 | `64` | Disruptor | — |
| 7 | `128` | Bowcaster | — |
| 8 | `256` | Repeater | — |
| 9 | `512` | Demp2 | — |
| 10 | `1024` | Flechette | — |
| 11 | `2048` | Rocket Launcher | — |
| 12 | `4096` | Thermal | — |
| 13 | `8192` | Trip Mine | — |
| 14 | `16384` | Det Pack | — |
| 15 | `32768` | Concussion Rifle | — |
| 16 | `65536` | Old Bryar Pistol | — |
## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-01-11`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:220](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L220)
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
| `2018-09-03` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_svcmds.c` | `medium` |
| `2018-09-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd)<br>Added jcinfo2 to allow UI to only show Race button when relevant | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_main.c` | `high` |
| `2023-12-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`06c84155e1fb`](https://github.com/videoP/jaPRO/commit/06c84155e1fb0b3aecfdffd9488d910345d80ea1) · [PR #65](https://github.com/taysta/TaystJK/pull/65)<br>Japro fixup (#65) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `high` |
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |
| `2024-01-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) · [PR #95](https://github.com/taysta/TaystJK/pull/95)<br>Japro update (#95) | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:219](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_xcvar.h#L219) (XCVAR_DEF)
- behavior: [codemp/game/g_client.c:3860](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_client.c#L3860)
- behavior: [codemp/game/g_client.c:3865](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_client.c#L3865)
- behavior: [codemp/game/g_client.c:3867](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_client.c#L3867)
- behavior: [codemp/game/g_client.c:3869](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_client.c#L3869)
- behavior: [codemp/game/g_client.c:3871](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_client.c#L3871)
- documentation: [docs/japro_docs.md:39](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/docs/japro_docs.md#L39)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
