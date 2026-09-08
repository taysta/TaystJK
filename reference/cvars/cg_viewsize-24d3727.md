---
title: "cg_viewsize"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_viewsize`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_viewsize` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `100` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_INTERNAL` — internal UI/engine state

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `100` | `cgame` | `—` | `always` |
| `100` | `engine-client` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:888](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L888)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_view.c` | `medium` |
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_view.c`, `codemp/client/cl_main.cpp` | `medium` |
| `2013-10-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`affd2fee9c8a`](https://github.com/JACoders/OpenJK/commit/affd2fee9c8a1fb30cc81ae015b0fb7eb49e7573)<br>[MP] Partially reverted 2ca29ae. (cg_viewsize portion) 2ca29ae: [MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed Fixes http://i.imgur.com/ArbOwRb.jpg | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_view.c`, `codemp/client/cl_main.cpp` | `medium` |
| `2016-04-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d2ebafa99e8e`](https://github.com/taysta/TaystJK/commit/d2ebafa99e8ef5218aa345ff036abf3c26d83578)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:370](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L370) (XCVAR_DEF)
- registration: [codemp/client/cl_main.cpp:3440](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3440) (Cvar_Get)
- behavior: [codemp/cgame/cg_view.c:198](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L198)
- behavior: [codemp/cgame/cg_view.c:202](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L202)
- behavior: [codemp/cgame/cg_consolecmds.c:59](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L59)
- behavior: [codemp/cgame/cg_consolecmds.c:70](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L70)
- behavior: [codemp/cgame/cg_view.c:207](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L207)
