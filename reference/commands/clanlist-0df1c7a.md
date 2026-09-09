---
title: "clanList"
layout: reference
nav_exclude: true
search_exclude: false
---

# `clanList`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `clanList <page (optional)>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-08-08`, integrated `2018-08-20`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2286](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2286)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/taysta/TaystJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/videoP/jaPRO/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/JKSunny/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2018-10-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`6c1418ec48c8`](https://github.com/videoP/jaPRO/commit/6c1418ec48c8ca2af1162b077423bc5aee230d53)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2611](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2611) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:8937](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8937) (game command table)
- handler: [codemp/game/g_account.c:4121](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L4121)
