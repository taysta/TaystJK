---
title: "cg_drawTeamOverlay"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawTeamOverlay`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Draw the team overlay for team-based gametypes

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | The team overlay is not drawn | [codemp/ui/ui_xdocs.h:133](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L133) |
| `1` | The team overlay is drawn | [codemp/ui/ui_xdocs.h:133](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L133) |
| `2` | The team overlay is drawn, excluding the local client | [codemp/ui/ui_xdocs.h:134](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L134) |
| `3` | The new team overlay is drawn | [codemp/ui/ui_xdocs.h:135](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L135) |
| `4` | The new team overlay is drawn, excluding the local client | [codemp/ui/ui_xdocs.h:136](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L136) |
| `5` | The vertical team overlay is drawn | [codemp/ui/ui_xdocs.h:138](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L138) |
| `6` | The vertical team overlay is drawn, excluding the local client | [codemp/ui/ui_xdocs.h:138](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L138) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:1005](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L1005)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2014-03-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6f4aadcbd269`](https://github.com/JACoders/OpenJK/commit/6f4aadcbd269b386afc086854ec26e3f3fa5fa0f)<br>[MP] CGame: Moved some cvar code to cg_cvar.c | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_cvar.c` | `medium` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2022-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`72f6921bb38a`](https://github.com/taysta/TaystJK/commit/72f6921bb38aedb0d0fed368a3c35af162947686)<br>hud/timer tweaks | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`81882b7ee881`](https://github.com/taysta/TaystJK/commit/81882b7ee8819e82f5308bf66d08fd2b7040aa35)<br>#13 new team overlays - cg_drawTeamOverlay 3/4 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c1db680833db`](https://github.com/taysta/TaystJK/commit/c1db680833db71f79af222d5cbecf2fe772f316d) · [PR #257](https://github.com/taysta/TaystJK/pull/257)<br>Merge pull request #257 from VincentMarnier/fix_drawteamoverlay2 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`bc7b9fb3a9e9`](https://github.com/taysta/TaystJK/commit/bc7b9fb3a9e9c3e2d18bf40111324aa801067ce8) · [PR #258](https://github.com/taysta/TaystJK/pull/258)<br>Merge pull request #258 from taysta/teamoverlay-new | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2026-08-06` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`17085eaeadd0`](https://github.com/taysta/TaystJK/commit/17085eaeadd029b670346330588de005c6c41158) · [PR #356](https://github.com/taysta/TaystJK/pull/356)<br>Merge pull request #356 from taysta/teamoverlay3 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/ui/ui_xdocs.h` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:53](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L53) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_cvar.c:50](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_cvar.c#L50)
- behavior: [codemp/cgame/cg_draw.c:6109](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6109)
- behavior: [codemp/cgame/cg_draw.c:6129](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6129)
- behavior: [codemp/cgame/cg_draw.c:6211](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6211)
- behavior: [codemp/cgame/cg_draw.c:6335](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6335)
- documentation: [codemp/ui/ui_xdocs.h:133](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L133)
