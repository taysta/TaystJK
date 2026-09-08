---
title: "ui_serverFilterType"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_serverFilterType`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_serverFilterType` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/ui/ui_main.c:9197](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9197) |
| `1` | Enabled. | [codemp/ui/ui_main.c:9197](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9197) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) on `2013-09-28` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:130](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_xcvar.h#L130)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/eternalcodes/EternalJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/SomaZ/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/taysta/TaystJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/videoP/jaPRO/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/jkanewmod/NewJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-09-28` | [`8fdb5fb65dbe`](https://github.com/JKSunny/EternalJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`91fdc16f64ff`](https://github.com/JACoders/OpenJK/commit/91fdc16f64ffb32f252c9a637978ff30955c9199)<br>[MP] Change game filters to display mods.  Partially from zturtleman/spearmint. Thanks zturtleman. Mods need to have pk3 + description.txt in mod folder to be displayed, same as the Mods menu. Basegame is included in mods menu if running with jamp engine and OpenJK ui module. The changes earlier to FS_GetModList includes basegame in modlist with OpenJK engine. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `high` |
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:142](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L142) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:9197](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9197)
- behavior: [codemp/ui/ui_main.c:9198](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L9198)
- behavior: [codemp/ui/ui_main.c:2451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L2451)
- behavior: [codemp/ui/ui_main.c:5107](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L5107)
- behavior: [codemp/ui/ui_main.c:2883](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L2883)
