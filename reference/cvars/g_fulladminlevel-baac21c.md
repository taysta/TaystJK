---
title: "g_fullAdminLevel"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fullAdminLevel`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fullAdminLevel` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1048576` | Enables the `JAPRO_ACCOUNTFLAG_A_CALLVOTE` code path. | [codemp/game/g_local.h:368](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L368) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:264](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L264)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |

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

- registration: [codemp/game/g_xcvar.h:263](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L263) (XCVAR_DEF)
- behavior: [codemp/game/g_account.c:7086](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L7086)
- behavior: [codemp/game/g_account.c:7203](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L7203)
- behavior: [codemp/game/g_cmds.c:3151](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L3151)
- behavior: [codemp/game/g_cmds.c:4932](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L4932)
- behavior: [codemp/game/g_svcmds.c:794](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L794)
