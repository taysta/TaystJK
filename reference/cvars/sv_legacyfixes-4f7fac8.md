---
title: "sv_legacyFixes"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_legacyFixes`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `sv_legacyFixes` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `128` | Rancor/wampa skins | [codemp/server/server.h:356](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/server.h#L356) |
| `8` | Enables the `SVFIXES_ALLOW_INVALID_FORCEPOWERS` code path. | [codemp/server/server.h:352](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/server.h#L352) |
| `64` | Enables the `SVFIXES_ALLOW_INVALID_PLAYER_NAMES` code path. | [codemp/server/server.h:355](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/server.h#L355) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-server` | `—` | `!defined(DEDICATED)` |
| `1` | `engine-server` | `—` | `else(!defined(DEDICATED))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`8b07e58c1c28`](https://github.com/JACoders/OpenJK/commit/8b07e58c1c2875e94823c8afe5443e003370349b) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2017-12-06`, integrated `2017-12-06`)
- TaystJK integration evidence: [`43b393062090`](https://github.com/taysta/TaystJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1009](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1009)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, rend2; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2017-12-06` | — | `2017-12-06` | [`8b07e58c1c28`](https://github.com/JACoders/OpenJK/commit/8b07e58c1c2875e94823c8afe5443e003370349b) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2017-12-06` | — | `2017-12-06` | [`8b07e58c1c28`](https://github.com/SomaZ/OpenJK/commit/8b07e58c1c2875e94823c8afe5443e003370349b) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-06` | — | `2017-12-29` | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-06` | — | `2017-12-29` | [`43b393062090`](https://github.com/taysta/TaystJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-06` | — | `2017-12-29` | [`43b393062090`](https://github.com/videoP/jaPRO/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-06` | — | `2017-12-29` | [`43b393062090`](https://github.com/JKSunny/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` and 1 more | `medium` |
| `2019-05-03` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`96cf7ecc01a1`](https://github.com/taysta/TaystJK/commit/96cf7ecc01a1c4aa7a7ae6a7ab1f5867c6b79bc9)<br>Port invalid userinfo crash in serverside engine (from JK2MV). | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`e0d767299eb2`](https://github.com/eternalcodes/EternalJK/commit/e0d767299eb2bfd7d735cdb55acba3644fd37844)<br>Fix obscure staff backwards DFA exploit. | Changed an exact bound cvar-variable reference. `codemp/server/sv_snapshot.cpp` | `medium` |
| `2019-05-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b8853f9880ee`](https://github.com/eternalcodes/EternalJK/commit/b8853f9880eec24cbb076f377268563e4d748928)<br>Fix player ghosting on basejka jampgame. | Changed an exact bound cvar-variable reference. `codemp/server/sv_game.cpp` | `medium` |
| `2019-05-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0208a2a50e75`](https://github.com/videoP/jaPRO/commit/0208a2a50e75e95f975b767166b221d2b13dbb4b)<br>Add basic mod detection to dedicated server. | Changed an exact bound cvar-variable reference. `codemp/server/sv_gameapi.cpp`, `codemp/server/sv_snapshot.cpp` | `high` |
| `2019-05-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`104b7d488c25`](https://github.com/eternalcodes/EternalJK/commit/104b7d488c25a4956974410a8045fd33943d9fdb)<br>Add bitvalues for sv_legacyFixes to control engine-side exploit patches. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_game.cpp` and 2 more | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`15c685c83005`](https://github.com/eternalcodes/EternalJK/commit/15c685c830057239017ac08c4a9be5ab8a98c300)<br>Merge pull request #95 from Yberion/serversideEngineFix | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9a37943df03d`](https://github.com/eternalcodes/EternalJK/commit/9a37943df03dd6d09740d3cf94f596c82043d49f)<br>Fix broken ClientCleanName function+Refactor server fixes to utilize new legacyFixes bitmask and server mod detection. | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-06-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9bece107afd6`](https://github.com/eternalcodes/EternalJK/commit/9bece107afd6962c09a3873e7ea8133949cf8770)<br>Filter npc spawn saber_droid command | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-07-31` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3597107bc435`](https://github.com/eternalcodes/EternalJK/commit/3597107bc435239fc837742f152a8cd7d9c578f7)<br>Add server engine-side spectator alt-fire=followPrev feature to sv_legacyFixes | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2020-04-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`73584012842e`](https://github.com/videoP/jaPRO/commit/73584012842e464a0ed23d407a808e4288da4e4b)<br>Serverside duel isolatin (JA+/jaPRO): don't disable collision on duelers | Changed an exact bound cvar-variable reference. `codemp/server/sv_gameapi.cpp` | `high` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1044](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1044) (Cvar_Get); condition `!defined(DEDICATED)`
- registration: [codemp/server/sv_init.cpp:1046](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1046) (Cvar_Get); condition `else(!defined(DEDICATED))`
- behavior: [codemp/server/sv_client.cpp:1181](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1181)
- behavior: [codemp/server/sv_client.cpp:1286](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1286)
- behavior: [codemp/server/sv_client.cpp:1304](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1304)
- behavior: [codemp/server/sv_client.cpp:1477](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1477)
- behavior: [codemp/server/sv_client.cpp:1483](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L1483)
