---
title: "dedicated"
layout: reference
nav_exclude: true
search_exclude: false
---

# `dedicated`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `dedicated` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `1` through `2` (integer; Cvar_CheckRange) — [codemp/qcommon/common.cpp:1436](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1436)
- `0` through `2` (integer; Cvar_CheckRange) — [codemp/qcommon/common.cpp:1445](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1445)

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `game` | `—` | `always` |
| `2` | `engine-shared` | `—` | `defined(DEDICATED)` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:354](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L354)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`393874137c54`](https://github.com/JACoders/OpenJK/commit/393874137c54b70b27856e62013bd283059ef6e0)<br>First batch of changes from Ensi | Changed an exact bound cvar-variable reference. `codemp/client/cl_scrn.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dcc17314ab11`](https://github.com/JACoders/OpenJK/commit/dcc17314ab1167547f172b0d21788c0ea1ecb760)<br>Removed cd key from mp/qcommon | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_main.c`, `codemp/game/g_svcmds.c` and 1 more | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`92e12a9e9b19`](https://github.com/JACoders/OpenJK/commit/92e12a9e9b19525c1f589f1f6779e9397b6bfd26)<br>Fixed long upstanding server issues from ioq3.  Free server entitites BEFORE GAME_INIT rather than after too. | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp` | `high` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/G2_API.cpp`, `codemp/rd-dedicated/tr_ghoul2.cpp`, `codemp/rd-dedicated/tr_model.cpp` and 3 more | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/qcommon/files.cpp` | `high` |
| `2013-07-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2afca07b43c`](https://github.com/JACoders/OpenJK/commit/b2afca07b43c126553236315c5a90c8fbbf76f05)<br>Merge pull request #299 from xycaleth/fix-warnings | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_image.cpp` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6f98a53f4616`](https://github.com/JACoders/OpenJK/commit/6f98a53f461663328222a2c40cdf36351dc169fa)<br>Merge branch 'master' of github.com:Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `high` |
| `2013-07-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ee552c5b46e5`](https://github.com/JACoders/OpenJK/commit/ee552c5b46e542f9b56f9471d12eb6defe0ad763)<br>Merge pull request #328 from xycaleth/rd-common | Changed an exact bound cvar-variable reference. `codemp/rd-common/tr_public.h`, `codemp/rd-vanilla/tr_image.cpp`, `codemp/rd-vanilla/tr_skin.cpp` | `medium` |
| `2013-07-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`79f46c2c3b22`](https://github.com/JACoders/OpenJK/commit/79f46c2c3b22c2c72430060770bf58cd675acfa0)<br>Merge pull request #329 from xycaleth/fix-warnings | Changed an exact bound cvar-variable reference. `codemp/rd-vanilla/tr_image.cpp` | `medium` |
| `2013-08-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dd9bd9b9ae92`](https://github.com/JACoders/OpenJK/commit/dd9bd9b9ae92d7937b8b6986d1df0bccf93e8c93)<br>Refactored renderer API, fixed some Ghoul2 crashes | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/G2_API.cpp`, `codemp/rd-dedicated/tr_ghoul2.cpp`, `codemp/rd-dedicated/tr_model.cpp` and 4 more | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/client/cl_scrn.cpp`, `codemp/ui/ui_main.c` | `medium` |
| `2013-08-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61cd6e979c3b`](https://github.com/JACoders/OpenJK/commit/61cd6e979c3bb37e8b05ca2c6f1a1fc0812aea17)<br>Removed stricmp etc, always use Q_ versions for consistency across platforms | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-11-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2e90f9c19be1`](https://github.com/JACoders/OpenJK/commit/2e90f9c19be1a2b74a1ac71f8ff0dcdadfa3103c)<br>[MP] Removed leftover delayFreeVM references. Init lastTime to 0 in Com_Frame. Bring back ERR_NEED_CD handling just for conformity sake. Init the jakey randomizer first thing in Com_Init. | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2013-11-14` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5d5eef61b5e4`](https://github.com/JACoders/OpenJK/commit/5d5eef61b5e4bdb33710730a693b4ac054ba5e5e)<br>[MP] Fixed early prints to the ingame console. This does not hurt anything since we don't allow dedicated in the main bin right now. Check this if we decide to re-enable without going the in-game console for openjk regular executable dedicated. | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2013-11-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`03e8231c183e`](https://github.com/JACoders/OpenJK/commit/03e8231c183ef3208e54acaccb73288d33a14de1)<br>[MP] Make g_svcmds use bsearch method for commands. Improve listip command. Improve ded server say cmd. | Changed an exact bound cvar-variable reference. `codemp/game/g_svcmds.c` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`adce8465b4b5`](https://github.com/JACoders/OpenJK/commit/adce8465b4b5acf64dbba3bbbd79a7d8766a7c34)<br>[MP] Allow dedicated cvar to be set to during init instead of not at all with dedicated executable. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/qcommon/cm_load.cpp`, `codemp/qcommon/common.cpp` | `medium` |
| `2014-08-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`03bba21225bb`](https://github.com/JACoders/OpenJK/commit/03bba21225bbdfe484236d00966b6783bd2077a7)<br>[MP] Add svtell command to send message to clients from server console. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/qcommon/files.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/server/sv_main.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/G2_API.cpp`, `codemp/rd-dedicated/tr_ghoul2.cpp`, `codemp/rd-vanilla/G2_API.cpp` and 2 more | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/sqlite3.c` | `high` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0db4ffc5f66d`](https://github.com/eternalcodes/EternalJK/commit/0db4ffc5f66d247d9031f3efe8a893e3d95d7153)<br>rcon status cleanup pt2 | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`701070354c7c`](https://github.com/eternalcodes/EternalJK/commit/701070354c7ca1e7bb1847d74b1710d23c52369f)<br>Fix OOB IP rate limiter breaking non-dedicated servers | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/G2_API.cpp`, `codemp/rd-vulkan/tr_ghoul2.cpp`, `codemp/rd-vulkan/tr_model.cpp` and 1 more | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_main.cpp`, `codemp/rd-vulkan/vk_frame.cpp` | `high` |
| `2021-06-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`2302bf7c732e`](https://github.com/taysta/TaystJK/commit/2302bf7c732e9f052f5c9b8d7b997302b794e105)<br>Removed localName from image loader | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_image.cpp` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`405022446ca4`](https://github.com/taysta/TaystJK/commit/405022446ca43e90b746b5b9331fcaacc059e83b)<br>[OpenJK] Re-merge OpenJK into EJK [1] | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed an exact bound cvar-variable reference. `codemp/rd-rend2/G2_API.cpp` | `medium` |
| `2024-01-25` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cd07288a30a6`](https://github.com/videoP/jaPRO/commit/cd07288a30a6aa276afdb11f1ae81e5e338134c3) · [PR #116](https://github.com/taysta/TaystJK/pull/116)<br>Japro updates (#116) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_cache.cpp`, `shared/rd-rend2/tr_ghoul2.cpp`, `shared/rd-rend2/tr_skin.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`22e66aeb32fc`](https://github.com/taysta/TaystJK/commit/22e66aeb32fca7ac91de70bc3474e4d23f38a8fa) · [PR #315](https://github.com/taysta/TaystJK/pull/315)<br>Merge pull request #315 from taysta/vk-up | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_cache.cpp`, `codemp/rd-vulkan/tr_model.cpp` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:61](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L61) (XCVAR_DEF)
- registration: [codemp/qcommon/common.cpp:1435](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1435) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/client/cl_scrn.cpp:608](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_scrn.cpp#L608)
- behavior: [codemp/game/g_svcmds.c:1738](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_svcmds.c#L1738)
- behavior: [codemp/qcommon/common.cpp:310](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L310)
- behavior: [codemp/qcommon/common.cpp:1521](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1521)
- behavior: [codemp/qcommon/common.cpp:1535](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1535)
