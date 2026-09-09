---
title: "Removed and inactive"
layout: reference
nav_order: 6
parent: "Console reference"
---

# Removed and inactive names

These identifiers are not part of the active static inventory, but remain useful search targets. `inactive` means the apparent registration is commented/disabled in the current tree; `renamed` identifies a verified replacement.

| Name | Kind | Status | Replacement | Reason | Evidence |
|:--|:--|:--|:--|:--|:--|
| `cl_jk2FX` | cvar | renamed | `fx_jk2` | Renamed when JK2 projectile-effect handling moved into the FX subsystem. | [codemp/client/FxUtil.cpp:119](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/FxUtil.cpp#L119) |
| `d_npc` | cvar | inactive | — | The NPC-name debug registration is commented out. | [codemp/game/NPC.c:1984](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/NPC.c#L1984) |
| `d_slowmodeath` | cvar | inactive | — | The slow-motion death registration remains inside a disabled comment block. | [codemp/game/NPC.c:1943](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/NPC.c#L1943) |
| `g_blueTeam` | cvar | inactive | — | The old engine registration and UI setters are commented out. | [codemp/client/cl_main.cpp:3422](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3422) |
| `g_redTeam` | cvar | inactive | — | The old engine registration and UI setters are commented out. | [codemp/client/cl_main.cpp:3421](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3421) |
| `r_flareCoeff` | cvar | inactive | — | The Vulkan flare coefficient registration is commented out. | [codemp/rd-vulkan/tr_init.cpp:828](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L828) |
| `r_flareFade` | cvar | inactive | — | The Vulkan flare fade registration is commented out. | [codemp/rd-vulkan/tr_init.cpp:827](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L827) |
| `r_flareSize` | cvar | inactive | — | The Vulkan flare-size registration is commented out. | [codemp/rd-vulkan/tr_init.cpp:826](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L826) |
| `sv_debugserver` | cvar | inactive | — | The server debug registration is commented out. | [codemp/server/sv_init.cpp:1036](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1036) |
| `amsheev` | command | inactive | — | The player-command table entry is commented out. | [codemp/game/g_cmds.c:8901](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8901) |
| `amstatus` | command | inactive | — | The player-command table entry is commented out. | [codemp/game/g_cmds.c:8914](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8914) |
| `debugsetbodyanim` | command | inactive | — | The debug player-command table entry is commented out. | [codemp/game/g_cmds.c:8953](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8953) |
| `debugSetSaberMove` | command | inactive | — | The debug player-command table entry is commented out. | [codemp/game/g_cmds.c:8954](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8954) |
| `devmapbsp` | command | inactive | `devmap` | The MP server registration is commented out as not relevant to the multiplayer codebase. | [codemp/server/sv_ccmds.cpp:2332](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2332) |
| `dfrefresh` | command | inactive | — | The race-ranking player-command table entry is commented out. | [codemp/game/g_cmds.c:8958](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8958) |
| `kylesmash` | command | inactive | — | The player-command table entry is commented out. | [codemp/game/g_cmds.c:8989](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8989) |

This list covers inactive registration candidates found by the current-tree audit plus verified renames. Fully deleted historical names require an additional all-revision extraction and remain a future audit item.
