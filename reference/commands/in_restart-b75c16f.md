---
title: "in_restart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `in_restart`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `IN_Restart` in the engine-shared module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Input & controls |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [controls.menu:3038](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/controls.menu#L3038), [ingame_controls.menu:2561](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_controls.menu#L2561), [ingame_controls.menu:2787](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_controls.menu#L2787) |
| Syntax | `in_restart` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/unix/unix_main.c:99](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/unix/unix_main.c#L99)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_main_console.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/unix/unix_main.c` | `high` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/unix/unix_main.c` | `high` |
| `2013-07-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a118ef1512c`](https://github.com/JACoders/OpenJK/commit/4a118ef1512c25b6fe5b24be4af48ef64a2232c6)<br>Merge pull request #318 from archSeer/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_main_console.cpp` | `medium` |
| `2013-07-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`df8fde726025`](https://github.com/JACoders/OpenJK/commit/df8fde726025fd962d7908109ffa23147242c32e)<br>Removed some unnecessary files. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/null/win_main.cpp` | `medium` |
| `2013-09-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`611dcfab4ab5`](https://github.com/JACoders/OpenJK/commit/611dcfab4ab5c3ab78305108a9c6e4ab0cb34d72)<br>Cleanup dedicatead server null files. | Changed the registered command handler. `codemp/null/null_input.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/win32/win_main.cpp`, `shared/sdl/sdl_input.cpp`, `shared/sys/sys_local.h` and 1 more | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed the registered command handler. `shared/sdl/sdl_window.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_main.cpp` | `medium` |
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed the registered command handler. `shared/sys/sys_local.h` | `medium` |

## Evidence

- registration: [shared/sys/sys_main.cpp:165](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L165) (Cmd_AddCommand)
- handler: [codemp/null/null_input.cpp:33](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/null/null_input.cpp#L33)
