---
title: "cg_drawTeamOverlayMaxHP"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawTeamOverlayMaxHP`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Combined health and shields that fills the bar on the team overlay. Only applies to cg_drawTeamOverlay 5 and 6. Base team FFA usually spawns 125 health and 25 shields with no shield pickups, servers running shield pickups want 225

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `150` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`17085eaeadd0`](https://github.com/taysta/TaystJK/commit/17085eaeadd029b670346330588de005c6c41158) on `2026-08-06` in <span class="label ref-origin ref-origin-taystjk">TaystJK</span>
- Pull request: [#356](https://github.com/taysta/TaystJK/pull/356)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:58](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L58)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-08-06` | [`17085eaeadd0`](https://github.com/taysta/TaystJK/commit/17085eaeadd029b670346330588de005c6c41158) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:58](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L58) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:6608](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6608)
- behavior: [codemp/ui/ui_xdocs.h:162](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L162)
- documentation: [codemp/ui/ui_xdocs.h:162](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L162)
