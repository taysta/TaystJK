---
title: "se_language"
layout: reference
nav_exclude: true
search_exclude: false
---

# `se_language`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `se_language` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared`, `renderer`, `ui` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `english` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_NORESTART` — preserved across cvar restart

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `english` | `engine-shared` | `—` | `always` |
| `english` | `renderer` | `rd-rend2` | `always` |
| `english` | `renderer` | `rd-vanilla` | `always` |
| `english` | `renderer` | `rd-vulkan` | `always` |
| `english` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Commit evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/stringed_ingame.cpp:1169](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/stringed_ingame.cpp#L1169)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/qcommon/stringed_ingame.cpp:1178](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/stringed_ingame.cpp#L1178) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1727](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1727) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1626](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1626) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:779](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L779) (Cvar_Get)
- registration: [codemp/ui/ui_xcvar.h:50](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L50) (XCVAR_DEF)
- behavior: [codemp/qcommon/stringed_ingame.cpp:937](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/stringed_ingame.cpp#L937)
- behavior: [codemp/qcommon/stringed_ingame.cpp:1196](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/stringed_ingame.cpp#L1196)
- behavior: [codemp/qcommon/stringed_ingame.cpp:1199](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/stringed_ingame.cpp#L1199)
- behavior: [codemp/qcommon/stringed_ingame.cpp:1260](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/stringed_ingame.cpp#L1260)
- behavior: [codemp/qcommon/stringed_ingame.h:93](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/stringed_ingame.h#L93)
