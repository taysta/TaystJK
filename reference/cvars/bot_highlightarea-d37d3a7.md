---
title: "bot_highlightarea"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `bot_highlightarea`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `bot_highlightarea` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Bots & AI |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_bot.cpp:243](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_bot.cpp#L243)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/server/sv_bot.cpp:263](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_bot.cpp#L263) (Cvar_Get)
- behavior: [codemp/server/sv_bot.cpp:269](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_bot.cpp#L269)
- behavior: [codemp/botlib/be_interface.cpp:393](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/botlib/be_interface.cpp#L393)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
