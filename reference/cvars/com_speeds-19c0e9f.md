---
title: "com_speeds"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_speeds`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_speeds` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `3` | Selects the code path tested for value 3. | [codemp/qcommon/common.cpp:1074](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1074) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/common.cpp:1042](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/common.cpp#L1042)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`393874137c54`](https://github.com/JACoders/OpenJK/commit/393874137c54b70b27856e62013bd283059ef6e0)<br>First batch of changes from Ensi | Changed an exact bound cvar-variable reference. `codemp/client/cl_scrn.cpp` | `medium` |
| `2013-11-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2e90f9c19be1`](https://github.com/JACoders/OpenJK/commit/2e90f9c19be1a2b74a1ac71f8ff0dcdadfa3103c)<br>[MP] Removed leftover delayFreeVM references. Init lastTime to 0 in Com_Frame. Bring back ERR_NEED_CD handling just for conformity sake. Init the jakey randomizer first thing in Com_Init. | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2014-04-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`79798ac51496`](https://github.com/JACoders/OpenJK/commit/79798ac51496a131dd91e3e464d39363bea17671)<br>[MP] Fix com_speed output when running server | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1472](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1472) (Cvar_Get)
- behavior: [codemp/client/cl_scrn.cpp:618](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L618)
- behavior: [codemp/qcommon/common.cpp:1065](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1065)
- behavior: [codemp/qcommon/common.cpp:1071](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1071)
- behavior: [codemp/qcommon/common.cpp:1074](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1074)
- behavior: [codemp/qcommon/common.cpp:1744](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1744)
