---
title: "g_tweakWeapons"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_tweakWeapons`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Configured with /tweakWeapons command

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
| `524288` | Enables the `WT_ANTI_VEHICLE` code path. | [codemp/game/g_local.h:213](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L213) |
| `67108864` | Enables the `WT_PROJ_SNIPER` code path. | [codemp/game/g_local.h:220](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L220) |
| `134217728` | Move this into g_tribesmode surely..? | [codemp/game/g_local.h:221](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L221) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-01-11`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:219](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L219)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-11` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`09e74095ff07`](https://github.com/eternalcodes/EternalJK/commit/09e74095ff0710d2c809cc402ed5e3b533f850ae)<br>Add stun baton to roll styles, let ppl roll with it rewrite race weapon giving code a bit | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2018-10-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d5b95947d04f`](https://github.com/videoP/jaPRO/commit/d5b95947d04f3fb485bbfccb41c5ecadd1587946)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c` | `high` |
| `2020-06-17` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`27b9e6ab27a4`](https://github.com/videoP/jaPRO/commit/27b9e6ab27a467db3024373db76ebf967b1afa9f)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/g_combat.c`, `codemp/game/g_missile.c` and 1 more | `high` |
| `2023-12-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`e194863d03f8`](https://github.com/taysta/TaystJK/commit/e194863d03f85d2e6dcfd9cf84233e2cc6614df2)<br>Fix some compiler warnings | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2023-12-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`41c7e75be47a`](https://github.com/videoP/jaPRO/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) · [PR #57](https://github.com/taysta/TaystJK/pull/57)<br>Japro update (#57) | Changed an exact bound cvar-variable reference. `codemp/game/NPC_AI_Jedi.c`, `codemp/game/g_weapon.c` | `high` |
| `2023-12-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`edec69cec7d0`](https://github.com/videoP/jaPRO/commit/edec69cec7d0e48dbdb66ac78318371abc222573) · [PR #58](https://github.com/taysta/TaystJK/pull/58)<br>Japro update (#58) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2023-12-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9b0d32775232`](https://github.com/taysta/TaystJK/commit/9b0d32775232ffd342c7200c757ce6c2df9bb26c)<br>tribes wep tweaks | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_combat.c`, `codemp/game/g_weapon.c` | `medium` |
| `2023-12-28` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3567d72d98c5`](https://github.com/videoP/jaPRO/commit/3567d72d98c5b41549e76ef6e4841bb14c318fba) · [PR #64](https://github.com/taysta/TaystJK/pull/64)<br>Update japro (#64) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c`, `codemp/game/g_cvar.c`, `codemp/game/g_weapon.c` | `high` |
| `2023-12-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`06c84155e1fb`](https://github.com/videoP/jaPRO/commit/06c84155e1fb0b3aecfdffd9488d910345d80ea1) · [PR #65](https://github.com/taysta/TaystJK/pull/65)<br>Japro fixup (#65) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_client.c`, `codemp/game/g_combat.c` and 3 more | `high` |
| `2023-12-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b4dc4332b515`](https://github.com/videoP/jaPRO/commit/b4dc4332b51568e107049216105092af9658af3b) · [PR #69](https://github.com/taysta/TaystJK/pull/69)<br>Japro update (#69) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/bg_pmove.c`, `codemp/game/g_cmds.c` and 3 more | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9e120086add8`](https://github.com/videoP/jaPRO/commit/9e120086add83f23befd7186ece215c286b943c8) · [PR #71](https://github.com/taysta/TaystJK/pull/71)<br>Japro update (#71) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) · [PR #74](https://github.com/taysta/TaystJK/pull/74)<br>Japro update (#74) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c`, `codemp/game/g_missile.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`e17f0f8fa133`](https://github.com/videoP/jaPRO/commit/e17f0f8fa13303cee8a377a03b6a49fc78c547dd) · [PR #75](https://github.com/taysta/TaystJK/pull/75)<br>Japro update (#75) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cab839d15251`](https://github.com/videoP/jaPRO/commit/cab839d1525122e2b6b7c3194ca66359ca240acf) · [PR #77](https://github.com/taysta/TaystJK/pull/77)<br>Japro update (#77) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c` | `high` |
| `2024-01-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0129a3137221`](https://github.com/taysta/TaystJK/commit/0129a3137221f29f545c5783091a708b7e856b09)<br>Remove some blank spaces/newlines and a code duplication | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2024-01-06` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`668338988def`](https://github.com/videoP/jaPRO/commit/668338988def7a28cb6cfbf9ffb8d3848a391662) · [PR #79](https://github.com/taysta/TaystJK/pull/79)<br>Japro update (#79) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`931f5d5c9044`](https://github.com/videoP/jaPRO/commit/931f5d5c90442d9f4d08c712d5e30537045416d3) · [PR #80](https://github.com/taysta/TaystJK/pull/80)<br>Japro update (#80) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c`, `codemp/game/g_items.c`, `codemp/game/g_main.c` and 1 more | `high` |
| `2024-01-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`751a7a93c325`](https://github.com/videoP/jaPRO/commit/751a7a93c325de5946dabbd4cff149b0cc44cc4b) · [PR #81](https://github.com/taysta/TaystJK/pull/81)<br>Japro update (#81) | Changed an exact bound cvar-variable reference. `codemp/game/bg_slidemove.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c`, `codemp/game/bg_saberLoad.c` and 7 more | `high` |
| `2024-01-10` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`90d3c68f2da9`](https://github.com/videoP/jaPRO/commit/90d3c68f2da918f353b24bff60e49066dd018806) · [PR #84](https://github.com/taysta/TaystJK/pull/84)<br>Japro update (#84) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_client.c`, `codemp/game/g_missile.c` and 2 more | `high` |
| `2024-01-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7a38e0e45170`](https://github.com/videoP/jaPRO/commit/7a38e0e4517065529ced6323cb23dbd12b49704d) · [PR #87](https://github.com/taysta/TaystJK/pull/87)<br>Japro update (#87) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c`, `codemp/game/g_items.c`, `codemp/game/g_missile.c` and 1 more | `high` |
| `2024-01-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`1967d08be20f`](https://github.com/videoP/jaPRO/commit/1967d08be20fe45f068fc5bfc835ccf63eaff09f) · [PR #89](https://github.com/taysta/TaystJK/pull/89)<br>Japro update (#89) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`367673403724`](https://github.com/videoP/jaPRO/commit/367673403724cb2a99237112e50c7a8aa3c0ff42) · [PR #92](https://github.com/taysta/TaystJK/pull/92)<br>Japro update (#92) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c`, `codemp/game/g_items.c` | `high` |
| `2024-01-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) · [PR #95](https://github.com/taysta/TaystJK/pull/95)<br>Japro update (#95) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_combat.c`, `codemp/game/g_utils.c` and 1 more | `high` |
| `2024-01-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cfe93fa637b5`](https://github.com/videoP/jaPRO/commit/cfe93fa637b5410c77a8cdd9e3b69eb7bbdc1705) · [PR #97](https://github.com/taysta/TaystJK/pull/97)<br>Japro update (#97) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-17` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c3293a76c178`](https://github.com/taysta/TaystJK/commit/c3293a76c1788eb104373f84a58a0219e5098bf5) · [PR #100](https://github.com/taysta/TaystJK/pull/100)<br>conc sniper uses energy like phase rifle, mortar  FX tweak, bounce strength (#100) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/g_weapon.c` | `medium` |
| `2024-01-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8cd2ef9d8dcb`](https://github.com/videoP/jaPRO/commit/8cd2ef9d8dcb331ecdf27076d9d1307dbd6ee0c5) · [PR #104](https://github.com/taysta/TaystJK/pull/104)<br>Japro update (#104) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`2812a6c459f5`](https://github.com/videoP/jaPRO/commit/2812a6c459f56f3190a0b269a5965eae63f36831) · [PR #108](https://github.com/taysta/TaystJK/pull/108)<br>Japro updates (#108) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-23` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`4ebe42313373`](https://github.com/videoP/jaPRO/commit/4ebe423133731609e58fd7f72fc05acd81d0c4cb) · [PR #109](https://github.com/taysta/TaystJK/pull/109)<br>Japro updates (#109) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93dfa66dc8e5`](https://github.com/videoP/jaPRO/commit/93dfa66dc8e5d49a7067d6f12818333e15366ead) · [PR #112](https://github.com/taysta/TaystJK/pull/112)<br>Japro updates (#112) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/w_force.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`388fc553f371`](https://github.com/videoP/jaPRO/commit/388fc553f371e34c929970c8bc6f09406d1da3ad) · [PR #114](https://github.com/taysta/TaystJK/pull/114)<br>Japro updates (#114) | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/g_combat.c`, `codemp/game/w_force.c` | `high` |
| `2024-01-25` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cd07288a30a6`](https://github.com/videoP/jaPRO/commit/cd07288a30a6aa276afdb11f1ae81e5e338134c3) · [PR #116](https://github.com/taysta/TaystJK/pull/116)<br>Japro updates (#116) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_weapon.c`, `codemp/game/w_force.c` | `high` |
| `2024-01-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a5c04e80d08f`](https://github.com/videoP/jaPRO/commit/a5c04e80d08fb4398d8ddc5fbcb9121bf4d7f8bd) · [PR #127](https://github.com/taysta/TaystJK/pull/127)<br>Japro updates (#127) | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_missile.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2024-02-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7dce9a576823`](https://github.com/videoP/jaPRO/commit/7dce9a5768238bbc22a004660c36c252c217701f) · [PR #134](https://github.com/taysta/TaystJK/pull/134)<br>Japro update (#134) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_cmds.c` | `high` |
| `2024-02-08` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c43219e502b9`](https://github.com/videoP/jaPRO/commit/c43219e502b96da39707d8ffaa9f2c35adb4f2f5) · [PR #136](https://github.com/taysta/TaystJK/pull/136)<br>Japro update - Surf Movement `/move surf` (#136) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-02-19` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0cf63a042a7b`](https://github.com/taysta/TaystJK/commit/0cf63a042a7bad37d8981c5828b39689d8c54ac0) · [PR #154](https://github.com/taysta/TaystJK/pull/154)<br>fix thrownade (#154) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2024-02-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) · [PR #157](https://github.com/taysta/TaystJK/pull/157)<br>Upstream update (#157) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0683da475d2a`](https://github.com/videoP/jaPRO/commit/0683da475d2a4eda63a78a006bd7976adbcf7e85)<br>[jaPRO/Tribes] Fixup tribes check | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |
| `2024-02-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`1119453aa232`](https://github.com/videoP/jaPRO/commit/1119453aa2329eab2ab5a95c501b126f3600730f) · [PR #159](https://github.com/taysta/TaystJK/pull/159)<br>Japro update (#159) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-03-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9912f30e367f`](https://github.com/taysta/TaystJK/commit/9912f30e367f9857bb65dc3047f77fd1b325ad4b) · [PR #166](https://github.com/taysta/TaystJK/pull/166)<br>Japro update (#166) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `medium` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`5f092f170d52`](https://github.com/taysta/TaystJK/commit/5f092f170d52ca07a53ed8005108fdee20776a70)<br>fix some weaponswitch tribes stuff? | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2024-04-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`959f7e18d624`](https://github.com/taysta/TaystJK/commit/959f7e18d624c6dba465b711f6f7447d005a6450) · [PR #191](https://github.com/taysta/TaystJK/pull/191)<br>Rend2 & jaPRO updates (#191) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `medium` |
| `2024-05-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`829a59ad0875`](https://github.com/videoP/jaPRO/commit/829a59ad08755dee1f62049d9a03be252668e47a) · [PR #200](https://github.com/taysta/TaystJK/pull/200)<br>[jaPRO] Fixup clang compiler warnings (#200) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `high` |
| `2024-05-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8188f06a4e61`](https://github.com/videoP/jaPRO/commit/8188f06a4e617f146c075888a885ab2dedeecd73) · [PR #204](https://github.com/taysta/TaystJK/pull/204)<br>Japro update (#204) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c`, `codemp/game/g_weapon.c`, `codemp/game/w_force.c` | `high` |
| `2024-05-28` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`87145eba654c`](https://github.com/videoP/jaPRO/commit/87145eba654c70609b15f9e6f6e9588d72ae0a5e) · [PR #206](https://github.com/taysta/TaystJK/pull/206)<br>Japro update (#206) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_cmds.c`, `codemp/game/g_combat.c` and 1 more | `high` |
| `2024-09-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`100cdfc116b9`](https://github.com/videoP/jaPRO/commit/100cdfc116b94679dbdc41940a21b36acc492b7b) · [PR #212](https://github.com/taysta/TaystJK/pull/212)<br>Japro Update | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:218](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L218) (XCVAR_DEF)
- behavior: [codemp/game/NPC_AI_Jedi.c:6310](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/NPC_AI_Jedi.c#L6310)
- behavior: [codemp/game/NPC_spawn.c:1539](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/NPC_spawn.c#L1539)
- behavior: [codemp/game/ai_main.c:4639](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L4639)
- behavior: [codemp/game/ai_main.c:4653](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L4653)
- behavior: [codemp/game/ai_main.c:4657](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L4657)
- documentation: [docs/japro_docs.md:38](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L38)
