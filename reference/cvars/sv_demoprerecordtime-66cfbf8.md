---
title: "sv_demoPreRecordTime"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_demoPreRecordTime`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

How many seconds of past packets should be stored for server demo pre-recording?

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `15` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c)
- Origin pull request: [#2](https://github.com/taysta/TaystJK/pull/2)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-06-14` | [2023-06-14](https://github.com/taysta/TaystJK/pull/2) | `2023-06-23` | [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-06-14` | — | `2023-06-23` | [`64b8343c85ea`](https://github.com/videoP/jaPRO/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`80bf35177f0a`](https://github.com/taysta/TaystJK/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) · [PR #88](https://github.com/taysta/TaystJK/pull/88)<br>Merge pull request #88 from TomArrow/taystjk_demomemorymanage | Changed an exact bound cvar-variable reference. `codemp/server/sv_snapshot.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1058](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1058) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_snapshot.cpp:898](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L898)
- behavior: [codemp/server/sv_snapshot.cpp:893](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L893)
- behavior: [codemp/server/sv_snapshot.cpp:894](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L894)
- documentation: [docs/japro_docs.md:134](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L134)
