---
title: "bot_reloadcharacters"
layout: reference
nav_exclude: true
search_exclude: false
---

# `bot_reloadcharacters`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Reload the bot characters each time

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
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/server/sv_bot.cpp:648](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/server/sv_bot.cpp#L648)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/server/sv_bot.cpp:669](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_bot.cpp#L669) (Cvar_Get)
- behavior: [codemp/botlib/be_ai_char.cpp:176](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_ai_char.cpp#L176)
- behavior: [codemp/botlib/be_ai_chat.cpp:2238](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_ai_chat.cpp#L2238)
- behavior: [codemp/botlib/be_ai_chat.cpp:2271](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_ai_chat.cpp#L2271)
- behavior: [codemp/botlib/be_ai_chat.cpp:2959](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_ai_chat.cpp#L2959)
- behavior: [codemp/botlib/be_ai_weight.cpp:156](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/botlib/be_ai_weight.cpp#L156)
