---
title: Pitch Helper
parent: HUD Cvars
grand_parent: Cvars
has_children: false
nav_order: 2
---

# Pitch Helper

-   Pitch helper is a new tool to help you maintain your pitch aim at a desired level based on colored text as a visual queue
-   `cg_pitchHelper 1` Pitch angle can now be drawn independently from `cg_showpos`
-   Center point has green text and goes as a gradient to orange until it leaves `cg_pitchHelperRange` where the orange becomes red.
-   The whole range can be offset up or down with `cg_pitchHelperOffset`
-   The drawn number can be moved with `cg_pitchHelperX` and `cg_pitchHelperX`