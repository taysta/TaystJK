---
title: "con_timestamps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `con_timestamps`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Draw local timestamps in console and condump output.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Selects the code path tested for value 0. | [codemp/client/cl_console.cpp:935](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L935) |
| `2` | Selects the code path tested for value 2. | [codemp/client/cl_console.cpp:935](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L935) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Commit evidence: [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3)
- Pull request: [#155](https://github.com/taysta/TaystJK/pull/155)
- Matching squash bullet: `add con_timestamps 2 to disable timestamps in the notify lines only`
- Upstream registration evidence: [src/client/cl_console.cpp:407](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/client/cl_console.cpp#L407)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/client/cl_console.cpp:667](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L667) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:399](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L399)
- behavior: [codemp/client/cl_console.cpp:935](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L935)
- behavior: [codemp/client/cl_console.cpp:1157](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1157)
- behavior: [codemp/client/cl_console.cpp:615](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L615)
- upstream-documentation: [CVARS.rst:161](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L161)
