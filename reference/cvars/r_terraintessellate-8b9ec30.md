---
title: "r_terrainTessellate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_terrainTessellate`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_terrainTessellate` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `3` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_CHEAT` — requires cheats

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `3` | `renderer` | `rd-vanilla` | `always` |
| `3` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_terrain.cpp:1025](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_terrain.cpp#L1025)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_terrain.cpp` | `high` |
| `2013-04-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1d1a3eb6a6b7`](https://github.com/JACoders/OpenJK/commit/1d1a3eb6a6b703edb83210ff30edc1ac0bf5bda5)<br>First batch of code edits for the JKA SP modular renderer | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/renderer/tr_terrain.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_terrain.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_terrain.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_terrain.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vanilla/tr_terrain.cpp:1016](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_terrain.cpp#L1016) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_terrain.cpp:1016](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_terrain.cpp#L1016) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_terrain.cpp:133](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_terrain.cpp#L133)
- behavior: [codemp/rd-vanilla/tr_terrain.cpp:145](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_terrain.cpp#L145)
- behavior: [codemp/rd-vulkan/tr_terrain.cpp:133](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_terrain.cpp#L133)
- behavior: [codemp/rd-vulkan/tr_terrain.cpp:145](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_terrain.cpp#L145)
