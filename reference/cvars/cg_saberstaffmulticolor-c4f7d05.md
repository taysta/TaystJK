---
title: "cg_saberStaffMultiColor"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_saberStaffMultiColor`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_saberStaffMultiColor` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

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

- Ultimate-origin introduction: [`31486bc3a398`](https://github.com/videoP/jaPRO/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2023-11-02`, integrated `2023-11-02`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:95](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L95)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-02` | — | `2023-11-02` | [`31486bc3a398`](https://github.com/taysta/TaystJK/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-02` | — | `2023-11-02` | [`31486bc3a398`](https://github.com/videoP/jaPRO/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f) | Ultimate origin |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:98](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L98) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_players.c:7541](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L7541)
