---
title: "r_ext_framebuffer_multisample"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_ext_framebuffer_multisample`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_ext_framebuffer_multisample` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `(float` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Commit evidence: [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69)
- Pull request: [#110](https://github.com/taysta/TaystJK/pull/110)
- Upstream registration evidence: [shared/rd-rend2/tr_fbo.cpp:422](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/shared/rd-rend2/tr_fbo.cpp#L422)
- Attribution method: `renderer-scope-and-upstream-presence`
- Attribution confidence: `high`

## Evidence

- registration: [shared/rd-rend2/tr_fbo.cpp:422](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L422) (implicit Cvar_SetValue)
- behavior: [shared/rd-rend2/tr_fbo.cpp:412](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L412)
- behavior: [shared/rd-rend2/tr_fbo.cpp:420](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L420)
- behavior: [shared/rd-rend2/tr_fbo.cpp:414](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L414)
