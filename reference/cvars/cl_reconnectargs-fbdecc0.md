---
title: "cl_reconnectArgs"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_reconnectArgs`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Arguments provided when last connecting to a server

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`d599e706c7ff`](https://github.com/JACoders/OpenJK/commit/d599e706c7ff985572ce00a7657abf0353a4dc82) on `2013-11-10` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- Upstream registration evidence: [codemp/client/cl_main.cpp:2836](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2836)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2, taystjk, japro; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-11-10` | [`d599e706c7ff`](https://github.com/JACoders/OpenJK/commit/d599e706c7ff985572ce00a7657abf0353a4dc82) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-11-10` | [`d599e706c7ff`](https://github.com/SomaZ/OpenJK/commit/d599e706c7ff985572ce00a7657abf0353a4dc82) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-11-10` | [`d599e706c7ff`](https://github.com/taysta/TaystJK/commit/d599e706c7ff985572ce00a7657abf0353a4dc82) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-11-10` | [`d599e706c7ff`](https://github.com/videoP/jaPRO/commit/d599e706c7ff985572ce00a7657abf0353a4dc82) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2026-06-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a6f521232afb`](https://github.com/taysta/TaystJK/commit/a6f521232afba109e20275bac4a71369ba5b5ae1) · [PR #311](https://github.com/taysta/TaystJK/pull/311)<br>Merge pull request #311 from taysta/bone-conversion | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/client/client.h` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3413](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3413) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:1124](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1124)
- behavior: [codemp/client/cl_main.cpp:1128](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1128)
- behavior: [codemp/client/cl_main.cpp:1147](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L1147)
