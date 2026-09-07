---
title: "minimize"
layout: reference
nav_exclude: true
search_exclude: false
---

# `minimize`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `GLimp_Minimize` in the engine-shared module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `minimize` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Commit evidence: [`8370ced3622c`](https://github.com/taysta/TaystJK/commit/8370ced3622c21b2f19ccf163f5fc0aef0fff1ff)
- Upstream registration evidence: [shared/sdl/sdl_window.cpp:784](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/shared/sdl/sdl_window.cpp#L784)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits vulkan.

## Evidence

- registration: [shared/sdl/sdl_window.cpp:791](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L791) (Cmd_AddCommand)
- handler: [shared/sdl/sdl_window.cpp:146](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L146)
