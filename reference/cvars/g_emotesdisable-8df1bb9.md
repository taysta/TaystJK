---
title: "g_emotesDisable"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_emotesDisable`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>toggleEmotes</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Configured with /toggleEmotes command

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
| Added | 2018-01-01 in [`d9d510063`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) <span class="status-chip">needs review</span> — [how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`toggleEmotes`](/TaystJK/reference/commands/toggleemotes-c7d169a/) |

## Bits

Toggle one with [`toggleEmotes`](/TaystJK/reference/commands/toggleemotes-c7d169a/) followed by the bit number. The value column is that bit on its own — [the labels come from the source table](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1532).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Beg | — |
| 1 | `2` | Breakdance | — |
| 2 | `4` | Cheer | — |
| 3 | `8` | Cower | — |
| 4 | `16` | Dance | — |
| 5 | `32` | Hug | — |
| 6 | `64` | Noisy | — |
| 7 | `128` | Point | — |
| 8 | `256` | Rage | — |
| 9 | `512` | Sit | — |
| 10 | `1024` | Surrender | — |
| 11 | `2048` | Smack | — |
| 12 | `4096` | Taunt | — |
| 13 | `8192` | Victory | — |
| 14 | `16384` | Jawa run | — |
| 15 | `32768` | Bernie | — |
| 16 | `65536` | Sleep | — |
| 17 | `131072` | Saberflip | — |
| 18 | `262144` | Slap | — |
| 19 | `524288` | Signal | — |
| 20 | `1048576` | Taunt/Flourish/Bow/Meditate outside of duel or while moving | — |
## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-01-11`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:300](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L300)
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
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a19ccb32a98d`](https://github.com/eternalcodes/EternalJK/commit/a19ccb32a98dbcd701d3ad151d744b2a7ccc3d63)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc10f7b67c56`](https://github.com/eternalcodes/EternalJK/commit/dc10f7b67c5611ae941cecbde51a85649a27c606)<br>Auto stash before rebase of "origin/master" | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:299](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L299) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:8500](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8500)
- behavior: [codemp/game/bg_pmove.c:8515](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8515)
- behavior: [codemp/game/bg_pmove.c:8530](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8530)
- behavior: [codemp/game/bg_pmove.c:8545](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8545)
- behavior: [codemp/game/bg_pmove.c:8560](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8560)
- documentation: [docs/japro_docs.md:91](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L91)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
