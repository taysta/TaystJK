---
title: Speedometer Cvars
parent: Strafe Cvars
has_children: false
nav_order: 2
---

# Speedometer Updates
-   Configured using the `speedometer` command
-   Running count of previous groundspeeds with `speedometer 10` and cvar `cg_speedometerJumps N` where N is the number of jumps
-   Speedometer jumps configuration cvars `cg_speedometerJumpsX`, `cg_speedometerJumpsY`
-   Use `%J%` in a chat bind to say your last N jumps eg. `bind 6 "say Jumps: %J%"`
-   Speedometer colors can now be disabled with `speedometer 11`
-   `speedometer 13` displays speeds as red/green based on difference from previous jump
-   `cg_jumpGoal` You can now set a first jump speed goal speed, if first jump speed is above your goal speed, the groundspeed text will be green. Requires `speedometer 1` enabled
-   Updated speed graph, revert to old style with `speedometer 14`
