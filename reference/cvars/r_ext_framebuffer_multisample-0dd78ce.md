---
title: "r_ext_framebuffer_multisample"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_ext_framebuffer_multisample`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: no registration exists; every cited site only writes it with <code>Cvar_Set</code>, so a value you set is replaced the next time that code runs.</p>

Controls `r_ext_framebuffer_multisample` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Feature family | Renderer extensions |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2024-02-04 in [`0c789787f`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `(float` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- TaystJK integration evidence: [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69)
- Origin pull request: [#110](https://github.com/taysta/TaystJK/pull/110)
- Upstream registration evidence: [codemp/rd-rend2/tr_fbo.cpp:416](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-rend2/tr_fbo.cpp#L416)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `medium`

## Evidence

- registration: [shared/rd-rend2/tr_fbo.cpp:422](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_fbo.cpp#L422) (implicit Cvar_SetValue)
- behavior: [shared/rd-rend2/tr_fbo.cpp:412](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_fbo.cpp#L412)
- behavior: [shared/rd-rend2/tr_fbo.cpp:420](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_fbo.cpp#L420)
- behavior: [shared/rd-rend2/tr_fbo.cpp:414](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_fbo.cpp#L414)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
