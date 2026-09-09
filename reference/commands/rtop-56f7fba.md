---
title: "rTop"
layout: reference
nav_exclude: true
search_exclude: false
---

# `rTop`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `rTop <course (if needed)> <style (optional)> <season (optional - example: s1)> <page (optional)>. This displays the top10 for the specified course` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-01-22`, integrated `2018-02-05`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2376](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2376)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-01-22` | — | `2018-02-05` | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-01-22` | — | `2018-02-05` | [`675e97128f48`](https://github.com/taysta/TaystJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-01-22` | — | `2018-02-05` | [`675e97128f48`](https://github.com/videoP/jaPRO/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-01-22` | — | `2018-02-05` | [`675e97128f48`](https://github.com/JKSunny/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0e5a7eb8505b`](https://github.com/eternalcodes/EternalJK/commit/0e5a7eb8505b396272176c643666507e09b5ea22)<br>rtop fix | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`33d933ca5f12`](https://github.com/eternalcodes/EternalJK/commit/33d933ca5f122abf278f8f6fefc5607c5f2c3b20)<br>rtop season support / rtop rewrite / rtop fix | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`36883b3c51d2`](https://github.com/eternalcodes/EternalJK/commit/36883b3c51d265707d88d2af0ef8e366f94205c4)<br>make misc_teleporter_dest logical | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9fab37a47123`](https://github.com/eternalcodes/EternalJK/commit/9fab37a47123105c2bd13480a257e4d3d0c81621)<br>debug crash print | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`18440d16f155`](https://github.com/eternalcodes/EternalJK/commit/18440d16f15520bed3c547fc994f2ac8ec5a0b16)<br>rworst update .. ? | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3389f70a3c94`](https://github.com/eternalcodes/EternalJK/commit/3389f70a3c949e96798b495ca574c0994270c2dd)<br>Redo camera spec stuff, remove legacy client support for camerasettings/netsettings | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`bd2baec5d0cb`](https://github.com/eternalcodes/EternalJK/commit/bd2baec5d0cbef6f2908d4f9777f7880e444d772)<br>error print fix | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e9cc9f99e33c`](https://github.com/eternalcodes/EternalJK/commit/e9cc9f99e33cf51323270505b0c76cbf1b33dc8f)<br>database error prints to console | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2018-09-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8b3ccefa8978`](https://github.com/videoP/jaPRO/commit/8b3ccefa8978b455ac4ecfb70bd7ac2bf29c28e7)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2018-09-26` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`50d84d540837`](https://github.com/videoP/jaPRO/commit/50d84d54083775a21c419d4f1d511e755eb63e65)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2701](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2701) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9034](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L9034) (game command table)
- handler: [codemp/game/g_account.c:6292](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L6292)
