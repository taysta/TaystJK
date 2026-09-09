---
title: "cg_killSounds"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_killSounds`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Play a sound when you kill someone

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Don't play the kill sound (Base behavior) | [codemp/ui/ui_xdocs.h:402](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L402) |
| `1` | Play the kill sound | [codemp/ui/ui_xdocs.h:403](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L403) |
| `2` | Play the kill sound + midair kill sound | [codemp/ui/ui_xdocs.h:403](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L403) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`477910d22e11`](https://github.com/videoP/jaPRO/commit/477910d22e11f8e6a4967b7ea074bfb2de181a49) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-03-06`, integrated `2024-03-06`)
- Origin pull request: [#168](https://github.com/taysta/TaystJK/pull/168)
- Matching squash bullet: `[jaPRO/Sounds] Guard new killsounds behind cvar cg_killSound 0 = off 1 = on 2 = on + midair sound, commented out developer print, made them louder`
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:123](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L123)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-03-06` | [2024-03-06](https://github.com/taysta/TaystJK/pull/168) | `2024-03-06` | [`477910d22e11`](https://github.com/taysta/TaystJK/commit/477910d22e11f8e6a4967b7ea074bfb2de181a49) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-03-06` | — | `2024-03-06` | [`477910d22e11`](https://github.com/videoP/jaPRO/commit/477910d22e11f8e6a4967b7ea074bfb2de181a49) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9ab5d982d35b`](https://github.com/taysta/TaystJK/commit/9ab5d982d35b63227680f36dfb5c402264a0ddfe) · [PR #256](https://github.com/taysta/TaystJK/pull/256)<br>Merge pull request #256 from VincentMarnier/fix_killfeed | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:126](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L126) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_event.c:277](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L277)
- behavior: [codemp/cgame/cg_event.c:276](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L276)
- behavior: [codemp/ui/ui_xdocs.h:402](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L402)
- documentation: [codemp/ui/ui_xdocs.h:402](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L402)
