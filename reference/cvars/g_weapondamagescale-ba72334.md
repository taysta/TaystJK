---
title: "g_weaponDamageScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_weaponDamageScale`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_weaponDamageScale` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:221](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L221)
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
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2023-12-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`41c7e75be47a`](https://github.com/videoP/jaPRO/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) · [PR #57](https://github.com/taysta/TaystJK/pull/57)<br>Japro update (#57) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2023-12-23` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`f0a9a1c00a10`](https://github.com/videoP/jaPRO/commit/f0a9a1c00a10e53e0f291c9eb3327b72c310cb0d) · [PR #61](https://github.com/taysta/TaystJK/pull/61)<br>Japro updates (#61) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2023-12-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9b0d32775232`](https://github.com/taysta/TaystJK/commit/9b0d32775232ffd342c7200c757ce6c2df9bb26c)<br>tribes wep tweaks | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2023-12-28` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3567d72d98c5`](https://github.com/videoP/jaPRO/commit/3567d72d98c5b41549e76ef6e4841bb14c318fba) · [PR #64](https://github.com/taysta/TaystJK/pull/64)<br>Update japro (#64) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2023-12-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b4dc4332b515`](https://github.com/videoP/jaPRO/commit/b4dc4332b51568e107049216105092af9658af3b) · [PR #69](https://github.com/taysta/TaystJK/pull/69)<br>Japro update (#69) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0129a3137221`](https://github.com/taysta/TaystJK/commit/0129a3137221f29f545c5783091a708b7e856b09)<br>Remove some blank spaces/newlines and a code duplication | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2024-01-06` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`668338988def`](https://github.com/videoP/jaPRO/commit/668338988def7a28cb6cfbf9ffb8d3848a391662) · [PR #79](https://github.com/taysta/TaystJK/pull/79)<br>Japro update (#79) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`931f5d5c9044`](https://github.com/videoP/jaPRO/commit/931f5d5c90442d9f4d08c712d5e30537045416d3) · [PR #80](https://github.com/taysta/TaystJK/pull/80)<br>Japro update (#80) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c` | `high` |
| `2024-01-10` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`90d3c68f2da9`](https://github.com/videoP/jaPRO/commit/90d3c68f2da918f353b24bff60e49066dd018806) · [PR #84](https://github.com/taysta/TaystJK/pull/84)<br>Japro update (#84) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`1967d08be20f`](https://github.com/videoP/jaPRO/commit/1967d08be20fe45f068fc5bfc835ccf63eaff09f) · [PR #89](https://github.com/taysta/TaystJK/pull/89)<br>Japro update (#89) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) · [PR #95](https://github.com/taysta/TaystJK/pull/95)<br>Japro update (#95) | Changed an exact bound cvar-variable reference. `codemp/game/bg_slidemove.c`, `codemp/game/g_items.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-17` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c3293a76c178`](https://github.com/taysta/TaystJK/commit/c3293a76c1788eb104373f84a58a0219e5098bf5) · [PR #100](https://github.com/taysta/TaystJK/pull/100)<br>conc sniper uses energy like phase rifle, mortar  FX tweak, bounce strength (#100) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `medium` |
| `2024-01-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8cd2ef9d8dcb`](https://github.com/videoP/jaPRO/commit/8cd2ef9d8dcb331ecdf27076d9d1307dbd6ee0c5) · [PR #104](https://github.com/taysta/TaystJK/pull/104)<br>Japro update (#104) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-23` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`4ebe42313373`](https://github.com/videoP/jaPRO/commit/4ebe423133731609e58fd7f72fc05acd81d0c4cb) · [PR #109](https://github.com/taysta/TaystJK/pull/109)<br>Japro updates (#109) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93dfa66dc8e5`](https://github.com/videoP/jaPRO/commit/93dfa66dc8e5d49a7067d6f12818333e15366ead) · [PR #112](https://github.com/taysta/TaystJK/pull/112)<br>Japro updates (#112) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`388fc553f371`](https://github.com/videoP/jaPRO/commit/388fc553f371e34c929970c8bc6f09406d1da3ad) · [PR #114](https://github.com/taysta/TaystJK/pull/114)<br>Japro updates (#114) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-05-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8188f06a4e61`](https://github.com/videoP/jaPRO/commit/8188f06a4e617f146c075888a885ab2dedeecd73) · [PR #204](https://github.com/taysta/TaystJK/pull/204)<br>Japro update (#204) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-05-28` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`87145eba654c`](https://github.com/videoP/jaPRO/commit/87145eba654c70609b15f9e6f6e9588d72ae0a5e) · [PR #206](https://github.com/taysta/TaystJK/pull/206)<br>Japro update (#206) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:220](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L220) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:8395](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8395)
- behavior: [codemp/game/g_items.c:573](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_items.c#L573)
- behavior: [codemp/game/g_items.c:575](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_items.c#L575)
- behavior: [codemp/game/g_items.c:1721](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_items.c#L1721)
- behavior: [codemp/game/g_weapon.c:647](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_weapon.c#L647)
