---
title: "bot_groundonly"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Only show ground faces of areas"
---

# `bot_groundonly`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Only show ground faces of areas

## At a glance

| Field | Value |
|:--|:--|
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Category | Bots & AI |
| Module | `engine-server` |
| Renderer | All / not renderer-specific |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_bot.cpp:268](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/server/sv_bot.cpp#L268) |
| `1` | Enabled. | [codemp/server/sv_bot.cpp:268](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/server/sv_bot.cpp#L268) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_bot.cpp:241](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_bot.cpp#L241)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/server/sv_bot.cpp:261](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/server/sv_bot.cpp#L261) (Cvar_Get)
- registration: [codemp/server/sv_bot.cpp:660](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/server/sv_bot.cpp#L660) (Cvar_Get)
- behavior: [codemp/server/sv_bot.cpp:268](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/server/sv_bot.cpp#L268)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a"><code>c722804317d7</code></a> on 2026-09-28. Anything merged after that is not reflected here.</p>
