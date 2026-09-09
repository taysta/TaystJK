---
title: "g_gametype"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_gametype`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Server gametype value

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `string` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | FFA | [codemp/ui/ui_xdocs.h:511](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L511) |
| `1` | Holocron | [codemp/ui/ui_xdocs.h:511](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L511) |
| `2` | Jedi Master | [codemp/ui/ui_xdocs.h:511](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L511) |
| `3` | Duel | [codemp/ui/ui_xdocs.h:513](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L513) |
| `4` | Powerduel | [codemp/ui/ui_xdocs.h:513](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L513) |
| `5` | SP FFA | [codemp/ui/ui_xdocs.h:514](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L514) |
| `6` | TFFA | [codemp/ui/ui_xdocs.h:515](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L515) |
| `7` | Siege | [codemp/ui/ui_xdocs.h:516](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L516) |
| `8` | CTF | [codemp/ui/ui_xdocs.h:517](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L517) |
| `9` | CTY | [codemp/ui/ui_xdocs.h:518](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L518) |

## Flags

- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `engine-server` | `—` | `always` |
| `0` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:246](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L246)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` and 1 more | `medium` |
| `2013-04-18` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`fb1edd965e6d`](https://github.com/JACoders/OpenJK/commit/fb1edd965e6d3439809b8a982e6cd8217adabb23)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/g_cmds.c`, `codemp/game/g_main.c` and 3 more | `high` |
| `2013-06-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`db4313eb0eb6`](https://github.com/JACoders/OpenJK/commit/db4313eb0eb6e40d44c2a6cf7ee67d0107c91201)<br>Merge remote-tracking branch 'upstream/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `medium` |
| `2013-06-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`873b95b64cc6`](https://github.com/JACoders/OpenJK/commit/873b95b64cc699afea28cf072479a516c3db9997)<br>Removed spmap and spdevmap. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7f053f0964cc`](https://github.com/JACoders/OpenJK/commit/7f053f0964cc98e9de60911ebe4befb0a1215028)<br>Improved status command for the console.  Is mostly inspired by the SOURCE status cmd. | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_cmds.c`, `codemp/game/g_main.c` and 2 more | `medium` |
| `2013-08-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`61cd6e979c3b`](https://github.com/JACoders/OpenJK/commit/61cd6e979c3bb37e8b05ca2c6f1a1fc0812aea17)<br>Removed stricmp etc, always use Q_ versions for consistency across platforms | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-28` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5cd41b41c941`](https://github.com/JACoders/OpenJK/commit/5cd41b41c941de081108a65bcffe81f41a77b876)<br>[MP] Port the xcvar stuff and clean up cvar usage in UI. Few minor tweaks in UI code for cleanup/was unused. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-10-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ada0921d57db`](https://github.com/JACoders/OpenJK/commit/ada0921d57dbe7a0e3efa364c21149374d8a0b0e)<br>[MP] Allow Capture the Ysalamiri in solo games | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-10-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`872159cb6796`](https://github.com/JACoders/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821)<br>[MP] Rewrote callvote to be far more robust | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2013-12-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f5c1b2ceb3ba`](https://github.com/JACoders/OpenJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1)<br>[MP] Made ui use bsearch for commands. Removed ui_teamOrders that did nothing. Made ui_test actually be considered a command to the engine. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_atoms.c` | `medium` |
| `2014-01-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6c0c841b1025`](https://github.com/JACoders/OpenJK/commit/6c0c841b1025831c732d81261e0cad2fc4a66440)<br>[MP] Fix stack corruption after 761e55fd73 | Changed an exact bound cvar-variable reference. `codemp/ui/ui_force.c` | `medium` |
| `2014-01-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2f056fba12f1`](https://github.com/JACoders/OpenJK/commit/2f056fba12f1d1fe86326868a7df572a0d3aa3ef)<br>[MP] UI_HasSetSaberOnly + UI_TrueJediEnabled tweaks. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2014-01-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d4ce8f0bbfe7`](https://github.com/JACoders/OpenJK/commit/d4ce8f0bbfe747de490416048277fa2a93d85233)<br>[MP] Clean up UI and bot code | Changed an exact bound cvar-variable reference. `codemp/ui/ui_atoms.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1abe445436b3`](https://github.com/JACoders/OpenJK/commit/1abe445436b322514c79e73269108e80a2de376f)<br>[MP] Force some cvars to update immediately. | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `medium` |
| `2014-08-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`036c904c5bd8`](https://github.com/JACoders/OpenJK/commit/036c904c5bd8134e33e69388ca77542a207e35f0)<br>[MP] Tweaked client list in status rcon cmd Cut client number down to 2 width since 32 is max players. Remove lastmsg and qport. Increased size of address to accommodate for future ipv6 support. Fix colored name padding. Based on ioquake/ioq3@94e36c288c6ce6b5273055e61077c29e81fbd2bf | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_svcmds.c`, `codemp/game/w_force.c` and 2 more | `high` |
| `2018-02-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`675e97128f48`](https://github.com/eternalcodes/EternalJK/commit/675e97128f486095bc24289cf0610badfd8130fd)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-02-06` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`f4405327b936`](https://github.com/videoP/jaPRO/commit/f4405327b9363ad0b91cd0ae1717fe9ed939982b)<br>Fixed VGS on non-jaPRO servers. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `high` |
| `2018-02-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6a8d7a01015a`](https://github.com/eternalcodes/EternalJK/commit/6a8d7a01015af48013b58b64390de2ffe982cfa3)<br>Merge remote-tracking branch 'eternalcodes/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-02-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`51e883047a18`](https://github.com/eternalcodes/EternalJK/commit/51e883047a186e26836d1bfff4b019e277f1d1cf)<br>Merge branch 'master' into eternalcodes/master | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2018-09-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd)<br>Added jcinfo2 to allow UI to only show Race button when relevant | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-10-06` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05f1ac70497e`](https://github.com/eternalcodes/EternalJK/commit/05f1ac70497e667ca2e6005753ff8bc76641c425)<br>rcon status cleanup move name to end of line, remove notrunc, cleanup status info | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6c6472650cc`](https://github.com/eternalcodes/EternalJK/commit/f6c6472650ccd08fb0d010755094ab09ca8aced7)<br>Discord RPC integration | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2019-06-13` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01)<br>Filter custom skins/species/hilts out of player menus on sv_pure servers | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2019-07-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbc6e7872c2b`](https://github.com/eternalcodes/EternalJK/commit/dbc6e7872c2b238f2515cd52cbd5f6cd6f303f93)<br>Add g_gametype description to xdocs (Artemis) | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2023-10-29` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) · [PR #29](https://github.com/taysta/TaystJK/pull/29)<br>Merge pull request #29 from taysta/reconcile | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c` | `high` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/game/g_svcmds.c:656](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L656) (Cvar_Register)
- registration: [codemp/game/g_xcvar.h:108](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L108) (XCVAR_DEF)
- registration: [codemp/server/sv_ccmds.cpp:204](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L204) (Cvar_Get)
- registration: [codemp/server/sv_init.cpp:976](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L976) (Cvar_Get)
- behavior: [codemp/game/ai_main.c:7977](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L7977)
- behavior: [codemp/game/ai_main.c:8125](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L8125)
- behavior: [codemp/game/g_cmds.c:3504](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3504)
- behavior: [codemp/game/g_main.c:173](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L173)
- behavior: [codemp/game/g_main.c:184](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L184)
- documentation: [codemp/ui/ui_xdocs.h:511](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L511)
