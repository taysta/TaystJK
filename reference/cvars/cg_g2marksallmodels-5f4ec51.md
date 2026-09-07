---
title: "cg_g2MarksAllModels"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_g2MarksAllModels`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Render marks on all G2 models

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-dedicated/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/G2_misc.cpp#L558) |
| `1` | Enabled. | [codemp/rd-dedicated/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/G2_misc.cpp#L558) |

## Flags

No cvar flags are registered at the cited site.

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-dedicated` | `defined(_G2_GORE)` |
| `0` | `renderer` | `rd-rend2` | `defined(_G2_GORE)` |
| `0` | `renderer` | `rd-vanilla` | `defined(_G2_GORE)` |
| `0` | `renderer` | `rd-vulkan` | `defined(_G2_GORE)` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Commit evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/ghoul2/G2_misc.cpp:565](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/ghoul2/G2_misc.cpp#L565)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-dedicated/G2_misc.cpp:554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/G2_misc.cpp#L554) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-dedicated/G2_misc.cpp:1503](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/G2_misc.cpp#L1503) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-rend2/G2_misc.cpp:545](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_misc.cpp#L545) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-rend2/G2_misc.cpp:1485](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_misc.cpp#L1485) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vanilla/G2_misc.cpp:554](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/G2_misc.cpp#L554) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vanilla/G2_misc.cpp:1504](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/G2_misc.cpp#L1504) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vulkan/G2_misc.cpp:562](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/G2_misc.cpp#L562) (Cvar_Get); condition `defined(_G2_GORE)`
- registration: [codemp/rd-vulkan/G2_misc.cpp:1568](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/G2_misc.cpp#L1568) (Cvar_Get); condition `defined(_G2_GORE)`
- behavior: [codemp/rd-dedicated/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/G2_misc.cpp#L558)
- behavior: [codemp/rd-dedicated/G2_misc.cpp:1507](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/G2_misc.cpp#L1507)
- behavior: [codemp/rd-rend2/G2_misc.cpp:549](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_misc.cpp#L549)
- behavior: [codemp/rd-rend2/G2_misc.cpp:1489](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_misc.cpp#L1489)
- behavior: [codemp/rd-vanilla/G2_misc.cpp:558](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/G2_misc.cpp#L558)
