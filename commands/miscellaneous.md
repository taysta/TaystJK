---
layout: page
title: Miscellaneous Commands
parent: Commands
has_children: true
nav_order: 1

---

# Miscellaneous Commands

## String Substitution 

`strSub`

Executes a command, substituting in the contents of cvar(s). Surround cvar names with `$` dollar signs.

***Example:*** `strsub say "Hello, I am $name$"`



## If Cvar

`ifCvar`

Executes a certain command based on the current setting of a cvar.

***Usage:*** `ifCvar [cvar name] <setting> <number of arguments to execute> <arguments to execute> <some other setting> <some other number of arguments> <some other arguments> ...`

Settings can optionally begin with special modifiers prepended with `$` dollar sign:

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
| `else`             	| This keyword will cause the comparison to always be true.                                          	|
| (No modifier used) 	| Compare whether the setting matches some text.

Settings can also reference the value of another cvar by prepending that cvar's name with $.

***Simple example:*** `ifCvar cg_myCvar 0 2 say_team hi 1 2 say_team bye` → if cg\_myCvar is `0`, then `say_team hi` is executed. If it's `1`, then `say_team bye` is executed.

***Complex example:*** `ifCvar cg_mycvar $>=$cg_someOtherCvar 1 quit $containsbeer 3 set model desann $else 4 bind x say_team "hello there"` → if `cg_myCvar` is greater than or equal to the value of `cg_someOtherCvar`, then quit is executed. If it contains the word `beer` anywhere, then `set model desann` is executed. For anything else, `bind x say_team "hello there"` is executed.

## Delay

`delay`

Waits a specified time (in milliseconds) before executing whatever follows. Unlike the base JKA `wait` command, other commands may freely execute in the meantime.  
***Example:*** `say darth;​delay 1000;​say vader`

## Delay Cancel 

`delaycancel`

Cancels any pending `delay`(s) that contain the argument. Use `""` to match anything.  
***Example:*** `delaycancel vader`

## Wait Freely 

`waitf`

Waits a specified time (in number of frames) before executing whatever follows. Unlike the base JKA `wait` command, other commands may freely execute in the meantime.  
***Example:*** `say darth;​waitf 333;​say vader`

## Wait Freely Cancel 

`waitfcancel`

Cancels any pending `waitf`(s) that contain the argument. Use `""` to match anything.  
***Example:*** `waitfcancel vader`

## Music Controls

### Next Track

`mnext`

### Previous Track 

`mprev`

### Pause/Play Music 

`mpause`

### Stop Music 

`mstop`