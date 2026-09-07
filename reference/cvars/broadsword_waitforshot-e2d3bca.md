---
title: "broadsword_waitforshot"
layout: reference
nav_exclude: true
search_exclude: false
---

# `broadsword_waitforshot`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `broadsword_waitforshot` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-dedicated`, `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/rd-rend2/G2_bones.cpp:1682](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_bones.cpp#L1682) |

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-dedicated` | `always` |
| `0` | `renderer` | `rd-rend2` | `always` |
| `0` | `renderer` | `rd-vanilla` | `always` |
| `0` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Commit evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/renderer/tr_init.cpp:1258](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/renderer/tr_init.cpp#L1258)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-dedicated/tr_init.cpp:446](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-dedicated/tr_init.cpp#L446) (Cvar_Get)
- registration: [codemp/rd-rend2/tr_init.cpp:1713](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1713) (Cvar_Get)
- registration: [codemp/rd-vanilla/tr_init.cpp:1759](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1759) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:991](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L991) (Cvar_Get)
- behavior: [codemp/rd-rend2/G2_bones.cpp:1682](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_bones.cpp#L1682)
- behavior: [codemp/rd-vanilla/G2_bones.cpp:1680](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/G2_bones.cpp#L1680)
- behavior: [codemp/rd-vulkan/G2_bones.cpp:1683](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/G2_bones.cpp#L1683)
- behavior: [codemp/rd-rend2/G2_bones.cpp:1680](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_bones.cpp#L1680)
- behavior: [codemp/rd-rend2/G2_bones.cpp:1706](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/G2_bones.cpp#L1706)
