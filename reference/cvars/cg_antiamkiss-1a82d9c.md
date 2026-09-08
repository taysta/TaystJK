---
title: "cg_antiAmKiss"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_antiAmKiss`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_antiAmKiss` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

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

- Ultimate-origin introduction: [`a5819fdb65ce`](https://github.com/videoP/jaPRO/commit/a5819fdb65ceb1e4a18177c0ccf6c3dbcdb94545) on `2023-11-02` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:94](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L94)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. An identifier-adjacent source/commit/PR line explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-02` | [`a5819fdb65ce`](https://github.com/taysta/TaystJK/commit/a5819fdb65ceb1e4a18177c0ccf6c3dbcdb94545) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-02` | [`a5819fdb65ce`](https://github.com/videoP/jaPRO/commit/a5819fdb65ceb1e4a18177c0ccf6c3dbcdb94545) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:97](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L97) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_view.c:2575](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2575)
