---
title: "cg_antiAmKiss"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_antiAmKiss`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_antiAmKiss` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`a5819fdb65ce`](https://github.com/taysta/TaystJK/commit/a5819fdb65ceb1e4a18177c0ccf6c3dbcdb94545)
- Attribution method: `identifier-adjacent-developer-lineage-credit`
- Attribution confidence: `high`
- Notes: Explicit Bucky developer credit identifies his unpublished EternalJK continuation as the origin; no public EternalJK registration is expected.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-20` | — | `2023-11-02` | [`a5819fdb65ce`](https://github.com/taysta/TaystJK/commit/a5819fdb65ceb1e4a18177c0ccf6c3dbcdb94545) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-20` | — | `2023-11-02` | [`a5819fdb65ce`](https://github.com/videoP/jaPRO/commit/a5819fdb65ceb1e4a18177c0ccf6c3dbcdb94545) | Other project appearance |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:97](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L97) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_view.c:2575](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L2575)
