---
title: "cg_drawScores"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawScores`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Team score counter in top right

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:278](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L278) |
| In-game menu | No |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Scores are hidden | [codemp/ui/ui_xdocs.h:278](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L278) |
| `1` | Team scores are drawn in the top right | [codemp/ui/ui_xdocs.h:279](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L279) |
| `2` | Team scores are drawn in the top right with color | [codemp/ui/ui_xdocs.h:281](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L281) |
| `3` | Large team scores | [codemp/ui/ui_xdocs.h:282](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L282) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:905](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L905)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b6c02420b9df`](https://github.com/taysta/TaystJK/commit/b6c02420b9df02ae2b88006b332f1e053ecbf15c)<br>#13 HUD Improvements - new timer (cg_drawTimer 7) and new team scores display (cg_drawScores 3) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/ui/ui_xdocs.h` | `medium` |
| `2022-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`81882b7ee881`](https://github.com/taysta/TaystJK/commit/81882b7ee8819e82f5308bf66d08fd2b7040aa35)<br>#13 new team overlays - cg_drawTeamOverlay 3/4 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-05-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1db3ddddc177`](https://github.com/taysta/TaystJK/commit/1db3ddddc177c7747959684f4e7d6aeca2fd1158)<br>update cvar definitions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2022-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`420d7dc3fb1d`](https://github.com/taysta/TaystJK/commit/420d7dc3fb1d739171ac22011774a7c9876c02bf)<br>add new basejka duel scores overlay wtih cg_drawscores 3 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2026-02-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`168729602a5b`](https://github.com/taysta/TaystJK/commit/168729602a5b876069e9a19a63f5c6708cd8e353) · [PR #292](https://github.com/taysta/TaystJK/pull/292)<br>Merge pull request #292 from taysta/draw-status | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:87](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L87) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:3855](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L3855)
- behavior: [codemp/cgame/cg_draw.c:4275](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L4275)
- behavior: [codemp/cgame/cg_draw.c:4277](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L4277)
- behavior: [codemp/cgame/cg_draw.c:4283](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L4283)
- behavior: [codemp/cgame/cg_draw.c:6323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6323)
- documentation: [codemp/ui/ui_xdocs.h:278](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L278)
