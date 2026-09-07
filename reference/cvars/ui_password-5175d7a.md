---
title: "ui_password"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_password`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_password` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_NORESTART` — preserved across cvar restart

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`c6eb4507a9c5`](https://github.com/taysta/TaystJK/commit/c6eb4507a9c53d8a50b61c37ab72cb3491d41cdf)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:155](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L155)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/ui/ui_xcvar.h:157](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L157) (XCVAR_DEF)
- behavior: [codemp/ui/ui_main.c:7806](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L7806)
- behavior: [codemp/ui/ui_main.c:7808](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L7808)
