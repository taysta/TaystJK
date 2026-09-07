---
title: "chatlog"
layout: reference
nav_exclude: true
search_exclude: false
---

# `chatlog`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_ChatLogSettings_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `chatlog [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Commit evidence: [`328d55f0062f`](https://github.com/taysta/TaystJK/commit/328d55f0062f745722046389d7b9744ec050d77f)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2200](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2200)
- Attribution method: `upstream-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2521](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2521) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:1923](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1923)
