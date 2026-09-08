---
title: "s_initsound"
layout: reference
nav_exclude: true
search_exclude: false
---

# `s_initsound`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cv` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
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
- Upstream registration evidence: [code/client/snd_ambient.cpp:814](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/snd_ambient.cpp#L814)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e)<br>Replaces jpeg-6 with jpeg-8c.  Adds AVI write support from ioquake3.  (jpeg update was required) | Changed an exact bound cvar-variable reference. `codemp/client/cl_avi.cpp` | `medium` |
| `2013-07-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a118ef1512c`](https://github.com/JACoders/OpenJK/commit/4a118ef1512c25b6fe5b24be4af48ef64a2232c6)<br>Merge pull request #318 from archSeer/master | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_dma_console.cpp`, `codemp/client/snd_dma_console.cpp` | `medium` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`04b68f71e4e9`](https://github.com/JACoders/OpenJK/commit/04b68f71e4e9c6b4b3348e89f27bc929cc7c41b5)<br>[SP] Don't mark s_initsound as being read only. Fixed some mismatched value types in sound code. Merged some win32 checks around OpenAL code from MP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_ambient.cpp`, `code/client/snd_dma.cpp` | `medium` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a768967708d2`](https://github.com/JACoders/OpenJK/commit/a768967708d2b66b494fd1a330eda89534ad8280)<br>[MP] Don't mark s_initsound as being read only. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/snd_dma.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/snd_ambient.cpp`, `code/client/snd_dma.cpp` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed an exact bound cvar-variable reference. `codemp/client/snd_ambient.cpp` | `medium` |

## Evidence

- registration: [codemp/client/snd_dma.cpp:484](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L484) (Cvar_Get)
- behavior: [codemp/client/snd_dma.cpp:485](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_dma.cpp#L485)
- behavior: [codemp/game/NPC_misc.c:38](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/NPC_misc.c#L38)
- behavior: [codemp/game/NPC_misc.c:67](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/NPC_misc.c#L67)
- behavior: [codemp/qcommon/cm_patch.cpp:1317](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cm_patch.cpp#L1317)
- behavior: [codemp/qcommon/cm_patch.cpp:1514](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cm_patch.cpp#L1514)
