---
title: "ui_playerServersFound"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_playerServersFound`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_server.menu:1772](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_server.menu#L1772) |
| Default | `va( holdSPString,uiInfo.pendingServerStatus.num, numFound)` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `va( holdSPString, 0, "s", uiInfo.findPlayerName)` | `ui` | `—` | `always` |
| `va( holdSPString, uiInfo.numFoundPlayerServers-1, uiInfo.numFoundPlayerServers == 2 ? "":"s", uiInfo.findPlayerName)` | `ui` | `—` | `always` |
| `va( holdSPString,uiInfo.pendingServerStatus.num, numFound)` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/ui/ui_main.c:8199](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/ui/ui_main.c#L8199)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/ui/ui_main.c:9416](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9416) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:9459](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9459) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:9489](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9489) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:9511](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9511) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:9518](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9518) (implicit Cvar_Set)
