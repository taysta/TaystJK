---
title: "fs_forcegame"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_forcegame`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Folder to use for overriding of fs_game (can not be set by the server).

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `` | `engine-shared` | `—` | `defined(DEDICATED)` |
| `TAYSTJKGAME` | `engine-shared` | `—` | `else(defined(DEDICATED))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`c24eecec72b4`](https://github.com/taysta/TaystJK/commit/c24eecec72b4cc94deeb65d2bba0a58f3344e1f2)
- Upstream registration evidence: [codemp/qcommon/files.cpp:3585](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/files.cpp#L3585)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/qcommon/files.cpp:3913](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3913) (Cvar_Get); condition `defined(DEDICATED)`
- registration: [codemp/qcommon/files.cpp:3915](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3915) (Cvar_Get); condition `else(defined(DEDICATED))`
- behavior: [codemp/qcommon/files.cpp:3752](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3752)
- behavior: [codemp/qcommon/files.cpp:3753](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3753)
- behavior: [codemp/qcommon/files.cpp:3988](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3988)
- behavior: [codemp/qcommon/files.cpp:3989](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3989)
- behavior: [codemp/qcommon/files.cpp:4480](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L4480)
