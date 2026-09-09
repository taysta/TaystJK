---
title: "jcinfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `jcinfo`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Not a cvar, dont change it

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_effects.c:676](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_effects.c#L676) |
| `1` | Enabled. | [codemp/cgame/cg_effects.c:676](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_effects.c#L676) |

## Flags

- `CVAR_ROM` — read-only after registration
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-01-11`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:298](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L298)
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
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3)<br>Merge pull request #3 from Bucky21659/master | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_local.h`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`09e74095ff07`](https://github.com/eternalcodes/EternalJK/commit/09e74095ff0710d2c809cc402ed5e3b533f850ae)<br>Add stun baton to roll styles, let ppl roll with it rewrite race weapon giving code a bit | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc10f7b67c56`](https://github.com/eternalcodes/EternalJK/commit/dc10f7b67c5611ae941cecbde51a85649a27c606)<br>Auto stash before rebase of "origin/master" | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_effects.c`, `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_event.c` and 6 more | `high` |
| `2018-09-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`88b547448bb8`](https://github.com/eternalcodes/EternalJK/commit/88b547448bb881aed4d42b537b3f8c6201fd91d1)<br>racemode roll fix, whitespace fix, followfastest optimization, getmovementstyle simplify | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-09-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`879b06083542`](https://github.com/videoP/jaPRO/commit/879b060835428b28fe2bd771d1ba2a1e8f9fcb65)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `high` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `high` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2019-02-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0e8b124d1344`](https://github.com/eternalcodes/EternalJK/commit/0e8b124d1344ca90657c2784de74586542dbde93)<br>Only lowjump (with current jump level) with onlybhop+crouchjump restrict | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`de5cb0c0b3ef`](https://github.com/videoP/jaPRO/commit/de5cb0c0b3ef12a888b24f44e1be44009dce11c0)<br>Improve performance offline+during jaPRO demo playback | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `high` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_servercmds.c`, `codemp/cgame/cg_weaponinit.c` and 3 more | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`65e71ac6da40`](https://github.com/eternalcodes/EternalJK/commit/65e71ac6da408f322a0c825bf0c3f61c9ce28b1d)<br>Fix headslide prediction since cgame mod detection refactoring. | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2020-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64349df34731`](https://github.com/eternalcodes/EternalJK/commit/64349df34731d25ab2efaaed8e9025d7cb2d9cf4)<br>JK2 style swing improvements | Changed an exact bound cvar-variable reference. `codemp/game/bg_local.h`, `codemp/game/bg_pmove.c`, `codemp/game/bg_saber.c` | `medium` |
| `2020-05-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c01c9ba41a7f`](https://github.com/eternalcodes/EternalJK/commit/c01c9ba41a7f8c8433c35985d4c8ed107d2f1192)<br>fix client staff/duals attack prediction after JK2 swing style updates | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c` | `medium` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c` | `high` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`002cfb0a3a8b`](https://github.com/eternalcodes/EternalJK/commit/002cfb0a3a8b12afeb35f537c01769d35701b7cf)<br>Always disable legdangle in racemode | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_cvar.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c635b474e0de`](https://github.com/eternalcodes/EternalJK/commit/c635b474e0de31387dbfa74438cc4b3866174148)<br>cgame updates for coop defrag | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5f9884ea53d2`](https://github.com/eternalcodes/EternalJK/commit/5f9884ea53d24fda9ac5a095ed552ae6a3579a3b)<br>cgame updates for coop x2 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_event.c` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`848ce21a29dd`](https://github.com/taysta/TaystJK/commit/848ce21a29dde392d2be2e9289d061f38428b193)<br>Bucky's cg_smoothclients fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2023-12-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`edec69cec7d0`](https://github.com/videoP/jaPRO/commit/edec69cec7d0e48dbdb66ac78318371abc222573) · [PR #58](https://github.com/taysta/TaystJK/pull/58)<br>Japro update (#58) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2023-12-28` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`2276bf63a27e`](https://github.com/videoP/jaPRO/commit/2276bf63a27e290d86a76388124f7e3a028e3cdc)<br>Fix jaPro projectile prediction clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `high` |
| `2023-12-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b4dc4332b515`](https://github.com/videoP/jaPRO/commit/b4dc4332b51568e107049216105092af9658af3b) · [PR #69](https://github.com/taysta/TaystJK/pull/69)<br>Japro update (#69) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9e120086add8`](https://github.com/videoP/jaPRO/commit/9e120086add83f23befd7186ece215c286b943c8) · [PR #71](https://github.com/taysta/TaystJK/pull/71)<br>Japro update (#71) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2024-01-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`e02b0850cea3`](https://github.com/videoP/jaPRO/commit/e02b0850cea39f205a51f6f650a984fbe81df60a) · [PR #91](https://github.com/taysta/TaystJK/pull/91)<br>Japro update (#91) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `high` |
| `2024-01-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8cd2ef9d8dcb`](https://github.com/videoP/jaPRO/commit/8cd2ef9d8dcb331ecdf27076d9d1307dbd6ee0c5) · [PR #104](https://github.com/taysta/TaystJK/pull/104)<br>Japro update (#104) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c` | `high` |
| `2024-01-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`2812a6c459f5`](https://github.com/videoP/jaPRO/commit/2812a6c459f56f3190a0b269a5965eae63f36831) · [PR #108](https://github.com/taysta/TaystJK/pull/108)<br>Japro updates (#108) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c`, `codemp/game/bg_pmove.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93dfa66dc8e5`](https://github.com/videoP/jaPRO/commit/93dfa66dc8e5d49a7067d6f12818333e15366ead) · [PR #112](https://github.com/taysta/TaystJK/pull/112)<br>Japro updates (#112) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_effects.c`, `codemp/cgame/cg_view.c` | `high` |
| `2024-01-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a8ae4c55d8a7`](https://github.com/videoP/jaPRO/commit/a8ae4c55d8a7b856f589b0566bdc58fb9cf7a3f2) · [PR #113](https://github.com/taysta/TaystJK/pull/113)<br>Japro updates (#113) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_effects.c`, `codemp/cgame/cg_view.c` | `high` |
| `2024-02-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) · [PR #157](https://github.com/taysta/TaystJK/pull/157)<br>Upstream update (#157) | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c1fa400ec798`](https://github.com/taysta/TaystJK/commit/c1fa400ec79858ec81cfccc17cbbc1aff178c6b2) · [PR #304](https://github.com/taysta/TaystJK/pull/304)<br>Merge pull request #304 from taysta/featureflag-flipkick | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`99776e29a7de`](https://github.com/taysta/TaystJK/commit/99776e29a7dec87b4fe3fd4551240c94d0995b4e) · [PR #313](https://github.com/taysta/TaystJK/pull/313)<br>Merge pull request #313 from taysta/tribes-fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:297](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L297) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_effects.c:676](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_effects.c#L676)
- behavior: [codemp/cgame/cg_event.c:2837](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L2837)
- behavior: [codemp/cgame/cg_event.c:2875](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L2875)
- behavior: [codemp/cgame/cg_event.c:3341](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L3341)
- behavior: [codemp/cgame/cg_weapons.c:2652](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L2652)
