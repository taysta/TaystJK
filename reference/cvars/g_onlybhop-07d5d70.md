---
title: "g_onlyBhop"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_onlyBhop`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

1=Disable forcejumps for all players. 2=Let players choose if they want to disable forcejumps.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Disable forcejumps for all players. | [docs/japro_docs.md:51](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L51) |
| `2` | Let players choose if they want to disable forcejumps. | [docs/japro_docs.md:51](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L51) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:233](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L233)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2019-02-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0e8b124d1344`](https://github.com/eternalcodes/EternalJK/commit/0e8b124d1344ca90657c2784de74586542dbde93)<br>Only lowjump (with current jump level) with onlybhop+crouchjump restrict | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbd3c0972e77`](https://github.com/eternalcodes/EternalJK/commit/dbd3c0972e777da1780b93834631adf8c4cc5444)<br>Fix CMake script | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:232](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L232) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:3544](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L3544)
- behavior: [codemp/game/g_cmds.c:8464](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8464)
- behavior: [codemp/game/g_cmds.c:8466](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8466)
- behavior: [codemp/game/g_cvar.c:113](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cvar.c#L113)
- behavior: [codemp/game/g_cvar.c:117](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cvar.c#L117)
- documentation: [docs/japro_docs.md:51](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L51)
