---
title: "masterlist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `masterlist`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `masterlist <page (optional)>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`50d84d540837`](https://github.com/videoP/jaPRO/commit/50d84d54083775a21c419d4f1d511e755eb63e65) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-09-25`, integrated `2018-09-26`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2616](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_consolecmds.c#L2616)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-25` | — | `2018-09-26` | [`50d84d540837`](https://github.com/eternalcodes/EternalJK/commit/50d84d54083775a21c419d4f1d511e755eb63e65) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-25` | — | `2018-09-26` | [`50d84d540837`](https://github.com/taysta/TaystJK/commit/50d84d54083775a21c419d4f1d511e755eb63e65) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-25` | — | `2018-09-26` | [`50d84d540837`](https://github.com/videoP/jaPRO/commit/50d84d54083775a21c419d4f1d511e755eb63e65) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-25` | — | `2018-09-26` | [`50d84d540837`](https://github.com/JKSunny/EternalJK/commit/50d84d54083775a21c419d4f1d511e755eb63e65) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`6c1418ec48c8`](https://github.com/videoP/jaPRO/commit/6c1418ec48c8ca2af1162b077423bc5aee230d53)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2616](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2616) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9001](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L9001) (game command table)
- handler: [codemp/game/g_account.c:4043](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L4043)
