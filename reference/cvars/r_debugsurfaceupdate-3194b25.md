---
title: "r_debugSurfaceUpdate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_debugSurfaceUpdate`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cv` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/cm_patch.cpp:2172](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/cm_patch.cpp#L2172)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/cm_patch_xbox.cpp` | `medium` |
| `2013-07-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a118ef1512c`](https://github.com/JACoders/OpenJK/commit/4a118ef1512c25b6fe5b24be4af48ef64a2232c6)<br>Merge pull request #318 from archSeer/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cm_patch.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/cm_patch.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/cm_patch.cpp:1315](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cm_patch.cpp#L1315) (Cvar_Get); condition `!defined(BSPC)`
- registration: [codemp/qcommon/cm_patch.cpp:1512](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cm_patch.cpp#L1512) (Cvar_Get); condition `!defined(BSPC)`
- behavior: [codemp/client/snd_dma.cpp:485](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L485)
- behavior: [codemp/game/NPC_misc.c:38](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/NPC_misc.c#L38)
- behavior: [codemp/game/NPC_misc.c:67](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/NPC_misc.c#L67)
- behavior: [codemp/qcommon/cm_patch.cpp:1317](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cm_patch.cpp#L1317)
- behavior: [codemp/qcommon/cm_patch.cpp:1514](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cm_patch.cpp#L1514)
