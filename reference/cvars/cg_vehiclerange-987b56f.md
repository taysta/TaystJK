---
title: "cg_vehicleRange"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_vehicleRange`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Offset vehicle camera ranges (useful for ultrawide monitors)

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
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:583](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L583) |
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

- Ultimate-origin introduction: [`174a753ff414`](https://github.com/taysta/TaystJK/commit/174a753ff4143f03f7b6074675b1a63dac294dd6) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2025-11-15`, PR opened `2025-11-15`, integrated `2025-11-28`)
- Origin pull request: [#274](https://github.com/taysta/TaystJK/pull/274)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:367](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L367)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-11-15` | [2025-11-15](https://github.com/taysta/TaystJK/pull/274) | `2025-11-28` | [`174a753ff414`](https://github.com/taysta/TaystJK/commit/174a753ff4143f03f7b6074675b1a63dac294dd6) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-11-15` | — | `2025-11-28` | [`174a753ff414`](https://github.com/videoP/jaPRO/commit/174a753ff4143f03f7b6074675b1a63dac294dd6) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:367](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L367) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_view.c:423](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L423)
- behavior: [codemp/cgame/cg_view.c:424](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L424)
- behavior: [codemp/ui/ui_xdocs.h:583](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L583)
- documentation: [codemp/ui/ui_xdocs.h:583](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L583)
