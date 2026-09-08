---
title: "debugBMove_Right"
layout: reference
nav_exclude: true
search_exclude: false
---

# `debugBMove_Right`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_BotMoveRight_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `debugBMove_Right [arguments]` |
| Cheat protected | Yes |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_ALIVE`, `CMD_CHEAT`.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/game/g_cmds.c:3399](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_cmds.c#L3399)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | [`14cea1563762`](https://github.com/SomaZ/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | [`14cea1563762`](https://github.com/jkanewmod/NewJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_cmds.c:8950](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8950) (game command table)
- handler: [codemp/game/g_cmds.c:4704](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L4704)
