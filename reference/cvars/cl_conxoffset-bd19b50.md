---
title: "cl_conXOffset"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_conXOffset`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_conXOffset` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_console.cpp:972](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L972) |
| `1` | Enabled. | [codemp/client/cl_console.cpp:972](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L972) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_console.cpp:512](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_console.cpp#L512)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_newDraw.c` | `medium` |
| `2016-03-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d92a64ca35d0`](https://github.com/eternalcodes/EternalJK/commit/d92a64ca35d02d096800f8ea5ed47c6429bfa084)<br>Console display time feature Added Timestamps New time format at bottom right console | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`135f109285cb`](https://github.com/eternalcodes/EternalJK/commit/135f109285cbe2e07bbfd4ef2dbe0ef5b492af1a)<br>Added con_scale from JK2MV. | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`652bd7e7bf18`](https://github.com/eternalcodes/EternalJK/commit/652bd7e7bf182e4e063ec9adb4294018f326345a)<br>define timestamp length, new prompt char, comments | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:948](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L948) (Cvar_Get)
- registration: [codemp/client/cl_console.cpp:989](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L989) (Cvar_Get)
- registration: [codemp/client/cl_main.cpp:3368](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3368) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:972](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L972)
- behavior: [codemp/client/cl_console.cpp:991](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L991)
- behavior: [codemp/client/cl_console.cpp:946](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L946)
- behavior: [codemp/client/cl_console.cpp:987](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L987)
- behavior: [codemp/cgame/cg_draw.c:10157](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L10157)
