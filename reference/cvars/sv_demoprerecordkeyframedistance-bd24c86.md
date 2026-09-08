---
title: "sv_demoPreRecordKeyframeDistance"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_demoPreRecordKeyframeDistance`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

A demo can only start with a gamestate and full non-delta snapshot. How often should we save such a gamestate message? The shorter the distance, the more precisely the pre-record duration will be kept, but also the higher the RAM usage and regularity of non-delta frames being sent to the clients.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `5` |
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
- Pull request: [#2](https://github.com/taysta/TaystJK/pull/2)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-06-23` | [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) | Additional dated evidence |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-06-23` | [`64b8343c85ea`](https://github.com/videoP/jaPRO/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) | Additional dated evidence |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`80bf35177f0a`](https://github.com/taysta/TaystJK/commit/80bf35177f0a769bb51f61c65e3148a69997ed8a) · [PR #88](https://github.com/taysta/TaystJK/pull/88)<br>Merge pull request #88 from TomArrow/taystjk_demomemorymanage | Changed an exact bound cvar-variable reference. `codemp/server/sv_snapshot.cpp` | `medium` |
| `2024-01-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a05fdded5341`](https://github.com/taysta/TaystJK/commit/a05fdded53412d4ab5c357a262f5a7657da1fca5) · [PR #102](https://github.com/taysta/TaystJK/pull/102)<br>- Fix: Pre-recording potentially not working after map changes/server time restarts. (#102) | Changed an exact bound cvar-variable reference. `codemp/server/sv_snapshot.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1059](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L1059) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_snapshot.cpp:865](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_snapshot.cpp#L865)
- behavior: [codemp/server/sv_ccmds.cpp:1642](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_ccmds.cpp#L1642)
- behavior: [codemp/server/server.h:140](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L140)
- behavior: [codemp/server/server.h:144](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/server.h#L144)
- documentation: [docs/japro_docs.md:135](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L135)
