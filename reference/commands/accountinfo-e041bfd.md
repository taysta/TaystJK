---
title: "accountInfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `accountInfo`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_AccountInfo_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `accountInfo <username>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-08-21`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_svcmds.c:1640](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_svcmds.c#L1640)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-08-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-08-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-08-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-08-21` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a19ccb32a98d`](https://github.com/eternalcodes/EternalJK/commit/a19ccb32a98dbcd701d3ad151d744b2a7ccc3d63)<br>Merge remote-tracking branch 'videoP/master' | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`bd2baec5d0cb`](https://github.com/eternalcodes/EternalJK/commit/bd2baec5d0cbef6f2908d4f9777f7880e444d772)<br>error print fix | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e9cc9f99e33c`](https://github.com/eternalcodes/EternalJK/commit/e9cc9f99e33cf51323270505b0c76cbf1b33dc8f)<br>database error prints to console | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |

## Evidence

- registration: [codemp/game/g_svcmds.c:1641](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1641) (game-console command table)
- handler: [codemp/game/g_account.c:2761](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L2761)
