---
title: "messagemode3"
layout: reference
nav_exclude: true
search_exclude: false
---

# `messagemode3`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Private Chat with Target Player

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `messagemode3` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_console.cpp:310](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_console.cpp#L310)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_console.cpp` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`55c2d54b3409`](https://github.com/JACoders/OpenJK/commit/55c2d54b34097448d9e5c8d8a62bcb35fe00391f)<br>Major improvements to command completion | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2017-12-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b713e21a0ea8`](https://github.com/videoP/jaPRO/commit/b713e21a0ea84fe4d2d1d87c1a6f5dfd84e9cbb5)<br>Merge pull request #1 from Bucky21659/master | Changed the registered command handler. `codemp/client/cl_console.cpp` | `high` |
| `2018-03-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`25a0b7fef8a3`](https://github.com/eternalcodes/EternalJK/commit/25a0b7fef8a386f3dbf6c8de98bd0f137c5184e4)<br>Cleaned up ratio correction code in engine and renderer | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2018-04-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`74b4931f54ac`](https://github.com/eternalcodes/EternalJK/commit/74b4931f54acd0f94c8a67eddc88d5c413edb706)<br>send messagemode3 to person you are spectating instead of who they are aiming crosshair at | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2018-04-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a76b8923b25a`](https://github.com/eternalcodes/EternalJK/commit/a76b8923b25ab4d87ec675e94dd6bdf105b3c8f3)<br>Adjusted "Whisper:" text field width. | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed the registered command handler. `codemp/client/cl_console.cpp` | `high` |
| `2023-11-02` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dd57de55b028`](https://github.com/taysta/TaystJK/commit/dd57de55b0284b7f7ecdb114d9f93e4d7867f6ea)<br>[EternalJK/Bucky] Stretch fix the Say: message on the top left of the screen when sending a message ingame | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:681](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L681) (Cmd_AddCommand)
- handler: [codemp/client/cl_console.cpp:124](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L124)
