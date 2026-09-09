---
title: "sv_maxclients"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_maxclients`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Max. connected clients

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-server` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `8` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `8` | `engine-server` | `—` | `always` |
| `8` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:249](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L249)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_bot.c`, `codemp/game/g_client.c`, `codemp/game/g_log.c` and 3 more | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9344b45fc2d8`](https://github.com/JACoders/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e)<br>Updates to sv_ccmds.c.  Adds kickall, kickbots, kicknum (clientkick alias). kick all and kick allbots still work. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`92e12a9e9b19`](https://github.com/JACoders/OpenJK/commit/92e12a9e9b19525c1f589f1f6779e9397b6bfd26)<br>Fixed long upstanding server issues from ioq3.  Free server entitites BEFORE GAME_INIT rather than after too. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp`, `codemp/server/sv_init.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_xcvar.h`, `codemp/server/sv_main.cpp` | `high` |
| `2013-06-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9893377ad980`](https://github.com/JACoders/OpenJK/commit/9893377ad980acdddca56d87db8dbfb97de399d5)<br>Add number of clients out of possible number of clients to status command. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-06-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`873b95b64cc6`](https://github.com/JACoders/OpenJK/commit/873b95b64cc699afea28cf072479a516c3db9997)<br>Removed spmap and spdevmap. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/client/cl_lan.cpp`, `codemp/server/sv_gameapi.cpp` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2014-01-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`0984fd715bbb`](https://github.com/JACoders/OpenJK/commit/0984fd715bbb0b9e6b349153f58116f6bc779b06)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/server.h`, `codemp/server/sv_init.cpp` | `high` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d5666875f3`](https://github.com/JACoders/OpenJK/commit/44d5666875f34d77c7f2451c6f7a493e60e6a348)<br>Merge pull request #480 from dpadgett/svdemo | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-01-27` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fde9de23e2ad`](https://github.com/JACoders/OpenJK/commit/fde9de23e2ad96b11d590d659a44b7892f6c601a)<br>Merge pull request #481 from dpadgett/svdemo | Changed an exact bound cvar-variable reference. `codemp/server/sv_init.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2014-02-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `high` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2016-02-05` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c0330fa17b25`](https://github.com/videoP/jaPRO/commit/c0330fa17b25177146ae2b941c623e08e6d81813)<br>Merge branch 'master' into japro | Changed an exact bound cvar-variable reference. `codemp/game/g_log.c` | `high` |
| `2016-02-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`27bdcf654906`](https://github.com/eternalcodes/EternalJK/commit/27bdcf654906fc0ada7f7dd5dadac971d3512e9b)<br>botfilter fix | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2016-04-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d2ebafa99e8e`](https://github.com/taysta/TaystJK/commit/d2ebafa99e8ef5218aa345ff036abf3c26d83578)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/server/sv_main.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_main.c`, `codemp/server/sv_ccmds.cpp` | `high` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0db4ffc5f66d`](https://github.com/eternalcodes/EternalJK/commit/0db4ffc5f66d247d9031f3efe8a893e3d95d7153)<br>rcon status cleanup pt2 | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`987d8cc36a14`](https://github.com/taysta/TaystJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5)<br>Exirmirai's server hibernation mode | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp`, `codemp/server/sv_main.cpp` | `medium` |
| `2018-10-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`724b58ba6bf5`](https://github.com/eternalcodes/EternalJK/commit/724b58ba6bf535c832bbcfdb7a092ed3581fdcdc)<br>add sv_listrecording command start servers with hibernation disabled | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1bcb29af6443`](https://github.com/eternalcodes/EternalJK/commit/1bcb29af644349fd7a3acb14cc07ee634d168803)<br>Implement Blackwolf's Discord Integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2019-03-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad1655124ccf`](https://github.com/eternalcodes/EternalJK/commit/ad1655124ccf0e8663e0e33f02a8a9ffb9a275ff)<br>Discord lib handling cleanup | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6c6472650cc`](https://github.com/eternalcodes/EternalJK/commit/f6c6472650ccd08fb0d010755094ab09ca8aced7)<br>Discord RPC integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`15c685c83005`](https://github.com/eternalcodes/EternalJK/commit/15c685c830057239017ac08c4a9be5ab8a98c300)<br>Merge pull request #95 from Yberion/serversideEngineFix | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9a37943df03d`](https://github.com/eternalcodes/EternalJK/commit/9a37943df03dd6d09740d3cf94f596c82043d49f)<br>Fix broken ClientCleanName function+Refactor server fixes to utilize new legacyFixes bitmask and server mod detection. | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2023-06-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`64b8343c85ea`](https://github.com/taysta/TaystJK/commit/64b8343c85eae26d2990f8ab10f90ac73491c25c) · [PR #2](https://github.com/taysta/TaystJK/pull/2)<br>Merge pull request #2 from TomArrow/taysternal | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_svcmds.c` | `high` |
| `2024-03-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`2a5ea5d885dc`](https://github.com/taysta/TaystJK/commit/2a5ea5d885dc6c081b75631334aac405da3fa36d) · [PR #169](https://github.com/taysta/TaystJK/pull/169)<br>HTTP Auto Download (Server + Client) (#169) | Changed an exact bound cvar-variable reference. `codemp/server/sv_init.cpp` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:179](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L179) (XCVAR_DEF)
- registration: [codemp/server/sv_init.cpp:245](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L245) (Cvar_Get)
- registration: [codemp/server/sv_init.cpp:984](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L984) (Cvar_Get)
- behavior: [codemp/game/g_bot.c:483](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_bot.c#L483)
- behavior: [codemp/game/g_bot.c:515](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_bot.c#L515)
- behavior: [codemp/game/g_bot.c:657](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_bot.c#L657)
- behavior: [codemp/game/g_bot.c:694](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_bot.c#L694)
- behavior: [codemp/game/g_bot.c:727](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_bot.c#L727)
