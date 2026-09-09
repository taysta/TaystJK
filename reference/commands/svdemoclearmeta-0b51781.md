---
title: "svdemoclearmeta"
layout: reference
nav_exclude: true
search_exclude: false
---

# `svdemoclearmeta`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Clears metadata for server-side demos for one player. Call with clientnum.

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
| Syntax | `svdemoclearmeta [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

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
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed the registered command handler. `codemp/server/sv_ccmds.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_ccmds.cpp:2346](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2346) (Cmd_AddCommand); condition `defined(DEDICATED)`
- handler: [codemp/server/sv_ccmds.cpp:2218](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2218)
- documentation: [docs/japro_docs.md:397](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L397)
