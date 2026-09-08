---
title: "move"
layout: reference
nav_exclude: true
search_exclude: false
---

# `move`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `move <siege, jka, qw, cpm, q3, pjk, wsw, rjq3, rjcpm, swoop, jetpack, speed, sp, slick, botcpm, coop, ocpm, tribes, or surf>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2388](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2388)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-02-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3f6908b4386d`](https://github.com/eternalcodes/EternalJK/commit/3f6908b4386df64512582eac4b4f72d959fc658d)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b5b028cdea55`](https://github.com/eternalcodes/EternalJK/commit/b5b028cdea555b87f8aaa340593cc0f219f5f601)<br>require alive for /move but put it after syntax check | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`36551a8dbf54`](https://github.com/eternalcodes/EternalJK/commit/36551a8dbf54012659febffe8f449788e9a56aac)<br>/move weapon change improvement? | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2018-10-23` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d4ab95e9cf64`](https://github.com/videoP/jaPRO/commit/d4ab95e9cf64fee79c07ea6f68416b0369e3835a)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9e120086add8`](https://github.com/videoP/jaPRO/commit/9e120086add83f23befd7186ece215c286b943c8) · [PR #71](https://github.com/taysta/TaystJK/pull/71)<br>Japro update (#71) | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2024-01-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a5c04e80d08f`](https://github.com/videoP/jaPRO/commit/a5c04e80d08fb4398d8ddc5fbcb9121bf4d7f8bd) · [PR #127](https://github.com/taysta/TaystJK/pull/127)<br>Japro updates (#127) | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2024-04-06` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`159821bdb1e0`](https://github.com/taysta/TaystJK/commit/159821bdb1e09d9265fa8313173521ae62ab15d3) · [PR #186](https://github.com/taysta/TaystJK/pull/186)<br>Upstream update (#186) | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2713](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2713) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9004](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L9004) (game command table)
- handler: [codemp/game/g_cmds.c:6687](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L6687)
