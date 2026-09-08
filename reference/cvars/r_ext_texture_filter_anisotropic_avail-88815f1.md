---
title: "r_ext_texture_filter_anisotropic_avail"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_ext_texture_filter_anisotropic_avail`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `glConfig.maxTextureFilterAnisotropy` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `renderer` | `rd-rend2` | `always` |
| `0` | `renderer` | `rd-vanilla` | `always` |
| `glConfig.maxTextureFilterAnisotropy` | `renderer` | `rd-rend2` | `always` |
| `glConfig.maxTextureFilterAnisotropy` | `renderer` | `rd-vanilla` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/mac/mac_glimp.c:326](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/mac/mac_glimp.c#L326)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:501](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L501) (implicit Cvar_SetValue)
- registration: [codemp/rd-vanilla/tr_init.cpp:504](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L504) (implicit Cvar_SetValue)
- registration: [codemp/rd-vanilla/tr_init.cpp:510](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L510) (implicit Cvar_Set)
- registration: [shared/rd-rend2/tr_extensions.cpp:560](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_extensions.cpp#L560) (implicit Cvar_SetValue)
- registration: [shared/rd-rend2/tr_extensions.cpp:563](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_extensions.cpp#L563) (implicit Cvar_SetValue)
- registration: [shared/rd-rend2/tr_extensions.cpp:569](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_extensions.cpp#L569) (implicit Cvar_Set)
