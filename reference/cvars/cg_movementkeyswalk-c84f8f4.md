---
title: "cg_movementKeysWalk"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_movementKeysWalk`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Display walk movement key input

## At a glance

| Field | Value |
|:--|:--|
| Category | Movement & race |
| Feature family | Movement keys |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:104](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L104) |
| In-game menu | No |
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

- Ultimate-origin introduction: [`77a255000dd4`](https://github.com/taysta/TaystJK/commit/77a255000dd43e3884ccd2651364f23284fc0161) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2026-04-18`, PR opened `2026-06-07`, integrated `2026-06-07`)
- Origin pull request: [#318](https://github.com/taysta/TaystJK/pull/318)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:45](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L45)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-04-18` | [2026-06-07](https://github.com/taysta/TaystJK/pull/318) | `2026-06-07` | [`77a255000dd4`](https://github.com/taysta/TaystJK/commit/77a255000dd43e3884ccd2651364f23284fc0161) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2026-04-18` | — | `2026-06-07` | [`77a255000dd4`](https://github.com/videoP/jaPRO/commit/77a255000dd43e3884ccd2651364f23284fc0161) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:45](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L45) (XCVAR_DEF)
- behavior: [codemp/cgame/hud_strafehelper.c:2322](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2322)
- behavior: [codemp/cgame/hud_strafehelper.c:2362](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2362)
- behavior: [codemp/cgame/hud_strafehelper.c:2279](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2279)
- behavior: [codemp/cgame/hud_strafehelper.c:2285](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2285)
- behavior: [codemp/ui/ui_xdocs.h:104](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L104)
- documentation: [codemp/ui/ui_xdocs.h:104](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L104)
