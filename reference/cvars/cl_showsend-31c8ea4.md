---
title: "cl_showSend"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_showSend`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_showSend` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_input.cpp:1614](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_input.cpp#L1614) |
| `1` | Enabled. | [codemp/client/cl_input.cpp:1614](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_input.cpp#L1614) |

## Flags

- `CVAR_TEMP`: temporary and not archived

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2572](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/client/cl_main.cpp#L2572)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/client/cl_main.cpp:3324](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_main.cpp#L3324) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1614](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_input.cpp#L1614)
- behavior: [codemp/client/cl_input.cpp:1662](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_input.cpp#L1662)
- behavior: [codemp/client/cl_input.cpp:1699](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_input.cpp#L1699)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/b35ed06fec41c53644352743c6b199a5d5d500f3"><code>b35ed06fec41</code></a> on 2026-09-27. Anything merged after that is not reflected here.</p>
