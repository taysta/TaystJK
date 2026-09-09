---
title: "sv_running"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_running`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Is a server running?

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `cgame` |
| Also registered in | `cgame`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame.menu:412](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L412) |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_cgame.cpp:551](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L551) |
| `1` | Enabled. | [codemp/client/cl_cgame.cpp:551](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L551) |

## Flags

- `CVAR_ROM` — read-only after registration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `engine-shared` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/common.cpp:1050](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/common.cpp#L1050)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`af4b4c2de891`](https://github.com/JACoders/OpenJK/commit/af4b4c2de891e091c429bcf9cc2d2f36d9d9d181)<br>Removed most Xbox stuff | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp`, `codemp/qcommon/common.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d1043c837228`](https://github.com/JACoders/OpenJK/commit/d1043c837228fea287e590753713376d1e15a4c0)<br>Pause code fixes (ioq3) | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e83eda7e823`](https://github.com/JACoders/OpenJK/commit/3e83eda7e823dfaffdece9e782b29d20d7ce117f)<br>Removed cdkey code from mp/server | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9344b45fc2d8`](https://github.com/JACoders/OpenJK/commit/9344b45fc2d8bb45e285499cd5706321eca2661e)<br>Updates to sv_ccmds.c.  Adds kickall, kickbots, kicknum (clientkick alias). kick all and kick allbots still work. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4a377df76459`](https://github.com/JACoders/OpenJK/commit/4a377df76459fc8024997def204efae18246bb77)<br>Killserver improvements | Changed an exact bound cvar-variable reference. `codemp/server/sv_init.cpp` | `medium` |
| `2013-04-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b1b8218b0d1a`](https://github.com/JACoders/OpenJK/commit/b1b8218b0d1a51151d3439616f376a1433f38905)<br>Only display the hitch warning message if server is actually running too | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`3e986be9ab0d`](https://github.com/JACoders/OpenJK/commit/3e986be9ab0dff376102717e0a693d58f048a66b)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `high` |
| `2013-07-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4d87f8556425`](https://github.com/JACoders/OpenJK/commit/4d87f8556425168ed81f5fe02a04c1d9936d9d44)<br>Merge branch 'master' of github.com:Razish/OpenJK | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_info.c`, `codemp/client/cl_cgame.cpp`, `codemp/client/cl_main.cpp` and 1 more | `medium` |
| `2014-01-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`649941d04db2`](https://github.com/JACoders/OpenJK/commit/649941d04db2a0d5581825824a3b88a3912f3185)<br>[MP] Merge cmd files into cmd.cpp. Improve cmdlist functionality. Add file buffer alias union. | Changed an exact bound cvar-variable reference. `codemp/qcommon/cmd.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp`, `codemp/server/sv_init.cpp` | `medium` |
| `2014-03-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6f4aadcbd269`](https://github.com/JACoders/OpenJK/commit/6f4aadcbd269b386afc086854ec26e3f3fa5fa0f)<br>[MP] CGame: Moved some cvar code to cg_cvar.c | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_cvar.c` | `medium` |
| `2014-04-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d45cd2ce3e70`](https://github.com/JACoders/OpenJK/commit/d45cd2ce3e70e49dfa98c7f50b876e7883f68392)<br>[MP] CL_ConnectedToServer -> CL_ConnectedToRemoteServer | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2014-08-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`73e537fdea26`](https://github.com/JACoders/OpenJK/commit/73e537fdea2620522dc7068f29cbd95fa113e13b)<br>[MP] Port ioq3 engine based ban code. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2014-08-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`03bba21225bb`](https://github.com/JACoders/OpenJK/commit/03bba21225bbdfe484236d00966b6783bd2077a7)<br>[MP] Add svtell command to send message to clients from server console. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/qcommon/net_ip.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2018-04-26` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`a983fa494fee`](https://github.com/taysta/TaystJK/commit/a983fa494fee7b9c475eed4eea61f7a05f9ede4b)<br>8 years too late, basic multiprotocol/multiversion support. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2018-05-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`097a0d05fa4e`](https://github.com/eternalcodes/EternalJK/commit/097a0d05fa4edb25c14bf88d42ea2bff668fd232)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0db4ffc5f66d`](https://github.com/eternalcodes/EternalJK/commit/0db4ffc5f66d247d9031f3efe8a893e3d95d7153)<br>rcon status cleanup pt2 | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2018-10-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`987d8cc36a14`](https://github.com/taysta/TaystJK/commit/987d8cc36a1414256cdfaf323cf7675319ddf0f5)<br>Exirmirai's server hibernation mode | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`580de0259290`](https://github.com/eternalcodes/EternalJK/commit/580de0259290c23ee3e410dc3772b373d118b3ff)<br>Discord status will show "Playing demo"/"Playing offline"/"Spectating on"/"Playing on" | Changed an exact bound cvar-variable reference. `codemp/client/cl_discordrpc.cpp` | `medium` |
| `2024-09-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ecf4edf9ad98`](https://github.com/taysta/TaystJK/commit/ecf4edf9ad985e0c95a2157d23adfd711206683b) · [PR #209](https://github.com/taysta/TaystJK/pull/209)<br>OpenJK Update (#209) | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:387](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L387) (XCVAR_DEF)
- registration: [codemp/qcommon/common.cpp:1480](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1480) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:551](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L551)
- behavior: [codemp/client/cl_cgame.cpp:813](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L813)
- behavior: [codemp/client/cl_cgame.cpp:963](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_cgame.cpp#L963)
- behavior: [codemp/client/cl_discordrpc.cpp:254](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L254)
- behavior: [codemp/client/cl_discordrpc.cpp:482](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_discordrpc.cpp#L482)
