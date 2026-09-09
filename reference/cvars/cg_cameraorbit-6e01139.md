---
title: "cg_cameraOrbit"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_cameraOrbit`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_cameraOrbit` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_CHEAT` — requires cheats

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:1025](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L1025)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/ui/ui_main.c` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c6e3f0479ac0`](https://github.com/JACoders/OpenJK/commit/c6e3f0479ac048e838ac002351fab307f726fa4d)<br>[MP] Meta: Remove unnecessary comments and names | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2014-01-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d4ce8f0bbfe7`](https://github.com/JACoders/OpenJK/commit/d4ce8f0bbfe747de490416048277fa2a93d85233)<br>[MP] Clean up UI and bot code | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:261](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L261) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_consolecmds.c:242](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L242)
- behavior: [codemp/cgame/cg_view.c:1783](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1783)
- behavior: [codemp/cgame/cg_view.c:1786](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1786)
- behavior: [codemp/cgame/cg_consolecmds.c:243](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L243)
- behavior: [codemp/cgame/cg_consolecmds.c:246](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L246)
