---
title: "cg_disruptorSpiralColor"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_disruptorSpiralColor`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Changes disruptor spiral color (accepts hexcode eg. xffffff)

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `xff2200` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Commit evidence: [`dd973c5506f8`](https://github.com/taysta/TaystJK/commit/dd973c5506f8cf0c4fdd1c03e577c488e277777c)
- Attribution method: `first-addition-in-registration-file-history`
- Attribution confidence: `medium`
- Notes: The first exact-name addition in the current registration file is a TaystJK commit; all configured upstream heads were also checked.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:423](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L423) (XCVAR_DEF)
- behavior: [codemp/cgame/fx_disruptor.c:197](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/fx_disruptor.c#L197)
- behavior: [codemp/cgame/fx_disruptor.c:198](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/fx_disruptor.c#L198)
- behavior: [codemp/ui/ui_xdocs.h:353](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L353)
- documentation: [codemp/ui/ui_xdocs.h:353](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L353)
