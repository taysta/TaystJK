---
title: "HUD and movement tools"
layout: reference
nav_order: 3
parent: "Features"
description: "Killfeed, team overlays, the centre timer and team score, SnapHUD, PitchHUD, the strafe helper, the speedometer, and the movement-keys display."
toc: true
origin: japro
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# HUD and movement tools

<p class="page-lede">On-screen tools this client adds for reading the game state and your own movement. Most of them are off by default, and the useful ones are configured by a command rather than by typing a number.</p>
</div>

## Bitmask cvars are configured by a command

Several of these tools pack every option into one integer. You are not expected to work out
that integer. Each has a companion command that prints the options as a numbered table and
toggles them one at a time:

| Command | Sets | Notes |
|:--|:--|:--|
| `strafehelper` | [`cg_strafeHelper`](/TaystJK/reference/cvars/cg_strafehelper-4850985/) | |
| `speedometer` | [`cg_speedometer`](/TaystJK/reference/cvars/cg_speedometer-9810620/) | |
| `stylePlayer` | [`cg_stylePlayer`](/TaystJK/reference/cvars/cg_styleplayer-c35894d/) | Player-model options; see [Cosmetics](/TaystJK/features/cosmetics/). |
| `plugin` (or `pluginDisable`) | [`cp_pluginDisable`](/TaystJK/reference/cvars/cp_plugindisable-715762d/) | Only on a JA+ or jaPRO server; it returns silently anywhere else ([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L1292)). |

Run one with no argument to see every option, its number, and whether it is on. Run it with
a number to toggle that option; it prints the new state.

```text
strafehelper        list every option
strafehelper 2      toggle option 2
```

**Some options are radio groups.** Turning one on turns its siblings off, because they are
alternatives rather than additions. The strafe helper's five styles behave this way
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L1165)),
as do the speedometer's unit and array-colour pairs
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L1560)).

Setting the cvar directly replaces every option at once, which is why `exec`ing a preset
does not merge with what you had. Presets ship with the client; see
[shipped configs](/TaystJK/features/shipped-configs/).

## The strafe helper

The most developed tool here. It draws the angle at which you gain speed for your current
movement style, so the physics it assumes change with the style the server is running; see
[movement styles](/TaystJK/features/movement-styles/).

Run `strafehelper` for the live list
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L1108)).
The options fall into three groups.

**Pick one style:** `Original`, `Updated`, `Cgaz`, `Warsow` or `Weze`. These are the
radio group; the rest stack on top.

**Choose which directions to draw:** `W`, `WA`, `WD`, `A`, `D`, `S`, `SA`, `SD`, plus
`Rear` and `Center`. Most players draw only the directions they actually strafe in.

**Add extras:** `Sound`, `Accel bar`, `Accel Zones`, `Line Crosshair`, `Small Lines`
and `Max`.

Tuning lives in separate cvars rather than bits: `cg_strafeHelperPrecision`,
`cg_strafeHelperOffset`, `cg_strafeHelperLineWidth`, `cg_strafeHelperCutoff`,
`cg_strafeHelperActiveColor`, `cg_strafeHelperInactiveAlpha` and `cg_strafeHelper_FPS`.
Look each up in the [console reference](/TaystJK/reference/?q=cg_strafehelper).

## The speedometer

Also bit-configured, via `speedometer`
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_consolecmds.c#L1509)).
Beyond the speed readout itself it can show pre-speed, jump height and distance, a vertical
speed indicator, a yaw speed indicator, an accel meter, a speed graph, and an array of your
recent pre-speeds.

Two choices are radio groups: units (`kilometers` or `imperial miles`, otherwise game
units) and the two array colour schemes.

Position and size are cvars: `cg_speedometerX`, `cg_speedometerY`, `cg_speedometerSize`,
and for the jumps array `cg_speedometerJumps`, `cg_speedometerJumpsX` and
`cg_speedometerJumpsY`.

## SnapHUD

