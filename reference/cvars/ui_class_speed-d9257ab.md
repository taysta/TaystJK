---
title: "ui_class_speed"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_class_speed`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: no registration exists — every cited site only writes it with <code>Cvar_Set</code>, so a value you set is replaced the next time that code runs.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) — [how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `va("%3.2f", scl->speed)` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No — the game writes this value. |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/ui/ui_main.c:9580](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/ui/ui_main.c#L9580)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/ui/ui_main.c:7379](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L7379) (implicit Cvar_Set)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
