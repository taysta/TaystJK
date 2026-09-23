---
title: "cm_noCurves"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cm_noCurves`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cm_noCurves` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
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
| Cheat protected | Yes |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/qcommon/cm_trace.cpp:242](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cm_trace.cpp#L242) |
| `1` | Enabled. | [codemp/qcommon/cm_trace.cpp:242](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cm_trace.cpp#L242) |

## Flags

- `CVAR_CHEAT`: requires cheats

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/cm_load.cpp:626](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/cm_load.cpp#L626)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cm_load.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cm_load.cpp:635](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cm_load.cpp#L635) (Cvar_Get); condition `!defined(BSPC)`
- behavior: [codemp/qcommon/cm_trace.cpp:242](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cm_trace.cpp#L242)
- behavior: [codemp/qcommon/cm_trace.cpp:682](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cm_trace.cpp#L682)
- behavior: [codemp/qcommon/cm_trace.cpp:1041](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cm_trace.cpp#L1041)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
