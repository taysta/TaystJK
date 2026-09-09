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
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:162](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L162) |
| In-game menu | No |
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

- Ultimate-origin introduction: [`17085eaeadd0`](https://github.com/taysta/TaystJK/commit/17085eaeadd029b670346330588de005c6c41158) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-08-06`, PR opened `2026-08-06`, integrated `2026-08-06`)
- Origin pull request: [#356](https://github.com/taysta/TaystJK/pull/356)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:58](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L58)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-08-06` | [2026-08-06](https://github.com/taysta/TaystJK/pull/356) | `2026-08-06` | [`17085eaeadd0`](https://github.com/taysta/TaystJK/commit/17085eaeadd029b670346330588de005c6c41158) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:58](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L58) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:6608](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6608)
- behavior: [codemp/ui/ui_xdocs.h:162](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L162)
- documentation: [codemp/ui/ui_xdocs.h:162](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L162)