Draws the yaw zones where the engine's velocity snapping helps or hurts, so you can turn
against them deliberately
([`hud_strafehelper.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L403)).
`cg_snapHud` turns it on; `cg_snapHudRgba1` and `cg_snapHudRgba2` colour the one-key and
two-key cases, and `cg_snapHudY` and `cg_snapHudHeight` place it.

Where the zones fall depends on the physics, and `cg_snapHudAuto` decides how the angle is
picked
([`hud_strafehelper.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L2563)).
Left at its default it follows what you are pressing and whether the style is CPM-like. Set
it to `0` and it always uses the fixed `cg_snapHudDef` angle instead.

`cg_snapHudFps` and `cg_snapHudSpeed` are separate overrides for the frame rate and base
speed the calculation assumes; both are worked out for you unless you set them. Leave all
three alone unless you know which numbers you want.

## PitchHUD

A much simpler readout of your pitch angle, for styles where looking up or down by a fixed
amount matters
([`hud_strafehelper.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L409)).
`cg_pitchHud` enables it; `cg_pitchHudAngle`, `cg_pitchHudWidth`, `cg_pitchHudThickness`,
`cg_pitchHudX` and `cg_pitchHudRgba` shape it.

## Pitch helper and position readout

Two small text readouts share the movement HUD's drawing code
([`DF_DrawShowPos`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L2445)).

[`cg_pitchHelper`](/TaystJK/reference/cvars/cg_pitchhelper-e3dadd7/) prints your pitch angle as a number. It is
separate from the PitchHUD above, which draws a marker rather than text. The number is green
while your pitch is inside a band [`cg_pitchHelperRange`](/TaystJK/reference/cvars/cg_pitchhelperrange-249a33b/)
degrees wide, shades towards orange near the edge of the band, and turns red outside it.
The band is centred on level unless [`cg_pitchHelperOffset`](/TaystJK/reference/cvars/cg_pitchhelperoffset-9b851a1/)
moves it. [`cg_pitchHelperX`](/TaystJK/reference/cvars/cg_pitchhelperx-a9d35e3/) and
[`cg_pitchHelperY`](/TaystJK/reference/cvars/cg_pitchhelpery-285d43a/) place it.

[`cg_showpos`](/TaystJK/reference/cvars/cg_showpos-785191d/) prints your position, view angles and speed in the
top-right corner. It is the quickest way to find the coordinates
[`addCheckpoint`](/TaystJK/features/racing/#your-own-checkpoints) needs.

## When these tools are drawn

The strafe helper, speedometer, movement keys, SnapHUD, PitchHUD, pitch helper and
`cg_showpos` are all drawn as part of the HUD
([`DF_DrawStrafeHUD`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L384)), so they appear and
disappear with it
([`cg_draw.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L11605)):

- not while you are on the spectator team, dead, or holding the scoreboard open
- not with [`cg_drawStatus 0`](/TaystJK/reference/cvars/cg_drawstatus-b5d2624/), which hides the whole status HUD
  and these tools with it
- not in a vehicle whose own HUD replaces the normal one

