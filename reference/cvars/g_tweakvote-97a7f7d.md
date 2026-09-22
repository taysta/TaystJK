---
title: "g_tweakVote"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_tweakVote`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>tweakVote</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Latch cuz of calculateRanks? not sure man

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
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`tweakVote`](/TaystJK/reference/commands/tweakvote-97236e2/) |

## Bits

Use [`tweakVote`](/TaystJK/reference/commands/tweakvote-97236e2/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own — [the labels come from the source table](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1473).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Allow spec callvote in siege gametype | [codemp/game/g_local.h:333](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L333) |
| 1 | `2` | Allow spec callvote in CTF/TFFA gametypes | — |
| 2 | `4` | Clear vote when going to spectate | [codemp/game/g_local.h:335](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L335) |
| 3 | `8` | Dont allow callvote for 30s after mapload | [codemp/game/g_local.h:336](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L336) |
| 4 | `16` | Floodprotect callvotes by IP | — |
| 5 | `32` | Dont allow map callvotes for 10 minutes at start of each map | — |
| 6 | `64` | Add vote delay for map callvotes only | — |
| 7 | `128` | Allow voting from spectate | — |
| 8 | `256` | Show votes in console | — |
| 9 | `512` | Only count voters in pass/fail calculation | — |
| 10 | `1024` | Fix mapchange after gametype vote | — |
| 11 | `2048` | Ignore gametype restrictions for map callvote | [codemp/game/g_local.h:344](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L344) |
## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2015-04-29`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:310](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L310)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-29` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-29` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-29` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-29` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a19ccb32a98d`](https://github.com/eternalcodes/EternalJK/commit/a19ccb32a98dbcd701d3ad151d744b2a7ccc3d63)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:309](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L309) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:1488](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L1488)
- behavior: [codemp/game/g_cmds.c:2746](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L2746)
- behavior: [codemp/game/g_cmds.c:2917](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L2917)
- behavior: [codemp/game/g_cmds.c:3146](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3146)
- behavior: [codemp/game/g_cmds.c:3165](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3165)
- documentation: [docs/japro_docs.md:110](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L110)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
