---
title: "g_tweakSaber"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_tweakSaber`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Configured with /tweakSaber command.

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
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `16` | CLIENT - also remove backwards run slowdown like jk2 | [codemp/game/g_local.h:277](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L277) |
| `128` | Enables the `ST_EASYBACKSLASH` code path. | [codemp/game/g_local.h:280](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L280) |
| `64` | Enables the `ST_FIXED_SABERSWITCH` code path. | [codemp/game/g_local.h:279](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L279) |
| `256` | Enables the `ST_JK2RDFA` code path. | [codemp/game/g_local.h:281](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L281) |
| `32` | Enables the `ST_NO_REDCHAIN` code path. | [codemp/game/g_local.h:278](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L278) |
| `2048` | Enables the `ST_SPINBACKSLASH` code path. | [codemp/game/g_local.h:284](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_local.h#L284) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:194](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L194)
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
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c`, `codemp/game/g_active.c` | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6b8655edcd6a`](https://github.com/eternalcodes/EternalJK/commit/6b8655edcd6adab847f2f929153cce5f35908e96)<br>ok | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c`, `codemp/game/w_saber.c` | `high` |
| `2018-10-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d5b95947d04f`](https://github.com/videoP/jaPRO/commit/d5b95947d04f3fb485bbfccb41c5ecadd1587946)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/w_saber.c` | `high` |
| `2020-03-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`27748943c598`](https://github.com/eternalcodes/EternalJK/commit/27748943c59875f3840c521a89089d5936d632c8)<br>Fix active saber blocks with MP damages | Changed an exact bound cvar-variable reference. `codemp/game/w_saber.c` | `medium` |
| `2020-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64349df34731`](https://github.com/eternalcodes/EternalJK/commit/64349df34731d25ab2efaaed8e9025d7cb2d9cf4)<br>JK2 style swing improvements | Changed an exact bound cvar-variable reference. `codemp/game/bg_local.h`, `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `medium` |
| `2020-05-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c01c9ba41a7f`](https://github.com/eternalcodes/EternalJK/commit/c01c9ba41a7f8c8433c35985d4c8ed107d2f1192)<br>fix client staff/duals attack prediction after JK2 swing style updates | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f124ea7347c4`](https://github.com/eternalcodes/EternalJK/commit/f124ea7347c4f2a6587be2359d0a525bcbc20a50)<br>Fix JK2 swing sabertweak x2 | Changed an exact bound cvar-variable reference. `codemp/game/bg_panimate.c`, `codemp/game/bg_saber.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/w_saber.c` | `high` |
| `2024-04-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`959f7e18d624`](https://github.com/taysta/TaystJK/commit/959f7e18d624c6dba465b711f6f7447d005a6450) · [PR #191](https://github.com/taysta/TaystJK/pull/191)<br>Rend2 & jaPRO updates (#191) | Changed an exact bound cvar-variable reference. `codemp/game/w_saber.c` | `medium` |
| `2024-05-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`13eac340e1ce`](https://github.com/videoP/jaPRO/commit/13eac340e1ce2e81ab6cbb47e21d984892a78c2a) · [PR #193](https://github.com/taysta/TaystJK/pull/193)<br>Japro update (#193) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:193](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L193) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:8387](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L8387)
- behavior: [codemp/game/bg_panimate.c:2701](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_panimate.c#L2701)
- behavior: [codemp/game/bg_pmove.c:4465](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L4465)
- behavior: [codemp/game/bg_pmove.c:6227](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L6227)
- behavior: [codemp/game/bg_pmove.c:9055](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L9055)
- documentation: [docs/japro_docs.md:13](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/docs/japro_docs.md#L13)
