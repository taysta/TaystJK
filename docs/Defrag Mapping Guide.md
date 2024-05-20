**JKA Defrag Map Maker guide:**

This guide will focus on making defrag maps for jaPRO mod.  I don't know of any other JKA MP mod that does defrag timers except for CTF fast-caps (timers based on ctf flag capture).

**Base concept:**
A defrag course has a start and a finish.  Players spawn before the start line and their timer is started by crossing the start line.  Their timer is stopped when they hit the finish line and their time is recorded if it is a personal best.  Leaderboards exist to see how they compare to other players.  You can have many courses in one map.

**Movement styles:**
Currently there are 19 different movement styles in jaPRO defrag.  A movement style is simply a different set of movement physics the player can choose to use.  Leaderboards are specific to a movement style.  The styles are:

1. **siege**
	This is the style used in siege mode of JKA.  There is no air acceleration.  Players typically use rolling, ramps, and wall-strafe to increase speed.
2. **jka**
	Default JKA style.
3. **qw**
	Inspired by quakeworld but with JKA force jump.  Players can make tighter turns while maintaining their speed.  It also has ramp jumps.  
4. **cpm**
	Inspired by CPM from q3 defrag.  No forcejumps, faster basespeed (320), high air control, rampjumps, and double jumps.
5. **q3**
	Inspired by vanilla mode from q3 defrag.  Like CPM but without increased air control.
6. **pjk**
	Like CPM but with force jump, and regular JKA basespeed.
7. **wsw**
	Inspired by Warsow.  Like CPM but with a dash move and a walljump move, which lets you redirect your speed to any angle without speed loss.  Its version of ramp jump also does not reduce your horizontal speed at all.
8. **rjq3**
	Q3 with rocket launcher.  Players propel them selves with rocket knockback.  
9. **rjcpm**
	RJQ3 with air control.
10. **swoop**
	Riding a swoop bike.  It's modified to give you a grav boost option which lowers your gravity for a few seconds.
11. **jetpack**
	Jetpack but with different jetpack physics and spiderman style grapple hook that lets you properly swing.  It also has detpacks for self knockback boost.
12. **speed**
	JKA but with faster base speed (same as forcespeed).  It only gives you 50force which does not regen.
13. **sp**
	SP inspired physics (higher air accelerate and your speed is halved when you land unless the landing point is lower than your takeoff point).
14. **slick**
	All ground friction is removed and has super fast acceleration while on ground.  No forcejump.
15. **botcpm**
	Same as CPM but it has a button that makes your strafe angles perfect.
16. **coop**
	2 player mode.  JKA physics with weaopns that let you boost eachother.  
17. **ocpm**
	Version of CPM which tries to be mroe accurate to Q3 defrags version of CPM.  Specifically 125fps physics and velocity snapping.
18. **tribes**
	Tries to mimic the skiing and jetpack style of movement from the tribes franchise.  Has a gun that you can self boost with, and a thrust pack that you can trade forcepoints for speed with.
19. **surf**
	Inspired by CS 1.6 physics.  Can be used for surf maps or bhop maps.

Seaons:
Furthermore, leaderboards can be broken down per season.  The current seasons typically lasts 1 year, for example season 5 was 2023.  A global leaderboard still exists which ignores seasons.

On jaPRO, most defrag maps are combined into "racepacks".  A racepack typically has a spawn room with doors that lead to the individual courses.  Inside the courses, there is typically a button to go back to the main room.  These can be combined into one trigger entity to save entity space.  It's a good idea to include a CTF room in a racepack with CTF spawns and CTF flags so it can be played in the CTF gametype as well.  Same for TFFA - a small TFFA room with TFFA spawns will make the map more playable.

**Mapping tips:**
There are a few things to take into account when making a defrag map.  First is the start area.  You don't want players to be able to build up a huge amount of speed before hitting the start trigger, as this is typically seen as boring gameplay called "loop starting".  Areas before the start brush are typically very small and have a patchmesh infront of the start trigger so players cant re-trigger the start once they go past it.  There are other options (trigger_newpush) that let you dynamically cap a players speed in certain directions (to prevent "loop starting") while in the start.  
Checkpoint triggers are popular to scatter throughout the course so players can gauge their speed throughout the run.
Try to make use of noise, message, etc fields on the triggers.  If you have multiple courses, the message field on the finish trigger is mandatory and acts as the courses name.

**New/modified entities:**
See here https://github.com/videoP/jaPRO/blob/master/scripts/japro_entities.def

**Examples:**
Challenge style map: https://www.youtube.com/watch?v=NqDdeNQkCjI

Race map on built on an existing map: https://www.youtube.com/watch?v=m7W-88DdPKk

Climb style map: https://www.youtube.com/watch?v=crhV1V4IndM

Torture style map: https://www.youtube.com/watch?v=WlgNCN6MbtQ

Montage: https://www.youtube.com/watch?v=sy3HdYTx0yE

