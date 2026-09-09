---
title: "cg_snapHudFps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_snapHudFps`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

FPS for calculations (Leave default for auto)

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/hud_strafehelper.c:2546](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2546) |
| `1` | Enabled. | [codemp/cgame/hud_strafehelper.c:2546](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2546) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2024-03-02`, PR opened `2023-11-05`, integrated `2024-03-02`)
- Origin pull request: [#46](https://github.com/taysta/TaystJK/pull/46)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:445](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L445)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-03-02` | [2023-11-05](https://github.com/taysta/TaystJK/pull/46) | `2024-03-02` | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-03-02` | — | `2024-03-02` | [`1d4c081cb762`](https://github.com/videoP/jaPRO/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:445](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L445) (XCVAR_DEF)
- behavior: [codemp/cgame/hud_strafehelper.c:2546](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2546)
- behavior: [codemp/ui/ui_xdocs.h:566](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L566)
- documentation: [codemp/ui/ui_xdocs.h:566](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L566)
