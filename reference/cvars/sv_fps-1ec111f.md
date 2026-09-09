---
title: "sv_fps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_fps`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Server frames per second

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `40` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Selects the code path tested for value 0. | [codemp/cgame/cg_snapshot.c:647](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_snapshot.c#L647) |
| `20` | Selects the code path tested for value 20. | [codemp/game/g_trigger.c:1351](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L1351) |
| `30` | Selects the code path tested for value 30. | [codemp/game/g_trigger.c:1351](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L1351) |
| `40` | Selects the code path tested for value 40. | [codemp/game/g_trigger.c:1351](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L1351) |

## Enforced ranges

- `0` through `1000` (integer; Cvar_CheckRange) — [codemp/server/sv_init.cpp:1015](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1015)

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `40` | `engine-server` | `—` | `always` |
| `40` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/server/sv_init.cpp:491](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/server/sv_init.cpp#L491)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_main.c`, `codemp/game/g_xcvar.h`, `codemp/game/w_force.c` and 1 more | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `high` |
| `2013-04-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`300bc4422b2a`](https://github.com/JACoders/OpenJK/commit/300bc4422b2a2b552f7e834881283aef20503730)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/server/sv_init.cpp` | `high` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` | `high` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_xcvar.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp` | `high` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `high` |
| `2013-08-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`28b5eccb29aa`](https://github.com/JACoders/OpenJK/commit/28b5eccb29aa03dacadf229cf11518a29cfea7cd)<br>Reverting SP's sv_fps back to 20 from 40.  Game code never was changed to suit this. From original commit b80e275. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/server/sv_init.cpp` | `medium` |
| `2013-10-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`0bf217273755`](https://github.com/JACoders/OpenJK/commit/0bf217273755c4fb10217c8479bb9d3a294526f3)<br>[MP] Merged critical fixes (ioquake/ioq3@f725b23) for snapshot floating point imprecision from ioq3 that were missing. | Changed an exact bound cvar-variable reference. `codemp/server/sv_snapshot.cpp` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c6e3f0479ac0`](https://github.com/JACoders/OpenJK/commit/c6e3f0479ac048e838ac002351fab307f726fa4d)<br>[MP] Meta: Remove unnecessary comments and names | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/w_force.c` | `medium` |
| `2014-01-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d63be8a74acc`](https://github.com/JACoders/OpenJK/commit/d63be8a74acc0af07f4fca0658ce9353c9e415a2)<br>[MP] Fix userinfo validation counting values as instances of keys | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e0710c1ba9c1`](https://github.com/JACoders/OpenJK/commit/e0710c1ba9c15203b38824a656606ec9532b368d)<br>Shared: Fixed what was hopefully the last of min/max macro usage in the main portion of the code.  Still need to do something with mp3code 3rd party lib. | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2015-06-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f614bc372a41`](https://github.com/taysta/TaystJK/commit/f614bc372a41cca80c0e1e401d584a57318bd495)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/server/sv_init.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2017-12-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9207f1148bdd`](https://github.com/eternalcodes/EternalJK/commit/9207f1148bdde81d25b6c0f97139bb2ce0fbc6a3)<br>Merge pull request #3 from Bucky21659/master | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/g_active.c`, `codemp/game/g_cmds.c` and 4 more | `high` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_snapshot.c` | `high` |
| `2018-10-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`987d8cc36a14`](https://github.com/taysta/TaystJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5)<br>Exirmirai's server hibernation mode | Changed an exact bound cvar-variable reference. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` and 1 more | `medium` |
| `2018-10-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c648f59e6b35`](https://github.com/eternalcodes/EternalJK/commit/c648f59e6b353f9755a4890a1e6f27abb2491cd1)<br>hibernate redo | Changed an exact bound cvar-variable reference. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` and 1 more | `medium` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc3c8171d100`](https://github.com/eternalcodes/EternalJK/commit/dc3c8171d100cca45ac75fc830cd749c851ad1ae)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_snapshot.cpp` | `high` |
| `2018-10-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`724b58ba6bf5`](https://github.com/eternalcodes/EternalJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc)<br>add sv_listrecording command start servers with hibernation disabled | Changed an exact bound cvar-variable reference. `codemp/server/server.h` | `medium` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2019-02-03` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`52f85bb57c06`](https://github.com/taysta/TaystJK/commit/52f85bb57c06d6683c939b5de0cef66b4137b17d)<br>Don't discard userinfo changes, only postpone them (from JK2MV) | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`70a18c64101f`](https://github.com/eternalcodes/EternalJK/commit/70a18c64101f3920bce495bde1c9c3e6ca89a495)<br>Change sv_snapsPolicy default to 2, fix crash with sv_snapsMin/snapsMax set to 0 | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2023-12-30` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`041bd7f51cb6`](https://github.com/videoP/jaPRO/commit/041bd7f51cb62681eec00a7e781e1095e5735210) · [PR #67](https://github.com/taysta/TaystJK/pull/67)<br>Japro updates (#67) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9e120086add8`](https://github.com/videoP/jaPRO/commit/9e120086add83f23befd7186ece215c286b943c8) · [PR #71](https://github.com/taysta/TaystJK/pull/71)<br>Japro update (#71) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `high` |
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) · [PR #74](https://github.com/taysta/TaystJK/pull/74)<br>Japro update (#74) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `high` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`3c9f3d577a07`](https://github.com/taysta/TaystJK/commit/3c9f3d577a07ab3256f6725fc42b8cbf8dfb781e)<br>bot cap fixes | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `medium` |
| `2024-04-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`258031c97e93`](https://github.com/videoP/jaPRO/commit/258031c97e933f2293dc35c18af5ea16847f0241) · [PR #188](https://github.com/taysta/TaystJK/pull/188)<br>Japro update (#188) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_snapshot.c` | `high` |
| `2024-05-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`829a59ad0875`](https://github.com/videoP/jaPRO/commit/829a59ad08755dee1f62049d9a03be252668e47a) · [PR #200](https://github.com/taysta/TaystJK/pull/200)<br>[jaPRO] Fixup clang compiler warnings (#200) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `high` |
| `2024-05-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93c2c1a5b4ef`](https://github.com/videoP/jaPRO/commit/93c2c1a5b4efbea4e009e65fbdbf5148cd68771c) · [PR #201](https://github.com/taysta/TaystJK/pull/201)<br>Japro update (#201) | Changed an exact bound cvar-variable reference. `codemp/game/g_trigger.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:177](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L177) (XCVAR_DEF)
- registration: [codemp/server/sv_init.cpp:1014](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1014) (Cvar_Get)
- behavior: [codemp/cgame/cg_snapshot.c:647](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_snapshot.c#L647)
- behavior: [codemp/game/g_active.c:6047](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L6047)
- behavior: [codemp/game/g_client.c:2703](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2703)
- behavior: [codemp/game/g_cmds.c:8760](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8760)
- behavior: [codemp/game/g_trigger.c:1351](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_trigger.c#L1351)
