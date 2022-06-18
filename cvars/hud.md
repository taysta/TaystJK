---
title: HUD Cvars
parent: Cvars
has_children: true
nav_order: 3
---

# Hud Cvars

## Hud Updates

- `cg_hudFiles 4` new Quake Champions style hud
- `cg_drawTimer 7` new csgo style match timer
- `cg_drawTeamOverlay 3` new style team overlay, set to 4 to ignore local client
- `cg_scoreboardTime 1` Display the local time on the scoreboard
- `cg_weaponCycleAmmo` Show ammo for weapons on the selection cycle

## Movement Keys

- `cg_movemenyKeys 2` Added second movement keys style that sits over the crosshair, can be scaled with `cg_movementKeysSize`
- `cg_movementKeys 3` is the same, but can be moved with `cg_movementKeysX` and `cg_movementKeysY`:
- Movement key overlay now includes attack/altattack inputs

# Pitch Helper

- Pitch helper is a new tool to help you maintain your pitch aim at a desired level based on colored text as a visual queue
- `cg_pitchHelper 1` Pitch angle can now be drawn independently from `cg_showpos`
- Center point has green text and goes as a gradient to orange until it leaves `cg_pitchHelperRange` where the orange becomes red.
- The whole range can be offset up or down with `cg_pitchHelperOffset`
- The drawn number can be moved with `cg_pitchHelperX` and `cg_pitchHelperX`
