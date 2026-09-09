---
title: "toggleconsole"
layout: reference
nav_exclude: true
search_exclude: false
---

# `toggleconsole`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Show/hide console

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `toggleconsole` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_console.cpp:242](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_console.cpp#L242)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_console.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `high` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`55c2d54b3409`](https://github.com/JACoders/OpenJK/commit/55c2d54b34097448d9e5c8d8a62bcb35fe00391f)<br>Major improvements to command completion | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/client/cl_console.cpp`, `codemp/client/cl_keys.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d43e7fab34a4`](https://github.com/JACoders/OpenJK/commit/d43e7fab34a467a43065d17e76981060972d88d1)<br>Clear key states on console toggling to prevent keys sticking while opening and closing console. Also makes the escape console close bind be exclusive to closing console now. | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2013-09-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f8564ad61037`](https://github.com/JACoders/OpenJK/commit/f8564ad6103745b83f63e4a2f52e8dbdd1a899d0)<br>Add con_autoclear cvar, defaults to 1. Disable this if you want the console input content to remain after the console closes. | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2014-02-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b276c56dd51c`](https://github.com/JACoders/OpenJK/commit/b276c56dd51c9934657fe418620165990229e97f)<br>[MP] Merged some ioq3 bind changes to MP along with togglemenu support. Console Command intercept should still work. | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b4c92e8bd16a`](https://github.com/eternalcodes/EternalJK/commit/b4c92e8bd16a54e5b612a814bc754251038004eb)<br>New console heights for Shift + CONSOLE and Ctrl + CONSOLE | Changed the registered command handler. `codemp/client/cl_keys.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa74b7e4e6b1`](https://github.com/eternalcodes/EternalJK/commit/fa74b7e4e6b1e61e0f888f95b12b9141597acd42)<br>Add Date/Time to console | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`135f109285cb`](https://github.com/eternalcodes/EternalJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a)<br>Added con_scale from JK2MV. | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:677](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L677) (Cmd_AddCommand)
- handler: [codemp/client/cl_console.cpp:69](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L69)
