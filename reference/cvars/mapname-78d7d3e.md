---
title: "mapname"
layout: reference
nav_exclude: true
search_exclude: false
---

# `mapname`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `mapname` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM` — read-only after registration
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `` | `game` | `—` | `always` |
| `nomap` | `engine-server` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/server/sv_init.cpp:484](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/server/sv_init.cpp#L484)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_cmds.c`, `codemp/game/g_syscalls.c` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61779788b020`](https://github.com/JACoders/OpenJK/commit/61779788b0207e43c974b10b79dfba4709369636)<br>Botlib improvements. Moved some botlib headers to the botlib folder | Changed an exact bound cvar-variable reference. `codemp/botlib/botlib.h` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`92e12a9e9b19`](https://github.com/JACoders/OpenJK/commit/92e12a9e9b19525c1f589f1f6779e9397b6bfd26)<br>Fixed long upstanding server issues from ioq3.  Free server entitites BEFORE GAME_INIT rather than after too. | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/rd-dedicated/tr_local.h`, `codemp/rd-vanilla/tr_image.cpp`, `codemp/rd-vanilla/tr_local.h` | `high` |
| `2013-04-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb29d3a516fb`](https://github.com/JACoders/OpenJK/commit/bb29d3a516fbc8f6dd8ca30864df3bd8b5ffea65)<br>Finished up most of the code now for the modular SP renderer. The things I need to fix still: - Some undefined externals - Some of the imports - The whole DLL import routine - Actual testing (???) Should be done by the end of this weekend, hopefully. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_syscalls.c` | `high` |
| `2013-06-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`873b95b64cc6`](https://github.com/JACoders/OpenJK/commit/873b95b64cc699afea28cf072479a516c3db9997)<br>Removed spmap and spdevmap. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2afca07b43c`](https://github.com/JACoders/OpenJK/commit/b2afca07b43c126553236315c5a90c8fbbf76f05)<br>Merge pull request #299 from xycaleth/fix-warnings | Changed an exact bound cvar-variable reference. `codemp/client/snd_dma.cpp` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_local.h`, `codemp/cgame/cg_main.c` and 16 more | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e57a5ecef64`](https://github.com/JACoders/OpenJK/commit/3e57a5ecef641ec5354b6a639c7317178be1fd99)<br>Use Q_strncpyz in g_log.c instead of manually doing it with strncpyz and clearing. | Changed an exact bound cvar-variable reference. `codemp/game/g_log.c` | `medium` |
| `2013-10-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`872159cb6796`](https://github.com/JACoders/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821)<br>[MP] Rewrote callvote to be far more robust | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fde9de23e2ad`](https://github.com/JACoders/OpenJK/commit/fde9de23e2ad96b11d590d659a44b7892f6c601a)<br>Merge pull request #481 from dpadgett/svdemo | Changed an exact bound cvar-variable reference. `codemp/server/sv_init.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1ba18ae105e7`](https://github.com/JACoders/OpenJK/commit/1ba18ae105e7e1b3f9751b4893e7295e2fae475f)<br>Fix warning for signed cvar flags | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_main.c` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `high` |
| `2014-03-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`543e9880e506`](https://github.com/JACoders/OpenJK/commit/543e9880e50647fcd2b853c44be5102e992abf1d)<br>[MP] Some cg_saga buffer cleanup. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c` | `medium` |
| `2014-03-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`be710edc1315`](https://github.com/JACoders/OpenJK/commit/be710edc1315615265da5821a94c26dbcaddba10)<br>Merge pull request #509 from dpadgett/svdemo | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-03-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`770ba4908087`](https://github.com/JACoders/OpenJK/commit/770ba4908087d7132f0cba9d348956c88ee46884)<br>[MP] Fixed an issue introduced during server side demo addition which introduced player colors and extended ascii being stripped from names. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/game/g_local.h`, `codemp/game/g_main.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/rd-vanilla/tr_init.cpp`, `code/server/sv_init.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_cmds.c`, `codemp/game/g_main.c` and 1 more | `high` |
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a19ccb32a98d`](https://github.com/eternalcodes/EternalJK/commit/a19ccb32a98dbcd701d3ad151d744b2a7ccc3d63)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `medium` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_main.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0e5a7eb8505b`](https://github.com/eternalcodes/EternalJK/commit/0e5a7eb8505b396272176c643666507e09b5ea22)<br>rtop fix | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`33d933ca5f12`](https://github.com/eternalcodes/EternalJK/commit/33d933ca5f122abf278f8f6fefc5607c5f2c3b20)<br>rtop season support / rtop rewrite / rtop fix | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`18440d16f155`](https://github.com/eternalcodes/EternalJK/commit/18440d16f15520bed3c547fc994f2ac8ec5a0b16)<br>rworst update .. ? | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `medium` |
| `2018-08-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fa2b5ba6883b`](https://github.com/eternalcodes/EternalJK/commit/fa2b5ba6883ba72c77c53130fedf2d3d2bfb86ea)<br>Merge branch 'feature/update-game' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_servercmds.c`, `codemp/cgame/cg_snapshot.c` | `high` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`2b816e244108`](https://github.com/videoP/jaPRO/commit/2b816e2441089c3de73a8ad0f66e6a2c52bafe55)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_local.h` | `high` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `high` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)<br>Implement Blackwolf's Discord Integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad1655124ccf`](https://github.com/eternalcodes/EternalJK/commit/ad1655124ccf0e8663e0e33f02a8a9ffb9a275ff)<br>Discord lib handling cleanup | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6c6472650cc`](https://github.com/eternalcodes/EternalJK/commit/f6c6472650ccd08fb0d010755094ab09ca8aced7)<br>Discord RPC integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp`, `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ef143933f94e`](https://github.com/eternalcodes/EternalJK/commit/ef143933f94e8ee7e873c604055274f5c6d7b2e5)<br>Fix compile | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2020-05-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bfdb71aee77`](https://github.com/videoP/jaPRO/commit/0bfdb71aee77ef4f66a7dbd4ec968946ac230e8d)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_cvar.c` | `high` |
| `2020-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c4b88abcfd76`](https://github.com/eternalcodes/EternalJK/commit/c4b88abcfd7678f9186ebec0c20ac98dc986d6b5)<br>cosmetic unlock integration? (loda) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_local.h`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/vk_image.cpp` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `high` |
| `2023-12-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`e194863d03f8`](https://github.com/taysta/TaystJK/commit/e194863d03f85d2e6dcfd9cf84233e2cc6614df2)<br>Fix some compiler warnings | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_ghoul2.cpp`, `shared/rd-rend2/tr_local.h` | `medium` |
| `2024-02-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7dce9a576823`](https://github.com/videoP/jaPRO/commit/7dce9a5768238bbc22a004660c36c252c217701f) · [PR #134](https://github.com/taysta/TaystJK/pull/134)<br>Japro update (#134) | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c`, `codemp/game/g_client.c` | `high` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fd60c90af33d`](https://github.com/taysta/TaystJK/commit/fd60c90af33defecee04566f23d593542b85a911)<br>bot cap routes | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `medium` |
| `2026-06-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`ca5625290071`](https://github.com/videoP/jaPRO/commit/ca5625290071860c03fbda26bf6082dfa47a0df0) · [PR #319](https://github.com/taysta/TaystJK/pull/319)<br>Merge pull request #319 from taysta/japro-up | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `high` |

## Evidence

- registration: [codemp/game/ai_wpnav.c:3288](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_wpnav.c#L3288) (Cvar_Register)
- registration: [codemp/game/ai_wpnav.c:3730](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_wpnav.c#L3730) (Cvar_Register)
- registration: [codemp/game/g_bot.c:242](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_bot.c#L242) (Cvar_Register)
- registration: [codemp/game/g_main.c:410](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L410) (Cvar_Register)
- registration: [codemp/game/g_main.c:3372](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L3372) (Cvar_Register)
- registration: [codemp/game/g_saga.c:163](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_saga.c#L163) (Cvar_Register)
- registration: [codemp/server/sv_init.cpp:980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L980) (Cvar_Get)
- behavior: [codemp/game/ai_wpnav.c:3309](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_wpnav.c#L3309)
- behavior: [codemp/game/g_account.c:1746](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L1746)
- behavior: [codemp/client/cl_discordrpc.cpp:137](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_discordrpc.cpp#L137)
- behavior: [codemp/cgame/cg_servercmds.c:154](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_servercmds.c#L154)
- behavior: [codemp/game/g_account.c:1813](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_account.c#L1813)
