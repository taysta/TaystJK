---
title: "ui_char_model"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_char_model`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_char_model` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_player2.menu:78](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_player2.menu#L78), [ingame_player2.menu:143](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_player2.menu#L143) |
| Default | `jedi_tf` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/ui/ui_main.cpp:361](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/ui/ui_main.cpp#L361)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c`, `codemp/ui/ui_shared.c` | `medium` |
| `2013-08-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61cd6e979c3b`](https://github.com/JACoders/OpenJK/commit/61cd6e979c3bb37e8b05ca2c6f1a1fc0812aea17)<br>Removed stricmp etc, always use Q_ versions for consistency across platforms | Changed an exact bound cvar-variable reference. `codemp/ui/ui_shared.c` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5cd41b41c941`](https://github.com/JACoders/OpenJK/commit/5cd41b41c941de081108a65bcffe81f41a77b876)<br>[MP] Port the xcvar stuff and clean up cvar usage in UI. Few minor tweaks in UI code for cleanup/was unused. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8fdb5fb65dbe`](https://github.com/JACoders/OpenJK/commit/8fdb5fb65dbe118ba0208194e9cf42ace7d6a6dd)<br>[MP] The cvar files for previous commit ... | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2013-09-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2ca29aebe0e9`](https://github.com/JACoders/OpenJK/commit/2ca29aebe0e9b6eddc6d754b36ea850b23c83517)<br>[MP] Fix more defaults for saber names and team names. Don't register cg_viewsize needlessly on client startup, update cvar as soon as it's changed | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |
| `2014-01-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4ffae0166eb5`](https://github.com/JACoders/OpenJK/commit/4ffae0166eb5cbc7b1f1443363306646ff3d16e4)<br>[MP] Fixed pointer to out-of-scope local stack variable in ItemParse_asset_model. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_shared.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/ui/ui_main.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b9f190a7a4b`](https://github.com/eternalcodes/EternalJK/commit/0b9f190a7a4b85682fcc0f1ff0d15e5a153e1180)<br>Reset ui_selectedModelIndex (last selected model icon) if the number of models counted has changed | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`452010cb69e8`](https://github.com/eternalcodes/EternalJK/commit/452010cb69e89d0c546144d5373bdb954e90afd5)<br>Add option to list skins that don't belong to another team under default | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:72](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L72) (XCVAR_DEF)
- behavior: [codemp/ui/ui_shared.c:7365](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_shared.c#L7365)
- behavior: [codemp/ui/ui_main.c:6478](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6478)
- behavior: [codemp/ui/ui_main.c:6508](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6508)
- behavior: [codemp/ui/ui_main.c:6548](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6548)
- behavior: [codemp/ui/ui_main.c:6604](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6604)
