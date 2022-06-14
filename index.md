> # New - taysta/EternalJK Wiki
>
> ## Strafe Helper Updates
>
> -   More strafe bars, draws 2 lines for all keys A, WA, W, WD, D, SD, S, SA, enable with new `strafehelper` options
> -   Updated Style (`strafehelper 1`) can be made smaller with new option `strafehelper 18`
> -   CGAZ Style (`strafehelper 2`) is now affected by `cg_strafeHelperCutoff`
>
> * * *
>
> ## Speedometer Updates
>
> -   Running count of previous groundspeeds with `speedometer 10` and cvar `cg_speedometerJumps N` where N is the number of jumps
> -   Speedometer jumps configuration cvars `cg_speedometerJumpsX`, `cg_speedometerJumpsY`
> -   Use `%J%` in a chat bind to say your last N jumps eg. `bind 6 "say Jumps: %J%"`
> -   Speedometer colors can now be disabled with `speedometer 11`
> -   `speedometer 13` displays speeds as red/green based on difference from previous jump  
      >     ![cg_speedometerJumpsColors 2](https://camo.githubusercontent.com/8c34a50dc8fee5fb5ac4e743ecf55f8c19c13cf14c4f1ef611026e084e7a63d5/68747470733a2f2f696d6775722e636f6d2f6d5a4b54616b682e706e67)
> -   `cg_jumpGoal` You can now set a first jump speed goal speed, if first jump speed is above your goal speed, the groundspeed text will be green. Requires `speedometer 1` enabled
> -   Updated speed graph, revert to old style with `speedometer 14`
>
> * * *
>
> ## Trigger/Clip/Slick Rendering
>
>
> ![Clip/](https://camo.githubusercontent.com/f60039865b1aa024208142bbfd4a2eecabdfa7cace946d174db8b78e97ec020a/68747470733a2f2f696d6775722e636f6d2f687a683930326d2e706e67)
>
> -   `r_renderClipBrushes 1` enable rendering of clip brushes
> -   `r_renderClipBrushesShader` shader to render over clip brushes
> -   `r_renderTriggerBrushes 1` enable rendering of trigger brushes
> -   `r_renderTriggerBrushesShader` shader to render over trigger brushes
> -   `r_renderSlickSurfaces 1` enable rendering of slick surfaces
> -   `r_renderSlickSurfacesShader` shader to render over slick surfaces
>
> * * *
>
> ## Race Timer Update
>
> -   Race timer start speed can now be moved seperate from the rest of the race timer with cvars `cg_raceStart 1`, `cg_raceStartX` and `cg_raceStartY`
> -   You can now set a start speed goal, if your start speed is above your goal speed, the text will be green `cg_startGoal`
>
> * * *
>
> ## Movement Keys Updates
>
> -   `cg_movemenyKeys 2` Added second movement keys style that sits over the crosshair, can be scaled with `cg_movementKeysSize`  
> -   `cg_movementKeys 3` is the same, but can be moved with `cg_movementKeysX` and `cg_movementKeysY`:
> -   Movement key overlay now includes attack/altattack inputs
>
> * * *
>
> ## Disruptor Updates
>
> -   `cg_crosshairScope 1` enables minimalist scope: crosshair, charge and ammo
> -   New trail effects enabled with `cg_disruptorNew 1`
>     -   `cg_disruptorTeamColour 1` Changes disruptor effects colors according to team
>     -   `cg_disruptorCoreColor` Changes disruptor line color (accepts hexcode eg. xffffff)
>     -   `cg_disruptorSpiral 1` Enable Quake disruptor spiral effect
>     -   `cg_disruptorSpiralColor` Changes disruptor spiral color (accepts hexcode eg. xffffff)
>     -   `cg_disruptorMainTime` Amount of time to display disruptor primary fire
>     -   `cg_disruptorAltTime` Amount of time to display disruptor alt fire
>
> * * *
>
> ## Pitch Helper
>
> -   Pitch helper is a new tool to help you maintain your pitch aim at a desired level based on colored text as a visual queue
> -   `cg_pitchHelper 1` Pitch angle can now be drawn independently from `cg_showpos`
> -   Center point has green text and goes as a gradient to orange until it leaves `cg_pitchHelperRange` where the orange becomes red.
> -   The whole range can be offset up or down with `cg_pitchHelperOffset`
> -   The drawn number can be moved with `cg_pitchHelperX` and `cg_pitchHelperX`
>
> * * *
>
> ## Keybind & Command Updates
>
> -   You can now bind key combinations using an Alt / Ctrl / Shift modifier key. For example, `bind ctrl+x kill` will make Ctrl + X perform `kill`.
>
> -   You can now bind the _right-side_ Alt / Ctrl / Shift keys separately from the _left-side_ keys. For example, `bind rctrl kill` will make the _right-side_ Ctrl key perform `kill`. Don't worry, your existing configuration is still 100% compatible — if no binding is specifically set for the right-side key, then the generic binding is used. The left-side key always uses the generic binding.
>
> -   Nested quotation marks are now supported in commands and binds, allowing for easier and more robust configuration. This allows entering commands like bind a "bind b "set c "d ; e" ; say "hello there"""
>
>
> #### String Substitution (`strSub`)
>
> -   Executes a command, substituting in the contents of cvar(s). Surround cvar names with `$` dollar signs.
>
> -   Example: `strsub say "Hello, I am $name$"`
>
>
> #### If Cvar (`ifCvar`)
>
> -   Executes a certain command based on the current setting of a cvar.
>
> -   Usage: `ifCvar [cvar name] <setting> <number of arguments to execute> <arguments to execute> <some other setting> <some other number of arguments> <some other arguments> ...`
>
> -   Settings can optionally begin with special modifiers prepended with `$` dollar sign:
>
>
> **Modifier**
>
> **Description**
>
> `$=`
>
> Convert the setting to a number and compare whether it is equal to another number.
>
> `$!=`
>
> Convert the setting to a number and compare whether it is unequal to another number.
>
> `$>`
>
> Convert the setting to a number and compare whether it is greater than another number.
>
> `$<`
>
> Convert the setting to a number and compare whether it is less than another number.
>
> `$>=`
>
> Convert the setting to a number and compare whether it is greater than or equal to another number.
>
> `$<=`
>
> Convert the setting to a number and compare whether it is less than or equal to another number.
>
> `$contains`
>
> Compare whether the setting contains some text anywhere in it.
>
> `$beginswith`
>
> Compare whether the setting begins with some text.
>
> `$endswith`
>
> Compare whether the setting ends with some text.
>
> `$else`
>
> This keyword will cause the comparison to always be true.
>
> (No modifier used)
>
> Compare whether the setting matches some text.
>
> -   Settings can also reference the value of another cvar by prepending that cvar's name with $.
>
> -   Simple example: `ifCvar cg_myCvar 0 2 say_team hi 1 2 say_team bye` → if cg\_myCvar is `0`, then `say_team hi` is executed. If it's `1`, then `say_team bye` is executed.
>
> -   Complex example: `ifCvar cg_mycvar $>=$cg_someOtherCvar 1 quit $containsbeer 3 set model desann $else 4 bind x say_team "hello there"` → if `cg_myCvar` is greater than or equal to the value of `cg_someOtherCvar`, then quit is executed. If it contains the word `beer` anywhere, then `set model desann` is executed. For anything else, `bind x say_team "hello there"` is executed.
>
>
> #### Delay (`delay`)
>
> Waits a specified time (in milliseconds) before executing whatever follows. Unlike the base JKA `wait` command, other commands may freely execute in the meantime.  
> Example:`say darth;​delay 1000;​say vader`
>
> #### Delay Cancel (`delaycancel`)
>
> Cancels any pending `delay`(s) that contain the argument. Use `""` to match anything.  
> Example: `delaycancel vader`
>
> #### Wait Freely (`waitf`)
>
> Waits a specified time (in number of frames) before executing whatever follows. Unlike the base JKA `wait` command, other commands may freely execute in the meantime.  
> Example:`say darth;​waitf 333;​say vader`
>
> #### Wait Freely Cancel (`waitfcancel`)
>
> Cancels any pending `waitf`(s) that contain the argument. Use `""` to match anything.  
> Example: `waitfcancel vader`
>
> #### Music Controls:
>
> #### Next Track (`mnext`)
>
> #### Previous Track (`mprev`)
>
> #### Pause/Play Music (`mpause`)
>
> #### Stop Music (`mstop`)
>
> These commands simulate hardware media buttons. Useful for controlling your music while in-game.
>
> Note that some music players do not support media buttons by default; for example, VLC Media Player requires media button support to be manually enabled in settings. These currently only work on the Win32 build.
>
> * * *
>
> ## Miscellaneous Updates
>
> -   `cg_scoreboardTime 1` Display the local time on the scoreboard
> -   `cg_ambientSounds 0` Enable/disable ambient map sounds
> -   `cg_weaponCycleAmmo` Show ammo for weapons on the selection cycle
> -   `styleplayer 16` New FFA invulnerability shell
> -   `cosmetics 8` Added covid mask cosmetic & updated pumpkin mask cosmetic (from MB2)
> -   `cg_forceCosmetics` cosmetics can now be forced onto all player models on non-japro servers
> -   `cg_hudFiles 4` new Quake Champions style hud
> -   `cg_drawTimer 7` new csgo style match timer
> -   `cg_drawTeamOverlay 3` new style team overlay, set to 4 to ignore local client
> -   Fixed various Linux compiling problems and related crashes
> -   Fixed null skin name crash
> -   Water wake shader fix from Circa
> -   Textureless MP Swoop fix from MagSul
> -   Jawa sound fixes from eezstreet
> -   Broken effects fixes
> -   Weapon charge sounds now accurately reflect their charge times
> -   Reduced NPCs choppy/laggy movement
> -   Chat/console now support \[shift+\]ctrl+backspace/del/left/right shortcuts
>
> ## Shader Overrides
>
> -   If there are two shaders sharing the same name, the one that was found in a file later on JKA file list (phone book order) takes precedence. For example if there is a shader called gfx/2d/charsgrid\_med in both shaders/original.shader and shaders/fonts.shader only the shader found in shaders/original.shader will be used then.
> -   Before this change, combining multiple mods that target shaders from the same .shader file was impossible without merging the shaders of all the mods into one shader that is a complete copy of the base shader it originally existed in. This made it a hassle to use multiple mods that were designed to apply new shaders to base assets.
>
> * * *
>
> ## Vulkan Renderer
>
> -   Enable with `cl_renderer rd-vulkan; vid_restart`
> -   `r_fbo 1; r_bloom 1` to enable bloom, adjust with `r_bloom_intensity` and `r_bloom_threshold`
> -   See more info [here](https://github.com/ec-/Quake3e#vulkan-renderer)
> -   From JKSunny
