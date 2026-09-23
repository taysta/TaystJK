---
title: "clanCreate"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `clanCreate`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-08-19 in [`fa2b5ba68`](https://github.com/taysta/TaystJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `clanCreate <name>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`fa2b5ba6883b`](https://github.com/videoP/jaPRO/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-08-08`, integrated `2018-08-20`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2607](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_consolecmds.c#L2607)
- Attribution method: `shared-earliest-commit-module-lineage`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; module lineage selects japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/taysta/TaystJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/videoP/jaPRO/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-08-08` | — | `2018-08-20` | [`fa2b5ba6883b`](https://github.com/JKSunny/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2607](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L2607) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:8932](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L8932) (game command table)
- registration: [codemp/game/g_svcmds.c:1663](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L1663) (game-console command table)
- handler: [codemp/game/g_account.c:3770](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3770)
- handler: [codemp/game/g_account.c:3167](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3167)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
