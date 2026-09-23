---
title: "ysal"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ysal`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-10-10 in [`2af38213b`](https://github.com/taysta/TaystJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame_setup.menu:3059](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame_setup.menu#L3059), [ingame_setup.menu:3070](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame_setup.menu#L3070) |
| Syntax | `ysal` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`2af38213b793`](https://github.com/videoP/jaPRO/commit/2af38213b793183fd6313a195d0f36ea3aa02196) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-10-07`, integrated `2018-10-10`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2721](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_consolecmds.c#L2721)
- Attribution method: `shared-earliest-commit-module-lineage`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; module lineage selects japro. The squash feature group broadly credits eternaljk, but non-identifier-specific credit does not override the japro game-module provider lineage.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-07` | — | `2018-10-10` | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-07` | — | `2018-10-10` | [`2af38213b793`](https://github.com/taysta/TaystJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-07` | — | `2018-10-10` | [`2af38213b793`](https://github.com/videoP/jaPRO/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-07` | — | `2018-10-10` | [`2af38213b793`](https://github.com/JKSunny/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293)<br>cosmetics | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2019-02-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d78437b0c615`](https://github.com/eternalcodes/EternalJK/commit/d78437b0c6152aa36c88470e48f731e51d35e335)<br>Fix /ysal command doing nothing with high servertime. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2024-01-25` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cd07288a30a6`](https://github.com/videoP/jaPRO/commit/cd07288a30a6aa276afdb11f1ae81e5e338134c3) · [PR #116](https://github.com/taysta/TaystJK/pull/116)<br>Japro updates (#116) | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2721](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L2721) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9080](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L9080) (game command table)
- handler: [codemp/game/g_cmds.c:7006](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L7006)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
