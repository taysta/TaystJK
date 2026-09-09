---
title: "cg_killfeedX"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_killfeedX`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

Offset the killfeed's horizontal position from its current position

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

- Ultimate-origin introduction: [`0c734b5f2ee4`](https://github.com/taysta/TaystJK/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2023-10-03`, PR opened `2023-10-03`, integrated `2023-10-05`)
- Origin pull request: [#13](https://github.com/taysta/TaystJK/pull/13)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:428](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L428)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-03` | [2023-10-03](https://github.com/taysta/TaystJK/pull/13) | `2023-10-05` | [`0c734b5f2ee4`](https://github.com/taysta/TaystJK/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-03` | — | `2023-10-05` | [`0c734b5f2ee4`](https://github.com/videoP/jaPRO/commit/0c734b5f2ee4f69b8bcc07a3c4d6431b1ae341d6) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:428](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L428) (XCVAR_DEF)
- behavior: [codemp/cgame/hud_obituary.c:42](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_obituary.c#L42)
- behavior: [codemp/ui/ui_xdocs.h:536](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L536)
- documentation: [codemp/ui/ui_xdocs.h:536](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L536)
