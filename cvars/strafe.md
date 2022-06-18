---
title: Strafe Cvars
parent: Cvars
has_children: true
nav_order: 6
---

# Strafe Cvars

## Race Timer

- Race timer start speed can now be moved seperate from the rest of the race timer with cvars `cg_raceStart 1`, `cg_raceStartX` and `cg_raceStartY`
- You can now set a start speed goal, if your start speed is above your goal speed, the text will be green `cg_startGoal`

## Speedometer

- Configured using the `speedometer` command
- Running count of previous groundspeeds with `speedometer 10` and cvar `cg_speedometerJumps N` where N is the number of jumps
- Speedometer jumps configuration cvars `cg_speedometerJumpsX`, `cg_speedometerJumpsY`
- Use `%J%` in a chat bind to say your last N jumps eg. `bind 6 "say Jumps: %J%"`
- Speedometer colors can now be disabled with `speedometer 11`
- `speedometer 13` displays speeds as red/green based on difference from previous jump
- `cg_jumpGoal` You can now set a first jump speed goal speed, if first jump speed is above your goal speed, the groundspeed text will be green. Requires `speedometer 1` enabled
- Updated speed graph, revert to old style with `speedometer 14`

## Strafe Helper Updates

- More strafe bars, draws 2 lines for all keys A, WA, W, WD, D, SD, S, SA, enable with new `strafehelper` options
- Updated Style (`strafehelper 1`) can be made smaller with new option `strafehelper 18`
- CGAZ Style (`strafehelper 2`) is now affected by `cg_strafeHelperCutoff`

## Trigger/Clip/Slick Rendering

- `r_renderClipBrushes 1` enable rendering of clip brushes
- `r_renderClipBrushesShader` shader to render over clip brushes
- `r_renderTriggerBrushes 1` enable rendering of trigger brushes
- `r_renderTriggerBrushesShader` shader to render over trigger brushes
- `r_renderSlickSurfaces 1` enable rendering of slick surfaces
- `r_renderSlickSurfacesShader` shader to render over slick surfaces