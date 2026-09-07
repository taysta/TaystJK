---
title: "cg_pitchHelperOffset"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_pitchHelperOffset`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Offset the green range up or down (eg. range 30, offset 10 = +25 to -5)

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Commit evidence: [`74597d49269a`](https://github.com/taysta/TaystJK/commit/74597d49269abe4383532d7e7f248c933f7e8076)
- Attribution method: `first-addition-in-registration-file-history`
- Attribution confidence: `medium`
- Notes: The first exact-name addition in the current registration file is a TaystJK commit; all configured upstream heads were also checked.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:94](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L94) (XCVAR_DEF)
- behavior: [codemp/cgame/hud_strafehelper.c:2447](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L2447)
- behavior: [codemp/ui/ui_xdocs.h:331](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L331)
- documentation: [codemp/ui/ui_xdocs.h:331](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L331)
