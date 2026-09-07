---
title: "r_cleardecals"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_cleardecals`

<span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `RE_ClearDecals` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `r_cleardecals` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span>

- Commit evidence: [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919)
- Pull request: [#12](https://github.com/taysta/TaystJK/pull/12)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1528](https://github.com/jkanewmod/NewJK/blob/ad8d071f714ab1bbcd7b6bb4bb8ceaeee6e57541/codemp/rd-rend2/tr_init.cpp#L1528)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`
- Notes: The current registration signature differs from the origin snapshot; the changing fork still needs commit-level review.

### Later changes

- <span class="label ref-origin ref-origin-unknown">Unknown</span> Registration defaults, flags, modules, or renderer scope differ from the originating snapshot. Confidence: `low`.

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1465](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1465) (renderer command table)
- registration: [codemp/rd-vanilla/tr_init.cpp:1604](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_init.cpp#L1604) (renderer command table)
- registration: [codemp/rd-vulkan/tr_init.cpp:755](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L755) (renderer command table)
- handler: [codemp/rd-vanilla/tr_decals.cpp:62](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vanilla/tr_decals.cpp#L62)
