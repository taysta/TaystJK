---
title: "net_restart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_restart`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Restart the networking sub-system

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `net_restart` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/win32/win_main_console.cpp:62](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/win32/win_main_console.cpp#L62)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/win32/win_main_console.cpp` | `medium` |
| `2013-07-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a118ef1512c`](https://github.com/JACoders/OpenJK/commit/4a118ef1512c25b6fe5b24be4af48ef64a2232c6)<br>Merge pull request #318 from archSeer/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/win32/win_main_console.cpp` | `medium` |
| `2013-07-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`df8fde726025`](https://github.com/JACoders/OpenJK/commit/df8fde726025fd962d7908109ffa23147242c32e)<br>Removed some unnecessary files. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/null/win_main.cpp` | `medium` |
| `2014-01-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`90d5fa42c4b5`](https://github.com/JACoders/OpenJK/commit/90d5fa42c4b58c5ac3a84cf96305bfba5ae4d3ae)<br>[MP] Unify win_net and sys_net into qcommon/net_ip. Unix now also supports the socks code. net_restart behaves correctly now if was disabled. | Changed the registered command handler. `codemp/qcommon/net_ip.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/qcommon/net_ip.cpp`, `codemp/qcommon/qcommon.h`, `codemp/win32/win_main.cpp` | `high` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/net_ip.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:995](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L995) (Cmd_AddCommand)
- handler: [codemp/qcommon/net_ip.cpp:1100](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L1100)
