---
title: "sv_paused"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `sv_paused`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>).</p>

Controls `sv_paused` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_cgame.cpp:963](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_cgame.cpp#L963) |
| `1` | Enabled. | [codemp/client/cl_cgame.cpp:963](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_cgame.cpp#L963) |

## Flags

- `CVAR_ROM`: read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/common.cpp:1049](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/common.cpp#L1049)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d1043c837228`](https://github.com/JACoders/OpenJK/commit/d1043c837228fea287e590753713376d1e15a4c0)<br>Pause code fixes (ioq3) | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp`, `codemp/client/cl_main.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`830c185c50e9`](https://github.com/eternalcodes/EternalJK/commit/830c185c50e93935e2d0dac88890154f06e6e58c)<br>don't timeout during demo pause | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1479](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L1479) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:963](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_cgame.cpp#L963)
- behavior: [codemp/client/cl_input.cpp:1690](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_input.cpp#L1690)
- behavior: [codemp/client/cl_main.cpp:2308](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L2308)
- behavior: [codemp/server/sv_main.cpp:1008](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_main.cpp#L1008)
- behavior: [codemp/server/sv_main.cpp:1013](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_main.cpp#L1013)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
