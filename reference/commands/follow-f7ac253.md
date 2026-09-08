---
title: "follow"
layout: reference
nav_exclude: true
search_exclude: false
---

# `follow`

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
| Syntax | `follow [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`, `sent-to-server`.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:380](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_consolecmds.c#L380)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_consolecmds.c` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-08-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3c1257cfd1c1`](https://github.com/JACoders/OpenJK/commit/3c1257cfd1c1afb015cb4d26f1647331086045d7)<br>Fixed fast teamswitch bypass exploit with follow commands. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2013-10-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e8532d590b97`](https://github.com/JACoders/OpenJK/commit/e8532d590b9752bd4a0359e714a31bd07baf6ef6)<br>[MP] Style: spelling mistakes | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2014-01-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`741e00ba61cc`](https://github.com/JACoders/OpenJK/commit/741e00ba61ccd01f7a2faa25d50ea7fa45a9559e)<br>[MP] Allow callvote kick to kick connecting clients. Clean up kickother and giveother commands.  Plus allow them to work even if the host command caller is not alive. | Changed the registered command handler. `codemp/game/g_cmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_cmds.c` | `high` |
| `2018-10-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`116fd88bcf51`](https://github.com/videoP/jaPRO/commit/116fd88bcf51c2c7e504191b5878cf04e50d6357)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `high` |
| `2019-05-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0bfc49840b96`](https://github.com/eternalcodes/EternalJK/commit/0bfc49840b965a25eaec86eb88f4f51d8dfb095b)<br>Add cgame /follow command that uses player name/clientNum as argument. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2019-06-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`96fd54d4bc38`](https://github.com/eternalcodes/EternalJK/commit/96fd54d4bc38f21aa828a1cfda03dbf6b972ea18)<br>Remove unused CG_CalcFovFromX function, move CG_ZoomDown/Up_f functions | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2501](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2501) (cgame command table)
- registration: [codemp/cgame/cg_consolecmds.c:2576](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2576) (forwarded client command table)
- registration: [codemp/game/g_cmds.c:8970](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8970) (game command table)
- handler: [codemp/cgame/cg_consolecmds.c:639](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L639)
- handler: [codemp/game/g_cmds.c:1980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L1980)
