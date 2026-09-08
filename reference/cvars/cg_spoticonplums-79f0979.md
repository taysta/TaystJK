---
title: "cg_spotIconPlums"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_spotIconPlums`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_spotIconPlums` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_effects.c:1054](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_effects.c#L1054) |
| `1` | Enabled. | [codemp/cgame/cg_effects.c:1054](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_effects.c#L1054) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`258031c97e93`](https://github.com/videoP/jaPRO/commit/258031c97e933f2293dc35c18af5ea16847f0241) on `2024-04-15` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#188](https://github.com/taysta/TaystJK/pull/188)
- Matching squash bullet: `[jaPRO/cgame] Restore cg_scorePlums default value and introduce cg_strafeTrailPlums and cg_spotIconPlums where new cg_scorePlums usages had occurred in jaPRO`
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:225](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L225)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. An identifier-adjacent source/commit/PR line explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-04-15` | [`258031c97e93`](https://github.com/taysta/TaystJK/commit/258031c97e933f2293dc35c18af5ea16847f0241) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-04-15` | [`258031c97e93`](https://github.com/videoP/jaPRO/commit/258031c97e933f2293dc35c18af5ea16847f0241) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:228](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L228) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_effects.c:1054](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_effects.c#L1054)
