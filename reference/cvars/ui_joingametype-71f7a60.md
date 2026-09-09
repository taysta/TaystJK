---
title: "ui_joinGametype"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_joinGametype`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_joinGametype` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_server.menu:202](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_server.menu#L202), [joinserver.menu:301](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/joinserver.menu#L301) |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `-1` | Selects the code path tested for value -1. | [codemp/ui/ui_main.c:9189](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9189) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/ui/ui_main.c:11456](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/ui/ui_main.c#L11456)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5cd41b41c941`](https://github.com/JACoders/OpenJK/commit/5cd41b41c941de081108a65bcffe81f41a77b876)<br>[MP] Port the xcvar stuff and clean up cvar usage in UI. Few minor tweaks in UI code for cleanup/was unused. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd)<br>[MP] The cvar files for previous commit ... | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:91](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L91) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:1704](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L1704)
- behavior: [codemp/ui/ui_main.c:9189](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9189)
- behavior: [codemp/ui/ui_main.c:9191](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9191)
- behavior: [codemp/ui/ui_main.c:1710](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L1710)
- behavior: [codemp/ui/ui_main.c:4936](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L4936)
