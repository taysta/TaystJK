---
title: "Racing on jaPRO"
layout: reference
nav_order: 8
parent: "Features"
description: "Getting started with defrag racing on a jaPRO server: racemode, practice, accounts and leaderboards, the HUD setup racers use, and strafe trails."
toc: true
origin: japro
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Racing on jaPRO

<p class="page-lede">jaPRO's defrag mode times you through a course in the movement style of your choice and keeps a leaderboard for each style. This page covers the commands you use on a race server and the client settings racers usually change.</p>
</div>

This page is adapted from a player guide written by Kane for people new to jaPRO servers.
Kane's advice is attributed to Kane where it appears. The behaviour of each command has been
checked against the source, and where the source disagrees with the original guide, this
page follows the source.

jaPRO is a Jedi Academy mod by loda. As well as defrag, it runs FullForce, saber, CTF and
[Tribes](/TaystJK/features/tribes/) modes. Almost everything here is a **server** command,
handled by jaPRO's game module, so it only works on a server that runs jaPRO with race mode
enabled. The HUD settings are client-side and work anywhere.

## Where to play

Kane's guide points new players to jaPRO's own site, [playja.pro](http://www.playja.pro/),
which hosts the maps and the online leaderboards.

- **Server:** `connect s.playja.pro`
- **Maps:** [playja.pro/?page=maps](http://www.playja.pro/?page=maps)
- **More maps (optional):** [playja.pro/maps/base/](http://www.playja.pro/maps/base/),
  including single-player JKA maps with timers added, for strafing offline.
- **Record demos:** [playja.pro/?page=race](http://www.playja.pro/?page=race). Click the
  date of a run to download its demo.

These are community sites. Nothing on this page controls what they host.

## Getting into racemode

```text
race
```

[`race`](/TaystJK/reference/commands/race-de4bedc/) toggles racemode for you. The server has
to allow it (`g_raceMode` set to `2` or higher); otherwise it prints "This command is not
allowed!"
([`Cmd_Race_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L7691)).

Then pick a physics style with [`move`](/TaystJK/reference/commands/move-379d6ce/), for
example `move cpm`. Run it with no argument for the list your server accepts. You must be
standing still in racemode for it to work. [Movement styles](/TaystJK/features/movement-styles/#choosing-a-style)
explains each style and the conditions `move` checks.

To get around a map:

| Command | What it does |
|:--|:--|
| [`amtelemark`](/TaystJK/reference/commands/amtelemark-456039e/) | Saves your position and view angle as a teleport marker. |
| [`amtele`](/TaystJK/reference/commands/amtele-cbff2a5/) | Teleports you back to that marker. |
| [`warp`](/TaystJK/reference/commands/warp-af58c70/) `<name>` | Teleports you to a named course start, on maps and racepacks that define warps. [`warplist`](/TaystJK/reference/commands/warplist-c2ce9d3/) lists them. |
| [`noclip`](/TaystJK/reference/commands/noclip-9bf6a6e/) | Fly through walls to explore a map or reach another course. |
| [`callvote`](/TaystJK/reference/commands/callvote-1457e21/) `map <mapname>` | Asks the server to change map. |

`warp` matches any warp whose name **contains** what you type, and takes the first match
([`Cmd_Warp_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L7431)),
so a short name can land you on a different course than you meant.

Outside practice mode, toggling `noclip` resets your timer
([`Cmd_Noclip_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L858)).
If the server allows marking a position during a run, `amtelemark` only works while you are
on the ground
([`Cmd_Amtelemark_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L7283)).
Whether you can use `amtele` and `noclip` at all is a server setting (`g_allowRaceTele`).

## Practice mode

```text
practice
```

[`practice`](/TaystJK/reference/commands/practice-e17674f/) toggles practice mode. Like
`move`, it needs you in racemode and standing still, and toggling it resets a running timer
([`Cmd_Practice_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L7211)).

**Times are not saved in practice mode.** The server warns you on screen when you start a
run: "times are not valid in practice mode"
([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_trigger.c#L1664)).
In exchange you get tools that would not be fair in a timed run:

- **Strafebot.** Hold `+button14` and your strafe angle is set for you. It works in practice
  mode, and in the `botcpm` style at any time
  ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/bg_pmove.c#L15284)).
  Bind it like any other button, for example `bind mouse4 +button14`.
- **`launch`.** [`launch`](/TaystJK/reference/commands/launch-f7c91fe/) `<speed>` throws you
  forward from where you stand at that speed. `launch <x y z yaw xyspeed zspeed>` teleports
  you to a point first, then launches you. Both start your timer, so you can rehearse a
  section from a known entry speed
  ([`Cmd_Launch_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L7130)).

## Accounts and leaderboards

Your times are only recorded while you are logged in. If you start a run logged out, the
server warns you on screen
([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_trigger.c#L1660)).

| Command | What it does |
|:--|:--|
| [`register`](/TaystJK/reference/commands/register-13a2828/) | Creates an account and logs you in. |
| [`login`](/TaystJK/reference/commands/login-2736fab/) | Logs in to your account. |
| [`logout`](/TaystJK/reference/commands/logout-55525e1/) | Logs out. |
| [`aminfo`](/TaystJK/reference/commands/aminfo-b53555a/) | Lists the server's commands. |
| [`whois`](/TaystJK/reference/commands/whois-a93a167/) | Lists players with their client numbers, whether they are logged in, and their style. |
| [`stats`](/TaystJK/reference/commands/stats-e350d5c/) `<player>` | Shows a player's account statistics. |
| [`rtop`](/TaystJK/reference/commands/rtop-56f7fba/) `<course> <style>` | Top ten times for a course. With no style it shows `jka` ([`Cmd_DFTop10_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_account.c#L6512)). |
| [`rrank`](/TaystJK/reference/commands/rrank-4a8ddea/) | The overall leaderboard, or one style's. |
| [`rlatest`](/TaystJK/reference/commands/rlatest-fa0c7ce/) | The latest times, overall or for one style. |
| [`top`](/TaystJK/reference/commands/top-af2c7b4/) | Duel leaderboards for the fighting modes, for example `top saber`. |

**Log in again after every map change.** Your login lives in data the server clears each
time you connect, and a map change reconnects you
([`ClientConnect`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_client.c#L2924)).

## A basic HUD setup

Kane's guide suggests starting from the Loda strafe helper preset, after backing up your
current settings:

```text
write defrag.cfg
exec strafehelper_loda
```

[`write`](/TaystJK/reference/commands/write-e1d0c6c/) (also `writeconfig`) saves your current
settings, so `exec defrag.cfg` puts them back.
[Shipped configs](/TaystJK/features/shipped-configs/#strafe-helper-presets) lists the other
presets.

From there, adjust the pieces one at a time with their commands. Run each with no argument
to see its options, and with a number to toggle one.
[HUD and movement tools](/TaystJK/features/hud-and-movement/) covers them in detail.

| Command | What it configures |
|:--|:--|
| [`strafehelper`](/TaystJK/reference/commands/strafehelper-bdb34b4/) | The strafe helper. `strafehelper 14` toggles the line crosshair ([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L1123)). |
| [`speedometer`](/TaystJK/reference/commands/speedometer-b0e26e4/) | The speedometer. Kane recommends options `0`, `1`, `2`, `10` and `13`. |
| [`stylePlayer`](/TaystJK/reference/commands/styleplayer-33ef966/) | Player-model visual options. |
| [`pluginDisable`](/TaystJK/reference/commands/plugindisable-98b2c24/) | Toggles gameplay and presentation options the server offers. The numbers follow the list your server prints, so check it before toggling. |

## Settings racers change

Kane's guide lists these as the next settings to look at once the basics are working. Tab
completion lists the rest: type `cg_strafeHelper` or `cg_speedometer` and press Tab.

| Setting | What it does |
|:--|:--|
| [`cg_raceStart`](/TaystJK/reference/cvars/cg_racestart-e3c5285/) `1` | Keeps your start speed on screen for the whole run, not just the first three seconds ([`hud_strafehelper.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L2431)). |
| [`cg_speedometerX`](/TaystJK/reference/cvars/cg_speedometerx-58598b2/), [`cg_speedometerY`](/TaystJK/reference/cvars/cg_speedometery-7d4b635/) | Move the speedometer. Kane uses `400` and `200` to sit it above the strafe helper. |
| [`cg_strafeHelper_FPS`](/TaystJK/reference/cvars/cg_strafehelper_fps-c64555f/) | The frame rate the strafe helper calculates for. `0` uses your `com_maxfps`; values above `1000` are treated as `1000` ([`DF_SetFrameTime`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L858)). |
| [`cg_strafeHelperOffset`](/TaystJK/reference/cvars/cg_strafehelperoffset-018a25b/) | How far the helper line sits from the optimal angle. The default is `75`. Kane uses `0` and tracks one pixel over the line for maximum acceleration. |
| [`cg_strafeHelperLineWidth`](/TaystJK/reference/cvars/cg_strafehelperlinewidth-790968e/) | Thickness of the helper lines and the line crosshair. |
| [`cg_strafeHelperCutoff`](/TaystJK/reference/cvars/cg_strafehelpercutoff-2cd5794/) | How far the helper lines extend. Higher values draw shorter lines. |
| [`com_maxfps`](/TaystJK/reference/cvars/com_maxfps-658bd0c/) `333` | Kane's recommendation for the air-control styles and `slick`: in Kane's experience it gives better mouse input and slightly more turning strength there, while styles without air control move at the same speed at 125 and 333. |
| [`cl_timeNudge`](/TaystJK/reference/cvars/cl_timenudge-4435ccb/) `-100` | Kane suggests this on a high ping, to run a high frame rate without "Connection Interrupted" warnings. The client ignores a negative value while you spectate or play a demo ([`cl_cgame.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_cgame.cpp#L990)). |
| [`cg_specCameraMode`](/TaystJK/reference/cvars/cg_speccameramode-95baeef/) | When `1`, the default, spectating someone on a jaPRO server uses their first- or third-person view and camera distance. `0` keeps your own ([`cg_view.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_view.c#L2960)). Your `cg_fov` applies either way. |
| [`cg_fov`](/TaystJK/reference/cvars/cg_fov-05db256/), [`cg_thirdPersonRange`](/TaystJK/reference/cvars/cg_thirdpersonrange-4c9945a/) | Field of view and third-person camera distance. |

On the rocket styles, [`rocketChange`](/TaystJK/reference/commands/rocketchange-f69e6d8/)
flips the direction your rockets fire from. It needs you standing still and resets your timer
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_cmds.c#L6919)).

### Your own checkpoints

You can mark split points on any course. They live only in your client, and nobody else sees
them.

```text
addCheckpoint <x1> <y1> <z1> <x2> <y2> <z2>
```

[`addCheckpoint`](/TaystJK/reference/commands/addcheckpoint-7c51bf3/) takes two opposite
corners of a box
([`CG_AddCheckpoint_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L2073)).
`cg_showpos` shows your coordinates so you can find them. When you pass through the box in
racemode with your timer running, it prints your split time, average speed and top speed in
the centre of the screen
([`cg_snapshot.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_snapshot.c#L548)).

[`listCheckpoints`](/TaystJK/reference/commands/listcheckpoints-86cf253/) lists them by
number, [`deleteCheckpoint`](/TaystJK/reference/commands/deletecheckpoint-ec6c155/) `<#>`
removes one, and [`teleToCheckpoint`](/TaystJK/reference/commands/teletocheckpoint-7aa58eb/) `<#>`
teleports you to it.

## Strafe trails

A strafe trail draws a line through the map along a recorded run, marking where the runner
jumped and landed. Loading the world record trail for a course shows you its whole route.

**Etiquette:** trails are a learning tool. Kane's guide asks veteran players not to lean on
them to copy a route they could work out themselves.

The trails for record runs come in a separate pk3. Download
[`strafetrails.pk3`](https://github.com/videoP/Demo2Trail/raw/master/Releases/strafetrails.pk3)
and put it in the mod directory you play jaPRO from, the one the server's `fs_game` selects.

```text
loadTrail dash1-jka
clearTrail -1
```

[`loadTrail`](/TaystJK/reference/commands/loadtrail-490c577/) `<course-style>` loads
`strafetrails/<course-style>.cfg`
([`CG_SpawnStrafeTrailFromCFG_f`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L725)).
[`clearTrail`](/TaystJK/reference/commands/cleartrail-314b9f6/) `<client #>` removes a trail,
and `-1` removes every trail
([`CG_RemoveStrafeTrail`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_localents.c#L1258)).

You can also make trails:

- [`strafeTrail`](/TaystJK/reference/commands/strafetrail-dddd025/) `<client #>` draws a
  live trail behind a player in the server. Get their number from
  [`showPlayerId`](/TaystJK/reference/commands/showplayerid-eb4fbea/) or `whois`. With no
  argument it lists players and which ones you are tracing; `-1` toggles every player.
- [`cg_logStrafeTrail`](/TaystJK/reference/cvars/cg_logstrafetrail-6216305/) `<name>`
  records your own runs to `strafetrails/<name>.cfg` while your race timer is running, in
  the format `loadTrail` reads
  ([`cg_snapshot.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_snapshot.c#L777)).
  Set it back to `0` to stop.

Type `cg_strafeTrail` and press Tab for the settings that control how trails look.

## Other things worth knowing

| Command | What it does |
|:--|:--|
| [`cvarlist`](/TaystJK/reference/commands/cvarlist-5cafd84/) `<filter>` | Lists cvars whose names match a wildcard, for example `cvarlist *speedometer*`. |
| [`cosmetics`](/TaystJK/reference/commands/cosmetics-01c96cf/) | Lists the hats and other cosmetics you can equip. Most unlock by finishing a particular course in a set time, and the list shows the requirement. See [Cosmetics](/TaystJK/features/cosmetics/). |
| [`listEmojis`](/TaystJK/reference/commands/listemojis-4b9aa16/) | Lists the chat emoji your client loaded; they draw when [`cg_chatBoxEmojis`](/TaystJK/reference/cvars/cg_chatboxemojis-7bdc808/) is on. See [Chat emoji](/TaystJK/features/emoji/). |
| [`voicechat`](/TaystJK/reference/commands/voicechat-a1c96f1/) | On a jaPRO server, opens the Tribes-style VGS voice menu, which sends a chat line and plays a voice clip. Bind it and type the letters: `bind v voicechat`, then <kbd>V</kbd> <kbd>G</kbd> <kbd>S</kbd> for "Shazbot!". `ui_vgs 0` turns the menu off ([`ui_main.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L1061)). |
