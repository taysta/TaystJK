---
title: "r_forceParallaxBias"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_forceParallaxBias`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_forceParallaxBias` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_TEMP` — temporary and not archived

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`d72bd836bcd4`](https://github.com/taysta/TaystJK/commit/d72bd836bcd4aef75b9f770a94feaa4a859b783f)
- Matching squash bullet: `r_forceParallaxBias can be used for previewing`
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1613](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1613)
- Attribution method: `renderer-scope-and-upstream-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1648](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1648) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_shade.cpp:1866](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1866)
- behavior: [codemp/rd-rend2/tr_init.cpp:1649](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1649)
