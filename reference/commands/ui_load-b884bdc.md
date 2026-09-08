---
title: "ui_load"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_load`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `UI_Load` in the ui module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `ui_load` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) on `2013-04-07` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/ui/ui_atoms.c:88](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_atoms.c#L88)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/eternalcodes/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | [`14cea1563762`](https://github.com/SomaZ/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | [`14cea1563762`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | [`14cea1563762`](https://github.com/videoP/jaPRO/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | [`14cea1563762`](https://github.com/jkanewmod/NewJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | [`14cea1563762`](https://github.com/JKSunny/EternalJK/commit/14cea1563762076974bee277afadbd5bf234c494) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed the registered command handler. `codemp/ui/ui_local.h`, `codemp/ui/ui_main.c` | `medium` |
| `2013-09-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`06310990a9eb`](https://github.com/JACoders/OpenJK/commit/06310990a9eb57f977411533d1c9907a88497190)<br>Some cleanup and fixes for UI code. Also disables automatic overstrike mode in UI fields. | Changed the registered command handler. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5cd41b41c941`](https://github.com/JACoders/OpenJK/commit/5cd41b41c941de081108a65bcffe81f41a77b876)<br>[MP] Port the xcvar stuff and clean up cvar usage in UI. Few minor tweaks in UI code for cleanup/was unused. | Changed the registered command handler. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`91fdc16f64ff`](https://github.com/JACoders/OpenJK/commit/91fdc16f64ffb32f252c9a637978ff30955c9199)<br>[MP] Change game filters to display mods.  Partially from zturtleman/spearmint. Thanks zturtleman. Mods need to have pk3 + description.txt in mod folder to be displayed, same as the Mods menu. Basegame is included in mods menu if running with jamp engine and OpenJK ui module. The changes earlier to FS_GetModList includes basegame in modlist with OpenJK engine. | Changed the registered command handler. `codemp/ui/ui_main.c` | `high` |
| `2013-12-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f5c1b2ceb3ba`](https://github.com/JACoders/OpenJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1)<br>[MP] Made ui use bsearch for commands. Removed ui_teamOrders that did nothing. Made ui_test actually be considered a command to the engine. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8ff26bc00814`](https://github.com/JACoders/OpenJK/commit/8ff26bc00814ec95162c11267950c7382d44b579)<br>[MP] Some buffer fixes in ui_main.c | Changed the registered command handler. `codemp/ui/ui_main.c` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed the registered command handler. `codemp/ui/ui_cvar.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/ui/ui_cvar.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_atoms.c:109](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_atoms.c#L109) (ui command table)
- handler: [codemp/ui/ui_main.c:1540](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L1540)
