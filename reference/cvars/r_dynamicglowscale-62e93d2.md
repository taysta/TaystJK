---
title: "r_DynamicGlowScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_DynamicGlowScale`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_DynamicGlowScale` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0.25` |
| Value type | `float` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0.25` | `renderer` | `rd-vanilla` | `always` |
| `0.25` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`f768a9d0b3b1`](https://github.com/taysta/TaystJK/commit/f768a9d0b3b10086974b9c9a01b620549d13915e)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:842](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/rd-vulkan/tr_init.cpp#L842)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:1650](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1650) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:802](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L802) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_image.cpp:1548](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_image.cpp#L1548)
- behavior: [codemp/rd-vanilla/tr_image.cpp:1549](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_image.cpp#L1549)
