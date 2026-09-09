---
title: "cp_pluginDisable"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cp_pluginDisable`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

'enable' holstered saber (512) and ledge grab (1536) by default, to avoid missing JA+ animations

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1536` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `524288` | Enables the `JAPRO_PLUGIN_BHOP` code path. | [codemp/game/bg_public.h:538](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L538) |
| `134217728` | Enables the `JAPRO_PLUGIN_CENTERMUZZLE` code path. | [codemp/game/bg_public.h:546](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L546) |
| `2` | Enables the `JAPRO_PLUGIN_DUELSEEOTHERS` code path. | [codemp/game/bg_public.h:516](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L516) |
| `1048576` | Enables the `JAPRO_PLUGIN_NOROLL` code path. | [codemp/game/bg_public.h:539](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L539) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_USERINFO` — sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2015-04-04`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:192](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/cgame/cg_xcvar.h#L192)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-04` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-04` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-04` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-04` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_players.c`, `codemp/cgame/cg_weapons.c` and 3 more | `high` |
| `2018-09-09` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3a666309b2fb`](https://github.com/eternalcodes/EternalJK/commit/3a666309b2fbf626fb606973cb1e8a7221d34872)<br>Fix black sabers | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d6357a63bc5d`](https://github.com/eternalcodes/EternalJK/commit/d6357a63bc5dc9347d729d3ca14742eaf66422c6)<br>Fixed black sabers | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2018-11-27` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2e1d4e27934f`](https://github.com/eternalcodes/EternalJK/commit/2e1d4e27934f67948e315b78250d42309411a318)<br>Don't show bodies in racemode or in isolated duels. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_players.c` | `medium` |
| `2019-02-01` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0e8b124d1344`](https://github.com/eternalcodes/EternalJK/commit/0e8b124d1344ca90657c2784de74586542dbde93)<br>Only lowjump (with current jump level) with onlybhop+crouchjump restrict | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c5fcd4abd860`](https://github.com/eternalcodes/EternalJK/commit/c5fcd4abd860d41a980edb769b7523233cb475db)<br>Fix disintegration effect on unfaded corpses with "fade bodies immediately" | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2019-05-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a790181f43ae`](https://github.com/eternalcodes/EternalJK/commit/a790181f43aec2b0a99fcc31d3dc2ad7ff6f5d9c)<br>Serverside duel isolation: respect clients' cp_pluginDisable setting on JA+ servers | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_players.c`, `codemp/game/bg_pmove.c` and 1 more | `medium` |
| `2019-05-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1037828cbff6`](https://github.com/eternalcodes/EternalJK/commit/1037828cbff6c63180151a9e74a785bf037498d6)<br>Fix cgame duel isolation. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9a37943df03d`](https://github.com/eternalcodes/EternalJK/commit/9a37943df03dd6d09740d3cf94f596c82043d49f)<br>Fix broken ClientCleanName function+Refactor server fixes to utilize new legacyFixes bitmask and server mod detection. | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2020-04-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`73584012842e`](https://github.com/videoP/jaPRO/commit/73584012842e464a0ed23d407a808e4288da4e4b)<br>Serverside duel isolatin (JA+/jaPRO): don't disable collision on duelers | Changed an exact bound cvar-variable reference. `codemp/server/server.h` | `high` |
| `2020-06-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5f9884ea53d2`](https://github.com/eternalcodes/EternalJK/commit/5f9884ea53d24fda9ac5a095ed552ae6a3579a3b)<br>cgame updates for coop x2 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2020-06-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a43a3418a405`](https://github.com/eternalcodes/EternalJK/commit/a43a3418a40564fc48038585ad6054b6df79dba2)<br>Fix NPC console spam+fix cg_drawHitBox on local player | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2020-08-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7e445d0e15f5`](https://github.com/eternalcodes/EternalJK/commit/7e445d0e15f53917a4fd5b30b4b99cc70fca7e97)<br>Fix strange regression causing corpses to always be hidden | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2025-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`36723927b9d2`](https://github.com/taysta/TaystJK/commit/36723927b9d211e22dbe7b9719a8b9dd10d1830b) · [PR #254](https://github.com/taysta/TaystJK/pull/254)<br>Merge pull request #254 from taysta/feature-flags | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2025-12-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3bfd04758bfb`](https://github.com/taysta/TaystJK/commit/3bfd04758bfbb105151f2d3cdc3f3629330982f1) · [PR #284](https://github.com/taysta/TaystJK/pull/284)<br>Merge pull request #284 from taysta/upstream | Changed an exact bound cvar-variable reference. `codemp/game/bg_saber.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:195](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L195) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_ents.c:933](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L933)
- behavior: [codemp/cgame/cg_players.c:10782](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L10782)
- behavior: [codemp/cgame/cg_weapons.c:2390](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weapons.c#L2390)
- behavior: [codemp/game/bg_pmove.c:3546](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L3546)
- behavior: [codemp/game/bg_pmove.c:6220](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L6220)
