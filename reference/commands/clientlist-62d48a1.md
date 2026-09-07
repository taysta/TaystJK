---
title: "clientlist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `clientlist`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

Displays a list of all connected clients and their real client numbers

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `clientlist` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Commit evidence: [`424691eaaa52`](https://github.com/taysta/TaystJK/commit/424691eaaa5203a23fd6a24c89bc7d352ecd60ec)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:299](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/cgame/cg_consolecmds.c#L299)
- Attribution method: `post-import-openjk-head-presence`
- Attribution confidence: `high`

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2451) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:158](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L158)
- documentation: [codemp/ui/ui_xdocs.h:619](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L619)
