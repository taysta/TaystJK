---
title: "bot_visualizejumppads"
layout: reference
nav_exclude: true
search_exclude: false
---

# `bot_visualizejumppads`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Show jumppads

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_CHEAT` — requires cheats

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_bot.cpp:641](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_bot.cpp#L641)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/server/sv_bot.cpp:662](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_bot.cpp#L662) (Cvar_Get)
- behavior: [codemp/botlib/be_aas_reach.cpp:297](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_aas_reach.cpp#L297)
- behavior: [codemp/botlib/be_aas_reach.cpp:306](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_aas_reach.cpp#L306)
- behavior: [codemp/botlib/be_aas_reach.cpp:308](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_aas_reach.cpp#L308)
- behavior: [codemp/botlib/be_aas_reach.cpp:336](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_aas_reach.cpp#L336)
- behavior: [codemp/botlib/be_aas_reach.cpp:3492](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_aas_reach.cpp#L3492)
