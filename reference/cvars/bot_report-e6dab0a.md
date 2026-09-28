---
title: "bot_report"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Get a full report in ctf"
---

# `bot_report`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Get a full report in ctf

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | Yes |
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

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_CHEAT`: requires cheats

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_bot.cpp:656](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_bot.cpp#L656)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/server/sv_bot.cpp:677](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/server/sv_bot.cpp#L677) (Cvar_Get)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a"><code>c722804317d7</code></a> on 2026-09-28. Anything merged after that is not reflected here.</p>
