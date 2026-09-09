---
title: "cg_drawScoreY"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawScoreY`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Vertical offset for score counter on HUD

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
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

- Ultimate-origin introduction: [`4e5065dabda1`](https://github.com/taysta/TaystJK/commit/4e5065dabda1ea838fc9aa8bb9eaccaa161770fc) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-06-01`, PR opened `2026-06-01`, integrated `2026-06-01`)
- Origin pull request: [#309](https://github.com/taysta/TaystJK/pull/309)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:86](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L86)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-06-01` | [2026-06-01](https://github.com/taysta/TaystJK/pull/309) | `2026-06-01` | [`4e5065dabda1`](https://github.com/taysta/TaystJK/commit/4e5065dabda1ea838fc9aa8bb9eaccaa161770fc) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-06-01` | — | `2026-06-01` | [`4e5065dabda1`](https://github.com/videoP/jaPRO/commit/4e5065dabda1ea838fc9aa8bb9eaccaa161770fc) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:86](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L86) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:2221](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L2221)
- behavior: [codemp/cgame/cg_draw.c:2230](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L2230)
- behavior: [codemp/ui/ui_xdocs.h:275](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L275)
- documentation: [codemp/ui/ui_xdocs.h:275](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L275)
