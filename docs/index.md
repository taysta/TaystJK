## Strafe Helper Updates
* More strafe bars, draws 2 lines for all keys A, WA, W, WD, D, SD, S, SA, enable with new `/strafehelper` options
* Updated Style (`strafehelper 1`) can be made smaller with new option `/strafehelper 18`
* CGAZ Style (`strafehelper 2`) is now affected by `cg_strafeHelperCutoff`
***
## Speedometer Updates
* Running count of previous groundspeeds with `/speedometer 10` and cvar `cg_speedometerJumps N` where N is the number of jumps
* Speedometer jumps configuration cvars `cg_speedometerJumpsX`, `cg_speedometerJumpsY`
* Use `%J%` in a chat bind to say your last N jumps eg. `bind 6 "say Jumps: %J%"`
* Speedometer colors can now be disabled with `/speedometer 11`
* `/speedometer 13` displays speeds as red/green based on difference from previous jump
<br>![cg_speedometerJumpsColors 2](https://imgur.com/mZKTakh.png)
* `cg_jumpGoal` You can now set a first jump speed goal speed, if first jump speed is above your goal speed, the groundspeed text will be green. Requires `speedometer 1` enabled
***
## Trigger/Clip/Slick Rendering 
<br>![Clip/](https://imgur.com/hzh902m.png)
* `r_renderClipBrushes 1` enable rendering of clip brushes
* `r_renderClipBrushesShader` shader to render over clip brushes
* `r_renderTriggerBrushes 1` enable rendering of trigger brushes
* `r_renderTriggerBrushesShader` shader to render over trigger brushes
* `r_renderSlickSurfaces 1` enable rendering of slick surfaces
* `r_renderSlickSurfacesShader` shader to render over slick surfaces
***
## Race Timer Update
* Race timer start speed can now be moved seperate from the rest of the race timer with cvars `cg_raceStart 1`, `cg_raceStartX` and `cg_raceStartY`
* You can now set a start speed goal, if your start speed is above your goal speed, the text will be green `cg_startGoal` 
***
## Movement Keys Updates
* Added second movement keys style with cvar `cg_movemenyKeys 2` that sits over the crosshair, can be scaled with `cg_movementKeysSize` 
<br>![cg_movementKeys 2](https://imgur.com/KiDaQUi.png)
* `cg_movementKeys 3` is the same, but can be moved with `cg_movementKeysX` and `cg_movementKeysY`:
***
## Disruptor Updates
* `cg_crosshairScope 1` enables minimalist scope: crosshair, charge and ammo
* New trail effects enabled with `cg_disruptorNew 1`
    * `cg_disruptorTeamColour 1` Changes disruptor effects colors according to team
    * `cg_disruptorCoreColor` Changes disruptor line color (accepts hexcode eg. xffffff)
    * `cg_disruptorSpiral 1` Enable quake disruptor spiral effect
    * `cg_disruptorSpiralColor` Changes disruptor spiral color (accepts hexcode eg. xffffff)
    * `cg_disruptorMainTime` Amount of time to display disruptor primary fire
    * `cg_disruptorAltTime` Amount of time to display disruptor alt fire
***
## Pitch Helper
* Pitch helper is a new tool to help you maintain your pitch aim at a desired level based on colored text as a visual queue
* Pitch angle can now be drawn independently from  `cg_showpos` by enabling `cg_pitchHelper 1`
* Center point has green text and goes as a gradient to orange until it leaves `cg_pitchHelperRange` where the orange becomes red.
* The whole range can be offset up or down with `cg_pitchHelperOffset`
* The drawn number can be moved with `cg_pitchHelperX` and `cg_pitchHelperX`
***
## Keybind & Command Updates

* You can now bind key combinations using an Alt / Ctrl / Shift modifier key. For example, `bind ctrl+x kill` will make Ctrl + X perform `kill`.

* You can now bind the _right-side_ Alt / Ctrl / Shift keys separately from the _left-side_ keys. For example, `bind rctrl kill` will make the _right-side_ Ctrl key perform `kill`. Don't worry, your existing configuration is still 100% compatible — if no binding is specifically set for the right-side key, then the generic binding is used. The left-side key always uses the generic binding.

* Nested quotation marks are now supported in commands and binds, allowing for easier and more robust configuration. This allows entering commands like bind a "bind b "set c "d ; e" ; say "hello there"""

#### String Substitution (`strSub`)

* Executes a command, substituting in the contents of cvar(s). Surround cvar names with `$` dollar signs.

* Example: `strsub say "Hello, I am $name$"`

#### If Cvar (`ifCvar`)
 
* Executes a certain command based on the current setting of a cvar.
 
* Usage: `ifCvar [cvar name] <setting> <number of arguments to execute> <arguments to execute> <some other setting> <some other number of arguments> <some other arguments> ...`

* Settings can optionally begin with special modifiers prepended with `$` dollar sign:

| **Modifier**       	| **Description**                                                                                    	|
|--------------------	|----------------------------------------------------------------------------------------------------	|
| `$=`               	| Convert the setting to a number and compare whether it is equal to another number.                 	|
| `$!=`              	| Convert the setting to a number and compare whether it is unequal to another number.               	|
| `$>`               	| Convert the setting to a number and compare whether it is greater than another number.             	|
| `$<`               	| Convert the setting to a number and compare whether it is less than another number.                	|
| `$>=`              	| Convert the setting to a number and compare whether it is greater than or equal to another number. 	|
| `$<=`              	| Convert the setting to a number and compare whether it is less than or equal to another number.    	|
| `$contains`        	| Compare whether the setting contains some text anywhere in it.                                     	|
| `$beginswith`      	| Compare whether the setting begins with some text.                                                 	|
| `$endswith`        	| Compare whether the setting ends with some text.                                                   	|
| `$else`             	| This keyword will cause the comparison to always be true.                                          	|
| (No modifier used) 	| Compare whether the setting matches some text.                                                     	|

* Settings can also reference the value of another cvar by prepending that cvar's name with $.

* Simple example: `ifCvar cg_myCvar 0 2 say_team hi 1 2 say_team bye` → if cg\_myCvar is `0`, then `say_team hi` is executed. If it's `1`, then `say_team bye` is executed.
 
* Complex example: `ifCvar cg_mycvar $>=$cg_someOtherCvar 1 quit $containsbeer 3 set model desann $else 4 bind x say_team "hello there"` → if `cg_myCvar` is greater than or equal to the value of `cg_someOtherCvar`, then quit is executed. If it contains the word `beer` anywhere, then `set model desann` is executed. For anything else, `bind x say_team "hello there"` is executed.

#### Delay (`delay`)

Waits a specified time (in milliseconds) before executing whatever follows. Unlike the base JKA `wait` command, other commands may freely execute in the meantime.  
Example:`say darth;​delay 1000;​say vader`

#### Delay Cancel (`delaycancel`)

Cancels any pending `delay`(s) that contain the argument. Use `""` to match anything.  
Example: `delaycancel vader`

#### Wait Freely (`waitf`)

Waits a specified time (in number of frames) before executing whatever follows. Unlike the base JKA `wait` command, other commands may freely execute in the meantime.  
Example:`say darth;​waitf 333;​say vader`

#### Wait Freely Cancel (`waitfcancel`)

Cancels any pending `waitf`(s) that contain the argument. Use `""` to match anything.  
Example: `waitfcancel vader`
***
## Miscellaneous Updates 
* `cg_scoreboardTime 1` display the local time on the scoreboard
* New FFA invulnerability shell, enable with `/styleplayer 16`
* Added covid mask cosmetic & updated pumpkin mask cosmetic (from MB2)
* cosmetics can now be forced onto all player models on non-japro servers with the cvar `cg_forceCosmetics`

***
## Crash Fixes
* Fixed Linux related crash
* Fixed null skin name crash
***
## Vulkan Renderer
* Enable with `cl_renderer rd-vulkan; vid_restart`
* `r_fbo 1; r_bloom 1` to enable bloom, adjust with `r_bloom_intensity` and `r_bloom_threshold`
* See more info [here](https://github.com/ec-/Quake3e#vulkan-renderer)
* From JKSunny


## Welcome to GitHub Pages

You can use the [editor on GitHub](https://github.com/taysta/EternalJK/edit/master/docs/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/taysta/EternalJK/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
