---
title: "stats"
layout: reference
nav_exclude: true
search_exclude: false
---

# `stats`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Rename to info?

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `stats <username> <type (optional - example: race/combat)> <page (optional)>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:388](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_consolecmds.c#L388)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `medium` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `high` |
| `2018-09-26` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`50d84d540837`](https://github.com/videoP/jaPRO/commit/50d84d54083775a21c419d4f1d511e755eb63e65)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_account.c`, `codemp/game/g_cmds.c` | `high` |
| `2018-10-19` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`96eedd5acfa3`](https://github.com/videoP/jaPRO/commit/96eedd5acfa332586ef51dde7189ed07dd7bc9ff)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed the registered command handler. `codemp/game/g_account.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed the registered command handler. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2592](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2592) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:9051](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L9051) (game command table)
- handler: [codemp/game/g_account.c:4523](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L4523)