**SnapHUD and PitchHUD need company.** The HUD only enters this code while the speedometer,
a strafe-helper style, the movement keys, the race timer or race start, the pitch helper or
`cg_showpos` is on ([`cg_draw.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L1962)). `cg_snapHud` and
`cg_pitchHud` are not on that list, so either one turned on by itself draws nothing. Turn
on one of the others alongside it.

On a jaPRO server in racemode, SnapHUD is also hidden for every style except `ocpm`
([`showSnapHud`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L374)).

If one of them has vanished, check those before its own settings.

## Movement keys

Shows which movement inputs you are pressing. This is useful for recording, for spectating, and
for seeing your own mistakes
([`CG_DrawMovementKeys`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_strafehelper.c#L2271)).

`cg_movementKeys` selects one of four layouts. `1` and `2` are the original display near the
bottom of the screen, and `2` adds your attack and alt-attack inputs to it. `4` is the newer
layout in the same place. `3` is the same newer layout drawn small and **fixed at the
crosshair**. It is the one exception that ignores `cg_movementKeysX` and
`cg_movementKeysY`, so if your offsets appear to do nothing, that is why.

`cg_movementKeysWalk` adds the walk key, and `cg_movementKeysSize` scales whichever layout
you chose.

## The killfeed

A running list of recent kills, derived from ioquake3's obituary code
([`hud_obituary.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/hud_obituary.c#L41)).
`cg_killfeed` turns it on
([`cg_draw.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L11554)).

`cg_killfeedX` and `cg_killfeedY` offset it, `cg_killfeedIconSize` and
`cg_killfeedTextSize` resize the two halves independently, `cg_killfeedAlignment` sets which
edge it aligns to, `cg_killfeedColors` colours the weapon icons, and `cg_killfeedReverse`
swaps the killer and victim sides.

## Team overlay

A list of your team with health, position and more, in team gametypes. `cg_drawTeamOverlay`
selects one of three designs, each as a pair
([`cg_draw.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L6911)):

| Value | Design | Highlights you |
|:--|:--|:--|
| `1` / `2` | The original overlay | `2` |
| `3` / `4` | The second style | `4` |
| `5` / `6` | The third style | `6` |

The odd value of each pair draws every teammate the same; the even one marks your own row.

`cg_drawTeamOverlayX` and `cg_drawTeamOverlayY` place it, and `cg_drawTeamOverlayWeapons`
adds each player's weapon. `cg_drawTeamOverlayScale` and `cg_drawTeamOverlayMaxHP` apply to
styles `5` and `6` only. The second sets what counts as a full health bar, since combined
health and shields can exceed 100. `cg_drawTeamOverlayForce` adds a force-point column and
needs a jaPRO server to have anything to show.

## The centre timer and team score

The stock HUD puts the timer and scores in the top-right corner. TaystJK adds a centred
arrangement across the top of the screen instead. The maintainer's changelog calls it a
Counter-Strike-style timer built from three cvars that are designed to be set together
([`CG_DrawTaystHUD`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L3825)).

```text
cg_drawTimer 7
cg_drawScores 3
cg_drawStatus 2
```

[`cg_drawTimer 7`](/TaystJK/reference/cvars/cg_drawtimer-431f426/) draws the match time in a box at the top centre.
Values `1` to `6` are the stock corner styles instead, and they follow the FPS counter's
font when one is enabled
([`CG_DrawTimer`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L5906)).

[`cg_drawScores 3`](/TaystJK/reference/cvars/cg_drawscores-493f7be/) puts the two team scores in boxes either side of
that timer. Without `cg_drawTimer 7` they still appear, centred on their own.

[`cg_drawStatus`](/TaystJK/reference/cvars/cg_drawstatus-b5d2624/) `2` or `3` adds flag status to the same row, in CTF
and CTY only
([`CG_DrawTeamHUD`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L3864)).

Two timer options only make sense here. `cg_drawTimerMsec` adds milliseconds, and
`cg_drawTimerCountdown` counts **down** to the time limit rather than up, which needs a
time limit to exist and applies to style `7`
([`cg_draw.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_draw.c#L5924)).
A negative `cg_drawTimer` shows absolute client time rather than time since the map loaded.

The quickest way to see the whole arrangement is to run the shipped preset, which sets these
along with the killfeed, the team overlay and the movement keys:

```text
exec hud_tayst
```

## Whole-HUD styles

`cg_hudFiles` swaps the underlying HUD layout rather than individual elements
([`cg_main.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_main.c#L2611)):
`3` loads the Elegance HUD and `4` loads the Tayst HUD, the Quake-style option. Both ship
in the asset pk3. The default leaves the stock Jedi Academy HUD in place. It takes effect immediately; the cvar
reloads the HUD when it changes
([`cg_cvar.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_cvar.c#L59)).

This is separate from everything above: the elements on this page draw regardless of which
HUD file you load.
