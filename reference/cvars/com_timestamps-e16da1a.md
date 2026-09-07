---
title: "com_timestamps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_timestamps`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Print timestamps in qconsole.log and system console.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/qcommon/common.cpp:176](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L176) |
| `1` | Enabled. | [codemp/qcommon/common.cpp:176](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L176) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Commit evidence: [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3)
- Pull request: [#155](https://github.com/taysta/TaystJK/pull/155)
- Matching squash bullet: `[Shared] Add com_timestamps cvar to enable timestamps in system terminal and qconsole.log`
- Upstream registration evidence: [src/qcommon/common.cpp:2618](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/qcommon/common.cpp#L2618)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits jk2mv. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/qcommon/common.cpp:1502](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1502) (Cvar_Get)
- behavior: [codemp/qcommon/common.cpp:176](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L176)
- upstream-documentation: [CVARS.rst:28](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L28)
