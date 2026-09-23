---
title: "sv_paks"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `sv_paks`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>).</p>

Controls `sv_paks` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Files & downloads |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM`: read-only after registration
- `CVAR_SYSTEMINFO`: replicated in systeminfo

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_init.cpp:844](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_init.cpp#L844)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/server/sv_init.cpp:1002](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_init.cpp#L1002) (Cvar_Get)
- behavior: [codemp/client/cl_parse.cpp:458](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_parse.cpp#L458)
- behavior: [codemp/server/sv_init.cpp:705](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_init.cpp#L705)
- behavior: [codemp/server/sv_init.cpp:719](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_init.cpp#L719)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
