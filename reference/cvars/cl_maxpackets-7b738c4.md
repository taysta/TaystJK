---
title: "cl_maxPackets"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_maxPackets`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_maxPackets` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-client` |
| Also registered in | `cgame`, `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `100` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `100` | `cgame` | `—` | `always` |
| `100` | `engine-client` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_main.cpp:1234](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_main.cpp#L1234)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2014-04-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7197cd614a8c`](https://github.com/JACoders/OpenJK/commit/7197cd614a8c69a0743a02bdedff324364866c9a)<br>[SP] Remove some unnecessary network-related cvars | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2014-11-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`337687913865`](https://github.com/JACoders/OpenJK/commit/337687913865ffe7f79bf5ce754127edc5217469)<br>[MP] More sane limits for cl_maxPackets | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2015-06-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d93386f34b71`](https://github.com/eternalcodes/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0)<br>Major ingame setup menu overhaul. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `high` |
| `2018-05-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`097a0d05fa4e`](https://github.com/eternalcodes/EternalJK/commit/097a0d05fa4edb25c14bf88d42ea2bff668fd232)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_view.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2023-09-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`09f29d37943e`](https://github.com/taysta/TaystJK/commit/09f29d37943e1d8af68855ab4306d80fd235d9a7)<br>[SETTINGS] Use more sane default settings for maxpackets and thirdpersonrange | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h`, `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:202](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L202) (XCVAR_DEF)
- registration: [codemp/client/cl_main.cpp:3345](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3345) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1520](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1520)
- behavior: [codemp/client/cl_input.cpp:1523](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1523)
- behavior: [codemp/client/cl_input.cpp:1528](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1528)
- behavior: [codemp/cgame/cg_view.c:2627](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L2627)
- behavior: [codemp/cgame/cg_view.c:2610](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L2610)
