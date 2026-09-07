---
title: "fs_portable"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_portable`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Disable fs_homepath and use only one folder for all game files

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`80275f5982ac`](https://github.com/taysta/TaystJK/commit/80275f5982ac0cc87a7b5444a7ea326eb405a4e1)
- Upstream registration evidence: [codemp/qcommon/files.cpp:3625](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/qcommon/files.cpp#L3625)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [codemp/qcommon/files.cpp:3922](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3922) (Cvar_Get)
- behavior: [shared/sys/sys_win32.cpp:176](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L176)
- behavior: [shared/sys/sys_win32.cpp:172](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L172)
- behavior: [shared/sys/sys_win32.cpp:174](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L174)
- behavior: [shared/sys/sys_win32.cpp:187](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_win32.cpp#L187)
