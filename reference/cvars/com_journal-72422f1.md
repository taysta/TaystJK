---
title: "com_journal"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `com_journal`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: no registration exists; every cited site only writes it with <code>Cvar_Set</code>, so a value you set is replaced the next time that code runs.</p>

Controls `com_journal` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Manually settable | No; the game writes this value. |
| Cheat protected | No |
| Network scope | `client-or-server`: Engine code in both the client and the dedicated server; each uses its own value. |
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/qcommon/common.cpp:927](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L927) |
| `2` | Selects the code path tested for value 2. | [codemp/qcommon/common.cpp:931](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L931) |

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/qcommon/common.cpp:777](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/qcommon/common.cpp#L777)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/qcommon/common.cpp:938](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L938) (implicit Cvar_Set)
- behavior: [codemp/qcommon/common.cpp:923](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L923)
- behavior: [codemp/qcommon/common.cpp:927](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L927)
- behavior: [codemp/qcommon/common.cpp:931](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L931)
- behavior: [codemp/qcommon/common.cpp:955](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L955)
- behavior: [codemp/qcommon/common.cpp:971](https://github.com/taysta/TaystJK/blame/21044fb29768df0061bc4897bbb97d82304a1fe3/codemp/qcommon/common.cpp#L971)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/21044fb29768df0061bc4897bbb97d82304a1fe3"><code>21044fb29768</code></a> on 2026-10-25. Anything merged after that is not reflected here.</p>
