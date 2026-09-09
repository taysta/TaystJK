---
title: "ui_selectedModelIndex"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_selectedModelIndex`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_selectedModelIndex` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `-1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `-1` | Selects the code path tested for value -1. | [codemp/ui/ui_shared.c:5790](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L5790) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/ui/ui_main.c:11403](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/ui/ui_main.c#L11403)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5cd41b41c941`](https://github.com/JACoders/OpenJK/commit/5cd41b41c941de081108a65bcffe81f41a77b876)<br>[MP] Port the xcvar stuff and clean up cvar usage in UI. Few minor tweaks in UI code for cleanup/was unused. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd)<br>[MP] The cvar files for previous commit ... | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2018-01-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a2acfb6b9129`](https://github.com/eternalcodes/EternalJK/commit/a2acfb6b91293508500c339e92b2ee9033a9323b)<br>Merge pull request #11 from Bucky21659/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `high` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b9f190a7a4b`](https://github.com/eternalcodes/EternalJK/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180)<br>Reset ui_selectedModelIndex (last selected model icon) if the number of models counted has changed | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_xcvar.h` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`713662027af3`](https://github.com/eternalcodes/EternalJK/commit/713662027af3aceeded2a573038bca5861b039a2)<br>Check model cvar for team skin and update profile menu accordingly. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`95dcf4d6228f`](https://github.com/eternalcodes/EternalJK/commit/95dcf4d6228ff88925ae2ad2ab1ad444cf13d0d7)<br>Fix crash | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a649365161ad`](https://github.com/eternalcodes/EternalJK/commit/a649365161ad6ee03c858c87429a6d01cb68bc88)<br>Ignore mutant_racnor and r5d2 in profile menu list | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`4fdbdfbd0443`](https://github.com/eternalcodes/EternalJK/commit/4fdbdfbd04431fdc458225317457eb8bce0ada81)<br>Fix custom jedi models being reset when closing ingame profile menu. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b6f9c97643c4`](https://github.com/eternalcodes/EternalJK/commit/b6f9c97643c4e9d88125bfb36c281380b0f9c914)<br>Don't highlight anything in model list if no model is selected (ui_selectedModelIndex -1) | Changed an exact bound cvar-variable reference. `codemp/ui/ui_shared.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:141](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L141) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:5829](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5829)
- behavior: [codemp/ui/ui_main.c:6562](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6562)
- behavior: [codemp/ui/ui_main.c:6569](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6569)
- behavior: [codemp/ui/ui_main.c:8959](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8959)
- behavior: [codemp/ui/ui_shared.c:5790](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L5790)
