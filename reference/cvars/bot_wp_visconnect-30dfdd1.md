---
title: "bot_wp_visconnect"
layout: reference
nav_exclude: true
search_exclude: false
---

# `bot_wp_visconnect`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `bot_wp_visconnect` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/ai_main.c:7597](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/ai_main.c#L7597)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/ai_wpnav.c` | `medium` |

## Evidence

- registration: [codemp/game/ai_main.c:10708](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L10708) (Cvar_Register)
- behavior: [codemp/game/ai_wpnav.c:1514](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_wpnav.c#L1514)
