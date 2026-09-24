---
title: "g_fullAdminLevel"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_fullAdminLevel`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>toggleAdmin</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Controls `g_fullAdminLevel` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Administration |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-01-01 in [`d9d510063`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/) |

## Bits

Use [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own. [The labels come from the source table](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_svcmds.c#L1305).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Amtele | — |
| 1 | `2` | Amfreeze | — |
| 2 | `4` | Amtelemark | — |
| 3 | `8` | Amban | — |
| 4 | `16` | Amkick | — |
| 5 | `32` | NPC | — |
| 6 | `64` | Noclip | — |
| 7 | `128` | Grantadmin | — |
| 8 | `256` | Ammap | — |
| 9 | `512` | Ampsay | — |
| 10 | `1024` | Amforceteam | — |
| 11 | `2048` | Amlockteam | — |
| 12 | `4096` | Amvstr | — |
| 13 | `8192` | See IPs | — |
| 14 | `16384` | Amrename | — |
| 15 | `32768` | Amlistmaps | — |
| 16 | `65536` | Amwhois | — |
| 17 | `131072` | Amlookup | — |
| 18 | `262144` | Use hide | — |
| 19 | `524288` | See hiders | — |
| 20 | `1048576` | Callvote | [codemp/game/g_local.h:368](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_local.h#L368) |
| 21 | `2097152` | Killvote | — |
| 22 | `4194304` | Read Amsay | — |
## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-01-11`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:264](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L264)
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
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2018-10-19` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`96eedd5acfa3`](https://github.com/videoP/jaPRO/commit/96eedd5acfa332586ef51dde7189ed07dd7bc9ff)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2018-10-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fd6d6b298cf8`](https://github.com/videoP/jaPRO/commit/fd6d6b298cf88dd88a787cf5d2cabc23930969cd)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_cmds.c` | `high` |
| `2018-11-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3d1c26c449c5`](https://github.com/videoP/jaPRO/commit/3d1c26c449c5a5f9cd94245e51850a04cd49cab0)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2018-11-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`4bbb14b56d12`](https://github.com/videoP/jaPRO/commit/4bbb14b56d12beddb3de30294fef6127beaeecc7)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_cmds.c`, `codemp/game/g_svcmds.c` | `high` |
| `2018-12-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`77bd5c24613a`](https://github.com/videoP/jaPRO/commit/77bd5c24613aa6a20828308d1ce31676068972a4)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:263](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_xcvar.h#L263) (XCVAR_DEF)
- behavior: [codemp/game/g_account.c:7086](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_account.c#L7086)
- behavior: [codemp/game/g_account.c:7203](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_account.c#L7203)
- behavior: [codemp/game/g_cmds.c:3151](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_cmds.c#L3151)
- behavior: [codemp/game/g_cmds.c:4932](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_cmds.c#L4932)
- behavior: [codemp/game/g_svcmds.c:794](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_svcmds.c#L794)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
