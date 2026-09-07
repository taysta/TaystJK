---
title: "cl_filterGames"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_filterGames`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

List of fs_game to filter (space separated)

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `MBII MBIIOpenBeta` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`765295786d85`](https://github.com/taysta/TaystJK/commit/765295786d85ae6f1b655455b15ff95dd89b8cca)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2830](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2830)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/client/cl_main.cpp:3409](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3409) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:3750](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3750)
- behavior: [codemp/client/cl_main.cpp:3759](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3759)
