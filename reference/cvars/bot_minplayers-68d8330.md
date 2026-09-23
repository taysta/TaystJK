---
title: "bot_minplayers"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `bot_minplayers`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Minimum players in a team or the game

## At a glance

| Field | Value |
|:--|:--|
| Category | Bots & AI |
| Module | `game` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_bot.c:665](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_bot.c#L665) |
| `1` | Enabled. | [codemp/game/g_bot.c:665](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_bot.c#L665) |

## Flags

- `CVAR_SERVERINFO`: published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-server` | `—` | `always` |
| `0` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_bot.c:1306](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_bot.c#L1306)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_bot.c`, `codemp/game/g_main.c` and 1 more | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_bot.c` | `high` |

## Evidence

- registration: [codemp/game/g_bot.c:1356](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_bot.c#L1356) (Cvar_Register)
- registration: [codemp/server/sv_bot.cpp:681](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_bot.cpp#L681) (Cvar_Get)
- behavior: [codemp/game/g_bot.c:665](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_bot.c#L665)
- behavior: [codemp/game/g_bot.c:669](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_bot.c#L669)
- behavior: [codemp/game/g_bot.c:654](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_bot.c#L654)
- behavior: [codemp/cgame/cg_servercmds.c:324](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_servercmds.c#L324)
- behavior: [codemp/game/g_main.c:3041](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_main.c#L3041)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
