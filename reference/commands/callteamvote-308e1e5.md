---
title: "callteamvote"
layout: reference
nav_exclude: true
search_exclude: false
---

# `callteamvote`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Forwards this command to the connected game server.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `callteamvote [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:386](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_consolecmds.c#L386)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c`, `codemp/game/g_cmds.c` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`76633efaeb80`](https://github.com/JACoders/OpenJK/commit/76633efaeb807cc9c6389c026218f72cb3ea0db2)<br>[MP] Cleanup teamvoting a bit. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3a01147d3902`](https://github.com/JACoders/OpenJK/commit/3a01147d39020af50c7d7f3a9851e43d93df4ab1)<br>[MP] Correct BOF fixes in g_cmds.c | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`0f94802053dc`](https://github.com/JACoders/OpenJK/commit/0f94802053dc3d92ea12492a5ec0deac61bd86bd)<br>[MP] Use correct variable in callteamvote for checking player team validity. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-06` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ded5deaeb78d`](https://github.com/JACoders/OpenJK/commit/ded5deaeb78d7941cc82e467e89058688e4bfa01)<br>[MP] Actually set clientid in callteamvote. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-06` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dad539743c34`](https://github.com/JACoders/OpenJK/commit/dad539743c34dd2edff251a313fd78f6fc007946)<br>[MP] Actually set level.teamVoteStringClean[cs_offset] to level.teamVoteString[cs_offset]. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`99f68a293fef`](https://github.com/JACoders/OpenJK/commit/99f68a293fef762f6c6cf8ee76e2b0e21811c7c3)<br>[MP] Fixed a few issues with vote code from previous commits. Tweaked the team vote code to be a simplified but similar version of the new callvote code. Added g_allowTeamVote, defaulted to 1 cvar to toggle team voting. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `high` |
| `2023-10-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) · [PR #29](https://github.com/taysta/TaystJK/pull/29)<br>Merge pull request #29 from taysta/reconcile | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2573](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2573) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:8926](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8926) (game command table)
- handler: [codemp/game/g_cmds.c:3498](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3498)
