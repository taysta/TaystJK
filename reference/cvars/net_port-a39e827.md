---
title: "net_port"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_port`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `net_port` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `XSTRING( PORT_SERVER )` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/unix/unix_net.c:309](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/unix/unix_net.c#L309)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed an exact bound cvar-variable reference. `codemp/qcommon/qcommon.h` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f9edad82febe`](https://github.com/JACoders/OpenJK/commit/f9edad82febef0b016641a03a77e6d628d448032)<br>Removed cdkey code from mp/client | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e83eda7e823`](https://github.com/JACoders/OpenJK/commit/3e83eda7e823dfaffdece9e782b29d20d7ce117f)<br>Removed cdkey code from mp/server | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`62c08daffa41`](https://github.com/JACoders/OpenJK/commit/62c08daffa410a375ed1f9c6b8b273aecc5666e4)<br>Challenge and Print security fixes on client | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fab2a580f1d7`](https://github.com/JACoders/OpenJK/commit/fab2a580f1d7e250ce4cf9eb72975eb0ea7957e3)<br>Use memcmp for ipv4 as well | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_chan.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9950d594349c`](https://github.com/JACoders/OpenJK/commit/9950d594349cfc625be716fa33372a493604a948)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/unix/unix_net.c` | `high` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9e15fadfd9b4`](https://github.com/JACoders/OpenJK/commit/9e15fadfd9b4223b60de8e0e76affce52930fe0b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `high` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/unix/unix_net.c` | `high` |
| `2013-04-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f0123a1e1fd`](https://github.com/JACoders/OpenJK/commit/9f0123a1e1fdd1e7bd5c4532fdffd7f952b1d907)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `high` |
| `2013-07-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b2afca07b43c`](https://github.com/JACoders/OpenJK/commit/b2afca07b43c126553236315c5a90c8fbbf76f05)<br>Merge pull request #299 from xycaleth/fix-warnings | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ee552c5b46e5`](https://github.com/JACoders/OpenJK/commit/ee552c5b46e542f9b56f9471d12eb6defe0ad763)<br>Merge pull request #328 from xycaleth/rd-common | Changed an exact bound cvar-variable reference. `codemp/rd-common/tr_font.cpp` | `medium` |
| `2014-01-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`866f5878acc3`](https://github.com/JACoders/OpenJK/commit/866f5878acc36dbc638cdc3e831796eb2c953ed6)<br>[MP] Fix NET_AdrToString to display port correctly. Minor cleanup to NET_StringToAdr. Use NET_AdrToString in a few places. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/qcommon/net_chan.cpp` | `medium` |
| `2014-01-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ed5ac3f124fd`](https://github.com/JACoders/OpenJK/commit/ed5ac3f124fd2c802c95873da5deb518a0f69a49)<br>[MP] IPX Removal with code cleanup. Unix net code cleanup/updates to windows minus socks support. Might cause *nix compile failure. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/net_chan.cpp`, `codemp/win32/win_net.cpp` | `medium` |
| `2014-01-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`90d5fa42c4b5`](https://github.com/JACoders/OpenJK/commit/90d5fa42c4b58c5ac3a84cf96305bfba5ae4d3ae)<br>[MP] Unify win_net and sys_net into qcommon/net_ip. Unix now also supports the socks code. net_restart behaves correctly now if was disabled. | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_ip.cpp` | `medium` |
| `2014-01-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1c39cb27409a`](https://github.com/JACoders/OpenJK/commit/1c39cb27409adcaf1b7a0c5b70ddb069a25a7064)<br>[MP] Hopefully fixing OSX net_ip from ioq3 changes at this point. | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_ip.cpp` | `medium` |
| `2014-01-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cd5d3753f0a7`](https://github.com/JACoders/OpenJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c)<br>[MP] Removed net_noudp in favor of net_enabled. Currently only 0 or 1, but it will be supported via bitmask later. Some other minor cleanups and merges from ioq3 in net_ip. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/net_ip.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `high` |
| `2014-05-06` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5090c9b842f1`](https://github.com/JACoders/OpenJK/commit/5090c9b842f1002a620abb44626ea798caa7839e)<br>[MP] Fix port display in master heartbeat. | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2014-05-17` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3a70129c5dd2`](https://github.com/JACoders/OpenJK/commit/3a70129c5dd2e43fec4177cf18a93c4dbce1f262)<br>[MP] Make cl_motd archived and an index to which cl_motdServer is used. Add cl_motdServer1-5.  1 is default, 2 is jkhub, 3-5 are unset by default. Set cl_motd to 0 if you want to disable the Welcome player message entirely. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2014-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`73e537fdea26`](https://github.com/JACoders/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b)<br>[MP] Port ioq3 engine based ban code. | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_chan.cpp` | `medium` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `codemp/qcommon/qcommon.h`, `shared/sys/sys_public.h` | `medium` |
| `2016-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0efc3164f2c4`](https://github.com/eternalcodes/EternalJK/commit/0efc3164f2c42a426d8d316c6347ea74395fb694)<br>Upgrade to SDL 2.0.4 | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_egl.h` | `medium` |
| `2016-07-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cd9a5be34933`](https://github.com/taysta/TaystJK/commit/cd9a5be349338ea7df597fde50116ff9b976e7d0)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_ip.cpp`, `shared/sys/sys_public.h` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/curl/curl.h` | `high` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`15c685c83005`](https://github.com/eternalcodes/EternalJK/commit/15c685c830057239017ac08c4a9be5ab8a98c300)<br>Merge pull request #95 from Yberion/serversideEngineFix | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2023-10-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9bad009e9a2b`](https://github.com/taysta/TaystJK/commit/9bad009e9a2bde6d30e802704c2b465a742cd37b) · [PR #27](https://github.com/taysta/TaystJK/pull/27)<br>Merge pull request #27 from taysta/discord_validation | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2024-03-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) · [PR #169](https://github.com/taysta/TaystJK/pull/169)<br>HTTP Auto Download (Server + Client) (#169) | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_http.cpp`, `codemp/qcommon/net_ip.cpp`, `codemp/qcommon/qcommon.h` and 3 more | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/qcommon/net_chan.cpp`, `codemp/qcommon/net_ip.cpp` and 2 more | `medium` |
| `2025-04-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) · [PR #228](https://github.com/taysta/TaystJK/pull/228)<br>Update built in SDL version for windows to 2.32.4 (#228) | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_guid.h` | `medium` |

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:886](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L886) (Cvar_Get)
- behavior: [codemp/qcommon/net_ip.cpp:835](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L835)
- behavior: [codemp/server/sv_ccmds.cpp:1190](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L1190)
- behavior: [codemp/qcommon/net_ip.cpp:887](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L887)
- behavior: [codemp/qcommon/net_ip.cpp:888](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L888)
- behavior: [codemp/qcommon/net_ip.cpp:842](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L842)
