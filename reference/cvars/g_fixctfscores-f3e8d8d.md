---
title: "g_fixCTFScores"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixCTFScores`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Tweak CTF score amounts.

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_combat.c:2694](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_combat.c#L2694) |
| `1` | Enabled. | [codemp/game/g_combat.c:2694](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_combat.c#L2694) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:188](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L188)
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
| `2018-10-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3340e21e273b`](https://github.com/videoP/jaPRO/commit/3340e21e273b5f68f4e617ac35b38bedc5d34d81)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) · [PR #74](https://github.com/taysta/TaystJK/pull/74)<br>Japro update (#74) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `high` |
| `2024-03-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9912f30e367f`](https://github.com/taysta/TaystJK/commit/9912f30e367f9857bb65dc3047f77fd1b325ad4b) · [PR #166](https://github.com/taysta/TaystJK/pull/166)<br>Japro update (#166) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `medium` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`5e05b78a788d`](https://github.com/taysta/TaystJK/commit/5e05b78a788dc9bb49a0d8fe5af9f7a9d4a22e73)<br>fixes | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `medium` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a7ef18daa5bb`](https://github.com/taysta/TaystJK/commit/a7ef18daa5bbef1fadfc9af68997e787dcfd166c)<br>flag points fix | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `medium` |
| `2024-05-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93c2c1a5b4ef`](https://github.com/videoP/jaPRO/commit/93c2c1a5b4efbea4e009e65fbdbf5148cd68771c) · [PR #201](https://github.com/taysta/TaystJK/pull/201)<br>Japro update (#201) | Changed an exact bound cvar-variable reference. `codemp/game/g_trigger.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:187](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L187) (XCVAR_DEF)
- behavior: [codemp/game/g_combat.c:2694](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_combat.c#L2694)
- behavior: [codemp/game/g_team.c:886](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_team.c#L886)
- behavior: [codemp/game/g_cmds.c:8457](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8457)
- behavior: [codemp/game/g_team.c:393](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_team.c#L393)
- behavior: [codemp/game/g_team.c:398](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_team.c#L398)
- documentation: [docs/japro_docs.md:8](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L8)
