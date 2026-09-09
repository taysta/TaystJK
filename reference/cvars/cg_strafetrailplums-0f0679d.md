---
title: "cg_strafeTrailPlums"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_strafeTrailPlums`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_strafeTrailPlums` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`258031c97e93`](https://github.com/videoP/jaPRO/commit/258031c97e933f2293dc35c18af5ea16847f0241) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-04-15`, integrated `2024-04-15`)
- Origin pull request: [#188](https://github.com/taysta/TaystJK/pull/188)
- Matching squash bullet: `[jaPRO/cgame] Restore cg_scorePlums default value and introduce cg_strafeTrailPlums and cg_spotIconPlums where new cg_scorePlums usages had occurred in jaPRO`
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:224](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L224)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-04-15` | [2024-04-12](https://github.com/taysta/TaystJK/pull/188) | `2024-04-15` | [`258031c97e93`](https://github.com/taysta/TaystJK/commit/258031c97e933f2293dc35c18af5ea16847f0241) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-04-15` | — | `2024-04-15` | [`258031c97e93`](https://github.com/videoP/jaPRO/commit/258031c97e933f2293dc35c18af5ea16847f0241) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:227](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L227) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_snapshot.c:647](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_snapshot.c#L647)
