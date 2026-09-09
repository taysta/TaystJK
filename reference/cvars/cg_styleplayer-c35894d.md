---
title: "cg_stylePlayer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_stylePlayer`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Configure with the /stylePlayer command

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `4` | Enables the `JAPRO_STYLE_HIDEDUELERS1` code path. | [codemp/cgame/cg_local.h:133](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L133) |
| `1024` | Base | [codemp/cgame/cg_local.h:141](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L141) |
| `2048` | Enables the `JAPRO_STYLE_HIDEYSALSHELL` code path. | [codemp/cgame/cg_local.h:142](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L142) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`1d5acfc05276`](https://github.com/videoP/jaPRO/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-04-19`, integrated `2018-04-19`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:133](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L133)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/taysta/TaystJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/videoP/jaPRO/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-19` | — | `2018-04-19` | [`1d5acfc05276`](https://github.com/JKSunny/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_ents.c` and 4 more | `high` |
| `2018-09-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d9658edfb8ed`](https://github.com/eternalcodes/EternalJK/commit/d9658edfb8ed714a28dffc17a6cb2db2e2a1a3da)<br>Added option to view FFA players normally while in race mode, always hide ysal shell in race mode | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_players.c` | `medium` |
| `2018-09-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bed814a0b3d0`](https://github.com/videoP/jaPRO/commit/bed814a0b3d0b7ee1e3ba2052f1e61a7707e303a)<br>Start of cosmetic item support on japro servers | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2018-10-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2af38213b793`](https://github.com/eternalcodes/EternalJK/commit/2af38213b793183fd6313a195d0f36ea3aa02196)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_players.c` | `high` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293)<br>cosmetics | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_players.c` | `medium` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e9643f2f5b09`](https://github.com/eternalcodes/EternalJK/commit/e9643f2f5b099a0cbc05da512cc8d455107454bb)<br>race mode cosmetics fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-11-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`66e0c49cdb24`](https://github.com/eternalcodes/EternalJK/commit/66e0c49cdb24f4b278594fb9c4d18a91a429739f)<br>Fix RF_NOLOD on duel shell | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-11-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2e1d4e27934f`](https://github.com/eternalcodes/EternalJK/commit/2e1d4e27934f67948e315b78250d42309411a318)<br>Don't show bodies in racemode or in isolated duels. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_players.c` | `medium` |
| `2018-11-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`81b34abb5846`](https://github.com/eternalcodes/EternalJK/commit/81b34abb584619349e45ee435e977f1457b5837b)<br>Register saberFlash shader and cosmetic models on startup | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-11-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`4ef56275a3fa`](https://github.com/eternalcodes/EternalJK/commit/4ef56275a3fab4a21de3630402ffd19cbb901b69)<br>New shader for duelers with VFX duelers option | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-11-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`418f3e1fcc29`](https://github.com/eternalcodes/EternalJK/commit/418f3e1fcc29e35e3535604041949a71e97207ee)<br>Check engine support for new renderfx flags, use old behavior if necessary | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c`, `codemp/cgame/cg_weapons.c` | `medium` |
| `2018-12-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f4d14139b3e3`](https://github.com/eternalcodes/EternalJK/commit/f4d14139b3e338ccf67b024999497e5201cdb7a6)<br>Apply racer/dueler VFX to player cosmetics | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5ad2c859363b`](https://github.com/eternalcodes/EternalJK/commit/5ad2c859363b2569220c45e745328d2b655a82aa)<br>Added player breathing visuals | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c5fcd4abd860`](https://github.com/eternalcodes/EternalJK/commit/c5fcd4abd860d41a980edb769b7523233cb475db)<br>Fix disintegration effect on unfaded corpses with "fade bodies immediately" | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`418ac5d98380`](https://github.com/eternalcodes/EternalJK/commit/418ac5d9838032ba4d2904d6ac9f56573eb1dcfb)<br>Add styleplayer option for old JA+ grapple hook effect | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_players.c` | `medium` |
| `2019-05-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1037828cbff6`](https://github.com/eternalcodes/EternalJK/commit/1037828cbff6c63180151a9e74a785bf037498d6)<br>Fix cgame duel isolation. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2019-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ab57b189a8e1`](https://github.com/eternalcodes/EternalJK/commit/ab57b189a8e1d725927c5c448184bb536b7e71e2)<br>Fix FPS drop from disintegrating corpse smoke at high FPS | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5f9884ea53d2`](https://github.com/eternalcodes/EternalJK/commit/5f9884ea53d24fda9ac5a095ed552ae6a3579a3b)<br>cgame updates for coop x2 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_event.c` | `medium` |
| `2020-08-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3ea9b3c38f7b`](https://github.com/eternalcodes/EternalJK/commit/3ea9b3c38f7bea43895619f40d5c2695f73c7704)<br>cg_chatBoxShowCutoff + emoji crash+whitespacing fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2020-08-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7e445d0e15f5`](https://github.com/eternalcodes/EternalJK/commit/7e445d0e15f53917a4fd5b30b4b99cc70fca7e97)<br>Fix strange regression causing corpses to always be hidden | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2023-11-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`80b6fdf0c505`](https://github.com/videoP/jaPRO/commit/80b6fdf0c505a9570fb9f4a263b8feac3b1de0cf)<br>[jaPRO/Bucky] Add seasonal cosmetics | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2023-11-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`5e105b50ebd8`](https://github.com/videoP/jaPRO/commit/5e105b50ebd8d4923b7e8cb47ec56a4eceeced95)<br>[jaPRO/Tayst] Add seasonal cosmetics to /styleplayer command for non jaPRO servers, needs testing | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2023-11-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c8517f4acfa0`](https://github.com/videoP/jaPRO/commit/c8517f4acfa0845ba7f8d5dc759f4e0cadc9c4f8)<br>[jaPRO/Bucky] Re-enable seasonal cosmetics on all servers (need to check individual cosmetics) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2023-11-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`51dbc3fe42d4`](https://github.com/taysta/TaystJK/commit/51dbc3fe42d40315fb9027cd6dca756691065d42) · [PR #39](https://github.com/taysta/TaystJK/pull/39)<br>Merge pull request #39 from taysta/cosmetics | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2023-11-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`66fe36b094c3`](https://github.com/taysta/TaystJK/commit/66fe36b094c3fbae2629049c48080c385f6d661a) · [PR #43](https://github.com/taysta/TaystJK/pull/43)<br>Merge pull request #43 from taysta/features | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weaponinit.c` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`51c7ec8001ed`](https://github.com/taysta/TaystJK/commit/51c7ec8001ed339c928188410f071dfdef70a388) · [PR #272](https://github.com/taysta/TaystJK/pull/272)<br>Merge pull request #272 from slash-fr/fix-npc-rgb-saber-crash | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:136](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L136) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:163](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L163) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:9564](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L9564)
- behavior: [codemp/cgame/cg_draw.c:9572](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L9572)
- behavior: [codemp/cgame/cg_draw.c:11399](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L11399)
- behavior: [codemp/cgame/cg_draw.c:11433](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L11433)
- behavior: [codemp/cgame/cg_ents.c:930](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L930)
- documentation: [codemp/ui/ui_xdocs.h:464](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L464)
