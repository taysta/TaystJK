---
title: "g_movementStyle"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_movementStyle`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Force movement style for players. 0=SIEGE 1=JKA 2=QW 3=CPM 4=Q3 5=PJK 6=WSW

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | SIEGE. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |
| `1` | JKA. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |
| `2` | QW. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |
| `3` | CPM. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |
| `4` | Q3. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |
| `5` | PJK. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |
| `6` | WSW. | [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:234](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L234)
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
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_active.c`, `codemp/game/g_cmds.c` | `medium` |
| `2019-02-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`08ee038fa4de`](https://github.com/eternalcodes/EternalJK/commit/08ee038fa4deede4ad45290f6a7358314d29f3df)<br>Allow onlybhop target_restrict change force jump level with count value, | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c635b474e0de`](https://github.com/eternalcodes/EternalJK/commit/c635b474e0de31387dbfa74438cc4b3866174148)<br>cgame updates for coop defrag | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_active.c`, `codemp/game/g_cmds.c` | `high` |
| `2024-03-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9912f30e367f`](https://github.com/taysta/TaystJK/commit/9912f30e367f9857bb65dc3047f77fd1b325ad4b) · [PR #166](https://github.com/taysta/TaystJK/pull/166)<br>Japro update (#166) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `medium` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fd60c90af33d`](https://github.com/taysta/TaystJK/commit/fd60c90af33defecee04566f23d593542b85a911)<br>bot cap routes | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `medium` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`30454fc96fad`](https://github.com/taysta/TaystJK/commit/30454fc96fad723017aa7e616aff885490766959)<br>bot cap ai tweak, crashfix? | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:233](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L233) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:8949](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8949)
- behavior: [codemp/game/ai_main.c:9017](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L9017)
- behavior: [codemp/game/bg_pmove.c:447](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L447)
- behavior: [codemp/game/bg_pmove.c:449](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L449)
- behavior: [codemp/game/bg_pmove.c:451](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L451)
- documentation: [docs/japro_docs.md:53](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L53)
