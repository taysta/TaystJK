---
title: "cl_forceavidemo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_forceavidemo`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_forceavidemo` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_main.cpp:2497](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2497) |
| `1` | Enabled. | [codemp/client/cl_main.cpp:2497](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2497) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2580](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_main.cpp#L2580)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-04-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d29a8d83cb6e`](https://github.com/JACoders/OpenJK/commit/d29a8d83cb6e37bd9ea77bf9faa46deab9c10c0a)<br>Merge pull request #533 from dpadgett/teh | Changed an exact bound cvar-variable reference. `codemp/client/client.h`, `codemp/client/snd_mix.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3331](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3331) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2497](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2497)
- behavior: [codemp/client/snd_mix.cpp:181](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/snd_mix.cpp#L181)
