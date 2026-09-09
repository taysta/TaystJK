---
title: "cg_jumpSounds"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_jumpSounds`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Play sound when players jump

## At a glance

| Field | Value |
|:--|:--|
| Category | Audio & music |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:374](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L374) |
| In-game menu | Yes — [ingame_setup.menu:4556](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L4556) |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Don't play jump sounds | [codemp/ui/ui_xdocs.h:374](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L374) |
| `1` | Play all jump sounds | [codemp/ui/ui_xdocs.h:374](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L374) |
| `2` | Play only when other clients jump | [codemp/ui/ui_xdocs.h:375](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L375) |
| `3` | Play only when local client jumps | [codemp/ui/ui_xdocs.h:377](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L377) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:945](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L945)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_event.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ddc7f40b75cd`](https://github.com/eternalcodes/EternalJK/commit/ddc7f40b75cda77961dfc877cb219c4054dcef8b)<br>Don't play jump sound immediately after a fall/land/pain sound. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fd64be2c318a`](https://github.com/eternalcodes/EternalJK/commit/fd64be2c318abc6936c963ad84e76de440701beb)<br>misc updates | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:120](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L120) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:1799](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L1799)
- behavior: [codemp/cgame/cg_event.c:1812](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L1812)
- behavior: [codemp/ui/ui_xdocs.h:374](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L374)
- documentation: [codemp/ui/ui_xdocs.h:374](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L374)
- documentation: [docs/japro_docs.md:453](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L453)
