---
title: "fs_apppath"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_apppath`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

(Read Only) Location of OSX .app bundle

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `Sys_DefaultAppPath()` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`2229f7cb1aba`](https://github.com/taysta/TaystJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)
- Upstream registration evidence: [code/qcommon/files.cpp:2906](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/files.cpp#L2906)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/qcommon/files.cpp:3942](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3942) (Cvar_Get); condition `defined(MACOS_X)`
- behavior: [codemp/qcommon/files.cpp:3944](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3944)
- behavior: [codemp/qcommon/files.cpp:3965](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3965)
- behavior: [codemp/qcommon/files.cpp:3945](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3945)
- behavior: [codemp/qcommon/files.cpp:3966](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3966)
- behavior: [codemp/qcommon/files.cpp:3816](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3816)
