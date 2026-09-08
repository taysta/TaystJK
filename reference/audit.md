---
title: "Audit report"
layout: reference
nav_order: 7
parent: "Console reference"
---

# Audit report

This is the deliberately untidy review queue behind the published reference. `unknown` and `needs-review` are used instead of guesses.

## Totals by origin

| Group | Count |
|:--|--:|
| Base Jedi Academy | 1024 |
| EternalJK | 136 |
| JK2MV | 19 |
| NewJK / NewMod | 10 |
| OpenJK | 215 |
| TaystJK | 82 |
| Vulkan | 32 |
| jaPRO | 464 |
| rend2 | 32 |

## Runtime reconciliation

Runtime target: `dedicated-server`; build: `latest-actions-autorelease-update-8433767e0`.

The static inventory is a union of client, dedicated server, game, cgame, UI, platform-conditional, and renderer registrations. Static-only entries are therefore expected for a single runtime target.

| Registry | Runtime | Static union | Runtime-only | Expected static-only |
|:--|--:|--:|--:|--:|
| Cvars | 456 | 1441 | 0 | 985 |
| Commands | 80 | 573 | 0 | 493 |

Runtime-only cvars: none.

Runtime-only commands: none.

The dump was captured from stdout after loading `mp/ffa3`; stdout does not use the client console scrollback buffer. Cvars and commands were dumped in separate launches so neither list could displace the other.

## Provenance needing review (899)

| Name | Kind | Module | Summary |
|:--|:--|:--|:--|
| [`_dedicated`](/TaystJK/reference/cvars/entry-_dedicated-f30b22a/) | cvar | engine-shared | Controls `com_dedicated` in the engine-shared module. |
| [`bot_maxbots`](/TaystJK/reference/cvars/bot_maxbots-0448e7e/) | cvar | game | Controls `bot_maxbots` in the game module. |
| [`bot_s1`](/TaystJK/reference/cvars/bot_s1-d2c1d4f/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s2`](/TaystJK/reference/cvars/bot_s2-0d0b10e/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s3`](/TaystJK/reference/cvars/bot_s3-e579014/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s4`](/TaystJK/reference/cvars/bot_s4-e27ebfb/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s5`](/TaystJK/reference/cvars/bot_s5-cc1e024/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s6`](/TaystJK/reference/cvars/bot_s6-67ce6b4/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_strafeOffset`](/TaystJK/reference/cvars/bot_strafeoffset-0fc4233/) | cvar | game | Controls `bot_strafeOffset` in the game module. |
| [`cg_alwaysShowAbsorb`](/TaystJK/reference/cvars/cg_alwaysshowabsorb-d52ebf0/) | cvar | cgame | Show absorb when it's in use |
| [`cg_ambientSounds`](/TaystJK/reference/cvars/cg_ambientsounds-00fb29b/) | cvar | cgame | Play ambient sounds |
| [`cg_autoKillWhenFalling`](/TaystJK/reference/cvars/cg_autokillwhenfalling-9eb85fc/) | cvar | cgame | Controls `cg_autoKillWhenFalling` in the cgame module. |
| [`cg_autoLoginPass1`](/TaystJK/reference/cvars/cg_autologinpass1-d618f6e/) | cvar | cgame | Password to use. |
| [`cg_autoLoginPass2`](/TaystJK/reference/cvars/cg_autologinpass2-b2b6380/) | cvar | cgame | Controls `cg_autoLoginPass2` in the cgame module. |
| [`cg_autoLoginPass3`](/TaystJK/reference/cvars/cg_autologinpass3-2065bc1/) | cvar | cgame | Controls `cg_autoLoginPass3` in the cgame module. |
| [`cg_autoLoginServer1`](/TaystJK/reference/cvars/cg_autologinserver1-0ca4073/) | cvar | cgame | IP of server to try to autologin on, used with /autologin command. If you are not on the right server, the password will not be sent to the server. |
| [`cg_autoLoginServer2`](/TaystJK/reference/cvars/cg_autologinserver2-9a34450/) | cvar | cgame | Controls `cg_autoLoginServer2` in the cgame module. |
| [`cg_autoLoginServer3`](/TaystJK/reference/cvars/cg_autologinserver3-66a3457/) | cvar | cgame | Controls `cg_autoLoginServer3` in the cgame module. |
| [`cg_autoRecordDemo`](/TaystJK/reference/cvars/cg_autorecorddemo-fad7d88/) | cvar | cgame | Controls `cg_autoRecordDemo` in the cgame module. |
| [`cg_autoRecordRaceDemo`](/TaystJK/reference/cvars/cg_autorecordracedemo-7ac473c/) | cvar | cgame | Controls `cg_autoRecordRaceDemo` in the cgame module. |
| [`cg_autoScreenshot`](/TaystJK/reference/cvars/cg_autoscreenshot-34930f2/) | cvar | cgame | Automatically take a screenshot at end of round. |
| [`cg_centerHeight`](/TaystJK/reference/cvars/cg_centerheight-bbab188/) | cvar | cgame | Controls `cg_centerHeight` in the cgame module. |
| [`cg_centerSize`](/TaystJK/reference/cvars/cg_centersize-615dcaa/) | cvar | cgame | Controls `cg_centerSize` in the cgame module. |
| [`cg_chatBoxCutOffLength`](/TaystJK/reference/cvars/cg_chatboxcutofflength-abf6a17/) | cvar | cgame | Width of a line in the chatbox before breaking to a new one |
| [`cg_chatBoxEmojis`](/TaystJK/reference/cvars/cg_chatboxemojis-7bdc808/) | cvar | cgame | Controls `cg_chatBoxEmojis` in the cgame module. |
| [`cg_chatBoxFontSize`](/TaystJK/reference/cvars/cg_chatboxfontsize-85a3a51/) | cvar | cgame | Scale of the chat box font |
| [`cg_chatBoxLines`](/TaystJK/reference/cvars/cg_chatboxlines-ef18116/) | cvar | cgame | This would be called chatBoxHeight if baseJKA didn't use that |
| [`cg_chatBoxShowCutoff`](/TaystJK/reference/cvars/cg_chatboxshowcutoff-3c9eab8/) | cvar | cgame | Controls `cg_chatBoxShowCutoff` in the cgame module. |
| [`cg_chatBoxShowHistory`](/TaystJK/reference/cvars/cg_chatboxshowhistory-e0f1ccf/) | cvar | cgame | Shows past messages when console is open |
| [`cg_chatBoxX`](/TaystJK/reference/cvars/cg_chatboxx-e3271fd/) | cvar | cgame | Controls `cg_chatBoxX` in the cgame module. |
| [`cg_chatSounds`](/TaystJK/reference/cvars/cg_chatsounds-fe6292d/) | cvar | cgame | Play sound when chat messages are received |
| [`cg_cleanChatbox`](/TaystJK/reference/cvars/cg_cleanchatbox-3609d1a/) | cvar | cgame | 1=Remove all colors from chat msgs, 2=Only remove color at begining of message |
| [`cg_crosshairColor`](/TaystJK/reference/cvars/cg_crosshaircolor-a61b771/) | cvar | cgame | Controls `cg_crosshairColor` in the cgame module. |
| [`cg_crosshairSaberStyleColor`](/TaystJK/reference/cvars/cg_crosshairsaberstylecolor-14bed3a/) | cvar | cgame | Controls `cg_crosshairSaberStyleColor` in the cgame module. |
| [`cg_crossHairScope`](/TaystJK/reference/cvars/cg_crosshairscope-93d2076/) | cvar | cgame | Minimalist crosshair disruptor scope replacement |
| [`cg_crosshairSizeScale`](/TaystJK/reference/cvars/cg_crosshairsizescale-8838e3c/) | cvar | cgame | Controls `cg_crosshairSizeScale` in the cgame module. |
| [`cg_debugGun`](/TaystJK/reference/cvars/cg_debuggun-6a4d591/) | cvar | cgame | Controls `cg_debugGun` in the cgame module. |
| [`cg_defaultFemaleModel`](/TaystJK/reference/cvars/cg_defaultfemalemodel-2d9b8bf/) | cvar | cgame | Controls `cg_defaultFemaleModel` in the cgame module. |
| [`cg_defaultModel`](/TaystJK/reference/cvars/cg_defaultmodel-16870a9/) | cvar | cgame | Controls `cg_defaultModel` in the cgame module. |
| [`cg_defaultModelRandom`](/TaystJK/reference/cvars/cg_defaultmodelrandom-139255e/) | cvar | cgame | Controls `cg_defaultModelRandom` in the cgame module. |
| [`cg_displayCameraPosition`](/TaystJK/reference/cvars/cg_displaycameraposition-7ad50eb/) | cvar | cgame | Controls `cg_displayCameraPosition` in the cgame module. |
| [`cg_displayNetSettings`](/TaystJK/reference/cvars/cg_displaynetsettings-a58025c/) | cvar | cgame | Controls `cg_displayNetSettings` in the cgame module. |
| [`cg_disruptorAltTime`](/TaystJK/reference/cvars/cg_disruptoralttime-265b925/) | cvar | cgame | Amount of time to display disruptor alt fire |
| [`cg_disruptorCoreColor`](/TaystJK/reference/cvars/cg_disruptorcorecolor-9319cd0/) | cvar | cgame | Changes disruptor line color (accepts hexcode eg. xffffff) |
| [`cg_disruptorMainTime`](/TaystJK/reference/cvars/cg_disruptormaintime-3ae961c/) | cvar | cgame | Amount of time to display disruptor primary fire |
| [`cg_disruptorNew`](/TaystJK/reference/cvars/cg_disruptornew-f6cffa9/) | cvar | cgame | Enable new disruptor effects |
| [`cg_disruptorSpiral`](/TaystJK/reference/cvars/cg_disruptorspiral-0625e4c/) | cvar | cgame | Enable disruptor spiral effect |
| [`cg_disruptorSpiralColor`](/TaystJK/reference/cvars/cg_disruptorspiralcolor-197aaca/) | cvar | cgame | Changes disruptor spiral color (accepts hexcode eg. xffffff) |
| [`cg_disruptorTeamColor`](/TaystJK/reference/cvars/cg_disruptorteamcolor-68d3b53/) | cvar | cgame | Changes disruptor effects colors according to team |
| [`cg_drainFX`](/TaystJK/reference/cvars/cg_drainfx-0b786b0/) | cvar | cgame | Controls `cg_drainFX` in the cgame module. |
| [`cg_drawHitBox`](/TaystJK/reference/cvars/cg_drawhitbox-0f70f0a/) | cvar | cgame | Controls `cg_drawHitBox` in the cgame module. |
| [`cg_drawInventory`](/TaystJK/reference/cvars/cg_drawinventory-d918048/) | cvar | cgame | Controls `cg_drawInventory` in the cgame module. |
| [`cg_drawPlayerNames`](/TaystJK/reference/cvars/cg_drawplayernames-688cd3a/) | cvar | cgame | Controls `cg_drawPlayerNames` in the cgame module. |
| [`cg_drawPlayerNamesScale`](/TaystJK/reference/cvars/cg_drawplayernamesscale-94d9ef0/) | cvar | cgame | Controls `cg_drawPlayerNamesScale` in the cgame module. |
| [`cg_drawPowerUpIcons`](/TaystJK/reference/cvars/cg_drawpowerupicons-309d5b9/) | cvar | cgame | Controls `cg_drawPowerUpIcons` in the cgame module. |
| [`cg_drawScore`](/TaystJK/reference/cvars/cg_drawscore-f2358ae/) | cvar | cgame | Score counter on HUD |
| [`cg_drawScoreX`](/TaystJK/reference/cvars/cg_drawscorex-3d12558/) | cvar | cgame | Horizontal offset for score counter on HUD |
| [`cg_drawScoreY`](/TaystJK/reference/cvars/cg_drawscorey-8ca83fd/) | cvar | cgame | Vertical offset for score counter on HUD |
| [`cg_drawScreenTints`](/TaystJK/reference/cvars/cg_drawscreentints-bddc984/) | cvar | cgame | Turn the tint from water on or off |
| [`cg_drawTeamOverlayWeapons`](/TaystJK/reference/cvars/cg_drawteamoverlayweapons-864b183/) | cvar | cgame | Draw each player's current weapon on the team overlay |
| [`cg_drawTeamOverlayX`](/TaystJK/reference/cvars/cg_drawteamoverlayx-0618c68/) | cvar | cgame | Horizontal location of the right edge of the team overlay |
| [`cg_drawTeamOverlayY`](/TaystJK/reference/cvars/cg_drawteamoverlayy-249a13a/) | cvar | cgame | Vertical location of the team overlay |
| [`cg_drawTimerCountdown`](/TaystJK/reference/cvars/cg_drawtimercountdown-26c13db/) | cvar | cgame | Controls `cg_drawTimerCountdown` in the cgame module. |
| [`cg_drawTimerMsec`](/TaystJK/reference/cvars/cg_drawtimermsec-156f1d2/) | cvar | cgame | Controls `cg_drawTimerMsec` in the cgame module. |
| [`cg_drawTrajectory`](/TaystJK/reference/cvars/cg_drawtrajectory-39b4cbe/) | cvar | cgame | Controls `cg_drawTrajectory` in the cgame module. |
| [`cg_drawTriggers`](/TaystJK/reference/cvars/cg_drawtriggers-ec57388/) | cvar | cgame | Controls `cg_drawTriggers` in the cgame module. |
| [`cg_drawUpperRight`](/TaystJK/reference/cvars/cg_drawupperright-5b41022/) | cvar | cgame | Controls `cg_drawUpperRight` in the cgame module. |
| [`cg_drawVote`](/TaystJK/reference/cvars/cg_drawvote-03fa352/) | cvar | cgame | Displays votecalls in the upper left |
| [`cg_duelMusic`](/TaystJK/reference/cvars/cg_duelmusic-aa17cd0/) | cvar | cgame | Enables special in-game music for private duels |
| [`cg_duelSounds`](/TaystJK/reference/cvars/cg_duelsounds-4be05fd/) | cvar | cgame | Enables/disables announcer/center print at the start of private duels |
| [`cg_engineModifications`](/TaystJK/reference/cvars/cg_enginemodifications-0e53ca8/) | cvar | cgame | Controls `cg_engineModifications` in the cgame module. |
| [`cg_fkDuration`](/TaystJK/reference/cvars/cg_fkduration-60df772/) | cvar | cgame | Controls `cg_fkDuration` in the cgame module. |
| [`cg_fkFirstJumpDuration`](/TaystJK/reference/cvars/cg_fkfirstjumpduration-6c4486b/) | cvar | cgame | Controls `cg_fkFirstJumpDuration` in the cgame module. |
| [`cg_fkSecondJumpDelay`](/TaystJK/reference/cvars/cg_fksecondjumpdelay-6217188/) | cvar | cgame | Controls `cg_fkSecondJumpDelay` in the cgame module. |
| [`cg_fleshSparks`](/TaystJK/reference/cvars/cg_fleshsparks-6cfe42f/) | cvar | cgame | Maximum number of sparks from a saber hit |
| [`cg_forceAllyModel`](/TaystJK/reference/cvars/cg_forceallymodel-2d546b7/) | cvar | cgame | Controls `cg_forceAllyModel` in the cgame module. |
| [`cg_forceCosmetics`](/TaystJK/reference/cvars/cg_forcecosmetics-598fb8d/) | cvar | cgame | Forces all players to have your cosmetics on non-japro servers |
| [`cg_forceEnemyModel`](/TaystJK/reference/cvars/cg_forceenemymodel-d577813/) | cvar | cgame | Controls `cg_forceEnemyModel` in the cgame module. |
| [`cg_forceOwnSaber`](/TaystJK/reference/cvars/cg_forceownsaber-6523482/) | cvar | cgame | Controls `cg_forceOwnSaber` in the cgame module. |
| [`cg_fovAspectAdjust`](/TaystJK/reference/cvars/cg_fovaspectadjust-a01b353/) | cvar | cgame | Fixed skyportal issue |
| [`cg_fovViewmodel`](/TaystJK/reference/cvars/cg_fovviewmodel-585844a/) | cvar | cgame | Controls `cg_fovViewmodel` in the cgame module. |
| [`cg_fovViewmodelAdjust`](/TaystJK/reference/cvars/cg_fovviewmodeladjust-4ab4013/) | cvar | cgame | Shifts viewmodels down above cg_fov 90 |
| [`cg_gunAlpha`](/TaystJK/reference/cvars/cg_gunalpha-82a9df0/) | cvar | cgame | Controls `cg_gunAlpha` in the cgame module. |
| [`cg_headTurn`](/TaystJK/reference/cvars/cg_headturn-2d5b44b/) | cvar | cgame | Controls `cg_headTurn` in the cgame module. |
| [`cg_hitsounds`](/TaystJK/reference/cvars/cg_hitsounds-5ef7d07/) | cvar | cgame | Play a sound when you hit someone |
| [`cg_hudColors`](/TaystJK/reference/cvars/cg_hudcolors-e3b9e30/) | cvar | cgame | Changes the colors of the HUD based on saber style and force |
| [`cg_instantDuck`](/TaystJK/reference/cvars/cg_instantduck-ee7bc95/) | cvar | cgame | Controls `cg_instantDuck` in the cgame module. |
| [`cg_jumpGoal`](/TaystJK/reference/cvars/cg_jumpgoal-829a115/) | cvar | cgame | Set a first jump speed goal speed, if first jump speed is above your goal speed, the pre-speed text will be green. Requires /speedometer 1 enabled |
| [`cg_jumpHeight`](/TaystJK/reference/cvars/cg_jumpheight-d0ee024/) | cvar | cgame | Specify jumpheight before jump is automaticaly canceled. |
| [`cg_killfeed`](/TaystJK/reference/cvars/cg_killfeed-020f6f8/) | cvar | cgame | Draw a killfeed on the HUD |
| [`cg_killfeedAlignment`](/TaystJK/reference/cvars/cg_killfeedalignment-10e367a/) | cvar | cgame | Align the killfeed |
| [`cg_killfeedColors`](/TaystJK/reference/cvars/cg_killfeedcolors-31f4cc3/) | cvar | cgame | Color the killfeed icons |
| [`cg_killfeedIconSize`](/TaystJK/reference/cvars/cg_killfeediconsize-508e23d/) | cvar | cgame | Resize the killfeed |
| [`cg_killfeedTextSize`](/TaystJK/reference/cvars/cg_killfeedtextsize-1f948df/) | cvar | cgame | Resize the killfeed |
| [`cg_killfeedX`](/TaystJK/reference/cvars/cg_killfeedx-32eb04e/) | cvar | cgame | Offset the killfeed's horizontal position from its current position |
| [`cg_killfeedY`](/TaystJK/reference/cvars/cg_killfeedy-e14002d/) | cvar | cgame | Offset the killfeed's vertical position from its current position |
| [`cg_killMessage`](/TaystJK/reference/cvars/cg_killmessage-b665d89/) | cvar | cgame | Print a kill message on the screen when you kill someone |
| [`cg_lagometerX`](/TaystJK/reference/cvars/cg_lagometerx-cb16443/) | cvar | cgame | Controls `cg_lagometerX` in the cgame module. |
| [`cg_lagometerY`](/TaystJK/reference/cvars/cg_lagometery-e1cecb6/) | cvar | cgame | Controls `cg_lagometerY` in the cgame module. |
| [`cg_leadIndicator`](/TaystJK/reference/cvars/cg_leadindicator-aebddda/) | cvar | cgame | Controls `cg_leadIndicator` in the cgame module. |
| [`cg_legstuck`](/TaystJK/reference/cvars/cg_legstuck-a73ad3c/) | cvar | cgame | Controls `cg_legstuck` in the cgame module. |
| [`cg_logChat`](/TaystJK/reference/cvars/cg_logchat-b9bd889/) | cvar | cgame | Controls `cg_logChat` in the cgame module. |
| [`cg_logStrafeTrail`](/TaystJK/reference/cvars/cg_logstrafetrail-6216305/) | cvar | cgame | Controls `cg_logStrafeTrail` in the cgame module. |
| [`cg_minimapScale`](/TaystJK/reference/cvars/cg_minimapscale-1662c4f/) | cvar | cgame | Controls `cg_minimapScale` in the cgame module. |
| [`cg_movementKeys`](/TaystJK/reference/cvars/cg_movementkeys-03e13b5/) | cvar | cgame | Select the on-screen movement-key overlay style. |
| [`cg_movementKeysSize`](/TaystJK/reference/cvars/cg_movementkeyssize-6686f74/) | cvar | cgame | Scale of the movement keys |
| [`cg_movementKeysX`](/TaystJK/reference/cvars/cg_movementkeysx-a7d563b/) | cvar | cgame | Horizontal location of the movement keys |
| [`cg_movementKeysY`](/TaystJK/reference/cvars/cg_movementkeysy-30e6290/) | cvar | cgame | Vertical location of the movement keys |
| [`cg_newFont`](/TaystJK/reference/cvars/cg_newfont-3b907a0/) | cvar | cgame | Uses a different font for the chat |
| [`cg_noFX`](/TaystJK/reference/cvars/cg_nofx-361d77e/) | cvar | cgame | Determines if effects and map models are shown |
| [`cg_noRGBSabers`](/TaystJK/reference/cvars/cg_norgbsabers-19cc29e/) | cvar | cgame | Controls `cg_noRGBSabers` in the cgame module. |
| [`cg_noTeleFX`](/TaystJK/reference/cvars/cg_notelefx-0a4c1c4/) | cvar | cgame | Disables the teleportation effect |
| [`cg_pitchHelper`](/TaystJK/reference/cvars/cg_pitchhelper-e3dadd7/) | cvar | cgame | Draw pitch angle independently from /cg_showpos |
| [`cg_pitchHelperOffset`](/TaystJK/reference/cvars/cg_pitchhelperoffset-9b851a1/) | cvar | cgame | Offset the green range up or down (eg. range 30, offset 10 = +25 to -5) |
| [`cg_pitchHelperRange`](/TaystJK/reference/cvars/cg_pitchhelperrange-249a33b/) | cvar | cgame | The range of numbers to display as green (eg. range 30, offset 0 = +15 to -15) |
| [`cg_pitchHelperX`](/TaystJK/reference/cvars/cg_pitchhelperx-a9d35e3/) | cvar | cgame | Move the pitch helper's horizontal location |
| [`cg_pitchHelperY`](/TaystJK/reference/cvars/cg_pitchhelpery-285d43a/) | cvar | cgame | Move the pitch helper's vertical location |
| [`cg_pitchHud`](/TaystJK/reference/cvars/cg_pitchhud-718ad06/) | cvar | cgame | Enable/Disable the pitch HUD |
| [`cg_pitchHudAngle`](/TaystJK/reference/cvars/cg_pitchhudangle-1647f9d/) | cvar | cgame | Controls `cg_pitchHudAngle` in the cgame module. |
| [`cg_pitchHudRgba`](/TaystJK/reference/cvars/cg_pitchhudrgba-b90e7dc/) | cvar | cgame | Color of the pitch HUD |
| [`cg_pitchHudThickness`](/TaystJK/reference/cvars/cg_pitchhudthickness-ea58d0e/) | cvar | cgame | Thickness |
| [`cg_pitchHudWidth`](/TaystJK/reference/cvars/cg_pitchhudwidth-770bd5f/) | cvar | cgame | Horizontal width |
| [`cg_pitchHudX`](/TaystJK/reference/cvars/cg_pitchhudx-d1f128d/) | cvar | cgame | Horizontal position |
| [`cg_predictKnockback`](/TaystJK/reference/cvars/cg_predictknockback-103096d/) | cvar | cgame | Predict self-inflicted rocket-jump knockback clientside (racemode only). Use with cg_simulatedProjectiles 1. |
| [`cg_raceSounds`](/TaystJK/reference/cvars/cg_racesounds-cfc3317/) | cvar | cgame | Bitvalue, but so far we just have RS_TIMER_START set up |
| [`cg_raceStart`](/TaystJK/reference/cvars/cg_racestart-e3c5285/) | cvar | cgame | Enable race timer start speed separately from the race timer |
| [`cg_raceStartX`](/TaystJK/reference/cvars/cg_racestartx-c82e957/) | cvar | cgame | Horizontal location of the race start timer onscreen |
| [`cg_raceStartY`](/TaystJK/reference/cvars/cg_racestarty-210e8af/) | cvar | cgame | Vertical location of the race start timer onscreen |
| [`cg_raceTimer`](/TaystJK/reference/cvars/cg_racetimer-7361db5/) | cvar | cgame | Show the race timer onscreen |
| [`cg_raceTimerSize`](/TaystJK/reference/cvars/cg_racetimersize-7c766ca/) | cvar | cgame | Scale of the race timer |
| [`cg_raceTimerX`](/TaystJK/reference/cvars/cg_racetimerx-6e9d43d/) | cvar | cgame | Horizontal location of the race timer onscreen |
| [`cg_raceTimerY`](/TaystJK/reference/cvars/cg_racetimery-7b7373c/) | cvar | cgame | Vertical location of the race timer onscreen |
| [`cg_remaps`](/TaystJK/reference/cvars/cg_remaps-267c59f/) | cvar | cgame | Show or hide serverside remaps |
| [`cg_rollSounds`](/TaystJK/reference/cvars/cg_rollsounds-370ef41/) | cvar | cgame | Play sound when players roll |
| [`cg_saberClash`](/TaystJK/reference/cvars/cg_saberclash-98e5abd/) | cvar | cgame | Controls `cg_saberClash` in the cgame module. |
| [`cg_saberIgnitionFlare`](/TaystJK/reference/cvars/cg_saberignitionflare-bf8696a/) | cvar | cgame | Controls `cg_saberIgnitionFlare` in the cgame module. |
| [`cg_saberTeamColors`](/TaystJK/reference/cvars/cg_saberteamcolors-c7e0745/) | cvar | cgame | Controls `cg_saberTeamColors` in the cgame module. |
| [`cg_scopeSensitivity`](/TaystJK/reference/cvars/cg_scopesensitivity-e27d084/) | cvar | cgame | Controls `cg_scopeSensitivity` in the cgame module. |
| [`cg_scoreboardTime`](/TaystJK/reference/cvars/cg_scoreboardtime-c017d2f/) | cvar | cgame | Displays the local time on the scoreboard |
| [`cg_scoreDeaths`](/TaystJK/reference/cvars/cg_scoredeaths-67a5132/) | cvar | cgame | Display score AND deaths on the scoreboard |
| [`cg_screenShake`](/TaystJK/reference/cvars/cg_screenshake-f987066/) | cvar | cgame | Shake screen when hit or while charging weapons |
| [`cg_shaderSaberCore`](/TaystJK/reference/cvars/cg_shadersabercore-88486dc/) | cvar | cgame | Controls `cg_shaderSaberCore` in the cgame module. |
| [`cg_shaderSaberGlow`](/TaystJK/reference/cvars/cg_shadersaberglow-585b811/) | cvar | cgame | Controls `cg_shaderSaberGlow` in the cgame module. |
| [`cg_showpos`](/TaystJK/reference/cvars/cg_showpos-785191d/) | cvar | cgame | Controls `cg_showpos` in the cgame module. |
| [`cg_simulatedHitscan`](/TaystJK/reference/cvars/cg_simulatedhitscan-8c02e38/) | cvar | cgame | Toggle predicted hitscan weapon effects. |
| [`cg_simulatedProjectiles`](/TaystJK/reference/cvars/cg_simulatedprojectiles-e12d5f1/) | cvar | cgame | Wether to use simulated projectiles so bullets appear instantly. Values > 1 don't draw the projectile right away. |
| [`cg_smallScoreboard`](/TaystJK/reference/cvars/cg_smallscoreboard-1c675db/) | cvar | cgame | Always use the small version of the scoreboard |
| [`cg_snapHud`](/TaystJK/reference/cvars/cg_snaphud-4dbb69f/) | cvar | cgame | Enable/Disable the snap HUD |
| [`cg_snapHudAuto`](/TaystJK/reference/cvars/cg_snaphudauto-f4cf9ff/) | cvar | cgame | Automatically detect best settings |
| [`cg_snapHudDef`](/TaystJK/reference/cvars/cg_snaphuddef-c5f71a3/) | cvar | cgame | Controls `cg_snapHudDef` in the cgame module. |
| [`cg_snapHudFps`](/TaystJK/reference/cvars/cg_snaphudfps-0576276/) | cvar | cgame | FPS for calculations (Leave default for auto) |
| [`cg_snapHudHeight`](/TaystJK/reference/cvars/cg_snaphudheight-d87b8e6/) | cvar | cgame | Vertical height |
| [`cg_snapHudRgba1`](/TaystJK/reference/cvars/cg_snaphudrgba1-b9ec8aa/) | cvar | cgame | Color for single key press |
| [`cg_snapHudRgba2`](/TaystJK/reference/cvars/cg_snaphudrgba2-e5d53f0/) | cvar | cgame | Color for two keys pressed |
| [`cg_snapHudSpeed`](/TaystJK/reference/cvars/cg_snaphudspeed-1a22dbb/) | cvar | cgame | Basespeed for calculations (Leave default for auto) |
| [`cg_snapHudY`](/TaystJK/reference/cvars/cg_snaphudy-cc550c0/) | cvar | cgame | Vertical position |
| [`cg_specCameraMode`](/TaystJK/reference/cvars/cg_speccameramode-95baeef/) | cvar | cgame | Controls `cg_specCameraMode` in the cgame module. |
| [`cg_specHud`](/TaystJK/reference/cvars/cg_spechud-70b1e1d/) | cvar | cgame | Controls `cg_specHud` in the cgame module. |
| [`cg_spectatorCameraDamp`](/TaystJK/reference/cvars/cg_spectatorcameradamp-1136737/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_speedometer`](/TaystJK/reference/cvars/cg_speedometer-9810620/) | cvar | cgame | Configure with the /speedometer command |
| [`cg_speedometerJumps`](/TaystJK/reference/cvars/cg_speedometerjumps-2a998a1/) | cvar | cgame | The amount of jumps to store in the jumps array, enable with the /speedometer command |
| [`cg_speedometerJumpsX`](/TaystJK/reference/cvars/cg_speedometerjumpsx-29e18d5/) | cvar | cgame | Horizontal location of the jumps array |
| [`cg_speedometerJumpsY`](/TaystJK/reference/cvars/cg_speedometerjumpsy-8a40b94/) | cvar | cgame | Vertical location of the jumps array |
| [`cg_speedometerSize`](/TaystJK/reference/cvars/cg_speedometersize-6fd381a/) | cvar | cgame | Scale of the speedometer |
| [`cg_speedometerX`](/TaystJK/reference/cvars/cg_speedometerx-58598b2/) | cvar | cgame | Horizontal location of the speedometer |
| [`cg_speedometerY`](/TaystJK/reference/cvars/cg_speedometery-7d4b635/) | cvar | cgame | Vertical location of the speedometer |
| [`cg_startGoal`](/TaystJK/reference/cvars/cg_startgoal-086db11/) | cvar | cgame | Start speed goal, if your start speed is above your goal speed, the text will be green, requires /cg_raceStart 1 |
| [`cg_strafeHelper`](/TaystJK/reference/cvars/cg_strafehelper-4850985/) | cvar | cgame | Configure with the /strafehelper command |
| [`cg_strafeHelper_FPS`](/TaystJK/reference/cvars/cg_strafehelper_fps-c64555f/) | cvar | cgame | Fats _ syntax to follow smod ;s |
| [`cg_strafeHelperActiveColor`](/TaystJK/reference/cvars/cg_strafehelperactivecolor-0c4cad4/) | cvar | cgame | Controls `cg_strafeHelperActiveColor` in the cgame module. |
| [`cg_strafeHelperCutoff`](/TaystJK/reference/cvars/cg_strafehelpercutoff-2cd5794/) | cvar | cgame | Controls `cg_strafeHelperCutoff` in the cgame module. |
| [`cg_strafeHelperInactiveAlpha`](/TaystJK/reference/cvars/cg_strafehelperinactivealpha-c641c50/) | cvar | cgame | Controls `cg_strafeHelperInactiveAlpha` in the cgame module. |
| [`cg_strafeHelperLineWidth`](/TaystJK/reference/cvars/cg_strafehelperlinewidth-790968e/) | cvar | cgame | Controls `cg_strafeHelperLineWidth` in the cgame module. |
| [`cg_strafeHelperOffset`](/TaystJK/reference/cvars/cg_strafehelperoffset-018a25b/) | cvar | cgame | Controls `cg_strafeHelperOffset` in the cgame module. |
| [`cg_strafeHelperPrecision`](/TaystJK/reference/cvars/cg_strafehelperprecision-9de34f5/) | cvar | cgame | Controls `cg_strafeHelperPrecision` in the cgame module. |
| [`cg_strafeTrailFPS`](/TaystJK/reference/cvars/cg_strafetrailfps-0969824/) | cvar | cgame | SV_FPS the strafetrail was recorded at. |
| [`cg_strafeTrailGhost`](/TaystJK/reference/cvars/cg_strafetrailghost-3933f97/) | cvar | cgame | Controls `cg_strafeTrailGhost` in the cgame module. |
| [`cg_strafeTrailLife`](/TaystJK/reference/cvars/cg_strafetraillife-79e03b0/) | cvar | cgame | Controls `cg_strafeTrailLife` in the cgame module. |
| [`cg_strafeTrailPlayers`](/TaystJK/reference/cvars/cg_strafetrailplayers-e720b69/) | cvar | cgame | Controls `cg_strafeTrailPlayers` in the cgame module. |
| [`cg_strafeTrailRacersOnly`](/TaystJK/reference/cvars/cg_strafetrailracersonly-2296b15/) | cvar | cgame | Controls `cg_strafeTrailRacersOnly` in the cgame module. |
| [`cg_strafeTrailRadius`](/TaystJK/reference/cvars/cg_strafetrailradius-d65c515/) | cvar | cgame | Controls `cg_strafeTrailRadius` in the cgame module. |
| [`cg_stylePlayer`](/TaystJK/reference/cvars/cg_styleplayer-c35894d/) | cvar | cgame | Configure with the /stylePlayer command |
| [`cg_thirdPersonCrosshairCenter`](/TaystJK/reference/cvars/cg_thirdpersoncrosshaircenter-a54cbd8/) | cvar | cgame | 1 is old third person static crosshair behavior |
| [`cg_thirdPersonFlagAlpha`](/TaystJK/reference/cvars/cg_thirdpersonflagalpha-ce71971/) | cvar | cgame | Custom transparency of the CTF flag |
| [`cg_tintHud`](/TaystJK/reference/cvars/cg_tinthud-0c71140/) | cvar | cgame | Changes the color of the HUD based on team color |
| [`cg_vehicleRange`](/TaystJK/reference/cvars/cg_vehiclerange-987b56f/) | cvar | cgame | Offset vehicle camera ranges (useful for ultrawide monitors) |
| [`cg_weaponCycleAmmo`](/TaystJK/reference/cvars/cg_weaponcycleammo-3286c8e/) | cvar | cgame | Controls `cg_weaponCycleAmmo` in the cgame module. |
| [`cg_zoomSensitivity`](/TaystJK/reference/cvars/cg_zoomsensitivity-f19085b/) | cvar | cgame | Controls `cg_zoomSensitivity` in the cgame module. |
| [`cjp_client`](/TaystJK/reference/cvars/cjp_client-30f1526/) | cvar | cgame | Controls `cjp_client` in the cgame module. |
| [`cl_afkPrefix`](/TaystJK/reference/cvars/cl_afkprefix-de26080/) | cvar | engine-client | Prefix to add to player name when AFK |
| [`cl_afkTime`](/TaystJK/reference/cvars/cl_afktime-a051a42/) | cvar | engine-client | Minutes to autorename to afk, 0 to disable |
| [`cl_afkTimeUnfocused`](/TaystJK/reference/cvars/cl_afktimeunfocused-3a38f9b/) | cvar | engine-client | Minutes to autorename to afk while unfocused/minimized |
| [`cl_allowEnterCompletion`](/TaystJK/reference/cvars/cl_allowentercompletion-7ec0985/) | cvar | engine-client | Enables autocomplete when pressing enter |
| [`cl_avi2GBLimit`](/TaystJK/reference/cvars/cl_avi2gblimit-4a65d18/) | cvar | engine-client | Controls `cl_avi2GBLimit` in the engine-client module. |
| [`cl_aviFrameRate`](/TaystJK/reference/cvars/cl_aviframerate-a13588d/) | cvar | engine-client | Controls `cl_aviFrameRate` in the engine-client module. |
| [`cl_aviMotionJpeg`](/TaystJK/reference/cvars/cl_avimotionjpeg-91b798a/) | cvar | engine-client | Controls `cl_aviMotionJpeg` in the engine-client module. |
| [`cl_chatStylePrefix`](/TaystJK/reference/cvars/cl_chatstyleprefix-1875f3b/) | cvar | engine-client | String inserted before sent chat messages |
| [`cl_chatStyleSuffix`](/TaystJK/reference/cvars/cl_chatstylesuffix-25c90ab/) | cvar | engine-client | String appended to send chat messages |
| [`cl_coloredTextShadows`](/TaystJK/reference/cvars/cl_coloredtextshadows-e3b625f/) | cvar | renderer | Toggle JK2 1.02-style colored text shadows |
| [`cl_colorString`](/TaystJK/reference/cvars/cl_colorstring-dfaadba/) | cvar | engine-client | Bit value of selected colors in colorString, configure chat colors with /colorstring |
| [`cl_colorStringCount`](/TaystJK/reference/cvars/cl_colorstringcount-5e55bbd/) | cvar | engine-client | Controls `cl_colorStringCount` in the engine-client module. |
| [`cl_colorStringRandom`](/TaystJK/reference/cvars/cl_colorstringrandom-d3b1d9a/) | cvar | engine-client | Randomness of the colors changing, higher numbers are less random |
| [`cl_commandsize`](/TaystJK/reference/cvars/cl_commandsize-8b702b0/) | cvar | cgame | Controls `cl_commandsize` in the cgame module. |
| [`cl_consoleKeys`](/TaystJK/reference/cvars/cl_consolekeys-0430407/) | cvar | engine-client | Which keys are used to toggle the console |
| [`cl_consoleUseScanCode`](/TaystJK/reference/cvars/cl_consoleusescancode-557fe4e/) | cvar | engine-client | Use native console key detection |
| [`cl_currentServerIP`](/TaystJK/reference/cvars/cl_currentserverip-18e40fb/) | cvar | engine-client | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_discordRichPresence`](/TaystJK/reference/cvars/cl_discordrichpresence-c4b29a5/) | cvar | engine-client | Allow/disallow sharing current game information on Discord profile status |
| [`cl_discordRichPresenceSharePassword`](/TaystJK/reference/cvars/cl_discordrichpresencesharepassword-79479cd/) | cvar | engine-client | If set, sends password to Discord friends who request to join your game |
| [`cl_downloadOverlay`](/TaystJK/reference/cvars/cl_downloadoverlay-ee4a68a/) | cvar | engine-client | Draw download info overlay |
| [`cl_downloadPrompt`](/TaystJK/reference/cvars/cl_downloadprompt-2444b92/) | cvar | engine-client | Confirm pk3 downloads from the server |
| [`cl_downloadProtocol`](/TaystJK/reference/cvars/cl_downloadprotocol-a36f359/) | cvar | engine-client | Report whether the active download uses HTTP or UDP. |
| [`cl_enableGuid`](/TaystJK/reference/cvars/cl_enableguid-d5d42ac/) | cvar | engine-client | Enable GUID userinfo identifier |
| [`cl_exitCommand`](/TaystJK/reference/cvars/cl_exitcommand-0f11b0a/) | cvar | engine-shared | Enables the /exit command |
| [`cl_filterGames`](/TaystJK/reference/cvars/cl_filtergames-7e85224/) | cvar | engine-client | List of fs_game to filter (space separated) |
| [`cl_guidServerUniq`](/TaystJK/reference/cvars/cl_guidserveruniq-7e6d8fe/) | cvar | engine-client | Use a unique guid value per server |
| [`cl_lanForcePackets`](/TaystJK/reference/cvars/cl_lanforcepackets-cafc4eb/) | cvar | engine-client | Controls `cl_lanForcePackets` in the engine-client module. |
| [`cl_logChat`](/TaystJK/reference/cvars/cl_logchat-5d53487/) | cvar | engine-client | Toggle engine chat logs |
| [`cl_motdServer1`](/TaystJK/reference/cvars/cl_motdserver1-a571b4a/) | cvar | engine-client | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_motdServer2`](/TaystJK/reference/cvars/cl_motdserver2-76b0c14/) | cvar | engine-client | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_mouseAccelOffset`](/TaystJK/reference/cvars/cl_mouseacceloffset-2ec97b6/) | cvar | engine-client | Mouse acceleration offset for style 1 |
| [`cl_mouseAccelStyle`](/TaystJK/reference/cvars/cl_mouseaccelstyle-fd1405e/) | cvar | engine-client | Mouse accelration style (0:legacy, 1:QuakeLive) |
| [`cl_ratioFix`](/TaystJK/reference/cvars/cl_ratiofix-67440df/) | cvar | engine-client | Widescreen aspect ratio correction |
| [`cl_reconnectArgs`](/TaystJK/reference/cvars/cl_reconnectargs-fbdecc0/) | cvar | engine-client | Arguments provided when last connecting to a server |
| [`cl_renderer`](/TaystJK/reference/cvars/cl_renderer-dc9f64f/) | cvar | engine-client | Which renderer library to use |
| [`cl_timenudgeDuration`](/TaystJK/reference/cvars/cl_timenudgeduration-676fa10/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cm_extraVerbose`](/TaystJK/reference/cvars/cm_extraverbose-f870864/) | cvar | engine-shared | Controls `cm_extraVerbose` in the engine-shared module. |
| [`com_affinity`](/TaystJK/reference/cvars/com_affinity-f32bd34/) | cvar | engine-shared | Controls `com_affinity` in the engine-shared module. |
| [`com_ansiColor`](/TaystJK/reference/cvars/com_ansicolor-94ebdea/) | cvar | engine-shared | Controls `com_ansiColor` in the engine-shared module. |
| [`com_bootlogo`](/TaystJK/reference/cvars/com_bootlogo-4f85af0/) | cvar | engine-shared | Show intro movies |
| [`com_busyWait`](/TaystJK/reference/cvars/com_busywait-3e64dd5/) | cvar | engine-shared | Controls `com_busyWait` in the engine-shared module. |
| [`com_homepath`](/TaystJK/reference/cvars/com_homepath-79625df/) | cvar | engine-shared | Controls `com_homepath` in the engine-shared module. |
| [`com_legacyprotocol`](/TaystJK/reference/cvars/com_legacyprotocol-f7ec076/) | cvar | engine-client | 1.00 protocol |
| [`com_maxfpsMinimized`](/TaystJK/reference/cvars/com_maxfpsminimized-ee39c66/) | cvar | engine-shared | Controls `com_maxfpsMinimized` in the engine-shared module. |
| [`com_maxfpsUnfocused`](/TaystJK/reference/cvars/com_maxfpsunfocused-888b9d8/) | cvar | engine-shared | Controls `com_maxfpsUnfocused` in the engine-shared module. |
| [`com_minimized`](/TaystJK/reference/cvars/com_minimized-fa62f52/) | cvar | engine-shared | Controls `com_minimized` in the engine-shared module. |
| [`com_priority`](/TaystJK/reference/cvars/com_priority-cac1576/) | cvar | engine-shared | Duno, -1 = do nothing, 1 = low priority, 2 = normal priority, 3 = high priority? i guess?? |
| [`com_protocol`](/TaystJK/reference/cvars/com_protocol-2cc2e0a/) | cvar | engine-client | 1.01 protocol |
| [`com_renderfps`](/TaystJK/reference/cvars/com_renderfps-485cbcb/) | cvar | engine-shared | Controls `com_renderfps` in the engine-shared module. |
| [`com_steamIntegration`](/TaystJK/reference/cvars/com_steamintegration-01ca9bb/) | cvar | engine-shared | Enables automatic Steam API integration (requires a steam_api64.dll to be in GameData) |
| [`com_timestamps`](/TaystJK/reference/cvars/com_timestamps-e16da1a/) | cvar | engine-shared | Show timestamps in terminal and qconsole.log |
| [`com_unfocused`](/TaystJK/reference/cvars/com_unfocused-804c4c7/) | cvar | engine-shared | Controls `com_unfocused` in the engine-shared module. |
| [`com_waitingForKey`](/TaystJK/reference/cvars/com_waitingforkey-4980251/) | cvar | engine-shared | Controls `com_waitingForKey` in the engine-shared module. |
| [`con_autoclear`](/TaystJK/reference/cvars/con_autoclear-ff60e4c/) | cvar | engine-client | Automatically clear console input on close |
| [`con_datetime`](/TaystJK/reference/cvars/con_datetime-fb79998/) | cvar | engine-client | Display human readable date/time in console |
| [`con_notifyconnect`](/TaystJK/reference/cvars/con_notifyconnect-0a48d2d/) | cvar | engine-client | Notifies you when someone connects to the server |
| [`con_notifylines`](/TaystJK/reference/cvars/con_notifylines-6373d07/) | cvar | engine-client | Max number of console lines to print in top left |
| [`con_notifyvote`](/TaystJK/reference/cvars/con_notifyvote-05d6ee1/) | cvar | engine-client | Notifies you when someone calls a vote |
| [`con_notifywords`](/TaystJK/reference/cvars/con_notifywords-97dfc24/) | cvar | engine-client | Notifies you when defined words are mentioned |
| [`con_opacity`](/TaystJK/reference/cvars/con_opacity-d0e065e/) | cvar | engine-client | Opacity of console background |
| [`con_ratioFix`](/TaystJK/reference/cvars/con_ratiofix-64c8547/) | cvar | engine-client | Correct console background height, should probably disable for custom console backgrounds. |
| [`con_timestamps`](/TaystJK/reference/cvars/con_timestamps-2b4f0eb/) | cvar | engine-client | Display timestamps infront of console lines |
| [`cp_clanPwd`](/TaystJK/reference/cvars/cp_clanpwd-ca86ca9/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cp_cosmetics`](/TaystJK/reference/cvars/cp_cosmetics-488f751/) | cvar | cgame | Controls `cp_cosmetics` in the cgame module. |
| [`cp_pluginDisable`](/TaystJK/reference/cvars/cp_plugindisable-715762d/) | cvar | cgame | 'enable' holstered saber (512) and ledge grab (1536) by default, to avoid missing JA+ animations |
| [`cp_sbRGB1`](/TaystJK/reference/cvars/cp_sbrgb1-0369930/) | cvar | cgame | Controls `cp_sbRGB1` in the cgame module. |
| [`cp_sbRGB2`](/TaystJK/reference/cvars/cp_sbrgb2-81b016f/) | cvar | cgame | Controls `cp_sbRGB2` in the cgame module. |
| [`disco`](/TaystJK/reference/cvars/disco-9a1c2a6/) | cvar | cgame | Controls `disco` in the cgame module. |
| [`fs_apppath`](/TaystJK/reference/cvars/fs_apppath-eaa658c/) | cvar | engine-shared | (Read Only) Location of OSX .app bundle |
| [`fx_physics`](/TaystJK/reference/cvars/fx_physics-6ce403e/) | cvar | engine-client | Controls physics applied to FX system particles - 0: Disable all FX physics - 1: use non-expensive physics only - 2: Use flags in the fx file (Default behavior) - 3: Force expensive physics on all particles |
| [`g_allowFlagThrow`](/TaystJK/reference/cvars/g_allowflagthrow-a034db8/) | cvar | game | Allow use of /throwflag command. |
| [`g_allowGrapple`](/TaystJK/reference/cvars/g_allowgrapple-4e7510c/) | cvar | game | 1=Tarzan style. 2=JA+ Style. |
| [`g_allowGunDuel`](/TaystJK/reference/cvars/g_allowgunduel-ac581ff/) | cvar | game | Controls `g_allowGunDuel` in the game module. |
| [`g_allowNoFollow`](/TaystJK/reference/cvars/g_allownofollow-6efa2b1/) | cvar | game | Allow players to hide themselves and not be spectated/seen in racemode. |
| [`g_allowRaceTele`](/TaystJK/reference/cvars/g_allowracetele-7aca7fe/) | cvar | game | 1=Allow amtele in racemode. 2=Also allow noclip. |
| [`g_allowRegistration`](/TaystJK/reference/cvars/g_allowregistration-45f9f37/) | cvar | game | Controls `g_allowRegistration` in the game module. |
| [`g_allowSaberSwitch`](/TaystJK/reference/cvars/g_allowsaberswitch-474c34a/) | cvar | game | Controls `g_allowSaberSwitch` in the game module. |
| [`g_allowSamePlayerNames`](/TaystJK/reference/cvars/g_allowsameplayernames-adac81f/) | cvar | game | Controls `g_allowSamePlayerNames` in the game module. |
| [`g_allowSpotting`](/TaystJK/reference/cvars/g_allowspotting-88ae036/) | cvar | game | Controls `g_allowSpotting` in the game module. |
| [`g_allowTargetLaser`](/TaystJK/reference/cvars/g_allowtargetlaser-61aa826/) | cvar | game | Target laser used with +button14 |
| [`g_allowTeamSuicide`](/TaystJK/reference/cvars/g_allowteamsuicide-5e88a75/) | cvar | game | Controls `g_allowTeamSuicide` in the game module. |
| [`g_allowUseInDuel`](/TaystJK/reference/cvars/g_allowuseinduel-c53aead/) | cvar | game | Controls `g_allowUseInDuel` in the game module. |
| [`g_allowVGS`](/TaystJK/reference/cvars/g_allowvgs-cbfffd9/) | cvar | game | Controls `g_allowVGS` in the game module. |
| [`g_antiFakePlayer`](/TaystJK/reference/cvars/g_antifakeplayer-eae051b/) | cvar | game | Controls `g_antiFakePlayer` in the game module. |
| [`g_antiWallhack`](/TaystJK/reference/cvars/g_antiwallhack-2d80c78/) | cvar | game | Experimental anti wallhack code. Use the client plugin so it can tell the server where your camera position is, and if you use 3rd person. |
| [`g_autoQuit`](/TaystJK/reference/cvars/g_autoquit-bc06a6f/) | cvar | game | Controls `g_autoQuit` in the game module. |
| [`g_backslashDamageScale`](/TaystJK/reference/cvars/g_backslashdamagescale-4775681/) | cvar | game | Controls `g_backslashDamageScale` in the game module. |
| [`g_blockDuelHealthSpec`](/TaystJK/reference/cvars/g_blockduelhealthspec-40519eb/) | cvar | game | Don't show duelers health to people in spectate. |
| [`g_blueDamageScale`](/TaystJK/reference/cvars/g_bluedamagescale-409fea4/) | cvar | game | Controls `g_blueDamageScale` in the game module. |
| [`g_centerMOTD`](/TaystJK/reference/cvars/g_centermotd-2a208ad/) | cvar | game | Controls `g_centerMOTD` in the game module. |
| [`g_centerMOTDTime`](/TaystJK/reference/cvars/g_centermotdtime-c0742ef/) | cvar | game | Controls `g_centerMOTDTime` in the game module. |
| [`g_charRestrictRGB`](/TaystJK/reference/cvars/g_charrestrictrgb-9c843ad/) | cvar | game | Controls `g_charRestrictRGB` in the game module. |
| [`g_consoleMOTD`](/TaystJK/reference/cvars/g_consolemotd-62e668c/) | cvar | game | Controls `g_consoleMOTD` in the game module. |
| [`g_corpseRemovalTime`](/TaystJK/reference/cvars/g_corpseremovaltime-1c8df23/) | cvar | game | Controls `g_corpseRemovalTime` in the game module. |
| [`g_damageNumbers`](/TaystJK/reference/cvars/g_damagenumbers-134f14c/) | cvar | game | 1-7. Controls different types of damagenumber printouts. |
| [`g_duelDistanceLimit`](/TaystJK/reference/cvars/g_dueldistancelimit-9422409/) | cvar | game | Controls `g_duelDistanceLimit` in the game module. |
| [`g_duelLog`](/TaystJK/reference/cvars/g_duellog-0286077/) | cvar | game | Log to duels.log. |
| [`g_duelRespawn`](/TaystJK/reference/cvars/g_duelrespawn-0acb1c8/) | cvar | game | Automatically respawn players to where they died after losing a duel. |
| [`g_duelStartArmor`](/TaystJK/reference/cvars/g_duelstartarmor-56fbd3c/) | cvar | game | Controls `g_duelStartArmor` in the game module. |
| [`g_duelStartHealth`](/TaystJK/reference/cvars/g_duelstarthealth-8a98d72/) | cvar | game | Controls `g_duelStartHealth` in the game module. |
| [`g_eloKValue1`](/TaystJK/reference/cvars/g_elokvalue1-29f4799/) | cvar | game | Controls `g_eloKValue1` in the game module. |
| [`g_eloKValue2`](/TaystJK/reference/cvars/g_elokvalue2-2c17376/) | cvar | game | Controls `g_eloKValue2` in the game module. |
| [`g_eloKValue3`](/TaystJK/reference/cvars/g_elokvalue3-e6ddcc0/) | cvar | game | Controls `g_eloKValue3` in the game module. |
| [`g_eloMinimumDuels`](/TaystJK/reference/cvars/g_elominimumduels-b90832e/) | cvar | game | Controls `g_eloMinimumDuels` in the game module. |
| [`g_eloNewUserCutoff`](/TaystJK/reference/cvars/g_elonewusercutoff-7843ba4/) | cvar | game | Controls `g_eloNewUserCutoff` in the game module. |
| [`g_eloProvisionalChangeBig`](/TaystJK/reference/cvars/g_eloprovisionalchangebig-990945a/) | cvar | game | Controls `g_eloProvisionalChangeBig` in the game module. |
| [`g_eloProvisionalChangeSmall`](/TaystJK/reference/cvars/g_eloprovisionalchangesmall-a70e34f/) | cvar | game | Controls `g_eloProvisionalChangeSmall` in the game module. |
| [`g_eloProvisionalCutoff`](/TaystJK/reference/cvars/g_eloprovisionalcutoff-429129e/) | cvar | game | Controls `g_eloProvisionalCutoff` in the game module. |
| [`g_eloRanking`](/TaystJK/reference/cvars/g_eloranking-b050319/) | cvar | game | Enables the built in elo ranking for duels. |
| [`g_emotesDisable`](/TaystJK/reference/cvars/g_emotesdisable-8df1bb9/) | cvar | game | Configured with /toggleEmotes command |
| [`g_fakeClients`](/TaystJK/reference/cvars/g_fakeclients-381934a/) | cvar | game | Controls `g_fakeClients` in the game module. |
| [`g_fixCTFScores`](/TaystJK/reference/cvars/g_fixctfscores-f3e8d8d/) | cvar | game | Tweak CTF score amounts. |
| [`g_fixFlagHitbox`](/TaystJK/reference/cvars/g_fixflaghitbox-93e20c3/) | cvar | game | Controls `g_fixFlagHitbox` in the game module. |
| [`g_fixFlagSuicide`](/TaystJK/reference/cvars/g_fixflagsuicide-f382dc6/) | cvar | game | Don't auto return flag when flag carrier suicides. |
| [`g_fixGetups`](/TaystJK/reference/cvars/g_fixgetups-987e065/) | cvar | game | 1=Allow grip during knockdown recovery. 2=Allow grip/push/pull during knockdown recovery. |
| [`g_fixGroundStab`](/TaystJK/reference/cvars/g_fixgroundstab-414db0a/) | cvar | game | 1=Groundstabs damage players on ground. 2=Groundstabs damage players on ground but with reduced damage. |
| [`g_fixHighFPSAbuse`](/TaystJK/reference/cvars/g_fixhighfpsabuse-1f4cf8c/) | cvar | game | Make players who have more than 250fps behave at 250fps physics. |
| [`g_fixKillCredit`](/TaystJK/reference/cvars/g_fixkillcredit-250953f/) | cvar | game | 1=Award kill credit after target suicides/spectates. 2=Also for disconnects/reconnects. |
| [`g_fixLightning`](/TaystJK/reference/cvars/g_fixlightning-a145552/) | cvar | game | 1=Lightning gives forcepoints to target. 2=Same as 1 with reduced damage. 3=Same as 2 with no melee bonus. |
| [`g_fixPlayerCollision`](/TaystJK/reference/cvars/g_fixplayercollision-c0ccf93/) | cvar | game | Controls `g_fixPlayerCollision` in the game module. |
| [`g_fixRoll`](/TaystJK/reference/cvars/g_fixroll-09a4b25/) | cvar | game | 1=JA+ style base roll. //2=Chainable roll. //3=JK2 style roll. |
| [`g_fixSaberDisarmBonus`](/TaystJK/reference/cvars/g_fixsaberdisarmbonus-d84721a/) | cvar | game | Controls `g_fixSaberDisarmBonus` in the game module. |
| [`g_fixSaberInGrip`](/TaystJK/reference/cvars/g_fixsaberingrip-b95f6ac/) | cvar | game | 1=Grip does not turn off lightsaber. 2=Same as 1 and also target can toggle lightsaber in grip. 3=Same as 2 and also target can switch saberstyle in grip. |
| [`g_fixSaberMoveData`](/TaystJK/reference/cvars/g_fixsabermovedata-4619480/) | cvar | game | Controls `g_fixSaberMoveData` in the game module. |
| [`g_fixSlidePhysics`](/TaystJK/reference/cvars/g_fixslidephysics-b4eea18/) | cvar | game | 1=Fixed slide physics for NPCS. 2=Fixed slide physics for NPCs and players. |
| [`g_fixTimerOOB`](/TaystJK/reference/cvars/g_fixtimeroob-b9f687d/) | cvar | game | Controls `g_fixTimerOOB` in the game module. |
| [`g_flagDrag`](/TaystJK/reference/cvars/g_flagdrag-88dcb4b/) | cvar | game | Add air friction to flag carrier. |
| [`g_flipKick`](/TaystJK/reference/cvars/g_flipkick-64576b3/) | cvar | game | 1=JA+ style. 2=Floodprotected to one kick every 50ms. 3=JK2 style. |
| [`g_flipKickDamageScale`](/TaystJK/reference/cvars/g_flipkickdamagescale-7c4913a/) | cvar | game | Controls `g_flipKickDamageScale` in the game module. |
| [`g_forceClientUpdateRate`](/TaystJK/reference/cvars/g_forceclientupdaterate-1c32854/) | cvar | game | Controls `g_forceClientUpdateRate` in the game module. |
| [`g_forceDrainDamage`](/TaystJK/reference/cvars/g_forcedraindamage-9a8a567/) | cvar | game | Controls `g_forceDrainDamage` in the game module. |
| [`g_forceDrainRestartDelay`](/TaystJK/reference/cvars/g_forcedrainrestartdelay-6b31ed4/) | cvar | game | Controls `g_forceDrainRestartDelay` in the game module. |
| [`g_forceDrainSelfRegenDelay`](/TaystJK/reference/cvars/g_forcedrainselfregendelay-9759e5d/) | cvar | game | Controls `g_forceDrainSelfRegenDelay` in the game module. |
| [`g_forceDrainTargetRegenDelay`](/TaystJK/reference/cvars/g_forcedraintargetregendelay-716a0ec/) | cvar | game | Controls `g_forceDrainTargetRegenDelay` in the game module. |
| [`g_forceDuelForceRegenTime`](/TaystJK/reference/cvars/g_forceduelforceregentime-6121a0c/) | cvar | game | Controls `g_forceDuelForceRegenTime` in the game module. |
| [`g_forceDuelSPDamage`](/TaystJK/reference/cvars/g_forceduelspdamage-6899daf/) | cvar | game | Toggle use of SP style damage in force duels. |
| [`g_forceLogin`](/TaystJK/reference/cvars/g_forcelogin-19fc6bd/) | cvar | game | 1=Force players to login in order to be ingame. 2=also block them from chatting until logging in. 3=also block them from renaming until logging in. |
| [`g_forcePowerDisableFFA`](/TaystJK/reference/cvars/g_forcepowerdisableffa-6942638/) | cvar | game | Controls `g_forcePowerDisableFFA` in the game module. |
| [`g_fullAdminLevel`](/TaystJK/reference/cvars/g_fulladminlevel-baac21c/) | cvar | game | Controls `g_fullAdminLevel` in the game module. |
| [`g_fullAdminMsg`](/TaystJK/reference/cvars/g_fulladminmsg-a1df874/) | cvar | game | Controls `g_fullAdminMsg` in the game module. |
| [`g_fullAdminPass`](/TaystJK/reference/cvars/g_fulladminpass-11858c2/) | cvar | game | Controls `g_fullAdminPass` in the game module. |
| [`g_fullInheritance`](/TaystJK/reference/cvars/g_fullinheritance-fb4c838/) | cvar | game | Scale of all player momentum gained by projectiles. |
| [`g_glitchKickDamage`](/TaystJK/reference/cvars/g_glitchkickdamage-381e14c/) | cvar | game | Controls `g_glitchKickDamage` in the game module. |
| [`g_godChat`](/TaystJK/reference/cvars/g_godchat-b1ca3c4/) | cvar | game | Controls `g_godChat` in the game module. |
| [`g_hookFloodProtect`](/TaystJK/reference/cvars/g_hookfloodprotect-882bcc8/) | cvar | game | Milliseconds between hook shots |
| [`g_hookInheritance`](/TaystJK/reference/cvars/g_hookinheritance-d65c1d8/) | cvar | game | Controls `g_hookInheritance` in the game module. |
| [`g_hookSpeed`](/TaystJK/reference/cvars/g_hookspeed-4804994/) | cvar | game | Speed that grapple hook travels at |
| [`g_hookStrength`](/TaystJK/reference/cvars/g_hookstrength-fc0d002/) | cvar | game | Speed that grapple pulls you at |
| [`g_hookStrength1`](/TaystJK/reference/cvars/g_hookstrength1-e5b30e7/) | cvar | game | Controls `g_hookStrength1` in the game module. |
| [`g_hookStrength2`](/TaystJK/reference/cvars/g_hookstrength2-5d40a55/) | cvar | game | Controls `g_hookStrength2` in the game module. |
| [`g_juniorAdminLevel`](/TaystJK/reference/cvars/g_junioradminlevel-0881d19/) | cvar | game | Controls `g_juniorAdminLevel` in the game module. |
| [`g_juniorAdminMsg`](/TaystJK/reference/cvars/g_junioradminmsg-60177a9/) | cvar | game | Controls `g_juniorAdminMsg` in the game module. |
| [`g_juniorAdminPass`](/TaystJK/reference/cvars/g_junioradminpass-f2dc6ae/) | cvar | game | Controls `g_juniorAdminPass` in the game module. |
| [`g_KOTH`](/TaystJK/reference/cvars/g_koth-67b50a0/) | cvar | game | Controls `g_KOTH` in the game module. |
| [`g_lagIcon`](/TaystJK/reference/cvars/g_lagicon-b8483ff/) | cvar | game | Controls `g_lagIcon` in the game module. |
| [`g_LegDangle`](/TaystJK/reference/cvars/g_legdangle-499ee3b/) | cvar | game | Toggle the leg dangle animation which is not predicted and results in jerkyness on ledges with high ping. |
| [`g_maxConnPerIP`](/TaystJK/reference/cvars/g_maxconnperip-714b0e2/) | cvar | game | Controls `g_maxConnPerIP` in the game module. |
| [`g_maxFallDmg`](/TaystJK/reference/cvars/g_maxfalldmg-e8af044/) | cvar | game | Controls `g_maxFallDmg` in the game module. |
| [`g_maxSaberDefense`](/TaystJK/reference/cvars/g_maxsaberdefense-6bba186/) | cvar | game | -1 disables, 0/1/2/3 enables and clamps level |
| [`g_mercyRule`](/TaystJK/reference/cvars/g_mercyrule-186f0be/) | cvar | game | If the difference is greater than X percent of the frag limit... then end match. |
| [`g_movementStyle`](/TaystJK/reference/cvars/g_movementstyle-cf714d4/) | cvar | game | Force movement style for players. 0=SIEGE 1=JKA 2=QW 3=CPM 4=Q3 5=PJK 6=WSW |
| [`g_newBotAI`](/TaystJK/reference/cvars/g_newbotai-156e15f/) | cvar | game | Controls `g_newBotAI` in the game module. |
| [`g_newBotAITarget`](/TaystJK/reference/cvars/g_newbotaitarget-9625e4f/) | cvar | game | -2=Target closest excluding otherbots. -1=target closest. 0-31=target clientnum. |
| [`g_nonRandomKnockdown`](/TaystJK/reference/cvars/g_nonrandomknockdown-6cb5a5c/) | cvar | game | 1=Nonrandom knockdowns based on forcepoints. 2=Pseudorandom with less variance. 3=Nonrandom based on viewangle of target. 4=Random based on viewangle of target. |
| [`g_onlyBhop`](/TaystJK/reference/cvars/g_onlybhop-07d5d70/) | cvar | game | 1=Disable forcejumps for all players. 2=Let players choose if they want to disable forcejumps. |
| [`g_pauseTime`](/TaystJK/reference/cvars/g_pausetime-f946ba0/) | cvar | game | Controls `g_pauseTime` in the game module. |
| [`g_playerLog`](/TaystJK/reference/cvars/g_playerlog-3ba9184/) | cvar | game | Used by /amlookup |
| [`g_projectileInheritance`](/TaystJK/reference/cvars/g_projectileinheritance-87e22cb/) | cvar | game | Scale of forward player momentum gained by projectiles. |
| [`g_projectileVelocityScale`](/TaystJK/reference/cvars/g_projectilevelocityscale-9182276/) | cvar | game | Controls `g_projectileVelocityScale` in the game module. |
| [`g_raceLog`](/TaystJK/reference/cvars/g_racelog-8a3ceb7/) | cvar | game | Log to races.log (incase database gets messed up). |
| [`g_raceMode`](/TaystJK/reference/cvars/g_racemode-04a9af7/) | cvar | game | 0=Noracemode, 1=forcedracemode, 2=player can toggle race mode with /racecommand. |
| [`g_randFix`](/TaystJK/reference/cvars/g_randfix-ff8f4d4/) | cvar | game | Controls `g_randFix` in the game module. |
| [`g_redDamageScale`](/TaystJK/reference/cvars/g_reddamagescale-0d0cc7a/) | cvar | game | Controls `g_redDamageScale` in the game module. |
| [`g_redDFADamageScale`](/TaystJK/reference/cvars/g_reddfadamagescale-1266724/) | cvar | game | Controls `g_redDFADamageScale` in the game module. |
| [`g_removeSpectatorPortals`](/TaystJK/reference/cvars/g_removespectatorportals-070ecec/) | cvar | game | Network all entity data to spectators, useful if you have a recorder in spectate so you can record all POV's. |
| [`g_saberDisable`](/TaystJK/reference/cvars/g_saberdisable-8b0544d/) | cvar | game | Configured with /saberDisable command. |
| [`g_saberDmgDelay_Hit`](/TaystJK/reference/cvars/g_saberdmgdelay_hit-504f5f4/) | cvar | game | Controls `g_saberDmgDelay_Hit` in the game module. |
| [`g_saberDuelForceRegenTime`](/TaystJK/reference/cvars/g_saberduelforceregentime-9b15b10/) | cvar | game | Controls `g_saberDuelForceRegenTime` in the game module. |
| [`g_saberDuelSPDamage`](/TaystJK/reference/cvars/g_saberduelspdamage-3438471/) | cvar | game | Toggle use of SP style damage in saber duels. |
| [`g_saberTouchDmg`](/TaystJK/reference/cvars/g_sabertouchdmg-2fe50c1/) | cvar | game | Configure saber touch damage for MP dmgs. Can be >1 for more touch damage. |
| [`g_scoreNPCs`](/TaystJK/reference/cvars/g_scorenpcs-6ccb95d/) | cvar | game | Controls `g_scoreNPCs` in the game module. |
| [`g_screenShake`](/TaystJK/reference/cvars/g_screenshake-590615c/) | cvar | game | Should be g_forceScreenShake |
| [`g_securityLog`](/TaystJK/reference/cvars/g_securitylog-ed66af1/) | cvar | game | Controls `g_securityLog` in the game module. |
| [`g_selfDamageScale`](/TaystJK/reference/cvars/g_selfdamagescale-3309fb9/) | cvar | game | Controls `g_selfDamageScale` in the game module. |
| [`g_showHealth`](/TaystJK/reference/cvars/g_showhealth-be5cfaa/) | cvar | game | Show healthbars above players heads when aimed at. Requires map restart. |
| [`g_showJumpSpot`](/TaystJK/reference/cvars/g_showjumpspot-316cca0/) | cvar | game | Marks where player touches ground as they land. Useful with the /nudge command on entities. |
| [`g_slideOnPlayer`](/TaystJK/reference/cvars/g_slideonplayer-57bcd53/) | cvar | game | Controls `g_slideOnPlayer` in the game module. |
| [`g_startingItems`](/TaystJK/reference/cvars/g_startingitems-8ece828/) | cvar | game | Configured with /startingItems command. |
| [`g_startingWeapons`](/TaystJK/reference/cvars/g_startingweapons-ba463fc/) | cvar | game | Start with saber only default, fall back to melee if no saberattack |
| [`g_stopHealthESP`](/TaystJK/reference/cvars/g_stophealthesp-34d40e0/) | cvar | game | Don't send health info to other players (pain sounds can't be used to count health now). |
| [`g_teamAbsorbScale`](/TaystJK/reference/cvars/g_teamabsorbscale-67e8eb0/) | cvar | game | Scale forcepoints gained from teampush/teampull etc. |
| [`g_teamEnergizeScale`](/TaystJK/reference/cvars/g_teamenergizescale-fb606bd/) | cvar | game | Scale forcepoints given from team energize. |
| [`g_teamHealScale`](/TaystJK/reference/cvars/g_teamhealscale-e1e033e/) | cvar | game | Scale health given from team heal. |
| [`g_tweakForce`](/TaystJK/reference/cvars/g_tweakforce-d616b7a/) | cvar | game | Configured with /tweakForce command. |
| [`g_tweakJetpack`](/TaystJK/reference/cvars/g_tweakjetpack-7b1ba8a/) | cvar | game | Controls `g_tweakJetpack` in the game module. |
| [`g_tweakSaber`](/TaystJK/reference/cvars/g_tweaksaber-7ff08dd/) | cvar | game | Configured with /tweakSaber command. |
| [`g_tweakVote`](/TaystJK/reference/cvars/g_tweakvote-97a7f7d/) | cvar | game | Latch cuz of calculateRanks? not sure man |
| [`g_tweakWeapons`](/TaystJK/reference/cvars/g_tweakweapons-7f0cd05/) | cvar | game | Configured with /tweakWeapons command |
| [`g_unlagged`](/TaystJK/reference/cvars/g_unlagged-06233db/) | cvar | game | Bitvalue. 1=Unlagged projectiles. 2=Unlagged hitscan. 4=Unlagged push/pull. |
| [`g_unpauseTime`](/TaystJK/reference/cvars/g_unpausetime-56cd138/) | cvar | game | Controls `g_unpauseTime` in the game module. |
| [`g_userinfoValidate`](/TaystJK/reference/cvars/g_userinfovalidate-8bbdc02/) | cvar | game | Controls `g_userinfoValidate` in the game module. |
| [`g_validateCosmetics`](/TaystJK/reference/cvars/g_validatecosmetics-59cafad/) | cvar | game | Controls `g_validateCosmetics` in the game module. |
| [`g_voteDelay`](/TaystJK/reference/cvars/g_votedelay-8d2f6a6/) | cvar | game | Controls `g_voteDelay` in the game module. |
| [`g_voteTimeout`](/TaystJK/reference/cvars/g_votetimeout-c55dafd/) | cvar | game | Time in seconds to lockout callvote after a failed vote |
| [`g_weaponDamageScale`](/TaystJK/reference/cvars/g_weapondamagescale-ba72334/) | cvar | game | Controls `g_weaponDamageScale` in the game module. |
| [`g_yellowDamageScale`](/TaystJK/reference/cvars/g_yellowdamagescale-ae81376/) | cvar | game | Controls `g_yellowDamageScale` in the game module. |
| [`in_availableJoysticks`](/TaystJK/reference/cvars/in_availablejoysticks-225bc96/) | cvar | engine-shared | Registered by the current source, but no user-facing behavior description has been verified. |
| [`in_joystickNo`](/TaystJK/reference/cvars/in_joystickno-d0cc911/) | cvar | engine-shared | Controls `in_joystickNo` in the engine-shared module. |
| [`in_joystickUseAnalog`](/TaystJK/reference/cvars/in_joystickuseanalog-501c877/) | cvar | engine-shared | Controls `in_joystickUseAnalog` in the engine-shared module. |
| [`in_keyboardDebug`](/TaystJK/reference/cvars/in_keyboarddebug-2793d91/) | cvar | engine-shared | Controls `in_keyboardDebug` in the engine-shared module. |
| [`in_mouserepeat`](/TaystJK/reference/cvars/in_mouserepeat-b6e4e4a/) | cvar | engine-shared | Controls `in_mouserepeat` in the engine-shared module. |
| [`in_nograb`](/TaystJK/reference/cvars/in_nograb-35cb150/) | cvar | engine-shared | Controls `in_nograb` in the engine-shared module. |
| [`ja_guid`](/TaystJK/reference/cvars/ja_guid-ea397d3/) | cvar | engine-client | Client GUID |
| [`jcinfo`](/TaystJK/reference/cvars/jcinfo-d257d4c/) | cvar | game | Not a cvar, dont change it |
| [`jcinfo2`](/TaystJK/reference/cvars/jcinfo2-4d14263/) | cvar | game | Not a cvar, dont change it |
| [`net_dropsim`](/TaystJK/reference/cvars/net_dropsim-45c82c0/) | cvar | engine-shared | Controls `net_dropsim` in the engine-shared module. |
| [`net_enabled`](/TaystJK/reference/cvars/net_enabled-800ae62/) | cvar | engine-shared | Controls `net_enabled` in the engine-shared module. |
| [`pmove_float`](/TaystJK/reference/cvars/pmove_float-d352a0d/) | cvar | cgame | Controls `pmove_float` in the cgame module. |
| [`protocolswitch`](/TaystJK/reference/cvars/protocolswitch-9a313ea/) | cvar | engine-client | Sets protocol based on server info response |
| [`r_allowScreenSaver`](/TaystJK/reference/cvars/r_allowscreensaver-9058284/) | cvar | engine-shared | Controls `r_allowScreenSaver` in the engine-shared module. |
| [`r_anaglyphMode`](/TaystJK/reference/cvars/r_anaglyphmode-756890b/) | cvar | renderer | Controls `r_anaglyphMode` in the renderer module. |
| [`r_arb_buffer_storage`](/TaystJK/reference/cvars/r_arb_buffer_storage-ac1e1c0/) | cvar | renderer | Disable/enable buffer storage GL extension |
| [`r_arb_half_float_pixel`](/TaystJK/reference/cvars/r_arb_half_float_pixel-6ad3bad/) | cvar | renderer | Disable/enable ARB_half_float GL extension |
| [`r_arb_seamless_cube_map`](/TaystJK/reference/cvars/r_arb_seamless_cube_map-c3396c7/) | cvar | renderer | Disable/enable seamless cube map filtering GL extension |
| [`r_arb_vertex_type_2_10_10_10_rev`](/TaystJK/reference/cvars/r_arb_vertex_type_2_10_10_10_rev-6fa9dbe/) | cvar | renderer | Disable/enable 1010102 UI data type |
| [`r_aspectCorrectFonts`](/TaystJK/reference/cvars/r_aspectcorrectfonts-be7251d/) | cvar | renderer | Controls `r_aspectCorrectFonts` in the renderer module. |
| [`r_autoExposure`](/TaystJK/reference/cvars/r_autoexposure-bbfaf39/) | cvar | renderer | Disable/enable auto exposure |
| [`r_availableModes`](/TaystJK/reference/cvars/r_availablemodes-bd904ae/) | cvar | engine-shared | Controls `r_availableModes` in the engine-shared module. |
| [`r_aviMotionJpegQuality`](/TaystJK/reference/cvars/r_avimotionjpegquality-108e51f/) | cvar | renderer | Controls `r_aviMotionJpegQuality` in the renderer module. |
| [`r_baseNormalX`](/TaystJK/reference/cvars/r_basenormalx-132f822/) | cvar | renderer | Controls `r_baseNormalX` in the renderer module. |
| [`r_baseNormalY`](/TaystJK/reference/cvars/r_basenormaly-f7f7006/) | cvar | renderer | Controls `r_baseNormalY` in the renderer module. |
| [`r_baseParallax`](/TaystJK/reference/cvars/r_baseparallax-6459a61/) | cvar | renderer | Controls `r_baseParallax` in the renderer module. |
| [`r_baseSpecular`](/TaystJK/reference/cvars/r_basespecular-24a3c96/) | cvar | renderer | Controls `r_baseSpecular` in the renderer module. |
| [`r_bloom`](/TaystJK/reference/cvars/r_bloom-656b99d/) | cvar | renderer | Enable bloom effect Requires \\r_fbo 1 |
| [`r_bloom_intensity`](/TaystJK/reference/cvars/r_bloom_intensity-78b7afa/) | cvar | renderer | Final bloom blend factor, default is 0.15 |
| [`r_bloom_threshold`](/TaystJK/reference/cvars/r_bloom_threshold-76fa432/) | cvar | renderer | Color level to extract to bloom texture, default is 0.05 |
| [`r_cameraExposure`](/TaystJK/reference/cvars/r_cameraexposure-7f22094/) | cvar | renderer | Controls `r_cameraExposure` in the renderer module. |
| [`r_centerWindow`](/TaystJK/reference/cvars/r_centerwindow-5f0b845/) | cvar | renderer | Controls `r_centerWindow` in the renderer module. |
| [`r_cubeMapping`](/TaystJK/reference/cvars/r_cubemapping-86bf3af/) | cvar | renderer | Disable/enable cubemapping |
| [`r_cubeMappingBounces`](/TaystJK/reference/cvars/r_cubemappingbounces-e20074f/) | cvar | renderer | Renders cubemaps multiple times to get reflections in reflections |
| [`r_debugContext`](/TaystJK/reference/cvars/r_debugcontext-c9977dd/) | cvar | renderer | Controls `r_debugContext` in the renderer module. |
| [`r_debugWeather`](/TaystJK/reference/cvars/r_debugweather-5e519c7/) | cvar | renderer | Controls `r_debugWeather` in the renderer module. |
| [`r_defaultImage`](/TaystJK/reference/cvars/r_defaultimage-48ebde4/) | cvar | renderer | Controls `r_defaultImage` in the renderer module. |
| [`r_deluxeMapping`](/TaystJK/reference/cvars/r_deluxemapping-a9c1e61/) | cvar | renderer | Disable/enable reading deluxemaps when compiled with q3map2 |
| [`r_deluxeSpecular`](/TaystJK/reference/cvars/r_deluxespecular-b2f4cf3/) | cvar | renderer | Disable/enable/scale the specular response from deluxemaps |
| [`r_depthPrepass`](/TaystJK/reference/cvars/r_depthprepass-3fbd4eb/) | cvar | renderer | Controls `r_depthPrepass` in the renderer module. |
| [`r_distanceCull`](/TaystJK/reference/cvars/r_distancecull-9ac0a11/) | cvar | renderer | Controls `r_distanceCull` in the renderer module. |
| [`r_dither`](/TaystJK/reference/cvars/r_dither-aea5dc5/) | cvar | renderer | Set dithering mode: 0 - disabled 1 - ordered Requires \\r_fbo 1 |
| [`r_dlightIntensity`](/TaystJK/reference/cvars/r_dlightintensity-d6b49d6/) | cvar | renderer | Controls `r_dlightIntensity` in the renderer module. |
| [`r_dlightMode`](/TaystJK/reference/cvars/r_dlightmode-f87fa68/) | cvar | renderer | Controls `r_dlightMode` in the renderer module. |
| [`r_dlightSaturation`](/TaystJK/reference/cvars/r_dlightsaturation-5f6800c/) | cvar | renderer | Controls `r_dlightSaturation` in the renderer module. |
| [`r_dlightScale`](/TaystJK/reference/cvars/r_dlightscale-cc85dd5/) | cvar | renderer | Controls `r_dlightScale` in the renderer module. |
| [`r_drawSunRays`](/TaystJK/reference/cvars/r_drawsunrays-f84fc82/) | cvar | renderer | Controls `r_drawSunRays` in the renderer module. |
| [`r_dynamicGlowBloom`](/TaystJK/reference/cvars/r_dynamicglowbloom-d4ab76d/) | cvar | renderer | Set rend2 dynamic-glow bloom strength from 0 through 2. |
| [`r_DynamicGlowScale`](/TaystJK/reference/cvars/r_dynamicglowscale-62e93d2/) | cvar | renderer | Controls `r_DynamicGlowScale` in the renderer module. |
| [`r_environmentMapping`](/TaystJK/reference/cvars/r_environmentmapping-4bbfdcf/) | cvar | renderer | Controls `r_environmentMapping` in the renderer module. |
| [`r_ext_alpha_to_coverage`](/TaystJK/reference/cvars/r_ext_alpha_to_coverage-5cfb4fd/) | cvar | renderer | Controls `r_ext_alpha_to_coverage` in the renderer module. |
| [`r_ext_draw_range_elements`](/TaystJK/reference/cvars/r_ext_draw_range_elements-17a8b5e/) | cvar | renderer | Unused |
| [`r_ext_max_anisotropy`](/TaystJK/reference/cvars/r_ext_max_anisotropy-ae414a3/) | cvar | renderer | Controls `r_ext_max_anisotropy` in the renderer module. |
| [`r_ext_multi_draw_arrays`](/TaystJK/reference/cvars/r_ext_multi_draw_arrays-47cef48/) | cvar | renderer | Unused |
| [`r_ext_multisample`](/TaystJK/reference/cvars/r_ext_multisample-9b2ea2a/) | cvar | renderer | Disable/enable framebuffer MSAA |
| [`r_ext_multisample_default_fb`](/TaystJK/reference/cvars/r_ext_multisample_default_fb-d2e37d5/) | cvar | engine-shared | Controls `r_ext_multisample_default_fb` in the engine-shared module. |
| [`r_ext_supersample`](/TaystJK/reference/cvars/r_ext_supersample-75d1107/) | cvar | renderer | Controls `r_ext_supersample` in the renderer module. |
| [`r_ext_texture_float`](/TaystJK/reference/cvars/r_ext_texture_float-f4a8764/) | cvar | renderer | Disable/enable floating-point textures |
| [`r_externalGLSL`](/TaystJK/reference/cvars/r_externalglsl-5987fc7/) | cvar | renderer | Controls `r_externalGLSL` in the renderer module. |
| [`r_fbo`](/TaystJK/reference/cvars/r_fbo-022d66e/) | cvar | renderer | Controls `r_fbo` in the renderer module. |
| [`r_floatLightmap`](/TaystJK/reference/cvars/r_floatlightmap-fe575c7/) | cvar | renderer | Disable/enable HDR lightmap support |
| [`r_forceAutoExposure`](/TaystJK/reference/cvars/r_forceautoexposure-d663377/) | cvar | renderer | Controls `r_forceAutoExposure` in the renderer module. |
| [`r_forceAutoExposureMax`](/TaystJK/reference/cvars/r_forceautoexposuremax-8cdd87f/) | cvar | renderer | Controls `r_forceAutoExposureMax` in the renderer module. |
| [`r_forceAutoExposureMin`](/TaystJK/reference/cvars/r_forceautoexposuremin-662d327/) | cvar | renderer | Controls `r_forceAutoExposureMin` in the renderer module. |
| [`r_forceParallaxBias`](/TaystJK/reference/cvars/r_forceparallaxbias-f673013/) | cvar | renderer | Controls `r_forceParallaxBias` in the renderer module. |
| [`r_forceSun`](/TaystJK/reference/cvars/r_forcesun-b623af1/) | cvar | renderer | Controls `r_forceSun` in the renderer module. |
| [`r_forceSunAmbientScale`](/TaystJK/reference/cvars/r_forcesunambientscale-2bb57dd/) | cvar | renderer | Controls `r_forceSunAmbientScale` in the renderer module. |
| [`r_forceSunLightScale`](/TaystJK/reference/cvars/r_forcesunlightscale-9f32ff8/) | cvar | renderer | Controls `r_forceSunLightScale` in the renderer module. |
| [`r_forceSunMapLightScale`](/TaystJK/reference/cvars/r_forcesunmaplightscale-c3ba4de/) | cvar | renderer | Controls `r_forceSunMapLightScale` in the renderer module. |
| [`r_forceToneMap`](/TaystJK/reference/cvars/r_forcetonemap-aaa4054/) | cvar | renderer | Controls `r_forceToneMap` in the renderer module. |
| [`r_forceToneMapAvg`](/TaystJK/reference/cvars/r_forcetonemapavg-df906d3/) | cvar | renderer | Controls `r_forceToneMapAvg` in the renderer module. |
| [`r_forceToneMapMax`](/TaystJK/reference/cvars/r_forcetonemapmax-996cd1f/) | cvar | renderer | Controls `r_forceToneMapMax` in the renderer module. |
| [`r_forceToneMapMin`](/TaystJK/reference/cvars/r_forcetonemapmin-b011396/) | cvar | renderer | Controls `r_forceToneMapMin` in the renderer module. |
| [`r_gammaShaders`](/TaystJK/reference/cvars/r_gammashaders-f8fed87/) | cvar | renderer | Set gamma using pixel shaders inside the game window only. |
| [`r_genNormalMaps`](/TaystJK/reference/cvars/r_gennormalmaps-3da13c7/) | cvar | renderer | Disable/enable generating normal maps from diffuse maps |
| [`r_greyscale`](/TaystJK/reference/cvars/r_greyscale-442b35b/) | cvar | renderer | Controls `r_greyscale` in the renderer module. |
| [`r_hdr`](/TaystJK/reference/cvars/r_hdr-806f3ee/) | cvar | renderer | Disable/enable rendering in HDR |
| [`r_ignoreDstAlpha`](/TaystJK/reference/cvars/r_ignoredstalpha-bad37b1/) | cvar | renderer | Controls `r_ignoreDstAlpha` in the renderer module. |
| [`r_imageUpsample`](/TaystJK/reference/cvars/r_imageupsample-45922fb/) | cvar | renderer | Controls `r_imageUpsample` in the renderer module. |
| [`r_imageUpsampleMaxSize`](/TaystJK/reference/cvars/r_imageupsamplemaxsize-a554326/) | cvar | renderer | Controls `r_imageUpsampleMaxSize` in the renderer module. |
| [`r_imageUpsampleType`](/TaystJK/reference/cvars/r_imageupsampletype-7553076/) | cvar | renderer | Controls `r_imageUpsampleType` in the renderer module. |
| [`r_mapGreyScale`](/TaystJK/reference/cvars/r_mapgreyscale-691d968/) | cvar | renderer | Controls `r_mapGreyScale` in the renderer module. |
| [`r_mapOverBrightBits`](/TaystJK/reference/cvars/r_mapoverbrightbits-f8fd76d/) | cvar | renderer | Controls `r_mapOverBrightBits` in the renderer module. |
| [`r_marksOnTriangleMeshes`](/TaystJK/reference/cvars/r_marksontrianglemeshes-3c9d053/) | cvar | renderer | Controls `r_marksOnTriangleMeshes` in the renderer module. |
| [`r_mergeLeafSurfaces`](/TaystJK/reference/cvars/r_mergeleafsurfaces-9631d20/) | cvar | renderer | Controls `r_mergeLeafSurfaces` in the renderer module. |
| [`r_mergeMultidraws`](/TaystJK/reference/cvars/r_mergemultidraws-471d2aa/) | cvar | renderer | Controls `r_mergeMultidraws` in the renderer module. |
| [`r_noborder`](/TaystJK/reference/cvars/r_noborder-09eac22/) | cvar | renderer | Controls `r_noborder` in the renderer module. |
| [`r_nomip`](/TaystJK/reference/cvars/r_nomip-784a698/) | cvar | renderer | Apply picmip only on worldspawn textures |
| [`r_normalMapping`](/TaystJK/reference/cvars/r_normalmapping-01198ee/) | cvar | renderer | Disable/enable normal mapping |
| [`r_parallaxMapping`](/TaystJK/reference/cvars/r_parallaxmapping-2354566/) | cvar | renderer | Disable/enable parallax mapping |
| [`r_presentBits`](/TaystJK/reference/cvars/r_presentbits-b73a39a/) | cvar | renderer | Select color bits used for presentation surfaces Requires \\r_fbo 1 |
| [`r_pshadowDist`](/TaystJK/reference/cvars/r_pshadowdist-c0c9961/) | cvar | renderer | Controls `r_pshadowDist` in the renderer module. |
| [`r_refractionChromaticAberration`](/TaystJK/reference/cvars/r_refractionchromaticaberration-ef62fde/) | cvar | renderer | Controls `r_refractionChromaticAberration` in the renderer module. |
| [`r_renderClipBrushes`](/TaystJK/reference/cvars/r_renderclipbrushes-2dbcbc3/) | cvar | engine-client | Render clip brushes |
| [`r_renderClipBrushesShader`](/TaystJK/reference/cvars/r_renderclipbrushesshader-28b5110/) | cvar | engine-client | Shader for clip brush rendering |
| [`r_renderHeight`](/TaystJK/reference/cvars/r_renderheight-77676c4/) | cvar | renderer | Controls `r_renderHeight` in the renderer module. |
| [`r_renderScale`](/TaystJK/reference/cvars/r_renderscale-eb5ad24/) | cvar | renderer | Scaling mode to be used with custom render resolution: 0 - disabled 1 - nearest filtering, stretch to full size 2 - nearest filtering, preserve aspect ratio (black bars on sides) 3 - linear filtering, stretch to full size 4 - linear filtering, preserve aspect ratio (black bars on sides) |
| [`r_renderSlickSurfaces`](/TaystJK/reference/cvars/r_renderslicksurfaces-8f52d68/) | cvar | engine-client | Render slick surfaces |
| [`r_renderSlickSurfacesShader`](/TaystJK/reference/cvars/r_renderslicksurfacesshader-f30c0b0/) | cvar | engine-client | Shader for slick surface rendering |
| [`r_renderTriggerBrushes`](/TaystJK/reference/cvars/r_rendertriggerbrushes-127cbfb/) | cvar | engine-client | Render trigger brushes |
| [`r_renderTriggerBrushesShader`](/TaystJK/reference/cvars/r_rendertriggerbrushesshader-98cc4d1/) | cvar | engine-client | The shader for trigger brushes |
| [`r_renderWidth`](/TaystJK/reference/cvars/r_renderwidth-4a7db81/) | cvar | renderer | Controls `r_renderWidth` in the renderer module. |
| [`r_roundImagesDown`](/TaystJK/reference/cvars/r_roundimagesdown-b41f9fd/) | cvar | renderer | Controls `r_roundImagesDown` in the renderer module. |
| [`r_saveFontData`](/TaystJK/reference/cvars/r_savefontdata-afb35a8/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_screenshotJpegQuality`](/TaystJK/reference/cvars/r_screenshotjpegquality-b8e56fb/) | cvar | renderer | Controls `r_screenshotJpegQuality` in the renderer module. |
| [`r_sdlDriver`](/TaystJK/reference/cvars/r_sdldriver-c79955e/) | cvar | engine-shared | Controls `r_sdlDriver` in the engine-shared module. |
| [`r_shadowCascadeZBias`](/TaystJK/reference/cvars/r_shadowcascadezbias-3a4ebe3/) | cvar | renderer | Controls `r_shadowCascadeZBias` in the renderer module. |
| [`r_shadowCascadeZFar`](/TaystJK/reference/cvars/r_shadowcascadezfar-70c7318/) | cvar | renderer | Controls `r_shadowCascadeZFar` in the renderer module. |
| [`r_shadowCascadeZNear`](/TaystJK/reference/cvars/r_shadowcascadeznear-3d8bcc7/) | cvar | renderer | Controls `r_shadowCascadeZNear` in the renderer module. |
| [`r_shadowFilter`](/TaystJK/reference/cvars/r_shadowfilter-bd830f4/) | cvar | renderer | Controls `r_shadowFilter` in the renderer module. |
| [`r_shadowMapSize`](/TaystJK/reference/cvars/r_shadowmapsize-f27fc20/) | cvar | renderer | Controls `r_shadowMapSize` in the renderer module. |
| [`r_shadowOffsetFactor`](/TaystJK/reference/cvars/r_shadowoffsetfactor-ed2b85f/) | cvar | renderer | Controls `r_shadowOffsetFactor` in the renderer module. |
| [`r_shadowOffsetUnits`](/TaystJK/reference/cvars/r_shadowoffsetunits-f883d48/) | cvar | renderer | Controls `r_shadowOffsetUnits` in the renderer module. |
| [`r_smaa`](/TaystJK/reference/cvars/r_smaa-0ca3ef0/) | cvar | renderer | Disable/enable SMAA |
| [`r_smaa_quality`](/TaystJK/reference/cvars/r_smaa_quality-af9853a/) | cvar | renderer | 0: LOW | 1: MEDIUM | 2: HIGH | 3: ULTRA |
| [`r_smartpicmip`](/TaystJK/reference/cvars/r_smartpicmip-88bba35/) | cvar | renderer | Applies r_picmip setting to map textures only. |
| [`r_specularMapping`](/TaystJK/reference/cvars/r_specularmapping-271a30a/) | cvar | renderer | Disable/enable specular mapping |
| [`r_ssao`](/TaystJK/reference/cvars/r_ssao-5b8c581/) | cvar | renderer | Controls `r_ssao` in the renderer module. |
| [`r_stereoSeparation`](/TaystJK/reference/cvars/r_stereoseparation-2be8daa/) | cvar | renderer | Controls `r_stereoSeparation` in the renderer module. |
| [`r_sunlightMode`](/TaystJK/reference/cvars/r_sunlightmode-1355059/) | cvar | renderer | Controls `r_sunlightMode` in the renderer module. |
| [`r_sunShadows`](/TaystJK/reference/cvars/r_sunshadows-ffe0a50/) | cvar | renderer | Controls `r_sunShadows` in the renderer module. |
| [`r_toneMap`](/TaystJK/reference/cvars/r_tonemap-27c4829/) | cvar | renderer | Disable/enable tonemapping |
| [`r_vbo`](/TaystJK/reference/cvars/r_vbo-8ee14c4/) | cvar | renderer | Cache static world surfaces |
| [`r_vbo_models`](/TaystJK/reference/cvars/r_vbo_models-8579ecd/) | cvar | renderer | Cache ghoul2 and md3 model surfaces |
| [`r_volumetricFog`](/TaystJK/reference/cvars/r_volumetricfog-bb8267b/) | cvar | renderer | Disable/enable lightgrid lighting on fog volumes |
| [`r_volumetricFogDefaultScale`](/TaystJK/reference/cvars/r_volumetricfogdefaultscale-2014496/) | cvar | renderer | Scales volumetric fog density unless scale has been explicitly defined |
| [`r_volumetricFogSamples`](/TaystJK/reference/cvars/r_volumetricfogsamples-c2f3eaa/) | cvar | renderer | How many ray samples to take |
| [`r_volumetricFogScale`](/TaystJK/reference/cvars/r_volumetricfogscale-e8d339c/) | cvar | renderer | Temporarily scales volumetric fog density |
| [`r_zproj`](/TaystJK/reference/cvars/r_zproj-3cfee13/) | cvar | renderer | Controls `r_zproj` in the renderer module. |
| [`restricts`](/TaystJK/reference/cvars/restricts-3fcd8e8/) | cvar | game | Controls `restricts` in the game module. |
| [`s_doppler`](/TaystJK/reference/cvars/s_doppler-affddec/) | cvar | engine-client | Controls `s_doppler` in the engine-client module. |
| [`s_sdlBits`](/TaystJK/reference/cvars/s_sdlbits-5a722c9/) | cvar | engine-shared | Controls `s_sdlBits` in the engine-shared module. |
| [`s_sdlChannels`](/TaystJK/reference/cvars/s_sdlchannels-db8bbb9/) | cvar | engine-shared | Controls `s_sdlChannels` in the engine-shared module. |
| [`s_sdlDevSamps`](/TaystJK/reference/cvars/s_sdldevsamps-433b99c/) | cvar | engine-shared | Controls `s_sdlDevSamps` in the engine-shared module. |
| [`s_sdlDriver`](/TaystJK/reference/cvars/s_sdldriver-b485ab9/) | cvar | engine-shared | Controls `s_sdlDriver` in the engine-shared module. |
| [`s_sdlMixSamps`](/TaystJK/reference/cvars/s_sdlmixsamps-d909425/) | cvar | engine-shared | Controls `s_sdlMixSamps` in the engine-shared module. |
| [`snd_mute_losefocus`](/TaystJK/reference/cvars/snd_mute_losefocus-56dc974/) | cvar | engine-client | Mute sound when game window is unfocused/minimized |
| [`sv_antiDST`](/TaystJK/reference/cvars/sv_antidst-09f18d9/) | cvar | engine-server | Attempts to detect and kick players injecting or using DST |
| [`sv_autoDemo`](/TaystJK/reference/cvars/sv_autodemo-9d9325d/) | cvar | engine-server | Automatically take server-side demos |
| [`sv_autoDemoBots`](/TaystJK/reference/cvars/sv_autodemobots-d25d8d2/) | cvar | engine-server | Record server-side demos for bots |
| [`sv_autoDemoMaxMaps`](/TaystJK/reference/cvars/sv_autodemomaxmaps-76728b7/) | cvar | engine-server | Controls `sv_autoDemoMaxMaps` in the engine-server module. |
| [`sv_autoRaceDemo`](/TaystJK/reference/cvars/sv_autoracedemo-b0d5159/) | cvar | game | Requires custom server executable with "svrecord" command. |
| [`sv_banFile`](/TaystJK/reference/cvars/sv_banfile-9b86cae/) | cvar | engine-server | File to use to store bans and exceptions |
| [`sv_clientRate`](/TaystJK/reference/cvars/sv_clientrate-25c8382/) | cvar | engine-server | Controls `sv_clientRate` in the engine-server module. |
| [`sv_demoPreRecordBots`](/TaystJK/reference/cvars/sv_demoprerecordbots-4548856/) | cvar | engine-server | Do demo pre-recording for bots as well |
| [`sv_filterCommands`](/TaystJK/reference/cvars/sv_filtercommands-f4a9480/) | cvar | engine-server | Controls `sv_filterCommands` in the engine-server module. |
| [`sv_hibernateTime`](/TaystJK/reference/cvars/sv_hibernatetime-940437b/) | cvar | engine-server | Time after which server will enter hibernation mode |
| [`sv_lanForceRate`](/TaystJK/reference/cvars/sv_lanforcerate-17e0934/) | cvar | engine-server | Controls `sv_lanForceRate` in the engine-server module. |
| [`sv_legacyFixes`](/TaystJK/reference/cvars/sv_legacyfixes-4f7fac8/) | cvar | engine-server | Controls `sv_legacyFixes` in the engine-server module. |
| [`sv_maxOOBRateIP`](/TaystJK/reference/cvars/sv_maxoobrateip-21dc800/) | cvar | engine-server | Maximum rate of handling incoming server commands per IP address |
| [`sv_maxTeamSize`](/TaystJK/reference/cvars/sv_maxteamsize-8db6a18/) | cvar | game | Controls `sv_maxTeamSize` in the game module. |
| [`sv_minRate`](/TaystJK/reference/cvars/sv_minrate-76512c7/) | cvar | engine-server | Min bandwidth rate allowed on server. Use 0 for unlimited. |
| [`sv_newfloodProtect`](/TaystJK/reference/cvars/sv_newfloodprotect-e4e33fe/) | cvar | engine-server | Use new method of delaying commands with flood protection |
| [`sv_pluginKey`](/TaystJK/reference/cvars/sv_pluginkey-9d80ed4/) | cvar | game | Controls `sv_pluginKey` in the game module. |
| [`sv_ratePolicy`](/TaystJK/reference/cvars/sv_ratepolicy-8e864f3/) | cvar | engine-server | Determines which policy of enforcement is used for client's \"rate\" cvar |
| [`sv_saberFPS`](/TaystJK/reference/cvars/sv_saberfps-7d809f3/) | cvar | game | Controls `sv_saberFPS` in the game module. |
| [`sv_snapShotDuelCull`](/TaystJK/reference/cvars/sv_snapshotduelcull-160745a/) | cvar | engine-server | Snapshot-based duel isolation |
| [`sv_snapsMax`](/TaystJK/reference/cvars/sv_snapsmax-b20336c/) | cvar | engine-server | Sv_snapsMin <=> sv_fps |
| [`sv_snapsMin`](/TaystJK/reference/cvars/sv_snapsmin-7fe81b5/) | cvar | engine-server | 1 <=> sv_snapsMax |
| [`sv_snapsPolicy`](/TaystJK/reference/cvars/sv_snapspolicy-385ae5d/) | cvar | engine-server | Determines which policy of enforcement is used for client's \"snaps\" cvar |
| [`ui_allowRegistration`](/TaystJK/reference/cvars/ui_allowregistration-713df1d/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_allowSaberSwitch`](/TaystJK/reference/cvars/ui_allowsaberswitch-6b40886/) | cvar | ui | Controls `ui_allowSaberSwitch` in the ui module. |
| [`ui_aspectratio`](/TaystJK/reference/cvars/ui_aspectratio-1403db8/) | cvar | ui | Controls `ui_aspectratio` in the ui module. |
| [`ui_browserFilterInvalidInfo`](/TaystJK/reference/cvars/ui_browserfilterinvalidinfo-7ee2364/) | cvar | ui | Controls `ui_browserFilterInvalidInfo` in the ui module. |
| [`ui_browserShowPasswordProtected`](/TaystJK/reference/cvars/ui_browsershowpasswordprotected-204880a/) | cvar | ui | Controls `ui_browserShowPasswordProtected` in the ui module. |
| [`ui_cl_maxpackets`](/TaystJK/reference/cvars/ui_cl_maxpackets-a1a306c/) | cvar | ui | Controls `ui_cl_maxpackets` in the ui module. |
| [`ui_disableWeaponSway`](/TaystJK/reference/cvars/ui_disableweaponsway-e995888/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_duel_fraglimit`](/TaystJK/reference/cvars/ui_duel_fraglimit-f40462c/) | cvar | ui | Controls `ui_duel_fraglimit` in the ui module. |
| [`ui_duel_timelimit`](/TaystJK/reference/cvars/ui_duel_timelimit-5f8e8ad/) | cvar | ui | Controls `ui_duel_timelimit` in the ui module. |
| [`ui_geometricdetail`](/TaystJK/reference/cvars/ui_geometricdetail-21121ee/) | cvar | ui | Controls `ui_geometricdetail` in the ui module. |
| [`ui_headCount`](/TaystJK/reference/cvars/ui_headcount-384f251/) | cvar | ui | Controls `ui_headCount` in the ui module. |
| [`ui_isJAPro`](/TaystJK/reference/cvars/ui_isjapro-9265944/) | cvar | ui | Controls `ui_isJAPro` in the ui module. |
| [`ui_lastServerRefresh_4`](/TaystJK/reference/cvars/ui_lastserverrefresh_4-d0bcc90/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_5`](/TaystJK/reference/cvars/ui_lastserverrefresh_5-2c6c262/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_6`](/TaystJK/reference/cvars/ui_lastserverrefresh_6-fba4ec6/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_password`](/TaystJK/reference/cvars/ui_password-5175d7a/) | cvar | ui | Controls `ui_password` in the ui module. |
| [`ui_r_customHeight`](/TaystJK/reference/cvars/ui_r_customheight-d1dc7bd/) | cvar | ui | Controls `ui_r_customHeight` in the ui module. |
| [`ui_r_customWidth`](/TaystJK/reference/cvars/ui_r_customwidth-5314b17/) | cvar | ui | Controls `ui_r_customWidth` in the ui module. |
| [`ui_r_fullBright`](/TaystJK/reference/cvars/ui_r_fullbright-8eeef50/) | cvar | ui | Controls `ui_r_fullBright` in the ui module. |
| [`ui_r_intensity`](/TaystJK/reference/cvars/ui_r_intensity-5f4c0bb/) | cvar | ui | Controls `ui_r_intensity` in the ui module. |
| [`ui_r_lightMap`](/TaystJK/reference/cvars/ui_r_lightmap-97c7b14/) | cvar | ui | Controls `ui_r_lightMap` in the ui module. |
| [`ui_r_picmip_custom`](/TaystJK/reference/cvars/ui_r_picmip_custom-fe590f2/) | cvar | ui | Controls `ui_r_picmip_custom` in the ui module. |
| [`ui_r_vertexLight`](/TaystJK/reference/cvars/ui_r_vertexlight-78fd857/) | cvar | ui | Controls `ui_r_vertexLight` in the ui module. |
| [`ui_raceMode`](/TaystJK/reference/cvars/ui_racemode-0db81ac/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_resolution`](/TaystJK/reference/cvars/ui_resolution-97111d4/) | cvar | ui | Controls `ui_resolution` in the ui module. |
| [`ui_RGBSkin`](/TaystJK/reference/cvars/ui_rgbskin-9bfb7fc/) | cvar | ui | Controls `ui_RGBSkin` in the ui module. |
| [`ui_sab1_b`](/TaystJK/reference/cvars/ui_sab1_b-3ba84b3/) | cvar | ui | Controls `ui_sab1_b` in the ui module. |
| [`ui_sab1_g`](/TaystJK/reference/cvars/ui_sab1_g-f26e57f/) | cvar | ui | Controls `ui_sab1_g` in the ui module. |
| [`ui_sab1_r`](/TaystJK/reference/cvars/ui_sab1_r-221f80f/) | cvar | ui | Controls `ui_sab1_r` in the ui module. |
| [`ui_sab2_b`](/TaystJK/reference/cvars/ui_sab2_b-96e5422/) | cvar | ui | Controls `ui_sab2_b` in the ui module. |
| [`ui_sab2_g`](/TaystJK/reference/cvars/ui_sab2_g-77c298e/) | cvar | ui | Controls `ui_sab2_g` in the ui module. |
| [`ui_sab2_r`](/TaystJK/reference/cvars/ui_sab2_r-9570b88/) | cvar | ui | Controls `ui_sab2_r` in the ui module. |
| [`ui_screenshotType`](/TaystJK/reference/cvars/ui_screenshottype-77cec01/) | cvar | ui | Controls `ui_screenshotType` in the ui module. |
| [`ui_serverFilterType`](/TaystJK/reference/cvars/ui_serverfiltertype-0e36b83/) | cvar | ui | Controls `ui_serverFilterType` in the ui module. |
| [`ui_sha_a`](/TaystJK/reference/cvars/ui_sha_a-a8e4932/) | cvar | ui | Controls `ui_sha_a` in the ui module. |
| [`ui_sha_b`](/TaystJK/reference/cvars/ui_sha_b-0e69c90/) | cvar | ui | Controls `ui_sha_b` in the ui module. |
| [`ui_sha_g`](/TaystJK/reference/cvars/ui_sha_g-ac3139d/) | cvar | ui | Controls `ui_sha_g` in the ui module. |
| [`ui_sha_r`](/TaystJK/reference/cvars/ui_sha_r-2be1fbe/) | cvar | ui | Controls `ui_sha_r` in the ui module. |
| [`ui_showAllSkins`](/TaystJK/reference/cvars/ui_showallskins-069498a/) | cvar | ui | Controls `ui_showAllSkins` in the ui module. |
| [`ui_sv_pure`](/TaystJK/reference/cvars/ui_sv_pure-05aa09d/) | cvar | ui | Controls `ui_sv_pure` in the ui module. |
| [`ui_teamSize`](/TaystJK/reference/cvars/ui_teamsize-7d2c5d8/) | cvar | ui | Controls `ui_teamSize` in the ui module. |
| [`ui_tribesMode`](/TaystJK/reference/cvars/ui_tribesmode-cc54205/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_username`](/TaystJK/reference/cvars/ui_username-1211939/) | cvar | ui | Controls `ui_username` in the ui module. |
| [`ui_version`](/TaystJK/reference/cvars/ui_version-b1d5a5a/) | cvar | cgame | Used by UI in the in-game "about" menu |
| [`ui_vgs`](/TaystJK/reference/cvars/ui_vgs-6f63532/) | cvar | ui | Controls `ui_vgs` in the ui module. |
| [`ui_vidrestart`](/TaystJK/reference/cvars/ui_vidrestart-724a091/) | cvar | ui | Controls `ui_vidrestart` in the ui module. |
| [`vm_legacy`](/TaystJK/reference/cvars/vm_legacy-cfedd35/) | cvar | engine-shared | Controls `vm_legacy` in the engine-shared module. |
| [`volume`](/TaystJK/reference/cvars/volume-d387fc8/) | cvar | engine-client | Volume |
| [`+button15`](/TaystJK/reference/commands/plusminus-button15-6428f06/) | command | engine-client | Button 15 |
| [`+duck`](/TaystJK/reference/commands/plusminus-duck-1aea248/) | command | cgame | Runs `CG_NorollDown_f` in the cgame module. |
| [`+grapple`](/TaystJK/reference/commands/plusminus-grapple-74f23a8/) | command | cgame | Runs `CG_GrappleDown_f` in the cgame module. |
| [`+singlefire`](/TaystJK/reference/commands/plusminus-singlefire-e166917/) | command | cgame | Runs `CG_SingleFireDown_f` in the cgame module. |
| [`+zoom`](/TaystJK/reference/commands/plusminus-zoom-0eb4e7d/) | command | cgame | Runs `CG_ZoomDown_f` in the cgame module. |
| [`-button15`](/TaystJK/reference/commands/minus-button15-95d61e3/) | command | engine-client | Runs `IN_Button15Up` in the engine-client module. |
| [`-duck`](/TaystJK/reference/commands/minus-duck-e229dd0/) | command | cgame | Runs `CG_NorollUp_f` in the cgame module. |
| [`-grapple`](/TaystJK/reference/commands/minus-grapple-b7c9090/) | command | cgame | Runs `CG_GrappleUp_f` in the cgame module. |
| [`-singlefire`](/TaystJK/reference/commands/minus-singlefire-9763ac0/) | command | cgame | Runs `CG_SingleFireUp_f` in the cgame module. |
| [`-zoom`](/TaystJK/reference/commands/minus-zoom-972df81/) | command | cgame | Runs `CG_ZoomUp_f` in the cgame module. |
| [`accountInfo`](/TaystJK/reference/commands/accountinfo-e041bfd/) | command | game | Runs `Svcmd_AccountInfo_f` in the game module. |
| [`addCheckpoint`](/TaystJK/reference/commands/addcheckpoint-7c51bf3/) | command | cgame | Runs `CG_AddCheckpoint_f` in the cgame module. |
| [`addFavorite`](/TaystJK/reference/commands/addfavorite-26823da/) | command | engine-client | Add server to favorites |
| [`addip`](/TaystJK/reference/commands/addip-5d88fb5/) | command | game | Runs `Svcmd_AddIP_f` in the game module. |
| [`addSpeedsound`](/TaystJK/reference/commands/addspeedsound-ab9ed14/) | command | cgame | Runs `CG_AddSpeedpoint_f` in the cgame module. |
| [`admCmdExe`](/TaystJK/reference/commands/admcmdexe-0988c2c/) | command | cgame | Forwards this command to the connected game server. |
| [`admCmdNext`](/TaystJK/reference/commands/admcmdnext-f31dbec/) | command | cgame | Forwards this command to the connected game server. |
| [`admCmdPrev`](/TaystJK/reference/commands/admcmdprev-a0e8fff/) | command | cgame | Forwards this command to the connected game server. |
| [`afk`](/TaystJK/reference/commands/afk-aec4e2a/) | command | engine-client | Rename to or from afk |
| [`amAltDim`](/TaystJK/reference/commands/amaltdim-6000039/) | command | cgame | Forwards this command to the connected game server. |
| [`amBan`](/TaystJK/reference/commands/amban-ac16303/) | command | cgame | Forwards this command to the connected game server. |
| [`amBeg`](/TaystJK/reference/commands/ambeg-ab94735/) | command | cgame | EMOTE |
| [`amBeg2`](/TaystJK/reference/commands/ambeg2-b509e29/) | command | cgame | EMOTE |
| [`ambernie`](/TaystJK/reference/commands/ambernie-ddb034a/) | command | game | EMOTE |
| [`amBreakDance`](/TaystJK/reference/commands/ambreakdance-1ce554f/) | command | cgame | EMOTE |
| [`amBreakDance2`](/TaystJK/reference/commands/ambreakdance2-3aab390/) | command | cgame | EMOTE |
| [`amBreakDance3`](/TaystJK/reference/commands/ambreakdance3-e2c5a04/) | command | cgame | EMOTE |
| [`amBreakDance4`](/TaystJK/reference/commands/ambreakdance4-3f4d2e8/) | command | cgame | EMOTE |
| [`amCheer`](/TaystJK/reference/commands/amcheer-e272fa7/) | command | cgame | EMOTE |
| [`amColor`](/TaystJK/reference/commands/amcolor-c9ed5c5/) | command | cgame | Forwards this command to the connected game server. |
| [`amCower`](/TaystJK/reference/commands/amcower-649ad64/) | command | cgame | EMOTE |
| [`amDance`](/TaystJK/reference/commands/amdance-c348eaa/) | command | cgame | EMOTE |
| [`amDenyVote`](/TaystJK/reference/commands/amdenyvote-8aee951/) | command | cgame | Forwards this command to the connected game server. |
| [`amDmgs`](/TaystJK/reference/commands/amdmgs-85b216b/) | command | cgame | Forwards this command to the connected game server. |
| [`amEmpower`](/TaystJK/reference/commands/amempower-738ceb5/) | command | cgame | Forwards this command to the connected game server. |
| [`amflip`](/TaystJK/reference/commands/amflip-0e01241/) | command | game | EMOTE |
| [`amForceAltDim`](/TaystJK/reference/commands/amforcealtdim-8a66f13/) | command | cgame | Forwards this command to the connected game server. |
| [`amForceTeam`](/TaystJK/reference/commands/amforceteam-7b44929/) | command | cgame | Forwards this command to the connected game server. |
| [`amFreeze`](/TaystJK/reference/commands/amfreeze-01cf6fd/) | command | cgame | Forwards this command to the connected game server. |
| [`amGhost`](/TaystJK/reference/commands/amghost-b436575/) | command | cgame | Forwards this command to the connected game server. |
| [`amGrantAdmin`](/TaystJK/reference/commands/amgrantadmin-4e5383a/) | command | cgame | Forwards this command to the connected game server. |
| [`amHug`](/TaystJK/reference/commands/amhug-82335a1/) | command | cgame | EMOTE |
| [`amInfo`](/TaystJK/reference/commands/aminfo-b53555a/) | command | cgame | Forwards this command to the connected game server. |
| [`amKick`](/TaystJK/reference/commands/amkick-2f00271/) | command | cgame | Forwards this command to the connected game server. |
| [`amKillVote`](/TaystJK/reference/commands/amkillvote-267af5c/) | command | cgame | Forwards this command to the connected game server. |
| [`amListMaps`](/TaystJK/reference/commands/amlistmaps-f83ab3c/) | command | cgame | Forwards this command to the connected game server. |
| [`amLockTeam`](/TaystJK/reference/commands/amlockteam-01e4806/) | command | cgame | Forwards this command to the connected game server. |
| [`amLogin`](/TaystJK/reference/commands/amlogin-0aff778/) | command | cgame | Forwards this command to the connected game server. |
| [`amLogout`](/TaystJK/reference/commands/amlogout-da89c31/) | command | cgame | Forwards this command to the connected game server. |
| [`amLookup`](/TaystJK/reference/commands/amlookup-0f303d7/) | command | cgame | Forwards this command to the connected game server. |
| [`amMap`](/TaystJK/reference/commands/ammap-7644e0b/) | command | cgame | Forwards this command to the connected game server. |
| [`amMerc`](/TaystJK/reference/commands/ammerc-34da96f/) | command | cgame | Forwards this command to the connected game server. |
| [`amMindTrick`](/TaystJK/reference/commands/ammindtrick-79013b1/) | command | cgame | Forwards this command to the connected game server. |
| [`amMotd`](/TaystJK/reference/commands/ammotd-5b85bc2/) | command | cgame | Forwards this command to the connected game server. |
| [`amMove`](/TaystJK/reference/commands/ammove-bc82282/) | command | cgame | Forwards this command to the connected game server. |
| [`amNoisy`](/TaystJK/reference/commands/amnoisy-fa20b9b/) | command | cgame | EMOTE |
| [`amPoint`](/TaystJK/reference/commands/ampoint-58ede89/) | command | cgame | EMOTE |
| [`amPoll`](/TaystJK/reference/commands/ampoll-ebab86e/) | command | cgame | Forwards this command to the connected game server. |
| [`amProtect`](/TaystJK/reference/commands/amprotect-604595f/) | command | cgame | Forwards this command to the connected game server. |
| [`ampSay`](/TaystJK/reference/commands/ampsay-c91ed51/) | command | cgame | Forwards this command to the connected game server. |
| [`amRage`](/TaystJK/reference/commands/amrage-79d8c3e/) | command | cgame | EMOTE |
| [`amRename`](/TaystJK/reference/commands/amrename-ad31e7c/) | command | cgame | Forwards this command to the connected game server. |
| [`amrun`](/TaystJK/reference/commands/amrun-373fdad/) | command | cgame | EMOTE |
| [`amSay`](/TaystJK/reference/commands/amsay-ef45240/) | command | cgame | Forwards this command to the connected game server. |
| [`amSeeGhost`](/TaystJK/reference/commands/amseeghost-383aa61/) | command | cgame | Forwards this command to the connected game server. |
| [`amShowMotd`](/TaystJK/reference/commands/amshowmotd-3ec94a1/) | command | cgame | Forwards this command to the connected game server. |
| [`amsignal`](/TaystJK/reference/commands/amsignal-1e13c57/) | command | game | EMOTE |
| [`amsignal2`](/TaystJK/reference/commands/amsignal2-f2de599/) | command | game | EMOTE |
| [`amsignal3`](/TaystJK/reference/commands/amsignal3-b6abb25/) | command | game | EMOTE |
| [`amsignal4`](/TaystJK/reference/commands/amsignal4-92650e2/) | command | game | EMOTE |
| [`amSilence`](/TaystJK/reference/commands/amsilence-0d4f91e/) | command | cgame | Forwards this command to the connected game server. |
| [`amSit`](/TaystJK/reference/commands/amsit-9d81b85/) | command | cgame | EMOTE |
| [`amSit2`](/TaystJK/reference/commands/amsit2-752a391/) | command | cgame | EMOTE |
| [`amSit3`](/TaystJK/reference/commands/amsit3-0cc6070/) | command | cgame | EMOTE |
| [`amSit4`](/TaystJK/reference/commands/amsit4-7ab8b7e/) | command | cgame | EMOTE |
| [`amSit5`](/TaystJK/reference/commands/amsit5-3281f99/) | command | cgame | EMOTE |
| [`amSlap`](/TaystJK/reference/commands/amslap-620092e/) | command | cgame | EMOTE |
| [`amSleep`](/TaystJK/reference/commands/amsleep-18eb1b4/) | command | cgame | EMOTE |
| [`amSmack`](/TaystJK/reference/commands/amsmack-21e8460/) | command | cgame | EMOTE |
| [`amStatus`](/TaystJK/reference/commands/amstatus-c75ade4/) | command | cgame | Forwards this command to the connected game server. |
| [`amSurrender`](/TaystJK/reference/commands/amsurrender-6e03fd5/) | command | cgame | EMOTE |
| [`amTaunt`](/TaystJK/reference/commands/amtaunt-3b4f992/) | command | cgame | EMOTE |
| [`amTaunt2`](/TaystJK/reference/commands/amtaunt2-e7be334/) | command | cgame | EMOTE |
| [`amTele`](/TaystJK/reference/commands/amtele-cbff2a5/) | command | cgame | Forwards this command to the connected game server. |
| [`amTeleMark`](/TaystJK/reference/commands/amtelemark-456039e/) | command | cgame | Forwards this command to the connected game server. |
| [`amUnForceAltDim`](/TaystJK/reference/commands/amunforcealtdim-9caf044/) | command | cgame | Forwards this command to the connected game server. |
| [`amVictory`](/TaystJK/reference/commands/amvictory-d06d5b4/) | command | cgame | EMOTE |
| [`amVstr`](/TaystJK/reference/commands/amvstr-e948c7e/) | command | cgame | Forwards this command to the connected game server. |
| [`amWait`](/TaystJK/reference/commands/amwait-8bd0bc7/) | command | cgame | Forwards this command to the connected game server. |
| [`amWake`](/TaystJK/reference/commands/amwake-799cb8f/) | command | cgame | Forwards this command to the connected game server. |
| [`amWeather`](/TaystJK/reference/commands/amweather-d7318f4/) | command | cgame | Forwards this command to the connected game server. |
| [`amWhois`](/TaystJK/reference/commands/amwhois-c3a6580/) | command | cgame | Forwards this command to the connected game server. |
| [`autoLogin`](/TaystJK/reference/commands/autologin-4739ac0/) | command | cgame | Runs `CG_Autologin_f` in the cgame module. |
| [`best`](/TaystJK/reference/commands/best-c5f5e4d/) | command | cgame | Forwards this command to the connected game server. |
| [`blink`](/TaystJK/reference/commands/blink-dcae3a7/) | command | game | Change for admin? |
| [`botlist`](/TaystJK/reference/commands/botlist-5978b77/) | command | game | Runs `Svcmd_BotList_f` in the game module. |
| [`cameraSettings`](/TaystJK/reference/commands/camerasettings-1e702fc/) | command | cgame | Runs `CG_ShowSpecCamera_f` in the cgame module. |
| [`capframes`](/TaystJK/reference/commands/capframes-e2a1440/) | command | renderer | Runs `R_CaptureFrameData_f` in the renderer module. |
| [`changePassword`](/TaystJK/reference/commands/changepassword-3dfd458/) | command | cgame | Forwards this command to the connected game server. |
| [`chatlog`](/TaystJK/reference/commands/chatlog-84c4a99/) | command | cgame | Runs `CG_ChatLogSettings_f` in the cgame module. |
| [`clanAdmin`](/TaystJK/reference/commands/clanadmin-81aa5bc/) | command | cgame | Forwards this command to the connected game server. |
| [`clanCreate`](/TaystJK/reference/commands/clancreate-c8e06da/) | command | cgame | Forwards this command to the connected game server. |
| [`clandelete`](/TaystJK/reference/commands/clandelete-a4890f1/) | command | game | Runs `Svcmd_ClanDelete_f` in the game module. |
| [`clanInfo`](/TaystJK/reference/commands/claninfo-d03453d/) | command | cgame | Forwards this command to the connected game server. |
| [`clanInvite`](/TaystJK/reference/commands/claninvite-0b616bf/) | command | cgame | Forwards this command to the connected game server. |
| [`clanJoin`](/TaystJK/reference/commands/clanjoin-45d4991/) | command | cgame | Forwards this command to the connected game server. |
| [`clankick`](/TaystJK/reference/commands/clankick-2d626df/) | command | game | Runs `Svcmd_ClanKick_f` in the game module. |
| [`clanLeave`](/TaystJK/reference/commands/clanleave-4c3bb60/) | command | cgame | Forwards this command to the connected game server. |
| [`clanList`](/TaystJK/reference/commands/clanlist-0df1c7a/) | command | cgame | Forwards this command to the connected game server. |
| [`clanPass`](/TaystJK/reference/commands/clanpass-e0e73ba/) | command | cgame | Forwards this command to the connected game server. |
| [`clanSay`](/TaystJK/reference/commands/clansay-0ce04c4/) | command | cgame | Forwards this command to the connected game server. |
| [`clanWhoIs`](/TaystJK/reference/commands/clanwhois-fc4d7f9/) | command | cgame | Forwards this command to the connected game server. |
| [`clearIP`](/TaystJK/reference/commands/clearip-92535a0/) | command | game | Runs `Svcmd_ClearIP_f` in the game module. |
| [`clearRemaps`](/TaystJK/reference/commands/clearremaps-10c3c32/) | command | renderer | Runs `R_ClearRemaps_f` in the renderer module. |
| [`clearTrail`](/TaystJK/reference/commands/cleartrail-314b9f6/) | command | cgame | Runs `CG_DeleteStrafeTrail_f` in the cgame module. |
| [`clientlist`](/TaystJK/reference/commands/clientlist-62d48a1/) | command | cgame | Displays a list of all connected clients and their real client numbers |
| [`colorname`](/TaystJK/reference/commands/colorname-eccdd14/) | command | engine-client | Color name |
| [`colorstring`](/TaystJK/reference/commands/colorstring-ff62b1e/) | command | engine-client | Color say text |
| [`coop`](/TaystJK/reference/commands/coop-786e986/) | command | game | Runs `Cmd_Coop_f` in the game module. |
| [`cosmetics`](/TaystJK/reference/commands/cosmetics-01c96cf/) | command | cgame | Runs `CG_Cosmetics_f` in the cgame module. |
| [`cvar_modified`](/TaystJK/reference/commands/cvar_modified-57ded5d/) | command | engine-shared | Show all modified cvars |
| [`cvar_usercreated`](/TaystJK/reference/commands/cvar_usercreated-da65457/) | command | engine-shared | Show all user created cvars |
| [`cvarAdd`](/TaystJK/reference/commands/cvaradd-8d5c5e5/) | command | engine-shared | Add a value to a cvar |
| [`cvarDiv`](/TaystJK/reference/commands/cvardiv-3fd3bfe/) | command | engine-shared | Divide a value from a cvar |
| [`cvarMod`](/TaystJK/reference/commands/cvarmod-47b87cc/) | command | engine-shared | Apply a modulo on a cvar |
| [`cvarMult`](/TaystJK/reference/commands/cvarmult-0b82792/) | command | engine-shared | Multiply a value to a cvar |
| [`cvarSub`](/TaystJK/reference/commands/cvarsub-4aed04d/) | command | engine-shared | Subtract a value from a cvar |
| [`DBInfo`](/TaystJK/reference/commands/dbinfo-c214d31/) | command | game | Runs `Svcmd_DBInfo_f` in the game module. |
| [`debugBMove_Back`](/TaystJK/reference/commands/debugbmove_back-8f2da3b/) | command | game | Runs `Cmd_BotMoveBack_f` in the game module. |
| [`debugBMove_Forward`](/TaystJK/reference/commands/debugbmove_forward-250e663/) | command | game | Runs `Cmd_BotMoveForward_f` in the game module. |
| [`debugBMove_Left`](/TaystJK/reference/commands/debugbmove_left-cccb2f7/) | command | game | Runs `Cmd_BotMoveLeft_f` in the game module. |
| [`debugBMove_Right`](/TaystJK/reference/commands/debugbmove_right-e2fea90/) | command | game | Runs `Cmd_BotMoveRight_f` in the game module. |
| [`debugBMove_Up`](/TaystJK/reference/commands/debugbmove_up-17c32c6/) | command | game | Runs `Cmd_BotMoveUp_f` in the game module. |
| [`deleteAccount`](/TaystJK/reference/commands/deleteaccount-1669172/) | command | game | Runs `Svcmd_DeleteAccount_f` in the game module. |
| [`deleteCheckpoint`](/TaystJK/reference/commands/deletecheckpoint-ec6c155/) | command | cgame | Runs `CG_DeleteCheckpoint_f` in the cgame module. |
| [`deletedemo`](/TaystJK/reference/commands/deletedemo-4eee4c5/) | command | engine-client | Delete a demo |
| [`deleteSpeedsound`](/TaystJK/reference/commands/deletespeedsound-a3361cf/) | command | cgame | Runs `CG_DeleteSpeedpoint_f` in the cgame module. |
| [`do`](/TaystJK/reference/commands/do-eadcd9b/) | command | cgame | Runs `CG_Do_f` in the cgame module. |
| [`duelteam`](/TaystJK/reference/commands/duelteam-50e5f76/) | command | cgame | Forwards this command to the connected game server. |
| [`duelWhois`](/TaystJK/reference/commands/duelwhois-6600b90/) | command | cgame | Forwards this command to the connected game server. |
| [`entityinfo`](/TaystJK/reference/commands/entityinfo-1ca8b9f/) | command | game | Runs `Svcmd_EntityInfo_f` in the game module. |
| [`entitylist`](/TaystJK/reference/commands/entitylist-f09e360/) | command | game | Runs `Svcmd_EntityList_f` in the game module. |
| [`execq`](/TaystJK/reference/commands/execq-48c51d3/) | command | engine-shared | Execute a script file without displaying a message |
| [`exit`](/TaystJK/reference/commands/exit-de3ac21/) | command | engine-shared | Exits the game |
| [`flagAccount`](/TaystJK/reference/commands/flagaccount-eeeecbc/) | command | game | Runs `Svcmd_FlagAccount_f` in the game module. |
| [`flipkick`](/TaystJK/reference/commands/flipkick-844ca0a/) | command | cgame | Runs `CG_Flipkick_f` in the cgame module. |
| [`followBlueFlag`](/TaystJK/reference/commands/followblueflag-a574443/) | command | cgame | Runs `CG_FollowBlueFlag_f` in the cgame module. |
| [`followFastest`](/TaystJK/reference/commands/followfastest-66908f6/) | command | cgame | Runs `CG_FollowFastest_f` in the cgame module. |
| [`follownext`](/TaystJK/reference/commands/follownext-a152e2f/) | command | cgame | Forwards this command to the connected game server. |
| [`followprev`](/TaystJK/reference/commands/followprev-c5dcaa8/) | command | cgame | Forwards this command to the connected game server. |
| [`followRedFlag`](/TaystJK/reference/commands/followredflag-caadae2/) | command | cgame | Runs `CG_FollowRedFlag_f` in the cgame module. |
| [`fontlist`](/TaystJK/reference/commands/fontlist-83422e5/) | command | renderer | Runs `R_FontList_f` in the renderer module. |
| [`forceteam`](/TaystJK/reference/commands/forceteam-72a2634/) | command | game | Runs `Svcmd_ForceTeam_f` in the game module. |
| [`fs_restart`](/TaystJK/reference/commands/fs_restart-205ee49/) | command | engine-shared | Restarts the filesystem if no module is currently using files from a pk3 |
| [`game_memory`](/TaystJK/reference/commands/game_memory-84c83cc/) | command | game | Runs `Svcmd_GameMem_f` in the game module. |
| [`gametype`](/TaystJK/reference/commands/gametype-d7c6fe6/) | command | game | Instantly changethe gametype of the server without having to reload the map |
| [`gc`](/TaystJK/reference/commands/gc-ec6d908/) | command | game | Runs `Cmd_GameCommand_f` in the game module. |
| [`gfxmeminfo`](/TaystJK/reference/commands/gfxmeminfo-491be17/) | command | renderer | Runs `GfxMemInfo_f` in the renderer module. |
| [`giveother`](/TaystJK/reference/commands/giveother-c475c5c/) | command | game | Runs `Cmd_GiveOther_f` in the game module. |
| [`help`](/TaystJK/reference/commands/help-92005ec/) | command | cgame | Print command help |
| [`hide`](/TaystJK/reference/commands/hide-93c8c96/) | command | cgame | Forwards this command to the connected game server. |
| [`ifCvar`](/TaystJK/reference/commands/ifcvar-a68f57c/) | command | engine-shared | Execute a command selected by comparisons against a cvar. |
| [`ignoreVGS`](/TaystJK/reference/commands/ignorevgs-46dc77b/) | command | cgame | Runs `CG_IgnoreVGS_f` in the cgame module. |
| [`invfree`](/TaystJK/reference/commands/invfree-4c191c5/) | command | cgame | Runs `CG_InvUseAvailable` in the cgame module. |
| [`jetpack`](/TaystJK/reference/commands/jetpack-806aec3/) | command | game | Runs `Cmd_Jetpack_f` in the game module. |
| [`jump`](/TaystJK/reference/commands/jump-271e9a5/) | command | cgame | Cmd_alive not needed but i think it resets on joingame cuz forcepoints? |
| [`kickall`](/TaystJK/reference/commands/kickall-7a42f1a/) | command | engine-server | Kick all users from the server |
| [`kickbots`](/TaystJK/reference/commands/kickbots-9695bdf/) | command | engine-server | Kick all bots from the server |
| [`kicknum`](/TaystJK/reference/commands/kicknum-43bb6d1/) | command | engine-server | Kick a user from the server by userid |
| [`killother`](/TaystJK/reference/commands/killother-c24ec29/) | command | game | Runs `Cmd_KillOther_f` in the game module. |
| [`launch`](/TaystJK/reference/commands/launch-f7c91fe/) | command | cgame | Forwards this command to the connected game server. |
| [`listAdmins`](/TaystJK/reference/commands/listadmins-135e048/) | command | game | Runs `Svcmd_ListAdmins_f` in the game module. |
| [`listCheckpoints`](/TaystJK/reference/commands/listcheckpoints-86cf253/) | command | cgame | Runs `CG_ListCheckpoints_f` in the cgame module. |
| [`listEmojis`](/TaystJK/reference/commands/listemojis-4b9aa16/) | command | cgame | Runs `CG_ListEmojis_f` in the cgame module. |
| [`listip`](/TaystJK/reference/commands/listip-3cf3e51/) | command | game | Runs `Svcmd_ListIP_f` in the game module. |
| [`listRemaps`](/TaystJK/reference/commands/listremaps-ccb7058/) | command | cgame | Runs `CG_ListRemaps_f` in the cgame module. |
| [`listSpeedsounds`](/TaystJK/reference/commands/listspeedsounds-fb40338/) | command | cgame | Runs `CG_ListSpeedpoints_f` in the cgame module. |
| [`loadmod`](/TaystJK/reference/commands/loadmod-ab292a3/) | command | engine-client | Restart the renderer (with specified mod folder) - or change the resolution |
| [`loadTrail`](/TaystJK/reference/commands/loadtrail-490c577/) | command | cgame | Runs `CG_SpawnStrafeTrailFromCFG_f` in the cgame module. |
| [`login`](/TaystJK/reference/commands/login-2736fab/) | command | cgame | Forwards this command to the connected game server. |
| [`logout`](/TaystJK/reference/commands/logout-55525e1/) | command | cgame | Forwards this command to the connected game server. |
| [`lowjump`](/TaystJK/reference/commands/lowjump-5afc6c0/) | command | cgame | Runs `CG_Lowjump_f` in the cgame module. |
| [`mapents`](/TaystJK/reference/commands/mapents-8844ab0/) | command | game | Runs `Cmd_MapEnts_f` in the game module. |
| [`master`](/TaystJK/reference/commands/master-4f26aea/) | command | cgame | Forwards this command to the connected game server. |
| [`masterlist`](/TaystJK/reference/commands/masterlist-96e0292/) | command | cgame | Forwards this command to the connected game server. |
| [`minimize`](/TaystJK/reference/commands/minimize-0c3639c/) | command | engine-shared | Runs `GLimp_Minimize` in the engine-shared module. |
| [`modversion`](/TaystJK/reference/commands/modversion-73dac73/) | command | cgame | Runs `CG_ModVersion_f` in the cgame module. |
| [`move`](/TaystJK/reference/commands/move-379d6ce/) | command | cgame | Forwards this command to the connected game server. |
| [`notCompleted`](/TaystJK/reference/commands/notcompleted-ce96ded/) | command | cgame | Forwards this command to the connected game server. |
| [`NPC`](/TaystJK/reference/commands/npc-3b86d7d/) | command | cgame | Removed cheat for admin //meh let us npc kill all from spec |
| [`nudge`](/TaystJK/reference/commands/nudge-37e4ac9/) | command | game | Runs `Cmd_Nudge_f` in the game module. |
| [`origin`](/TaystJK/reference/commands/origin-b284f94/) | command | cgame | Forwards this command to the connected game server. |
| [`pause`](/TaystJK/reference/commands/pause-ef8d299/) | command | game | Pause/unpause the game |
| [`playdemo`](/TaystJK/reference/commands/playdemo-eb741af/) | command | engine-client | Playback a demo |
| [`playerNext`](/TaystJK/reference/commands/playernext-f53bdbc/) | command | cgame | Forwards this command to the connected game server. |
| [`playerPrev`](/TaystJK/reference/commands/playerprev-2b5e037/) | command | cgame | Forwards this command to the connected game server. |
| [`plugin`](/TaystJK/reference/commands/plugin-fd8c7c8/) | command | cgame | Runs `CG_PluginDisable_f` in the cgame module. |
| [`pluginDisable`](/TaystJK/reference/commands/plugindisable-98b2c24/) | command | cgame | Runs `CG_PluginDisable_f` in the cgame module. |
| [`practice`](/TaystJK/reference/commands/practice-e17674f/) | command | cgame | Forwards this command to the connected game server. |
| [`print`](/TaystJK/reference/commands/print-6d0d587/) | command | engine-shared | Print cvar help |
| [`printStats`](/TaystJK/reference/commands/printstats-482f44d/) | command | cgame | Forwards this command to the connected game server. |
| [`PTele`](/TaystJK/reference/commands/ptele-fb0f4da/) | command | cgame | Runs `CG_PTele_f` in the cgame module. |
| [`PTelemark`](/TaystJK/reference/commands/ptelemark-8fcd18e/) | command | cgame | Runs `CG_PTelemark_f` in the cgame module. |
| [`r_cleardecals`](/TaystJK/reference/commands/r_cleardecals-243dbd7/) | command | renderer | Runs `RE_ClearDecals` in the renderer module. |
| [`race`](/TaystJK/reference/commands/race-de4bedc/) | command | cgame | Forwards this command to the connected game server. |
| [`rebuildElo`](/TaystJK/reference/commands/rebuildelo-eed7ec9/) | command | game | Delete all Elo records and rebuild them from the duel records in the database. |
| [`rebuildRaces`](/TaystJK/reference/commands/rebuildraces-de93639/) | command | game | Runs `SV_RebuildRaceRanks_f` in the game module. |
| [`rebuildUnlocks`](/TaystJK/reference/commands/rebuildunlocks-9112329/) | command | game | Runs `SV_RebuildUnlocks_f` in the game module. |
| [`register`](/TaystJK/reference/commands/register-13a2828/) | command | cgame | Forwards this command to the connected game server. |
| [`remapShader`](/TaystJK/reference/commands/remapshader-5315061/) | command | cgame | Runs `CG_RemapShader_f` in the cgame module. |
| [`remapSky`](/TaystJK/reference/commands/remapsky-55c2535/) | command | renderer | Runs `R_RemapSkyShader_f` in the renderer module. |
| [`removeip`](/TaystJK/reference/commands/removeip-38af509/) | command | game | Runs `Svcmd_RemoveIP_f` in the game module. |
| [`renameAccount`](/TaystJK/reference/commands/renameaccount-3fd6fd7/) | command | game | Runs `Svcmd_RenameAccount_f` in the game module. |
| [`resetScores`](/TaystJK/reference/commands/resetscores-5efac86/) | command | game | Reset all player/team scores without having to reload the map. |
| [`rFind`](/TaystJK/reference/commands/rfind-f2fd376/) | command | cgame | Forwards this command to the connected game server. |
| [`rHardest`](/TaystJK/reference/commands/rhardest-4250c13/) | command | cgame | Forwards this command to the connected game server. |
| [`rLatest`](/TaystJK/reference/commands/rlatest-fa0c7ce/) | command | cgame | Forwards this command to the connected game server. |
| [`rocketChange`](/TaystJK/reference/commands/rocketchange-f69e6d8/) | command | cgame | Forwards this command to the connected game server. |
| [`rPopular`](/TaystJK/reference/commands/rpopular-a69422f/) | command | cgame | Forwards this command to the connected game server. |
| [`rRank`](/TaystJK/reference/commands/rrank-4a8ddea/) | command | cgame | Forwards this command to the connected game server. |
| [`rTop`](/TaystJK/reference/commands/rtop-56f7fba/) | command | cgame | Forwards this command to the connected game server. |
| [`rWorst`](/TaystJK/reference/commands/rworst-00fab73/) | command | cgame | Forwards this command to the connected game server. |
| [`saber`](/TaystJK/reference/commands/saber-1b60697/) | command | cgame | Runs `CG_Saber_f` in the cgame module. |
| [`saberColor`](/TaystJK/reference/commands/sabercolor-78e6a36/) | command | cgame | Forwards this command to the connected game server. |
| [`saberDisable`](/TaystJK/reference/commands/saberdisable-cf2b094/) | command | game | Runs `Svcmd_ToggleSaberDisable_f` in the game module. |
| [`say_team_mod`](/TaystJK/reference/commands/say_team_mod-1d67bc8/) | command | cgame | Forwards this command to the connected game server. |
| [`score`](/TaystJK/reference/commands/score-75ebcb3/) | command | game | Runs `Cmd_Score_f` in the game module. |
| [`screenshot_png`](/TaystJK/reference/commands/screenshot_png-78032a6/) | command | renderer | Runs `R_ScreenShotPNG_f` in the renderer module. |
| [`selectfiremode`](/TaystJK/reference/commands/selectfiremode-bb9939e/) | command | cgame | Runs `CG_ToggleSingleFire_f` in the cgame module. |
| [`serverconfig`](/TaystJK/reference/commands/serverconfig-ee5ed61/) | command | cgame | Runs `CG_ServerConfig_f` in the cgame module. |
| [`showNet`](/TaystJK/reference/commands/shownet-4d0ae0e/) | command | cgame | Forwards this command to the connected game server. |
| [`showPlayerId`](/TaystJK/reference/commands/showplayerid-eb4fbea/) | command | cgame | Runs `CG_ClientList_f` in the cgame module. |
| [`siegeclass`](/TaystJK/reference/commands/siegeclass-3ba0852/) | command | cgame | Forwards this command to the connected game server. |
| [`slotnext`](/TaystJK/reference/commands/slotnext-3dbba08/) | command | cgame | Runs `CG_PrevWeaponSlot_f` in the cgame module. |
| [`slotprev`](/TaystJK/reference/commands/slotprev-4fb55f3/) | command | cgame | Runs `CG_NextWeaponSlot_f` in the cgame module. |
| [`speedometer`](/TaystJK/reference/commands/speedometer-b0e26e4/) | command | cgame | Runs `CG_SpeedometerSettings_f` in the cgame module. |
| [`spot`](/TaystJK/reference/commands/spot-9f4b527/) | command | cgame | Forwards this command to the connected game server. |
| [`startingItems`](/TaystJK/reference/commands/startingitems-2ed82fa/) | command | game | Runs `Svcmd_ToggleStartingItems_f` in the game module. |
| [`startingWeapons`](/TaystJK/reference/commands/startingweapons-7252a71/) | command | game | Runs `Svcmd_ToggleStartingWeapons_f` in the game module. |
| [`stopmusic`](/TaystJK/reference/commands/stopmusic-38c05b1/) | command | engine-client | Stops all music |
| [`stopvideo`](/TaystJK/reference/commands/stopvideo-db7ecec/) | command | engine-client | Stop avi recording |
| [`strafeHelper`](/TaystJK/reference/commands/strafehelper-bdb34b4/) | command | cgame | Runs `CG_StrafeHelper_f` in the cgame module. |
| [`strafeTrail`](/TaystJK/reference/commands/strafetrail-dddd025/) | command | cgame | Runs `CG_AddStrafeTrail_f` in the cgame module. |
| [`strSub`](/TaystJK/reference/commands/strsub-25a3e39/) | command | engine-shared | Execute a command with $cvar$ value substitution. |
| [`stylePlayer`](/TaystJK/reference/commands/styleplayer-33ef966/) | command | cgame | Runs `CG_StylePlayer_f` in the cgame module. |
| [`sv_banaddr`](/TaystJK/reference/commands/sv_banaddr-5213a27/) | command | engine-server | Bans a user |
| [`sv_bandel`](/TaystJK/reference/commands/sv_bandel-d30e97f/) | command | engine-server | Removes a ban |
| [`sv_exceptaddr`](/TaystJK/reference/commands/sv_exceptaddr-8c8c6e0/) | command | engine-server | Adds a ban exception for a user |
| [`sv_exceptdel`](/TaystJK/reference/commands/sv_exceptdel-8577ae8/) | command | engine-server | Removes a ban exception |
| [`sv_flushbans`](/TaystJK/reference/commands/sv_flushbans-884a191/) | command | engine-server | Removes all bans and exceptions |
| [`sv_listbans`](/TaystJK/reference/commands/sv_listbans-720c4f8/) | command | engine-server | Lists bans |
| [`sv_listrecording`](/TaystJK/reference/commands/sv_listrecording-21f40d6/) | command | engine-server | Lists demos being recorded |
| [`sv_rehashbans`](/TaystJK/reference/commands/sv_rehashbans-6f9f69f/) | command | engine-server | Reloads banlist from file |
| [`svrecord`](/TaystJK/reference/commands/svrecord-96937de/) | command | engine-server | Record a server-side demo |
| [`svrenamedemo`](/TaystJK/reference/commands/svrenamedemo-6d02cec/) | command | engine-server | Rename a server-side demo |
| [`svstoprecord`](/TaystJK/reference/commands/svstoprecord-b9ffafa/) | command | engine-server | Stop recording a server-side demo |
| [`svtell`](/TaystJK/reference/commands/svtell-f8cd34e/) | command | engine-server | Private message from the server to a user |
| [`t_use`](/TaystJK/reference/commands/t_use-2d01a2e/) | command | game | Runs `Cmd_TargetUse_f` in the game module. |
| [`teleToCheckpoint`](/TaystJK/reference/commands/teletocheckpoint-7aa58eb/) | command | cgame | Runs `CG_TeleToCheckpoint_f` in the cgame module. |
| [`testBSP`](/TaystJK/reference/commands/testbsp-22b895a/) | command | game | Runs `Cmd_TestBSP_f` in the game module. |
| [`thedestroyer`](/TaystJK/reference/commands/thedestroyer-eb1d67f/) | command | game | Runs `Cmd_TheDestroyer_f` in the game module. |
| [`throwflag`](/TaystJK/reference/commands/throwflag-d12a8a7/) | command | game | Runs `Cmd_Throwflag_f` in the game module. |
| [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/) | command | game | Runs `Svcmd_ToggleAdmin_f` in the game module. |
| [`toggleallowvote`](/TaystJK/reference/commands/toggleallowvote-3e2cc73/) | command | game | Runs `Svcmd_ToggleAllowVote_f` in the game module. |
| [`toggleEmotes`](/TaystJK/reference/commands/toggleemotes-c7d169a/) | command | game | Runs `Svcmd_ToggleEmotes_f` in the game module. |
| [`togglemenu`](/TaystJK/reference/commands/togglemenu-8971d97/) | command | engine-client | Show/hide the menu |
| [`toggleuserinfovalidation`](/TaystJK/reference/commands/toggleuserinfovalidation-f54be87/) | command | game | Runs `Svcmd_ToggleUserinfoValidation_f` in the game module. |
| [`toggleVote`](/TaystJK/reference/commands/togglevote-397b6ff/) | command | game | Runs `Svcmd_ToggleVote_f` in the game module. |
| [`top`](/TaystJK/reference/commands/top-af2c7b4/) | command | cgame | Forwards this command to the connected game server. |
| [`trace`](/TaystJK/reference/commands/trace-d0fa554/) | command | game | Runs `Cmd_Trace_f` in the game module. |
| [`tweakForce`](/TaystJK/reference/commands/tweakforce-05bb9d3/) | command | game | Runs `Svcmd_ToggleTweakForce_f` in the game module. |
| [`tweakSaber`](/TaystJK/reference/commands/tweaksaber-e5f1b57/) | command | game | Runs `Svcmd_ToggleTweakSaber_f` in the game module. |
| [`tweakVote`](/TaystJK/reference/commands/tweakvote-97236e2/) | command | game | Runs `Svcmd_ToggleTweakVote_f` in the game module. |
| [`tweakWeapons`](/TaystJK/reference/commands/tweakweapons-fd5860d/) | command | game | Runs `Svcmd_ToggleTweakWeapons_f` in the game module. |
| [`ui_cache`](/TaystJK/reference/commands/ui_cache-3e1b71d/) | command | ui | Runs `UI_Cache_f` in the ui module. |
| [`ui_load`](/TaystJK/reference/commands/ui_load-b884bdc/) | command | ui | Runs `UI_Load` in the ui module. |
| [`ui_modversion`](/TaystJK/reference/commands/ui_modversion-a282cdc/) | command | ui | Runs `UI_Modversion_f` in the ui module. |
| [`ui_openmenu`](/TaystJK/reference/commands/ui_openmenu-e42ca8c/) | command | ui | Runs `UI_OpenMenu_f` in the ui module. |
| [`ui_opensiegemenu`](/TaystJK/reference/commands/ui_opensiegemenu-a05b9b7/) | command | ui | Runs `UI_OpenSiegeMenu_f` in the ui module. |
| [`ui_report`](/TaystJK/reference/commands/ui_report-71f7773/) | command | ui | Runs `UI_Report` in the ui module. |
| [`unset`](/TaystJK/reference/commands/unset-fff210f/) | command | engine-shared | Unset a user generated cvar |
| [`unset_usercreated`](/TaystJK/reference/commands/unset_usercreated-9632483/) | command | engine-shared | Unset all user generated cvars Use with caution! |
| [`userinfo`](/TaystJK/reference/commands/userinfo-c0214b8/) | command | engine-client | Runs `CL_Clientinfo_f` in the engine-client module. |
| [`vbolist`](/TaystJK/reference/commands/vbolist-fe10c4e/) | command | renderer | Runs `R_VBOList_f` in the renderer module. |
| [`vgs_cmd`](/TaystJK/reference/commands/vgs_cmd-98de8a4/) | command | cgame | Vgs |
| [`video`](/TaystJK/reference/commands/video-ffbaf58/) | command | engine-client | Record demo to avi |
| [`voice_cmd`](/TaystJK/reference/commands/voice_cmd-3d7f601/) | command | cgame | Forwards this command to the connected game server. |
| [`warp`](/TaystJK/reference/commands/warp-af58c70/) | command | cgame | Forwards this command to the connected game server. |
| [`warpList`](/TaystJK/reference/commands/warplist-c2ce9d3/) | command | cgame | Forwards this command to the connected game server. |
| [`weaplast`](/TaystJK/reference/commands/weaplast-837fa67/) | command | cgame | Runs `CG_LastWeapon_f` in the cgame module. |
| [`weapontoggle`](/TaystJK/reference/commands/weapontoggle-7ca8872/) | command | engine-server | Toggle g_weaponDisable bits |
| [`where`](/TaystJK/reference/commands/where-46148cc/) | command | cgame | Forwards this command to the connected game server. |
| [`which`](/TaystJK/reference/commands/which-ed04ff4/) | command | engine-shared | Determines which search path a file was loaded from |
| [`whois`](/TaystJK/reference/commands/whois-a93a167/) | command | cgame | Forwards this command to the connected game server. |
| [`write`](/TaystJK/reference/commands/write-e1d0c6c/) | command | engine-shared | Write the configuration to file |
| [`ysal`](/TaystJK/reference/commands/ysal-49fb494/) | command | cgame | Forwards this command to the connected game server. |

## Semantics or options needing review (1707)

| Name | Kind | Module | Summary |
|:--|:--|:--|:--|
| [`_dedicated`](/TaystJK/reference/cvars/entry-_dedicated-f30b22a/) | cvar | engine-shared | Controls `com_dedicated` in the engine-shared module. |
| [`activeAction`](/TaystJK/reference/cvars/activeaction-b789056/) | cvar | engine-client | Controls `cl_activeAction` in the engine-client module. |
| [`arch`](/TaystJK/reference/cvars/arch-5a36f11/) | cvar | engine-shared | Controls `arch` in the engine-shared module. |
| [`bg_fighterAltControl`](/TaystJK/reference/cvars/bg_fighteraltcontrol-74138a2/) | cvar | cgame | Controls `bg_fighterAltControl` in the cgame module. |
| [`bot_attachments`](/TaystJK/reference/cvars/bot_attachments-21e20aa/) | cvar | game | Controls `bot_attachments` in the game module. |
| [`bot_camp`](/TaystJK/reference/cvars/bot_camp-bab1b8d/) | cvar | game | Controls `bot_camp` in the game module. |
| [`bot_debugmessages`](/TaystJK/reference/cvars/bot_debugmessages-b7195a5/) | cvar | game | Controls `bot_debugmessages` in the game module. |
| [`bot_forcepowers`](/TaystJK/reference/cvars/bot_forcepowers-a3120e7/) | cvar | game | Controls `bot_forcepowers` in the game module. |
| [`bot_forgimmick`](/TaystJK/reference/cvars/bot_forgimmick-6a07194/) | cvar | game | Controls `bot_forgimmick` in the game module. |
| [`bot_getinthecarrr`](/TaystJK/reference/cvars/bot_getinthecarrr-e9423b5/) | cvar | game | Controls `bot_getinthecarrr` in the game module. |
| [`bot_highlightarea`](/TaystJK/reference/cvars/bot_highlightarea-d37d3a7/) | cvar | engine-server | Controls `bot_highlightarea` in the engine-server module. |
| [`bot_honorableduelacceptance`](/TaystJK/reference/cvars/bot_honorableduelacceptance-5696da4/) | cvar | game | Controls `bot_honorableduelacceptance` in the game module. |
| [`bot_maxbots`](/TaystJK/reference/cvars/bot_maxbots-0448e7e/) | cvar | game | Controls `bot_maxbots` in the game module. |
| [`bot_nogoals`](/TaystJK/reference/cvars/bot_nogoals-e2324c1/) | cvar | game | Controls `bot_nogoals` in the game module. |
| [`bot_normgpath`](/TaystJK/reference/cvars/bot_normgpath-140f9e8/) | cvar | game | Controls `bot_normgpath` in the game module. |
| [`bot_pvstype`](/TaystJK/reference/cvars/bot_pvstype-72027f9/) | cvar | game | Controls `bot_pvstype` in the game module. |
| [`bot_s1`](/TaystJK/reference/cvars/bot_s1-d2c1d4f/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s2`](/TaystJK/reference/cvars/bot_s2-0d0b10e/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s3`](/TaystJK/reference/cvars/bot_s3-e579014/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s4`](/TaystJK/reference/cvars/bot_s4-e27ebfb/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s5`](/TaystJK/reference/cvars/bot_s5-cc1e024/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_s6`](/TaystJK/reference/cvars/bot_s6-67ce6b4/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`bot_strafeOffset`](/TaystJK/reference/cvars/bot_strafeoffset-0fc4233/) | cvar | game | Controls `bot_strafeOffset` in the game module. |
| [`bot_team`](/TaystJK/reference/cvars/bot_team-6042a35/) | cvar | game | Controls `bot_team` in the game module. |
| [`bot_wp_clearweight`](/TaystJK/reference/cvars/bot_wp_clearweight-8adccfd/) | cvar | game | Controls `bot_wp_clearweight` in the game module. |
| [`bot_wp_distconnect`](/TaystJK/reference/cvars/bot_wp_distconnect-6c3d5f5/) | cvar | game | Controls `bot_wp_distconnect` in the game module. |
| [`bot_wp_edit`](/TaystJK/reference/cvars/bot_wp_edit-3e7e69b/) | cvar | game | Controls `bot_wp_edit` in the game module. |
| [`bot_wp_info`](/TaystJK/reference/cvars/bot_wp_info-3cdeb0e/) | cvar | game | Controls `bot_wp_info` in the game module. |
| [`bot_wp_visconnect`](/TaystJK/reference/cvars/bot_wp_visconnect-30dfdd1/) | cvar | game | Controls `bot_wp_visconnect` in the game module. |
| [`broadsword`](/TaystJK/reference/cvars/broadsword-b938fd3/) | cvar | cgame | Controls `broadsword` in the cgame module. |
| [`broadsword_dircap`](/TaystJK/reference/cvars/broadsword_dircap-4a84248/) | cvar | renderer | Controls `broadsword_dircap` in the renderer module. |
| [`broadsword_dontstopanim`](/TaystJK/reference/cvars/broadsword_dontstopanim-96a0420/) | cvar | renderer | Controls `broadsword_dontstopanim` in the renderer module. |
| [`broadsword_effcorr`](/TaystJK/reference/cvars/broadsword_effcorr-0fade97/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_extra1`](/TaystJK/reference/cvars/broadsword_extra1-1b72b03/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_extra2`](/TaystJK/reference/cvars/broadsword_extra2-a936376/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_kickbones`](/TaystJK/reference/cvars/broadsword_kickbones-de3a44f/) | cvar | renderer | Controls `broadsword_kickbones` in the renderer module. |
| [`broadsword_kickorigin`](/TaystJK/reference/cvars/broadsword_kickorigin-504df15/) | cvar | renderer | Controls `broadsword_kickorigin` in the renderer module. |
| [`broadsword_playflop`](/TaystJK/reference/cvars/broadsword_playflop-431f63d/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_ragtobase`](/TaystJK/reference/cvars/broadsword_ragtobase-5874a91/) | cvar | renderer | Controls `broadsword_ragtobase` in the renderer module. |
| [`broadsword_smallbbox`](/TaystJK/reference/cvars/broadsword_smallbbox-3c99ac6/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_waitforshot`](/TaystJK/reference/cvars/broadsword_waitforshot-e2d3bca/) | cvar | renderer | Controls `broadsword_waitforshot` in the renderer module. |
| [`cg_alwaysShowAbsorb`](/TaystJK/reference/cvars/cg_alwaysshowabsorb-d52ebf0/) | cvar | cgame | Show absorb when it's in use |
| [`cg_ambientSounds`](/TaystJK/reference/cvars/cg_ambientsounds-00fb29b/) | cvar | cgame | Play ambient sounds |
| [`cg_animBlend`](/TaystJK/reference/cvars/cg_animblend-cce43f8/) | cvar | cgame | Controls `cg_animBlend` in the cgame module. |
| [`cg_animSpeed`](/TaystJK/reference/cvars/cg_animspeed-ccea52f/) | cvar | cgame | Controls `cg_animSpeed` in the cgame module. |
| [`cg_antiAmKiss`](/TaystJK/reference/cvars/cg_antiamkiss-1a82d9c/) | cvar | cgame | Controls `cg_antiAmKiss` in the cgame module. |
| [`cg_auraShell`](/TaystJK/reference/cvars/cg_aurashell-c22e6ae/) | cvar | cgame | Controls `cg_auraShell` in the cgame module. |
| [`cg_autoKillWhenFalling`](/TaystJK/reference/cvars/cg_autokillwhenfalling-9eb85fc/) | cvar | cgame | Controls `cg_autoKillWhenFalling` in the cgame module. |
| [`cg_autoLoginPass1`](/TaystJK/reference/cvars/cg_autologinpass1-d618f6e/) | cvar | cgame | Password to use. |
| [`cg_autoLoginPass2`](/TaystJK/reference/cvars/cg_autologinpass2-b2b6380/) | cvar | cgame | Controls `cg_autoLoginPass2` in the cgame module. |
| [`cg_autoLoginPass3`](/TaystJK/reference/cvars/cg_autologinpass3-2065bc1/) | cvar | cgame | Controls `cg_autoLoginPass3` in the cgame module. |
| [`cg_autoLoginServer1`](/TaystJK/reference/cvars/cg_autologinserver1-0ca4073/) | cvar | cgame | IP of server to try to autologin on, used with /autologin command. If you are not on the right server, the password will not be sent to the server. |
| [`cg_autoLoginServer2`](/TaystJK/reference/cvars/cg_autologinserver2-9a34450/) | cvar | cgame | Controls `cg_autoLoginServer2` in the cgame module. |
| [`cg_autoLoginServer3`](/TaystJK/reference/cvars/cg_autologinserver3-66a3457/) | cvar | cgame | Controls `cg_autoLoginServer3` in the cgame module. |
| [`cg_autoRecordDemo`](/TaystJK/reference/cvars/cg_autorecorddemo-fad7d88/) | cvar | cgame | Controls `cg_autoRecordDemo` in the cgame module. |
| [`cg_autoRecordRaceDemo`](/TaystJK/reference/cvars/cg_autorecordracedemo-7ac473c/) | cvar | cgame | Controls `cg_autoRecordRaceDemo` in the cgame module. |
| [`cg_autoScreenshot`](/TaystJK/reference/cvars/cg_autoscreenshot-34930f2/) | cvar | cgame | Automatically take a screenshot at end of round. |
| [`cg_autoSwitch`](/TaystJK/reference/cvars/cg_autoswitch-5936261/) | cvar | cgame | Controls `cg_autoSwitch` in the cgame module. |
| [`cg_bobPitch`](/TaystJK/reference/cvars/cg_bobpitch-6c78935/) | cvar | cgame | Controls `cg_bobPitch` in the cgame module. |
| [`cg_bobRoll`](/TaystJK/reference/cvars/cg_bobroll-3321473/) | cvar | cgame | Controls `cg_bobRoll` in the cgame module. |
| [`cg_bobUp`](/TaystJK/reference/cvars/cg_bobup-5e07470/) | cvar | cgame | Controls `cg_bobUp` in the cgame module. |
| [`cg_cameraOrbit`](/TaystJK/reference/cvars/cg_cameraorbit-6e01139/) | cvar | cgame | Controls `cg_cameraOrbit` in the cgame module. |
| [`cg_cameraOrbitDelay`](/TaystJK/reference/cvars/cg_cameraorbitdelay-4cd862d/) | cvar | cgame | Controls `cg_cameraOrbitDelay` in the cgame module. |
| [`cg_centerHeight`](/TaystJK/reference/cvars/cg_centerheight-bbab188/) | cvar | cgame | Controls `cg_centerHeight` in the cgame module. |
| [`cg_centerSize`](/TaystJK/reference/cvars/cg_centersize-615dcaa/) | cvar | cgame | Controls `cg_centerSize` in the cgame module. |
| [`cg_centerTime`](/TaystJK/reference/cvars/cg_centertime-5b86ac2/) | cvar | cgame | Controls `cg_centerTime` in the cgame module. |
| [`cg_chatBox`](/TaystJK/reference/cvars/cg_chatbox-d3edbae/) | cvar | cgame | Controls `cg_chatBox` in the cgame module. |
| [`cg_chatBoxCutOffLength`](/TaystJK/reference/cvars/cg_chatboxcutofflength-abf6a17/) | cvar | cgame | Width of a line in the chatbox before breaking to a new one |
| [`cg_chatBoxEmojis`](/TaystJK/reference/cvars/cg_chatboxemojis-7bdc808/) | cvar | cgame | Controls `cg_chatBoxEmojis` in the cgame module. |
| [`cg_chatBoxFontSize`](/TaystJK/reference/cvars/cg_chatboxfontsize-85a3a51/) | cvar | cgame | Scale of the chat box font |
| [`cg_chatBoxHeight`](/TaystJK/reference/cvars/cg_chatboxheight-08b8bc2/) | cvar | cgame | Controls `cg_chatBoxHeight` in the cgame module. |
| [`cg_chatBoxLines`](/TaystJK/reference/cvars/cg_chatboxlines-ef18116/) | cvar | cgame | This would be called chatBoxHeight if baseJKA didn't use that |
| [`cg_chatBoxShowCutoff`](/TaystJK/reference/cvars/cg_chatboxshowcutoff-3c9eab8/) | cvar | cgame | Controls `cg_chatBoxShowCutoff` in the cgame module. |
| [`cg_chatBoxShowHistory`](/TaystJK/reference/cvars/cg_chatboxshowhistory-e0f1ccf/) | cvar | cgame | Shows past messages when console is open |
| [`cg_chatBoxX`](/TaystJK/reference/cvars/cg_chatboxx-e3271fd/) | cvar | cgame | Controls `cg_chatBoxX` in the cgame module. |
| [`cg_chatSounds`](/TaystJK/reference/cvars/cg_chatsounds-fe6292d/) | cvar | cgame | Play sound when chat messages are received |
| [`cg_cleanChatbox`](/TaystJK/reference/cvars/cg_cleanchatbox-3609d1a/) | cvar | cgame | 1=Remove all colors from chat msgs, 2=Only remove color at begining of message |
| [`cg_crosshairColor`](/TaystJK/reference/cvars/cg_crosshaircolor-a61b771/) | cvar | cgame | Controls `cg_crosshairColor` in the cgame module. |
| [`cg_crosshairHealth`](/TaystJK/reference/cvars/cg_crosshairhealth-754bdda/) | cvar | cgame | Controls `cg_crosshairHealth` in the cgame module. |
| [`cg_crosshairIdentifyTarget`](/TaystJK/reference/cvars/cg_crosshairidentifytarget-f52b58a/) | cvar | cgame | Controls `cg_crosshairIdentifyTarget` in the cgame module. |
| [`cg_crosshairSaberStyleColor`](/TaystJK/reference/cvars/cg_crosshairsaberstylecolor-14bed3a/) | cvar | cgame | Controls `cg_crosshairSaberStyleColor` in the cgame module. |
| [`cg_crossHairScope`](/TaystJK/reference/cvars/cg_crosshairscope-93d2076/) | cvar | cgame | Minimalist crosshair disruptor scope replacement |
| [`cg_crosshairSize`](/TaystJK/reference/cvars/cg_crosshairsize-5325063/) | cvar | cgame | Controls `cg_crosshairSize` in the cgame module. |
| [`cg_crosshairSizeScale`](/TaystJK/reference/cvars/cg_crosshairsizescale-8838e3c/) | cvar | cgame | Controls `cg_crosshairSizeScale` in the cgame module. |
| [`cg_crosshairX`](/TaystJK/reference/cvars/cg_crosshairx-fbaeab2/) | cvar | cgame | Controls `cg_crosshairX` in the cgame module. |
| [`cg_crosshairY`](/TaystJK/reference/cvars/cg_crosshairy-79c55c3/) | cvar | cgame | Controls `cg_crosshairY` in the cgame module. |
| [`cg_currentSelectedPlayer`](/TaystJK/reference/cvars/cg_currentselectedplayer-5cdbbf9/) | cvar | cgame | Controls `cg_currentSelectedPlayer` in the cgame module. |
| [`cg_debugAnim`](/TaystJK/reference/cvars/cg_debuganim-a7b3132/) | cvar | cgame | Controls `cg_debugAnim` in the cgame module. |
| [`cg_debugEvents`](/TaystJK/reference/cvars/cg_debugevents-20ff0e7/) | cvar | cgame | Controls `cg_debugEvents` in the cgame module. |
| [`cg_debugGun`](/TaystJK/reference/cvars/cg_debuggun-6a4d591/) | cvar | cgame | Controls `cg_debugGun` in the cgame module. |
| [`cg_debugPosition`](/TaystJK/reference/cvars/cg_debugposition-66bbc1e/) | cvar | cgame | Controls `cg_debugPosition` in the cgame module. |
| [`cg_debugSaber`](/TaystJK/reference/cvars/cg_debugsaber-0399b3c/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_defaultFemaleModel`](/TaystJK/reference/cvars/cg_defaultfemalemodel-2d9b8bf/) | cvar | cgame | Controls `cg_defaultFemaleModel` in the cgame module. |
| [`cg_defaultModel`](/TaystJK/reference/cvars/cg_defaultmodel-16870a9/) | cvar | cgame | Controls `cg_defaultModel` in the cgame module. |
| [`cg_defaultModelRandom`](/TaystJK/reference/cvars/cg_defaultmodelrandom-139255e/) | cvar | cgame | Controls `cg_defaultModelRandom` in the cgame module. |
| [`cg_deferPlayers`](/TaystJK/reference/cvars/cg_deferplayers-7884da1/) | cvar | cgame | Controls `cg_deferPlayers` in the cgame module. |
| [`cg_dismember`](/TaystJK/reference/cvars/cg_dismember-8f13e99/) | cvar | cgame | Controls `cg_dismember` in the cgame module. |
| [`cg_displayCameraPosition`](/TaystJK/reference/cvars/cg_displaycameraposition-7ad50eb/) | cvar | cgame | Controls `cg_displayCameraPosition` in the cgame module. |
| [`cg_displayNetSettings`](/TaystJK/reference/cvars/cg_displaynetsettings-a58025c/) | cvar | cgame | Controls `cg_displayNetSettings` in the cgame module. |
| [`cg_disruptorAltTime`](/TaystJK/reference/cvars/cg_disruptoralttime-265b925/) | cvar | cgame | Amount of time to display disruptor alt fire |
| [`cg_disruptorCoreColor`](/TaystJK/reference/cvars/cg_disruptorcorecolor-9319cd0/) | cvar | cgame | Changes disruptor line color (accepts hexcode eg. xffffff) |
| [`cg_disruptorMainTime`](/TaystJK/reference/cvars/cg_disruptormaintime-3ae961c/) | cvar | cgame | Amount of time to display disruptor primary fire |
| [`cg_disruptorNew`](/TaystJK/reference/cvars/cg_disruptornew-f6cffa9/) | cvar | cgame | Enable new disruptor effects |
| [`cg_disruptorSpiral`](/TaystJK/reference/cvars/cg_disruptorspiral-0625e4c/) | cvar | cgame | Enable disruptor spiral effect |
| [`cg_disruptorSpiralColor`](/TaystJK/reference/cvars/cg_disruptorspiralcolor-197aaca/) | cvar | cgame | Changes disruptor spiral color (accepts hexcode eg. xffffff) |
| [`cg_disruptorTeamColor`](/TaystJK/reference/cvars/cg_disruptorteamcolor-68d3b53/) | cvar | cgame | Changes disruptor effects colors according to team |
| [`cg_drainFX`](/TaystJK/reference/cvars/cg_drainfx-0b786b0/) | cvar | cgame | Controls `cg_drainFX` in the cgame module. |
| [`cg_draw3DIcons`](/TaystJK/reference/cvars/cg_draw3dicons-e42c146/) | cvar | cgame | Controls `cg_draw3DIcons` in the cgame module. |
| [`cg_drawAmmoWarning`](/TaystJK/reference/cvars/cg_drawammowarning-1ecf584/) | cvar | cgame | Controls `cg_drawAmmoWarning` in the cgame module. |
| [`cg_drawCrosshair`](/TaystJK/reference/cvars/cg_drawcrosshair-2db6bb9/) | cvar | cgame | Controls `cg_drawCrosshair` in the cgame module. |
| [`cg_drawEnemyInfo`](/TaystJK/reference/cvars/cg_drawenemyinfo-83f96b2/) | cvar | cgame | Controls `cg_drawEnemyInfo` in the cgame module. |
| [`cg_drawFriend`](/TaystJK/reference/cvars/cg_drawfriend-75e27fd/) | cvar | cgame | Controls `cg_drawFriend` in the cgame module. |
| [`cg_drawGun`](/TaystJK/reference/cvars/cg_drawgun-f3f4ebe/) | cvar | cgame | Controls `cg_drawGun` in the cgame module. |
| [`cg_drawHitBox`](/TaystJK/reference/cvars/cg_drawhitbox-0f70f0a/) | cvar | cgame | Controls `cg_drawHitBox` in the cgame module. |
| [`cg_drawHud`](/TaystJK/reference/cvars/cg_drawhud-d58b164/) | cvar | cgame | Controls `cg_drawHud` in the cgame module. |
| [`cg_drawIcons`](/TaystJK/reference/cvars/cg_drawicons-5e047ed/) | cvar | cgame | Controls `cg_drawIcons` in the cgame module. |
| [`cg_drawInventory`](/TaystJK/reference/cvars/cg_drawinventory-d918048/) | cvar | cgame | Controls `cg_drawInventory` in the cgame module. |
| [`cg_drawPlayerNames`](/TaystJK/reference/cvars/cg_drawplayernames-688cd3a/) | cvar | cgame | Controls `cg_drawPlayerNames` in the cgame module. |
| [`cg_drawPlayerNamesScale`](/TaystJK/reference/cvars/cg_drawplayernamesscale-94d9ef0/) | cvar | cgame | Controls `cg_drawPlayerNamesScale` in the cgame module. |
| [`cg_drawPowerUpIcons`](/TaystJK/reference/cvars/cg_drawpowerupicons-309d5b9/) | cvar | cgame | Controls `cg_drawPowerUpIcons` in the cgame module. |
| [`cg_drawRadar`](/TaystJK/reference/cvars/cg_drawradar-b79f76e/) | cvar | cgame | Controls `cg_drawRadar` in the cgame module. |
| [`cg_drawRewards`](/TaystJK/reference/cvars/cg_drawrewards-49bc8f7/) | cvar | cgame | Controls `cg_drawRewards` in the cgame module. |
| [`cg_drawScore`](/TaystJK/reference/cvars/cg_drawscore-f2358ae/) | cvar | cgame | Score counter on HUD |
| [`cg_drawScoreX`](/TaystJK/reference/cvars/cg_drawscorex-3d12558/) | cvar | cgame | Horizontal offset for score counter on HUD |
| [`cg_drawScoreY`](/TaystJK/reference/cvars/cg_drawscorey-8ca83fd/) | cvar | cgame | Vertical offset for score counter on HUD |
| [`cg_drawScreenTints`](/TaystJK/reference/cvars/cg_drawscreentints-bddc984/) | cvar | cgame | Turn the tint from water on or off |
| [`cg_drawSnapshot`](/TaystJK/reference/cvars/cg_drawsnapshot-bdaa7eb/) | cvar | cgame | Controls `cg_drawSnapshot` in the cgame module. |
| [`cg_drawTeamOverlayWeapons`](/TaystJK/reference/cvars/cg_drawteamoverlayweapons-864b183/) | cvar | cgame | Draw each player's current weapon on the team overlay |
| [`cg_drawTeamOverlayX`](/TaystJK/reference/cvars/cg_drawteamoverlayx-0618c68/) | cvar | cgame | Horizontal location of the right edge of the team overlay |
| [`cg_drawTeamOverlayY`](/TaystJK/reference/cvars/cg_drawteamoverlayy-249a13a/) | cvar | cgame | Vertical location of the team overlay |
| [`cg_drawTimerCountdown`](/TaystJK/reference/cvars/cg_drawtimercountdown-26c13db/) | cvar | cgame | Controls `cg_drawTimerCountdown` in the cgame module. |
| [`cg_drawTimerMsec`](/TaystJK/reference/cvars/cg_drawtimermsec-156f1d2/) | cvar | cgame | Controls `cg_drawTimerMsec` in the cgame module. |
| [`cg_drawTrajectory`](/TaystJK/reference/cvars/cg_drawtrajectory-39b4cbe/) | cvar | cgame | Controls `cg_drawTrajectory` in the cgame module. |
| [`cg_drawTriggers`](/TaystJK/reference/cvars/cg_drawtriggers-ec57388/) | cvar | cgame | Controls `cg_drawTriggers` in the cgame module. |
| [`cg_drawUpperRight`](/TaystJK/reference/cvars/cg_drawupperright-5b41022/) | cvar | cgame | Controls `cg_drawUpperRight` in the cgame module. |
| [`cg_drawVehLeadIndicator`](/TaystJK/reference/cvars/cg_drawvehleadindicator-a231e1c/) | cvar | cgame | Controls `cg_drawVehLeadIndicator` in the cgame module. |
| [`cg_drawVote`](/TaystJK/reference/cvars/cg_drawvote-03fa352/) | cvar | cgame | Displays votecalls in the upper left |
| [`cg_duelMusic`](/TaystJK/reference/cvars/cg_duelmusic-aa17cd0/) | cvar | cgame | Enables special in-game music for private duels |
| [`cg_duelSounds`](/TaystJK/reference/cvars/cg_duelsounds-4be05fd/) | cvar | cgame | Enables/disables announcer/center print at the start of private duels |
| [`cg_dynamicCrosshair`](/TaystJK/reference/cvars/cg_dynamiccrosshair-279645a/) | cvar | cgame | Controls `cg_dynamicCrosshair` in the cgame module. |
| [`cg_dynamicCrosshairPrecision`](/TaystJK/reference/cvars/cg_dynamiccrosshairprecision-5e5ca88/) | cvar | cgame | Controls `cg_dynamicCrosshairPrecision` in the cgame module. |
| [`cg_engineModifications`](/TaystJK/reference/cvars/cg_enginemodifications-0e53ca8/) | cvar | cgame | Controls `cg_engineModifications` in the cgame module. |
| [`cg_errorDecay`](/TaystJK/reference/cvars/cg_errordecay-6e1a208/) | cvar | cgame | Controls `cg_errorDecay` in the cgame module. |
| [`cg_fkDuration`](/TaystJK/reference/cvars/cg_fkduration-60df772/) | cvar | cgame | Controls `cg_fkDuration` in the cgame module. |
| [`cg_fkFirstJumpDuration`](/TaystJK/reference/cvars/cg_fkfirstjumpduration-6c4486b/) | cvar | cgame | Controls `cg_fkFirstJumpDuration` in the cgame module. |
| [`cg_fkSecondJumpDelay`](/TaystJK/reference/cvars/cg_fksecondjumpdelay-6217188/) | cvar | cgame | Controls `cg_fkSecondJumpDelay` in the cgame module. |
| [`cg_fleshSparks`](/TaystJK/reference/cvars/cg_fleshsparks-6cfe42f/) | cvar | cgame | Maximum number of sparks from a saber hit |
| [`cg_footsteps`](/TaystJK/reference/cvars/cg_footsteps-2707982/) | cvar | cgame | Controls `cg_footsteps` in the cgame module. |
| [`cg_forceAllyModel`](/TaystJK/reference/cvars/cg_forceallymodel-2d546b7/) | cvar | cgame | Controls `cg_forceAllyModel` in the cgame module. |
| [`cg_forceCosmetics`](/TaystJK/reference/cvars/cg_forcecosmetics-598fb8d/) | cvar | cgame | Forces all players to have your cosmetics on non-japro servers |
| [`cg_forceEnemyModel`](/TaystJK/reference/cvars/cg_forceenemymodel-d577813/) | cvar | cgame | Controls `cg_forceEnemyModel` in the cgame module. |
| [`cg_forceModel`](/TaystJK/reference/cvars/cg_forcemodel-86e3071/) | cvar | cgame | Controls `cg_forceModel` in the cgame module. |
| [`cg_forceOwnSaber`](/TaystJK/reference/cvars/cg_forceownsaber-6523482/) | cvar | cgame | Controls `cg_forceOwnSaber` in the cgame module. |
| [`cg_fov`](/TaystJK/reference/cvars/cg_fov-05db256/) | cvar | cgame | Controls `cg_fov` in the cgame module. |
| [`cg_fovAspectAdjust`](/TaystJK/reference/cvars/cg_fovaspectadjust-a01b353/) | cvar | cgame | Fixed skyportal issue |
| [`cg_fovViewmodel`](/TaystJK/reference/cvars/cg_fovviewmodel-585844a/) | cvar | cgame | Controls `cg_fovViewmodel` in the cgame module. |
| [`cg_fovViewmodelAdjust`](/TaystJK/reference/cvars/cg_fovviewmodeladjust-4ab4013/) | cvar | cgame | Shifts viewmodels down above cg_fov 90 |
| [`cg_fpls`](/TaystJK/reference/cvars/cg_fpls-c3e3b71/) | cvar | cgame | Controls `cg_fpls` in the cgame module. |
| [`cg_g2TraceLod`](/TaystJK/reference/cvars/cg_g2tracelod-6685be5/) | cvar | cgame | Controls `cg_g2TraceLod` in the cgame module. |
| [`cg_ghoul2Marks`](/TaystJK/reference/cvars/cg_ghoul2marks-1892a1a/) | cvar | cgame | Controls `cg_ghoul2Marks` in the cgame module. |
| [`cg_gunAlpha`](/TaystJK/reference/cvars/cg_gunalpha-82a9df0/) | cvar | cgame | Controls `cg_gunAlpha` in the cgame module. |
| [`cg_gunX`](/TaystJK/reference/cvars/cg_gunx-7fa7158/) | cvar | cgame | Controls `cg_gunX` in the cgame module. |
| [`cg_gunY`](/TaystJK/reference/cvars/cg_guny-e7310ce/) | cvar | cgame | Controls `cg_gunY` in the cgame module. |
| [`cg_gunZ`](/TaystJK/reference/cvars/cg_gunz-b9382f0/) | cvar | cgame | Controls `cg_gunZ` in the cgame module. |
| [`cg_headTurn`](/TaystJK/reference/cvars/cg_headturn-2d5b44b/) | cvar | cgame | Controls `cg_headTurn` in the cgame module. |
| [`cg_hitsounds`](/TaystJK/reference/cvars/cg_hitsounds-5ef7d07/) | cvar | cgame | Play a sound when you hit someone |
| [`cg_hudColors`](/TaystJK/reference/cvars/cg_hudcolors-e3b9e30/) | cvar | cgame | Changes the colors of the HUD based on saber style and force |
| [`cg_instantDuck`](/TaystJK/reference/cvars/cg_instantduck-ee7bc95/) | cvar | cgame | Controls `cg_instantDuck` in the cgame module. |
| [`cg_jumpGoal`](/TaystJK/reference/cvars/cg_jumpgoal-829a115/) | cvar | cgame | Set a first jump speed goal speed, if first jump speed is above your goal speed, the pre-speed text will be green. Requires /speedometer 1 enabled |
| [`cg_jumpHeight`](/TaystJK/reference/cvars/cg_jumpheight-d0ee024/) | cvar | cgame | Specify jumpheight before jump is automaticaly canceled. |
| [`cg_killfeed`](/TaystJK/reference/cvars/cg_killfeed-020f6f8/) | cvar | cgame | Draw a killfeed on the HUD |
| [`cg_killfeedAlignment`](/TaystJK/reference/cvars/cg_killfeedalignment-10e367a/) | cvar | cgame | Align the killfeed |
| [`cg_killfeedColors`](/TaystJK/reference/cvars/cg_killfeedcolors-31f4cc3/) | cvar | cgame | Color the killfeed icons |
| [`cg_killfeedIconSize`](/TaystJK/reference/cvars/cg_killfeediconsize-508e23d/) | cvar | cgame | Resize the killfeed |
| [`cg_killfeedTextSize`](/TaystJK/reference/cvars/cg_killfeedtextsize-1f948df/) | cvar | cgame | Resize the killfeed |
| [`cg_killfeedX`](/TaystJK/reference/cvars/cg_killfeedx-32eb04e/) | cvar | cgame | Offset the killfeed's horizontal position from its current position |
| [`cg_killfeedY`](/TaystJK/reference/cvars/cg_killfeedy-e14002d/) | cvar | cgame | Offset the killfeed's vertical position from its current position |
| [`cg_killMessage`](/TaystJK/reference/cvars/cg_killmessage-b665d89/) | cvar | cgame | Print a kill message on the screen when you kill someone |
| [`cg_lagometer`](/TaystJK/reference/cvars/cg_lagometer-da10c07/) | cvar | cgame | Controls `cg_lagometer` in the cgame module. |
| [`cg_lagometerX`](/TaystJK/reference/cvars/cg_lagometerx-cb16443/) | cvar | cgame | Controls `cg_lagometerX` in the cgame module. |
| [`cg_lagometerY`](/TaystJK/reference/cvars/cg_lagometery-e1cecb6/) | cvar | cgame | Controls `cg_lagometerY` in the cgame module. |
| [`cg_leadIndicator`](/TaystJK/reference/cvars/cg_leadindicator-aebddda/) | cvar | cgame | Controls `cg_leadIndicator` in the cgame module. |
| [`cg_legstuck`](/TaystJK/reference/cvars/cg_legstuck-a73ad3c/) | cvar | cgame | Controls `cg_legstuck` in the cgame module. |
| [`cg_logChat`](/TaystJK/reference/cvars/cg_logchat-b9bd889/) | cvar | cgame | Controls `cg_logChat` in the cgame module. |
| [`cg_logStrafeTrail`](/TaystJK/reference/cvars/cg_logstrafetrail-6216305/) | cvar | cgame | Controls `cg_logStrafeTrail` in the cgame module. |
| [`cg_marks`](/TaystJK/reference/cvars/cg_marks-04d0449/) | cvar | cgame | Controls `cg_marks` in the cgame module. |
| [`cg_minimapScale`](/TaystJK/reference/cvars/cg_minimapscale-1662c4f/) | cvar | cgame | Controls `cg_minimapScale` in the cgame module. |
| [`cg_movementKeys`](/TaystJK/reference/cvars/cg_movementkeys-03e13b5/) | cvar | cgame | Select the on-screen movement-key overlay style. |
| [`cg_movementKeysSize`](/TaystJK/reference/cvars/cg_movementkeyssize-6686f74/) | cvar | cgame | Scale of the movement keys |
| [`cg_movementKeysX`](/TaystJK/reference/cvars/cg_movementkeysx-a7d563b/) | cvar | cgame | Horizontal location of the movement keys |
| [`cg_movementKeysY`](/TaystJK/reference/cvars/cg_movementkeysy-30e6290/) | cvar | cgame | Vertical location of the movement keys |
| [`cg_newFont`](/TaystJK/reference/cvars/cg_newfont-3b907a0/) | cvar | cgame | Uses a different font for the chat |
| [`cg_noFX`](/TaystJK/reference/cvars/cg_nofx-361d77e/) | cvar | cgame | Determines if effects and map models are shown |
| [`cg_noPlayerAnims`](/TaystJK/reference/cvars/cg_noplayeranims-75a0858/) | cvar | cgame | Controls `cg_noPlayerAnims` in the cgame module. |
| [`cg_noPredict`](/TaystJK/reference/cvars/cg_nopredict-f4b05f6/) | cvar | cgame | Controls `cg_noPredict` in the cgame module. |
| [`cg_noProjectileTrail`](/TaystJK/reference/cvars/cg_noprojectiletrail-fb1950f/) | cvar | cgame | Controls `cg_noProjectileTrail` in the cgame module. |
| [`cg_noRGBSabers`](/TaystJK/reference/cvars/cg_norgbsabers-19cc29e/) | cvar | cgame | Controls `cg_noRGBSabers` in the cgame module. |
| [`cg_noTaunt`](/TaystJK/reference/cvars/cg_notaunt-3bb3d8c/) | cvar | cgame | Controls `cg_noTaunt` in the cgame module. |
| [`cg_noTeleFX`](/TaystJK/reference/cvars/cg_notelefx-0a4c1c4/) | cvar | cgame | Disables the teleportation effect |
| [`cg_oldPainSounds`](/TaystJK/reference/cvars/cg_oldpainsounds-535e857/) | cvar | cgame | Controls `cg_oldPainSounds` in the cgame module. |
| [`cg_pitchHelper`](/TaystJK/reference/cvars/cg_pitchhelper-e3dadd7/) | cvar | cgame | Draw pitch angle independently from /cg_showpos |
| [`cg_pitchHelperOffset`](/TaystJK/reference/cvars/cg_pitchhelperoffset-9b851a1/) | cvar | cgame | Offset the green range up or down (eg. range 30, offset 10 = +25 to -5) |
| [`cg_pitchHelperRange`](/TaystJK/reference/cvars/cg_pitchhelperrange-249a33b/) | cvar | cgame | The range of numbers to display as green (eg. range 30, offset 0 = +15 to -15) |
| [`cg_pitchHelperX`](/TaystJK/reference/cvars/cg_pitchhelperx-a9d35e3/) | cvar | cgame | Move the pitch helper's horizontal location |
| [`cg_pitchHelperY`](/TaystJK/reference/cvars/cg_pitchhelpery-285d43a/) | cvar | cgame | Move the pitch helper's vertical location |
| [`cg_pitchHud`](/TaystJK/reference/cvars/cg_pitchhud-718ad06/) | cvar | cgame | Enable/Disable the pitch HUD |
| [`cg_pitchHudAngle`](/TaystJK/reference/cvars/cg_pitchhudangle-1647f9d/) | cvar | cgame | Controls `cg_pitchHudAngle` in the cgame module. |
| [`cg_pitchHudRgba`](/TaystJK/reference/cvars/cg_pitchhudrgba-b90e7dc/) | cvar | cgame | Color of the pitch HUD |
| [`cg_pitchHudThickness`](/TaystJK/reference/cvars/cg_pitchhudthickness-ea58d0e/) | cvar | cgame | Thickness |
| [`cg_pitchHudWidth`](/TaystJK/reference/cvars/cg_pitchhudwidth-770bd5f/) | cvar | cgame | Horizontal width |
| [`cg_pitchHudX`](/TaystJK/reference/cvars/cg_pitchhudx-d1f128d/) | cvar | cgame | Horizontal position |
| [`cg_predictItems`](/TaystJK/reference/cvars/cg_predictitems-61db805/) | cvar | cgame | Controls `cg_predictItems` in the cgame module. |
| [`cg_predictKnockback`](/TaystJK/reference/cvars/cg_predictknockback-103096d/) | cvar | cgame | Predict self-inflicted rocket-jump knockback clientside (racemode only). Use with cg_simulatedProjectiles 1. |
| [`cg_raceSounds`](/TaystJK/reference/cvars/cg_racesounds-cfc3317/) | cvar | cgame | Bitvalue, but so far we just have RS_TIMER_START set up |
| [`cg_raceStart`](/TaystJK/reference/cvars/cg_racestart-e3c5285/) | cvar | cgame | Enable race timer start speed separately from the race timer |
| [`cg_raceStartX`](/TaystJK/reference/cvars/cg_racestartx-c82e957/) | cvar | cgame | Horizontal location of the race start timer onscreen |
| [`cg_raceStartY`](/TaystJK/reference/cvars/cg_racestarty-210e8af/) | cvar | cgame | Vertical location of the race start timer onscreen |
| [`cg_raceTimer`](/TaystJK/reference/cvars/cg_racetimer-7361db5/) | cvar | cgame | Show the race timer onscreen |
| [`cg_raceTimerSize`](/TaystJK/reference/cvars/cg_racetimersize-7c766ca/) | cvar | cgame | Scale of the race timer |
| [`cg_raceTimerX`](/TaystJK/reference/cvars/cg_racetimerx-6e9d43d/) | cvar | cgame | Horizontal location of the race timer onscreen |
| [`cg_raceTimerY`](/TaystJK/reference/cvars/cg_racetimery-7b7373c/) | cvar | cgame | Vertical location of the race timer onscreen |
| [`cg_remaps`](/TaystJK/reference/cvars/cg_remaps-267c59f/) | cvar | cgame | Show or hide serverside remaps |
| [`cg_renderToTextureFX`](/TaystJK/reference/cvars/cg_rendertotexturefx-744c624/) | cvar | cgame | Controls `cg_renderToTextureFX` in the cgame module. |
| [`cg_repeaterOrb`](/TaystJK/reference/cvars/cg_repeaterorb-a5e5769/) | cvar | cgame | Controls `cg_repeaterOrb` in the cgame module. |
| [`cg_rollSounds`](/TaystJK/reference/cvars/cg_rollsounds-370ef41/) | cvar | cgame | Play sound when players roll |
| [`cg_runPitch`](/TaystJK/reference/cvars/cg_runpitch-db8b764/) | cvar | cgame | Controls `cg_runPitch` in the cgame module. |
| [`cg_runRoll`](/TaystJK/reference/cvars/cg_runroll-f6bae02/) | cvar | cgame | Controls `cg_runRoll` in the cgame module. |
| [`cg_saberClash`](/TaystJK/reference/cvars/cg_saberclash-98e5abd/) | cvar | cgame | Controls `cg_saberClash` in the cgame module. |
| [`cg_saberClientVisualCompensation`](/TaystJK/reference/cvars/cg_saberclientvisualcompensation-5111482/) | cvar | cgame | Controls `cg_saberClientVisualCompensation` in the cgame module. |
| [`cg_saberContact`](/TaystJK/reference/cvars/cg_sabercontact-343ea90/) | cvar | cgame | Controls `cg_saberContact` in the cgame module. |
| [`cg_saberDynamicMarks`](/TaystJK/reference/cvars/cg_saberdynamicmarks-9dbc592/) | cvar | cgame | Controls `cg_saberDynamicMarks` in the cgame module. |
| [`cg_saberDynamicMarkTime`](/TaystJK/reference/cvars/cg_saberdynamicmarktime-9ea8c5d/) | cvar | cgame | Controls `cg_saberDynamicMarkTime` in the cgame module. |
| [`cg_saberIgnitionFlare`](/TaystJK/reference/cvars/cg_saberignitionflare-bf8696a/) | cvar | cgame | Controls `cg_saberIgnitionFlare` in the cgame module. |
| [`cg_saberModelTraceEffect`](/TaystJK/reference/cvars/cg_sabermodeltraceeffect-d010298/) | cvar | cgame | Controls `cg_saberModelTraceEffect` in the cgame module. |
| [`cg_saberStaffMultiColor`](/TaystJK/reference/cvars/cg_saberstaffmulticolor-c4f7d05/) | cvar | cgame | Controls `cg_saberStaffMultiColor` in the cgame module. |
| [`cg_saberTeamColors`](/TaystJK/reference/cvars/cg_saberteamcolors-c7e0745/) | cvar | cgame | Controls `cg_saberTeamColors` in the cgame module. |
| [`cg_saberTrail`](/TaystJK/reference/cvars/cg_sabertrail-504b3ad/) | cvar | cgame | Controls `cg_saberTrail` in the cgame module. |
| [`cg_scopeSensitivity`](/TaystJK/reference/cvars/cg_scopesensitivity-e27d084/) | cvar | cgame | Controls `cg_scopeSensitivity` in the cgame module. |
| [`cg_scoreboardTime`](/TaystJK/reference/cvars/cg_scoreboardtime-c017d2f/) | cvar | cgame | Displays the local time on the scoreboard |
| [`cg_scoreDeaths`](/TaystJK/reference/cvars/cg_scoredeaths-67a5132/) | cvar | cgame | Display score AND deaths on the scoreboard |
| [`cg_scorePlums`](/TaystJK/reference/cvars/cg_scoreplums-7d5e895/) | cvar | cgame | Controls `cg_scorePlums` in the cgame module. |
| [`cg_screenShake`](/TaystJK/reference/cvars/cg_screenshake-f987066/) | cvar | cgame | Shake screen when hit or while charging weapons |
| [`cg_selectedPlayer`](/TaystJK/reference/cvars/cg_selectedplayer-8bf325d/) | cvar | ui | Controls `cg_selectedPlayer` in the ui module. |
| [`cg_selectedPlayerName`](/TaystJK/reference/cvars/cg_selectedplayername-ecf90ae/) | cvar | ui | Controls `cg_selectedPlayerName` in the ui module. |
| [`cg_shaderSaberCore`](/TaystJK/reference/cvars/cg_shadersabercore-88486dc/) | cvar | cgame | Controls `cg_shaderSaberCore` in the cgame module. |
| [`cg_shaderSaberGlow`](/TaystJK/reference/cvars/cg_shadersaberglow-585b811/) | cvar | cgame | Controls `cg_shaderSaberGlow` in the cgame module. |
| [`cg_shadows`](/TaystJK/reference/cvars/cg_shadows-09f85e1/) | cvar | cgame | Controls `cg_shadows` in the cgame module. |
| [`cg_showMiss`](/TaystJK/reference/cvars/cg_showmiss-96e3788/) | cvar | cgame | Controls `cg_showMiss` in the cgame module. |
| [`cg_showpos`](/TaystJK/reference/cvars/cg_showpos-785191d/) | cvar | cgame | Controls `cg_showpos` in the cgame module. |
| [`cg_showVehBounds`](/TaystJK/reference/cvars/cg_showvehbounds-e3b5f0c/) | cvar | cgame | Controls `cg_showVehBounds` in the cgame module. |
| [`cg_showVehMiss`](/TaystJK/reference/cvars/cg_showvehmiss-7394191/) | cvar | cgame | Controls `cg_showVehMiss` in the cgame module. |
| [`cg_siegeMessage`](/TaystJK/reference/cvars/cg_siegemessage-b0500ed/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_siegeTeam1`](/TaystJK/reference/cvars/cg_siegeteam1-3bda02e/) | cvar | cgame | Controls `cg_siegeTeam1` in the cgame module. |
| [`cg_siegeTeam1Name`](/TaystJK/reference/cvars/cg_siegeteam1name-bb506d0/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_siegeTeam2`](/TaystJK/reference/cvars/cg_siegeteam2-c84b26e/) | cvar | cgame | Controls `cg_siegeTeam2` in the cgame module. |
| [`cg_siegeTeam2Name`](/TaystJK/reference/cvars/cg_siegeteam2name-c4eb04f/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_simpleItems`](/TaystJK/reference/cvars/cg_simpleitems-b02935a/) | cvar | cgame | Controls `cg_simpleItems` in the cgame module. |
| [`cg_simulatedHitscan`](/TaystJK/reference/cvars/cg_simulatedhitscan-8c02e38/) | cvar | cgame | Toggle predicted hitscan weapon effects. |
| [`cg_simulatedProjectiles`](/TaystJK/reference/cvars/cg_simulatedprojectiles-e12d5f1/) | cvar | cgame | Wether to use simulated projectiles so bullets appear instantly. Values > 1 don't draw the projectile right away. |
| [`cg_smallScoreboard`](/TaystJK/reference/cvars/cg_smallscoreboard-1c675db/) | cvar | cgame | Always use the small version of the scoreboard |
| [`cg_smoothClients`](/TaystJK/reference/cvars/cg_smoothclients-baf7386/) | cvar | cgame | Controls `cg_smoothClients` in the cgame module. |
| [`cg_snapHud`](/TaystJK/reference/cvars/cg_snaphud-4dbb69f/) | cvar | cgame | Enable/Disable the snap HUD |
| [`cg_snapHudAuto`](/TaystJK/reference/cvars/cg_snaphudauto-f4cf9ff/) | cvar | cgame | Automatically detect best settings |
| [`cg_snapHudDef`](/TaystJK/reference/cvars/cg_snaphuddef-c5f71a3/) | cvar | cgame | Controls `cg_snapHudDef` in the cgame module. |
| [`cg_snapHudFps`](/TaystJK/reference/cvars/cg_snaphudfps-0576276/) | cvar | cgame | FPS for calculations (Leave default for auto) |
| [`cg_snapHudHeight`](/TaystJK/reference/cvars/cg_snaphudheight-d87b8e6/) | cvar | cgame | Vertical height |
| [`cg_snapHudRgba1`](/TaystJK/reference/cvars/cg_snaphudrgba1-b9ec8aa/) | cvar | cgame | Color for single key press |
| [`cg_snapHudRgba2`](/TaystJK/reference/cvars/cg_snaphudrgba2-e5d53f0/) | cvar | cgame | Color for two keys pressed |
| [`cg_snapHudSpeed`](/TaystJK/reference/cvars/cg_snaphudspeed-1a22dbb/) | cvar | cgame | Basespeed for calculations (Leave default for auto) |
| [`cg_snapHudY`](/TaystJK/reference/cvars/cg_snaphudy-cc550c0/) | cvar | cgame | Vertical position |
| [`cg_snapshotTimeout`](/TaystJK/reference/cvars/cg_snapshottimeout-6079a2a/) | cvar | cgame | Controls `cg_snapshotTimeout` in the cgame module. |
| [`cg_specCameraMode`](/TaystJK/reference/cvars/cg_speccameramode-95baeef/) | cvar | cgame | Controls `cg_specCameraMode` in the cgame module. |
| [`cg_specHud`](/TaystJK/reference/cvars/cg_spechud-70b1e1d/) | cvar | cgame | Controls `cg_specHud` in the cgame module. |
| [`cg_spectatorCameraDamp`](/TaystJK/reference/cvars/cg_spectatorcameradamp-1136737/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_speedometer`](/TaystJK/reference/cvars/cg_speedometer-9810620/) | cvar | cgame | Configure with the /speedometer command |
| [`cg_speedometerJumps`](/TaystJK/reference/cvars/cg_speedometerjumps-2a998a1/) | cvar | cgame | The amount of jumps to store in the jumps array, enable with the /speedometer command |
| [`cg_speedometerJumpsX`](/TaystJK/reference/cvars/cg_speedometerjumpsx-29e18d5/) | cvar | cgame | Horizontal location of the jumps array |
| [`cg_speedometerJumpsY`](/TaystJK/reference/cvars/cg_speedometerjumpsy-8a40b94/) | cvar | cgame | Vertical location of the jumps array |
| [`cg_speedometerSize`](/TaystJK/reference/cvars/cg_speedometersize-6fd381a/) | cvar | cgame | Scale of the speedometer |
| [`cg_speedometerX`](/TaystJK/reference/cvars/cg_speedometerx-58598b2/) | cvar | cgame | Horizontal location of the speedometer |
| [`cg_speedometerY`](/TaystJK/reference/cvars/cg_speedometery-7d4b635/) | cvar | cgame | Vertical location of the speedometer |
| [`cg_speedTrail`](/TaystJK/reference/cvars/cg_speedtrail-2918eb4/) | cvar | cgame | Controls `cg_speedTrail` in the cgame module. |
| [`cg_spotIconPlums`](/TaystJK/reference/cvars/cg_spoticonplums-79f0979/) | cvar | cgame | Controls `cg_spotIconPlums` in the cgame module. |
| [`cg_startGoal`](/TaystJK/reference/cvars/cg_startgoal-086db11/) | cvar | cgame | Start speed goal, if your start speed is above your goal speed, the text will be green, requires /cg_raceStart 1 |
| [`cg_stats`](/TaystJK/reference/cvars/cg_stats-0e14171/) | cvar | cgame | Controls `cg_stats` in the cgame module. |
| [`cg_stereoSeparation`](/TaystJK/reference/cvars/cg_stereoseparation-63c20da/) | cvar | cgame | Controls `cg_stereoSeparation` in the cgame module. |
| [`cg_strafeHelper`](/TaystJK/reference/cvars/cg_strafehelper-4850985/) | cvar | cgame | Configure with the /strafehelper command |
| [`cg_strafeHelper_FPS`](/TaystJK/reference/cvars/cg_strafehelper_fps-c64555f/) | cvar | cgame | Fats _ syntax to follow smod ;s |
| [`cg_strafeHelperActiveColor`](/TaystJK/reference/cvars/cg_strafehelperactivecolor-0c4cad4/) | cvar | cgame | Controls `cg_strafeHelperActiveColor` in the cgame module. |
| [`cg_strafeHelperCutoff`](/TaystJK/reference/cvars/cg_strafehelpercutoff-2cd5794/) | cvar | cgame | Controls `cg_strafeHelperCutoff` in the cgame module. |
| [`cg_strafeHelperInactiveAlpha`](/TaystJK/reference/cvars/cg_strafehelperinactivealpha-c641c50/) | cvar | cgame | Controls `cg_strafeHelperInactiveAlpha` in the cgame module. |
| [`cg_strafeHelperLineWidth`](/TaystJK/reference/cvars/cg_strafehelperlinewidth-790968e/) | cvar | cgame | Controls `cg_strafeHelperLineWidth` in the cgame module. |
| [`cg_strafeHelperOffset`](/TaystJK/reference/cvars/cg_strafehelperoffset-018a25b/) | cvar | cgame | Controls `cg_strafeHelperOffset` in the cgame module. |
| [`cg_strafeHelperPrecision`](/TaystJK/reference/cvars/cg_strafehelperprecision-9de34f5/) | cvar | cgame | Controls `cg_strafeHelperPrecision` in the cgame module. |
| [`cg_strafeTrailFPS`](/TaystJK/reference/cvars/cg_strafetrailfps-0969824/) | cvar | cgame | SV_FPS the strafetrail was recorded at. |
| [`cg_strafeTrailGhost`](/TaystJK/reference/cvars/cg_strafetrailghost-3933f97/) | cvar | cgame | Controls `cg_strafeTrailGhost` in the cgame module. |
| [`cg_strafeTrailLife`](/TaystJK/reference/cvars/cg_strafetraillife-79e03b0/) | cvar | cgame | Controls `cg_strafeTrailLife` in the cgame module. |
| [`cg_strafeTrailPlayers`](/TaystJK/reference/cvars/cg_strafetrailplayers-e720b69/) | cvar | cgame | Controls `cg_strafeTrailPlayers` in the cgame module. |
| [`cg_strafeTrailPlums`](/TaystJK/reference/cvars/cg_strafetrailplums-0f0679d/) | cvar | cgame | Controls `cg_strafeTrailPlums` in the cgame module. |
| [`cg_strafeTrailRacersOnly`](/TaystJK/reference/cvars/cg_strafetrailracersonly-2296b15/) | cvar | cgame | Controls `cg_strafeTrailRacersOnly` in the cgame module. |
| [`cg_strafeTrailRadius`](/TaystJK/reference/cvars/cg_strafetrailradius-d65c515/) | cvar | cgame | Controls `cg_strafeTrailRadius` in the cgame module. |
| [`cg_stylePlayer`](/TaystJK/reference/cvars/cg_styleplayer-c35894d/) | cvar | cgame | Configure with the /stylePlayer command |
| [`cg_thirdPerson`](/TaystJK/reference/cvars/cg_thirdperson-9be206a/) | cvar | cgame | Controls `cg_thirdPerson` in the cgame module. |
| [`cg_thirdPersonAlpha`](/TaystJK/reference/cvars/cg_thirdpersonalpha-1dbc32f/) | cvar | cgame | Controls `cg_thirdPersonAlpha` in the cgame module. |
| [`cg_thirdPersonAngle`](/TaystJK/reference/cvars/cg_thirdpersonangle-8fc1e1d/) | cvar | cgame | Controls `cg_thirdPersonAngle` in the cgame module. |
| [`cg_thirdPersonCameraDamp`](/TaystJK/reference/cvars/cg_thirdpersoncameradamp-23ee471/) | cvar | cgame | Controls `cg_thirdPersonCameraDamp` in the cgame module. |
| [`cg_thirdPersonCrosshairCenter`](/TaystJK/reference/cvars/cg_thirdpersoncrosshaircenter-a54cbd8/) | cvar | cgame | 1 is old third person static crosshair behavior |
| [`cg_thirdPersonFlagAlpha`](/TaystJK/reference/cvars/cg_thirdpersonflagalpha-ce71971/) | cvar | cgame | Custom transparency of the CTF flag |
| [`cg_thirdPersonHorzOffset`](/TaystJK/reference/cvars/cg_thirdpersonhorzoffset-1e694a4/) | cvar | cgame | Controls `cg_thirdPersonHorzOffset` in the cgame module. |
| [`cg_thirdPersonPitchOffset`](/TaystJK/reference/cvars/cg_thirdpersonpitchoffset-4c885af/) | cvar | cgame | Controls `cg_thirdPersonPitchOffset` in the cgame module. |
| [`cg_thirdPersonRange`](/TaystJK/reference/cvars/cg_thirdpersonrange-4c9945a/) | cvar | cgame | Controls `cg_thirdPersonRange` in the cgame module. |
| [`cg_thirdPersonSpecialCam`](/TaystJK/reference/cvars/cg_thirdpersonspecialcam-7a949a2/) | cvar | cgame | Controls `cg_thirdPersonSpecialCam` in the cgame module. |
| [`cg_thirdPersonTargetDamp`](/TaystJK/reference/cvars/cg_thirdpersontargetdamp-2dc65c3/) | cvar | cgame | Controls `cg_thirdPersonTargetDamp` in the cgame module. |
| [`cg_thirdPersonVertOffset`](/TaystJK/reference/cvars/cg_thirdpersonvertoffset-9b21aeb/) | cvar | cgame | Controls `cg_thirdPersonVertOffset` in the cgame module. |
| [`cg_timescaleFadeEnd`](/TaystJK/reference/cvars/cg_timescalefadeend-da092b6/) | cvar | cgame | Controls `cg_timescaleFadeEnd` in the cgame module. |
| [`cg_timescaleFadeSpeed`](/TaystJK/reference/cvars/cg_timescalefadespeed-b1ffd95/) | cvar | cgame | Controls `cg_timescaleFadeSpeed` in the cgame module. |
| [`cg_tintHud`](/TaystJK/reference/cvars/cg_tinthud-0c71140/) | cvar | cgame | Changes the color of the HUD based on team color |
| [`cg_vehicleRange`](/TaystJK/reference/cvars/cg_vehiclerange-987b56f/) | cvar | cgame | Offset vehicle camera ranges (useful for ultrawide monitors) |
| [`cg_viewsize`](/TaystJK/reference/cvars/cg_viewsize-24d3727/) | cvar | cgame | Controls `cg_viewsize` in the cgame module. |
| [`cg_weaponCycleAmmo`](/TaystJK/reference/cvars/cg_weaponcycleammo-3286c8e/) | cvar | cgame | Controls `cg_weaponCycleAmmo` in the cgame module. |
| [`cg_zoomSensitivity`](/TaystJK/reference/cvars/cg_zoomsensitivity-f19085b/) | cvar | cgame | Controls `cg_zoomSensitivity` in the cgame module. |
| [`cjp_client`](/TaystJK/reference/cvars/cjp_client-30f1526/) | cvar | cgame | Controls `cjp_client` in the cgame module. |
| [`cl_afkPrefix`](/TaystJK/reference/cvars/cl_afkprefix-de26080/) | cvar | engine-client | Prefix to add to player name when AFK |
| [`cl_afkTime`](/TaystJK/reference/cvars/cl_afktime-a051a42/) | cvar | engine-client | Minutes to autorename to afk, 0 to disable |
| [`cl_afkTimeUnfocused`](/TaystJK/reference/cvars/cl_afktimeunfocused-3a38f9b/) | cvar | engine-client | Minutes to autorename to afk while unfocused/minimized |
| [`cl_allowEnterCompletion`](/TaystJK/reference/cvars/cl_allowentercompletion-7ec0985/) | cvar | engine-client | Enables autocomplete when pressing enter |
| [`cl_anglespeedkey`](/TaystJK/reference/cvars/cl_anglespeedkey-612edff/) | cvar | engine-client | Controls `cl_anglespeedkey` in the engine-client module. |
| [`cl_autolodscale`](/TaystJK/reference/cvars/cl_autolodscale-b9ad539/) | cvar | engine-client | Controls `cl_autolodscale` in the engine-client module. |
| [`cl_avi2GBLimit`](/TaystJK/reference/cvars/cl_avi2gblimit-4a65d18/) | cvar | engine-client | Controls `cl_avi2GBLimit` in the engine-client module. |
| [`cl_aviFrameRate`](/TaystJK/reference/cvars/cl_aviframerate-a13588d/) | cvar | engine-client | Controls `cl_aviFrameRate` in the engine-client module. |
| [`cl_aviMotionJpeg`](/TaystJK/reference/cvars/cl_avimotionjpeg-91b798a/) | cvar | engine-client | Controls `cl_aviMotionJpeg` in the engine-client module. |
| [`cl_chatBubbleSelf`](/TaystJK/reference/cvars/cl_chatbubbleself-c8495de/) | cvar | engine-client | Controls `cl_chatBubbleSelf` in the engine-client module. |
| [`cl_chatBubbleUnfocused`](/TaystJK/reference/cvars/cl_chatbubbleunfocused-45667c5/) | cvar | engine-client | Controls `cl_chatBubbleUnfocused` in the engine-client module. |
| [`cl_chatStylePrefix`](/TaystJK/reference/cvars/cl_chatstyleprefix-1875f3b/) | cvar | engine-client | String inserted before sent chat messages |
| [`cl_chatStyleSuffix`](/TaystJK/reference/cvars/cl_chatstylesuffix-25c90ab/) | cvar | engine-client | String appended to send chat messages |
| [`cl_coloredTextShadows`](/TaystJK/reference/cvars/cl_coloredtextshadows-e3b625f/) | cvar | renderer | Toggle JK2 1.02-style colored text shadows |
| [`cl_colorString`](/TaystJK/reference/cvars/cl_colorstring-dfaadba/) | cvar | engine-client | Bit value of selected colors in colorString, configure chat colors with /colorstring |
| [`cl_colorStringCount`](/TaystJK/reference/cvars/cl_colorstringcount-5e55bbd/) | cvar | engine-client | Controls `cl_colorStringCount` in the engine-client module. |
| [`cl_colorStringRandom`](/TaystJK/reference/cvars/cl_colorstringrandom-d3b1d9a/) | cvar | engine-client | Randomness of the colors changing, higher numbers are less random |
| [`cl_commandsize`](/TaystJK/reference/cvars/cl_commandsize-8b702b0/) | cvar | cgame | Controls `cl_commandsize` in the cgame module. |
| [`cl_consoleKeys`](/TaystJK/reference/cvars/cl_consolekeys-0430407/) | cvar | engine-client | Which keys are used to toggle the console |
| [`cl_consoleUseScanCode`](/TaystJK/reference/cvars/cl_consoleusescancode-557fe4e/) | cvar | engine-client | Use native console key detection |
| [`cl_conXOffset`](/TaystJK/reference/cvars/cl_conxoffset-bd19b50/) | cvar | engine-client | Controls `cl_conXOffset` in the engine-client module. |
| [`cl_currentServerAddress`](/TaystJK/reference/cvars/cl_currentserveraddress-f6d6414/) | cvar | cgame | Controls `cl_currentServerAddress` in the cgame module. |
| [`cl_currentServerIP`](/TaystJK/reference/cvars/cl_currentserverip-18e40fb/) | cvar | engine-client | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_debugMove`](/TaystJK/reference/cvars/cl_debugmove-84599e2/) | cvar | engine-client | Controls `cl_debugMove` in the engine-client module. |
| [`cl_discordRichPresence`](/TaystJK/reference/cvars/cl_discordrichpresence-c4b29a5/) | cvar | engine-client | Allow/disallow sharing current game information on Discord profile status |
| [`cl_discordRichPresenceSharePassword`](/TaystJK/reference/cvars/cl_discordrichpresencesharepassword-79479cd/) | cvar | engine-client | If set, sends password to Discord friends who request to join your game |
| [`cl_downloadCount`](/TaystJK/reference/cvars/cl_downloadcount-1882f4f/) | cvar | engine-client | Controls `cl_downloadCount` in the engine-client module. |
| [`cl_downloadName`](/TaystJK/reference/cvars/cl_downloadname-eff2323/) | cvar | engine-client | Controls `cl_downloadName` in the engine-client module. |
| [`cl_downloadOverlay`](/TaystJK/reference/cvars/cl_downloadoverlay-ee4a68a/) | cvar | engine-client | Draw download info overlay |
| [`cl_downloadPrompt`](/TaystJK/reference/cvars/cl_downloadprompt-2444b92/) | cvar | engine-client | Confirm pk3 downloads from the server |
| [`cl_downloadProtocol`](/TaystJK/reference/cvars/cl_downloadprotocol-a36f359/) | cvar | engine-client | Report whether the active download uses HTTP or UDP. |
| [`cl_downloadSize`](/TaystJK/reference/cvars/cl_downloadsize-d836714/) | cvar | engine-client | Controls `cl_downloadSize` in the engine-client module. |
| [`cl_downloadTime`](/TaystJK/reference/cvars/cl_downloadtime-59d8294/) | cvar | engine-client | Controls `cl_downloadTime` in the engine-client module. |
| [`cl_enableGuid`](/TaystJK/reference/cvars/cl_enableguid-d5d42ac/) | cvar | engine-client | Enable GUID userinfo identifier |
| [`cl_exitCommand`](/TaystJK/reference/cvars/cl_exitcommand-0f11b0a/) | cvar | engine-shared | Enables the /exit command |
| [`cl_filterGames`](/TaystJK/reference/cvars/cl_filtergames-7e85224/) | cvar | engine-client | List of fs_game to filter (space separated) |
| [`cl_forceavidemo`](/TaystJK/reference/cvars/cl_forceavidemo-a2f9476/) | cvar | engine-client | Controls `cl_forceavidemo` in the engine-client module. |
| [`cl_framerate`](/TaystJK/reference/cvars/cl_framerate-6aed8d0/) | cvar | engine-client | Controls `cl_framerate` in the engine-client module. |
| [`cl_guidServerUniq`](/TaystJK/reference/cvars/cl_guidserveruniq-7e6d8fe/) | cvar | engine-client | Use a unique guid value per server |
| [`cl_idrive`](/TaystJK/reference/cvars/cl_idrive-a66b0b8/) | cvar | engine-client | Controls `cl_idrive` in the engine-client module. |
| [`cl_lanForcePackets`](/TaystJK/reference/cvars/cl_lanforcepackets-cafc4eb/) | cvar | engine-client | Controls `cl_lanForcePackets` in the engine-client module. |
| [`cl_logChat`](/TaystJK/reference/cvars/cl_logchat-5d53487/) | cvar | engine-client | Toggle engine chat logs |
| [`cl_maxPackets`](/TaystJK/reference/cvars/cl_maxpackets-7b738c4/) | cvar | engine-client | Controls `cl_maxPackets` in the engine-client module. |
| [`cl_motdServer1`](/TaystJK/reference/cvars/cl_motdserver1-a571b4a/) | cvar | engine-client | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_motdServer2`](/TaystJK/reference/cvars/cl_motdserver2-76b0c14/) | cvar | engine-client | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_motdString`](/TaystJK/reference/cvars/cl_motdstring-b47e754/) | cvar | engine-client | Controls `cl_motdString` in the engine-client module. |
| [`cl_mouseAccelOffset`](/TaystJK/reference/cvars/cl_mouseacceloffset-2ec97b6/) | cvar | engine-client | Mouse acceleration offset for style 1 |
| [`cl_mouseAccelStyle`](/TaystJK/reference/cvars/cl_mouseaccelstyle-fd1405e/) | cvar | engine-client | Mouse accelration style (0:legacy, 1:QuakeLive) |
| [`cl_nodelta`](/TaystJK/reference/cvars/cl_nodelta-8da8fc8/) | cvar | engine-client | Controls `cl_nodelta` in the engine-client module. |
| [`cl_noprint`](/TaystJK/reference/cvars/cl_noprint-26599b8/) | cvar | engine-client | Controls `cl_noprint` in the engine-client module. |
| [`cl_packetdup`](/TaystJK/reference/cvars/cl_packetdup-86b0e4b/) | cvar | engine-client | Controls `cl_packetdup` in the engine-client module. |
| [`cl_paused`](/TaystJK/reference/cvars/cl_paused-2461a17/) | cvar | cgame | Controls `cl_paused` in the cgame module. |
| [`cl_pitchspeed`](/TaystJK/reference/cvars/cl_pitchspeed-c2c603e/) | cvar | engine-client | Controls `cl_pitchspeed` in the engine-client module. |
| [`cl_ratioFix`](/TaystJK/reference/cvars/cl_ratiofix-67440df/) | cvar | engine-client | Widescreen aspect ratio correction |
| [`cl_reconnectArgs`](/TaystJK/reference/cvars/cl_reconnectargs-fbdecc0/) | cvar | engine-client | Arguments provided when last connecting to a server |
| [`cl_renderer`](/TaystJK/reference/cvars/cl_renderer-dc9f64f/) | cvar | engine-client | Which renderer library to use |
| [`cl_serverStatusResendTime`](/TaystJK/reference/cvars/cl_serverstatusresendtime-ffba1d7/) | cvar | engine-client | Controls `cl_serverStatusResendTime` in the engine-client module. |
| [`cl_showmouserate`](/TaystJK/reference/cvars/cl_showmouserate-09d0667/) | cvar | engine-client | Controls `cl_showMouseRate` in the engine-client module. |
| [`cl_shownet`](/TaystJK/reference/cvars/cl_shownet-85e342e/) | cvar | engine-client | Controls `cl_shownet` in the engine-client module. |
| [`cl_showSend`](/TaystJK/reference/cvars/cl_showsend-31c8ea4/) | cvar | engine-client | Controls `cl_showSend` in the engine-client module. |
| [`cl_showTimeDelta`](/TaystJK/reference/cvars/cl_showtimedelta-f5e0f42/) | cvar | engine-client | Controls `cl_showTimeDelta` in the engine-client module. |
| [`cl_timeNudge`](/TaystJK/reference/cvars/cl_timenudge-4435ccb/) | cvar | engine-client | Controls `cl_timeNudge` in the engine-client module. |
| [`cl_timenudgeDuration`](/TaystJK/reference/cvars/cl_timenudgeduration-676fa10/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cl_timeout`](/TaystJK/reference/cvars/cl_timeout-cc5e885/) | cvar | engine-client | Controls `cl_timeout` in the engine-client module. |
| [`cl_yawspeed`](/TaystJK/reference/cvars/cl_yawspeed-7102728/) | cvar | engine-client | Controls `cl_yawspeed` in the engine-client module. |
| [`cm_debugSize`](/TaystJK/reference/cvars/cm_debugsize-960fad0/) | cvar | engine-shared | Controls `cv` in the engine-shared module. |
| [`cm_extraVerbose`](/TaystJK/reference/cvars/cm_extraverbose-f870864/) | cvar | engine-shared | Controls `cm_extraVerbose` in the engine-shared module. |
| [`cm_noAreas`](/TaystJK/reference/cvars/cm_noareas-486fcb8/) | cvar | engine-shared | Controls `cm_noAreas` in the engine-shared module. |
| [`cm_noCurves`](/TaystJK/reference/cvars/cm_nocurves-7fbfdd9/) | cvar | engine-shared | Controls `cm_noCurves` in the engine-shared module. |
| [`cm_playerCurveClip`](/TaystJK/reference/cvars/cm_playercurveclip-ab37e03/) | cvar | engine-shared | Controls `cm_playerCurveClip` in the engine-shared module. |
| [`com_affinity`](/TaystJK/reference/cvars/com_affinity-f32bd34/) | cvar | engine-shared | Controls `com_affinity` in the engine-shared module. |
| [`com_ansiColor`](/TaystJK/reference/cvars/com_ansicolor-94ebdea/) | cvar | engine-shared | Controls `com_ansiColor` in the engine-shared module. |
| [`com_bootlogo`](/TaystJK/reference/cvars/com_bootlogo-4f85af0/) | cvar | engine-shared | Show intro movies |
| [`com_buildScript`](/TaystJK/reference/cvars/com_buildscript-4b0ed7d/) | cvar | cgame | Controls `com_buildScript` in the cgame module. |
| [`com_busyWait`](/TaystJK/reference/cvars/com_busywait-3e64dd5/) | cvar | engine-shared | Controls `com_busyWait` in the engine-shared module. |
| [`com_cameraMode`](/TaystJK/reference/cvars/com_cameramode-83e70f2/) | cvar | cgame | Controls `com_cameraMode` in the cgame module. |
| [`com_G2Report`](/TaystJK/reference/cvars/com_g2report-5cb35fa/) | cvar | engine-shared | Controls `com_G2Report` in the engine-shared module. |
| [`com_homepath`](/TaystJK/reference/cvars/com_homepath-79625df/) | cvar | engine-shared | Controls `com_homepath` in the engine-shared module. |
| [`com_journal`](/TaystJK/reference/cvars/com_journal-72422f1/) | cvar | engine-shared | Controls `com_journal` in the engine-shared module. |
| [`com_legacyprotocol`](/TaystJK/reference/cvars/com_legacyprotocol-f7ec076/) | cvar | engine-client | 1.00 protocol |
| [`com_maxfpsMinimized`](/TaystJK/reference/cvars/com_maxfpsminimized-ee39c66/) | cvar | engine-shared | Controls `com_maxfpsMinimized` in the engine-shared module. |
| [`com_maxfpsUnfocused`](/TaystJK/reference/cvars/com_maxfpsunfocused-888b9d8/) | cvar | engine-shared | Controls `com_maxfpsUnfocused` in the engine-shared module. |
| [`com_minimized`](/TaystJK/reference/cvars/com_minimized-fa62f52/) | cvar | engine-shared | Controls `com_minimized` in the engine-shared module. |
| [`com_optvehtrace`](/TaystJK/reference/cvars/com_optvehtrace-690075a/) | cvar | cgame | Controls `com_optvehtrace` in the cgame module. |
| [`com_priority`](/TaystJK/reference/cvars/com_priority-cac1576/) | cvar | engine-shared | Duno, -1 = do nothing, 1 = low priority, 2 = normal priority, 3 = high priority? i guess?? |
| [`com_protocol`](/TaystJK/reference/cvars/com_protocol-2cc2e0a/) | cvar | engine-client | 1.01 protocol |
| [`com_renderfps`](/TaystJK/reference/cvars/com_renderfps-485cbcb/) | cvar | engine-shared | Controls `com_renderfps` in the engine-shared module. |
| [`com_showtrace`](/TaystJK/reference/cvars/com_showtrace-0461442/) | cvar | engine-shared | Controls `com_showtrace` in the engine-shared module. |
| [`com_speeds`](/TaystJK/reference/cvars/com_speeds-19c0e9f/) | cvar | engine-shared | Controls `com_speeds` in the engine-shared module. |
| [`com_steamIntegration`](/TaystJK/reference/cvars/com_steamintegration-01ca9bb/) | cvar | engine-shared | Enables automatic Steam API integration (requires a steam_api64.dll to be in GameData) |
| [`com_timestamps`](/TaystJK/reference/cvars/com_timestamps-e16da1a/) | cvar | engine-shared | Show timestamps in terminal and qconsole.log |
| [`com_unfocused`](/TaystJK/reference/cvars/com_unfocused-804c4c7/) | cvar | engine-shared | Controls `com_unfocused` in the engine-shared module. |
| [`com_unpackLibraries`](/TaystJK/reference/cvars/com_unpacklibraries-27a5b09/) | cvar | engine-shared | Controls `com_unpackLibraries` in the engine-shared module. |
| [`com_validateZone`](/TaystJK/reference/cvars/com_validatezone-d30815f/) | cvar | engine-shared | Controls `com_validateZone` in the engine-shared module. |
| [`com_waitingForKey`](/TaystJK/reference/cvars/com_waitingforkey-4980251/) | cvar | engine-shared | Controls `com_waitingForKey` in the engine-shared module. |
| [`con_autoclear`](/TaystJK/reference/cvars/con_autoclear-ff60e4c/) | cvar | engine-client | Automatically clear console input on close |
| [`con_datetime`](/TaystJK/reference/cvars/con_datetime-fb79998/) | cvar | engine-client | Display human readable date/time in console |
| [`con_notifyconnect`](/TaystJK/reference/cvars/con_notifyconnect-0a48d2d/) | cvar | engine-client | Notifies you when someone connects to the server |
| [`con_notifylines`](/TaystJK/reference/cvars/con_notifylines-6373d07/) | cvar | engine-client | Max number of console lines to print in top left |
| [`con_notifyvote`](/TaystJK/reference/cvars/con_notifyvote-05d6ee1/) | cvar | engine-client | Notifies you when someone calls a vote |
| [`con_notifywords`](/TaystJK/reference/cvars/con_notifywords-97dfc24/) | cvar | engine-client | Notifies you when defined words are mentioned |
| [`con_opacity`](/TaystJK/reference/cvars/con_opacity-d0e065e/) | cvar | engine-client | Opacity of console background |
| [`con_ratioFix`](/TaystJK/reference/cvars/con_ratiofix-64c8547/) | cvar | engine-client | Correct console background height, should probably disable for custom console backgrounds. |
| [`con_timestamps`](/TaystJK/reference/cvars/con_timestamps-2b4f0eb/) | cvar | engine-client | Display timestamps infront of console lines |
| [`cp_clanPwd`](/TaystJK/reference/cvars/cp_clanpwd-ca86ca9/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cp_cosmetics`](/TaystJK/reference/cvars/cp_cosmetics-488f751/) | cvar | cgame | Controls `cp_cosmetics` in the cgame module. |
| [`cp_pluginDisable`](/TaystJK/reference/cvars/cp_plugindisable-715762d/) | cvar | cgame | 'enable' holstered saber (512) and ledge grab (1536) by default, to avoid missing JA+ animations |
| [`cp_sbRGB1`](/TaystJK/reference/cvars/cp_sbrgb1-0369930/) | cvar | cgame | Controls `cp_sbRGB1` in the cgame module. |
| [`cp_sbRGB2`](/TaystJK/reference/cvars/cp_sbrgb2-81b016f/) | cvar | cgame | Controls `cp_sbRGB2` in the cgame module. |
| [`currentObjMapIconBackground`](/TaystJK/reference/cvars/currentobjmapiconbackground-748291d/) | cvar | ui | Controls `currentObjMapIconBackground` in the ui module. |
| [`currentObjMapIconItem`](/TaystJK/reference/cvars/currentobjmapiconitem-c57cd4a/) | cvar | ui | Controls `currentObjMapIconItem` in the ui module. |
| [`d_altRoutes`](/TaystJK/reference/cvars/d_altroutes-c57e072/) | cvar | game | Controls `d_altRoutes` in the game module. |
| [`d_asynchronousGroupAI`](/TaystJK/reference/cvars/d_asynchronousgroupai-fccc4e1/) | cvar | game | Controls `d_asynchronousGroupAI` in the game module. |
| [`d_break`](/TaystJK/reference/cvars/d_break-eaf2fa0/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_JediAI`](/TaystJK/reference/cvars/d_jediai-6689f4f/) | cvar | game | Controls `d_JediAI` in the game module. |
| [`d_noGroupAI`](/TaystJK/reference/cvars/d_nogroupai-47246c1/) | cvar | game | Controls `d_noGroupAI` in the game module. |
| [`d_noIntermissionWait`](/TaystJK/reference/cvars/d_nointermissionwait-961a829/) | cvar | game | Controls `d_noIntermissionWait` in the game module. |
| [`d_noroam`](/TaystJK/reference/cvars/d_noroam-44d534c/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_npcai`](/TaystJK/reference/cvars/d_npcai-d1346e9/) | cvar | game | Controls `d_npcai` in the game module. |
| [`d_npcaiming`](/TaystJK/reference/cvars/d_npcaiming-3221a7b/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_npcfreeze`](/TaystJK/reference/cvars/d_npcfreeze-0300949/) | cvar | game | Controls `d_npcfreeze` in the game module. |
| [`d_patched`](/TaystJK/reference/cvars/d_patched-c172442/) | cvar | game | Controls `d_patched` in the game module. |
| [`d_perPlayerGhoul2`](/TaystJK/reference/cvars/d_perplayerghoul2-9292fd8/) | cvar | game | Controls `d_perPlayerGhoul2` in the game module. |
| [`d_powerDuelPrint`](/TaystJK/reference/cvars/d_powerduelprint-0db3ba4/) | cvar | game | Controls `d_powerDuelPrint` in the game module. |
| [`d_projectileGhoul2Collision`](/TaystJK/reference/cvars/d_projectileghoul2collision-6d3853e/) | cvar | game | Controls `d_projectileGhoul2Collision` in the game module. |
| [`d_saberAlwaysBoxTrace`](/TaystJK/reference/cvars/d_saberalwaysboxtrace-3a56bc8/) | cvar | game | Controls `d_saberAlwaysBoxTrace` in the game module. |
| [`d_saberBoxTraceSize`](/TaystJK/reference/cvars/d_saberboxtracesize-3dfdf82/) | cvar | game | Controls `d_saberBoxTraceSize` in the game module. |
| [`d_saberCombat`](/TaystJK/reference/cvars/d_sabercombat-ad98941/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_saberGhoul2Collision`](/TaystJK/reference/cvars/d_saberghoul2collision-2081f36/) | cvar | game | Controls `d_saberGhoul2Collision` in the game module. |
| [`d_saberInterpolate`](/TaystJK/reference/cvars/d_saberinterpolate-98af971/) | cvar | game | Controls `d_saberInterpolate` in the game module. |
| [`d_saberKickTweak`](/TaystJK/reference/cvars/d_saberkicktweak-1706de8/) | cvar | game | Controls `d_saberKickTweak` in the game module. |
| [`d_saberStanceDebug`](/TaystJK/reference/cvars/d_saberstancedebug-9609018/) | cvar | game | Controls `d_saberStanceDebug` in the game module. |
| [`d_siegeSeekerNPC`](/TaystJK/reference/cvars/d_siegeseekernpc-7419e17/) | cvar | game | Controls `d_siegeSeekerNPC` in the game module. |
| [`debug_protocol`](/TaystJK/reference/cvars/debug_protocol-51b58be/) | cvar | ui | Controls `debug_protocol` in the ui module. |
| [`debugBB`](/TaystJK/reference/cvars/debugbb-1d5d0a8/) | cvar | cgame | Controls `debugBB` in the cgame module. |
| [`debuggraph`](/TaystJK/reference/cvars/debuggraph-8bd94d1/) | cvar | engine-client | Controls `cl_debuggraph` in the engine-client module. |
| [`dedicated`](/TaystJK/reference/cvars/dedicated-0d30712/) | cvar | game | Controls `dedicated` in the game module. |
| [`disco`](/TaystJK/reference/cvars/disco-9a1c2a6/) | cvar | cgame | Controls `disco` in the cgame module. |
| [`dmflags`](/TaystJK/reference/cvars/dmflags-9484c55/) | cvar | game | Controls `dmflags` in the game module. |
| [`duel_fraglimit`](/TaystJK/reference/cvars/duel_fraglimit-5cd7d2a/) | cvar | game | Controls `duel_fraglimit` in the game module. |
| [`fixedtime`](/TaystJK/reference/cvars/fixedtime-30e21eb/) | cvar | engine-shared | Controls `com_fixedtime` in the engine-shared module. |
| [`fraglimit`](/TaystJK/reference/cvars/fraglimit-0b2d675/) | cvar | game | Controls `fraglimit` in the game module. |
| [`fs_apppath`](/TaystJK/reference/cvars/fs_apppath-eaa658c/) | cvar | engine-shared | (Read Only) Location of OSX .app bundle |
| [`fs_basegame`](/TaystJK/reference/cvars/fs_basegame-34b9b3a/) | cvar | engine-shared | Controls `fs_basegame` in the engine-shared module. |
| [`fs_copyfiles`](/TaystJK/reference/cvars/fs_copyfiles-d93a4a0/) | cvar | engine-shared | Controls `fs_copyfiles` in the engine-shared module. |
| [`fs_debug`](/TaystJK/reference/cvars/fs_debug-bfc2f15/) | cvar | engine-shared | Controls `fs_debug` in the engine-shared module. |
| [`fx_countScale`](/TaystJK/reference/cvars/fx_countscale-467322f/) | cvar | engine-client | Controls `fx_countScale` in the engine-client module. |
| [`fx_debug`](/TaystJK/reference/cvars/fx_debug-b5dd314/) | cvar | engine-client | Controls `fx_debug` in the engine-client module. |
| [`fx_freeze`](/TaystJK/reference/cvars/fx_freeze-e0afc73/) | cvar | engine-client | Controls `fx_freeze` in the engine-client module. |
| [`fx_nearCull`](/TaystJK/reference/cvars/fx_nearcull-19f1396/) | cvar | engine-client | Controls `fx_nearCull` in the engine-client module. |
| [`fx_physics`](/TaystJK/reference/cvars/fx_physics-6ce403e/) | cvar | engine-client | Controls physics applied to FX system particles - 0: Disable all FX physics - 1: use non-expensive physics only - 2: Use flags in the fx file (Default behavior) - 3: Force expensive physics on all particles |
| [`g_adaptRespawn`](/TaystJK/reference/cvars/g_adaptrespawn-48b0aed/) | cvar | game | Controls `g_adaptRespawn` in the game module. |
| [`g_allowDuelSuicide`](/TaystJK/reference/cvars/g_allowduelsuicide-4945a44/) | cvar | game | Controls `g_allowDuelSuicide` in the game module. |
| [`g_allowFlagThrow`](/TaystJK/reference/cvars/g_allowflagthrow-a034db8/) | cvar | game | Allow use of /throwflag command. |
| [`g_allowGrapple`](/TaystJK/reference/cvars/g_allowgrapple-4e7510c/) | cvar | game | 1=Tarzan style. 2=JA+ Style. |
| [`g_allowGunDuel`](/TaystJK/reference/cvars/g_allowgunduel-ac581ff/) | cvar | game | Controls `g_allowGunDuel` in the game module. |
| [`g_allowHighPingDuelist`](/TaystJK/reference/cvars/g_allowhighpingduelist-963519a/) | cvar | game | Controls `g_allowHighPingDuelist` in the game module. |
| [`g_allowNoFollow`](/TaystJK/reference/cvars/g_allownofollow-6efa2b1/) | cvar | game | Allow players to hide themselves and not be spectated/seen in racemode. |
| [`g_allowNPC`](/TaystJK/reference/cvars/g_allownpc-d36f098/) | cvar | game | Controls `g_allowNPC` in the game module. |
| [`g_allowRaceTele`](/TaystJK/reference/cvars/g_allowracetele-7aca7fe/) | cvar | game | 1=Allow amtele in racemode. 2=Also allow noclip. |
| [`g_allowRegistration`](/TaystJK/reference/cvars/g_allowregistration-45f9f37/) | cvar | game | Controls `g_allowRegistration` in the game module. |
| [`g_allowSaberSwitch`](/TaystJK/reference/cvars/g_allowsaberswitch-474c34a/) | cvar | game | Controls `g_allowSaberSwitch` in the game module. |
| [`g_allowSamePlayerNames`](/TaystJK/reference/cvars/g_allowsameplayernames-adac81f/) | cvar | game | Controls `g_allowSamePlayerNames` in the game module. |
| [`g_allowSpotting`](/TaystJK/reference/cvars/g_allowspotting-88ae036/) | cvar | game | Controls `g_allowSpotting` in the game module. |
| [`g_allowTargetLaser`](/TaystJK/reference/cvars/g_allowtargetlaser-61aa826/) | cvar | game | Target laser used with +button14 |
| [`g_allowTeamSuicide`](/TaystJK/reference/cvars/g_allowteamsuicide-5e88a75/) | cvar | game | Controls `g_allowTeamSuicide` in the game module. |
| [`g_allowTeamVote`](/TaystJK/reference/cvars/g_allowteamvote-d6b1ddf/) | cvar | game | Controls `g_allowTeamVote` in the game module. |
| [`g_allowUseInDuel`](/TaystJK/reference/cvars/g_allowuseinduel-c53aead/) | cvar | game | Controls `g_allowUseInDuel` in the game module. |
| [`g_allowVGS`](/TaystJK/reference/cvars/g_allowvgs-cbfffd9/) | cvar | game | Controls `g_allowVGS` in the game module. |
| [`g_allowVote`](/TaystJK/reference/cvars/g_allowvote-fdda916/) | cvar | game | Controls `g_allowVote` in the game module. |
| [`g_antiFakePlayer`](/TaystJK/reference/cvars/g_antifakeplayer-eae051b/) | cvar | game | Controls `g_antiFakePlayer` in the game module. |
| [`g_antiWallhack`](/TaystJK/reference/cvars/g_antiwallhack-2d80c78/) | cvar | game | Experimental anti wallhack code. Use the client plugin so it can tell the server where your camera position is, and if you use 3rd person. |
| [`g_armBreakage`](/TaystJK/reference/cvars/g_armbreakage-8d44482/) | cvar | game | Controls `g_armBreakage` in the game module. |
| [`g_austrian`](/TaystJK/reference/cvars/g_austrian-ebbf80f/) | cvar | game | Controls `g_austrian` in the game module. |
| [`g_autoMapCycle`](/TaystJK/reference/cvars/g_automapcycle-2b9887f/) | cvar | game | Controls `g_autoMapCycle` in the game module. |
| [`g_autoQuit`](/TaystJK/reference/cvars/g_autoquit-bc06a6f/) | cvar | game | Controls `g_autoQuit` in the game module. |
| [`g_backslashDamageScale`](/TaystJK/reference/cvars/g_backslashdamagescale-4775681/) | cvar | game | Controls `g_backslashDamageScale` in the game module. |
| [`g_banIPs`](/TaystJK/reference/cvars/g_banips-5693b4b/) | cvar | game | Controls `g_banIPs` in the game module. |
| [`g_blockDuelHealthSpec`](/TaystJK/reference/cvars/g_blockduelhealthspec-40519eb/) | cvar | game | Don't show duelers health to people in spectate. |
| [`g_blueDamageScale`](/TaystJK/reference/cvars/g_bluedamagescale-409fea4/) | cvar | game | Controls `g_blueDamageScale` in the game module. |
| [`g_botsFile`](/TaystJK/reference/cvars/g_botsfile-8fb6936/) | cvar | game | Controls `botsFile` in the game module. |
| [`g_centerMOTD`](/TaystJK/reference/cvars/g_centermotd-2a208ad/) | cvar | game | Controls `g_centerMOTD` in the game module. |
| [`g_centerMOTDTime`](/TaystJK/reference/cvars/g_centermotdtime-c0742ef/) | cvar | game | Controls `g_centerMOTDTime` in the game module. |
| [`g_charRestrictRGB`](/TaystJK/reference/cvars/g_charrestrictrgb-9c843ad/) | cvar | game | Controls `g_charRestrictRGB` in the game module. |
| [`g_consoleMOTD`](/TaystJK/reference/cvars/g_consolemotd-62e668c/) | cvar | game | Controls `g_consoleMOTD` in the game module. |
| [`g_corpseRemovalTime`](/TaystJK/reference/cvars/g_corpseremovaltime-1c8df23/) | cvar | game | Controls `g_corpseRemovalTime` in the game module. |
| [`g_damageNumbers`](/TaystJK/reference/cvars/g_damagenumbers-134f14c/) | cvar | game | 1-7. Controls different types of damagenumber printouts. |
| [`g_debugAlloc`](/TaystJK/reference/cvars/g_debugalloc-f84f0d3/) | cvar | game | Controls `g_debugAlloc` in the game module. |
| [`g_debugDamage`](/TaystJK/reference/cvars/g_debugdamage-4185007/) | cvar | game | Controls `g_debugDamage` in the game module. |
| [`g_debugMelee`](/TaystJK/reference/cvars/g_debugmelee-cf2d02e/) | cvar | game | Controls `g_debugMelee` in the game module. |
| [`g_debugMove`](/TaystJK/reference/cvars/g_debugmove-9478efa/) | cvar | game | Controls `g_debugMove` in the game module. |
| [`g_debugSaberLocks`](/TaystJK/reference/cvars/g_debugsaberlocks-38c74dd/) | cvar | game | Controls `g_debugSaberLocks` in the game module. |
| [`g_debugServerSkel`](/TaystJK/reference/cvars/g_debugserverskel-10f12d9/) | cvar | game | Controls `g_debugServerSkel` in the game module. |
| [`g_disableServerG2`](/TaystJK/reference/cvars/g_disableserverg2-d981ab3/) | cvar | game | Controls `g_disableServerG2` in the game module. |
| [`g_dismember`](/TaystJK/reference/cvars/g_dismember-209a737/) | cvar | game | Controls `g_dismember` in the game module. |
| [`g_doWarmup`](/TaystJK/reference/cvars/g_dowarmup-9a8d9cc/) | cvar | game | Controls `g_doWarmup` in the game module. |
| [`g_duelDistanceLimit`](/TaystJK/reference/cvars/g_dueldistancelimit-9422409/) | cvar | game | Controls `g_duelDistanceLimit` in the game module. |
| [`g_duelLog`](/TaystJK/reference/cvars/g_duellog-0286077/) | cvar | game | Log to duels.log. |
| [`g_duelRespawn`](/TaystJK/reference/cvars/g_duelrespawn-0acb1c8/) | cvar | game | Automatically respawn players to where they died after losing a duel. |
| [`g_duelStartArmor`](/TaystJK/reference/cvars/g_duelstartarmor-56fbd3c/) | cvar | game | Controls `g_duelStartArmor` in the game module. |
| [`g_duelStartHealth`](/TaystJK/reference/cvars/g_duelstarthealth-8a98d72/) | cvar | game | Controls `g_duelStartHealth` in the game module. |
| [`g_duelWeaponDisable`](/TaystJK/reference/cvars/g_duelweapondisable-a038b8f/) | cvar | game | Controls `g_duelWeaponDisable` in the game module. |
| [`g_eloKValue1`](/TaystJK/reference/cvars/g_elokvalue1-29f4799/) | cvar | game | Controls `g_eloKValue1` in the game module. |
| [`g_eloKValue2`](/TaystJK/reference/cvars/g_elokvalue2-2c17376/) | cvar | game | Controls `g_eloKValue2` in the game module. |
| [`g_eloKValue3`](/TaystJK/reference/cvars/g_elokvalue3-e6ddcc0/) | cvar | game | Controls `g_eloKValue3` in the game module. |
| [`g_eloMinimumDuels`](/TaystJK/reference/cvars/g_elominimumduels-b90832e/) | cvar | game | Controls `g_eloMinimumDuels` in the game module. |
| [`g_eloNewUserCutoff`](/TaystJK/reference/cvars/g_elonewusercutoff-7843ba4/) | cvar | game | Controls `g_eloNewUserCutoff` in the game module. |
| [`g_eloProvisionalChangeBig`](/TaystJK/reference/cvars/g_eloprovisionalchangebig-990945a/) | cvar | game | Controls `g_eloProvisionalChangeBig` in the game module. |
| [`g_eloProvisionalChangeSmall`](/TaystJK/reference/cvars/g_eloprovisionalchangesmall-a70e34f/) | cvar | game | Controls `g_eloProvisionalChangeSmall` in the game module. |
| [`g_eloProvisionalCutoff`](/TaystJK/reference/cvars/g_eloprovisionalcutoff-429129e/) | cvar | game | Controls `g_eloProvisionalCutoff` in the game module. |
| [`g_eloRanking`](/TaystJK/reference/cvars/g_eloranking-b050319/) | cvar | game | Enables the built in elo ranking for duels. |
| [`g_emotesDisable`](/TaystJK/reference/cvars/g_emotesdisable-8df1bb9/) | cvar | game | Configured with /toggleEmotes command |
| [`g_fakeClients`](/TaystJK/reference/cvars/g_fakeclients-381934a/) | cvar | game | Controls `g_fakeClients` in the game module. |
| [`g_ff_objectives`](/TaystJK/reference/cvars/g_ff_objectives-5800a9a/) | cvar | game | Controls `g_ff_objectives` in the game module. |
| [`g_filterBan`](/TaystJK/reference/cvars/g_filterban-1aadd85/) | cvar | game | Controls `g_filterBan` in the game module. |
| [`g_fixCTFScores`](/TaystJK/reference/cvars/g_fixctfscores-f3e8d8d/) | cvar | game | Tweak CTF score amounts. |
| [`g_fixFlagHitbox`](/TaystJK/reference/cvars/g_fixflaghitbox-93e20c3/) | cvar | game | Controls `g_fixFlagHitbox` in the game module. |
| [`g_fixFlagSuicide`](/TaystJK/reference/cvars/g_fixflagsuicide-f382dc6/) | cvar | game | Don't auto return flag when flag carrier suicides. |
| [`g_fixGetups`](/TaystJK/reference/cvars/g_fixgetups-987e065/) | cvar | game | 1=Allow grip during knockdown recovery. 2=Allow grip/push/pull during knockdown recovery. |
| [`g_fixGroundStab`](/TaystJK/reference/cvars/g_fixgroundstab-414db0a/) | cvar | game | 1=Groundstabs damage players on ground. 2=Groundstabs damage players on ground but with reduced damage. |
| [`g_fixHighFPSAbuse`](/TaystJK/reference/cvars/g_fixhighfpsabuse-1f4cf8c/) | cvar | game | Make players who have more than 250fps behave at 250fps physics. |
| [`g_fixKillCredit`](/TaystJK/reference/cvars/g_fixkillcredit-250953f/) | cvar | game | 1=Award kill credit after target suicides/spectates. 2=Also for disconnects/reconnects. |
| [`g_fixLightning`](/TaystJK/reference/cvars/g_fixlightning-a145552/) | cvar | game | 1=Lightning gives forcepoints to target. 2=Same as 1 with reduced damage. 3=Same as 2 with no melee bonus. |
| [`g_fixPlayerCollision`](/TaystJK/reference/cvars/g_fixplayercollision-c0ccf93/) | cvar | game | Controls `g_fixPlayerCollision` in the game module. |
| [`g_fixRoll`](/TaystJK/reference/cvars/g_fixroll-09a4b25/) | cvar | game | 1=JA+ style base roll. //2=Chainable roll. //3=JK2 style roll. |
| [`g_fixRunWalkAnims`](/TaystJK/reference/cvars/g_fixrunwalkanims-47abdcb/) | cvar | game | Controls `g_fixRunWalkAnims` in the game module. |
| [`g_fixSaberDisarmBonus`](/TaystJK/reference/cvars/g_fixsaberdisarmbonus-d84721a/) | cvar | game | Controls `g_fixSaberDisarmBonus` in the game module. |
| [`g_fixSaberInGrip`](/TaystJK/reference/cvars/g_fixsaberingrip-b95f6ac/) | cvar | game | 1=Grip does not turn off lightsaber. 2=Same as 1 and also target can toggle lightsaber in grip. 3=Same as 2 and also target can switch saberstyle in grip. |
| [`g_fixSaberMoveData`](/TaystJK/reference/cvars/g_fixsabermovedata-4619480/) | cvar | game | Controls `g_fixSaberMoveData` in the game module. |
| [`g_fixSlidePhysics`](/TaystJK/reference/cvars/g_fixslidephysics-b4eea18/) | cvar | game | 1=Fixed slide physics for NPCS. 2=Fixed slide physics for NPCs and players. |
| [`g_fixTimerOOB`](/TaystJK/reference/cvars/g_fixtimeroob-b9f687d/) | cvar | game | Controls `g_fixTimerOOB` in the game module. |
| [`g_fixWeaponAttackAnim`](/TaystJK/reference/cvars/g_fixweaponattackanim-fc108b3/) | cvar | game | Controls `g_fixWeaponAttackAnim` in the game module. |
| [`g_flagDrag`](/TaystJK/reference/cvars/g_flagdrag-88dcb4b/) | cvar | game | Add air friction to flag carrier. |
| [`g_flipKick`](/TaystJK/reference/cvars/g_flipkick-64576b3/) | cvar | game | 1=JA+ style. 2=Floodprotected to one kick every 50ms. 3=JK2 style. |
| [`g_flipKickDamageScale`](/TaystJK/reference/cvars/g_flipkickdamagescale-7c4913a/) | cvar | game | Controls `g_flipKickDamageScale` in the game module. |
| [`g_forceBasedTeams`](/TaystJK/reference/cvars/g_forcebasedteams-349b27a/) | cvar | game | Controls `g_forceBasedTeams` in the game module. |
| [`g_forceClientUpdateRate`](/TaystJK/reference/cvars/g_forceclientupdaterate-1c32854/) | cvar | game | Controls `g_forceClientUpdateRate` in the game module. |
| [`g_forceDodge`](/TaystJK/reference/cvars/g_forcedodge-48cc6f3/) | cvar | game | Controls `g_forceDodge` in the game module. |
| [`g_forceDrainDamage`](/TaystJK/reference/cvars/g_forcedraindamage-9a8a567/) | cvar | game | Controls `g_forceDrainDamage` in the game module. |
| [`g_forceDrainRestartDelay`](/TaystJK/reference/cvars/g_forcedrainrestartdelay-6b31ed4/) | cvar | game | Controls `g_forceDrainRestartDelay` in the game module. |
| [`g_forceDrainSelfRegenDelay`](/TaystJK/reference/cvars/g_forcedrainselfregendelay-9759e5d/) | cvar | game | Controls `g_forceDrainSelfRegenDelay` in the game module. |
| [`g_forceDrainTargetRegenDelay`](/TaystJK/reference/cvars/g_forcedraintargetregendelay-716a0ec/) | cvar | game | Controls `g_forceDrainTargetRegenDelay` in the game module. |
| [`g_forceDuelForceRegenTime`](/TaystJK/reference/cvars/g_forceduelforceregentime-6121a0c/) | cvar | game | Controls `g_forceDuelForceRegenTime` in the game module. |
| [`g_forceDuelSPDamage`](/TaystJK/reference/cvars/g_forceduelspdamage-6899daf/) | cvar | game | Toggle use of SP style damage in force duels. |
| [`g_forceLogin`](/TaystJK/reference/cvars/g_forcelogin-19fc6bd/) | cvar | game | 1=Force players to login in order to be ingame. 2=also block them from chatting until logging in. 3=also block them from renaming until logging in. |
| [`g_forcePowerDisable`](/TaystJK/reference/cvars/g_forcepowerdisable-370e0a6/) | cvar | game | Controls `g_forcePowerDisable` in the game module. |
| [`g_forcePowerDisableFFA`](/TaystJK/reference/cvars/g_forcepowerdisableffa-6942638/) | cvar | game | Controls `g_forcePowerDisableFFA` in the game module. |
| [`g_forceRegenTime`](/TaystJK/reference/cvars/g_forceregentime-6e2c86f/) | cvar | game | Controls `g_forceRegenTime` in the game module. |
| [`g_forceRespawn`](/TaystJK/reference/cvars/g_forcerespawn-ad887df/) | cvar | game | Controls `g_forceRespawn` in the game module. |
| [`g_fraglimitVoteCorrection`](/TaystJK/reference/cvars/g_fraglimitvotecorrection-2977f70/) | cvar | game | Controls `g_fraglimitVoteCorrection` in the game module. |
| [`g_friendlyFire`](/TaystJK/reference/cvars/g_friendlyfire-e3552b6/) | cvar | game | Controls `g_friendlyFire` in the game module. |
| [`g_friendlySaber`](/TaystJK/reference/cvars/g_friendlysaber-a3dc40b/) | cvar | game | Controls `g_friendlySaber` in the game module. |
| [`g_fullAdminLevel`](/TaystJK/reference/cvars/g_fulladminlevel-baac21c/) | cvar | game | Controls `g_fullAdminLevel` in the game module. |
| [`g_fullAdminMsg`](/TaystJK/reference/cvars/g_fulladminmsg-a1df874/) | cvar | game | Controls `g_fullAdminMsg` in the game module. |
| [`g_fullAdminPass`](/TaystJK/reference/cvars/g_fulladminpass-11858c2/) | cvar | game | Controls `g_fullAdminPass` in the game module. |
| [`g_fullInheritance`](/TaystJK/reference/cvars/g_fullinheritance-fb4c838/) | cvar | game | Scale of all player momentum gained by projectiles. |
| [`g_g2TraceLod`](/TaystJK/reference/cvars/g_g2tracelod-5bdfdfd/) | cvar | game | Controls `g_g2TraceLod` in the game module. |
| [`g_glitchKickDamage`](/TaystJK/reference/cvars/g_glitchkickdamage-381e14c/) | cvar | game | Controls `g_glitchKickDamage` in the game module. |
| [`g_godChat`](/TaystJK/reference/cvars/g_godchat-b1ca3c4/) | cvar | game | Controls `g_godChat` in the game module. |
| [`g_gravity`](/TaystJK/reference/cvars/g_gravity-8571dee/) | cvar | game | Controls `g_gravity` in the game module. |
| [`g_gunGame`](/TaystJK/reference/cvars/g_gungame-0b95542/) | cvar | game | Controls `g_gunGame` in the game module. |
| [`g_hookFloodProtect`](/TaystJK/reference/cvars/g_hookfloodprotect-882bcc8/) | cvar | game | Milliseconds between hook shots |
| [`g_hookInheritance`](/TaystJK/reference/cvars/g_hookinheritance-d65c1d8/) | cvar | game | Controls `g_hookInheritance` in the game module. |
| [`g_hookSpeed`](/TaystJK/reference/cvars/g_hookspeed-4804994/) | cvar | game | Speed that grapple hook travels at |
| [`g_hookStrength`](/TaystJK/reference/cvars/g_hookstrength-fc0d002/) | cvar | game | Speed that grapple pulls you at |
| [`g_hookStrength1`](/TaystJK/reference/cvars/g_hookstrength1-e5b30e7/) | cvar | game | Controls `g_hookStrength1` in the game module. |
| [`g_hookStrength2`](/TaystJK/reference/cvars/g_hookstrength2-5d40a55/) | cvar | game | Controls `g_hookStrength2` in the game module. |
| [`g_inactivity`](/TaystJK/reference/cvars/g_inactivity-ff5f46f/) | cvar | game | Controls `g_inactivity` in the game module. |
| [`g_jediVmerc`](/TaystJK/reference/cvars/g_jedivmerc-0e45262/) | cvar | game | Controls `g_jediVmerc` in the game module. |
| [`g_juniorAdminLevel`](/TaystJK/reference/cvars/g_junioradminlevel-0881d19/) | cvar | game | Controls `g_juniorAdminLevel` in the game module. |
| [`g_juniorAdminMsg`](/TaystJK/reference/cvars/g_junioradminmsg-60177a9/) | cvar | game | Controls `g_juniorAdminMsg` in the game module. |
| [`g_juniorAdminPass`](/TaystJK/reference/cvars/g_junioradminpass-f2dc6ae/) | cvar | game | Controls `g_juniorAdminPass` in the game module. |
| [`g_knockback`](/TaystJK/reference/cvars/g_knockback-bd8fbb6/) | cvar | game | Controls `g_knockback` in the game module. |
| [`g_KOTH`](/TaystJK/reference/cvars/g_koth-67b50a0/) | cvar | game | Controls `g_KOTH` in the game module. |
| [`g_lagIcon`](/TaystJK/reference/cvars/g_lagicon-b8483ff/) | cvar | game | Controls `g_lagIcon` in the game module. |
| [`g_LegDangle`](/TaystJK/reference/cvars/g_legdangle-499ee3b/) | cvar | game | Toggle the leg dangle animation which is not predicted and results in jerkyness on ledges with high ping. |
| [`g_locationBasedDamage`](/TaystJK/reference/cvars/g_locationbaseddamage-f99568b/) | cvar | game | Controls `g_locationBasedDamage` in the game module. |
| [`g_log`](/TaystJK/reference/cvars/g_log-f2fc3fb/) | cvar | game | Controls `g_log` in the game module. |
| [`g_logClientInfo`](/TaystJK/reference/cvars/g_logclientinfo-53d26bc/) | cvar | game | Controls `g_logClientInfo` in the game module. |
| [`g_logSync`](/TaystJK/reference/cvars/g_logsync-d545359/) | cvar | game | Controls `g_logSync` in the game module. |
| [`g_maxConnPerIP`](/TaystJK/reference/cvars/g_maxconnperip-714b0e2/) | cvar | game | Controls `g_maxConnPerIP` in the game module. |
| [`g_maxFallDmg`](/TaystJK/reference/cvars/g_maxfalldmg-e8af044/) | cvar | game | Controls `g_maxFallDmg` in the game module. |
| [`g_maxForceRank`](/TaystJK/reference/cvars/g_maxforcerank-6e1aa63/) | cvar | game | Controls `g_maxForceRank` in the game module. |
| [`g_maxGameClients`](/TaystJK/reference/cvars/g_maxgameclients-5050424/) | cvar | game | Controls `g_maxGameClients` in the game module. |
| [`g_maxHolocronCarry`](/TaystJK/reference/cvars/g_maxholocroncarry-00643fd/) | cvar | game | Controls `g_maxHolocronCarry` in the game module. |
| [`g_maxSaberDefense`](/TaystJK/reference/cvars/g_maxsaberdefense-6bba186/) | cvar | game | -1 disables, 0/1/2/3 enables and clamps level |
| [`g_mercyRule`](/TaystJK/reference/cvars/g_mercyrule-186f0be/) | cvar | game | If the difference is greater than X percent of the frag limit... then end match. |
| [`g_motd`](/TaystJK/reference/cvars/g_motd-6d67b6c/) | cvar | game | Controls `g_motd` in the game module. |
| [`g_movementStyle`](/TaystJK/reference/cvars/g_movementstyle-cf714d4/) | cvar | game | Force movement style for players. 0=SIEGE 1=JKA 2=QW 3=CPM 4=Q3 5=PJK 6=WSW |
| [`g_neutralFlag`](/TaystJK/reference/cvars/g_neutralflag-55bb88d/) | cvar | game | Controls `g_neutralFlag` in the game module. |
| [`g_neutralFlagTimer`](/TaystJK/reference/cvars/g_neutralflagtimer-8ada420/) | cvar | game | Controls `g_neutralFlagTimer` in the game module. |
| [`g_newBotAI`](/TaystJK/reference/cvars/g_newbotai-156e15f/) | cvar | game | Controls `g_newBotAI` in the game module. |
| [`g_newBotAITarget`](/TaystJK/reference/cvars/g_newbotaitarget-9625e4f/) | cvar | game | -2=Target closest excluding otherbots. -1=target closest. 0-31=target clientnum. |
| [`g_newVehicleDamageScale`](/TaystJK/reference/cvars/g_newvehicledamagescale-1f63b01/) | cvar | game | Controls `g_newVehicleDamageScale` in the game module. |
| [`g_nonRandomKnockdown`](/TaystJK/reference/cvars/g_nonrandomknockdown-6cb5a5c/) | cvar | game | 1=Nonrandom knockdowns based on forcepoints. 2=Pseudorandom with less variance. 3=Nonrandom based on viewangle of target. 4=Random based on viewangle of target. |
| [`g_noSpecMove`](/TaystJK/reference/cvars/g_nospecmove-8633e1f/) | cvar | game | Controls `g_noSpecMove` in the game module. |
| [`g_npcspskill`](/TaystJK/reference/cvars/g_npcspskill-7746049/) | cvar | game | Controls `g_npcspskill` in the game module. |
| [`g_onlyBhop`](/TaystJK/reference/cvars/g_onlybhop-07d5d70/) | cvar | game | 1=Disable forcejumps for all players. 2=Let players choose if they want to disable forcejumps. |
| [`g_password`](/TaystJK/reference/cvars/g_password-db052ef/) | cvar | game | Controls `g_password` in the game module. |
| [`g_pauseTime`](/TaystJK/reference/cvars/g_pausetime-f946ba0/) | cvar | game | Controls `g_pauseTime` in the game module. |
| [`g_playerLog`](/TaystJK/reference/cvars/g_playerlog-3ba9184/) | cvar | game | Used by /amlookup |
| [`g_powerDuelEndHealth`](/TaystJK/reference/cvars/g_powerduelendhealth-6ed9bba/) | cvar | game | Controls `g_powerDuelEndHealth` in the game module. |
| [`g_powerDuelStartHealth`](/TaystJK/reference/cvars/g_powerduelstarthealth-47791bf/) | cvar | game | Controls `g_powerDuelStartHealth` in the game module. |
| [`g_privateDuel`](/TaystJK/reference/cvars/g_privateduel-d667c8f/) | cvar | game | Controls `g_privateDuel` in the game module. |
| [`g_projectileInheritance`](/TaystJK/reference/cvars/g_projectileinheritance-87e22cb/) | cvar | game | Scale of forward player momentum gained by projectiles. |
| [`g_projectileVelocityScale`](/TaystJK/reference/cvars/g_projectilevelocityscale-9182276/) | cvar | game | Controls `g_projectileVelocityScale` in the game module. |
| [`g_raceLog`](/TaystJK/reference/cvars/g_racelog-8a3ceb7/) | cvar | game | Log to races.log (incase database gets messed up). |
| [`g_raceMode`](/TaystJK/reference/cvars/g_racemode-04a9af7/) | cvar | game | 0=Noracemode, 1=forcedracemode, 2=player can toggle race mode with /racecommand. |
| [`g_randFix`](/TaystJK/reference/cvars/g_randfix-ff8f4d4/) | cvar | game | Controls `g_randFix` in the game module. |
| [`g_redDamageScale`](/TaystJK/reference/cvars/g_reddamagescale-0d0cc7a/) | cvar | game | Controls `g_redDamageScale` in the game module. |
| [`g_redDFADamageScale`](/TaystJK/reference/cvars/g_reddfadamagescale-1266724/) | cvar | game | Controls `g_redDFADamageScale` in the game module. |
| [`g_removeSpectatorPortals`](/TaystJK/reference/cvars/g_removespectatorportals-070ecec/) | cvar | game | Network all entity data to spectators, useful if you have a recorder in spectate so you can record all POV's. |
| [`g_restarted`](/TaystJK/reference/cvars/g_restarted-7cbf453/) | cvar | game | Controls `g_restarted` in the game module. |
| [`g_saber2_color`](/TaystJK/reference/cvars/g_saber2_color-64c6cc3/) | cvar | ui | Controls `g_saber2_color` in the ui module. |
| [`g_saber_color`](/TaystJK/reference/cvars/g_saber_color-c921632/) | cvar | ui | Controls `g_saber_color` in the ui module. |
| [`g_saberBladeFaces`](/TaystJK/reference/cvars/g_saberbladefaces-ee223ef/) | cvar | game | Controls `g_saberBladeFaces` in the game module. |
| [`g_saberDamageScale`](/TaystJK/reference/cvars/g_saberdamagescale-1902b96/) | cvar | game | Controls `g_saberDamageScale` in the game module. |
| [`g_saberDebugBox`](/TaystJK/reference/cvars/g_saberdebugbox-24991b0/) | cvar | game | Controls `g_saberDebugBox` in the game module. |
| [`g_saberDebugPrint`](/TaystJK/reference/cvars/g_saberdebugprint-7d18485/) | cvar | game | Controls `g_saberDebugPrint` in the game module. |
| [`g_saberDisable`](/TaystJK/reference/cvars/g_saberdisable-8b0544d/) | cvar | game | Configured with /saberDisable command. |
| [`g_saberDmgDelay_Hit`](/TaystJK/reference/cvars/g_saberdmgdelay_hit-504f5f4/) | cvar | game | Controls `g_saberDmgDelay_Hit` in the game module. |
| [`g_saberDmgDelay_Idle`](/TaystJK/reference/cvars/g_saberdmgdelay_idle-ff5bfc4/) | cvar | game | Controls `g_saberDmgDelay_Idle` in the game module. |
| [`g_saberDmgDelay_Wound`](/TaystJK/reference/cvars/g_saberdmgdelay_wound-e5965b8/) | cvar | game | Controls `g_saberDmgDelay_Wound` in the game module. |
| [`g_saberDmgVelocityScale`](/TaystJK/reference/cvars/g_saberdmgvelocityscale-c7bbdc8/) | cvar | game | Controls `g_saberDmgVelocityScale` in the game module. |
| [`g_saberDuelForceRegenTime`](/TaystJK/reference/cvars/g_saberduelforceregentime-9b15b10/) | cvar | game | Controls `g_saberDuelForceRegenTime` in the game module. |
| [`g_saberDuelSPDamage`](/TaystJK/reference/cvars/g_saberduelspdamage-3438471/) | cvar | game | Toggle use of SP style damage in saber duels. |
| [`g_saberLockFactor`](/TaystJK/reference/cvars/g_saberlockfactor-9043e22/) | cvar | game | Controls `g_saberLockFactor` in the game module. |
| [`g_saberLocking`](/TaystJK/reference/cvars/g_saberlocking-aa88986/) | cvar | game | Controls `g_saberLocking` in the game module. |
| [`g_saberLockRandomNess`](/TaystJK/reference/cvars/g_saberlockrandomness-428b3a7/) | cvar | game | Controls `g_saberLockRandomNess` in the game module. |
| [`g_saberRealisticCombat`](/TaystJK/reference/cvars/g_saberrealisticcombat-9fda4bf/) | cvar | game | Controls `g_saberRealisticCombat` in the game module. |
| [`g_saberRestrictForce`](/TaystJK/reference/cvars/g_saberrestrictforce-71cb7d9/) | cvar | game | Controls `g_saberRestrictForce` in the game module. |
| [`g_saberTouchDmg`](/TaystJK/reference/cvars/g_sabertouchdmg-2fe50c1/) | cvar | game | Configure saber touch damage for MP dmgs. Can be >1 for more touch damage. |
| [`g_saberTraceSaberFirst`](/TaystJK/reference/cvars/g_sabertracesaberfirst-3e9e21c/) | cvar | game | Controls `g_saberTraceSaberFirst` in the game module. |
| [`g_saberWallDamageScale`](/TaystJK/reference/cvars/g_saberwalldamagescale-33dbc45/) | cvar | game | Controls `g_saberWallDamageScale` in the game module. |
| [`g_scoreNPCs`](/TaystJK/reference/cvars/g_scorenpcs-6ccb95d/) | cvar | game | Controls `g_scoreNPCs` in the game module. |
| [`g_screenShake`](/TaystJK/reference/cvars/g_screenshake-590615c/) | cvar | game | Should be g_forceScreenShake |
| [`g_securityLog`](/TaystJK/reference/cvars/g_securitylog-ed66af1/) | cvar | game | Controls `g_securityLog` in the game module. |
| [`g_selfDamageScale`](/TaystJK/reference/cvars/g_selfdamagescale-3309fb9/) | cvar | game | Controls `g_selfDamageScale` in the game module. |
| [`g_showDuelHealths`](/TaystJK/reference/cvars/g_showduelhealths-479a1ba/) | cvar | game | Controls `g_showDuelHealths` in the game module. |
| [`g_showHealth`](/TaystJK/reference/cvars/g_showhealth-be5cfaa/) | cvar | game | Show healthbars above players heads when aimed at. Requires map restart. |
| [`g_showJumpSpot`](/TaystJK/reference/cvars/g_showjumpspot-316cca0/) | cvar | game | Marks where player touches ground as they land. Useful with the /nudge command on entities. |
| [`g_siegeRespawn`](/TaystJK/reference/cvars/g_siegerespawn-1ca75dd/) | cvar | game | Controls `g_siegeRespawn` in the game module. |
| [`g_siegeTeam1`](/TaystJK/reference/cvars/g_siegeteam1-4e2932b/) | cvar | game | Controls `g_siegeTeam1` in the game module. |
| [`g_siegeTeam2`](/TaystJK/reference/cvars/g_siegeteam2-60ec475/) | cvar | game | Controls `g_siegeTeam2` in the game module. |
| [`g_siegeTeamSwitch`](/TaystJK/reference/cvars/g_siegeteamswitch-ec4e992/) | cvar | game | Controls `g_siegeTeamSwitch` in the game module. |
| [`g_slideOnPlayer`](/TaystJK/reference/cvars/g_slideonplayer-57bcd53/) | cvar | game | Controls `g_slideOnPlayer` in the game module. |
| [`g_slowmoDuelEnd`](/TaystJK/reference/cvars/g_slowmoduelend-b7759cf/) | cvar | game | Controls `g_slowmoDuelEnd` in the game module. |
| [`g_smoothClients`](/TaystJK/reference/cvars/g_smoothclients-6772924/) | cvar | game | Controls `g_smoothClients` in the game module. |
| [`g_spawnInvulnerability`](/TaystJK/reference/cvars/g_spawninvulnerability-ba2c93a/) | cvar | game | Controls `g_spawnInvulnerability` in the game module. |
| [`g_speed`](/TaystJK/reference/cvars/g_speed-a067ac2/) | cvar | game | Controls `g_speed` in the game module. |
| [`g_splashDamageScale`](/TaystJK/reference/cvars/g_splashdamagescale-562c534/) | cvar | game | Controls `g_splashDamageScale` in the game module. |
| [`g_spSkill`](/TaystJK/reference/cvars/g_spskill-6446743/) | cvar | ui | Controls `g_spSkill` in the ui module. |
| [`g_startingItems`](/TaystJK/reference/cvars/g_startingitems-8ece828/) | cvar | game | Configured with /startingItems command. |
| [`g_startingWeapons`](/TaystJK/reference/cvars/g_startingweapons-ba463fc/) | cvar | game | Start with saber only default, fall back to melee if no saberattack |
| [`g_statLog`](/TaystJK/reference/cvars/g_statlog-879e05c/) | cvar | game | Controls `g_statLog` in the game module. |
| [`g_statLogFile`](/TaystJK/reference/cvars/g_statlogfile-37923cd/) | cvar | game | Controls `g_statLogFile` in the game module. |
| [`g_stepSlideFix`](/TaystJK/reference/cvars/g_stepslidefix-9d644c1/) | cvar | game | Controls `g_stepSlideFix` in the game module. |
| [`g_stopHealthESP`](/TaystJK/reference/cvars/g_stophealthesp-34d40e0/) | cvar | game | Don't send health info to other players (pain sounds can't be used to count health now). |
| [`g_synchronousClients`](/TaystJK/reference/cvars/g_synchronousclients-8895acf/) | cvar | game | Controls `g_synchronousClients` in the game module. |
| [`g_teamAbsorbScale`](/TaystJK/reference/cvars/g_teamabsorbscale-67e8eb0/) | cvar | game | Scale forcepoints gained from teampush/teampull etc. |
| [`g_teamAutoJoin`](/TaystJK/reference/cvars/g_teamautojoin-7c2230e/) | cvar | game | Controls `g_teamAutoJoin` in the game module. |
| [`g_teamEnergizeScale`](/TaystJK/reference/cvars/g_teamenergizescale-fb606bd/) | cvar | game | Scale forcepoints given from team energize. |
| [`g_teamForceBalance`](/TaystJK/reference/cvars/g_teamforcebalance-6ef2dbb/) | cvar | game | Controls `g_teamForceBalance` in the game module. |
| [`g_teamHealScale`](/TaystJK/reference/cvars/g_teamhealscale-e1e033e/) | cvar | game | Scale health given from team heal. |
| [`g_timeouttospec`](/TaystJK/reference/cvars/g_timeouttospec-3b41a9c/) | cvar | game | Controls `g_timeouttospec` in the game module. |
| [`g_tribesMode`](/TaystJK/reference/cvars/g_tribesmode-2e2993b/) | cvar | game | Controls `g_tribesMode` in the game module. |
| [`g_tweakForce`](/TaystJK/reference/cvars/g_tweakforce-d616b7a/) | cvar | game | Configured with /tweakForce command. |
| [`g_tweakJetpack`](/TaystJK/reference/cvars/g_tweakjetpack-7b1ba8a/) | cvar | game | Controls `g_tweakJetpack` in the game module. |
| [`g_tweakSaber`](/TaystJK/reference/cvars/g_tweaksaber-7ff08dd/) | cvar | game | Configured with /tweakSaber command. |
| [`g_tweakVote`](/TaystJK/reference/cvars/g_tweakvote-97a7f7d/) | cvar | game | Latch cuz of calculateRanks? not sure man |
| [`g_tweakWeapons`](/TaystJK/reference/cvars/g_tweakweapons-7f0cd05/) | cvar | game | Configured with /tweakWeapons command |
| [`g_unlagged`](/TaystJK/reference/cvars/g_unlagged-06233db/) | cvar | game | Bitvalue. 1=Unlagged projectiles. 2=Unlagged hitscan. 4=Unlagged push/pull. |
| [`g_unlaggedProjectileTolerance`](/TaystJK/reference/cvars/g_unlaggedprojectiletolerance-4f622f0/) | cvar | game | Controls `g_unlaggedProjectileTolerance` in the game module. |
| [`g_unpauseTime`](/TaystJK/reference/cvars/g_unpausetime-56cd138/) | cvar | game | Controls `g_unpauseTime` in the game module. |
| [`g_userinfoValidate`](/TaystJK/reference/cvars/g_userinfovalidate-8bbdc02/) | cvar | game | Controls `g_userinfoValidate` in the game module. |
| [`g_useWhileThrowing`](/TaystJK/reference/cvars/g_usewhilethrowing-3895f86/) | cvar | game | Controls `g_useWhileThrowing` in the game module. |
| [`g_validateCosmetics`](/TaystJK/reference/cvars/g_validatecosmetics-59cafad/) | cvar | game | Controls `g_validateCosmetics` in the game module. |
| [`g_voteDelay`](/TaystJK/reference/cvars/g_votedelay-8d2f6a6/) | cvar | game | Controls `g_voteDelay` in the game module. |
| [`g_voteTimeout`](/TaystJK/reference/cvars/g_votetimeout-c55dafd/) | cvar | game | Time in seconds to lockout callvote after a failed vote |
| [`g_warmup`](/TaystJK/reference/cvars/g_warmup-10d46fd/) | cvar | game | Controls `g_warmup` in the game module. |
| [`g_weaponDamageScale`](/TaystJK/reference/cvars/g_weapondamagescale-ba72334/) | cvar | game | Controls `g_weaponDamageScale` in the game module. |
| [`g_weaponDisable`](/TaystJK/reference/cvars/g_weapondisable-3dcdfe1/) | cvar | game | Controls `g_weaponDisable` in the game module. |
| [`g_weaponRespawn`](/TaystJK/reference/cvars/g_weaponrespawn-0999f17/) | cvar | game | Controls `g_weaponRespawn` in the game module. |
| [`g_yellowDamageScale`](/TaystJK/reference/cvars/g_yellowdamagescale-ae81376/) | cvar | game | Controls `g_yellowDamageScale` in the game module. |
| [`gamedate`](/TaystJK/reference/cvars/gamedate-1b8201a/) | cvar | game | Controls `gamedate` in the game module. |
| [`gamename`](/TaystJK/reference/cvars/gamename-eab6420/) | cvar | game | Controls `gamename` in the game module. |
| [`graphheight`](/TaystJK/reference/cvars/graphheight-4f6183b/) | cvar | engine-client | Controls `cl_graphheight` in the engine-client module. |
| [`graphscale`](/TaystJK/reference/cvars/graphscale-bad841c/) | cvar | engine-client | Controls `cl_graphscale` in the engine-client module. |
| [`graphshift`](/TaystJK/reference/cvars/graphshift-5b8cd72/) | cvar | engine-client | Controls `cl_graphshift` in the engine-client module. |
| [`in_availableJoysticks`](/TaystJK/reference/cvars/in_availablejoysticks-225bc96/) | cvar | engine-shared | Registered by the current source, but no user-facing behavior description has been verified. |
| [`in_joystick`](/TaystJK/reference/cvars/in_joystick-922c9b6/) | cvar | engine-shared | Controls `in_joystick` in the engine-shared module. |
| [`in_joystickNo`](/TaystJK/reference/cvars/in_joystickno-d0cc911/) | cvar | engine-shared | Controls `in_joystickNo` in the engine-shared module. |
| [`in_joystickUseAnalog`](/TaystJK/reference/cvars/in_joystickuseanalog-501c877/) | cvar | engine-shared | Controls `in_joystickUseAnalog` in the engine-shared module. |
| [`in_keyboardDebug`](/TaystJK/reference/cvars/in_keyboarddebug-2793d91/) | cvar | engine-shared | Controls `in_keyboardDebug` in the engine-shared module. |
| [`in_mouse`](/TaystJK/reference/cvars/in_mouse-8c4b2e5/) | cvar | engine-shared | Controls `in_mouse` in the engine-shared module. |
| [`in_mouserepeat`](/TaystJK/reference/cvars/in_mouserepeat-b6e4e4a/) | cvar | engine-shared | Controls `in_mouserepeat` in the engine-shared module. |
| [`in_nograb`](/TaystJK/reference/cvars/in_nograb-35cb150/) | cvar | engine-shared | Controls `in_nograb` in the engine-shared module. |
| [`ja_guid`](/TaystJK/reference/cvars/ja_guid-ea397d3/) | cvar | engine-client | Client GUID |
| [`jcinfo`](/TaystJK/reference/cvars/jcinfo-d257d4c/) | cvar | game | Not a cvar, dont change it |
| [`jcinfo2`](/TaystJK/reference/cvars/jcinfo2-4d14263/) | cvar | game | Not a cvar, dont change it |
| [`journal`](/TaystJK/reference/cvars/journal-4954ccf/) | cvar | engine-shared | Controls `com_journal` in the engine-shared module. |
| [`joy_threshold`](/TaystJK/reference/cvars/joy_threshold-6a68c9b/) | cvar | engine-shared | Controls `in_joystickThreshold` in the engine-shared module. |
| [`logfile`](/TaystJK/reference/cvars/logfile-1a0ef65/) | cvar | engine-shared | Controls `com_logfile` in the engine-shared module. |
| [`m_filter`](/TaystJK/reference/cvars/m_filter-378f864/) | cvar | engine-client | Controls `m_filter` in the engine-client module. |
| [`m_forward`](/TaystJK/reference/cvars/m_forward-dde14cf/) | cvar | engine-client | Controls `m_forward` in the engine-client module. |
| [`m_pitch`](/TaystJK/reference/cvars/m_pitch-5a9b25b/) | cvar | engine-client | Controls `m_pitch` in the engine-client module. |
| [`m_pitchVeh`](/TaystJK/reference/cvars/m_pitchveh-c5a5b83/) | cvar | engine-client | Controls `m_pitchVeh` in the engine-client module. |
| [`m_side`](/TaystJK/reference/cvars/m_side-503d870/) | cvar | engine-client | Controls `m_side` in the engine-client module. |
| [`m_yaw`](/TaystJK/reference/cvars/m_yaw-6897351/) | cvar | engine-client | Controls `m_yaw` in the engine-client module. |
| [`mapname`](/TaystJK/reference/cvars/mapname-78d7d3e/) | cvar | game | Controls `mapname` in the game module. |
| [`net_dropsim`](/TaystJK/reference/cvars/net_dropsim-45c82c0/) | cvar | engine-shared | Controls `net_dropsim` in the engine-shared module. |
| [`net_enabled`](/TaystJK/reference/cvars/net_enabled-800ae62/) | cvar | engine-shared | Controls `net_enabled` in the engine-shared module. |
| [`net_forcenonlocal`](/TaystJK/reference/cvars/net_forcenonlocal-8af0d5b/) | cvar | engine-shared | Controls `net_forcenonlocal` in the engine-shared module. |
| [`net_ip`](/TaystJK/reference/cvars/net_ip-e167d28/) | cvar | engine-shared | Controls `net_ip` in the engine-shared module. |
| [`net_port`](/TaystJK/reference/cvars/net_port-a39e827/) | cvar | engine-shared | Controls `net_port` in the engine-shared module. |
| [`net_qport`](/TaystJK/reference/cvars/net_qport-47e2de0/) | cvar | engine-shared | Controls `qport` in the engine-shared module. |
| [`net_socksEnabled`](/TaystJK/reference/cvars/net_socksenabled-f39d306/) | cvar | engine-shared | Controls `net_socksEnabled` in the engine-shared module. |
| [`net_socksPassword`](/TaystJK/reference/cvars/net_sockspassword-3231521/) | cvar | engine-shared | Controls `net_socksPassword` in the engine-shared module. |
| [`net_socksPort`](/TaystJK/reference/cvars/net_socksport-4b3f54f/) | cvar | engine-shared | Controls `net_socksPort` in the engine-shared module. |
| [`net_socksServer`](/TaystJK/reference/cvars/net_socksserver-8f0c6a4/) | cvar | engine-shared | Controls `net_socksServer` in the engine-shared module. |
| [`net_socksUsername`](/TaystJK/reference/cvars/net_socksusername-e7b675d/) | cvar | engine-shared | Controls `net_socksUsername` in the engine-shared module. |
| [`nextdemo`](/TaystJK/reference/cvars/nextdemo-699667e/) | cvar | engine-client | Controls `nextdemo` in the engine-client module. |
| [`nextmap`](/TaystJK/reference/cvars/nextmap-fc2a1f6/) | cvar | engine-server | Controls `nextmap` in the engine-server module. |
| [`pmove_fixed`](/TaystJK/reference/cvars/pmove_fixed-614b895/) | cvar | cgame | Controls `pmove_fixed` in the cgame module. |
| [`pmove_float`](/TaystJK/reference/cvars/pmove_float-d352a0d/) | cvar | cgame | Controls `pmove_float` in the cgame module. |
| [`pmove_msec`](/TaystJK/reference/cvars/pmove_msec-2b6eec8/) | cvar | cgame | Controls `pmove_msec` in the cgame module. |
| [`protocol`](/TaystJK/reference/cvars/protocol-6e9b4af/) | cvar | engine-server | Controls `protocol` in the engine-server module. |
| [`protocolswitch`](/TaystJK/reference/cvars/protocolswitch-9a313ea/) | cvar | engine-client | Sets protocol based on server info response |
| [`r_allowScreenSaver`](/TaystJK/reference/cvars/r_allowscreensaver-9058284/) | cvar | engine-shared | Controls `r_allowScreenSaver` in the engine-shared module. |
| [`r_allowSoftwareGL`](/TaystJK/reference/cvars/r_allowsoftwaregl-fab7aac/) | cvar | engine-shared | Controls `r_allowSoftwareGL` in the engine-shared module. |
| [`r_ambientScale`](/TaystJK/reference/cvars/r_ambientscale-2aa83ee/) | cvar | renderer | Controls `r_ambientScale` in the renderer module. |
| [`r_anaglyphMode`](/TaystJK/reference/cvars/r_anaglyphmode-756890b/) | cvar | renderer | Controls `r_anaglyphMode` in the renderer module. |
| [`r_arb_buffer_storage`](/TaystJK/reference/cvars/r_arb_buffer_storage-ac1e1c0/) | cvar | renderer | Disable/enable buffer storage GL extension |
| [`r_arb_half_float_pixel`](/TaystJK/reference/cvars/r_arb_half_float_pixel-6ad3bad/) | cvar | renderer | Disable/enable ARB_half_float GL extension |
| [`r_arb_seamless_cube_map`](/TaystJK/reference/cvars/r_arb_seamless_cube_map-c3396c7/) | cvar | renderer | Disable/enable seamless cube map filtering GL extension |
| [`r_arb_vertex_type_2_10_10_10_rev`](/TaystJK/reference/cvars/r_arb_vertex_type_2_10_10_10_rev-6fa9dbe/) | cvar | renderer | Disable/enable 1010102 UI data type |
| [`r_aspectCorrectFonts`](/TaystJK/reference/cvars/r_aspectcorrectfonts-be7251d/) | cvar | renderer | Controls `r_aspectCorrectFonts` in the renderer module. |
| [`r_autoExposure`](/TaystJK/reference/cvars/r_autoexposure-bbfaf39/) | cvar | renderer | Disable/enable auto exposure |
| [`r_autolodscalevalue`](/TaystJK/reference/cvars/r_autolodscalevalue-ea276af/) | cvar | renderer | Controls `r_autolodscalevalue` in the renderer module. |
| [`r_autoMap`](/TaystJK/reference/cvars/r_automap-3176cbc/) | cvar | renderer | Controls `r_autoMap` in the renderer module. |
| [`r_autoMapBackAlpha`](/TaystJK/reference/cvars/r_automapbackalpha-9645661/) | cvar | renderer | Controls `r_autoMapBackAlpha` in the renderer module. |
| [`r_autoMapDisable`](/TaystJK/reference/cvars/r_automapdisable-ad56d1c/) | cvar | renderer | Controls `r_autoMapDisable` in the renderer module. |
| [`r_autoMapH`](/TaystJK/reference/cvars/r_automaph-90ace7f/) | cvar | cgame | Controls `r_autoMapH` in the cgame module. |
| [`r_autoMapW`](/TaystJK/reference/cvars/r_automapw-b5b1ae5/) | cvar | cgame | Controls `r_autoMapW` in the cgame module. |
| [`r_autoMapX`](/TaystJK/reference/cvars/r_automapx-874954b/) | cvar | cgame | Controls `r_autoMapX` in the cgame module. |
| [`r_autoMapY`](/TaystJK/reference/cvars/r_automapy-0791303/) | cvar | cgame | Controls `r_autoMapY` in the cgame module. |
| [`r_availableModes`](/TaystJK/reference/cvars/r_availablemodes-bd904ae/) | cvar | engine-shared | Controls `r_availableModes` in the engine-shared module. |
| [`r_aviMotionJpegQuality`](/TaystJK/reference/cvars/r_avimotionjpegquality-108e51f/) | cvar | renderer | Controls `r_aviMotionJpegQuality` in the renderer module. |
| [`r_baseNormalX`](/TaystJK/reference/cvars/r_basenormalx-132f822/) | cvar | renderer | Controls `r_baseNormalX` in the renderer module. |
| [`r_baseNormalY`](/TaystJK/reference/cvars/r_basenormaly-f7f7006/) | cvar | renderer | Controls `r_baseNormalY` in the renderer module. |
| [`r_baseParallax`](/TaystJK/reference/cvars/r_baseparallax-6459a61/) | cvar | renderer | Controls `r_baseParallax` in the renderer module. |
| [`r_baseSpecular`](/TaystJK/reference/cvars/r_basespecular-24a3c96/) | cvar | renderer | Controls `r_baseSpecular` in the renderer module. |
| [`r_bloom`](/TaystJK/reference/cvars/r_bloom-656b99d/) | cvar | renderer | Enable bloom effect Requires \\r_fbo 1 |
| [`r_bloom_intensity`](/TaystJK/reference/cvars/r_bloom_intensity-78b7afa/) | cvar | renderer | Final bloom blend factor, default is 0.15 |
| [`r_bloom_threshold`](/TaystJK/reference/cvars/r_bloom_threshold-76fa432/) | cvar | renderer | Color level to extract to bloom texture, default is 0.05 |
| [`r_cameraExposure`](/TaystJK/reference/cvars/r_cameraexposure-7f22094/) | cvar | renderer | Controls `r_cameraExposure` in the renderer module. |
| [`r_centerWindow`](/TaystJK/reference/cvars/r_centerwindow-5f0b845/) | cvar | renderer | Controls `r_centerWindow` in the renderer module. |
| [`r_clear`](/TaystJK/reference/cvars/r_clear-b558454/) | cvar | renderer | Controls `r_clear` in the renderer module. |
| [`r_colorbits`](/TaystJK/reference/cvars/r_colorbits-4da06ec/) | cvar | renderer | Controls `r_colorbits` in the renderer module. |
| [`r_colorMipLevels`](/TaystJK/reference/cvars/r_colormiplevels-3b94fc7/) | cvar | renderer | Controls `r_colorMipLevels` in the renderer module. |
| [`r_cubeMapping`](/TaystJK/reference/cvars/r_cubemapping-86bf3af/) | cvar | renderer | Disable/enable cubemapping |
| [`r_cubeMappingBounces`](/TaystJK/reference/cvars/r_cubemappingbounces-e20074f/) | cvar | renderer | Renders cubemaps multiple times to get reflections in reflections |
| [`r_cullRoofFaces`](/TaystJK/reference/cvars/r_cullrooffaces-6bb0064/) | cvar | renderer | Controls `r_cullRoofFaces` in the renderer module. |
| [`r_customheight`](/TaystJK/reference/cvars/r_customheight-380d198/) | cvar | renderer | Controls `r_customheight` in the renderer module. |
| [`r_customwidth`](/TaystJK/reference/cvars/r_customwidth-40fe778/) | cvar | renderer | Controls `r_customwidth` in the renderer module. |
| [`r_debugContext`](/TaystJK/reference/cvars/r_debugcontext-c9977dd/) | cvar | renderer | Controls `r_debugContext` in the renderer module. |
| [`r_debuglight`](/TaystJK/reference/cvars/r_debuglight-b8d0433/) | cvar | renderer | Controls `r_debuglight` in the renderer module. |
| [`r_debugSort`](/TaystJK/reference/cvars/r_debugsort-3e4fd35/) | cvar | renderer | Controls `r_debugSort` in the renderer module. |
| [`r_debugSurface`](/TaystJK/reference/cvars/r_debugsurface-abe21fc/) | cvar | renderer | Controls `cv2` in the renderer module. |
| [`r_debugSurfaceUpdate`](/TaystJK/reference/cvars/r_debugsurfaceupdate-3194b25/) | cvar | engine-shared | Controls `cv` in the engine-shared module. |
| [`r_debugWeather`](/TaystJK/reference/cvars/r_debugweather-5e519c7/) | cvar | renderer | Controls `r_debugWeather` in the renderer module. |
| [`r_defaultImage`](/TaystJK/reference/cvars/r_defaultimage-48ebde4/) | cvar | renderer | Controls `r_defaultImage` in the renderer module. |
| [`r_deluxeMapping`](/TaystJK/reference/cvars/r_deluxemapping-a9c1e61/) | cvar | renderer | Disable/enable reading deluxemaps when compiled with q3map2 |
| [`r_deluxeSpecular`](/TaystJK/reference/cvars/r_deluxespecular-b2f4cf3/) | cvar | renderer | Disable/enable/scale the specular response from deluxemaps |
| [`r_depthbits`](/TaystJK/reference/cvars/r_depthbits-16d7986/) | cvar | renderer | Controls `r_depthbits` in the renderer module. |
| [`r_depthPrepass`](/TaystJK/reference/cvars/r_depthprepass-3fbd4eb/) | cvar | renderer | Controls `r_depthPrepass` in the renderer module. |
| [`r_detailtextures`](/TaystJK/reference/cvars/r_detailtextures-a15c8ff/) | cvar | renderer | Controls `r_detailtextures` in the renderer module. |
| [`r_directedScale`](/TaystJK/reference/cvars/r_directedscale-6aee8ad/) | cvar | renderer | Controls `r_directedScale` in the renderer module. |
| [`r_displayRefresh`](/TaystJK/reference/cvars/r_displayrefresh-59d8e1d/) | cvar | renderer | Controls `r_displayRefresh` in the renderer module. |
| [`r_distanceCull`](/TaystJK/reference/cvars/r_distancecull-9ac0a11/) | cvar | renderer | Controls `r_distanceCull` in the renderer module. |
| [`r_dither`](/TaystJK/reference/cvars/r_dither-aea5dc5/) | cvar | renderer | Set dithering mode: 0 - disabled 1 - ordered Requires \\r_fbo 1 |
| [`r_dlightIntensity`](/TaystJK/reference/cvars/r_dlightintensity-d6b49d6/) | cvar | renderer | Controls `r_dlightIntensity` in the renderer module. |
| [`r_dlightMode`](/TaystJK/reference/cvars/r_dlightmode-f87fa68/) | cvar | renderer | Controls `r_dlightMode` in the renderer module. |
| [`r_dlightSaturation`](/TaystJK/reference/cvars/r_dlightsaturation-5f6800c/) | cvar | renderer | Controls `r_dlightSaturation` in the renderer module. |
| [`r_dlightScale`](/TaystJK/reference/cvars/r_dlightscale-cc85dd5/) | cvar | renderer | Controls `r_dlightScale` in the renderer module. |
| [`r_dlightStyle`](/TaystJK/reference/cvars/r_dlightstyle-fcbcb83/) | cvar | renderer | Controls `r_dlightStyle` in the renderer module. |
| [`r_drawBuffer`](/TaystJK/reference/cvars/r_drawbuffer-a1f545a/) | cvar | renderer | Controls `r_drawBuffer` in the renderer module. |
| [`r_drawentities`](/TaystJK/reference/cvars/r_drawentities-ea638d1/) | cvar | renderer | Controls `r_drawentities` in the renderer module. |
| [`r_drawSun`](/TaystJK/reference/cvars/r_drawsun-4ed1bcb/) | cvar | renderer | Controls `r_drawSun` in the renderer module. |
| [`r_drawSunRays`](/TaystJK/reference/cvars/r_drawsunrays-f84fc82/) | cvar | renderer | Controls `r_drawSunRays` in the renderer module. |
| [`r_drawTerrain`](/TaystJK/reference/cvars/r_drawterrain-7e74ebd/) | cvar | renderer | Controls `r_drawTerrain` in the renderer module. |
| [`r_drawworld`](/TaystJK/reference/cvars/r_drawworld-f118f2d/) | cvar | renderer | Controls `r_drawworld` in the renderer module. |
| [`r_dynamicGlowBloom`](/TaystJK/reference/cvars/r_dynamicglowbloom-d4ab76d/) | cvar | renderer | Set rend2 dynamic-glow bloom strength from 0 through 2. |
| [`r_DynamicGlowDelta`](/TaystJK/reference/cvars/r_dynamicglowdelta-0aacfd7/) | cvar | renderer | Controls `r_DynamicGlowDelta` in the renderer module. |
| [`r_DynamicGlowHeight`](/TaystJK/reference/cvars/r_dynamicglowheight-ff563ef/) | cvar | renderer | Controls `r_DynamicGlowHeight` in the renderer module. |
| [`r_DynamicGlowIntensity`](/TaystJK/reference/cvars/r_dynamicglowintensity-aa3cade/) | cvar | renderer | Controls `r_DynamicGlowIntensity` in the renderer module. |
| [`r_DynamicGlowPasses`](/TaystJK/reference/cvars/r_dynamicglowpasses-a2699dc/) | cvar | renderer | Controls `r_DynamicGlowPasses` in the renderer module. |
| [`r_DynamicGlowScale`](/TaystJK/reference/cvars/r_dynamicglowscale-62e93d2/) | cvar | renderer | Controls `r_DynamicGlowScale` in the renderer module. |
| [`r_DynamicGlowSoft`](/TaystJK/reference/cvars/r_dynamicglowsoft-b5f5c97/) | cvar | renderer | Controls `r_DynamicGlowSoft` in the renderer module. |
| [`r_DynamicGlowWidth`](/TaystJK/reference/cvars/r_dynamicglowwidth-7d73e61/) | cvar | renderer | Controls `r_DynamicGlowWidth` in the renderer module. |
| [`r_dynamiclight`](/TaystJK/reference/cvars/r_dynamiclight-917a4f5/) | cvar | renderer | Controls `r_dynamiclight` in the renderer module. |
| [`r_environmentMapping`](/TaystJK/reference/cvars/r_environmentmapping-4bbfdcf/) | cvar | renderer | Controls `r_environmentMapping` in the renderer module. |
| [`r_ext_alpha_to_coverage`](/TaystJK/reference/cvars/r_ext_alpha_to_coverage-5cfb4fd/) | cvar | renderer | Controls `r_ext_alpha_to_coverage` in the renderer module. |
| [`r_ext_compress_lightmaps`](/TaystJK/reference/cvars/r_ext_compress_lightmaps-1ddfa36/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ext_draw_range_elements`](/TaystJK/reference/cvars/r_ext_draw_range_elements-17a8b5e/) | cvar | renderer | Unused |
| [`r_ext_framebuffer_multisample`](/TaystJK/reference/cvars/r_ext_framebuffer_multisample-0dd78ce/) | cvar | renderer | Controls `r_ext_framebuffer_multisample` in the renderer module. |
| [`r_ext_gamma_control`](/TaystJK/reference/cvars/r_ext_gamma_control-8e482d7/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ext_max_anisotropy`](/TaystJK/reference/cvars/r_ext_max_anisotropy-ae414a3/) | cvar | renderer | Controls `r_ext_max_anisotropy` in the renderer module. |
| [`r_ext_multi_draw_arrays`](/TaystJK/reference/cvars/r_ext_multi_draw_arrays-47cef48/) | cvar | renderer | Unused |
| [`r_ext_multisample`](/TaystJK/reference/cvars/r_ext_multisample-9b2ea2a/) | cvar | renderer | Disable/enable framebuffer MSAA |
| [`r_ext_multisample_default_fb`](/TaystJK/reference/cvars/r_ext_multisample_default_fb-d2e37d5/) | cvar | engine-shared | Controls `r_ext_multisample_default_fb` in the engine-shared module. |
| [`r_ext_supersample`](/TaystJK/reference/cvars/r_ext_supersample-75d1107/) | cvar | renderer | Controls `r_ext_supersample` in the renderer module. |
| [`r_ext_texture_filter_anisotropic_avail`](/TaystJK/reference/cvars/r_ext_texture_filter_anisotropic_avail-88815f1/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ext_texture_float`](/TaystJK/reference/cvars/r_ext_texture_float-f4a8764/) | cvar | renderer | Disable/enable floating-point textures |
| [`r_externalGLSL`](/TaystJK/reference/cvars/r_externalglsl-5987fc7/) | cvar | renderer | Controls `r_externalGLSL` in the renderer module. |
| [`r_facePlaneCull`](/TaystJK/reference/cvars/r_faceplanecull-527e83b/) | cvar | renderer | Controls `r_facePlaneCull` in the renderer module. |
| [`r_fastsky`](/TaystJK/reference/cvars/r_fastsky-24089fb/) | cvar | renderer | Controls `r_fastsky` in the renderer module. |
| [`r_fbo`](/TaystJK/reference/cvars/r_fbo-022d66e/) | cvar | renderer | Controls `r_fbo` in the renderer module. |
| [`r_finish`](/TaystJK/reference/cvars/r_finish-9b66ed8/) | cvar | renderer | Controls `r_finish` in the renderer module. |
| [`r_flares`](/TaystJK/reference/cvars/r_flares-675003d/) | cvar | renderer | Controls `r_flares` in the renderer module. |
| [`r_floatLightmap`](/TaystJK/reference/cvars/r_floatlightmap-fe575c7/) | cvar | renderer | Disable/enable HDR lightmap support |
| [`r_forceAutoExposure`](/TaystJK/reference/cvars/r_forceautoexposure-d663377/) | cvar | renderer | Controls `r_forceAutoExposure` in the renderer module. |
| [`r_forceAutoExposureMax`](/TaystJK/reference/cvars/r_forceautoexposuremax-8cdd87f/) | cvar | renderer | Controls `r_forceAutoExposureMax` in the renderer module. |
| [`r_forceAutoExposureMin`](/TaystJK/reference/cvars/r_forceautoexposuremin-662d327/) | cvar | renderer | Controls `r_forceAutoExposureMin` in the renderer module. |
| [`r_forceParallaxBias`](/TaystJK/reference/cvars/r_forceparallaxbias-f673013/) | cvar | renderer | Controls `r_forceParallaxBias` in the renderer module. |
| [`r_forceSun`](/TaystJK/reference/cvars/r_forcesun-b623af1/) | cvar | renderer | Controls `r_forceSun` in the renderer module. |
| [`r_forceSunAmbientScale`](/TaystJK/reference/cvars/r_forcesunambientscale-2bb57dd/) | cvar | renderer | Controls `r_forceSunAmbientScale` in the renderer module. |
| [`r_forceSunLightScale`](/TaystJK/reference/cvars/r_forcesunlightscale-9f32ff8/) | cvar | renderer | Controls `r_forceSunLightScale` in the renderer module. |
| [`r_forceSunMapLightScale`](/TaystJK/reference/cvars/r_forcesunmaplightscale-c3ba4de/) | cvar | renderer | Controls `r_forceSunMapLightScale` in the renderer module. |
| [`r_forceToneMap`](/TaystJK/reference/cvars/r_forcetonemap-aaa4054/) | cvar | renderer | Controls `r_forceToneMap` in the renderer module. |
| [`r_forceToneMapAvg`](/TaystJK/reference/cvars/r_forcetonemapavg-df906d3/) | cvar | renderer | Controls `r_forceToneMapAvg` in the renderer module. |
| [`r_forceToneMapMax`](/TaystJK/reference/cvars/r_forcetonemapmax-996cd1f/) | cvar | renderer | Controls `r_forceToneMapMax` in the renderer module. |
| [`r_forceToneMapMin`](/TaystJK/reference/cvars/r_forcetonemapmin-b011396/) | cvar | renderer | Controls `r_forceToneMapMin` in the renderer module. |
| [`r_fullbright`](/TaystJK/reference/cvars/r_fullbright-4d2b005/) | cvar | renderer | Controls `r_fullbright` in the renderer module. |
| [`r_fullscreen`](/TaystJK/reference/cvars/r_fullscreen-3ecab87/) | cvar | renderer | Controls `r_fullscreen` in the renderer module. |
| [`r_gamma`](/TaystJK/reference/cvars/r_gamma-9954e45/) | cvar | renderer | Controls `r_gamma` in the renderer module. |
| [`r_gammaShaders`](/TaystJK/reference/cvars/r_gammashaders-f8fed87/) | cvar | renderer | Set gamma using pixel shaders inside the game window only. |
| [`r_genNormalMaps`](/TaystJK/reference/cvars/r_gennormalmaps-3da13c7/) | cvar | renderer | Disable/enable generating normal maps from diffuse maps |
| [`r_ghoul2animsmooth`](/TaystJK/reference/cvars/r_ghoul2animsmooth-475e6c7/) | cvar | renderer | Controls `r_ghoul2animsmooth` in the renderer module. |
| [`r_ghoul2unsqashaftersmooth`](/TaystJK/reference/cvars/r_ghoul2unsqashaftersmooth-8ec055c/) | cvar | renderer | Controls `r_ghoul2unsqashaftersmooth` in the renderer module. |
| [`r_greyscale`](/TaystJK/reference/cvars/r_greyscale-442b35b/) | cvar | renderer | Controls `r_greyscale` in the renderer module. |
| [`r_hdr`](/TaystJK/reference/cvars/r_hdr-806f3ee/) | cvar | renderer | Disable/enable rendering in HDR |
| [`r_ignore`](/TaystJK/reference/cvars/r_ignore-737663a/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ignoreDstAlpha`](/TaystJK/reference/cvars/r_ignoredstalpha-bad37b1/) | cvar | renderer | Controls `r_ignoreDstAlpha` in the renderer module. |
| [`r_ignoreGLErrors`](/TaystJK/reference/cvars/r_ignoreglerrors-af91e54/) | cvar | renderer | Controls `r_ignoreGLErrors` in the renderer module. |
| [`r_imageUpsample`](/TaystJK/reference/cvars/r_imageupsample-45922fb/) | cvar | renderer | Controls `r_imageUpsample` in the renderer module. |
| [`r_imageUpsampleMaxSize`](/TaystJK/reference/cvars/r_imageupsamplemaxsize-a554326/) | cvar | renderer | Controls `r_imageUpsampleMaxSize` in the renderer module. |
| [`r_imageUpsampleType`](/TaystJK/reference/cvars/r_imageupsampletype-7553076/) | cvar | renderer | Controls `r_imageUpsampleType` in the renderer module. |
| [`r_inGameVideo`](/TaystJK/reference/cvars/r_ingamevideo-af33e5e/) | cvar | renderer | Controls `cl_inGameVideo` in the renderer module. |
| [`r_intensity`](/TaystJK/reference/cvars/r_intensity-b48f8d7/) | cvar | renderer | Controls `r_intensity` in the renderer module. |
| [`r_lightmap`](/TaystJK/reference/cvars/r_lightmap-0095642/) | cvar | renderer | Controls `r_lightmap` in the renderer module. |
| [`r_lockpvs`](/TaystJK/reference/cvars/r_lockpvs-e7f9355/) | cvar | renderer | Controls `r_lockpvs` in the renderer module. |
| [`r_lodbias`](/TaystJK/reference/cvars/r_lodbias-dccee8d/) | cvar | renderer | Controls `r_lodbias` in the renderer module. |
| [`r_lodCurveError`](/TaystJK/reference/cvars/r_lodcurveerror-a26d1cc/) | cvar | renderer | Controls `r_lodCurveError` in the renderer module. |
| [`r_lodscale`](/TaystJK/reference/cvars/r_lodscale-8715415/) | cvar | renderer | Controls `r_lodscale` in the renderer module. |
| [`r_logFile`](/TaystJK/reference/cvars/r_logfile-6b6703b/) | cvar | renderer | Controls `r_logFile` in the renderer module. |
| [`r_mapGreyScale`](/TaystJK/reference/cvars/r_mapgreyscale-691d968/) | cvar | renderer | Controls `r_mapGreyScale` in the renderer module. |
| [`r_mapOverBrightBits`](/TaystJK/reference/cvars/r_mapoverbrightbits-f8fd76d/) | cvar | renderer | Controls `r_mapOverBrightBits` in the renderer module. |
| [`r_markcount`](/TaystJK/reference/cvars/r_markcount-98ade6f/) | cvar | renderer | Controls `r_markcount` in the renderer module. |
| [`r_marksOnTriangleMeshes`](/TaystJK/reference/cvars/r_marksontrianglemeshes-3c9d053/) | cvar | renderer | Controls `r_marksOnTriangleMeshes` in the renderer module. |
| [`r_maxpolys`](/TaystJK/reference/cvars/r_maxpolys-653618a/) | cvar | renderer | Controls `r_maxpolys` in the renderer module. |
| [`r_maxpolyverts`](/TaystJK/reference/cvars/r_maxpolyverts-976a4f2/) | cvar | renderer | Controls `r_maxpolyverts` in the renderer module. |
| [`r_measureOverdraw`](/TaystJK/reference/cvars/r_measureoverdraw-0cef375/) | cvar | renderer | Controls `r_measureOverdraw` in the renderer module. |
| [`r_mergeLeafSurfaces`](/TaystJK/reference/cvars/r_mergeleafsurfaces-9631d20/) | cvar | renderer | Controls `r_mergeLeafSurfaces` in the renderer module. |
| [`r_mergeMultidraws`](/TaystJK/reference/cvars/r_mergemultidraws-471d2aa/) | cvar | renderer | Controls `r_mergeMultidraws` in the renderer module. |
| [`r_mode`](/TaystJK/reference/cvars/r_mode-ab69328/) | cvar | renderer | Controls `r_mode` in the renderer module. |
| [`r_modelpoolmegs`](/TaystJK/reference/cvars/r_modelpoolmegs-72aef0d/) | cvar | renderer | Controls `r_modelpoolmegs` in the renderer module. |
| [`r_nobind`](/TaystJK/reference/cvars/r_nobind-468736a/) | cvar | renderer | Controls `r_nobind` in the renderer module. |
| [`r_noborder`](/TaystJK/reference/cvars/r_noborder-09eac22/) | cvar | renderer | Controls `r_noborder` in the renderer module. |
| [`r_nocull`](/TaystJK/reference/cvars/r_nocull-45c5f6a/) | cvar | renderer | Controls `r_nocull` in the renderer module. |
| [`r_nocurves`](/TaystJK/reference/cvars/r_nocurves-cdabcba/) | cvar | renderer | Controls `r_nocurves` in the renderer module. |
| [`r_noghoul2`](/TaystJK/reference/cvars/r_noghoul2-182f730/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_nomip`](/TaystJK/reference/cvars/r_nomip-784a698/) | cvar | renderer | Apply picmip only on worldspawn textures |
| [`r_noportals`](/TaystJK/reference/cvars/r_noportals-b716e20/) | cvar | renderer | Controls `r_noportals` in the renderer module. |
| [`r_noPrecacheGLA`](/TaystJK/reference/cvars/r_noprecachegla-754f482/) | cvar | renderer | Controls `r_noPrecacheGLA` in the renderer module. |
| [`r_norefresh`](/TaystJK/reference/cvars/r_norefresh-8502c24/) | cvar | renderer | Controls `r_norefresh` in the renderer module. |
| [`r_normalMapping`](/TaystJK/reference/cvars/r_normalmapping-01198ee/) | cvar | renderer | Disable/enable normal mapping |
| [`r_noserverghoul2`](/TaystJK/reference/cvars/r_noserverghoul2-13e2e0d/) | cvar | renderer | Controls `r_noserverghoul2` in the renderer module. |
| [`r_novis`](/TaystJK/reference/cvars/r_novis-2bb6ab2/) | cvar | renderer | Controls `r_novis` in the renderer module. |
| [`r_offsetfactor`](/TaystJK/reference/cvars/r_offsetfactor-349c509/) | cvar | renderer | Controls `r_offsetfactor` in the renderer module. |
| [`r_offsetunits`](/TaystJK/reference/cvars/r_offsetunits-e36e68f/) | cvar | renderer | Controls `r_offsetunits` in the renderer module. |
| [`r_overBrightBits`](/TaystJK/reference/cvars/r_overbrightbits-acf2388/) | cvar | renderer | Controls `r_overBrightBits` in the renderer module. |
| [`r_parallaxMapping`](/TaystJK/reference/cvars/r_parallaxmapping-2354566/) | cvar | renderer | Disable/enable parallax mapping |
| [`r_picmip`](/TaystJK/reference/cvars/r_picmip-94fef1f/) | cvar | renderer | Controls `r_picmip` in the renderer module. |
| [`r_portalOnly`](/TaystJK/reference/cvars/r_portalonly-119fda0/) | cvar | renderer | Controls `r_portalOnly` in the renderer module. |
| [`r_presentBits`](/TaystJK/reference/cvars/r_presentbits-b73a39a/) | cvar | renderer | Select color bits used for presentation surfaces Requires \\r_fbo 1 |
| [`r_primitives`](/TaystJK/reference/cvars/r_primitives-ee344cc/) | cvar | renderer | Controls `r_primitives` in the renderer module. |
| [`r_printShaders`](/TaystJK/reference/cvars/r_printshaders-de38905/) | cvar | renderer | Controls `r_printShaders` in the renderer module. |
| [`r_pshadowDist`](/TaystJK/reference/cvars/r_pshadowdist-c0c9961/) | cvar | renderer | Controls `r_pshadowDist` in the renderer module. |
| [`r_refractionChromaticAberration`](/TaystJK/reference/cvars/r_refractionchromaticaberration-ef62fde/) | cvar | renderer | Controls `r_refractionChromaticAberration` in the renderer module. |
| [`r_renderClipBrushes`](/TaystJK/reference/cvars/r_renderclipbrushes-2dbcbc3/) | cvar | engine-client | Render clip brushes |
| [`r_renderClipBrushesShader`](/TaystJK/reference/cvars/r_renderclipbrushesshader-28b5110/) | cvar | engine-client | Shader for clip brush rendering |
| [`r_renderHeight`](/TaystJK/reference/cvars/r_renderheight-77676c4/) | cvar | renderer | Controls `r_renderHeight` in the renderer module. |
| [`r_renderScale`](/TaystJK/reference/cvars/r_renderscale-eb5ad24/) | cvar | renderer | Scaling mode to be used with custom render resolution: 0 - disabled 1 - nearest filtering, stretch to full size 2 - nearest filtering, preserve aspect ratio (black bars on sides) 3 - linear filtering, stretch to full size 4 - linear filtering, preserve aspect ratio (black bars on sides) |
| [`r_renderSlickSurfaces`](/TaystJK/reference/cvars/r_renderslicksurfaces-8f52d68/) | cvar | engine-client | Render slick surfaces |
| [`r_renderSlickSurfacesShader`](/TaystJK/reference/cvars/r_renderslicksurfacesshader-f30c0b0/) | cvar | engine-client | Shader for slick surface rendering |
| [`r_renderTriggerBrushes`](/TaystJK/reference/cvars/r_rendertriggerbrushes-127cbfb/) | cvar | engine-client | Render trigger brushes |
| [`r_renderTriggerBrushesShader`](/TaystJK/reference/cvars/r_rendertriggerbrushesshader-98cc4d1/) | cvar | engine-client | The shader for trigger brushes |
| [`r_renderWidth`](/TaystJK/reference/cvars/r_renderwidth-4a7db81/) | cvar | renderer | Controls `r_renderWidth` in the renderer module. |
| [`r_roofCeilFloorDist`](/TaystJK/reference/cvars/r_roofceilfloordist-8324544/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_roofCullCeilDist`](/TaystJK/reference/cvars/r_roofcullceildist-923eb04/) | cvar | renderer | Controls `r_roofCullCeilDist` in the renderer module. |
| [`r_roundImagesDown`](/TaystJK/reference/cvars/r_roundimagesdown-b41f9fd/) | cvar | renderer | Controls `r_roundImagesDown` in the renderer module. |
| [`r_saveFontData`](/TaystJK/reference/cvars/r_savefontdata-afb35a8/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_screenshotJpegQuality`](/TaystJK/reference/cvars/r_screenshotjpegquality-b8e56fb/) | cvar | renderer | Controls `r_screenshotJpegQuality` in the renderer module. |
| [`r_sdlDriver`](/TaystJK/reference/cvars/r_sdldriver-c79955e/) | cvar | engine-shared | Controls `r_sdlDriver` in the engine-shared module. |
| [`r_shadowCascadeZBias`](/TaystJK/reference/cvars/r_shadowcascadezbias-3a4ebe3/) | cvar | renderer | Controls `r_shadowCascadeZBias` in the renderer module. |
| [`r_shadowCascadeZFar`](/TaystJK/reference/cvars/r_shadowcascadezfar-70c7318/) | cvar | renderer | Controls `r_shadowCascadeZFar` in the renderer module. |
| [`r_shadowCascadeZNear`](/TaystJK/reference/cvars/r_shadowcascadeznear-3d8bcc7/) | cvar | renderer | Controls `r_shadowCascadeZNear` in the renderer module. |
| [`r_shadowFilter`](/TaystJK/reference/cvars/r_shadowfilter-bd830f4/) | cvar | renderer | Controls `r_shadowFilter` in the renderer module. |
| [`r_shadowMapSize`](/TaystJK/reference/cvars/r_shadowmapsize-f27fc20/) | cvar | renderer | Controls `r_shadowMapSize` in the renderer module. |
| [`r_shadowOffsetFactor`](/TaystJK/reference/cvars/r_shadowoffsetfactor-ed2b85f/) | cvar | renderer | Controls `r_shadowOffsetFactor` in the renderer module. |
| [`r_shadowOffsetUnits`](/TaystJK/reference/cvars/r_shadowoffsetunits-f883d48/) | cvar | renderer | Controls `r_shadowOffsetUnits` in the renderer module. |
| [`r_shadowRange`](/TaystJK/reference/cvars/r_shadowrange-944ff5a/) | cvar | renderer | Controls `r_shadowRange` in the renderer module. |
| [`r_showcluster`](/TaystJK/reference/cvars/r_showcluster-3f0fbb6/) | cvar | renderer | Controls `r_showcluster` in the renderer module. |
| [`r_showFrameVariance`](/TaystJK/reference/cvars/r_showframevariance-a2a515e/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_showImages`](/TaystJK/reference/cvars/r_showimages-9a4938c/) | cvar | renderer | Controls `r_showImages` in the renderer module. |
| [`r_shownormals`](/TaystJK/reference/cvars/r_shownormals-452ef91/) | cvar | renderer | Controls `r_shownormals` in the renderer module. |
| [`r_showsky`](/TaystJK/reference/cvars/r_showsky-fbfd196/) | cvar | renderer | Controls `r_showsky` in the renderer module. |
| [`r_showtris`](/TaystJK/reference/cvars/r_showtris-29c5271/) | cvar | renderer | Controls `r_showtris` in the renderer module. |
| [`r_simpleMipMaps`](/TaystJK/reference/cvars/r_simplemipmaps-24e88c1/) | cvar | renderer | Controls `r_simpleMipMaps` in the renderer module. |
| [`r_singleShader`](/TaystJK/reference/cvars/r_singleshader-e4e6862/) | cvar | renderer | Controls `r_singleShader` in the renderer module. |
| [`r_skipBackEnd`](/TaystJK/reference/cvars/r_skipbackend-0e7b613/) | cvar | renderer | Controls `r_skipBackEnd` in the renderer module. |
| [`r_smaa`](/TaystJK/reference/cvars/r_smaa-0ca3ef0/) | cvar | renderer | Disable/enable SMAA |
| [`r_smaa_quality`](/TaystJK/reference/cvars/r_smaa_quality-af9853a/) | cvar | renderer | 0: LOW | 1: MEDIUM | 2: HIGH | 3: ULTRA |
| [`r_smartpicmip`](/TaystJK/reference/cvars/r_smartpicmip-88bba35/) | cvar | renderer | Applies r_picmip setting to map textures only. |
| [`r_specularMapping`](/TaystJK/reference/cvars/r_specularmapping-271a30a/) | cvar | renderer | Disable/enable specular mapping |
| [`r_speeds`](/TaystJK/reference/cvars/r_speeds-707e8db/) | cvar | renderer | Controls `r_speeds` in the renderer module. |
| [`r_ssao`](/TaystJK/reference/cvars/r_ssao-5b8c581/) | cvar | renderer | Controls `r_ssao` in the renderer module. |
| [`r_stencilbits`](/TaystJK/reference/cvars/r_stencilbits-f1960ea/) | cvar | renderer | Controls `r_stencilbits` in the renderer module. |
| [`r_stereo`](/TaystJK/reference/cvars/r_stereo-899040b/) | cvar | renderer | Controls `r_stereo` in the renderer module. |
| [`r_stereoSeparation`](/TaystJK/reference/cvars/r_stereoseparation-2be8daa/) | cvar | renderer | Controls `r_stereoSeparation` in the renderer module. |
| [`r_subdivisions`](/TaystJK/reference/cvars/r_subdivisions-217daa3/) | cvar | renderer | Controls `r_subdivisions` in the renderer module. |
| [`r_sunlightMode`](/TaystJK/reference/cvars/r_sunlightmode-1355059/) | cvar | renderer | Controls `r_sunlightMode` in the renderer module. |
| [`r_sunShadows`](/TaystJK/reference/cvars/r_sunshadows-ffe0a50/) | cvar | renderer | Controls `r_sunShadows` in the renderer module. |
| [`r_surfaceSprites`](/TaystJK/reference/cvars/r_surfacesprites-19c6bde/) | cvar | renderer | Controls `r_surfaceSprites` in the renderer module. |
| [`r_surfaceWeather`](/TaystJK/reference/cvars/r_surfaceweather-42e08bb/) | cvar | renderer | Controls `r_surfaceWeather` in the renderer module. |
| [`r_swapInterval`](/TaystJK/reference/cvars/r_swapinterval-f4d114e/) | cvar | renderer | Controls `r_swapInterval` in the renderer module. |
| [`r_terrainTessellate`](/TaystJK/reference/cvars/r_terraintessellate-8b9ec30/) | cvar | renderer | Controls `r_terrainTessellate` in the renderer module. |
| [`r_terrainWaterOffset`](/TaystJK/reference/cvars/r_terrainwateroffset-0b046ea/) | cvar | renderer | Controls `r_terrainWaterOffset` in the renderer module. |
| [`r_texturebits`](/TaystJK/reference/cvars/r_texturebits-10d2b90/) | cvar | renderer | Controls `r_texturebits` in the renderer module. |
| [`r_texturebitslm`](/TaystJK/reference/cvars/r_texturebitslm-a3e9dd1/) | cvar | renderer | Controls `r_texturebitslm` in the renderer module. |
| [`r_textureMode`](/TaystJK/reference/cvars/r_texturemode-e53a999/) | cvar | renderer | Controls `r_textureMode` in the renderer module. |
| [`r_toneMap`](/TaystJK/reference/cvars/r_tonemap-27c4829/) | cvar | renderer | Disable/enable tonemapping |
| [`r_uifullscreen`](/TaystJK/reference/cvars/r_uifullscreen-9c735db/) | cvar | renderer | Controls `r_uifullscreen` in the renderer module. |
| [`r_vbo`](/TaystJK/reference/cvars/r_vbo-8ee14c4/) | cvar | renderer | Cache static world surfaces |
| [`r_vbo_models`](/TaystJK/reference/cvars/r_vbo_models-8579ecd/) | cvar | renderer | Cache ghoul2 and md3 model surfaces |
| [`r_verbose`](/TaystJK/reference/cvars/r_verbose-d91726d/) | cvar | renderer | Controls `r_verbose` in the renderer module. |
| [`r_vertexLight`](/TaystJK/reference/cvars/r_vertexlight-7001f2e/) | cvar | renderer | Controls `r_vertexLight` in the renderer module. |
| [`r_volumetricFog`](/TaystJK/reference/cvars/r_volumetricfog-bb8267b/) | cvar | renderer | Disable/enable lightgrid lighting on fog volumes |
| [`r_volumetricFogDefaultScale`](/TaystJK/reference/cvars/r_volumetricfogdefaultscale-2014496/) | cvar | renderer | Scales volumetric fog density unless scale has been explicitly defined |
| [`r_volumetricFogSamples`](/TaystJK/reference/cvars/r_volumetricfogsamples-c2f3eaa/) | cvar | renderer | How many ray samples to take |
| [`r_volumetricFogScale`](/TaystJK/reference/cvars/r_volumetricfogscale-e8d339c/) | cvar | renderer | Temporarily scales volumetric fog density |
| [`r_windAngle`](/TaystJK/reference/cvars/r_windangle-352ebf2/) | cvar | renderer | Controls `r_windAngle` in the renderer module. |
| [`r_windDampFactor`](/TaystJK/reference/cvars/r_winddampfactor-41a51c0/) | cvar | renderer | Controls `r_windDampFactor` in the renderer module. |
| [`r_windGust`](/TaystJK/reference/cvars/r_windgust-564e371/) | cvar | renderer | Controls `r_windGust` in the renderer module. |
| [`r_windPointForce`](/TaystJK/reference/cvars/r_windpointforce-a52b5e0/) | cvar | renderer | Controls `r_windPointForce` in the renderer module. |
| [`r_windPointX`](/TaystJK/reference/cvars/r_windpointx-7d8981c/) | cvar | renderer | Controls `r_windPointX` in the renderer module. |
| [`r_windPointY`](/TaystJK/reference/cvars/r_windpointy-b387ced/) | cvar | renderer | Controls `r_windPointY` in the renderer module. |
| [`r_windSpeed`](/TaystJK/reference/cvars/r_windspeed-85cb1e1/) | cvar | renderer | Controls `r_windSpeed` in the renderer module. |
| [`r_znear`](/TaystJK/reference/cvars/r_znear-eeed2b7/) | cvar | renderer | Controls `r_znear` in the renderer module. |
| [`r_zproj`](/TaystJK/reference/cvars/r_zproj-3cfee13/) | cvar | renderer | Controls `r_zproj` in the renderer module. |
| [`restricts`](/TaystJK/reference/cvars/restricts-3fcd8e8/) | cvar | game | Controls `restricts` in the game module. |
| [`RMG`](/TaystJK/reference/cvars/rmg-7504210/) | cvar | game | Controls `RMG` in the game module. |
| [`s_allowDynamicMusic`](/TaystJK/reference/cvars/s_allowdynamicmusic-a2b0b0a/) | cvar | engine-client | Controls `s_allowDynamicMusic` in the engine-client module. |
| [`s_debugdynamic`](/TaystJK/reference/cvars/s_debugdynamic-6580034/) | cvar | engine-client | Controls `s_debugdynamic` in the engine-client module. |
| [`s_doppler`](/TaystJK/reference/cvars/s_doppler-affddec/) | cvar | engine-client | Controls `s_doppler` in the engine-client module. |
| [`s_initsound`](/TaystJK/reference/cvars/s_initsound-b12dffe/) | cvar | engine-client | Controls `cv` in the engine-client module. |
| [`s_khz`](/TaystJK/reference/cvars/s_khz-72a60cb/) | cvar | engine-client | Controls `s_khz` in the engine-client module. |
| [`s_mixahead`](/TaystJK/reference/cvars/s_mixahead-7da5a46/) | cvar | engine-client | Controls `s_mixahead` in the engine-client module. |
| [`s_mixPreStep`](/TaystJK/reference/cvars/s_mixprestep-e32c565/) | cvar | engine-client | Controls `s_mixPreStep` in the engine-client module. |
| [`s_mp3overhead`](/TaystJK/reference/cvars/s_mp3overhead-3e470ef/) | cvar | engine-client | Controls `cv_MP3overhead` in the engine-client module. |
| [`s_musicMult`](/TaystJK/reference/cvars/s_musicmult-418de4f/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`s_sdlBits`](/TaystJK/reference/cvars/s_sdlbits-5a722c9/) | cvar | engine-shared | Controls `s_sdlBits` in the engine-shared module. |
| [`s_sdlChannels`](/TaystJK/reference/cvars/s_sdlchannels-db8bbb9/) | cvar | engine-shared | Controls `s_sdlChannels` in the engine-shared module. |
| [`s_sdlDevSamps`](/TaystJK/reference/cvars/s_sdldevsamps-433b99c/) | cvar | engine-shared | Controls `s_sdlDevSamps` in the engine-shared module. |
| [`s_sdlDriver`](/TaystJK/reference/cvars/s_sdldriver-b485ab9/) | cvar | engine-shared | Controls `s_sdlDriver` in the engine-shared module. |
| [`s_sdlMixSamps`](/TaystJK/reference/cvars/s_sdlmixsamps-d909425/) | cvar | engine-shared | Controls `s_sdlMixSamps` in the engine-shared module. |
| [`s_separation`](/TaystJK/reference/cvars/s_separation-ce56ff6/) | cvar | engine-client | Controls `s_separation` in the engine-client module. |
| [`s_show`](/TaystJK/reference/cvars/s_show-42944ff/) | cvar | engine-client | Controls `s_show` in the engine-client module. |
| [`s_soundpoolmegs`](/TaystJK/reference/cvars/s_soundpoolmegs-7f0c33e/) | cvar | engine-client | Controls `s_soundpoolmegs` in the engine-client module. |
| [`s_testsound`](/TaystJK/reference/cvars/s_testsound-a5efbf3/) | cvar | engine-client | Controls `s_testsound` in the engine-client module. |
| [`s_threshold1`](/TaystJK/reference/cvars/s_threshold1-e537283/) | cvar | engine-client | Controls `s_lip_threshold_1` in the engine-client module. |
| [`s_threshold2`](/TaystJK/reference/cvars/s_threshold2-c620de4/) | cvar | engine-client | Controls `s_lip_threshold_2` in the engine-client module. |
| [`s_threshold3`](/TaystJK/reference/cvars/s_threshold3-42c9ced/) | cvar | engine-client | Controls `s_lip_threshold_3` in the engine-client module. |
| [`s_threshold4`](/TaystJK/reference/cvars/s_threshold4-efb9d34/) | cvar | engine-client | Controls `s_lip_threshold_4` in the engine-client module. |
| [`s_UseOpenAL`](/TaystJK/reference/cvars/s_useopenal-edb5f99/) | cvar | engine-client | Controls `cv` in the engine-client module. |
| [`se_debug`](/TaystJK/reference/cvars/se_debug-6156cff/) | cvar | engine-shared | Controls `se_debug` in the engine-shared module. |
| [`se_language`](/TaystJK/reference/cvars/se_language-5545a01/) | cvar | engine-shared | Controls `se_language` in the engine-shared module. |
| [`session`](/TaystJK/reference/cvars/session-fcbdc4c/) | cvar | game | Controls `session` in the game module. |
| [`showdrop`](/TaystJK/reference/cvars/showdrop-b56d343/) | cvar | engine-shared | Controls `showdrop` in the engine-shared module. |
| [`showevents`](/TaystJK/reference/cvars/showevents-fbb73ba/) | cvar | game | Controls `showEvents` in the game module. |
| [`showpackets`](/TaystJK/reference/cvars/showpackets-13ebc18/) | cvar | engine-shared | Controls `showpackets` in the engine-shared module. |
| [`siege_mapgraphic`](/TaystJK/reference/cvars/siege_mapgraphic-031bee7/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`siege_missionname`](/TaystJK/reference/cvars/siege_missionname-1ea193a/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`snd_mute_losefocus`](/TaystJK/reference/cvars/snd_mute_losefocus-56dc974/) | cvar | engine-client | Mute sound when game window is unfocused/minimized |
| [`sp_leet`](/TaystJK/reference/cvars/sp_leet-e15c4b2/) | cvar | engine-shared | Controls `sp_leet` in the engine-shared module. |
| [`sv_antiDST`](/TaystJK/reference/cvars/sv_antidst-09f18d9/) | cvar | engine-server | Attempts to detect and kick players injecting or using DST |
| [`sv_autoDemo`](/TaystJK/reference/cvars/sv_autodemo-9d9325d/) | cvar | engine-server | Automatically take server-side demos |
| [`sv_autoDemoBots`](/TaystJK/reference/cvars/sv_autodemobots-d25d8d2/) | cvar | engine-server | Record server-side demos for bots |
| [`sv_autoDemoMaxMaps`](/TaystJK/reference/cvars/sv_autodemomaxmaps-76728b7/) | cvar | engine-server | Controls `sv_autoDemoMaxMaps` in the engine-server module. |
| [`sv_autoRaceDemo`](/TaystJK/reference/cvars/sv_autoracedemo-b0d5159/) | cvar | game | Requires custom server executable with "svrecord" command. |
| [`sv_banFile`](/TaystJK/reference/cvars/sv_banfile-9b86cae/) | cvar | engine-server | File to use to store bans and exceptions |
| [`sv_clientRate`](/TaystJK/reference/cvars/sv_clientrate-25c8382/) | cvar | engine-server | Controls `sv_clientRate` in the engine-server module. |
| [`sv_demoPreRecordBots`](/TaystJK/reference/cvars/sv_demoprerecordbots-4548856/) | cvar | engine-server | Do demo pre-recording for bots as well |
| [`sv_filterCommands`](/TaystJK/reference/cvars/sv_filtercommands-f4a9480/) | cvar | engine-server | Controls `sv_filterCommands` in the engine-server module. |
| [`sv_hibernateTime`](/TaystJK/reference/cvars/sv_hibernatetime-940437b/) | cvar | engine-server | Time after which server will enter hibernation mode |
| [`sv_keywords`](/TaystJK/reference/cvars/sv_keywords-f941027/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_killserver`](/TaystJK/reference/cvars/sv_killserver-7431ced/) | cvar | engine-server | Controls `sv_killserver` in the engine-server module. |
| [`sv_lanForceRate`](/TaystJK/reference/cvars/sv_lanforcerate-17e0934/) | cvar | engine-server | Controls `sv_lanForceRate` in the engine-server module. |
| [`sv_legacyFixes`](/TaystJK/reference/cvars/sv_legacyfixes-4f7fac8/) | cvar | engine-server | Controls `sv_legacyFixes` in the engine-server module. |
| [`sv_mapChecksum`](/TaystJK/reference/cvars/sv_mapchecksum-848ef8d/) | cvar | engine-server | Controls `ckSum` in the engine-server module. |
| [`sv_master1`](/TaystJK/reference/cvars/sv_master1-f9b0f7d/) | cvar | engine-server | Controls `sv_master1` in the engine-server module. |
| [`sv_master2`](/TaystJK/reference/cvars/sv_master2-5450788/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_master3`](/TaystJK/reference/cvars/sv_master3-14c7d89/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_master4`](/TaystJK/reference/cvars/sv_master4-1ef6bb9/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_master5`](/TaystJK/reference/cvars/sv_master5-79a049a/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_maxOOBRateIP`](/TaystJK/reference/cvars/sv_maxoobrateip-21dc800/) | cvar | engine-server | Maximum rate of handling incoming server commands per IP address |
| [`sv_maxPing`](/TaystJK/reference/cvars/sv_maxping-3bde469/) | cvar | engine-server | Controls `sv_maxPing` in the engine-server module. |
| [`sv_maxTeamSize`](/TaystJK/reference/cvars/sv_maxteamsize-8db6a18/) | cvar | game | Controls `sv_maxTeamSize` in the game module. |
| [`sv_minPing`](/TaystJK/reference/cvars/sv_minping-8e1c6bb/) | cvar | engine-server | Controls `sv_minPing` in the engine-server module. |
| [`sv_minRate`](/TaystJK/reference/cvars/sv_minrate-76512c7/) | cvar | engine-server | Min bandwidth rate allowed on server. Use 0 for unlimited. |
| [`sv_newfloodProtect`](/TaystJK/reference/cvars/sv_newfloodprotect-e4e33fe/) | cvar | engine-server | Use new method of delaying commands with flood protection |
| [`sv_padPackets`](/TaystJK/reference/cvars/sv_padpackets-d11a7ea/) | cvar | engine-server | Controls `sv_padPackets` in the engine-server module. |
| [`sv_pakNames`](/TaystJK/reference/cvars/sv_paknames-bebd909/) | cvar | engine-server | Controls `sv_pakNames` in the engine-server module. |
| [`sv_paks`](/TaystJK/reference/cvars/sv_paks-2f0d74d/) | cvar | engine-server | Controls `sv_paks` in the engine-server module. |
| [`sv_paused`](/TaystJK/reference/cvars/sv_paused-d622ecf/) | cvar | engine-shared | Controls `sv_paused` in the engine-shared module. |
| [`sv_pluginKey`](/TaystJK/reference/cvars/sv_pluginkey-9d80ed4/) | cvar | game | Controls `sv_pluginKey` in the game module. |
| [`sv_privatePassword`](/TaystJK/reference/cvars/sv_privatepassword-98b62ad/) | cvar | engine-server | Controls `sv_privatePassword` in the engine-server module. |
| [`sv_ratePolicy`](/TaystJK/reference/cvars/sv_ratepolicy-8e864f3/) | cvar | engine-server | Determines which policy of enforcement is used for client's \"rate\" cvar |
| [`sv_reconnectlimit`](/TaystJK/reference/cvars/sv_reconnectlimit-aaba884/) | cvar | engine-server | Controls `sv_reconnectlimit` in the engine-server module. |
| [`sv_referencedPakNames`](/TaystJK/reference/cvars/sv_referencedpaknames-7bbf18d/) | cvar | engine-server | Controls `sv_referencedPakNames` in the engine-server module. |
| [`sv_referencedPaks`](/TaystJK/reference/cvars/sv_referencedpaks-3456d25/) | cvar | engine-server | Controls `sv_referencedPaks` in the engine-server module. |
| [`sv_saberFPS`](/TaystJK/reference/cvars/sv_saberfps-7d809f3/) | cvar | game | Controls `sv_saberFPS` in the game module. |
| [`sv_serverid`](/TaystJK/reference/cvars/sv_serverid-929cf16/) | cvar | engine-server | Controls `sv_serverid` in the engine-server module. |
| [`sv_showghoultraces`](/TaystJK/reference/cvars/sv_showghoultraces-6c0c074/) | cvar | engine-server | Controls `sv_showghoultraces` in the engine-server module. |
| [`sv_showloss`](/TaystJK/reference/cvars/sv_showloss-545b07f/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_snapShotDuelCull`](/TaystJK/reference/cvars/sv_snapshotduelcull-160745a/) | cvar | engine-server | Snapshot-based duel isolation |
| [`sv_snapsMax`](/TaystJK/reference/cvars/sv_snapsmax-b20336c/) | cvar | engine-server | Sv_snapsMin <=> sv_fps |
| [`sv_snapsMin`](/TaystJK/reference/cvars/sv_snapsmin-7fe81b5/) | cvar | engine-server | 1 <=> sv_snapsMax |
| [`sv_snapsPolicy`](/TaystJK/reference/cvars/sv_snapspolicy-385ae5d/) | cvar | engine-server | Determines which policy of enforcement is used for client's \"snaps\" cvar |
| [`sv_timeout`](/TaystJK/reference/cvars/sv_timeout-2e15cf0/) | cvar | engine-server | Controls `sv_timeout` in the engine-server module. |
| [`sv_zombietime`](/TaystJK/reference/cvars/sv_zombietime-c069b6b/) | cvar | engine-server | Controls `sv_zombietime` in the engine-server module. |
| [`sys_lowmem`](/TaystJK/reference/cvars/sys_lowmem-8037c1f/) | cvar | engine-shared | Controls `sys_lowmem` in the engine-shared module. |
| [`team1_icon`](/TaystJK/reference/cvars/team1_icon-d94de55/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`team2_icon`](/TaystJK/reference/cvars/team2_icon-a8c547c/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`teamoverlay`](/TaystJK/reference/cvars/teamoverlay-f842919/) | cvar | cgame | Controls `teamoverlay` in the cgame module. |
| [`timedemo`](/TaystJK/reference/cvars/timedemo-32d1727/) | cvar | engine-client | Controls `cl_timedemo` in the engine-client module. |
| [`timegraph`](/TaystJK/reference/cvars/timegraph-db7f449/) | cvar | engine-client | Controls `cl_timegraph` in the engine-client module. |
| [`timelimit`](/TaystJK/reference/cvars/timelimit-050b6ba/) | cvar | game | Controls `timelimit` in the game module. |
| [`timescale`](/TaystJK/reference/cvars/timescale-97bdf9f/) | cvar | cgame | Controls `timescale` in the cgame module. |
| [`ui_about_botminplayers`](/TaystJK/reference/cvars/ui_about_botminplayers-10e7331/) | cvar | cgame | Controls `ui_about_botminplayers` in the cgame module. |
| [`ui_about_capturelimit`](/TaystJK/reference/cvars/ui_about_capturelimit-98d5070/) | cvar | cgame | Controls `ui_about_capturelimit` in the cgame module. |
| [`ui_about_dmflags`](/TaystJK/reference/cvars/ui_about_dmflags-59c5610/) | cvar | cgame | Controls `ui_about_dmflags` in the cgame module. |
| [`ui_about_duellimit`](/TaystJK/reference/cvars/ui_about_duellimit-bce4d5b/) | cvar | cgame | Controls `ui_about_duellimit` in the cgame module. |
| [`ui_about_fraglimit`](/TaystJK/reference/cvars/ui_about_fraglimit-87f305c/) | cvar | cgame | Controls `ui_about_fraglimit` in the cgame module. |
| [`ui_about_gametype`](/TaystJK/reference/cvars/ui_about_gametype-da939aa/) | cvar | cgame | Controls `ui_about_gametype` in the cgame module. |
| [`ui_about_hostname`](/TaystJK/reference/cvars/ui_about_hostname-52cdc99/) | cvar | cgame | Controls `ui_about_hostname` in the cgame module. |
| [`ui_about_mapname`](/TaystJK/reference/cvars/ui_about_mapname-48214ba/) | cvar | cgame | Controls `ui_about_mapname` in the cgame module. |
| [`ui_about_maxclients`](/TaystJK/reference/cvars/ui_about_maxclients-7bbd8c0/) | cvar | cgame | Controls `ui_about_maxclients` in the cgame module. |
| [`ui_about_needpass`](/TaystJK/reference/cvars/ui_about_needpass-578f7b4/) | cvar | cgame | Controls `ui_about_needpass` in the cgame module. |
| [`ui_about_timelimit`](/TaystJK/reference/cvars/ui_about_timelimit-182983b/) | cvar | cgame | Controls `ui_about_timelimit` in the cgame module. |
| [`ui_actualNetGametype`](/TaystJK/reference/cvars/ui_actualnetgametype-70fb097/) | cvar | ui | Controls `ui_actualNetGametype` in the ui module. |
| [`ui_allowRegistration`](/TaystJK/reference/cvars/ui_allowregistration-713df1d/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_allowSaberSwitch`](/TaystJK/reference/cvars/ui_allowsaberswitch-6b40886/) | cvar | ui | Controls `ui_allowSaberSwitch` in the ui module. |
| [`ui_aspectratio`](/TaystJK/reference/cvars/ui_aspectratio-1403db8/) | cvar | ui | Controls `ui_aspectratio` in the ui module. |
| [`ui_blueteam`](/TaystJK/reference/cvars/ui_blueteam-17a25d6/) | cvar | ui | Controls `ui_blueteam` in the ui module. |
| [`ui_blueteam1`](/TaystJK/reference/cvars/ui_blueteam1-340fe0d/) | cvar | ui | Controls `ui_blueteam1` in the ui module. |
| [`ui_blueteam2`](/TaystJK/reference/cvars/ui_blueteam2-ee938fb/) | cvar | ui | Controls `ui_blueteam2` in the ui module. |
| [`ui_blueteam3`](/TaystJK/reference/cvars/ui_blueteam3-e2e0895/) | cvar | ui | Controls `ui_blueteam3` in the ui module. |
| [`ui_blueteam4`](/TaystJK/reference/cvars/ui_blueteam4-7fa667e/) | cvar | ui | Controls `ui_blueteam4` in the ui module. |
| [`ui_blueteam5`](/TaystJK/reference/cvars/ui_blueteam5-fe0911a/) | cvar | ui | Controls `ui_blueteam5` in the ui module. |
| [`ui_blueteam6`](/TaystJK/reference/cvars/ui_blueteam6-9ab3444/) | cvar | ui | Controls `ui_blueteam6` in the ui module. |
| [`ui_blueteam7`](/TaystJK/reference/cvars/ui_blueteam7-b99b7a8/) | cvar | ui | Controls `ui_blueteam7` in the ui module. |
| [`ui_blueteam8`](/TaystJK/reference/cvars/ui_blueteam8-900a45c/) | cvar | ui | Controls `ui_blueteam8` in the ui module. |
| [`ui_browserFilterInvalidInfo`](/TaystJK/reference/cvars/ui_browserfilterinvalidinfo-7ee2364/) | cvar | ui | Controls `ui_browserFilterInvalidInfo` in the ui module. |
| [`ui_browserShowEmpty`](/TaystJK/reference/cvars/ui_browsershowempty-68572ca/) | cvar | ui | Controls `ui_browserShowEmpty` in the ui module. |
| [`ui_browserShowFull`](/TaystJK/reference/cvars/ui_browsershowfull-6068674/) | cvar | ui | Controls `ui_browserShowFull` in the ui module. |
| [`ui_browserShowPasswordProtected`](/TaystJK/reference/cvars/ui_browsershowpasswordprotected-204880a/) | cvar | ui | Controls `ui_browserShowPasswordProtected` in the ui module. |
| [`ui_bypassMainMenuLoad`](/TaystJK/reference/cvars/ui_bypassmainmenuload-408ee1e/) | cvar | ui | Controls `ui_bypassMainMenuLoad` in the ui module. |
| [`ui_captureLimit`](/TaystJK/reference/cvars/ui_capturelimit-0eca7ff/) | cvar | ui | Controls `ui_captureLimit` in the ui module. |
| [`ui_cg_shadows`](/TaystJK/reference/cvars/ui_cg_shadows-b52e606/) | cvar | ui | Controls `ui_cg_shadows` in the ui module. |
| [`ui_char_anim`](/TaystJK/reference/cvars/ui_char_anim-09080f3/) | cvar | ui | Controls `ui_char_anim` in the ui module. |
| [`ui_char_color_blue`](/TaystJK/reference/cvars/ui_char_color_blue-28e01a4/) | cvar | ui | Controls `ui_char_color_blue` in the ui module. |
| [`ui_char_color_green`](/TaystJK/reference/cvars/ui_char_color_green-efefe4d/) | cvar | ui | Controls `ui_char_color_green` in the ui module. |
| [`ui_char_color_red`](/TaystJK/reference/cvars/ui_char_color_red-efed648/) | cvar | ui | Controls `ui_char_color_red` in the ui module. |
| [`ui_char_model`](/TaystJK/reference/cvars/ui_char_model-767a8b1/) | cvar | ui | Controls `ui_char_model` in the ui module. |
| [`ui_char_skin_head`](/TaystJK/reference/cvars/ui_char_skin_head-8f224b8/) | cvar | ui | Controls `ui_char_skin_head` in the ui module. |
| [`ui_char_skin_legs`](/TaystJK/reference/cvars/ui_char_skin_legs-76fbb98/) | cvar | ui | Controls `ui_char_skin_legs` in the ui module. |
| [`ui_char_skin_torso`](/TaystJK/reference/cvars/ui_char_skin_torso-0fe93fd/) | cvar | ui | Controls `ui_char_skin_torso` in the ui module. |
| [`ui_cl_maxpackets`](/TaystJK/reference/cvars/ui_cl_maxpackets-a1a306c/) | cvar | ui | Controls `ui_cl_maxpackets` in the ui module. |
| [`ui_cl_renderer`](/TaystJK/reference/cvars/ui_cl_renderer-955b72c/) | cvar | ui | Controls `ui_cl_renderer` in the ui module. |
| [`ui_class_armor`](/TaystJK/reference/cvars/ui_class_armor-754c891/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_class_health`](/TaystJK/reference/cvars/ui_class_health-259f487/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_class_icon`](/TaystJK/reference/cvars/ui_class_icon-ed0fb7c/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_class_speed`](/TaystJK/reference/cvars/ui_class_speed-d9257ab/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_classDesc`](/TaystJK/reference/cvars/ui_classdesc-1756c39/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_classPortrait`](/TaystJK/reference/cvars/ui_classportrait-6b54bf0/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_ctf_capturelimit`](/TaystJK/reference/cvars/ui_ctf_capturelimit-639898d/) | cvar | ui | Controls `ui_ctf_capturelimit` in the ui module. |
| [`ui_ctf_friendly`](/TaystJK/reference/cvars/ui_ctf_friendly-ff1dc3a/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_ctf_timelimit`](/TaystJK/reference/cvars/ui_ctf_timelimit-186b2d1/) | cvar | ui | Controls `ui_ctf_timelimit` in the ui module. |
| [`ui_currentMap`](/TaystJK/reference/cvars/ui_currentmap-27fc114/) | cvar | ui | Controls `ui_currentMap` in the ui module. |
| [`ui_currentNetMap`](/TaystJK/reference/cvars/ui_currentnetmap-81eb329/) | cvar | ui | Controls `ui_currentNetMap` in the ui module. |
| [`ui_currentOpponent`](/TaystJK/reference/cvars/ui_currentopponent-bbc3c11/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_dedicated`](/TaystJK/reference/cvars/ui_dedicated-c7593a0/) | cvar | ui | Controls `ui_dedicated` in the ui module. |
| [`ui_demo_cnt`](/TaystJK/reference/cvars/ui_demo_cnt-55f87f1/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_disableWeaponSway`](/TaystJK/reference/cvars/ui_disableweaponsway-e995888/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_doWarmup`](/TaystJK/reference/cvars/ui_dowarmup-ff727ff/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_drawTimer`](/TaystJK/reference/cvars/ui_drawtimer-f8d1cb4/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_dualforcepower`](/TaystJK/reference/cvars/ui_dualforcepower-60e193b/) | cvar | ui | Controls `ui_dualforcepower` in the ui module. |
| [`ui_duel_fraglimit`](/TaystJK/reference/cvars/ui_duel_fraglimit-f40462c/) | cvar | ui | Controls `ui_duel_fraglimit` in the ui module. |
| [`ui_duel_timelimit`](/TaystJK/reference/cvars/ui_duel_timelimit-5f8e8ad/) | cvar | ui | Controls `ui_duel_timelimit` in the ui module. |
| [`ui_ffa_fraglimit`](/TaystJK/reference/cvars/ui_ffa_fraglimit-5876427/) | cvar | ui | Controls `ui_ffa_fraglimit` in the ui module. |
| [`ui_ffa_timelimit`](/TaystJK/reference/cvars/ui_ffa_timelimit-ce6b60e/) | cvar | ui | Controls `ui_ffa_timelimit` in the ui module. |
| [`ui_findPlayer`](/TaystJK/reference/cvars/ui_findplayer-02ede1c/) | cvar | ui | Controls `ui_findPlayer` in the ui module. |
| [`ui_forcePowerDisable`](/TaystJK/reference/cvars/ui_forcepowerdisable-331521c/) | cvar | ui | Controls `ui_forcePowerDisable` in the ui module. |
| [`ui_fragLimit`](/TaystJK/reference/cvars/ui_fraglimit-178a086/) | cvar | ui | Controls `ui_fragLimit` in the ui module. |
| [`ui_freeSaber`](/TaystJK/reference/cvars/ui_freesaber-c23f8d2/) | cvar | ui | Controls `ui_freeSaber` in the ui module. |
| [`ui_friendlyFire`](/TaystJK/reference/cvars/ui_friendlyfire-91d84c9/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_gametype`](/TaystJK/reference/cvars/ui_gametype-a49b5f0/) | cvar | ui | Controls `ui_gametype` in the ui module. |
| [`ui_geometricdetail`](/TaystJK/reference/cvars/ui_geometricdetail-21121ee/) | cvar | ui | Controls `ui_geometricdetail` in the ui module. |
| [`ui_headCount`](/TaystJK/reference/cvars/ui_headcount-384f251/) | cvar | ui | Controls `ui_headCount` in the ui module. |
| [`ui_heavy_cnt`](/TaystJK/reference/cvars/ui_heavy_cnt-020d02c/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_holdteam`](/TaystJK/reference/cvars/ui_holdteam-6816b79/) | cvar | ui | Controls `ui_holdteam` in the ui module. |
| [`ui_infantry_cnt`](/TaystJK/reference/cvars/ui_infantry_cnt-414d93d/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_isJAPro`](/TaystJK/reference/cvars/ui_isjapro-9265944/) | cvar | ui | Controls `ui_isJAPro` in the ui module. |
| [`ui_itemforceinvdesc`](/TaystJK/reference/cvars/ui_itemforceinvdesc-d6588bb/) | cvar | ui | Controls `ui_itemforceinvdesc` in the ui module. |
| [`ui_jedi_cnt`](/TaystJK/reference/cvars/ui_jedi_cnt-8c23f9b/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_joinGametype`](/TaystJK/reference/cvars/ui_joingametype-71f7a60/) | cvar | ui | Controls `ui_joinGametype` in the ui module. |
| [`ui_lastServerRefresh_0`](/TaystJK/reference/cvars/ui_lastserverrefresh_0-be69301/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_1`](/TaystJK/reference/cvars/ui_lastserverrefresh_1-14bcea1/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_2`](/TaystJK/reference/cvars/ui_lastserverrefresh_2-686148e/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_3`](/TaystJK/reference/cvars/ui_lastserverrefresh_3-aa83713/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_4`](/TaystJK/reference/cvars/ui_lastserverrefresh_4-d0bcc90/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_5`](/TaystJK/reference/cvars/ui_lastserverrefresh_5-2c6c262/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_6`](/TaystJK/reference/cvars/ui_lastserverrefresh_6-fba4ec6/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_mapIndex`](/TaystJK/reference/cvars/ui_mapindex-5cacf3a/) | cvar | ui | Controls `ui_mapIndex` in the ui module. |
| [`ui_maxClients`](/TaystJK/reference/cvars/ui_maxclients-c99a58b/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_menuFilesMP`](/TaystJK/reference/cvars/ui_menufilesmp-4fdfd20/) | cvar | ui | Controls `ui_menuFilesMP` in the ui module. |
| [`ui_mousePitch`](/TaystJK/reference/cvars/ui_mousepitch-f7e9ef6/) | cvar | ui | Controls `ui_mousePitch` in the ui module. |
| [`ui_mousePitchVeh`](/TaystJK/reference/cvars/ui_mousepitchveh-9ffa9f6/) | cvar | ui | Controls `ui_mousePitchVeh` in the ui module. |
| [`ui_move_desc`](/TaystJK/reference/cvars/ui_move_desc-84d5d18/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_mySiegeClass`](/TaystJK/reference/cvars/ui_mysiegeclass-ba0c7b0/) | cvar | cgame | Controls `ui_mySiegeClass` in the cgame module. |
| [`ui_myteam`](/TaystJK/reference/cvars/ui_myteam-fece47c/) | cvar | cgame | Controls `ui_myteam` in the cgame module. |
| [`ui_Name`](/TaystJK/reference/cvars/ui_name-9d84122/) | cvar | ui | Controls `ui_Name` in the ui module. |
| [`ui_netGametype`](/TaystJK/reference/cvars/ui_netgametype-273c08f/) | cvar | ui | Controls `ui_netGametype` in the ui module. |
| [`ui_netSource`](/TaystJK/reference/cvars/ui_netsource-7f47658/) | cvar | ui | Controls `ui_netSource` in the ui module. |
| [`ui_opponentName`](/TaystJK/reference/cvars/ui_opponentname-479d170/) | cvar | ui | Controls `ui_opponentName` in the ui module. |
| [`ui_password`](/TaystJK/reference/cvars/ui_password-5175d7a/) | cvar | ui | Controls `ui_password` in the ui module. |
| [`ui_playerServersFound`](/TaystJK/reference/cvars/ui_playerserversfound-c03deaf/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_PrecacheModels`](/TaystJK/reference/cvars/ui_precachemodels-5229eee/) | cvar | ui | Controls `ui_PrecacheModels` in the ui module. |
| [`ui_pure`](/TaystJK/reference/cvars/ui_pure-f965bc7/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_r_allowExtensions`](/TaystJK/reference/cvars/ui_r_allowextensions-8370712/) | cvar | ui | Controls `ui_r_allowExtensions` in the ui module. |
| [`ui_r_autoexposure`](/TaystJK/reference/cvars/ui_r_autoexposure-b83e601/) | cvar | ui | Controls `ui_r_autoexposure` in the ui module. |
| [`ui_r_colorbits`](/TaystJK/reference/cvars/ui_r_colorbits-edf76e7/) | cvar | ui | Controls `ui_r_colorbits` in the ui module. |
| [`ui_r_cubemapping`](/TaystJK/reference/cvars/ui_r_cubemapping-fce2f9f/) | cvar | ui | Controls `ui_r_cubemapping` in the ui module. |
| [`ui_r_cubemappingBounces`](/TaystJK/reference/cvars/ui_r_cubemappingbounces-7eddb9f/) | cvar | ui | Controls `ui_r_cubemappingBounces` in the ui module. |
| [`ui_r_customHeight`](/TaystJK/reference/cvars/ui_r_customheight-d1dc7bd/) | cvar | ui | Controls `ui_r_customHeight` in the ui module. |
| [`ui_r_customWidth`](/TaystJK/reference/cvars/ui_r_customwidth-5314b17/) | cvar | ui | Controls `ui_r_customWidth` in the ui module. |
| [`ui_r_deluxemapping`](/TaystJK/reference/cvars/ui_r_deluxemapping-52635ff/) | cvar | ui | Controls `ui_r_deluxemapping` in the ui module. |
| [`ui_r_depthbits`](/TaystJK/reference/cvars/ui_r_depthbits-60aa449/) | cvar | ui | Controls `ui_r_depthbits` in the ui module. |
| [`ui_r_detailtextures`](/TaystJK/reference/cvars/ui_r_detailtextures-3adef96/) | cvar | ui | Controls `ui_r_detailtextures` in the ui module. |
| [`ui_r_ext_compress_textures`](/TaystJK/reference/cvars/ui_r_ext_compress_textures-6b011e4/) | cvar | ui | Controls `ui_r_ext_compress_textures` in the ui module. |
| [`ui_r_fastSky`](/TaystJK/reference/cvars/ui_r_fastsky-ba5631d/) | cvar | ui | Controls `ui_r_fastSky` in the ui module. |
| [`ui_r_floatLightmap`](/TaystJK/reference/cvars/ui_r_floatlightmap-59a00c5/) | cvar | ui | Controls `ui_r_floatLightmap` in the ui module. |
| [`ui_r_fullBright`](/TaystJK/reference/cvars/ui_r_fullbright-8eeef50/) | cvar | ui | Controls `ui_r_fullBright` in the ui module. |
| [`ui_r_fullscreen`](/TaystJK/reference/cvars/ui_r_fullscreen-d65a208/) | cvar | ui | Controls `ui_r_fullscreen` in the ui module. |
| [`ui_r_genNormalMaps`](/TaystJK/reference/cvars/ui_r_gennormalmaps-c97f4b3/) | cvar | ui | Controls `ui_r_genNormalMaps` in the ui module. |
| [`ui_r_glCustom`](/TaystJK/reference/cvars/ui_r_glcustom-8cde091/) | cvar | ui | Controls `ui_r_glCustom` in the ui module. |
| [`ui_r_hdr`](/TaystJK/reference/cvars/ui_r_hdr-d318c21/) | cvar | ui | Controls `ui_r_hdr` in the ui module. |
| [`ui_r_inGameVideo`](/TaystJK/reference/cvars/ui_r_ingamevideo-7c28d4e/) | cvar | ui | Controls `ui_r_inGameVideo` in the ui module. |
| [`ui_r_intensity`](/TaystJK/reference/cvars/ui_r_intensity-5f4c0bb/) | cvar | ui | Controls `ui_r_intensity` in the ui module. |
| [`ui_r_lightMap`](/TaystJK/reference/cvars/ui_r_lightmap-97c7b14/) | cvar | ui | Controls `ui_r_lightMap` in the ui module. |
| [`ui_r_lodbias`](/TaystJK/reference/cvars/ui_r_lodbias-7ae11a3/) | cvar | ui | Controls `ui_r_lodbias` in the ui module. |
| [`ui_r_mode`](/TaystJK/reference/cvars/ui_r_mode-c847d5b/) | cvar | ui | Controls `ui_r_mode` in the ui module. |
| [`ui_r_modified`](/TaystJK/reference/cvars/ui_r_modified-31a56f1/) | cvar | ui | Controls `ui_r_modified` in the ui module. |
| [`ui_r_parallaxmapping`](/TaystJK/reference/cvars/ui_r_parallaxmapping-5756301/) | cvar | ui | Controls `ui_r_parallaxmapping` in the ui module. |
| [`ui_r_picmip`](/TaystJK/reference/cvars/ui_r_picmip-643c4bd/) | cvar | ui | Controls `ui_r_picmip` in the ui module. |
| [`ui_r_picmip_custom`](/TaystJK/reference/cvars/ui_r_picmip_custom-fe590f2/) | cvar | ui | Controls `ui_r_picmip_custom` in the ui module. |
| [`ui_r_ssao`](/TaystJK/reference/cvars/ui_r_ssao-81f91aa/) | cvar | ui | Controls `ui_r_ssao` in the ui module. |
| [`ui_r_subdivisions`](/TaystJK/reference/cvars/ui_r_subdivisions-a364fcd/) | cvar | ui | Controls `ui_r_subdivisions` in the ui module. |
| [`ui_r_texturebits`](/TaystJK/reference/cvars/ui_r_texturebits-548dadc/) | cvar | ui | Controls `ui_r_texturebits` in the ui module. |
| [`ui_r_texturemode`](/TaystJK/reference/cvars/ui_r_texturemode-a7e1e5d/) | cvar | ui | Controls `ui_r_texturemode` in the ui module. |
| [`ui_r_tonemap`](/TaystJK/reference/cvars/ui_r_tonemap-22bf8a3/) | cvar | ui | Controls `ui_r_tonemap` in the ui module. |
| [`ui_r_vertexLight`](/TaystJK/reference/cvars/ui_r_vertexlight-78fd857/) | cvar | ui | Controls `ui_r_vertexLight` in the ui module. |
| [`ui_raceMode`](/TaystJK/reference/cvars/ui_racemode-0db81ac/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_rankChange`](/TaystJK/reference/cvars/ui_rankchange-ccf6b2b/) | cvar | ui | Controls `ui_rankChange` in the ui module. |
| [`ui_recordSPDemo`](/TaystJK/reference/cvars/ui_recordspdemo-44187ba/) | cvar | ui | Controls `ui_recordSPDemo` in the ui module. |
| [`ui_recordSPDemoName`](/TaystJK/reference/cvars/ui_recordspdemoname-ee64901/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_redteam`](/TaystJK/reference/cvars/ui_redteam-6b35b92/) | cvar | ui | Controls `ui_redteam` in the ui module. |
| [`ui_redteam2`](/TaystJK/reference/cvars/ui_redteam2-49de4e1/) | cvar | ui | Controls `ui_redteam2` in the ui module. |
| [`ui_redteam3`](/TaystJK/reference/cvars/ui_redteam3-5f1890f/) | cvar | ui | Controls `ui_redteam3` in the ui module. |
| [`ui_redteam4`](/TaystJK/reference/cvars/ui_redteam4-665ae9e/) | cvar | ui | Controls `ui_redteam4` in the ui module. |
| [`ui_redteam5`](/TaystJK/reference/cvars/ui_redteam5-7facc52/) | cvar | ui | Controls `ui_redteam5` in the ui module. |
| [`ui_redteam6`](/TaystJK/reference/cvars/ui_redteam6-216c2b4/) | cvar | ui | Controls `ui_redteam6` in the ui module. |
| [`ui_redteam7`](/TaystJK/reference/cvars/ui_redteam7-3764a86/) | cvar | ui | Controls `ui_redteam7` in the ui module. |
| [`ui_redteam8`](/TaystJK/reference/cvars/ui_redteam8-75f4165/) | cvar | ui | Controls `ui_redteam8` in the ui module. |
| [`ui_resolution`](/TaystJK/reference/cvars/ui_resolution-97111d4/) | cvar | ui | Controls `ui_resolution` in the ui module. |
| [`ui_RGBSkin`](/TaystJK/reference/cvars/ui_rgbskin-9bfb7fc/) | cvar | ui | Controls `ui_RGBSkin` in the ui module. |
| [`ui_rules_backout`](/TaystJK/reference/cvars/ui_rules_backout-43fffab/) | cvar | ui | Controls `ui_rules_backout` in the ui module. |
| [`ui_sab1_b`](/TaystJK/reference/cvars/ui_sab1_b-3ba84b3/) | cvar | ui | Controls `ui_sab1_b` in the ui module. |
| [`ui_sab1_g`](/TaystJK/reference/cvars/ui_sab1_g-f26e57f/) | cvar | ui | Controls `ui_sab1_g` in the ui module. |
| [`ui_sab1_r`](/TaystJK/reference/cvars/ui_sab1_r-221f80f/) | cvar | ui | Controls `ui_sab1_r` in the ui module. |
| [`ui_sab2_b`](/TaystJK/reference/cvars/ui_sab2_b-96e5422/) | cvar | ui | Controls `ui_sab2_b` in the ui module. |
| [`ui_sab2_g`](/TaystJK/reference/cvars/ui_sab2_g-77c298e/) | cvar | ui | Controls `ui_sab2_g` in the ui module. |
| [`ui_sab2_r`](/TaystJK/reference/cvars/ui_sab2_r-9570b88/) | cvar | ui | Controls `ui_sab2_r` in the ui module. |
| [`ui_saber`](/TaystJK/reference/cvars/ui_saber-71ba6a0/) | cvar | ui | Controls `ui_saber` in the ui module. |
| [`ui_saber2`](/TaystJK/reference/cvars/ui_saber2-bf4c5fb/) | cvar | ui | Controls `ui_saber2` in the ui module. |
| [`ui_saber2_color`](/TaystJK/reference/cvars/ui_saber2_color-f8b16cc/) | cvar | ui | Controls `ui_saber2_color` in the ui module. |
| [`ui_saber_color`](/TaystJK/reference/cvars/ui_saber_color-b952b9a/) | cvar | ui | Controls `ui_saber_color` in the ui module. |
| [`ui_saber_type`](/TaystJK/reference/cvars/ui_saber_type-64a96ba/) | cvar | ui | Controls `ui_saber_type` in the ui module. |
| [`ui_saveCaptureLimit`](/TaystJK/reference/cvars/ui_savecapturelimit-6abe884/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_saveDuelLimit`](/TaystJK/reference/cvars/ui_saveduellimit-32fae8f/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_saveFragLimit`](/TaystJK/reference/cvars/ui_savefraglimit-5b77a89/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreAccuracy`](/TaystJK/reference/cvars/ui_scoreaccuracy-5d5cf15/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreAssists`](/TaystJK/reference/cvars/ui_scoreassists-0c89a87/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreBase`](/TaystJK/reference/cvars/ui_scorebase-32f4ade/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreCaptures`](/TaystJK/reference/cvars/ui_scorecaptures-3988e53/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreDefends`](/TaystJK/reference/cvars/ui_scoredefends-b3729af/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreExcellents`](/TaystJK/reference/cvars/ui_scoreexcellents-2ff7ed1/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreGauntlets`](/TaystJK/reference/cvars/ui_scoregauntlets-72788c3/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreImpressives`](/TaystJK/reference/cvars/ui_scoreimpressives-f849016/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreMap`](/TaystJK/reference/cvars/ui_scoremap-89ac401/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scorePerfect`](/TaystJK/reference/cvars/ui_scoreperfect-3cd27c8/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreScore`](/TaystJK/reference/cvars/ui_scorescore-3d05888/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreShutoutBonus`](/TaystJK/reference/cvars/ui_scoreshutoutbonus-07f5014/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreSkillBonus`](/TaystJK/reference/cvars/ui_scoreskillbonus-91d5bda/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreTeam`](/TaystJK/reference/cvars/ui_scoreteam-d324531/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreTime`](/TaystJK/reference/cvars/ui_scoretime-6f45bec/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreTimeBonus`](/TaystJK/reference/cvars/ui_scoretimebonus-ba25d5e/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_screenshotType`](/TaystJK/reference/cvars/ui_screenshottype-77cec01/) | cvar | ui | Controls `ui_screenshotType` in the ui module. |
| [`ui_selectedModelIndex`](/TaystJK/reference/cvars/ui_selectedmodelindex-659d4e5/) | cvar | ui | Controls `ui_selectedModelIndex` in the ui module. |
| [`ui_serverFilterType`](/TaystJK/reference/cvars/ui_serverfiltertype-0e36b83/) | cvar | ui | Controls `ui_serverFilterType` in the ui module. |
| [`ui_serverStatusTimeOut`](/TaystJK/reference/cvars/ui_serverstatustimeout-133ca4a/) | cvar | ui | Controls `ui_serverStatusTimeOut` in the ui module. |
| [`ui_sha_a`](/TaystJK/reference/cvars/ui_sha_a-a8e4932/) | cvar | ui | Controls `ui_sha_a` in the ui module. |
| [`ui_sha_b`](/TaystJK/reference/cvars/ui_sha_b-0e69c90/) | cvar | ui | Controls `ui_sha_b` in the ui module. |
| [`ui_sha_g`](/TaystJK/reference/cvars/ui_sha_g-ac3139d/) | cvar | ui | Controls `ui_sha_g` in the ui module. |
| [`ui_sha_r`](/TaystJK/reference/cvars/ui_sha_r-2be1fbe/) | cvar | ui | Controls `ui_sha_r` in the ui module. |
| [`ui_showAllSkins`](/TaystJK/reference/cvars/ui_showallskins-069498a/) | cvar | ui | Controls `ui_showAllSkins` in the ui module. |
| [`ui_siegeTimer`](/TaystJK/reference/cvars/ui_siegetimer-2d873ef/) | cvar | cgame | Controls `ui_siegeTimer` in the cgame module. |
| [`ui_singlePlayerActive`](/TaystJK/reference/cvars/ui_singleplayeractive-d8349a1/) | cvar | ui | Controls `ui_singlePlayerActive` in the ui module. |
| [`ui_startsiegeclass`](/TaystJK/reference/cvars/ui_startsiegeclass-69ac34c/) | cvar | ui | Controls `ui_startsiegeclass` in the ui module. |
| [`ui_startsiegeteam`](/TaystJK/reference/cvars/ui_startsiegeteam-a546d1c/) | cvar | ui | Controls `ui_startsiegeteam` in the ui module. |
| [`ui_support_cnt`](/TaystJK/reference/cvars/ui_support_cnt-dc2cd26/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_sv_pure`](/TaystJK/reference/cvars/ui_sv_pure-05aa09d/) | cvar | ui | Controls `ui_sv_pure` in the ui module. |
| [`ui_team`](/TaystJK/reference/cvars/ui_team-9c61cf2/) | cvar | ui | Controls `ui_team` in the ui module. |
| [`ui_team_fraglimit`](/TaystJK/reference/cvars/ui_team_fraglimit-91b6e91/) | cvar | ui | Controls `ui_team_fraglimit` in the ui module. |
| [`ui_team_friendly`](/TaystJK/reference/cvars/ui_team_friendly-a4d19b4/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_team_timelimit`](/TaystJK/reference/cvars/ui_team_timelimit-23b0f17/) | cvar | ui | Controls `ui_team_timelimit` in the ui module. |
| [`ui_teamSize`](/TaystJK/reference/cvars/ui_teamsize-7d2c5d8/) | cvar | ui | Controls `ui_teamSize` in the ui module. |
| [`ui_tm1_c0_cnt`](/TaystJK/reference/cvars/ui_tm1_c0_cnt-6969d05/) | cvar | cgame | Controls `ui_tm1_c0_cnt` in the cgame module. |
| [`ui_tm1_c1_cnt`](/TaystJK/reference/cvars/ui_tm1_c1_cnt-adca072/) | cvar | cgame | Controls `ui_tm1_c1_cnt` in the cgame module. |
| [`ui_tm1_c2_cnt`](/TaystJK/reference/cvars/ui_tm1_c2_cnt-ffb7dfb/) | cvar | cgame | Controls `ui_tm1_c2_cnt` in the cgame module. |
| [`ui_tm1_c3_cnt`](/TaystJK/reference/cvars/ui_tm1_c3_cnt-19a03be/) | cvar | cgame | Controls `ui_tm1_c3_cnt` in the cgame module. |
| [`ui_tm1_c4_cnt`](/TaystJK/reference/cvars/ui_tm1_c4_cnt-dfd1642/) | cvar | cgame | Controls `ui_tm1_c4_cnt` in the cgame module. |
| [`ui_tm1_c5_cnt`](/TaystJK/reference/cvars/ui_tm1_c5_cnt-2faa522/) | cvar | cgame | Controls `ui_tm1_c5_cnt` in the cgame module. |
| [`ui_tm1_cnt`](/TaystJK/reference/cvars/ui_tm1_cnt-a83c5ab/) | cvar | cgame | Controls `ui_tm1_cnt` in the cgame module. |
| [`ui_tm2_c0_cnt`](/TaystJK/reference/cvars/ui_tm2_c0_cnt-0b18292/) | cvar | cgame | Controls `ui_tm2_c0_cnt` in the cgame module. |
| [`ui_tm2_c1_cnt`](/TaystJK/reference/cvars/ui_tm2_c1_cnt-bd46ba2/) | cvar | cgame | Controls `ui_tm2_c1_cnt` in the cgame module. |
| [`ui_tm2_c2_cnt`](/TaystJK/reference/cvars/ui_tm2_c2_cnt-ccda017/) | cvar | cgame | Controls `ui_tm2_c2_cnt` in the cgame module. |
| [`ui_tm2_c3_cnt`](/TaystJK/reference/cvars/ui_tm2_c3_cnt-02a4ab2/) | cvar | cgame | Controls `ui_tm2_c3_cnt` in the cgame module. |
| [`ui_tm2_c4_cnt`](/TaystJK/reference/cvars/ui_tm2_c4_cnt-e659b3d/) | cvar | cgame | Controls `ui_tm2_c4_cnt` in the cgame module. |
| [`ui_tm2_c5_cnt`](/TaystJK/reference/cvars/ui_tm2_c5_cnt-57587a0/) | cvar | cgame | Controls `ui_tm2_c5_cnt` in the cgame module. |
| [`ui_tm2_cnt`](/TaystJK/reference/cvars/ui_tm2_cnt-abb217e/) | cvar | cgame | Controls `ui_tm2_cnt` in the cgame module. |
| [`ui_tm3_cnt`](/TaystJK/reference/cvars/ui_tm3_cnt-f359456/) | cvar | cgame | Controls `ui_tm3_cnt` in the cgame module. |
| [`ui_tribesMode`](/TaystJK/reference/cvars/ui_tribesmode-cc54205/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_username`](/TaystJK/reference/cvars/ui_username-1211939/) | cvar | ui | Controls `ui_username` in the ui module. |
| [`ui_vanguard_cnt`](/TaystJK/reference/cvars/ui_vanguard_cnt-41c56e2/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_version`](/TaystJK/reference/cvars/ui_version-b1d5a5a/) | cvar | cgame | Used by UI in the in-game "about" menu |
| [`ui_vgs`](/TaystJK/reference/cvars/ui_vgs-6f63532/) | cvar | ui | Controls `ui_vgs` in the ui module. |
| [`ui_vidrestart`](/TaystJK/reference/cvars/ui_vidrestart-724a091/) | cvar | ui | Controls `ui_vidrestart` in the ui module. |
| [`ui_Warmup`](/TaystJK/reference/cvars/ui_warmup-90318b8/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`username`](/TaystJK/reference/cvars/username-249ba36/) | cvar | engine-shared | Controls `username` in the engine-shared module. |
| [`version`](/TaystJK/reference/cvars/version-c692273/) | cvar | engine-shared | Registered by the current source, but no user-facing behavior description has been verified. |
| [`vid_xpos`](/TaystJK/reference/cvars/vid_xpos-617b8c0/) | cvar | engine-shared | Controls `vid_xpos` in the engine-shared module. |
| [`vid_ypos`](/TaystJK/reference/cvars/vid_ypos-a66867d/) | cvar | engine-shared | Controls `vid_ypos` in the engine-shared module. |
| [`vm_legacy`](/TaystJK/reference/cvars/vm_legacy-cfedd35/) | cvar | engine-shared | Controls `vm_legacy` in the engine-shared module. |
| [`volume`](/TaystJK/reference/cvars/volume-d387fc8/) | cvar | engine-client | Volume |
| [`+button15`](/TaystJK/reference/commands/plusminus-button15-6428f06/) | command | engine-client | Button 15 |
| [`+duck`](/TaystJK/reference/commands/plusminus-duck-1aea248/) | command | cgame | Runs `CG_NorollDown_f` in the cgame module. |
| [`+grapple`](/TaystJK/reference/commands/plusminus-grapple-74f23a8/) | command | cgame | Runs `CG_GrappleDown_f` in the cgame module. |
| [`+scores`](/TaystJK/reference/commands/plusminus-scores-d436431/) | command | cgame | Runs `CG_ScoresDown_f` in the cgame module. |
| [`+singlefire`](/TaystJK/reference/commands/plusminus-singlefire-e166917/) | command | cgame | Runs `CG_SingleFireDown_f` in the cgame module. |
| [`+zoom`](/TaystJK/reference/commands/plusminus-zoom-0eb4e7d/) | command | cgame | Runs `CG_ZoomDown_f` in the cgame module. |
| [`-altattack`](/TaystJK/reference/commands/minus-altattack-0273d3a/) | command | engine-client | Runs `IN_Button7Up` in the engine-client module. |
| [`-attack`](/TaystJK/reference/commands/minus-attack-e43abab/) | command | engine-client | Runs `IN_Button0Up` in the engine-client module. |
| [`-back`](/TaystJK/reference/commands/minus-back-9d738c1/) | command | engine-client | Runs `IN_BackUp` in the engine-client module. |
| [`-button0`](/TaystJK/reference/commands/minus-button0-0c59ac3/) | command | engine-client | Runs `IN_Button0Up` in the engine-client module. |
| [`-button1`](/TaystJK/reference/commands/minus-button1-1f0afc2/) | command | engine-client | Runs `IN_Button1Up` in the engine-client module. |
| [`-button10`](/TaystJK/reference/commands/minus-button10-ecaa3f2/) | command | engine-client | Runs `IN_Button10Up` in the engine-client module. |
| [`-button11`](/TaystJK/reference/commands/minus-button11-72100b7/) | command | engine-client | Runs `IN_Button11Up` in the engine-client module. |
| [`-button12`](/TaystJK/reference/commands/minus-button12-34f0dd4/) | command | engine-client | Runs `IN_Button12Up` in the engine-client module. |
| [`-button13`](/TaystJK/reference/commands/minus-button13-29fece4/) | command | engine-client | Runs `IN_Button13Up` in the engine-client module. |
| [`-button14`](/TaystJK/reference/commands/minus-button14-cc48ee5/) | command | engine-client | Runs `IN_Button14Up` in the engine-client module. |
| [`-button15`](/TaystJK/reference/commands/minus-button15-95d61e3/) | command | engine-client | Runs `IN_Button15Up` in the engine-client module. |
| [`-button2`](/TaystJK/reference/commands/minus-button2-09a0451/) | command | engine-client | Runs `IN_Button2Up` in the engine-client module. |
| [`-button3`](/TaystJK/reference/commands/minus-button3-d59f20f/) | command | engine-client | Runs `IN_Button3Up` in the engine-client module. |
| [`-button4`](/TaystJK/reference/commands/minus-button4-e553417/) | command | engine-client | Runs `IN_Button4Up` in the engine-client module. |
| [`-button5`](/TaystJK/reference/commands/minus-button5-ccc9730/) | command | engine-client | Runs `IN_Button5Up` in the engine-client module. |
| [`-button6`](/TaystJK/reference/commands/minus-button6-073c01d/) | command | engine-client | Runs `IN_Button6Up` in the engine-client module. |
| [`-button7`](/TaystJK/reference/commands/minus-button7-1028e4d/) | command | engine-client | Runs `IN_Button7Up` in the engine-client module. |
| [`-button8`](/TaystJK/reference/commands/minus-button8-44eb725/) | command | engine-client | Runs `IN_Button8Up` in the engine-client module. |
| [`-button9`](/TaystJK/reference/commands/minus-button9-70255ea/) | command | engine-client | Runs `IN_Button9Up` in the engine-client module. |
| [`-duck`](/TaystJK/reference/commands/minus-duck-e229dd0/) | command | cgame | Runs `CG_NorollUp_f` in the cgame module. |
| [`-force_drain`](/TaystJK/reference/commands/minus-force_drain-8150067/) | command | engine-client | Runs `IN_Button11Up` in the engine-client module. |
| [`-force_grip`](/TaystJK/reference/commands/minus-force_grip-e61faf8/) | command | engine-client | Runs `IN_Button6Up` in the engine-client module. |
| [`-force_lightning`](/TaystJK/reference/commands/minus-force_lightning-58e7bf3/) | command | engine-client | Runs `IN_Button10Up` in the engine-client module. |
| [`-forward`](/TaystJK/reference/commands/minus-forward-780292f/) | command | engine-client | Runs `IN_ForwardUp` in the engine-client module. |
| [`-grapple`](/TaystJK/reference/commands/minus-grapple-b7c9090/) | command | cgame | Runs `CG_GrappleUp_f` in the cgame module. |
| [`-left`](/TaystJK/reference/commands/minus-left-adf5fbd/) | command | engine-client | Runs `IN_LeftUp` in the engine-client module. |
| [`-lookdown`](/TaystJK/reference/commands/minus-lookdown-93d6cd0/) | command | engine-client | Runs `IN_LookdownUp` in the engine-client module. |
| [`-lookup`](/TaystJK/reference/commands/minus-lookup-8aa409f/) | command | engine-client | Runs `IN_LookupUp` in the engine-client module. |
| [`-mlook`](/TaystJK/reference/commands/minus-mlook-94b9765/) | command | engine-client | Runs `IN_MLookUp` in the engine-client module. |
| [`-movedown`](/TaystJK/reference/commands/minus-movedown-4fdaa04/) | command | engine-client | Runs `IN_DownUp` in the engine-client module. |
| [`-moveleft`](/TaystJK/reference/commands/minus-moveleft-b288f12/) | command | engine-client | Runs `IN_MoveleftUp` in the engine-client module. |
| [`-moveright`](/TaystJK/reference/commands/minus-moveright-7382f10/) | command | engine-client | Runs `IN_MoverightUp` in the engine-client module. |
| [`-moveup`](/TaystJK/reference/commands/minus-moveup-356a171/) | command | engine-client | Runs `IN_UpUp` in the engine-client module. |
| [`-right`](/TaystJK/reference/commands/minus-right-a838480/) | command | engine-client | Runs `IN_RightUp` in the engine-client module. |
| [`-scores`](/TaystJK/reference/commands/minus-scores-a8f4d4c/) | command | cgame | Runs `CG_ScoresUp_f` in the cgame module. |
| [`-singlefire`](/TaystJK/reference/commands/minus-singlefire-9763ac0/) | command | cgame | Runs `CG_SingleFireUp_f` in the cgame module. |
| [`-speed`](/TaystJK/reference/commands/minus-speed-abca6cc/) | command | engine-client | Runs `IN_SpeedUp` in the engine-client module. |
| [`-strafe`](/TaystJK/reference/commands/minus-strafe-fd501b2/) | command | engine-client | Runs `IN_StrafeUp` in the engine-client module. |
| [`-use`](/TaystJK/reference/commands/minus-use-4c6096b/) | command | engine-client | Runs `IN_Button5Up` in the engine-client module. |
| [`-useforce`](/TaystJK/reference/commands/minus-useforce-92d91ec/) | command | engine-client | Runs `IN_Button9Up` in the engine-client module. |
| [`-zoom`](/TaystJK/reference/commands/minus-zoom-972df81/) | command | cgame | Runs `CG_ZoomUp_f` in the cgame module. |
| [`accountInfo`](/TaystJK/reference/commands/accountinfo-e041bfd/) | command | game | Runs `Svcmd_AccountInfo_f` in the game module. |
| [`addbot`](/TaystJK/reference/commands/addbot-fec764b/) | command | cgame | Forwards this command to the connected game server. |
| [`addCheckpoint`](/TaystJK/reference/commands/addcheckpoint-7c51bf3/) | command | cgame | Runs `CG_AddCheckpoint_f` in the cgame module. |
| [`addFavorite`](/TaystJK/reference/commands/addfavorite-26823da/) | command | engine-client | Add server to favorites |
| [`addip`](/TaystJK/reference/commands/addip-5d88fb5/) | command | game | Runs `Svcmd_AddIP_f` in the game module. |
| [`addSpeedsound`](/TaystJK/reference/commands/addspeedsound-ab9ed14/) | command | cgame | Runs `CG_AddSpeedpoint_f` in the cgame module. |
| [`admCmdExe`](/TaystJK/reference/commands/admcmdexe-0988c2c/) | command | cgame | Forwards this command to the connected game server. |
| [`admCmdNext`](/TaystJK/reference/commands/admcmdnext-f31dbec/) | command | cgame | Forwards this command to the connected game server. |
| [`admCmdPrev`](/TaystJK/reference/commands/admcmdprev-a0e8fff/) | command | cgame | Forwards this command to the connected game server. |
| [`afk`](/TaystJK/reference/commands/afk-aec4e2a/) | command | engine-client | Rename to or from afk |
| [`amAltDim`](/TaystJK/reference/commands/amaltdim-6000039/) | command | cgame | Forwards this command to the connected game server. |
| [`amBan`](/TaystJK/reference/commands/amban-ac16303/) | command | cgame | Forwards this command to the connected game server. |
| [`amBeg`](/TaystJK/reference/commands/ambeg-ab94735/) | command | cgame | EMOTE |
| [`amBeg2`](/TaystJK/reference/commands/ambeg2-b509e29/) | command | cgame | EMOTE |
| [`ambernie`](/TaystJK/reference/commands/ambernie-ddb034a/) | command | game | EMOTE |
| [`amBreakDance`](/TaystJK/reference/commands/ambreakdance-1ce554f/) | command | cgame | EMOTE |
| [`amBreakDance2`](/TaystJK/reference/commands/ambreakdance2-3aab390/) | command | cgame | EMOTE |
| [`amBreakDance3`](/TaystJK/reference/commands/ambreakdance3-e2c5a04/) | command | cgame | EMOTE |
| [`amBreakDance4`](/TaystJK/reference/commands/ambreakdance4-3f4d2e8/) | command | cgame | EMOTE |
| [`amCheer`](/TaystJK/reference/commands/amcheer-e272fa7/) | command | cgame | EMOTE |
| [`amColor`](/TaystJK/reference/commands/amcolor-c9ed5c5/) | command | cgame | Forwards this command to the connected game server. |
| [`amCower`](/TaystJK/reference/commands/amcower-649ad64/) | command | cgame | EMOTE |
| [`amDance`](/TaystJK/reference/commands/amdance-c348eaa/) | command | cgame | EMOTE |
| [`amDenyVote`](/TaystJK/reference/commands/amdenyvote-8aee951/) | command | cgame | Forwards this command to the connected game server. |
| [`amDmgs`](/TaystJK/reference/commands/amdmgs-85b216b/) | command | cgame | Forwards this command to the connected game server. |
| [`amEmpower`](/TaystJK/reference/commands/amempower-738ceb5/) | command | cgame | Forwards this command to the connected game server. |
| [`amflip`](/TaystJK/reference/commands/amflip-0e01241/) | command | game | EMOTE |
| [`amForceAltDim`](/TaystJK/reference/commands/amforcealtdim-8a66f13/) | command | cgame | Forwards this command to the connected game server. |
| [`amForceTeam`](/TaystJK/reference/commands/amforceteam-7b44929/) | command | cgame | Forwards this command to the connected game server. |
| [`amFreeze`](/TaystJK/reference/commands/amfreeze-01cf6fd/) | command | cgame | Forwards this command to the connected game server. |
| [`amGhost`](/TaystJK/reference/commands/amghost-b436575/) | command | cgame | Forwards this command to the connected game server. |
| [`amGrantAdmin`](/TaystJK/reference/commands/amgrantadmin-4e5383a/) | command | cgame | Forwards this command to the connected game server. |
| [`amHug`](/TaystJK/reference/commands/amhug-82335a1/) | command | cgame | EMOTE |
| [`amInfo`](/TaystJK/reference/commands/aminfo-b53555a/) | command | cgame | Forwards this command to the connected game server. |
| [`amKick`](/TaystJK/reference/commands/amkick-2f00271/) | command | cgame | Forwards this command to the connected game server. |
| [`amKillVote`](/TaystJK/reference/commands/amkillvote-267af5c/) | command | cgame | Forwards this command to the connected game server. |
| [`amListMaps`](/TaystJK/reference/commands/amlistmaps-f83ab3c/) | command | cgame | Forwards this command to the connected game server. |
| [`amLockTeam`](/TaystJK/reference/commands/amlockteam-01e4806/) | command | cgame | Forwards this command to the connected game server. |
| [`amLogin`](/TaystJK/reference/commands/amlogin-0aff778/) | command | cgame | Forwards this command to the connected game server. |
| [`amLogout`](/TaystJK/reference/commands/amlogout-da89c31/) | command | cgame | Forwards this command to the connected game server. |
| [`amLookup`](/TaystJK/reference/commands/amlookup-0f303d7/) | command | cgame | Forwards this command to the connected game server. |
| [`amMap`](/TaystJK/reference/commands/ammap-7644e0b/) | command | cgame | Forwards this command to the connected game server. |
| [`amMerc`](/TaystJK/reference/commands/ammerc-34da96f/) | command | cgame | Forwards this command to the connected game server. |
| [`amMindTrick`](/TaystJK/reference/commands/ammindtrick-79013b1/) | command | cgame | Forwards this command to the connected game server. |
| [`amMotd`](/TaystJK/reference/commands/ammotd-5b85bc2/) | command | cgame | Forwards this command to the connected game server. |
| [`amMove`](/TaystJK/reference/commands/ammove-bc82282/) | command | cgame | Forwards this command to the connected game server. |
| [`amNoisy`](/TaystJK/reference/commands/amnoisy-fa20b9b/) | command | cgame | EMOTE |
| [`amPoint`](/TaystJK/reference/commands/ampoint-58ede89/) | command | cgame | EMOTE |
| [`amPoll`](/TaystJK/reference/commands/ampoll-ebab86e/) | command | cgame | Forwards this command to the connected game server. |
| [`amProtect`](/TaystJK/reference/commands/amprotect-604595f/) | command | cgame | Forwards this command to the connected game server. |
| [`ampSay`](/TaystJK/reference/commands/ampsay-c91ed51/) | command | cgame | Forwards this command to the connected game server. |
| [`amRage`](/TaystJK/reference/commands/amrage-79d8c3e/) | command | cgame | EMOTE |
| [`amRename`](/TaystJK/reference/commands/amrename-ad31e7c/) | command | cgame | Forwards this command to the connected game server. |
| [`amrun`](/TaystJK/reference/commands/amrun-373fdad/) | command | cgame | EMOTE |
| [`amSay`](/TaystJK/reference/commands/amsay-ef45240/) | command | cgame | Forwards this command to the connected game server. |
| [`amSeeGhost`](/TaystJK/reference/commands/amseeghost-383aa61/) | command | cgame | Forwards this command to the connected game server. |
| [`amShowMotd`](/TaystJK/reference/commands/amshowmotd-3ec94a1/) | command | cgame | Forwards this command to the connected game server. |
| [`amsignal`](/TaystJK/reference/commands/amsignal-1e13c57/) | command | game | EMOTE |
| [`amsignal2`](/TaystJK/reference/commands/amsignal2-f2de599/) | command | game | EMOTE |
| [`amsignal3`](/TaystJK/reference/commands/amsignal3-b6abb25/) | command | game | EMOTE |
| [`amsignal4`](/TaystJK/reference/commands/amsignal4-92650e2/) | command | game | EMOTE |
| [`amSilence`](/TaystJK/reference/commands/amsilence-0d4f91e/) | command | cgame | Forwards this command to the connected game server. |
| [`amSit`](/TaystJK/reference/commands/amsit-9d81b85/) | command | cgame | EMOTE |
| [`amSit2`](/TaystJK/reference/commands/amsit2-752a391/) | command | cgame | EMOTE |
| [`amSit3`](/TaystJK/reference/commands/amsit3-0cc6070/) | command | cgame | EMOTE |
| [`amSit4`](/TaystJK/reference/commands/amsit4-7ab8b7e/) | command | cgame | EMOTE |
| [`amSit5`](/TaystJK/reference/commands/amsit5-3281f99/) | command | cgame | EMOTE |
| [`amSlap`](/TaystJK/reference/commands/amslap-620092e/) | command | cgame | EMOTE |
| [`amSleep`](/TaystJK/reference/commands/amsleep-18eb1b4/) | command | cgame | EMOTE |
| [`amSmack`](/TaystJK/reference/commands/amsmack-21e8460/) | command | cgame | EMOTE |
| [`amStatus`](/TaystJK/reference/commands/amstatus-c75ade4/) | command | cgame | Forwards this command to the connected game server. |
| [`amSurrender`](/TaystJK/reference/commands/amsurrender-6e03fd5/) | command | cgame | EMOTE |
| [`amTaunt`](/TaystJK/reference/commands/amtaunt-3b4f992/) | command | cgame | EMOTE |
| [`amTaunt2`](/TaystJK/reference/commands/amtaunt2-e7be334/) | command | cgame | EMOTE |
| [`amTele`](/TaystJK/reference/commands/amtele-cbff2a5/) | command | cgame | Forwards this command to the connected game server. |
| [`amTeleMark`](/TaystJK/reference/commands/amtelemark-456039e/) | command | cgame | Forwards this command to the connected game server. |
| [`amUnForceAltDim`](/TaystJK/reference/commands/amunforcealtdim-9caf044/) | command | cgame | Forwards this command to the connected game server. |
| [`amVictory`](/TaystJK/reference/commands/amvictory-d06d5b4/) | command | cgame | EMOTE |
| [`amVstr`](/TaystJK/reference/commands/amvstr-e948c7e/) | command | cgame | Forwards this command to the connected game server. |
| [`amWait`](/TaystJK/reference/commands/amwait-8bd0bc7/) | command | cgame | Forwards this command to the connected game server. |
| [`amWake`](/TaystJK/reference/commands/amwake-799cb8f/) | command | cgame | Forwards this command to the connected game server. |
| [`amWeather`](/TaystJK/reference/commands/amweather-d7318f4/) | command | cgame | Forwards this command to the connected game server. |
| [`amWhois`](/TaystJK/reference/commands/amwhois-c3a6580/) | command | cgame | Forwards this command to the connected game server. |
| [`autoLogin`](/TaystJK/reference/commands/autologin-4739ac0/) | command | cgame | Runs `CG_Autologin_f` in the cgame module. |
| [`best`](/TaystJK/reference/commands/best-c5f5e4d/) | command | cgame | Forwards this command to the connected game server. |
| [`blink`](/TaystJK/reference/commands/blink-dcae3a7/) | command | game | Change for admin? |
| [`botlist`](/TaystJK/reference/commands/botlist-5978b77/) | command | game | Runs `Svcmd_BotList_f` in the game module. |
| [`briefing`](/TaystJK/reference/commands/briefing-c8e5d02/) | command | cgame | Runs `CG_SiegeBriefing_f` in the cgame module. |
| [`callteamvote`](/TaystJK/reference/commands/callteamvote-308e1e5/) | command | cgame | Forwards this command to the connected game server. |
| [`callvote`](/TaystJK/reference/commands/callvote-1457e21/) | command | cgame | Forwards this command to the connected game server. |
| [`cameraSettings`](/TaystJK/reference/commands/camerasettings-1e702fc/) | command | cgame | Runs `CG_ShowSpecCamera_f` in the cgame module. |
| [`capframes`](/TaystJK/reference/commands/capframes-e2a1440/) | command | renderer | Runs `R_CaptureFrameData_f` in the renderer module. |
| [`changePassword`](/TaystJK/reference/commands/changepassword-3dfd458/) | command | cgame | Forwards this command to the connected game server. |
| [`changeVectors`](/TaystJK/reference/commands/changevectors-7f0e466/) | command | engine-shared | Runs `MSG_ReportChangeVectors_f` in the engine-shared module. |
| [`chatlog`](/TaystJK/reference/commands/chatlog-84c4a99/) | command | cgame | Runs `CG_ChatLogSettings_f` in the cgame module. |
| [`clanAdmin`](/TaystJK/reference/commands/clanadmin-81aa5bc/) | command | cgame | Forwards this command to the connected game server. |
| [`clanCreate`](/TaystJK/reference/commands/clancreate-c8e06da/) | command | cgame | Forwards this command to the connected game server. |
| [`clandelete`](/TaystJK/reference/commands/clandelete-a4890f1/) | command | game | Runs `Svcmd_ClanDelete_f` in the game module. |
| [`clanInfo`](/TaystJK/reference/commands/claninfo-d03453d/) | command | cgame | Forwards this command to the connected game server. |
| [`clanInvite`](/TaystJK/reference/commands/claninvite-0b616bf/) | command | cgame | Forwards this command to the connected game server. |
| [`clanJoin`](/TaystJK/reference/commands/clanjoin-45d4991/) | command | cgame | Forwards this command to the connected game server. |
| [`clankick`](/TaystJK/reference/commands/clankick-2d626df/) | command | game | Runs `Svcmd_ClanKick_f` in the game module. |
| [`clanLeave`](/TaystJK/reference/commands/clanleave-4c3bb60/) | command | cgame | Forwards this command to the connected game server. |
| [`clanList`](/TaystJK/reference/commands/clanlist-0df1c7a/) | command | cgame | Forwards this command to the connected game server. |
| [`clanPass`](/TaystJK/reference/commands/clanpass-e0e73ba/) | command | cgame | Forwards this command to the connected game server. |
| [`clanSay`](/TaystJK/reference/commands/clansay-0ce04c4/) | command | cgame | Forwards this command to the connected game server. |
| [`clanWhoIs`](/TaystJK/reference/commands/clanwhois-fc4d7f9/) | command | cgame | Forwards this command to the connected game server. |
| [`clearIP`](/TaystJK/reference/commands/clearip-92535a0/) | command | game | Runs `Svcmd_ClearIP_f` in the game module. |
| [`clearRemaps`](/TaystJK/reference/commands/clearremaps-10c3c32/) | command | renderer | Runs `R_ClearRemaps_f` in the renderer module. |
| [`clearTrail`](/TaystJK/reference/commands/cleartrail-314b9f6/) | command | cgame | Runs `CG_DeleteStrafeTrail_f` in the cgame module. |
| [`clientlist`](/TaystJK/reference/commands/clientlist-62d48a1/) | command | cgame | Displays a list of all connected clients and their real client numbers |
| [`colorname`](/TaystJK/reference/commands/colorname-eccdd14/) | command | engine-client | Color name |
| [`colorstring`](/TaystJK/reference/commands/colorstring-ff62b1e/) | command | engine-client | Color say text |
| [`coop`](/TaystJK/reference/commands/coop-786e986/) | command | game | Runs `Cmd_Coop_f` in the game module. |
| [`cosmetics`](/TaystJK/reference/commands/cosmetics-01c96cf/) | command | cgame | Runs `CG_Cosmetics_f` in the cgame module. |
| [`crash`](/TaystJK/reference/commands/crash-2fc7f14/) | command | engine-shared | Runs `Com_Crash_f` in the engine-shared module. |
| [`crouchjump`](/TaystJK/reference/commands/crouchjump-c7353d9/) | command | game | Runs `Cmd_ToggleCrouchJump_f` in the game module. |
| [`cvar_modified`](/TaystJK/reference/commands/cvar_modified-57ded5d/) | command | engine-shared | Show all modified cvars |
| [`cvar_usercreated`](/TaystJK/reference/commands/cvar_usercreated-da65457/) | command | engine-shared | Show all user created cvars |
| [`cvarAdd`](/TaystJK/reference/commands/cvaradd-8d5c5e5/) | command | engine-shared | Add a value to a cvar |
| [`cvarDiv`](/TaystJK/reference/commands/cvardiv-3fd3bfe/) | command | engine-shared | Divide a value from a cvar |
| [`cvarMod`](/TaystJK/reference/commands/cvarmod-47b87cc/) | command | engine-shared | Apply a modulo on a cvar |
| [`cvarMult`](/TaystJK/reference/commands/cvarmult-0b82792/) | command | engine-shared | Multiply a value to a cvar |
| [`cvarSub`](/TaystJK/reference/commands/cvarsub-4aed04d/) | command | engine-shared | Subtract a value from a cvar |
| [`DBInfo`](/TaystJK/reference/commands/dbinfo-c214d31/) | command | game | Runs `Svcmd_DBInfo_f` in the game module. |
| [`debugBMove_Back`](/TaystJK/reference/commands/debugbmove_back-8f2da3b/) | command | game | Runs `Cmd_BotMoveBack_f` in the game module. |
| [`debugBMove_Forward`](/TaystJK/reference/commands/debugbmove_forward-250e663/) | command | game | Runs `Cmd_BotMoveForward_f` in the game module. |
| [`debugBMove_Left`](/TaystJK/reference/commands/debugbmove_left-cccb2f7/) | command | game | Runs `Cmd_BotMoveLeft_f` in the game module. |
| [`debugBMove_Right`](/TaystJK/reference/commands/debugbmove_right-e2fea90/) | command | game | Runs `Cmd_BotMoveRight_f` in the game module. |
| [`debugBMove_Up`](/TaystJK/reference/commands/debugbmove_up-17c32c6/) | command | game | Runs `Cmd_BotMoveUp_f` in the game module. |
| [`deleteAccount`](/TaystJK/reference/commands/deleteaccount-1669172/) | command | game | Runs `Svcmd_DeleteAccount_f` in the game module. |
| [`deleteCheckpoint`](/TaystJK/reference/commands/deletecheckpoint-ec6c155/) | command | cgame | Runs `CG_DeleteCheckpoint_f` in the cgame module. |
| [`deletedemo`](/TaystJK/reference/commands/deletedemo-4eee4c5/) | command | engine-client | Delete a demo |
| [`deleteSpeedsound`](/TaystJK/reference/commands/deletespeedsound-a3361cf/) | command | cgame | Runs `CG_DeleteSpeedpoint_f` in the cgame module. |
| [`do`](/TaystJK/reference/commands/do-eadcd9b/) | command | cgame | Runs `CG_Do_f` in the cgame module. |
| [`duelteam`](/TaystJK/reference/commands/duelteam-50e5f76/) | command | cgame | Forwards this command to the connected game server. |
| [`duelWhois`](/TaystJK/reference/commands/duelwhois-6600b90/) | command | cgame | Forwards this command to the connected game server. |
| [`entityinfo`](/TaystJK/reference/commands/entityinfo-1ca8b9f/) | command | game | Runs `Svcmd_EntityInfo_f` in the game module. |
| [`entitylist`](/TaystJK/reference/commands/entitylist-f09e360/) | command | game | Runs `Svcmd_EntityList_f` in the game module. |
| [`error`](/TaystJK/reference/commands/error-11f9578/) | command | engine-shared | Runs `Com_Error_f` in the engine-shared module. |
| [`execq`](/TaystJK/reference/commands/execq-48c51d3/) | command | engine-shared | Execute a script file without displaying a message |
| [`exit`](/TaystJK/reference/commands/exit-de3ac21/) | command | engine-shared | Exits the game |
| [`flagAccount`](/TaystJK/reference/commands/flagaccount-eeeecbc/) | command | game | Runs `Svcmd_FlagAccount_f` in the game module. |
| [`flagRecord`](/TaystJK/reference/commands/flagrecord-015800d/) | command | game | Runs `Cmd_InvalidateRace_f` in the game module. |
| [`flipkick`](/TaystJK/reference/commands/flipkick-844ca0a/) | command | cgame | Runs `CG_Flipkick_f` in the cgame module. |
| [`follow`](/TaystJK/reference/commands/follow-f7ac253/) | command | cgame | Forwards this command to the connected game server. |
| [`followBlueFlag`](/TaystJK/reference/commands/followblueflag-a574443/) | command | cgame | Runs `CG_FollowBlueFlag_f` in the cgame module. |
| [`followFastest`](/TaystJK/reference/commands/followfastest-66908f6/) | command | cgame | Runs `CG_FollowFastest_f` in the cgame module. |
| [`follownext`](/TaystJK/reference/commands/follownext-a152e2f/) | command | cgame | Forwards this command to the connected game server. |
| [`followprev`](/TaystJK/reference/commands/followprev-c5dcaa8/) | command | cgame | Forwards this command to the connected game server. |
| [`followRedFlag`](/TaystJK/reference/commands/followredflag-caadae2/) | command | cgame | Runs `CG_FollowRedFlag_f` in the cgame module. |
| [`fontlist`](/TaystJK/reference/commands/fontlist-83422e5/) | command | renderer | Runs `R_FontList_f` in the renderer module. |
| [`forcechanged`](/TaystJK/reference/commands/forcechanged-6b7cd08/) | command | cgame | Forwards this command to the connected game server. |
| [`forcenext`](/TaystJK/reference/commands/forcenext-f6f1a66/) | command | cgame | Runs `CG_NextForcePower_f` in the cgame module. |
| [`forcepowers`](/TaystJK/reference/commands/forcepowers-5f9594f/) | command | engine-client | Runs `CL_SetForcePowers_f` in the engine-client module. |
| [`forceprev`](/TaystJK/reference/commands/forceprev-2ea0d1f/) | command | cgame | Runs `CG_PrevForcePower_f` in the cgame module. |
| [`forceteam`](/TaystJK/reference/commands/forceteam-72a2634/) | command | game | Runs `Svcmd_ForceTeam_f` in the game module. |
| [`freeze`](/TaystJK/reference/commands/freeze-adcdee7/) | command | engine-shared | Runs `Com_Freeze_f` in the engine-shared module. |
| [`fs_restart`](/TaystJK/reference/commands/fs_restart-205ee49/) | command | engine-shared | Restarts the filesystem if no module is currently using files from a pk3 |
| [`game_memory`](/TaystJK/reference/commands/game_memory-84c83cc/) | command | game | Runs `Svcmd_GameMem_f` in the game module. |
| [`gametype`](/TaystJK/reference/commands/gametype-d7c6fe6/) | command | game | Instantly changethe gametype of the server without having to reload the map |
| [`gc`](/TaystJK/reference/commands/gc-ec6d908/) | command | game | Runs `Cmd_GameCommand_f` in the game module. |
| [`gfxinfo`](/TaystJK/reference/commands/gfxinfo-5473f68/) | command | renderer | Runs `GfxInfo_f` in the renderer module. |
| [`gfxmeminfo`](/TaystJK/reference/commands/gfxmeminfo-491be17/) | command | renderer | Runs `GfxMemInfo_f` in the renderer module. |
| [`give`](/TaystJK/reference/commands/give-fa9f22e/) | command | cgame | Forwards this command to the connected game server. |
| [`giveother`](/TaystJK/reference/commands/giveother-c475c5c/) | command | game | Runs `Cmd_GiveOther_f` in the game module. |
| [`god`](/TaystJK/reference/commands/god-21298df/) | command | cgame | Forwards this command to the connected game server. |
| [`haste`](/TaystJK/reference/commands/haste-08a06a9/) | command | game | Runs `Cmd_Haste_f` in the game module. |
| [`help`](/TaystJK/reference/commands/help-92005ec/) | command | cgame | Print command help |
| [`hide`](/TaystJK/reference/commands/hide-93c8c96/) | command | cgame | Forwards this command to the connected game server. |
| [`ifCvar`](/TaystJK/reference/commands/ifcvar-a68f57c/) | command | engine-shared | Execute a command selected by comparisons against a cvar. |
| [`ignoreVGS`](/TaystJK/reference/commands/ignorevgs-46dc77b/) | command | cgame | Runs `CG_IgnoreVGS_f` in the cgame module. |
| [`imagecacheinfo`](/TaystJK/reference/commands/imagecacheinfo-a198210/) | command | renderer | Runs `RE_RegisterImages_Info_f` in the renderer module. |
| [`imagelist`](/TaystJK/reference/commands/imagelist-4c06ba7/) | command | renderer | Runs `R_ImageList_f` in the renderer module. |
| [`in_restart`](/TaystJK/reference/commands/in_restart-b75c16f/) | command | engine-shared | Runs `IN_Restart` in the engine-shared module. |
| [`invfree`](/TaystJK/reference/commands/invfree-4c191c5/) | command | cgame | Runs `CG_InvUseAvailable` in the cgame module. |
| [`invnext`](/TaystJK/reference/commands/invnext-3271b96/) | command | cgame | Runs `CG_NextInventory_f` in the cgame module. |
| [`invprev`](/TaystJK/reference/commands/invprev-e6081df/) | command | cgame | Runs `CG_PrevInventory_f` in the cgame module. |
| [`jetpack`](/TaystJK/reference/commands/jetpack-806aec3/) | command | game | Runs `Cmd_Jetpack_f` in the game module. |
| [`jump`](/TaystJK/reference/commands/jump-271e9a5/) | command | cgame | Cmd_alive not needed but i think it resets on joingame cuz forcepoints? |
| [`kickall`](/TaystJK/reference/commands/kickall-7a42f1a/) | command | engine-server | Kick all users from the server |
| [`kickbots`](/TaystJK/reference/commands/kickbots-9695bdf/) | command | engine-server | Kick all bots from the server |
| [`kicknum`](/TaystJK/reference/commands/kicknum-43bb6d1/) | command | engine-server | Kick a user from the server by userid |
| [`kill`](/TaystJK/reference/commands/kill-c80f5bc/) | command | cgame | Forwards this command to the connected game server. |
| [`killother`](/TaystJK/reference/commands/killother-c24ec29/) | command | game | Runs `Cmd_KillOther_f` in the game module. |
| [`launch`](/TaystJK/reference/commands/launch-f7c91fe/) | command | cgame | Forwards this command to the connected game server. |
| [`levelshot`](/TaystJK/reference/commands/levelshot-eb585e1/) | command | cgame | Forwards this command to the connected game server. |
| [`listAdmins`](/TaystJK/reference/commands/listadmins-135e048/) | command | game | Runs `Svcmd_ListAdmins_f` in the game module. |
| [`listCheckpoints`](/TaystJK/reference/commands/listcheckpoints-86cf253/) | command | cgame | Runs `CG_ListCheckpoints_f` in the cgame module. |
| [`listEmojis`](/TaystJK/reference/commands/listemojis-4b9aa16/) | command | cgame | Runs `CG_ListEmojis_f` in the cgame module. |
| [`listip`](/TaystJK/reference/commands/listip-3cf3e51/) | command | game | Runs `Svcmd_ListIP_f` in the game module. |
| [`listRemaps`](/TaystJK/reference/commands/listremaps-ccb7058/) | command | cgame | Runs `CG_ListRemaps_f` in the cgame module. |
| [`listSpeedsounds`](/TaystJK/reference/commands/listspeedsounds-fb40338/) | command | cgame | Runs `CG_ListSpeedpoints_f` in the cgame module. |
| [`loaddefered`](/TaystJK/reference/commands/loaddefered-b9476e3/) | command | cgame | Forwards this command to the connected game server. |
| [`loaddeferred`](/TaystJK/reference/commands/loaddeferred-a84ce37/) | command | cgame | Runs `CG_LoadDeferredPlayers` in the cgame module. |
| [`loadhud`](/TaystJK/reference/commands/loadhud-0e6c052/) | command | cgame | Runs `CG_LoadHud_f` in the cgame module. |
| [`loadmod`](/TaystJK/reference/commands/loadmod-ab292a3/) | command | engine-client | Restart the renderer (with specified mod folder) - or change the resolution |
| [`loadTrail`](/TaystJK/reference/commands/loadtrail-490c577/) | command | cgame | Runs `CG_SpawnStrafeTrailFromCFG_f` in the cgame module. |
| [`login`](/TaystJK/reference/commands/login-2736fab/) | command | cgame | Forwards this command to the connected game server. |
| [`logout`](/TaystJK/reference/commands/logout-55525e1/) | command | cgame | Forwards this command to the connected game server. |
| [`lowjump`](/TaystJK/reference/commands/lowjump-5afc6c0/) | command | cgame | Runs `CG_Lowjump_f` in the cgame module. |
| [`mapents`](/TaystJK/reference/commands/mapents-8844ab0/) | command | game | Runs `Cmd_MapEnts_f` in the game module. |
| [`master`](/TaystJK/reference/commands/master-4f26aea/) | command | cgame | Forwards this command to the connected game server. |
| [`masterlist`](/TaystJK/reference/commands/masterlist-96e0292/) | command | cgame | Forwards this command to the connected game server. |
| [`migrateCheckpoints`](/TaystJK/reference/commands/migratecheckpoints-2796a98/) | command | game | Runs `SV_MigrateCheckpoints_f` in the game module. |
| [`minimize`](/TaystJK/reference/commands/minimize-0c3639c/) | command | engine-shared | Runs `GLimp_Minimize` in the engine-shared module. |
| [`modelcacheinfo`](/TaystJK/reference/commands/modelcacheinfo-86baf55/) | command | renderer | Runs `RE_RegisterModels_Info_f` in the renderer module. |
| [`modelist`](/TaystJK/reference/commands/modelist-5c7e939/) | command | engine-shared | Runs `R_ModeList_f` in the engine-shared module. |
| [`modellist`](/TaystJK/reference/commands/modellist-858000a/) | command | renderer | Runs `R_Modellist_f` in the renderer module. |
| [`modversion`](/TaystJK/reference/commands/modversion-73dac73/) | command | cgame | Runs `CG_ModVersion_f` in the cgame module. |
| [`move`](/TaystJK/reference/commands/move-379d6ce/) | command | cgame | Forwards this command to the connected game server. |
| [`mp3_calcvols`](/TaystJK/reference/commands/mp3_calcvols-80b9f54/) | command | engine-client | Runs `S_MP3_CalcVols_f` in the engine-client module. |
| [`nearby`](/TaystJK/reference/commands/nearby-8809020/) | command | game | Runs `Cmd_Nearby_f` in the game module. |
| [`nextframe`](/TaystJK/reference/commands/nextframe-23b6320/) | command | cgame | Runs `CG_TestModelNextFrame_f` in the cgame module. |
| [`nextskin`](/TaystJK/reference/commands/nextskin-4ecdde3/) | command | cgame | Runs `CG_TestModelNextSkin_f` in the cgame module. |
| [`notarget`](/TaystJK/reference/commands/notarget-ec14eef/) | command | cgame | Forwards this command to the connected game server. |
| [`notCompleted`](/TaystJK/reference/commands/notcompleted-ce96ded/) | command | cgame | Forwards this command to the connected game server. |
| [`NPC`](/TaystJK/reference/commands/npc-3b86d7d/) | command | cgame | Removed cheat for admin //meh let us npc kill all from spec |
| [`nudge`](/TaystJK/reference/commands/nudge-37e4ac9/) | command | game | Runs `Cmd_Nudge_f` in the game module. |
| [`origin`](/TaystJK/reference/commands/origin-b284f94/) | command | cgame | Forwards this command to the connected game server. |
| [`pack`](/TaystJK/reference/commands/pack-6acd621/) | command | game | Runs `Cmd_TribesPack_f` in the game module. |
| [`pause`](/TaystJK/reference/commands/pause-ef8d299/) | command | game | Pause/unpause the game |
| [`playdemo`](/TaystJK/reference/commands/playdemo-eb741af/) | command | engine-client | Playback a demo |
| [`playerNext`](/TaystJK/reference/commands/playernext-f53bdbc/) | command | cgame | Forwards this command to the connected game server. |
| [`playerPrev`](/TaystJK/reference/commands/playerprev-2b5e037/) | command | cgame | Forwards this command to the connected game server. |
| [`plugin`](/TaystJK/reference/commands/plugin-fd8c7c8/) | command | cgame | Runs `CG_PluginDisable_f` in the cgame module. |
| [`pluginDisable`](/TaystJK/reference/commands/plugindisable-98b2c24/) | command | cgame | Runs `CG_PluginDisable_f` in the cgame module. |
| [`practice`](/TaystJK/reference/commands/practice-e17674f/) | command | cgame | Forwards this command to the connected game server. |
| [`prevframe`](/TaystJK/reference/commands/prevframe-67fc671/) | command | cgame | Runs `CG_TestModelPrevFrame_f` in the cgame module. |
| [`prevskin`](/TaystJK/reference/commands/prevskin-d9924ca/) | command | cgame | Runs `CG_TestModelPrevSkin_f` in the cgame module. |
| [`print`](/TaystJK/reference/commands/print-6d0d587/) | command | engine-shared | Print cvar help |
| [`printStats`](/TaystJK/reference/commands/printstats-482f44d/) | command | cgame | Forwards this command to the connected game server. |
| [`PTele`](/TaystJK/reference/commands/ptele-fb0f4da/) | command | cgame | Runs `CG_PTele_f` in the cgame module. |
| [`PTelemark`](/TaystJK/reference/commands/ptelemark-8fcd18e/) | command | cgame | Runs `CG_PTelemark_f` in the cgame module. |
| [`r_atihack`](/TaystJK/reference/commands/r_atihack-d43dcf7/) | command | renderer | Runs `R_AtiHackToggle_f` in the renderer module. |
| [`r_cleardecals`](/TaystJK/reference/commands/r_cleardecals-243dbd7/) | command | renderer | Runs `RE_ClearDecals` in the renderer module. |
| [`r_we`](/TaystJK/reference/commands/r_we-8921bfa/) | command | renderer | Runs `R_WorldEffect_f` in the renderer module. |
| [`race`](/TaystJK/reference/commands/race-de4bedc/) | command | cgame | Forwards this command to the connected game server. |
| [`rCompare`](/TaystJK/reference/commands/rcompare-e6c9345/) | command | game | Runs `Cmd_DFCompare_f` in the game module. |
| [`rebuildElo`](/TaystJK/reference/commands/rebuildelo-eed7ec9/) | command | game | Delete all Elo records and rebuild them from the duel records in the database. |
| [`rebuildRaces`](/TaystJK/reference/commands/rebuildraces-de93639/) | command | game | Runs `SV_RebuildRaceRanks_f` in the game module. |
| [`rebuildUnlocks`](/TaystJK/reference/commands/rebuildunlocks-9112329/) | command | game | Runs `SV_RebuildUnlocks_f` in the game module. |
| [`register`](/TaystJK/reference/commands/register-13a2828/) | command | cgame | Forwards this command to the connected game server. |
| [`remapShader`](/TaystJK/reference/commands/remapshader-5315061/) | command | cgame | Runs `CG_RemapShader_f` in the cgame module. |
| [`remapSky`](/TaystJK/reference/commands/remapsky-55c2535/) | command | renderer | Runs `R_RemapSkyShader_f` in the renderer module. |
| [`removeip`](/TaystJK/reference/commands/removeip-38af509/) | command | game | Runs `Svcmd_RemoveIP_f` in the game module. |
| [`renameAccount`](/TaystJK/reference/commands/renameaccount-3fd6fd7/) | command | game | Runs `Svcmd_RenameAccount_f` in the game module. |
| [`resetScores`](/TaystJK/reference/commands/resetscores-5efac86/) | command | game | Reset all player/team scores without having to reload the map. |
| [`rFind`](/TaystJK/reference/commands/rfind-f2fd376/) | command | cgame | Forwards this command to the connected game server. |
| [`rHardest`](/TaystJK/reference/commands/rhardest-4250c13/) | command | cgame | Forwards this command to the connected game server. |
| [`rLatest`](/TaystJK/reference/commands/rlatest-fa0c7ce/) | command | cgame | Forwards this command to the connected game server. |
| [`rocketChange`](/TaystJK/reference/commands/rocketchange-f69e6d8/) | command | cgame | Forwards this command to the connected game server. |
| [`rPopular`](/TaystJK/reference/commands/rpopular-a69422f/) | command | cgame | Forwards this command to the connected game server. |
| [`rRank`](/TaystJK/reference/commands/rrank-4a8ddea/) | command | cgame | Forwards this command to the connected game server. |
| [`rTop`](/TaystJK/reference/commands/rtop-56f7fba/) | command | cgame | Forwards this command to the connected game server. |
| [`rWorst`](/TaystJK/reference/commands/rworst-00fab73/) | command | cgame | Forwards this command to the connected game server. |
| [`saber`](/TaystJK/reference/commands/saber-1b60697/) | command | cgame | Runs `CG_Saber_f` in the cgame module. |
| [`saberColor`](/TaystJK/reference/commands/sabercolor-78e6a36/) | command | cgame | Forwards this command to the connected game server. |
| [`saberDisable`](/TaystJK/reference/commands/saberdisable-cf2b094/) | command | game | Runs `Svcmd_ToggleSaberDisable_f` in the game module. |
| [`say`](/TaystJK/reference/commands/say-dc01c6b/) | command | cgame | Forwards this command to the connected game server. |
| [`say_team`](/TaystJK/reference/commands/say_team-bae6793/) | command | cgame | Forwards this command to the connected game server. |
| [`say_team_mod`](/TaystJK/reference/commands/say_team_mod-1d67bc8/) | command | cgame | Forwards this command to the connected game server. |
| [`score`](/TaystJK/reference/commands/score-75ebcb3/) | command | game | Runs `Cmd_Score_f` in the game module. |
| [`screenshot`](/TaystJK/reference/commands/screenshot-754d2e9/) | command | renderer | Runs `R_ScreenShotJPEG_f` in the renderer module. |
| [`screenshot_png`](/TaystJK/reference/commands/screenshot_png-78032a6/) | command | renderer | Runs `R_ScreenShotPNG_f` in the renderer module. |
| [`screenshot_tga`](/TaystJK/reference/commands/screenshot_tga-0b6a900/) | command | renderer | Runs `R_ScreenShotTGA_f` in the renderer module. |
| [`sectorlist`](/TaystJK/reference/commands/sectorlist-5e02669/) | command | engine-server | Runs `SV_SectorList_f` in the engine-server module. |
| [`selectfiremode`](/TaystJK/reference/commands/selectfiremode-bb9939e/) | command | cgame | Runs `CG_ToggleSingleFire_f` in the cgame module. |
| [`serverconfig`](/TaystJK/reference/commands/serverconfig-ee5ed61/) | command | cgame | Runs `CG_ServerConfig_f` in the cgame module. |
| [`shaderlist`](/TaystJK/reference/commands/shaderlist-a425a58/) | command | renderer | Runs `R_ShaderList_f` in the renderer module. |
| [`showNet`](/TaystJK/reference/commands/shownet-4d0ae0e/) | command | cgame | Forwards this command to the connected game server. |
| [`showPlayerId`](/TaystJK/reference/commands/showplayerid-eb4fbea/) | command | cgame | Runs `CG_ClientList_f` in the cgame module. |
| [`siegeclass`](/TaystJK/reference/commands/siegeclass-3ba0852/) | command | cgame | Forwards this command to the connected game server. |
| [`siegeCompleteCvarUpdate`](/TaystJK/reference/commands/siegecompletecvarupdate-73dd2e9/) | command | cgame | Runs `CG_SiegeCompleteCvarUpdate_f` in the cgame module. |
| [`siegeCvarUpdate`](/TaystJK/reference/commands/siegecvarupdate-85c4442/) | command | cgame | Runs `CG_SiegeCvarUpdate_f` in the cgame module. |
| [`sizedown`](/TaystJK/reference/commands/sizedown-b787541/) | command | cgame | Runs `CG_SizeDown_f` in the cgame module. |
| [`sizeup`](/TaystJK/reference/commands/sizeup-fb872d7/) | command | cgame | Runs `CG_SizeUp_f` in the cgame module. |
| [`skinlist`](/TaystJK/reference/commands/skinlist-f37b889/) | command | renderer | Runs `R_SkinList_f` in the renderer module. |
| [`slot`](/TaystJK/reference/commands/slot-462854f/) | command | cgame | Runs `CG_WeaponSlot_f` in the cgame module. |
| [`slotnext`](/TaystJK/reference/commands/slotnext-3dbba08/) | command | cgame | Runs `CG_PrevWeaponSlot_f` in the cgame module. |
| [`slotprev`](/TaystJK/reference/commands/slotprev-4fb55f3/) | command | cgame | Runs `CG_NextWeaponSlot_f` in the cgame module. |
| [`speedometer`](/TaystJK/reference/commands/speedometer-b0e26e4/) | command | cgame | Runs `CG_SpeedometerSettings_f` in the cgame module. |
| [`spot`](/TaystJK/reference/commands/spot-9f4b527/) | command | cgame | Forwards this command to the connected game server. |
| [`startingItems`](/TaystJK/reference/commands/startingitems-2ed82fa/) | command | game | Runs `Svcmd_ToggleStartingItems_f` in the game module. |
| [`startingWeapons`](/TaystJK/reference/commands/startingweapons-7252a71/) | command | game | Runs `Svcmd_ToggleStartingWeapons_f` in the game module. |
| [`startOrbit`](/TaystJK/reference/commands/startorbit-4e02c93/) | command | cgame | Runs `CG_StartOrbit_f` in the cgame module. |
| [`stopmusic`](/TaystJK/reference/commands/stopmusic-38c05b1/) | command | engine-client | Stops all music |
| [`stopvideo`](/TaystJK/reference/commands/stopvideo-db7ecec/) | command | engine-client | Stop avi recording |
| [`strafeHelper`](/TaystJK/reference/commands/strafehelper-bdb34b4/) | command | cgame | Runs `CG_StrafeHelper_f` in the cgame module. |
| [`strafeTrail`](/TaystJK/reference/commands/strafetrail-dddd025/) | command | cgame | Runs `CG_AddStrafeTrail_f` in the cgame module. |
| [`strSub`](/TaystJK/reference/commands/strsub-25a3e39/) | command | engine-shared | Execute a command with $cvar$ value substitution. |
| [`stylePlayer`](/TaystJK/reference/commands/styleplayer-33ef966/) | command | cgame | Runs `CG_StylePlayer_f` in the cgame module. |
| [`sv_banaddr`](/TaystJK/reference/commands/sv_banaddr-5213a27/) | command | engine-server | Bans a user |
| [`sv_bandel`](/TaystJK/reference/commands/sv_bandel-d30e97f/) | command | engine-server | Removes a ban |
| [`sv_exceptaddr`](/TaystJK/reference/commands/sv_exceptaddr-8c8c6e0/) | command | engine-server | Adds a ban exception for a user |
| [`sv_exceptdel`](/TaystJK/reference/commands/sv_exceptdel-8577ae8/) | command | engine-server | Removes a ban exception |
| [`sv_flushbans`](/TaystJK/reference/commands/sv_flushbans-884a191/) | command | engine-server | Removes all bans and exceptions |
| [`sv_listbans`](/TaystJK/reference/commands/sv_listbans-720c4f8/) | command | engine-server | Lists bans |
| [`sv_listrecording`](/TaystJK/reference/commands/sv_listrecording-21f40d6/) | command | engine-server | Lists demos being recorded |
| [`sv_rehashbans`](/TaystJK/reference/commands/sv_rehashbans-6f9f69f/) | command | engine-server | Reloads banlist from file |
| [`svrecord`](/TaystJK/reference/commands/svrecord-96937de/) | command | engine-server | Record a server-side demo |
| [`svrenamedemo`](/TaystJK/reference/commands/svrenamedemo-6d02cec/) | command | engine-server | Rename a server-side demo |
| [`svstoprecord`](/TaystJK/reference/commands/svstoprecord-b9ffafa/) | command | engine-server | Stop recording a server-side demo |
| [`svtell`](/TaystJK/reference/commands/svtell-f8cd34e/) | command | engine-server | Private message from the server to a user |
| [`t_use`](/TaystJK/reference/commands/t_use-2d01a2e/) | command | game | Runs `Cmd_TargetUse_f` in the game module. |
| [`tcmd`](/TaystJK/reference/commands/tcmd-f9ee575/) | command | cgame | Runs `CG_TargetCommand_f` in the cgame module. |
| [`team`](/TaystJK/reference/commands/team-d25187d/) | command | cgame | Forwards this command to the connected game server. |
| [`teamtask`](/TaystJK/reference/commands/teamtask-e766c1c/) | command | cgame | Forwards this command to the connected game server. |
| [`teamvote`](/TaystJK/reference/commands/teamvote-7ffad1d/) | command | cgame | Forwards this command to the connected game server. |
| [`teleToCheckpoint`](/TaystJK/reference/commands/teletocheckpoint-7aa58eb/) | command | cgame | Runs `CG_TeleToCheckpoint_f` in the cgame module. |
| [`tell`](/TaystJK/reference/commands/tell-47b8015/) | command | cgame | Forwards this command to the connected game server. |
| [`tell_attacker`](/TaystJK/reference/commands/tell_attacker-317094f/) | command | cgame | Runs `CG_TellAttacker_f` in the cgame module. |
| [`tell_target`](/TaystJK/reference/commands/tell_target-5cabe4a/) | command | cgame | Runs `CG_TellTarget_f` in the cgame module. |
| [`testBSP`](/TaystJK/reference/commands/testbsp-22b895a/) | command | game | Runs `Cmd_TestBSP_f` in the game module. |
| [`testgun`](/TaystJK/reference/commands/testgun-3d13933/) | command | cgame | Runs `CG_TestGun_f` in the cgame module. |
| [`testmodel`](/TaystJK/reference/commands/testmodel-8452360/) | command | cgame | Runs `CG_TestModel_f` in the cgame module. |
| [`thedestroyer`](/TaystJK/reference/commands/thedestroyer-eb1d67f/) | command | game | Runs `Cmd_TheDestroyer_f` in the game module. |
| [`throwflag`](/TaystJK/reference/commands/throwflag-d12a8a7/) | command | game | Runs `Cmd_Throwflag_f` in the game module. |
| [`thrownade`](/TaystJK/reference/commands/thrownade-ab0fd85/) | command | game | Runs `Cmd_ThrowNade_f` in the game module. |
| [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/) | command | game | Runs `Svcmd_ToggleAdmin_f` in the game module. |
| [`toggleallowvote`](/TaystJK/reference/commands/toggleallowvote-3e2cc73/) | command | game | Runs `Svcmd_ToggleAllowVote_f` in the game module. |
| [`toggleEmotes`](/TaystJK/reference/commands/toggleemotes-c7d169a/) | command | game | Runs `Svcmd_ToggleEmotes_f` in the game module. |
| [`togglemenu`](/TaystJK/reference/commands/togglemenu-8971d97/) | command | engine-client | Show/hide the menu |
| [`toggleuserinfovalidation`](/TaystJK/reference/commands/toggleuserinfovalidation-f54be87/) | command | game | Runs `Svcmd_ToggleUserinfoValidation_f` in the game module. |
| [`toggleVote`](/TaystJK/reference/commands/togglevote-397b6ff/) | command | game | Runs `Svcmd_ToggleVote_f` in the game module. |
| [`top`](/TaystJK/reference/commands/top-af2c7b4/) | command | cgame | Forwards this command to the connected game server. |
| [`trace`](/TaystJK/reference/commands/trace-d0fa554/) | command | game | Runs `Cmd_Trace_f` in the game module. |
| [`tweakForce`](/TaystJK/reference/commands/tweakforce-05bb9d3/) | command | game | Runs `Svcmd_ToggleTweakForce_f` in the game module. |
| [`tweakSaber`](/TaystJK/reference/commands/tweaksaber-e5f1b57/) | command | game | Runs `Svcmd_ToggleTweakSaber_f` in the game module. |
| [`tweakVote`](/TaystJK/reference/commands/tweakvote-97236e2/) | command | game | Runs `Svcmd_ToggleTweakVote_f` in the game module. |
| [`tweakWeapons`](/TaystJK/reference/commands/tweakweapons-fd5860d/) | command | game | Runs `Svcmd_ToggleTweakWeapons_f` in the game module. |
| [`ui_cache`](/TaystJK/reference/commands/ui_cache-3e1b71d/) | command | ui | Runs `UI_Cache_f` in the ui module. |
| [`ui_load`](/TaystJK/reference/commands/ui_load-b884bdc/) | command | ui | Runs `UI_Load` in the ui module. |
| [`ui_modversion`](/TaystJK/reference/commands/ui_modversion-a282cdc/) | command | ui | Runs `UI_Modversion_f` in the ui module. |
| [`ui_openmenu`](/TaystJK/reference/commands/ui_openmenu-e42ca8c/) | command | ui | Runs `UI_OpenMenu_f` in the ui module. |
| [`ui_opensiegemenu`](/TaystJK/reference/commands/ui_opensiegemenu-a05b9b7/) | command | ui | Runs `UI_OpenSiegeMenu_f` in the ui module. |
| [`ui_report`](/TaystJK/reference/commands/ui_report-71f7773/) | command | ui | Runs `UI_Report` in the ui module. |
| [`unset`](/TaystJK/reference/commands/unset-fff210f/) | command | engine-shared | Unset a user generated cvar |
| [`unset_usercreated`](/TaystJK/reference/commands/unset_usercreated-9632483/) | command | engine-shared | Unset all user generated cvars Use with caution! |
| [`userinfo`](/TaystJK/reference/commands/userinfo-c0214b8/) | command | engine-client | Runs `CL_Clientinfo_f` in the engine-client module. |
| [`vbolist`](/TaystJK/reference/commands/vbolist-fe10c4e/) | command | renderer | Runs `R_VBOList_f` in the renderer module. |
| [`vgs_cmd`](/TaystJK/reference/commands/vgs_cmd-98de8a4/) | command | cgame | Vgs |
| [`video`](/TaystJK/reference/commands/video-ffbaf58/) | command | engine-client | Record demo to avi |
| [`viewpos`](/TaystJK/reference/commands/viewpos-f7d1e6b/) | command | cgame | Runs `CG_Viewpos_f` in the cgame module. |
| [`vkinfo`](/TaystJK/reference/commands/vkinfo-a9a6314/) | command | renderer | Runs `vk_info_f` in the renderer module. |
| [`voice_cmd`](/TaystJK/reference/commands/voice_cmd-3d7f601/) | command | cgame | Forwards this command to the connected game server. |
| [`vote`](/TaystJK/reference/commands/vote-fd63f1e/) | command | cgame | Forwards this command to the connected game server. |
| [`warp`](/TaystJK/reference/commands/warp-af58c70/) | command | cgame | Forwards this command to the connected game server. |
| [`warpList`](/TaystJK/reference/commands/warplist-c2ce9d3/) | command | cgame | Forwards this command to the connected game server. |
| [`weaplast`](/TaystJK/reference/commands/weaplast-837fa67/) | command | cgame | Runs `CG_LastWeapon_f` in the cgame module. |
| [`weapnext`](/TaystJK/reference/commands/weapnext-27bad9f/) | command | cgame | Runs `CG_NextWeapon_f` in the cgame module. |
| [`weapon`](/TaystJK/reference/commands/weapon-395d3b4/) | command | cgame | Runs `CG_Weapon_f` in the cgame module. |
| [`weaponclean`](/TaystJK/reference/commands/weaponclean-4f42615/) | command | cgame | Runs `CG_WeaponClean_f` in the cgame module. |
| [`weapontoggle`](/TaystJK/reference/commands/weapontoggle-7ca8872/) | command | engine-server | Toggle g_weaponDisable bits |
| [`weapprev`](/TaystJK/reference/commands/weapprev-e523eb8/) | command | cgame | Runs `CG_PrevWeapon_f` in the cgame module. |
| [`where`](/TaystJK/reference/commands/where-46148cc/) | command | cgame | Forwards this command to the connected game server. |
| [`which`](/TaystJK/reference/commands/which-ed04ff4/) | command | engine-shared | Determines which search path a file was loaded from |
| [`whois`](/TaystJK/reference/commands/whois-a93a167/) | command | cgame | Forwards this command to the connected game server. |
| [`write`](/TaystJK/reference/commands/write-e1d0c6c/) | command | engine-shared | Write the configuration to file |
| [`ysal`](/TaystJK/reference/commands/ysal-49fb494/) | command | cgame | Forwards this command to the connected game server. |
| [`zone_memrecovertest`](/TaystJK/reference/commands/zone_memrecovertest-0999822/) | command | engine-shared | Runs `Z_MemRecoverTest_f` in the engine-shared module. |

## Post-origin change history (1539 entries; 8322 events)

These entries have dated post-origin registration or behavior evidence on TaystJK's inherited first-parent history. Each detail page links the exact commit and records whether attribution comes from explicit credit, a unique project mainline, shared lineage, or an unresolved registration difference.

| Name | Kind | Module | Summary |
|:--|:--|:--|:--|
| [`_dedicated`](/TaystJK/reference/cvars/entry-_dedicated-f30b22a/) | cvar | engine-shared | Controls `com_dedicated` in the engine-shared module. |
| [`activeAction`](/TaystJK/reference/cvars/activeaction-b789056/) | cvar | engine-client | Controls `cl_activeAction` in the engine-client module. |
| [`arch`](/TaystJK/reference/cvars/arch-5a36f11/) | cvar | engine-shared | Controls `arch` in the engine-shared module. |
| [`bg_fighterAltControl`](/TaystJK/reference/cvars/bg_fighteraltcontrol-74138a2/) | cvar | cgame | Controls `bg_fighterAltControl` in the cgame module. |
| [`bot_attachments`](/TaystJK/reference/cvars/bot_attachments-21e20aa/) | cvar | game | Controls `bot_attachments` in the game module. |
| [`bot_camp`](/TaystJK/reference/cvars/bot_camp-bab1b8d/) | cvar | game | Controls `bot_camp` in the game module. |
| [`bot_debugmessages`](/TaystJK/reference/cvars/bot_debugmessages-b7195a5/) | cvar | game | Controls `bot_debugmessages` in the game module. |
| [`bot_enable`](/TaystJK/reference/cvars/bot_enable-18dd573/) | cvar | engine-server | Enable the bot |
| [`bot_forcepowers`](/TaystJK/reference/cvars/bot_forcepowers-a3120e7/) | cvar | game | Controls `bot_forcepowers` in the game module. |
| [`bot_forgimmick`](/TaystJK/reference/cvars/bot_forgimmick-6a07194/) | cvar | game | Controls `bot_forgimmick` in the game module. |
| [`bot_getinthecarrr`](/TaystJK/reference/cvars/bot_getinthecarrr-e9423b5/) | cvar | game | Controls `bot_getinthecarrr` in the game module. |
| [`bot_honorableduelacceptance`](/TaystJK/reference/cvars/bot_honorableduelacceptance-5696da4/) | cvar | game | Controls `bot_honorableduelacceptance` in the game module. |
| [`bot_minplayers`](/TaystJK/reference/cvars/bot_minplayers-68d8330/) | cvar | game | Minimum players in a team or the game |
| [`bot_nochat`](/TaystJK/reference/cvars/bot_nochat-9bebf83/) | cvar | game | Disable chats |
| [`bot_nogoals`](/TaystJK/reference/cvars/bot_nogoals-e2324c1/) | cvar | game | Controls `bot_nogoals` in the game module. |
| [`bot_normgpath`](/TaystJK/reference/cvars/bot_normgpath-140f9e8/) | cvar | game | Controls `bot_normgpath` in the game module. |
| [`bot_pvstype`](/TaystJK/reference/cvars/bot_pvstype-72027f9/) | cvar | game | Controls `bot_pvstype` in the game module. |
| [`bot_strafeOffset`](/TaystJK/reference/cvars/bot_strafeoffset-0fc4233/) | cvar | game | Controls `bot_strafeOffset` in the game module. |
| [`bot_wp_clearweight`](/TaystJK/reference/cvars/bot_wp_clearweight-8adccfd/) | cvar | game | Controls `bot_wp_clearweight` in the game module. |
| [`bot_wp_distconnect`](/TaystJK/reference/cvars/bot_wp_distconnect-6c3d5f5/) | cvar | game | Controls `bot_wp_distconnect` in the game module. |
| [`bot_wp_edit`](/TaystJK/reference/cvars/bot_wp_edit-3e7e69b/) | cvar | game | Controls `bot_wp_edit` in the game module. |
| [`bot_wp_info`](/TaystJK/reference/cvars/bot_wp_info-3cdeb0e/) | cvar | game | Controls `bot_wp_info` in the game module. |
| [`bot_wp_visconnect`](/TaystJK/reference/cvars/bot_wp_visconnect-30dfdd1/) | cvar | game | Controls `bot_wp_visconnect` in the game module. |
| [`broadsword`](/TaystJK/reference/cvars/broadsword-b938fd3/) | cvar | cgame | Controls `broadsword` in the cgame module. |
| [`broadsword_dircap`](/TaystJK/reference/cvars/broadsword_dircap-4a84248/) | cvar | renderer | Controls `broadsword_dircap` in the renderer module. |
| [`broadsword_dontstopanim`](/TaystJK/reference/cvars/broadsword_dontstopanim-96a0420/) | cvar | renderer | Controls `broadsword_dontstopanim` in the renderer module. |
| [`broadsword_effcorr`](/TaystJK/reference/cvars/broadsword_effcorr-0fade97/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_extra1`](/TaystJK/reference/cvars/broadsword_extra1-1b72b03/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_extra2`](/TaystJK/reference/cvars/broadsword_extra2-a936376/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_kickbones`](/TaystJK/reference/cvars/broadsword_kickbones-de3a44f/) | cvar | renderer | Controls `broadsword_kickbones` in the renderer module. |
| [`broadsword_kickorigin`](/TaystJK/reference/cvars/broadsword_kickorigin-504df15/) | cvar | renderer | Controls `broadsword_kickorigin` in the renderer module. |
| [`broadsword_playflop`](/TaystJK/reference/cvars/broadsword_playflop-431f63d/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_ragtobase`](/TaystJK/reference/cvars/broadsword_ragtobase-5874a91/) | cvar | renderer | Controls `broadsword_ragtobase` in the renderer module. |
| [`broadsword_smallbbox`](/TaystJK/reference/cvars/broadsword_smallbbox-3c99ac6/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`broadsword_waitforshot`](/TaystJK/reference/cvars/broadsword_waitforshot-e2d3bca/) | cvar | renderer | Controls `broadsword_waitforshot` in the renderer module. |
| [`capturelimit`](/TaystJK/reference/cvars/capturelimit-15744ea/) | cvar | game | Fixme init'd to 8 in game module |
| [`cg_alwaysShowAbsorb`](/TaystJK/reference/cvars/cg_alwaysshowabsorb-d52ebf0/) | cvar | cgame | Show absorb when it's in use |
| [`cg_ambientSounds`](/TaystJK/reference/cvars/cg_ambientsounds-00fb29b/) | cvar | cgame | Play ambient sounds |
| [`cg_animBlend`](/TaystJK/reference/cvars/cg_animblend-cce43f8/) | cvar | cgame | Controls `cg_animBlend` in the cgame module. |
| [`cg_animSpeed`](/TaystJK/reference/cvars/cg_animspeed-ccea52f/) | cvar | cgame | Controls `cg_animSpeed` in the cgame module. |
| [`cg_auraShell`](/TaystJK/reference/cvars/cg_aurashell-c22e6ae/) | cvar | cgame | Controls `cg_auraShell` in the cgame module. |
| [`cg_autoKillWhenFalling`](/TaystJK/reference/cvars/cg_autokillwhenfalling-9eb85fc/) | cvar | cgame | Controls `cg_autoKillWhenFalling` in the cgame module. |
| [`cg_autoRecordDemo`](/TaystJK/reference/cvars/cg_autorecorddemo-fad7d88/) | cvar | cgame | Controls `cg_autoRecordDemo` in the cgame module. |
| [`cg_autoSwitch`](/TaystJK/reference/cvars/cg_autoswitch-5936261/) | cvar | cgame | Controls `cg_autoSwitch` in the cgame module. |
| [`cg_blood`](/TaystJK/reference/cvars/cg_blood-cc15687/) | cvar | cgame | JAPRO - Clientside - re add cg_blood |
| [`cg_bobPitch`](/TaystJK/reference/cvars/cg_bobpitch-6c78935/) | cvar | cgame | Controls `cg_bobPitch` in the cgame module. |
| [`cg_bobRoll`](/TaystJK/reference/cvars/cg_bobroll-3321473/) | cvar | cgame | Controls `cg_bobRoll` in the cgame module. |
| [`cg_bobUp`](/TaystJK/reference/cvars/cg_bobup-5e07470/) | cvar | cgame | Controls `cg_bobUp` in the cgame module. |
| [`cg_cameraFPS`](/TaystJK/reference/cvars/cg_camerafps-62ac0e1/) | cvar | cgame | Set the reference frame rate for third-person camera damping. |
| [`cg_cameraOrbit`](/TaystJK/reference/cvars/cg_cameraorbit-6e01139/) | cvar | cgame | Controls `cg_cameraOrbit` in the cgame module. |
| [`cg_cameraOrbitDelay`](/TaystJK/reference/cvars/cg_cameraorbitdelay-4cd862d/) | cvar | cgame | Controls `cg_cameraOrbitDelay` in the cgame module. |
| [`cg_centerSize`](/TaystJK/reference/cvars/cg_centersize-615dcaa/) | cvar | cgame | Controls `cg_centerSize` in the cgame module. |
| [`cg_centerTime`](/TaystJK/reference/cvars/cg_centertime-5b86ac2/) | cvar | cgame | Controls `cg_centerTime` in the cgame module. |
| [`cg_chatBox`](/TaystJK/reference/cvars/cg_chatbox-d3edbae/) | cvar | cgame | Controls `cg_chatBox` in the cgame module. |
| [`cg_chatBoxCutOffLength`](/TaystJK/reference/cvars/cg_chatboxcutofflength-abf6a17/) | cvar | cgame | Width of a line in the chatbox before breaking to a new one |
| [`cg_chatBoxEmojis`](/TaystJK/reference/cvars/cg_chatboxemojis-7bdc808/) | cvar | cgame | Controls `cg_chatBoxEmojis` in the cgame module. |
| [`cg_chatBoxFontSize`](/TaystJK/reference/cvars/cg_chatboxfontsize-85a3a51/) | cvar | cgame | Scale of the chat box font |
| [`cg_chatBoxHeight`](/TaystJK/reference/cvars/cg_chatboxheight-08b8bc2/) | cvar | cgame | Controls `cg_chatBoxHeight` in the cgame module. |
| [`cg_chatBoxLines`](/TaystJK/reference/cvars/cg_chatboxlines-ef18116/) | cvar | cgame | This would be called chatBoxHeight if baseJKA didn't use that |
| [`cg_chatBoxShowCutoff`](/TaystJK/reference/cvars/cg_chatboxshowcutoff-3c9eab8/) | cvar | cgame | Controls `cg_chatBoxShowCutoff` in the cgame module. |
| [`cg_chatBoxShowHistory`](/TaystJK/reference/cvars/cg_chatboxshowhistory-e0f1ccf/) | cvar | cgame | Shows past messages when console is open |
| [`cg_chatBoxX`](/TaystJK/reference/cvars/cg_chatboxx-e3271fd/) | cvar | cgame | Controls `cg_chatBoxX` in the cgame module. |
| [`cg_chatSounds`](/TaystJK/reference/cvars/cg_chatsounds-fe6292d/) | cvar | cgame | Play sound when chat messages are received |
| [`cg_cleanChatbox`](/TaystJK/reference/cvars/cg_cleanchatbox-3609d1a/) | cvar | cgame | 1=Remove all colors from chat msgs, 2=Only remove color at begining of message |
| [`cg_crosshairColor`](/TaystJK/reference/cvars/cg_crosshaircolor-a61b771/) | cvar | cgame | Controls `cg_crosshairColor` in the cgame module. |
| [`cg_crosshairHealth`](/TaystJK/reference/cvars/cg_crosshairhealth-754bdda/) | cvar | cgame | Controls `cg_crosshairHealth` in the cgame module. |
| [`cg_crosshairIdentifyTarget`](/TaystJK/reference/cvars/cg_crosshairidentifytarget-f52b58a/) | cvar | cgame | Controls `cg_crosshairIdentifyTarget` in the cgame module. |
| [`cg_crosshairSaberStyleColor`](/TaystJK/reference/cvars/cg_crosshairsaberstylecolor-14bed3a/) | cvar | cgame | Controls `cg_crosshairSaberStyleColor` in the cgame module. |
| [`cg_crossHairScope`](/TaystJK/reference/cvars/cg_crosshairscope-93d2076/) | cvar | cgame | Minimalist crosshair disruptor scope replacement |
| [`cg_crosshairSize`](/TaystJK/reference/cvars/cg_crosshairsize-5325063/) | cvar | cgame | Controls `cg_crosshairSize` in the cgame module. |
| [`cg_crosshairSizeScale`](/TaystJK/reference/cvars/cg_crosshairsizescale-8838e3c/) | cvar | cgame | Controls `cg_crosshairSizeScale` in the cgame module. |
| [`cg_crosshairX`](/TaystJK/reference/cvars/cg_crosshairx-fbaeab2/) | cvar | cgame | Controls `cg_crosshairX` in the cgame module. |
| [`cg_crosshairY`](/TaystJK/reference/cvars/cg_crosshairy-79c55c3/) | cvar | cgame | Controls `cg_crosshairY` in the cgame module. |
| [`cg_currentSelectedPlayer`](/TaystJK/reference/cvars/cg_currentselectedplayer-5cdbbf9/) | cvar | cgame | Controls `cg_currentSelectedPlayer` in the cgame module. |
| [`cg_debugAnim`](/TaystJK/reference/cvars/cg_debuganim-a7b3132/) | cvar | cgame | Controls `cg_debugAnim` in the cgame module. |
| [`cg_debugEvents`](/TaystJK/reference/cvars/cg_debugevents-20ff0e7/) | cvar | cgame | Controls `cg_debugEvents` in the cgame module. |
| [`cg_debugPosition`](/TaystJK/reference/cvars/cg_debugposition-66bbc1e/) | cvar | cgame | Controls `cg_debugPosition` in the cgame module. |
| [`cg_debugSaber`](/TaystJK/reference/cvars/cg_debugsaber-0399b3c/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`cg_defaultFemaleModel`](/TaystJK/reference/cvars/cg_defaultfemalemodel-2d9b8bf/) | cvar | cgame | Controls `cg_defaultFemaleModel` in the cgame module. |
| [`cg_defaultModel`](/TaystJK/reference/cvars/cg_defaultmodel-16870a9/) | cvar | cgame | Controls `cg_defaultModel` in the cgame module. |
| [`cg_defaultModelRandom`](/TaystJK/reference/cvars/cg_defaultmodelrandom-139255e/) | cvar | cgame | Controls `cg_defaultModelRandom` in the cgame module. |
| [`cg_deferPlayers`](/TaystJK/reference/cvars/cg_deferplayers-7884da1/) | cvar | cgame | Controls `cg_deferPlayers` in the cgame module. |
| [`cg_dismember`](/TaystJK/reference/cvars/cg_dismember-8f13e99/) | cvar | cgame | Controls `cg_dismember` in the cgame module. |
| [`cg_disruptorNew`](/TaystJK/reference/cvars/cg_disruptornew-f6cffa9/) | cvar | cgame | Enable new disruptor effects |
| [`cg_drainFX`](/TaystJK/reference/cvars/cg_drainfx-0b786b0/) | cvar | cgame | Controls `cg_drainFX` in the cgame module. |
| [`cg_draw2D`](/TaystJK/reference/cvars/cg_draw2d-fd966da/) | cvar | cgame | 2=No tinted overlay during rage/ysal use. |
| [`cg_draw3DIcons`](/TaystJK/reference/cvars/cg_draw3dicons-e42c146/) | cvar | cgame | Controls `cg_draw3DIcons` in the cgame module. |
| [`cg_drawAmmoWarning`](/TaystJK/reference/cvars/cg_drawammowarning-1ecf584/) | cvar | cgame | Controls `cg_drawAmmoWarning` in the cgame module. |
| [`cg_drawCrosshair`](/TaystJK/reference/cvars/cg_drawcrosshair-2db6bb9/) | cvar | cgame | Controls `cg_drawCrosshair` in the cgame module. |
| [`cg_drawCrosshairNames`](/TaystJK/reference/cvars/cg_drawcrosshairnames-fb9d41a/) | cvar | cgame | Set crosshair target-name display and fade duration. |
| [`cg_drawEnemyInfo`](/TaystJK/reference/cvars/cg_drawenemyinfo-83f96b2/) | cvar | cgame | Controls `cg_drawEnemyInfo` in the cgame module. |
| [`cg_drawFPS`](/TaystJK/reference/cvars/cg_drawfps-2b6a553/) | cvar | cgame | Draw the match timer |
| [`cg_drawFriend`](/TaystJK/reference/cvars/cg_drawfriend-75e27fd/) | cvar | cgame | Controls `cg_drawFriend` in the cgame module. |
| [`cg_drawGun`](/TaystJK/reference/cvars/cg_drawgun-f3f4ebe/) | cvar | cgame | Controls `cg_drawGun` in the cgame module. |
| [`cg_drawHud`](/TaystJK/reference/cvars/cg_drawhud-d58b164/) | cvar | cgame | Controls `cg_drawHud` in the cgame module. |
| [`cg_drawIcons`](/TaystJK/reference/cvars/cg_drawicons-5e047ed/) | cvar | cgame | Controls `cg_drawIcons` in the cgame module. |
| [`cg_drawPlayerNames`](/TaystJK/reference/cvars/cg_drawplayernames-688cd3a/) | cvar | cgame | Controls `cg_drawPlayerNames` in the cgame module. |
| [`cg_drawPlayerNamesScale`](/TaystJK/reference/cvars/cg_drawplayernamesscale-94d9ef0/) | cvar | cgame | Controls `cg_drawPlayerNamesScale` in the cgame module. |
| [`cg_drawPowerUpIcons`](/TaystJK/reference/cvars/cg_drawpowerupicons-309d5b9/) | cvar | cgame | Controls `cg_drawPowerUpIcons` in the cgame module. |
| [`cg_drawRadar`](/TaystJK/reference/cvars/cg_drawradar-b79f76e/) | cvar | cgame | Controls `cg_drawRadar` in the cgame module. |
| [`cg_drawRewards`](/TaystJK/reference/cvars/cg_drawrewards-49bc8f7/) | cvar | cgame | Controls `cg_drawRewards` in the cgame module. |
| [`cg_drawScore`](/TaystJK/reference/cvars/cg_drawscore-f2358ae/) | cvar | cgame | Score counter on HUD |
| [`cg_drawScores`](/TaystJK/reference/cvars/cg_drawscores-493f7be/) | cvar | cgame | Team score counter in top right |
| [`cg_drawScreenTints`](/TaystJK/reference/cvars/cg_drawscreentints-bddc984/) | cvar | cgame | Turn the tint from water on or off |
| [`cg_drawSnapshot`](/TaystJK/reference/cvars/cg_drawsnapshot-bdaa7eb/) | cvar | cgame | Controls `cg_drawSnapshot` in the cgame module. |
| [`cg_drawStatus`](/TaystJK/reference/cvars/cg_drawstatus-b5d2624/) | cvar | cgame | Controls whether the main HUD status elements are drawn |
| [`cg_drawTeamOverlay`](/TaystJK/reference/cvars/cg_drawteamoverlay-2c01b46/) | cvar | cgame | Draw the team overlay for team-based gametypes |
| [`cg_drawTeamOverlayWeapons`](/TaystJK/reference/cvars/cg_drawteamoverlayweapons-864b183/) | cvar | cgame | Draw each player's current weapon on the team overlay |
| [`cg_drawTeamOverlayX`](/TaystJK/reference/cvars/cg_drawteamoverlayx-0618c68/) | cvar | cgame | Horizontal location of the right edge of the team overlay |
| [`cg_drawTeamOverlayY`](/TaystJK/reference/cvars/cg_drawteamoverlayy-249a13a/) | cvar | cgame | Vertical location of the team overlay |
| [`cg_drawTimer`](/TaystJK/reference/cvars/cg_drawtimer-431f426/) | cvar | cgame | Draw the match timer |
| [`cg_drawTimerCountdown`](/TaystJK/reference/cvars/cg_drawtimercountdown-26c13db/) | cvar | cgame | Controls `cg_drawTimerCountdown` in the cgame module. |
| [`cg_drawTimerMsec`](/TaystJK/reference/cvars/cg_drawtimermsec-156f1d2/) | cvar | cgame | Controls `cg_drawTimerMsec` in the cgame module. |
| [`cg_drawTriggers`](/TaystJK/reference/cvars/cg_drawtriggers-ec57388/) | cvar | cgame | Controls `cg_drawTriggers` in the cgame module. |
| [`cg_drawVehLeadIndicator`](/TaystJK/reference/cvars/cg_drawvehleadindicator-a231e1c/) | cvar | cgame | Controls `cg_drawVehLeadIndicator` in the cgame module. |
| [`cg_duelMusic`](/TaystJK/reference/cvars/cg_duelmusic-aa17cd0/) | cvar | cgame | Enables special in-game music for private duels |
| [`cg_dynamicCrosshair`](/TaystJK/reference/cvars/cg_dynamiccrosshair-279645a/) | cvar | cgame | Controls `cg_dynamicCrosshair` in the cgame module. |
| [`cg_dynamicCrosshairPrecision`](/TaystJK/reference/cvars/cg_dynamiccrosshairprecision-5e5ca88/) | cvar | cgame | Controls `cg_dynamicCrosshairPrecision` in the cgame module. |
| [`cg_engineModifications`](/TaystJK/reference/cvars/cg_enginemodifications-0e53ca8/) | cvar | cgame | Controls `cg_engineModifications` in the cgame module. |
| [`cg_errorDecay`](/TaystJK/reference/cvars/cg_errordecay-6e1a208/) | cvar | cgame | Controls `cg_errorDecay` in the cgame module. |
| [`cg_fleshSparks`](/TaystJK/reference/cvars/cg_fleshsparks-6cfe42f/) | cvar | cgame | Maximum number of sparks from a saber hit |
| [`cg_footsteps`](/TaystJK/reference/cvars/cg_footsteps-2707982/) | cvar | cgame | Controls `cg_footsteps` in the cgame module. |
| [`cg_forceAllyModel`](/TaystJK/reference/cvars/cg_forceallymodel-2d546b7/) | cvar | cgame | Controls `cg_forceAllyModel` in the cgame module. |
| [`cg_forceCosmetics`](/TaystJK/reference/cvars/cg_forcecosmetics-598fb8d/) | cvar | cgame | Forces all players to have your cosmetics on non-japro servers |
| [`cg_forceEnemyModel`](/TaystJK/reference/cvars/cg_forceenemymodel-d577813/) | cvar | cgame | Controls `cg_forceEnemyModel` in the cgame module. |
| [`cg_forceModel`](/TaystJK/reference/cvars/cg_forcemodel-86e3071/) | cvar | cgame | Controls `cg_forceModel` in the cgame module. |
| [`cg_fov`](/TaystJK/reference/cvars/cg_fov-05db256/) | cvar | cgame | Controls `cg_fov` in the cgame module. |
| [`cg_fovAspectAdjust`](/TaystJK/reference/cvars/cg_fovaspectadjust-a01b353/) | cvar | cgame | Fixed skyportal issue |
| [`cg_fovViewmodel`](/TaystJK/reference/cvars/cg_fovviewmodel-585844a/) | cvar | cgame | Controls `cg_fovViewmodel` in the cgame module. |
| [`cg_fovViewmodelAdjust`](/TaystJK/reference/cvars/cg_fovviewmodeladjust-4ab4013/) | cvar | cgame | Shifts viewmodels down above cg_fov 90 |
| [`cg_fpls`](/TaystJK/reference/cvars/cg_fpls-c3e3b71/) | cvar | cgame | Controls `cg_fpls` in the cgame module. |
| [`cg_g2MarksAllModels`](/TaystJK/reference/cvars/cg_g2marksallmodels-5f4ec51/) | cvar | renderer | Render marks on all G2 models |
| [`cg_g2TraceLod`](/TaystJK/reference/cvars/cg_g2tracelod-6685be5/) | cvar | cgame | Controls `cg_g2TraceLod` in the cgame module. |
| [`cg_ghoul2Marks`](/TaystJK/reference/cvars/cg_ghoul2marks-1892a1a/) | cvar | cgame | Controls `cg_ghoul2Marks` in the cgame module. |
| [`cg_gunX`](/TaystJK/reference/cvars/cg_gunx-7fa7158/) | cvar | cgame | Controls `cg_gunX` in the cgame module. |
| [`cg_gunY`](/TaystJK/reference/cvars/cg_guny-e7310ce/) | cvar | cgame | Controls `cg_gunY` in the cgame module. |
| [`cg_gunZ`](/TaystJK/reference/cvars/cg_gunz-b9382f0/) | cvar | cgame | Controls `cg_gunZ` in the cgame module. |
| [`cg_headTurn`](/TaystJK/reference/cvars/cg_headturn-2d5b44b/) | cvar | cgame | Controls `cg_headTurn` in the cgame module. |
| [`cg_hitsounds`](/TaystJK/reference/cvars/cg_hitsounds-5ef7d07/) | cvar | cgame | Play a sound when you hit someone |
| [`cg_hudColors`](/TaystJK/reference/cvars/cg_hudcolors-e3b9e30/) | cvar | cgame | Changes the colors of the HUD based on saber style and force |
| [`cg_hudFiles`](/TaystJK/reference/cvars/cg_hudfiles-37efefc/) | cvar | cgame | HUD style |
| [`cg_instantDuck`](/TaystJK/reference/cvars/cg_instantduck-ee7bc95/) | cvar | cgame | Controls `cg_instantDuck` in the cgame module. |
| [`cg_jumpGoal`](/TaystJK/reference/cvars/cg_jumpgoal-829a115/) | cvar | cgame | Set a first jump speed goal speed, if first jump speed is above your goal speed, the pre-speed text will be green. Requires /speedometer 1 enabled |
| [`cg_jumpHeight`](/TaystJK/reference/cvars/cg_jumpheight-d0ee024/) | cvar | cgame | Specify jumpheight before jump is automaticaly canceled. |
| [`cg_jumpSounds`](/TaystJK/reference/cvars/cg_jumpsounds-834a387/) | cvar | cgame | Play sound when players jump |
| [`cg_killfeed`](/TaystJK/reference/cvars/cg_killfeed-020f6f8/) | cvar | cgame | Draw a killfeed on the HUD |
| [`cg_killfeedAlignment`](/TaystJK/reference/cvars/cg_killfeedalignment-10e367a/) | cvar | cgame | Align the killfeed |
| [`cg_killfeedColors`](/TaystJK/reference/cvars/cg_killfeedcolors-31f4cc3/) | cvar | cgame | Color the killfeed icons |
| [`cg_killfeedIconSize`](/TaystJK/reference/cvars/cg_killfeediconsize-508e23d/) | cvar | cgame | Resize the killfeed |
| [`cg_killfeedTextSize`](/TaystJK/reference/cvars/cg_killfeedtextsize-1f948df/) | cvar | cgame | Resize the killfeed |
| [`cg_killfeedX`](/TaystJK/reference/cvars/cg_killfeedx-32eb04e/) | cvar | cgame | Offset the killfeed's horizontal position from its current position |
| [`cg_killfeedY`](/TaystJK/reference/cvars/cg_killfeedy-e14002d/) | cvar | cgame | Offset the killfeed's vertical position from its current position |
| [`cg_killMessage`](/TaystJK/reference/cvars/cg_killmessage-b665d89/) | cvar | cgame | Print a kill message on the screen when you kill someone |
| [`cg_killSounds`](/TaystJK/reference/cvars/cg_killsounds-7a11d7f/) | cvar | cgame | Play a sound when you kill someone |
| [`cg_lagometer`](/TaystJK/reference/cvars/cg_lagometer-da10c07/) | cvar | cgame | Controls `cg_lagometer` in the cgame module. |
| [`cg_lagometerX`](/TaystJK/reference/cvars/cg_lagometerx-cb16443/) | cvar | cgame | Controls `cg_lagometerX` in the cgame module. |
| [`cg_lagometerY`](/TaystJK/reference/cvars/cg_lagometery-e1cecb6/) | cvar | cgame | Controls `cg_lagometerY` in the cgame module. |
| [`cg_logChat`](/TaystJK/reference/cvars/cg_logchat-b9bd889/) | cvar | cgame | Controls `cg_logChat` in the cgame module. |
| [`cg_marks`](/TaystJK/reference/cvars/cg_marks-04d0449/) | cvar | cgame | Controls `cg_marks` in the cgame module. |
| [`cg_movementKeys`](/TaystJK/reference/cvars/cg_movementkeys-03e13b5/) | cvar | cgame | Select the on-screen movement-key overlay style. |
| [`cg_movementKeysSize`](/TaystJK/reference/cvars/cg_movementkeyssize-6686f74/) | cvar | cgame | Scale of the movement keys |
| [`cg_movementKeysX`](/TaystJK/reference/cvars/cg_movementkeysx-a7d563b/) | cvar | cgame | Horizontal location of the movement keys |
| [`cg_movementKeysY`](/TaystJK/reference/cvars/cg_movementkeysy-30e6290/) | cvar | cgame | Vertical location of the movement keys |
| [`cg_newFont`](/TaystJK/reference/cvars/cg_newfont-3b907a0/) | cvar | cgame | Uses a different font for the chat |
| [`cg_noFX`](/TaystJK/reference/cvars/cg_nofx-361d77e/) | cvar | cgame | Determines if effects and map models are shown |
| [`cg_noPlayerAnims`](/TaystJK/reference/cvars/cg_noplayeranims-75a0858/) | cvar | cgame | Controls `cg_noPlayerAnims` in the cgame module. |
| [`cg_noPredict`](/TaystJK/reference/cvars/cg_nopredict-f4b05f6/) | cvar | cgame | Controls `cg_noPredict` in the cgame module. |
| [`cg_noProjectileTrail`](/TaystJK/reference/cvars/cg_noprojectiletrail-fb1950f/) | cvar | cgame | Controls `cg_noProjectileTrail` in the cgame module. |
| [`cg_noRGBSabers`](/TaystJK/reference/cvars/cg_norgbsabers-19cc29e/) | cvar | cgame | Controls `cg_noRGBSabers` in the cgame module. |
| [`cg_noTaunt`](/TaystJK/reference/cvars/cg_notaunt-3bb3d8c/) | cvar | cgame | Controls `cg_noTaunt` in the cgame module. |
| [`cg_noTeleFX`](/TaystJK/reference/cvars/cg_notelefx-0a4c1c4/) | cvar | cgame | Disables the teleportation effect |
| [`cg_oldPainSounds`](/TaystJK/reference/cvars/cg_oldpainsounds-535e857/) | cvar | cgame | Controls `cg_oldPainSounds` in the cgame module. |
| [`cg_pitchHelper`](/TaystJK/reference/cvars/cg_pitchhelper-e3dadd7/) | cvar | cgame | Draw pitch angle independently from /cg_showpos |
| [`cg_pitchHelperOffset`](/TaystJK/reference/cvars/cg_pitchhelperoffset-9b851a1/) | cvar | cgame | Offset the green range up or down (eg. range 30, offset 10 = +25 to -5) |
| [`cg_pitchHelperRange`](/TaystJK/reference/cvars/cg_pitchhelperrange-249a33b/) | cvar | cgame | The range of numbers to display as green (eg. range 30, offset 0 = +15 to -15) |
| [`cg_pitchHelperX`](/TaystJK/reference/cvars/cg_pitchhelperx-a9d35e3/) | cvar | cgame | Move the pitch helper's horizontal location |
| [`cg_pitchHelperY`](/TaystJK/reference/cvars/cg_pitchhelpery-285d43a/) | cvar | cgame | Move the pitch helper's vertical location |
| [`cg_pitchHudAngle`](/TaystJK/reference/cvars/cg_pitchhudangle-1647f9d/) | cvar | cgame | Controls `cg_pitchHudAngle` in the cgame module. |
| [`cg_predictItems`](/TaystJK/reference/cvars/cg_predictitems-61db805/) | cvar | cgame | Controls `cg_predictItems` in the cgame module. |
| [`cg_predictKnockback`](/TaystJK/reference/cvars/cg_predictknockback-103096d/) | cvar | cgame | Predict self-inflicted rocket-jump knockback clientside (racemode only). Use with cg_simulatedProjectiles 1. |
| [`cg_raceSounds`](/TaystJK/reference/cvars/cg_racesounds-cfc3317/) | cvar | cgame | Bitvalue, but so far we just have RS_TIMER_START set up |
| [`cg_raceStart`](/TaystJK/reference/cvars/cg_racestart-e3c5285/) | cvar | cgame | Enable race timer start speed separately from the race timer |
| [`cg_raceStartX`](/TaystJK/reference/cvars/cg_racestartx-c82e957/) | cvar | cgame | Horizontal location of the race start timer onscreen |
| [`cg_raceStartY`](/TaystJK/reference/cvars/cg_racestarty-210e8af/) | cvar | cgame | Vertical location of the race start timer onscreen |
| [`cg_raceTimer`](/TaystJK/reference/cvars/cg_racetimer-7361db5/) | cvar | cgame | Show the race timer onscreen |
| [`cg_raceTimerSize`](/TaystJK/reference/cvars/cg_racetimersize-7c766ca/) | cvar | cgame | Scale of the race timer |
| [`cg_raceTimerX`](/TaystJK/reference/cvars/cg_racetimerx-6e9d43d/) | cvar | cgame | Horizontal location of the race timer onscreen |
| [`cg_raceTimerY`](/TaystJK/reference/cvars/cg_racetimery-7b7373c/) | cvar | cgame | Vertical location of the race timer onscreen |
| [`cg_remaps`](/TaystJK/reference/cvars/cg_remaps-267c59f/) | cvar | cgame | Show or hide serverside remaps |
| [`cg_renderToTextureFX`](/TaystJK/reference/cvars/cg_rendertotexturefx-744c624/) | cvar | cgame | Controls `cg_renderToTextureFX` in the cgame module. |
| [`cg_repeaterOrb`](/TaystJK/reference/cvars/cg_repeaterorb-a5e5769/) | cvar | cgame | Controls `cg_repeaterOrb` in the cgame module. |
| [`cg_rollSounds`](/TaystJK/reference/cvars/cg_rollsounds-370ef41/) | cvar | cgame | Play sound when players roll |
| [`cg_runPitch`](/TaystJK/reference/cvars/cg_runpitch-db8b764/) | cvar | cgame | Controls `cg_runPitch` in the cgame module. |
| [`cg_runRoll`](/TaystJK/reference/cvars/cg_runroll-f6bae02/) | cvar | cgame | Controls `cg_runRoll` in the cgame module. |
| [`cg_saberClientVisualCompensation`](/TaystJK/reference/cvars/cg_saberclientvisualcompensation-5111482/) | cvar | cgame | Controls `cg_saberClientVisualCompensation` in the cgame module. |
| [`cg_saberContact`](/TaystJK/reference/cvars/cg_sabercontact-343ea90/) | cvar | cgame | Controls `cg_saberContact` in the cgame module. |
| [`cg_saberDynamicMarks`](/TaystJK/reference/cvars/cg_saberdynamicmarks-9dbc592/) | cvar | cgame | Controls `cg_saberDynamicMarks` in the cgame module. |
| [`cg_saberDynamicMarkTime`](/TaystJK/reference/cvars/cg_saberdynamicmarktime-9ea8c5d/) | cvar | cgame | Controls `cg_saberDynamicMarkTime` in the cgame module. |
| [`cg_saberModelTraceEffect`](/TaystJK/reference/cvars/cg_sabermodeltraceeffect-d010298/) | cvar | cgame | Controls `cg_saberModelTraceEffect` in the cgame module. |
| [`cg_saberTrail`](/TaystJK/reference/cvars/cg_sabertrail-504b3ad/) | cvar | cgame | Controls `cg_saberTrail` in the cgame module. |
| [`cg_scoreDeaths`](/TaystJK/reference/cvars/cg_scoredeaths-67a5132/) | cvar | cgame | Display score AND deaths on the scoreboard |
| [`cg_scorePlums`](/TaystJK/reference/cvars/cg_scoreplums-7d5e895/) | cvar | cgame | Controls `cg_scorePlums` in the cgame module. |
| [`cg_screenShake`](/TaystJK/reference/cvars/cg_screenshake-f987066/) | cvar | cgame | Shake screen when hit or while charging weapons |
| [`cg_selectedPlayer`](/TaystJK/reference/cvars/cg_selectedplayer-8bf325d/) | cvar | ui | Controls `cg_selectedPlayer` in the ui module. |
| [`cg_selectedPlayerName`](/TaystJK/reference/cvars/cg_selectedplayername-ecf90ae/) | cvar | ui | Controls `cg_selectedPlayerName` in the ui module. |
| [`cg_shaderSaberCore`](/TaystJK/reference/cvars/cg_shadersabercore-88486dc/) | cvar | cgame | Controls `cg_shaderSaberCore` in the cgame module. |
| [`cg_shaderSaberGlow`](/TaystJK/reference/cvars/cg_shadersaberglow-585b811/) | cvar | cgame | Controls `cg_shaderSaberGlow` in the cgame module. |
| [`cg_shadows`](/TaystJK/reference/cvars/cg_shadows-09f85e1/) | cvar | cgame | Controls `cg_shadows` in the cgame module. |
| [`cg_showMiss`](/TaystJK/reference/cvars/cg_showmiss-96e3788/) | cvar | cgame | Controls `cg_showMiss` in the cgame module. |
| [`cg_showpos`](/TaystJK/reference/cvars/cg_showpos-785191d/) | cvar | cgame | Controls `cg_showpos` in the cgame module. |
| [`cg_showVehBounds`](/TaystJK/reference/cvars/cg_showvehbounds-e3b5f0c/) | cvar | cgame | Controls `cg_showVehBounds` in the cgame module. |
| [`cg_showVehMiss`](/TaystJK/reference/cvars/cg_showvehmiss-7394191/) | cvar | cgame | Controls `cg_showVehMiss` in the cgame module. |
| [`cg_simpleItems`](/TaystJK/reference/cvars/cg_simpleitems-b02935a/) | cvar | cgame | Controls `cg_simpleItems` in the cgame module. |
| [`cg_simulatedHitscan`](/TaystJK/reference/cvars/cg_simulatedhitscan-8c02e38/) | cvar | cgame | Toggle predicted hitscan weapon effects. |
| [`cg_simulatedProjectiles`](/TaystJK/reference/cvars/cg_simulatedprojectiles-e12d5f1/) | cvar | cgame | Wether to use simulated projectiles so bullets appear instantly. Values > 1 don't draw the projectile right away. |
| [`cg_smoothClients`](/TaystJK/reference/cvars/cg_smoothclients-baf7386/) | cvar | cgame | Controls `cg_smoothClients` in the cgame module. |
| [`cg_snapHudHeight`](/TaystJK/reference/cvars/cg_snaphudheight-d87b8e6/) | cvar | cgame | Vertical height |
| [`cg_snapHudSpeed`](/TaystJK/reference/cvars/cg_snaphudspeed-1a22dbb/) | cvar | cgame | Basespeed for calculations (Leave default for auto) |
| [`cg_snapHudY`](/TaystJK/reference/cvars/cg_snaphudy-cc550c0/) | cvar | cgame | Vertical position |
| [`cg_snapshotTimeout`](/TaystJK/reference/cvars/cg_snapshottimeout-6079a2a/) | cvar | cgame | Controls `cg_snapshotTimeout` in the cgame module. |
| [`cg_specCameraMode`](/TaystJK/reference/cvars/cg_speccameramode-95baeef/) | cvar | cgame | Controls `cg_specCameraMode` in the cgame module. |
| [`cg_specHud`](/TaystJK/reference/cvars/cg_spechud-70b1e1d/) | cvar | cgame | Controls `cg_specHud` in the cgame module. |
| [`cg_speedometer`](/TaystJK/reference/cvars/cg_speedometer-9810620/) | cvar | cgame | Configure with the /speedometer command |
| [`cg_speedometerJumps`](/TaystJK/reference/cvars/cg_speedometerjumps-2a998a1/) | cvar | cgame | The amount of jumps to store in the jumps array, enable with the /speedometer command |
| [`cg_speedometerJumpsX`](/TaystJK/reference/cvars/cg_speedometerjumpsx-29e18d5/) | cvar | cgame | Horizontal location of the jumps array |
| [`cg_speedometerJumpsY`](/TaystJK/reference/cvars/cg_speedometerjumpsy-8a40b94/) | cvar | cgame | Vertical location of the jumps array |
| [`cg_speedometerSize`](/TaystJK/reference/cvars/cg_speedometersize-6fd381a/) | cvar | cgame | Scale of the speedometer |
| [`cg_speedometerX`](/TaystJK/reference/cvars/cg_speedometerx-58598b2/) | cvar | cgame | Horizontal location of the speedometer |
| [`cg_speedometerY`](/TaystJK/reference/cvars/cg_speedometery-7d4b635/) | cvar | cgame | Vertical location of the speedometer |
| [`cg_speedTrail`](/TaystJK/reference/cvars/cg_speedtrail-2918eb4/) | cvar | cgame | Controls `cg_speedTrail` in the cgame module. |
| [`cg_startGoal`](/TaystJK/reference/cvars/cg_startgoal-086db11/) | cvar | cgame | Start speed goal, if your start speed is above your goal speed, the text will be green, requires /cg_raceStart 1 |
| [`cg_stats`](/TaystJK/reference/cvars/cg_stats-0e14171/) | cvar | cgame | Controls `cg_stats` in the cgame module. |
| [`cg_stereoSeparation`](/TaystJK/reference/cvars/cg_stereoseparation-63c20da/) | cvar | cgame | Controls `cg_stereoSeparation` in the cgame module. |
| [`cg_strafeHelper`](/TaystJK/reference/cvars/cg_strafehelper-4850985/) | cvar | cgame | Configure with the /strafehelper command |
| [`cg_strafeHelper_FPS`](/TaystJK/reference/cvars/cg_strafehelper_fps-c64555f/) | cvar | cgame | Fats _ syntax to follow smod ;s |
| [`cg_strafeHelperActiveColor`](/TaystJK/reference/cvars/cg_strafehelperactivecolor-0c4cad4/) | cvar | cgame | Controls `cg_strafeHelperActiveColor` in the cgame module. |
| [`cg_strafeHelperCutoff`](/TaystJK/reference/cvars/cg_strafehelpercutoff-2cd5794/) | cvar | cgame | Controls `cg_strafeHelperCutoff` in the cgame module. |
| [`cg_strafeHelperInactiveAlpha`](/TaystJK/reference/cvars/cg_strafehelperinactivealpha-c641c50/) | cvar | cgame | Controls `cg_strafeHelperInactiveAlpha` in the cgame module. |
| [`cg_strafeHelperLineWidth`](/TaystJK/reference/cvars/cg_strafehelperlinewidth-790968e/) | cvar | cgame | Controls `cg_strafeHelperLineWidth` in the cgame module. |
| [`cg_strafeHelperOffset`](/TaystJK/reference/cvars/cg_strafehelperoffset-018a25b/) | cvar | cgame | Controls `cg_strafeHelperOffset` in the cgame module. |
| [`cg_strafeHelperPrecision`](/TaystJK/reference/cvars/cg_strafehelperprecision-9de34f5/) | cvar | cgame | Controls `cg_strafeHelperPrecision` in the cgame module. |
| [`cg_strafeTrailGhost`](/TaystJK/reference/cvars/cg_strafetrailghost-3933f97/) | cvar | cgame | Controls `cg_strafeTrailGhost` in the cgame module. |
| [`cg_strafeTrailPlayers`](/TaystJK/reference/cvars/cg_strafetrailplayers-e720b69/) | cvar | cgame | Controls `cg_strafeTrailPlayers` in the cgame module. |
| [`cg_strafeTrailRacersOnly`](/TaystJK/reference/cvars/cg_strafetrailracersonly-2296b15/) | cvar | cgame | Controls `cg_strafeTrailRacersOnly` in the cgame module. |
| [`cg_stylePlayer`](/TaystJK/reference/cvars/cg_styleplayer-c35894d/) | cvar | cgame | Configure with the /stylePlayer command |
| [`cg_teamChatsOnly`](/TaystJK/reference/cvars/cg_teamchatsonly-3b033ae/) | cvar | cgame | Hide non-team chat messages |
| [`cg_thirdPerson`](/TaystJK/reference/cvars/cg_thirdperson-9be206a/) | cvar | cgame | Controls `cg_thirdPerson` in the cgame module. |
| [`cg_thirdPersonAlpha`](/TaystJK/reference/cvars/cg_thirdpersonalpha-1dbc32f/) | cvar | cgame | Controls `cg_thirdPersonAlpha` in the cgame module. |
| [`cg_thirdPersonAngle`](/TaystJK/reference/cvars/cg_thirdpersonangle-8fc1e1d/) | cvar | cgame | Controls `cg_thirdPersonAngle` in the cgame module. |
| [`cg_thirdPersonCameraDamp`](/TaystJK/reference/cvars/cg_thirdpersoncameradamp-23ee471/) | cvar | cgame | Controls `cg_thirdPersonCameraDamp` in the cgame module. |
| [`cg_thirdPersonFlagAlpha`](/TaystJK/reference/cvars/cg_thirdpersonflagalpha-ce71971/) | cvar | cgame | Custom transparency of the CTF flag |
| [`cg_thirdPersonHorzOffset`](/TaystJK/reference/cvars/cg_thirdpersonhorzoffset-1e694a4/) | cvar | cgame | Controls `cg_thirdPersonHorzOffset` in the cgame module. |
| [`cg_thirdPersonPitchOffset`](/TaystJK/reference/cvars/cg_thirdpersonpitchoffset-4c885af/) | cvar | cgame | Controls `cg_thirdPersonPitchOffset` in the cgame module. |
| [`cg_thirdPersonRange`](/TaystJK/reference/cvars/cg_thirdpersonrange-4c9945a/) | cvar | cgame | Controls `cg_thirdPersonRange` in the cgame module. |
| [`cg_thirdPersonSpecialCam`](/TaystJK/reference/cvars/cg_thirdpersonspecialcam-7a949a2/) | cvar | cgame | Controls `cg_thirdPersonSpecialCam` in the cgame module. |
| [`cg_thirdPersonTargetDamp`](/TaystJK/reference/cvars/cg_thirdpersontargetdamp-2dc65c3/) | cvar | cgame | Controls `cg_thirdPersonTargetDamp` in the cgame module. |
| [`cg_thirdPersonVertOffset`](/TaystJK/reference/cvars/cg_thirdpersonvertoffset-9b21aeb/) | cvar | cgame | Controls `cg_thirdPersonVertOffset` in the cgame module. |
| [`cg_timescaleFadeEnd`](/TaystJK/reference/cvars/cg_timescalefadeend-da092b6/) | cvar | cgame | Controls `cg_timescaleFadeEnd` in the cgame module. |
| [`cg_timescaleFadeSpeed`](/TaystJK/reference/cvars/cg_timescalefadespeed-b1ffd95/) | cvar | cgame | Controls `cg_timescaleFadeSpeed` in the cgame module. |
| [`cg_tintHud`](/TaystJK/reference/cvars/cg_tinthud-0c71140/) | cvar | cgame | Changes the color of the HUD based on team color |
| [`cg_viewsize`](/TaystJK/reference/cvars/cg_viewsize-24d3727/) | cvar | cgame | Controls `cg_viewsize` in the cgame module. |
| [`cg_weaponCycleAmmo`](/TaystJK/reference/cvars/cg_weaponcycleammo-3286c8e/) | cvar | cgame | Controls `cg_weaponCycleAmmo` in the cgame module. |
| [`cg_zoomFov`](/TaystJK/reference/cvars/cg_zoomfov-c976ef9/) | cvar | cgame | The field of view when using +zoom |
| [`char_color_blue`](/TaystJK/reference/cvars/char_color_blue-3e5537b/) | cvar | engine-client | Player tint (Blue) |
| [`char_color_green`](/TaystJK/reference/cvars/char_color_green-bfa51ee/) | cvar | engine-client | Player tint (Green) |
| [`char_color_red`](/TaystJK/reference/cvars/char_color_red-bcef1ac/) | cvar | engine-client | Player tint (Red) |
| [`cjp_client`](/TaystJK/reference/cvars/cjp_client-30f1526/) | cvar | cgame | Controls `cjp_client` in the cgame module. |
| [`cl_afkTime`](/TaystJK/reference/cvars/cl_afktime-a051a42/) | cvar | engine-client | Minutes to autorename to afk, 0 to disable |
| [`cl_afkTimeUnfocused`](/TaystJK/reference/cvars/cl_afktimeunfocused-3a38f9b/) | cvar | engine-client | Minutes to autorename to afk while unfocused/minimized |
| [`cl_allowAltEnter`](/TaystJK/reference/cvars/cl_allowaltenter-dfdb5ca/) | cvar | engine-client | Enables use of ALT+ENTER keyboard combo to toggle fullscreen |
| [`cl_allowDownload`](/TaystJK/reference/cvars/cl_allowdownload-86fa984/) | cvar | engine-client | Allow downloading custom paks from server |
| [`cl_anglespeedkey`](/TaystJK/reference/cvars/cl_anglespeedkey-612edff/) | cvar | engine-client | Controls `cl_anglespeedkey` in the engine-client module. |
| [`cl_autolodscale`](/TaystJK/reference/cvars/cl_autolodscale-b9ad539/) | cvar | engine-client | Controls `cl_autolodscale` in the engine-client module. |
| [`cl_aviFrameRate`](/TaystJK/reference/cvars/cl_aviframerate-a13588d/) | cvar | engine-client | Controls `cl_aviFrameRate` in the engine-client module. |
| [`cl_coloredTextShadows`](/TaystJK/reference/cvars/cl_coloredtextshadows-e3b625f/) | cvar | renderer | Toggle JK2 1.02-style colored text shadows |
| [`cl_colorString`](/TaystJK/reference/cvars/cl_colorstring-dfaadba/) | cvar | engine-client | Bit value of selected colors in colorString, configure chat colors with /colorstring |
| [`cl_colorStringCount`](/TaystJK/reference/cvars/cl_colorstringcount-5e55bbd/) | cvar | engine-client | Controls `cl_colorStringCount` in the engine-client module. |
| [`cl_colorStringRandom`](/TaystJK/reference/cvars/cl_colorstringrandom-d3b1d9a/) | cvar | engine-client | Randomness of the colors changing, higher numbers are less random |
| [`cl_commandsize`](/TaystJK/reference/cvars/cl_commandsize-8b702b0/) | cvar | cgame | Controls `cl_commandsize` in the cgame module. |
| [`cl_consoleKeys`](/TaystJK/reference/cvars/cl_consolekeys-0430407/) | cvar | engine-client | Which keys are used to toggle the console |
| [`cl_consoleUseScanCode`](/TaystJK/reference/cvars/cl_consoleusescancode-557fe4e/) | cvar | engine-client | Use native console key detection |
| [`cl_conXOffset`](/TaystJK/reference/cvars/cl_conxoffset-bd19b50/) | cvar | engine-client | Controls `cl_conXOffset` in the engine-client module. |
| [`cl_currentServerAddress`](/TaystJK/reference/cvars/cl_currentserveraddress-f6d6414/) | cvar | cgame | Controls `cl_currentServerAddress` in the cgame module. |
| [`cl_debugMove`](/TaystJK/reference/cvars/cl_debugmove-84599e2/) | cvar | engine-client | Controls `cl_debugMove` in the engine-client module. |
| [`cl_discordRichPresence`](/TaystJK/reference/cvars/cl_discordrichpresence-c4b29a5/) | cvar | engine-client | Allow/disallow sharing current game information on Discord profile status |
| [`cl_discordRichPresenceSharePassword`](/TaystJK/reference/cvars/cl_discordrichpresencesharepassword-79479cd/) | cvar | engine-client | If set, sends password to Discord friends who request to join your game |
| [`cl_downloadCount`](/TaystJK/reference/cvars/cl_downloadcount-1882f4f/) | cvar | engine-client | Controls `cl_downloadCount` in the engine-client module. |
| [`cl_downloadName`](/TaystJK/reference/cvars/cl_downloadname-eff2323/) | cvar | engine-client | Controls `cl_downloadName` in the engine-client module. |
| [`cl_downloadPrompt`](/TaystJK/reference/cvars/cl_downloadprompt-2444b92/) | cvar | engine-client | Confirm pk3 downloads from the server |
| [`cl_downloadSize`](/TaystJK/reference/cvars/cl_downloadsize-d836714/) | cvar | engine-client | Controls `cl_downloadSize` in the engine-client module. |
| [`cl_downloadTime`](/TaystJK/reference/cvars/cl_downloadtime-59d8294/) | cvar | engine-client | Controls `cl_downloadTime` in the engine-client module. |
| [`cl_drawRecording`](/TaystJK/reference/cvars/cl_drawrecording-b820c48/) | cvar | engine-client | Selects one of the modes documented by JK2MV for `cl_drawRecording`. |
| [`cl_enableGuid`](/TaystJK/reference/cvars/cl_enableguid-d5d42ac/) | cvar | engine-client | Enable GUID userinfo identifier |
| [`cl_filterGames`](/TaystJK/reference/cvars/cl_filtergames-7e85224/) | cvar | engine-client | List of fs_game to filter (space separated) |
| [`cl_forceavidemo`](/TaystJK/reference/cvars/cl_forceavidemo-a2f9476/) | cvar | engine-client | Controls `cl_forceavidemo` in the engine-client module. |
| [`cl_framerate`](/TaystJK/reference/cvars/cl_framerate-6aed8d0/) | cvar | engine-client | Controls `cl_framerate` in the engine-client module. |
| [`cl_freelook`](/TaystJK/reference/cvars/cl_freelook-c416c51/) | cvar | engine-client | Mouse look |
| [`cl_guidServerUniq`](/TaystJK/reference/cvars/cl_guidserveruniq-7e6d8fe/) | cvar | engine-client | Use a unique guid value per server |
| [`cl_idrive`](/TaystJK/reference/cvars/cl_idrive-a66b0b8/) | cvar | engine-client | Controls `cl_idrive` in the engine-client module. |
| [`cl_lanForcePackets`](/TaystJK/reference/cvars/cl_lanforcepackets-cafc4eb/) | cvar | engine-client | Controls `cl_lanForcePackets` in the engine-client module. |
| [`cl_logChat`](/TaystJK/reference/cvars/cl_logchat-5d53487/) | cvar | engine-client | Toggle engine chat logs |
| [`cl_maxPackets`](/TaystJK/reference/cvars/cl_maxpackets-7b738c4/) | cvar | engine-client | Controls `cl_maxPackets` in the engine-client module. |
| [`cl_maxPing`](/TaystJK/reference/cvars/cl_maxping-0f77c67/) | cvar | engine-client | Max. ping for servers when searching the serverlist |
| [`cl_motd`](/TaystJK/reference/cvars/cl_motd-750627f/) | cvar | engine-client | Display welcome message from master server on the bottom of connection screen |
| [`cl_motdString`](/TaystJK/reference/cvars/cl_motdstring-b47e754/) | cvar | engine-client | Controls `cl_motdString` in the engine-client module. |
| [`cl_mouseAccel`](/TaystJK/reference/cvars/cl_mouseaccel-5b90310/) | cvar | engine-client | Mouse acceleration value |
| [`cl_mouseAccelOffset`](/TaystJK/reference/cvars/cl_mouseacceloffset-2ec97b6/) | cvar | engine-client | Mouse acceleration offset for style 1 |
| [`cl_mouseAccelStyle`](/TaystJK/reference/cvars/cl_mouseaccelstyle-fd1405e/) | cvar | engine-client | Mouse accelration style (0:legacy, 1:QuakeLive) |
| [`cl_nodelta`](/TaystJK/reference/cvars/cl_nodelta-8da8fc8/) | cvar | engine-client | Controls `cl_nodelta` in the engine-client module. |
| [`cl_noprint`](/TaystJK/reference/cvars/cl_noprint-26599b8/) | cvar | engine-client | Controls `cl_noprint` in the engine-client module. |
| [`cl_packetdup`](/TaystJK/reference/cvars/cl_packetdup-86b0e4b/) | cvar | engine-client | Controls `cl_packetdup` in the engine-client module. |
| [`cl_paused`](/TaystJK/reference/cvars/cl_paused-2461a17/) | cvar | cgame | Controls `cl_paused` in the cgame module. |
| [`cl_pitchspeed`](/TaystJK/reference/cvars/cl_pitchspeed-c2c603e/) | cvar | engine-client | Controls `cl_pitchspeed` in the engine-client module. |
| [`cl_ratioFix`](/TaystJK/reference/cvars/cl_ratiofix-67440df/) | cvar | engine-client | Widescreen aspect ratio correction |
| [`cl_reconnectArgs`](/TaystJK/reference/cvars/cl_reconnectargs-fbdecc0/) | cvar | engine-client | Arguments provided when last connecting to a server |
| [`cl_renderer`](/TaystJK/reference/cvars/cl_renderer-dc9f64f/) | cvar | engine-client | Which renderer library to use |
| [`cl_run`](/TaystJK/reference/cvars/cl_run-c5db87c/) | cvar | engine-client | Always run |
| [`cl_running`](/TaystJK/reference/cvars/cl_running-68ed015/) | cvar | engine-shared | Is the client running? |
| [`cl_serverStatusResendTime`](/TaystJK/reference/cvars/cl_serverstatusresendtime-ffba1d7/) | cvar | engine-client | Controls `cl_serverStatusResendTime` in the engine-client module. |
| [`cl_showmouserate`](/TaystJK/reference/cvars/cl_showmouserate-09d0667/) | cvar | engine-client | Controls `cl_showMouseRate` in the engine-client module. |
| [`cl_shownet`](/TaystJK/reference/cvars/cl_shownet-85e342e/) | cvar | engine-client | Controls `cl_shownet` in the engine-client module. |
| [`cl_showTimeDelta`](/TaystJK/reference/cvars/cl_showtimedelta-f5e0f42/) | cvar | engine-client | Controls `cl_showTimeDelta` in the engine-client module. |
| [`cl_timeNudge`](/TaystJK/reference/cvars/cl_timenudge-4435ccb/) | cvar | engine-client | Controls `cl_timeNudge` in the engine-client module. |
| [`cl_timeout`](/TaystJK/reference/cvars/cl_timeout-cc5e885/) | cvar | engine-client | Controls `cl_timeout` in the engine-client module. |
| [`cl_yawspeed`](/TaystJK/reference/cvars/cl_yawspeed-7102728/) | cvar | engine-client | Controls `cl_yawspeed` in the engine-client module. |
| [`cm_debugSize`](/TaystJK/reference/cvars/cm_debugsize-960fad0/) | cvar | engine-shared | Controls `cv` in the engine-shared module. |
| [`cm_noAreas`](/TaystJK/reference/cvars/cm_noareas-486fcb8/) | cvar | engine-shared | Controls `cm_noAreas` in the engine-shared module. |
| [`cm_noCurves`](/TaystJK/reference/cvars/cm_nocurves-7fbfdd9/) | cvar | engine-shared | Controls `cm_noCurves` in the engine-shared module. |
| [`cm_playerCurveClip`](/TaystJK/reference/cvars/cm_playercurveclip-ab37e03/) | cvar | engine-shared | Controls `cm_playerCurveClip` in the engine-shared module. |
| [`color1`](/TaystJK/reference/cvars/color1-9367edb/) | cvar | engine-client | Player saber1 color |
| [`color2`](/TaystJK/reference/cvars/color2-fffd19a/) | cvar | engine-client | Player saber2 color |
| [`com_affinity`](/TaystJK/reference/cvars/com_affinity-f32bd34/) | cvar | engine-shared | Controls `com_affinity` in the engine-shared module. |
| [`com_ansiColor`](/TaystJK/reference/cvars/com_ansicolor-94ebdea/) | cvar | engine-shared | Controls `com_ansiColor` in the engine-shared module. |
| [`com_bootlogo`](/TaystJK/reference/cvars/com_bootlogo-4f85af0/) | cvar | engine-shared | Show intro movies |
| [`com_buildScript`](/TaystJK/reference/cvars/com_buildscript-4b0ed7d/) | cvar | cgame | Controls `com_buildScript` in the cgame module. |
| [`com_busyWait`](/TaystJK/reference/cvars/com_busywait-3e64dd5/) | cvar | engine-shared | Controls `com_busyWait` in the engine-shared module. |
| [`com_cameraMode`](/TaystJK/reference/cvars/com_cameramode-83e70f2/) | cvar | cgame | Controls `com_cameraMode` in the cgame module. |
| [`com_errorMessage`](/TaystJK/reference/cvars/com_errormessage-94c2b45/) | cvar | engine-shared | Give com_errorMessage a default so it won't come back to life after a resetDefaults |
| [`com_G2Report`](/TaystJK/reference/cvars/com_g2report-5cb35fa/) | cvar | engine-shared | Controls `com_G2Report` in the engine-shared module. |
| [`com_homepath`](/TaystJK/reference/cvars/com_homepath-79625df/) | cvar | engine-shared | Controls `com_homepath` in the engine-shared module. |
| [`com_maxFPS`](/TaystJK/reference/cvars/com_maxfps-658bd0c/) | cvar | cgame | Maximum frames per second |
| [`com_maxfpsMinimized`](/TaystJK/reference/cvars/com_maxfpsminimized-ee39c66/) | cvar | engine-shared | Controls `com_maxfpsMinimized` in the engine-shared module. |
| [`com_maxfpsUnfocused`](/TaystJK/reference/cvars/com_maxfpsunfocused-888b9d8/) | cvar | engine-shared | Controls `com_maxfpsUnfocused` in the engine-shared module. |
| [`com_minimized`](/TaystJK/reference/cvars/com_minimized-fa62f52/) | cvar | engine-shared | Controls `com_minimized` in the engine-shared module. |
| [`com_optvehtrace`](/TaystJK/reference/cvars/com_optvehtrace-690075a/) | cvar | cgame | Controls `com_optvehtrace` in the cgame module. |
| [`com_priority`](/TaystJK/reference/cvars/com_priority-cac1576/) | cvar | engine-shared | Duno, -1 = do nothing, 1 = low priority, 2 = normal priority, 3 = high priority? i guess?? |
| [`com_renderfps`](/TaystJK/reference/cvars/com_renderfps-485cbcb/) | cvar | engine-shared | Controls `com_renderfps` in the engine-shared module. |
| [`com_showtrace`](/TaystJK/reference/cvars/com_showtrace-0461442/) | cvar | engine-shared | Controls `com_showtrace` in the engine-shared module. |
| [`com_speeds`](/TaystJK/reference/cvars/com_speeds-19c0e9f/) | cvar | engine-shared | Controls `com_speeds` in the engine-shared module. |
| [`com_steamIntegration`](/TaystJK/reference/cvars/com_steamintegration-01ca9bb/) | cvar | engine-shared | Enables automatic Steam API integration (requires a steam_api64.dll to be in GameData) |
| [`com_timestamps`](/TaystJK/reference/cvars/com_timestamps-e16da1a/) | cvar | engine-shared | Show timestamps in terminal and qconsole.log |
| [`com_unfocused`](/TaystJK/reference/cvars/com_unfocused-804c4c7/) | cvar | engine-shared | Controls `com_unfocused` in the engine-shared module. |
| [`com_validateZone`](/TaystJK/reference/cvars/com_validatezone-d30815f/) | cvar | engine-shared | Controls `com_validateZone` in the engine-shared module. |
| [`con_autoclear`](/TaystJK/reference/cvars/con_autoclear-ff60e4c/) | cvar | engine-client | Automatically clear console input on close |
| [`con_height`](/TaystJK/reference/cvars/con_height-41c46da/) | cvar | engine-client | Adjust the height of the console |
| [`con_notifyconnect`](/TaystJK/reference/cvars/con_notifyconnect-0a48d2d/) | cvar | engine-client | Notifies you when someone connects to the server |
| [`con_notifytime`](/TaystJK/reference/cvars/con_notifytime-ab6ca08/) | cvar | engine-client | How many seconds notify messages should be shown before they fade away |
| [`con_notifyvote`](/TaystJK/reference/cvars/con_notifyvote-05d6ee1/) | cvar | engine-client | Notifies you when someone calls a vote |
| [`con_notifywords`](/TaystJK/reference/cvars/con_notifywords-97dfc24/) | cvar | engine-client | Notifies you when defined words are mentioned |
| [`con_opacity`](/TaystJK/reference/cvars/con_opacity-d0e065e/) | cvar | engine-client | Opacity of console background |
| [`con_scale`](/TaystJK/reference/cvars/con_scale-d334b5a/) | cvar | engine-client | Console character scale |
| [`con_timestamps`](/TaystJK/reference/cvars/con_timestamps-2b4f0eb/) | cvar | engine-client | Display timestamps infront of console lines |
| [`cp_cosmetics`](/TaystJK/reference/cvars/cp_cosmetics-488f751/) | cvar | cgame | Controls `cp_cosmetics` in the cgame module. |
| [`cp_pluginDisable`](/TaystJK/reference/cvars/cp_plugindisable-715762d/) | cvar | cgame | 'enable' holstered saber (512) and ledge grab (1536) by default, to avoid missing JA+ animations |
| [`cp_sbRGB1`](/TaystJK/reference/cvars/cp_sbrgb1-0369930/) | cvar | cgame | Controls `cp_sbRGB1` in the cgame module. |
| [`cp_sbRGB2`](/TaystJK/reference/cvars/cp_sbrgb2-81b016f/) | cvar | cgame | Controls `cp_sbRGB2` in the cgame module. |
| [`d_altRoutes`](/TaystJK/reference/cvars/d_altroutes-c57e072/) | cvar | game | Controls `d_altRoutes` in the game module. |
| [`d_asynchronousGroupAI`](/TaystJK/reference/cvars/d_asynchronousgroupai-fccc4e1/) | cvar | game | Controls `d_asynchronousGroupAI` in the game module. |
| [`d_break`](/TaystJK/reference/cvars/d_break-eaf2fa0/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_JediAI`](/TaystJK/reference/cvars/d_jediai-6689f4f/) | cvar | game | Controls `d_JediAI` in the game module. |
| [`d_noGroupAI`](/TaystJK/reference/cvars/d_nogroupai-47246c1/) | cvar | game | Controls `d_noGroupAI` in the game module. |
| [`d_noIntermissionWait`](/TaystJK/reference/cvars/d_nointermissionwait-961a829/) | cvar | game | Controls `d_noIntermissionWait` in the game module. |
| [`d_noroam`](/TaystJK/reference/cvars/d_noroam-44d534c/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_npcai`](/TaystJK/reference/cvars/d_npcai-d1346e9/) | cvar | game | Controls `d_npcai` in the game module. |
| [`d_npcaiming`](/TaystJK/reference/cvars/d_npcaiming-3221a7b/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_npcfreeze`](/TaystJK/reference/cvars/d_npcfreeze-0300949/) | cvar | game | Controls `d_npcfreeze` in the game module. |
| [`d_patched`](/TaystJK/reference/cvars/d_patched-c172442/) | cvar | game | Controls `d_patched` in the game module. |
| [`d_perPlayerGhoul2`](/TaystJK/reference/cvars/d_perplayerghoul2-9292fd8/) | cvar | game | Controls `d_perPlayerGhoul2` in the game module. |
| [`d_powerDuelPrint`](/TaystJK/reference/cvars/d_powerduelprint-0db3ba4/) | cvar | game | Controls `d_powerDuelPrint` in the game module. |
| [`d_projectileGhoul2Collision`](/TaystJK/reference/cvars/d_projectileghoul2collision-6d3853e/) | cvar | game | Controls `d_projectileGhoul2Collision` in the game module. |
| [`d_saberAlwaysBoxTrace`](/TaystJK/reference/cvars/d_saberalwaysboxtrace-3a56bc8/) | cvar | game | Controls `d_saberAlwaysBoxTrace` in the game module. |
| [`d_saberBoxTraceSize`](/TaystJK/reference/cvars/d_saberboxtracesize-3dfdf82/) | cvar | game | Controls `d_saberBoxTraceSize` in the game module. |
| [`d_saberCombat`](/TaystJK/reference/cvars/d_sabercombat-ad98941/) | cvar | game | Registered by the current source, but no user-facing behavior description has been verified. |
| [`d_saberGhoul2Collision`](/TaystJK/reference/cvars/d_saberghoul2collision-2081f36/) | cvar | game | Controls `d_saberGhoul2Collision` in the game module. |
| [`d_saberInterpolate`](/TaystJK/reference/cvars/d_saberinterpolate-98af971/) | cvar | game | Controls `d_saberInterpolate` in the game module. |
| [`d_saberKickTweak`](/TaystJK/reference/cvars/d_saberkicktweak-1706de8/) | cvar | game | Controls `d_saberKickTweak` in the game module. |
| [`d_saberSPStyleDamage`](/TaystJK/reference/cvars/d_saberspstyledamage-2dd455c/) | cvar | game | Toggle use of SP style damage in normal game. |
| [`d_saberStanceDebug`](/TaystJK/reference/cvars/d_saberstancedebug-9609018/) | cvar | game | Controls `d_saberStanceDebug` in the game module. |
| [`d_siegeSeekerNPC`](/TaystJK/reference/cvars/d_siegeseekernpc-7419e17/) | cvar | game | Controls `d_siegeSeekerNPC` in the game module. |
| [`debug_protocol`](/TaystJK/reference/cvars/debug_protocol-51b58be/) | cvar | ui | Controls `debug_protocol` in the ui module. |
| [`debugBB`](/TaystJK/reference/cvars/debugbb-1d5d0a8/) | cvar | cgame | Controls `debugBB` in the cgame module. |
| [`debuggraph`](/TaystJK/reference/cvars/debuggraph-8bd94d1/) | cvar | engine-client | Controls `cl_debuggraph` in the engine-client module. |
| [`dedicated`](/TaystJK/reference/cvars/dedicated-0d30712/) | cvar | game | Controls `dedicated` in the game module. |
| [`developer`](/TaystJK/reference/cvars/developer-3dacbce/) | cvar | game | Developer mode |
| [`dmflags`](/TaystJK/reference/cvars/dmflags-9484c55/) | cvar | game | Controls `dmflags` in the game module. |
| [`duel_fraglimit`](/TaystJK/reference/cvars/duel_fraglimit-5cd7d2a/) | cvar | game | Controls `duel_fraglimit` in the game module. |
| [`fixedtime`](/TaystJK/reference/cvars/fixedtime-30e21eb/) | cvar | engine-shared | Controls `com_fixedtime` in the engine-shared module. |
| [`forcepowers`](/TaystJK/reference/cvars/forcepowers-5f9594f/) | cvar | cgame | Player forcepowers |
| [`fraglimit`](/TaystJK/reference/cvars/fraglimit-0b2d675/) | cvar | game | Controls `fraglimit` in the game module. |
| [`fs_apppath`](/TaystJK/reference/cvars/fs_apppath-eaa658c/) | cvar | engine-shared | (Read Only) Location of OSX .app bundle |
| [`fs_basegame`](/TaystJK/reference/cvars/fs_basegame-34b9b3a/) | cvar | engine-shared | Controls `fs_basegame` in the engine-shared module. |
| [`fs_basepath`](/TaystJK/reference/cvars/fs_basepath-b0ea0cc/) | cvar | engine-shared | (Read Only) Location for game files |
| [`fs_cdpath`](/TaystJK/reference/cvars/fs_cdpath-e7e5afa/) | cvar | engine-shared | (Read Only) Location for development files |
| [`fs_copyfiles`](/TaystJK/reference/cvars/fs_copyfiles-d93a4a0/) | cvar | engine-shared | Controls `fs_copyfiles` in the engine-shared module. |
| [`fs_debug`](/TaystJK/reference/cvars/fs_debug-bfc2f15/) | cvar | engine-shared | Controls `fs_debug` in the engine-shared module. |
| [`fs_dirbeforepak`](/TaystJK/reference/cvars/fs_dirbeforepak-70f2a5d/) | cvar | engine-shared | Prioritize directories before paks if not pure |
| [`fs_forcegame`](/TaystJK/reference/cvars/fs_forcegame-3547288/) | cvar | engine-shared | Folder to use for overriding of fs_game (can not be set by the server). |
| [`fs_game`](/TaystJK/reference/cvars/fs_game-520c78a/) | cvar | engine-shared | Mod directory |
| [`fs_homepath`](/TaystJK/reference/cvars/fs_homepath-7aca1d5/) | cvar | engine-shared | (Read/Write) Location for user generated files |
| [`fx_countScale`](/TaystJK/reference/cvars/fx_countscale-467322f/) | cvar | engine-client | Controls `fx_countScale` in the engine-client module. |
| [`fx_debug`](/TaystJK/reference/cvars/fx_debug-b5dd314/) | cvar | engine-client | Controls `fx_debug` in the engine-client module. |
| [`fx_freeze`](/TaystJK/reference/cvars/fx_freeze-e0afc73/) | cvar | engine-client | Controls `fx_freeze` in the engine-client module. |
| [`fx_jk2`](/TaystJK/reference/cvars/fx_jk2-16a4fc2/) | cvar | engine-client | Displays jk2 style projectile fx - 0: Disabled - 1: Enabled |
| [`fx_nearCull`](/TaystJK/reference/cvars/fx_nearcull-19f1396/) | cvar | engine-client | Controls `fx_nearCull` in the engine-client module. |
| [`fx_physics`](/TaystJK/reference/cvars/fx_physics-6ce403e/) | cvar | engine-client | Controls physics applied to FX system particles - 0: Disable all FX physics - 1: use non-expensive physics only - 2: Use flags in the fx file (Default behavior) - 3: Force expensive physics on all particles |
| [`g_adaptRespawn`](/TaystJK/reference/cvars/g_adaptrespawn-48b0aed/) | cvar | game | Controls `g_adaptRespawn` in the game module. |
| [`g_allowDuelSuicide`](/TaystJK/reference/cvars/g_allowduelsuicide-4945a44/) | cvar | game | Controls `g_allowDuelSuicide` in the game module. |
| [`g_allowFlagThrow`](/TaystJK/reference/cvars/g_allowflagthrow-a034db8/) | cvar | game | Allow use of /throwflag command. |
| [`g_allowGrapple`](/TaystJK/reference/cvars/g_allowgrapple-4e7510c/) | cvar | game | 1=Tarzan style. 2=JA+ Style. |
| [`g_allowHighPingDuelist`](/TaystJK/reference/cvars/g_allowhighpingduelist-963519a/) | cvar | game | Controls `g_allowHighPingDuelist` in the game module. |
| [`g_allowNoFollow`](/TaystJK/reference/cvars/g_allownofollow-6efa2b1/) | cvar | game | Allow players to hide themselves and not be spectated/seen in racemode. |
| [`g_allowNPC`](/TaystJK/reference/cvars/g_allownpc-d36f098/) | cvar | game | Controls `g_allowNPC` in the game module. |
| [`g_allowRaceTele`](/TaystJK/reference/cvars/g_allowracetele-7aca7fe/) | cvar | game | 1=Allow amtele in racemode. 2=Also allow noclip. |
| [`g_allowRegistration`](/TaystJK/reference/cvars/g_allowregistration-45f9f37/) | cvar | game | Controls `g_allowRegistration` in the game module. |
| [`g_allowSaberSwitch`](/TaystJK/reference/cvars/g_allowsaberswitch-474c34a/) | cvar | game | Controls `g_allowSaberSwitch` in the game module. |
| [`g_allowSpotting`](/TaystJK/reference/cvars/g_allowspotting-88ae036/) | cvar | game | Controls `g_allowSpotting` in the game module. |
| [`g_allowTargetLaser`](/TaystJK/reference/cvars/g_allowtargetlaser-61aa826/) | cvar | game | Target laser used with +button14 |
| [`g_allowTeamVote`](/TaystJK/reference/cvars/g_allowteamvote-d6b1ddf/) | cvar | game | Controls `g_allowTeamVote` in the game module. |
| [`g_allowUseInDuel`](/TaystJK/reference/cvars/g_allowuseinduel-c53aead/) | cvar | game | Controls `g_allowUseInDuel` in the game module. |
| [`g_allowVGS`](/TaystJK/reference/cvars/g_allowvgs-cbfffd9/) | cvar | game | Controls `g_allowVGS` in the game module. |
| [`g_allowVote`](/TaystJK/reference/cvars/g_allowvote-fdda916/) | cvar | game | Controls `g_allowVote` in the game module. |
| [`g_armBreakage`](/TaystJK/reference/cvars/g_armbreakage-8d44482/) | cvar | game | Controls `g_armBreakage` in the game module. |
| [`g_austrian`](/TaystJK/reference/cvars/g_austrian-ebbf80f/) | cvar | game | Controls `g_austrian` in the game module. |
| [`g_autoMapCycle`](/TaystJK/reference/cvars/g_automapcycle-2b9887f/) | cvar | game | Controls `g_autoMapCycle` in the game module. |
| [`g_autoQuit`](/TaystJK/reference/cvars/g_autoquit-bc06a6f/) | cvar | game | Controls `g_autoQuit` in the game module. |
| [`g_banIPs`](/TaystJK/reference/cvars/g_banips-5693b4b/) | cvar | game | Controls `g_banIPs` in the game module. |
| [`g_botsFile`](/TaystJK/reference/cvars/g_botsfile-8fb6936/) | cvar | game | Controls `botsFile` in the game module. |
| [`g_consoleMOTD`](/TaystJK/reference/cvars/g_consolemotd-62e668c/) | cvar | game | Controls `g_consoleMOTD` in the game module. |
| [`g_corpseRemovalTime`](/TaystJK/reference/cvars/g_corpseremovaltime-1c8df23/) | cvar | game | Controls `g_corpseRemovalTime` in the game module. |
| [`g_damageNumbers`](/TaystJK/reference/cvars/g_damagenumbers-134f14c/) | cvar | game | 1-7. Controls different types of damagenumber printouts. |
| [`g_debugAlloc`](/TaystJK/reference/cvars/g_debugalloc-f84f0d3/) | cvar | game | Controls `g_debugAlloc` in the game module. |
| [`g_debugDamage`](/TaystJK/reference/cvars/g_debugdamage-4185007/) | cvar | game | Controls `g_debugDamage` in the game module. |
| [`g_debugMelee`](/TaystJK/reference/cvars/g_debugmelee-cf2d02e/) | cvar | game | Controls `g_debugMelee` in the game module. |
| [`g_debugMove`](/TaystJK/reference/cvars/g_debugmove-9478efa/) | cvar | game | Controls `g_debugMove` in the game module. |
| [`g_debugSaberLocks`](/TaystJK/reference/cvars/g_debugsaberlocks-38c74dd/) | cvar | game | Controls `g_debugSaberLocks` in the game module. |
| [`g_debugServerSkel`](/TaystJK/reference/cvars/g_debugserverskel-10f12d9/) | cvar | game | Controls `g_debugServerSkel` in the game module. |
| [`g_disableServerG2`](/TaystJK/reference/cvars/g_disableserverg2-d981ab3/) | cvar | game | Controls `g_disableServerG2` in the game module. |
| [`g_dismember`](/TaystJK/reference/cvars/g_dismember-209a737/) | cvar | game | Controls `g_dismember` in the game module. |
| [`g_doWarmup`](/TaystJK/reference/cvars/g_dowarmup-9a8d9cc/) | cvar | game | Controls `g_doWarmup` in the game module. |
| [`g_duelDistanceLimit`](/TaystJK/reference/cvars/g_dueldistancelimit-9422409/) | cvar | game | Controls `g_duelDistanceLimit` in the game module. |
| [`g_duelStartArmor`](/TaystJK/reference/cvars/g_duelstartarmor-56fbd3c/) | cvar | game | Controls `g_duelStartArmor` in the game module. |
| [`g_duelStartHealth`](/TaystJK/reference/cvars/g_duelstarthealth-8a98d72/) | cvar | game | Controls `g_duelStartHealth` in the game module. |
| [`g_duelWeaponDisable`](/TaystJK/reference/cvars/g_duelweapondisable-a038b8f/) | cvar | game | Controls `g_duelWeaponDisable` in the game module. |
| [`g_eloKValue1`](/TaystJK/reference/cvars/g_elokvalue1-29f4799/) | cvar | game | Controls `g_eloKValue1` in the game module. |
| [`g_eloKValue2`](/TaystJK/reference/cvars/g_elokvalue2-2c17376/) | cvar | game | Controls `g_eloKValue2` in the game module. |
| [`g_eloKValue3`](/TaystJK/reference/cvars/g_elokvalue3-e6ddcc0/) | cvar | game | Controls `g_eloKValue3` in the game module. |
| [`g_eloMinimumDuels`](/TaystJK/reference/cvars/g_elominimumduels-b90832e/) | cvar | game | Controls `g_eloMinimumDuels` in the game module. |
| [`g_eloRanking`](/TaystJK/reference/cvars/g_eloranking-b050319/) | cvar | game | Enables the built in elo ranking for duels. |
| [`g_emotesDisable`](/TaystJK/reference/cvars/g_emotesdisable-8df1bb9/) | cvar | game | Configured with /toggleEmotes command |
| [`g_ff_objectives`](/TaystJK/reference/cvars/g_ff_objectives-5800a9a/) | cvar | game | Controls `g_ff_objectives` in the game module. |
| [`g_filterBan`](/TaystJK/reference/cvars/g_filterban-1aadd85/) | cvar | game | Controls `g_filterBan` in the game module. |
| [`g_fixCTFScores`](/TaystJK/reference/cvars/g_fixctfscores-f3e8d8d/) | cvar | game | Tweak CTF score amounts. |
| [`g_fixFlagSuicide`](/TaystJK/reference/cvars/g_fixflagsuicide-f382dc6/) | cvar | game | Don't auto return flag when flag carrier suicides. |
| [`g_fixKillCredit`](/TaystJK/reference/cvars/g_fixkillcredit-250953f/) | cvar | game | 1=Award kill credit after target suicides/spectates. 2=Also for disconnects/reconnects. |
| [`g_fixPlayerCollision`](/TaystJK/reference/cvars/g_fixplayercollision-c0ccf93/) | cvar | game | Controls `g_fixPlayerCollision` in the game module. |
| [`g_fixRoll`](/TaystJK/reference/cvars/g_fixroll-09a4b25/) | cvar | game | 1=JA+ style base roll. //2=Chainable roll. //3=JK2 style roll. |
| [`g_fixSaberInGrip`](/TaystJK/reference/cvars/g_fixsaberingrip-b95f6ac/) | cvar | game | 1=Grip does not turn off lightsaber. 2=Same as 1 and also target can toggle lightsaber in grip. 3=Same as 2 and also target can switch saberstyle in grip. |
| [`g_fixSaberMoveData`](/TaystJK/reference/cvars/g_fixsabermovedata-4619480/) | cvar | game | Controls `g_fixSaberMoveData` in the game module. |
| [`g_fixSlidePhysics`](/TaystJK/reference/cvars/g_fixslidephysics-b4eea18/) | cvar | game | 1=Fixed slide physics for NPCS. 2=Fixed slide physics for NPCs and players. |
| [`g_flagDrag`](/TaystJK/reference/cvars/g_flagdrag-88dcb4b/) | cvar | game | Add air friction to flag carrier. |
| [`g_flipKick`](/TaystJK/reference/cvars/g_flipkick-64576b3/) | cvar | game | 1=JA+ style. 2=Floodprotected to one kick every 50ms. 3=JK2 style. |
| [`g_forceBasedTeams`](/TaystJK/reference/cvars/g_forcebasedteams-349b27a/) | cvar | game | Controls `g_forceBasedTeams` in the game module. |
| [`g_forceClientUpdateRate`](/TaystJK/reference/cvars/g_forceclientupdaterate-1c32854/) | cvar | game | Controls `g_forceClientUpdateRate` in the game module. |
| [`g_forceDodge`](/TaystJK/reference/cvars/g_forcedodge-48cc6f3/) | cvar | game | Controls `g_forceDodge` in the game module. |
| [`g_forceLogin`](/TaystJK/reference/cvars/g_forcelogin-19fc6bd/) | cvar | game | 1=Force players to login in order to be ingame. 2=also block them from chatting until logging in. 3=also block them from renaming until logging in. |
| [`g_forcePowerDisable`](/TaystJK/reference/cvars/g_forcepowerdisable-370e0a6/) | cvar | game | Controls `g_forcePowerDisable` in the game module. |
| [`g_forceRegenTime`](/TaystJK/reference/cvars/g_forceregentime-6e2c86f/) | cvar | game | Controls `g_forceRegenTime` in the game module. |
| [`g_forceRespawn`](/TaystJK/reference/cvars/g_forcerespawn-ad887df/) | cvar | game | Controls `g_forceRespawn` in the game module. |
| [`g_fraglimitVoteCorrection`](/TaystJK/reference/cvars/g_fraglimitvotecorrection-2977f70/) | cvar | game | Controls `g_fraglimitVoteCorrection` in the game module. |
| [`g_friendlyFire`](/TaystJK/reference/cvars/g_friendlyfire-e3552b6/) | cvar | game | Controls `g_friendlyFire` in the game module. |
| [`g_friendlySaber`](/TaystJK/reference/cvars/g_friendlysaber-a3dc40b/) | cvar | game | Controls `g_friendlySaber` in the game module. |
| [`g_fullAdminLevel`](/TaystJK/reference/cvars/g_fulladminlevel-baac21c/) | cvar | game | Controls `g_fullAdminLevel` in the game module. |
| [`g_fullAdminMsg`](/TaystJK/reference/cvars/g_fulladminmsg-a1df874/) | cvar | game | Controls `g_fullAdminMsg` in the game module. |
| [`g_fullAdminPass`](/TaystJK/reference/cvars/g_fulladminpass-11858c2/) | cvar | game | Controls `g_fullAdminPass` in the game module. |
| [`g_fullInheritance`](/TaystJK/reference/cvars/g_fullinheritance-fb4c838/) | cvar | game | Scale of all player momentum gained by projectiles. |
| [`g_g2TraceLod`](/TaystJK/reference/cvars/g_g2tracelod-5bdfdfd/) | cvar | game | Controls `g_g2TraceLod` in the game module. |
| [`g_gametype`](/TaystJK/reference/cvars/g_gametype-cc259e5/) | cvar | game | Server gametype value |
| [`g_glitchKickDamage`](/TaystJK/reference/cvars/g_glitchkickdamage-381e14c/) | cvar | game | Controls `g_glitchKickDamage` in the game module. |
| [`g_gravity`](/TaystJK/reference/cvars/g_gravity-8571dee/) | cvar | game | Controls `g_gravity` in the game module. |
| [`g_gunGame`](/TaystJK/reference/cvars/g_gungame-0b95542/) | cvar | game | Controls `g_gunGame` in the game module. |
| [`g_hookFloodProtect`](/TaystJK/reference/cvars/g_hookfloodprotect-882bcc8/) | cvar | game | Milliseconds between hook shots |
| [`g_hookInheritance`](/TaystJK/reference/cvars/g_hookinheritance-d65c1d8/) | cvar | game | Controls `g_hookInheritance` in the game module. |
| [`g_hookSpeed`](/TaystJK/reference/cvars/g_hookspeed-4804994/) | cvar | game | Speed that grapple hook travels at |
| [`g_hookStrength`](/TaystJK/reference/cvars/g_hookstrength-fc0d002/) | cvar | game | Speed that grapple pulls you at |
| [`g_hookStrength1`](/TaystJK/reference/cvars/g_hookstrength1-e5b30e7/) | cvar | game | Controls `g_hookStrength1` in the game module. |
| [`g_hookStrength2`](/TaystJK/reference/cvars/g_hookstrength2-5d40a55/) | cvar | game | Controls `g_hookStrength2` in the game module. |
| [`g_inactivity`](/TaystJK/reference/cvars/g_inactivity-ff5f46f/) | cvar | game | Controls `g_inactivity` in the game module. |
| [`g_jediVmerc`](/TaystJK/reference/cvars/g_jedivmerc-0e45262/) | cvar | game | Controls `g_jediVmerc` in the game module. |
| [`g_juniorAdminLevel`](/TaystJK/reference/cvars/g_junioradminlevel-0881d19/) | cvar | game | Controls `g_juniorAdminLevel` in the game module. |
| [`g_juniorAdminMsg`](/TaystJK/reference/cvars/g_junioradminmsg-60177a9/) | cvar | game | Controls `g_juniorAdminMsg` in the game module. |
| [`g_juniorAdminPass`](/TaystJK/reference/cvars/g_junioradminpass-f2dc6ae/) | cvar | game | Controls `g_juniorAdminPass` in the game module. |
| [`g_knockback`](/TaystJK/reference/cvars/g_knockback-bd8fbb6/) | cvar | game | Controls `g_knockback` in the game module. |
| [`g_KOTH`](/TaystJK/reference/cvars/g_koth-67b50a0/) | cvar | game | Controls `g_KOTH` in the game module. |
| [`g_LegDangle`](/TaystJK/reference/cvars/g_legdangle-499ee3b/) | cvar | game | Toggle the leg dangle animation which is not predicted and results in jerkyness on ledges with high ping. |
| [`g_locationBasedDamage`](/TaystJK/reference/cvars/g_locationbaseddamage-f99568b/) | cvar | game | Controls `g_locationBasedDamage` in the game module. |
| [`g_log`](/TaystJK/reference/cvars/g_log-f2fc3fb/) | cvar | game | Controls `g_log` in the game module. |
| [`g_logClientInfo`](/TaystJK/reference/cvars/g_logclientinfo-53d26bc/) | cvar | game | Controls `g_logClientInfo` in the game module. |
| [`g_logSync`](/TaystJK/reference/cvars/g_logsync-d545359/) | cvar | game | Controls `g_logSync` in the game module. |
| [`g_maxConnPerIP`](/TaystJK/reference/cvars/g_maxconnperip-714b0e2/) | cvar | game | Controls `g_maxConnPerIP` in the game module. |
| [`g_maxFallDmg`](/TaystJK/reference/cvars/g_maxfalldmg-e8af044/) | cvar | game | Controls `g_maxFallDmg` in the game module. |
| [`g_maxForceRank`](/TaystJK/reference/cvars/g_maxforcerank-6e1aa63/) | cvar | game | Controls `g_maxForceRank` in the game module. |
| [`g_maxGameClients`](/TaystJK/reference/cvars/g_maxgameclients-5050424/) | cvar | game | Controls `g_maxGameClients` in the game module. |
| [`g_maxHolocronCarry`](/TaystJK/reference/cvars/g_maxholocroncarry-00643fd/) | cvar | game | Controls `g_maxHolocronCarry` in the game module. |
| [`g_maxSaberDefense`](/TaystJK/reference/cvars/g_maxsaberdefense-6bba186/) | cvar | game | -1 disables, 0/1/2/3 enables and clamps level |
| [`g_motd`](/TaystJK/reference/cvars/g_motd-6d67b6c/) | cvar | game | Controls `g_motd` in the game module. |
| [`g_movementStyle`](/TaystJK/reference/cvars/g_movementstyle-cf714d4/) | cvar | game | Force movement style for players. 0=SIEGE 1=JKA 2=QW 3=CPM 4=Q3 5=PJK 6=WSW |
| [`g_needpass`](/TaystJK/reference/cvars/g_needpass-d848438/) | cvar | game | Server needs password to join |
| [`g_neutralFlag`](/TaystJK/reference/cvars/g_neutralflag-55bb88d/) | cvar | game | Controls `g_neutralFlag` in the game module. |
| [`g_neutralFlagTimer`](/TaystJK/reference/cvars/g_neutralflagtimer-8ada420/) | cvar | game | Controls `g_neutralFlagTimer` in the game module. |
| [`g_newBotAI`](/TaystJK/reference/cvars/g_newbotai-156e15f/) | cvar | game | Controls `g_newBotAI` in the game module. |
| [`g_newBotAITarget`](/TaystJK/reference/cvars/g_newbotaitarget-9625e4f/) | cvar | game | -2=Target closest excluding otherbots. -1=target closest. 0-31=target clientnum. |
| [`g_nonRandomKnockdown`](/TaystJK/reference/cvars/g_nonrandomknockdown-6cb5a5c/) | cvar | game | 1=Nonrandom knockdowns based on forcepoints. 2=Pseudorandom with less variance. 3=Nonrandom based on viewangle of target. 4=Random based on viewangle of target. |
| [`g_noSpecMove`](/TaystJK/reference/cvars/g_nospecmove-8633e1f/) | cvar | game | Controls `g_noSpecMove` in the game module. |
| [`g_npcspskill`](/TaystJK/reference/cvars/g_npcspskill-7746049/) | cvar | game | Controls `g_npcspskill` in the game module. |
| [`g_onlyBhop`](/TaystJK/reference/cvars/g_onlybhop-07d5d70/) | cvar | game | 1=Disable forcejumps for all players. 2=Let players choose if they want to disable forcejumps. |
| [`g_password`](/TaystJK/reference/cvars/g_password-db052ef/) | cvar | game | Controls `g_password` in the game module. |
| [`g_playerLog`](/TaystJK/reference/cvars/g_playerlog-3ba9184/) | cvar | game | Used by /amlookup |
| [`g_powerDuelEndHealth`](/TaystJK/reference/cvars/g_powerduelendhealth-6ed9bba/) | cvar | game | Controls `g_powerDuelEndHealth` in the game module. |
| [`g_powerDuelStartHealth`](/TaystJK/reference/cvars/g_powerduelstarthealth-47791bf/) | cvar | game | Controls `g_powerDuelStartHealth` in the game module. |
| [`g_privateDuel`](/TaystJK/reference/cvars/g_privateduel-d667c8f/) | cvar | game | Controls `g_privateDuel` in the game module. |
| [`g_projectileInheritance`](/TaystJK/reference/cvars/g_projectileinheritance-87e22cb/) | cvar | game | Scale of forward player momentum gained by projectiles. |
| [`g_projectileVelocityScale`](/TaystJK/reference/cvars/g_projectilevelocityscale-9182276/) | cvar | game | Controls `g_projectileVelocityScale` in the game module. |
| [`g_raceMode`](/TaystJK/reference/cvars/g_racemode-04a9af7/) | cvar | game | 0=Noracemode, 1=forcedracemode, 2=player can toggle race mode with /racecommand. |
| [`g_redDFADamageScale`](/TaystJK/reference/cvars/g_reddfadamagescale-1266724/) | cvar | game | Controls `g_redDFADamageScale` in the game module. |
| [`g_removeSpectatorPortals`](/TaystJK/reference/cvars/g_removespectatorportals-070ecec/) | cvar | game | Network all entity data to spectators, useful if you have a recorder in spectate so you can record all POV's. |
| [`g_restarted`](/TaystJK/reference/cvars/g_restarted-7cbf453/) | cvar | game | Controls `g_restarted` in the game module. |
| [`g_saberBladeFaces`](/TaystJK/reference/cvars/g_saberbladefaces-ee223ef/) | cvar | game | Controls `g_saberBladeFaces` in the game module. |
| [`g_saberDamageScale`](/TaystJK/reference/cvars/g_saberdamagescale-1902b96/) | cvar | game | Controls `g_saberDamageScale` in the game module. |
| [`g_saberDebugBox`](/TaystJK/reference/cvars/g_saberdebugbox-24991b0/) | cvar | game | Controls `g_saberDebugBox` in the game module. |
| [`g_saberDebugPrint`](/TaystJK/reference/cvars/g_saberdebugprint-7d18485/) | cvar | game | Controls `g_saberDebugPrint` in the game module. |
| [`g_saberDisable`](/TaystJK/reference/cvars/g_saberdisable-8b0544d/) | cvar | game | Configured with /saberDisable command. |
| [`g_saberDmgDelay_Hit`](/TaystJK/reference/cvars/g_saberdmgdelay_hit-504f5f4/) | cvar | game | Controls `g_saberDmgDelay_Hit` in the game module. |
| [`g_saberDmgDelay_Idle`](/TaystJK/reference/cvars/g_saberdmgdelay_idle-ff5bfc4/) | cvar | game | Controls `g_saberDmgDelay_Idle` in the game module. |
| [`g_saberDmgDelay_Wound`](/TaystJK/reference/cvars/g_saberdmgdelay_wound-e5965b8/) | cvar | game | Controls `g_saberDmgDelay_Wound` in the game module. |
| [`g_saberDmgVelocityScale`](/TaystJK/reference/cvars/g_saberdmgvelocityscale-c7bbdc8/) | cvar | game | Controls `g_saberDmgVelocityScale` in the game module. |
| [`g_saberLockFactor`](/TaystJK/reference/cvars/g_saberlockfactor-9043e22/) | cvar | game | Controls `g_saberLockFactor` in the game module. |
| [`g_saberLocking`](/TaystJK/reference/cvars/g_saberlocking-aa88986/) | cvar | game | Controls `g_saberLocking` in the game module. |
| [`g_saberLockRandomNess`](/TaystJK/reference/cvars/g_saberlockrandomness-428b3a7/) | cvar | game | Controls `g_saberLockRandomNess` in the game module. |
| [`g_saberRealisticCombat`](/TaystJK/reference/cvars/g_saberrealisticcombat-9fda4bf/) | cvar | game | Controls `g_saberRealisticCombat` in the game module. |
| [`g_saberRestrictForce`](/TaystJK/reference/cvars/g_saberrestrictforce-71cb7d9/) | cvar | game | Controls `g_saberRestrictForce` in the game module. |
| [`g_saberTraceSaberFirst`](/TaystJK/reference/cvars/g_sabertracesaberfirst-3e9e21c/) | cvar | game | Controls `g_saberTraceSaberFirst` in the game module. |
| [`g_saberWallDamageScale`](/TaystJK/reference/cvars/g_saberwalldamagescale-33dbc45/) | cvar | game | Controls `g_saberWallDamageScale` in the game module. |
| [`g_selfDamageScale`](/TaystJK/reference/cvars/g_selfdamagescale-3309fb9/) | cvar | game | Controls `g_selfDamageScale` in the game module. |
| [`g_showDuelHealths`](/TaystJK/reference/cvars/g_showduelhealths-479a1ba/) | cvar | game | Controls `g_showDuelHealths` in the game module. |
| [`g_showHealth`](/TaystJK/reference/cvars/g_showhealth-be5cfaa/) | cvar | game | Show healthbars above players heads when aimed at. Requires map restart. |
| [`g_showJumpSpot`](/TaystJK/reference/cvars/g_showjumpspot-316cca0/) | cvar | game | Marks where player touches ground as they land. Useful with the /nudge command on entities. |
| [`g_siegeRespawn`](/TaystJK/reference/cvars/g_siegerespawn-1ca75dd/) | cvar | game | Controls `g_siegeRespawn` in the game module. |
| [`g_siegeTeam1`](/TaystJK/reference/cvars/g_siegeteam1-4e2932b/) | cvar | game | Controls `g_siegeTeam1` in the game module. |
| [`g_siegeTeam2`](/TaystJK/reference/cvars/g_siegeteam2-60ec475/) | cvar | game | Controls `g_siegeTeam2` in the game module. |
| [`g_siegeTeamSwitch`](/TaystJK/reference/cvars/g_siegeteamswitch-ec4e992/) | cvar | game | Controls `g_siegeTeamSwitch` in the game module. |
| [`g_slideOnPlayer`](/TaystJK/reference/cvars/g_slideonplayer-57bcd53/) | cvar | game | Controls `g_slideOnPlayer` in the game module. |
| [`g_slowmoDuelEnd`](/TaystJK/reference/cvars/g_slowmoduelend-b7759cf/) | cvar | game | Controls `g_slowmoDuelEnd` in the game module. |
| [`g_smoothClients`](/TaystJK/reference/cvars/g_smoothclients-6772924/) | cvar | game | Controls `g_smoothClients` in the game module. |
| [`g_spawnInvulnerability`](/TaystJK/reference/cvars/g_spawninvulnerability-ba2c93a/) | cvar | game | Controls `g_spawnInvulnerability` in the game module. |
| [`g_speed`](/TaystJK/reference/cvars/g_speed-a067ac2/) | cvar | game | Controls `g_speed` in the game module. |
| [`g_splashDamageScale`](/TaystJK/reference/cvars/g_splashdamagescale-562c534/) | cvar | game | Controls `g_splashDamageScale` in the game module. |
| [`g_spSkill`](/TaystJK/reference/cvars/g_spskill-6446743/) | cvar | ui | Controls `g_spSkill` in the ui module. |
| [`g_startingItems`](/TaystJK/reference/cvars/g_startingitems-8ece828/) | cvar | game | Configured with /startingItems command. |
| [`g_startingWeapons`](/TaystJK/reference/cvars/g_startingweapons-ba463fc/) | cvar | game | Start with saber only default, fall back to melee if no saberattack |
| [`g_statLog`](/TaystJK/reference/cvars/g_statlog-879e05c/) | cvar | game | Controls `g_statLog` in the game module. |
| [`g_statLogFile`](/TaystJK/reference/cvars/g_statlogfile-37923cd/) | cvar | game | Controls `g_statLogFile` in the game module. |
| [`g_stepSlideFix`](/TaystJK/reference/cvars/g_stepslidefix-9d644c1/) | cvar | game | Controls `g_stepSlideFix` in the game module. |
| [`g_stopHealthESP`](/TaystJK/reference/cvars/g_stophealthesp-34d40e0/) | cvar | game | Don't send health info to other players (pain sounds can't be used to count health now). |
| [`g_synchronousClients`](/TaystJK/reference/cvars/g_synchronousclients-8895acf/) | cvar | game | Controls `g_synchronousClients` in the game module. |
| [`g_teamAbsorbScale`](/TaystJK/reference/cvars/g_teamabsorbscale-67e8eb0/) | cvar | game | Scale forcepoints gained from teampush/teampull etc. |
| [`g_teamAutoJoin`](/TaystJK/reference/cvars/g_teamautojoin-7c2230e/) | cvar | game | Controls `g_teamAutoJoin` in the game module. |
| [`g_teamForceBalance`](/TaystJK/reference/cvars/g_teamforcebalance-6ef2dbb/) | cvar | game | Controls `g_teamForceBalance` in the game module. |
| [`g_timeouttospec`](/TaystJK/reference/cvars/g_timeouttospec-3b41a9c/) | cvar | game | Controls `g_timeouttospec` in the game module. |
| [`g_tribesMode`](/TaystJK/reference/cvars/g_tribesmode-2e2993b/) | cvar | game | Controls `g_tribesMode` in the game module. |
| [`g_tweakForce`](/TaystJK/reference/cvars/g_tweakforce-d616b7a/) | cvar | game | Configured with /tweakForce command. |
| [`g_tweakJetpack`](/TaystJK/reference/cvars/g_tweakjetpack-7b1ba8a/) | cvar | game | Controls `g_tweakJetpack` in the game module. |
| [`g_tweakSaber`](/TaystJK/reference/cvars/g_tweaksaber-7ff08dd/) | cvar | game | Configured with /tweakSaber command. |
| [`g_tweakVote`](/TaystJK/reference/cvars/g_tweakvote-97a7f7d/) | cvar | game | Latch cuz of calculateRanks? not sure man |
| [`g_tweakWeapons`](/TaystJK/reference/cvars/g_tweakweapons-7f0cd05/) | cvar | game | Configured with /tweakWeapons command |
| [`g_unlagged`](/TaystJK/reference/cvars/g_unlagged-06233db/) | cvar | game | Bitvalue. 1=Unlagged projectiles. 2=Unlagged hitscan. 4=Unlagged push/pull. |
| [`g_unlaggedProjectileTolerance`](/TaystJK/reference/cvars/g_unlaggedprojectiletolerance-4f622f0/) | cvar | game | Controls `g_unlaggedProjectileTolerance` in the game module. |
| [`g_userinfoValidate`](/TaystJK/reference/cvars/g_userinfovalidate-8bbdc02/) | cvar | game | Controls `g_userinfoValidate` in the game module. |
| [`g_useWhileThrowing`](/TaystJK/reference/cvars/g_usewhilethrowing-3895f86/) | cvar | game | Controls `g_useWhileThrowing` in the game module. |
| [`g_validateCosmetics`](/TaystJK/reference/cvars/g_validatecosmetics-59cafad/) | cvar | game | Controls `g_validateCosmetics` in the game module. |
| [`g_voteDelay`](/TaystJK/reference/cvars/g_votedelay-8d2f6a6/) | cvar | game | Controls `g_voteDelay` in the game module. |
| [`g_voteTimeout`](/TaystJK/reference/cvars/g_votetimeout-c55dafd/) | cvar | game | Time in seconds to lockout callvote after a failed vote |
| [`g_warmup`](/TaystJK/reference/cvars/g_warmup-10d46fd/) | cvar | game | Controls `g_warmup` in the game module. |
| [`g_weaponDamageScale`](/TaystJK/reference/cvars/g_weapondamagescale-ba72334/) | cvar | game | Controls `g_weaponDamageScale` in the game module. |
| [`g_weaponDisable`](/TaystJK/reference/cvars/g_weapondisable-3dcdfe1/) | cvar | game | Controls `g_weaponDisable` in the game module. |
| [`g_weaponRespawn`](/TaystJK/reference/cvars/g_weaponrespawn-0999f17/) | cvar | game | Controls `g_weaponRespawn` in the game module. |
| [`gamedate`](/TaystJK/reference/cvars/gamedate-1b8201a/) | cvar | game | Controls `gamedate` in the game module. |
| [`gamename`](/TaystJK/reference/cvars/gamename-eab6420/) | cvar | game | Controls `gamename` in the game module. |
| [`graphheight`](/TaystJK/reference/cvars/graphheight-4f6183b/) | cvar | engine-client | Controls `cl_graphheight` in the engine-client module. |
| [`graphscale`](/TaystJK/reference/cvars/graphscale-bad841c/) | cvar | engine-client | Controls `cl_graphscale` in the engine-client module. |
| [`graphshift`](/TaystJK/reference/cvars/graphshift-5b8cd72/) | cvar | engine-client | Controls `cl_graphshift` in the engine-client module. |
| [`handicap`](/TaystJK/reference/cvars/handicap-541968c/) | cvar | engine-client | Player handicap |
| [`in_joystick`](/TaystJK/reference/cvars/in_joystick-922c9b6/) | cvar | engine-shared | Controls `in_joystick` in the engine-shared module. |
| [`in_joystickNo`](/TaystJK/reference/cvars/in_joystickno-d0cc911/) | cvar | engine-shared | Controls `in_joystickNo` in the engine-shared module. |
| [`in_joystickUseAnalog`](/TaystJK/reference/cvars/in_joystickuseanalog-501c877/) | cvar | engine-shared | Controls `in_joystickUseAnalog` in the engine-shared module. |
| [`in_keyboardDebug`](/TaystJK/reference/cvars/in_keyboarddebug-2793d91/) | cvar | engine-shared | Controls `in_keyboardDebug` in the engine-shared module. |
| [`in_mouse`](/TaystJK/reference/cvars/in_mouse-8c4b2e5/) | cvar | engine-shared | Controls `in_mouse` in the engine-shared module. |
| [`in_mouserepeat`](/TaystJK/reference/cvars/in_mouserepeat-b6e4e4a/) | cvar | engine-shared | Controls `in_mouserepeat` in the engine-shared module. |
| [`in_nograb`](/TaystJK/reference/cvars/in_nograb-35cb150/) | cvar | engine-shared | Controls `in_nograb` in the engine-shared module. |
| [`ja_guid`](/TaystJK/reference/cvars/ja_guid-ea397d3/) | cvar | engine-client | Client GUID |
| [`jcinfo`](/TaystJK/reference/cvars/jcinfo-d257d4c/) | cvar | game | Not a cvar, dont change it |
| [`jcinfo2`](/TaystJK/reference/cvars/jcinfo2-4d14263/) | cvar | game | Not a cvar, dont change it |
| [`journal`](/TaystJK/reference/cvars/journal-4954ccf/) | cvar | engine-shared | Controls `com_journal` in the engine-shared module. |
| [`joy_threshold`](/TaystJK/reference/cvars/joy_threshold-6a68c9b/) | cvar | engine-shared | Controls `in_joystickThreshold` in the engine-shared module. |
| [`logfile`](/TaystJK/reference/cvars/logfile-1a0ef65/) | cvar | engine-shared | Controls `com_logfile` in the engine-shared module. |
| [`m_filter`](/TaystJK/reference/cvars/m_filter-378f864/) | cvar | engine-client | Controls `m_filter` in the engine-client module. |
| [`m_forward`](/TaystJK/reference/cvars/m_forward-dde14cf/) | cvar | engine-client | Controls `m_forward` in the engine-client module. |
| [`m_pitch`](/TaystJK/reference/cvars/m_pitch-5a9b25b/) | cvar | engine-client | Controls `m_pitch` in the engine-client module. |
| [`m_pitchVeh`](/TaystJK/reference/cvars/m_pitchveh-c5a5b83/) | cvar | engine-client | Controls `m_pitchVeh` in the engine-client module. |
| [`m_side`](/TaystJK/reference/cvars/m_side-503d870/) | cvar | engine-client | Controls `m_side` in the engine-client module. |
| [`m_yaw`](/TaystJK/reference/cvars/m_yaw-6897351/) | cvar | engine-client | Controls `m_yaw` in the engine-client module. |
| [`mapname`](/TaystJK/reference/cvars/mapname-78d7d3e/) | cvar | game | Controls `mapname` in the game module. |
| [`model`](/TaystJK/reference/cvars/model-1d06a0d/) | cvar | cgame | Player model |
| [`name`](/TaystJK/reference/cvars/name-6ae9995/) | cvar | engine-client | Player name |
| [`net_enabled`](/TaystJK/reference/cvars/net_enabled-800ae62/) | cvar | engine-shared | Controls `net_enabled` in the engine-shared module. |
| [`net_forcenonlocal`](/TaystJK/reference/cvars/net_forcenonlocal-8af0d5b/) | cvar | engine-shared | Controls `net_forcenonlocal` in the engine-shared module. |
| [`net_ip`](/TaystJK/reference/cvars/net_ip-e167d28/) | cvar | engine-shared | Controls `net_ip` in the engine-shared module. |
| [`net_port`](/TaystJK/reference/cvars/net_port-a39e827/) | cvar | engine-shared | Controls `net_port` in the engine-shared module. |
| [`net_qport`](/TaystJK/reference/cvars/net_qport-47e2de0/) | cvar | engine-shared | Controls `qport` in the engine-shared module. |
| [`net_socksEnabled`](/TaystJK/reference/cvars/net_socksenabled-f39d306/) | cvar | engine-shared | Controls `net_socksEnabled` in the engine-shared module. |
| [`net_socksPassword`](/TaystJK/reference/cvars/net_sockspassword-3231521/) | cvar | engine-shared | Controls `net_socksPassword` in the engine-shared module. |
| [`net_socksPort`](/TaystJK/reference/cvars/net_socksport-4b3f54f/) | cvar | engine-shared | Controls `net_socksPort` in the engine-shared module. |
| [`net_socksServer`](/TaystJK/reference/cvars/net_socksserver-8f0c6a4/) | cvar | engine-shared | Controls `net_socksServer` in the engine-shared module. |
| [`net_socksUsername`](/TaystJK/reference/cvars/net_socksusername-e7b675d/) | cvar | engine-shared | Controls `net_socksUsername` in the engine-shared module. |
| [`nextmap`](/TaystJK/reference/cvars/nextmap-fc2a1f6/) | cvar | engine-server | Controls `nextmap` in the engine-server module. |
| [`password`](/TaystJK/reference/cvars/password-5baa61e/) | cvar | engine-client | Password to join server |
| [`pmove_fixed`](/TaystJK/reference/cvars/pmove_fixed-614b895/) | cvar | cgame | Controls `pmove_fixed` in the cgame module. |
| [`pmove_float`](/TaystJK/reference/cvars/pmove_float-d352a0d/) | cvar | cgame | Controls `pmove_float` in the cgame module. |
| [`pmove_msec`](/TaystJK/reference/cvars/pmove_msec-2b6eec8/) | cvar | cgame | Controls `pmove_msec` in the cgame module. |
| [`protocol`](/TaystJK/reference/cvars/protocol-6e9b4af/) | cvar | engine-server | Controls `protocol` in the engine-server module. |
| [`protocolswitch`](/TaystJK/reference/cvars/protocolswitch-9a313ea/) | cvar | engine-client | Sets protocol based on server info response |
| [`r_allowExtensions`](/TaystJK/reference/cvars/r_allowextensions-57dba23/) | cvar | renderer | Allow GL extensions |
| [`r_allowSoftwareGL`](/TaystJK/reference/cvars/r_allowsoftwaregl-fab7aac/) | cvar | engine-shared | Controls `r_allowSoftwareGL` in the engine-shared module. |
| [`r_ambientScale`](/TaystJK/reference/cvars/r_ambientscale-2aa83ee/) | cvar | renderer | Controls `r_ambientScale` in the renderer module. |
| [`r_aspectCorrectFonts`](/TaystJK/reference/cvars/r_aspectcorrectfonts-be7251d/) | cvar | renderer | Controls `r_aspectCorrectFonts` in the renderer module. |
| [`r_autolodscalevalue`](/TaystJK/reference/cvars/r_autolodscalevalue-ea276af/) | cvar | renderer | Controls `r_autolodscalevalue` in the renderer module. |
| [`r_autoMap`](/TaystJK/reference/cvars/r_automap-3176cbc/) | cvar | renderer | Controls `r_autoMap` in the renderer module. |
| [`r_autoMapBackAlpha`](/TaystJK/reference/cvars/r_automapbackalpha-9645661/) | cvar | renderer | Controls `r_autoMapBackAlpha` in the renderer module. |
| [`r_autoMapDisable`](/TaystJK/reference/cvars/r_automapdisable-ad56d1c/) | cvar | renderer | Controls `r_autoMapDisable` in the renderer module. |
| [`r_autoMapH`](/TaystJK/reference/cvars/r_automaph-90ace7f/) | cvar | cgame | Controls `r_autoMapH` in the cgame module. |
| [`r_autoMapW`](/TaystJK/reference/cvars/r_automapw-b5b1ae5/) | cvar | cgame | Controls `r_autoMapW` in the cgame module. |
| [`r_autoMapX`](/TaystJK/reference/cvars/r_automapx-874954b/) | cvar | cgame | Controls `r_autoMapX` in the cgame module. |
| [`r_autoMapY`](/TaystJK/reference/cvars/r_automapy-0791303/) | cvar | cgame | Controls `r_autoMapY` in the cgame module. |
| [`r_availableModes`](/TaystJK/reference/cvars/r_availablemodes-bd904ae/) | cvar | engine-shared | Controls `r_availableModes` in the engine-shared module. |
| [`r_aviMotionJpegQuality`](/TaystJK/reference/cvars/r_avimotionjpegquality-108e51f/) | cvar | renderer | Controls `r_aviMotionJpegQuality` in the renderer module. |
| [`r_baseSpecular`](/TaystJK/reference/cvars/r_basespecular-24a3c96/) | cvar | renderer | Controls `r_baseSpecular` in the renderer module. |
| [`r_bloom`](/TaystJK/reference/cvars/r_bloom-656b99d/) | cvar | renderer | Enable bloom effect Requires \\r_fbo 1 |
| [`r_bloom_intensity`](/TaystJK/reference/cvars/r_bloom_intensity-78b7afa/) | cvar | renderer | Final bloom blend factor, default is 0.15 |
| [`r_bloom_threshold`](/TaystJK/reference/cvars/r_bloom_threshold-76fa432/) | cvar | renderer | Color level to extract to bloom texture, default is 0.05 |
| [`r_centerWindow`](/TaystJK/reference/cvars/r_centerwindow-5f0b845/) | cvar | renderer | Controls `r_centerWindow` in the renderer module. |
| [`r_clear`](/TaystJK/reference/cvars/r_clear-b558454/) | cvar | renderer | Controls `r_clear` in the renderer module. |
| [`r_colorbits`](/TaystJK/reference/cvars/r_colorbits-4da06ec/) | cvar | renderer | Controls `r_colorbits` in the renderer module. |
| [`r_colorMipLevels`](/TaystJK/reference/cvars/r_colormiplevels-3b94fc7/) | cvar | renderer | Controls `r_colorMipLevels` in the renderer module. |
| [`r_cullRoofFaces`](/TaystJK/reference/cvars/r_cullrooffaces-6bb0064/) | cvar | renderer | Controls `r_cullRoofFaces` in the renderer module. |
| [`r_customheight`](/TaystJK/reference/cvars/r_customheight-380d198/) | cvar | renderer | Controls `r_customheight` in the renderer module. |
| [`r_customwidth`](/TaystJK/reference/cvars/r_customwidth-40fe778/) | cvar | renderer | Controls `r_customwidth` in the renderer module. |
| [`r_debuglight`](/TaystJK/reference/cvars/r_debuglight-b8d0433/) | cvar | renderer | Controls `r_debuglight` in the renderer module. |
| [`r_debugSort`](/TaystJK/reference/cvars/r_debugsort-3e4fd35/) | cvar | renderer | Controls `r_debugSort` in the renderer module. |
| [`r_debugSurface`](/TaystJK/reference/cvars/r_debugsurface-abe21fc/) | cvar | renderer | Controls `cv2` in the renderer module. |
| [`r_debugSurfaceUpdate`](/TaystJK/reference/cvars/r_debugsurfaceupdate-3194b25/) | cvar | engine-shared | Controls `cv` in the engine-shared module. |
| [`r_depthbits`](/TaystJK/reference/cvars/r_depthbits-16d7986/) | cvar | renderer | Controls `r_depthbits` in the renderer module. |
| [`r_detailtextures`](/TaystJK/reference/cvars/r_detailtextures-a15c8ff/) | cvar | renderer | Controls `r_detailtextures` in the renderer module. |
| [`r_device`](/TaystJK/reference/cvars/r_device-8238fc4/) | cvar | renderer | Select physical device to render: 0+ - use explicit device index -1 - first discrete GPU -2 - first integrated GPU |
| [`r_directedScale`](/TaystJK/reference/cvars/r_directedscale-6aee8ad/) | cvar | renderer | Controls `r_directedScale` in the renderer module. |
| [`r_displayRefresh`](/TaystJK/reference/cvars/r_displayrefresh-59d8e1d/) | cvar | renderer | Controls `r_displayRefresh` in the renderer module. |
| [`r_distanceCull`](/TaystJK/reference/cvars/r_distancecull-9ac0a11/) | cvar | renderer | Controls `r_distanceCull` in the renderer module. |
| [`r_dlightBacks`](/TaystJK/reference/cvars/r_dlightbacks-6e40190/) | cvar | renderer | Dlight non-facing surfaces for continuity |
| [`r_dlightMode`](/TaystJK/reference/cvars/r_dlightmode-f87fa68/) | cvar | renderer | Controls `r_dlightMode` in the renderer module. |
| [`r_dlightStyle`](/TaystJK/reference/cvars/r_dlightstyle-fcbcb83/) | cvar | renderer | Controls `r_dlightStyle` in the renderer module. |
| [`r_drawBuffer`](/TaystJK/reference/cvars/r_drawbuffer-a1f545a/) | cvar | renderer | Controls `r_drawBuffer` in the renderer module. |
| [`r_drawentities`](/TaystJK/reference/cvars/r_drawentities-ea638d1/) | cvar | renderer | Controls `r_drawentities` in the renderer module. |
| [`r_drawfog`](/TaystJK/reference/cvars/r_drawfog-89ae687/) | cvar | renderer | Select disabled, software, or hardware fog rendering. |
| [`r_drawSun`](/TaystJK/reference/cvars/r_drawsun-4ed1bcb/) | cvar | renderer | Controls `r_drawSun` in the renderer module. |
| [`r_drawTerrain`](/TaystJK/reference/cvars/r_drawterrain-7e74ebd/) | cvar | renderer | Controls `r_drawTerrain` in the renderer module. |
| [`r_drawworld`](/TaystJK/reference/cvars/r_drawworld-f118f2d/) | cvar | renderer | Controls `r_drawworld` in the renderer module. |
| [`r_DynamicGlow`](/TaystJK/reference/cvars/r_dynamicglow-e23bada/) | cvar | renderer | Enable dynamic glow effect Requires \\r_fbo 1 |
| [`r_DynamicGlowDelta`](/TaystJK/reference/cvars/r_dynamicglowdelta-0aacfd7/) | cvar | renderer | Controls `r_DynamicGlowDelta` in the renderer module. |
| [`r_DynamicGlowHeight`](/TaystJK/reference/cvars/r_dynamicglowheight-ff563ef/) | cvar | renderer | Controls `r_DynamicGlowHeight` in the renderer module. |
| [`r_DynamicGlowIntensity`](/TaystJK/reference/cvars/r_dynamicglowintensity-aa3cade/) | cvar | renderer | Controls `r_DynamicGlowIntensity` in the renderer module. |
| [`r_DynamicGlowPasses`](/TaystJK/reference/cvars/r_dynamicglowpasses-a2699dc/) | cvar | renderer | Controls `r_DynamicGlowPasses` in the renderer module. |
| [`r_DynamicGlowScale`](/TaystJK/reference/cvars/r_dynamicglowscale-62e93d2/) | cvar | renderer | Controls `r_DynamicGlowScale` in the renderer module. |
| [`r_DynamicGlowSoft`](/TaystJK/reference/cvars/r_dynamicglowsoft-b5f5c97/) | cvar | renderer | Controls `r_DynamicGlowSoft` in the renderer module. |
| [`r_DynamicGlowWidth`](/TaystJK/reference/cvars/r_dynamicglowwidth-7d73e61/) | cvar | renderer | Controls `r_DynamicGlowWidth` in the renderer module. |
| [`r_dynamiclight`](/TaystJK/reference/cvars/r_dynamiclight-917a4f5/) | cvar | renderer | Controls `r_dynamiclight` in the renderer module. |
| [`r_environmentMapping`](/TaystJK/reference/cvars/r_environmentmapping-4bbfdcf/) | cvar | renderer | Controls `r_environmentMapping` in the renderer module. |
| [`r_ext_compiled_vertex_array`](/TaystJK/reference/cvars/r_ext_compiled_vertex_array-d6b2813/) | cvar | renderer | Unused |
| [`r_ext_compress_lightmaps`](/TaystJK/reference/cvars/r_ext_compress_lightmaps-1ddfa36/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ext_compress_textures`](/TaystJK/reference/cvars/r_ext_compress_textures-f9b3b78/) | cvar | renderer | Disable/enable texture compression |
| [`r_ext_gamma_control`](/TaystJK/reference/cvars/r_ext_gamma_control-8e482d7/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ext_multisample`](/TaystJK/reference/cvars/r_ext_multisample-9b2ea2a/) | cvar | renderer | Disable/enable framebuffer MSAA |
| [`r_ext_multitexture`](/TaystJK/reference/cvars/r_ext_multitexture-7dae98e/) | cvar | renderer | Unused |
| [`r_ext_preferred_tc_method`](/TaystJK/reference/cvars/r_ext_preferred_tc_method-cbfcdd9/) | cvar | renderer | Preferred texture compression method |
| [`r_ext_texture_env_add`](/TaystJK/reference/cvars/r_ext_texture_env_add-40420dc/) | cvar | renderer | Unused |
| [`r_ext_texture_filter_anisotropic`](/TaystJK/reference/cvars/r_ext_texture_filter_anisotropic-19cfe9c/) | cvar | renderer | Disable/enable anisotropic texture filtering |
| [`r_facePlaneCull`](/TaystJK/reference/cvars/r_faceplanecull-527e83b/) | cvar | renderer | Controls `r_facePlaneCull` in the renderer module. |
| [`r_fastsky`](/TaystJK/reference/cvars/r_fastsky-24089fb/) | cvar | renderer | Controls `r_fastsky` in the renderer module. |
| [`r_finish`](/TaystJK/reference/cvars/r_finish-9b66ed8/) | cvar | renderer | Controls `r_finish` in the renderer module. |
| [`r_flares`](/TaystJK/reference/cvars/r_flares-675003d/) | cvar | renderer | Controls `r_flares` in the renderer module. |
| [`r_fontSharpness`](/TaystJK/reference/cvars/r_fontsharpness-50394a7/) | cvar | renderer | Relative font sharpness (doesn't affect console font). |
| [`r_forceAutoExposureMax`](/TaystJK/reference/cvars/r_forceautoexposuremax-8cdd87f/) | cvar | renderer | Controls `r_forceAutoExposureMax` in the renderer module. |
| [`r_forceAutoExposureMin`](/TaystJK/reference/cvars/r_forceautoexposuremin-662d327/) | cvar | renderer | Controls `r_forceAutoExposureMin` in the renderer module. |
| [`r_forceToneMapAvg`](/TaystJK/reference/cvars/r_forcetonemapavg-df906d3/) | cvar | renderer | Controls `r_forceToneMapAvg` in the renderer module. |
| [`r_fullbright`](/TaystJK/reference/cvars/r_fullbright-4d2b005/) | cvar | renderer | Controls `r_fullbright` in the renderer module. |
| [`r_fullscreen`](/TaystJK/reference/cvars/r_fullscreen-3ecab87/) | cvar | renderer | Controls `r_fullscreen` in the renderer module. |
| [`r_gamma`](/TaystJK/reference/cvars/r_gamma-9954e45/) | cvar | renderer | Controls `r_gamma` in the renderer module. |
| [`r_gammaShaders`](/TaystJK/reference/cvars/r_gammashaders-f8fed87/) | cvar | renderer | Set gamma using pixel shaders inside the game window only. |
| [`r_ghoul2animsmooth`](/TaystJK/reference/cvars/r_ghoul2animsmooth-475e6c7/) | cvar | renderer | Controls `r_ghoul2animsmooth` in the renderer module. |
| [`r_ghoul2unsqashaftersmooth`](/TaystJK/reference/cvars/r_ghoul2unsqashaftersmooth-8ec055c/) | cvar | renderer | Controls `r_ghoul2unsqashaftersmooth` in the renderer module. |
| [`r_greyscale`](/TaystJK/reference/cvars/r_greyscale-442b35b/) | cvar | renderer | Controls `r_greyscale` in the renderer module. |
| [`r_hdr`](/TaystJK/reference/cvars/r_hdr-806f3ee/) | cvar | renderer | Disable/enable rendering in HDR |
| [`r_ignore`](/TaystJK/reference/cvars/r_ignore-737663a/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_ignoreGLErrors`](/TaystJK/reference/cvars/r_ignoreglerrors-af91e54/) | cvar | renderer | Controls `r_ignoreGLErrors` in the renderer module. |
| [`r_ignorehwgamma`](/TaystJK/reference/cvars/r_ignorehwgamma-1ebcc68/) | cvar | renderer | Overrides hardware gamma capabilities |
| [`r_inGameVideo`](/TaystJK/reference/cvars/r_ingamevideo-af33e5e/) | cvar | renderer | Controls `cl_inGameVideo` in the renderer module. |
| [`r_intensity`](/TaystJK/reference/cvars/r_intensity-b48f8d7/) | cvar | renderer | Controls `r_intensity` in the renderer module. |
| [`r_lightmap`](/TaystJK/reference/cvars/r_lightmap-0095642/) | cvar | renderer | Controls `r_lightmap` in the renderer module. |
| [`r_lockpvs`](/TaystJK/reference/cvars/r_lockpvs-e7f9355/) | cvar | renderer | Controls `r_lockpvs` in the renderer module. |
| [`r_lodbias`](/TaystJK/reference/cvars/r_lodbias-dccee8d/) | cvar | renderer | Controls `r_lodbias` in the renderer module. |
| [`r_lodCurveError`](/TaystJK/reference/cvars/r_lodcurveerror-a26d1cc/) | cvar | renderer | Controls `r_lodCurveError` in the renderer module. |
| [`r_lodscale`](/TaystJK/reference/cvars/r_lodscale-8715415/) | cvar | renderer | Controls `r_lodscale` in the renderer module. |
| [`r_logFile`](/TaystJK/reference/cvars/r_logfile-6b6703b/) | cvar | renderer | Controls `r_logFile` in the renderer module. |
| [`r_mapOverBrightBits`](/TaystJK/reference/cvars/r_mapoverbrightbits-f8fd76d/) | cvar | renderer | Controls `r_mapOverBrightBits` in the renderer module. |
| [`r_markcount`](/TaystJK/reference/cvars/r_markcount-98ade6f/) | cvar | renderer | Controls `r_markcount` in the renderer module. |
| [`r_marksOnTriangleMeshes`](/TaystJK/reference/cvars/r_marksontrianglemeshes-3c9d053/) | cvar | renderer | Controls `r_marksOnTriangleMeshes` in the renderer module. |
| [`r_maxpolys`](/TaystJK/reference/cvars/r_maxpolys-653618a/) | cvar | renderer | Controls `r_maxpolys` in the renderer module. |
| [`r_maxpolyverts`](/TaystJK/reference/cvars/r_maxpolyverts-976a4f2/) | cvar | renderer | Controls `r_maxpolyverts` in the renderer module. |
| [`r_measureOverdraw`](/TaystJK/reference/cvars/r_measureoverdraw-0cef375/) | cvar | renderer | Controls `r_measureOverdraw` in the renderer module. |
| [`r_mode`](/TaystJK/reference/cvars/r_mode-ab69328/) | cvar | renderer | Controls `r_mode` in the renderer module. |
| [`r_modelpoolmegs`](/TaystJK/reference/cvars/r_modelpoolmegs-72aef0d/) | cvar | renderer | Controls `r_modelpoolmegs` in the renderer module. |
| [`r_nobind`](/TaystJK/reference/cvars/r_nobind-468736a/) | cvar | renderer | Controls `r_nobind` in the renderer module. |
| [`r_noborder`](/TaystJK/reference/cvars/r_noborder-09eac22/) | cvar | renderer | Controls `r_noborder` in the renderer module. |
| [`r_nocull`](/TaystJK/reference/cvars/r_nocull-45c5f6a/) | cvar | renderer | Controls `r_nocull` in the renderer module. |
| [`r_nocurves`](/TaystJK/reference/cvars/r_nocurves-cdabcba/) | cvar | renderer | Controls `r_nocurves` in the renderer module. |
| [`r_noghoul2`](/TaystJK/reference/cvars/r_noghoul2-182f730/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_noportals`](/TaystJK/reference/cvars/r_noportals-b716e20/) | cvar | renderer | Controls `r_noportals` in the renderer module. |
| [`r_noPrecacheGLA`](/TaystJK/reference/cvars/r_noprecachegla-754f482/) | cvar | renderer | Controls `r_noPrecacheGLA` in the renderer module. |
| [`r_norefresh`](/TaystJK/reference/cvars/r_norefresh-8502c24/) | cvar | renderer | Controls `r_norefresh` in the renderer module. |
| [`r_noserverghoul2`](/TaystJK/reference/cvars/r_noserverghoul2-13e2e0d/) | cvar | renderer | Controls `r_noserverghoul2` in the renderer module. |
| [`r_novis`](/TaystJK/reference/cvars/r_novis-2bb6ab2/) | cvar | renderer | Controls `r_novis` in the renderer module. |
| [`r_offsetfactor`](/TaystJK/reference/cvars/r_offsetfactor-349c509/) | cvar | renderer | Controls `r_offsetfactor` in the renderer module. |
| [`r_offsetunits`](/TaystJK/reference/cvars/r_offsetunits-e36e68f/) | cvar | renderer | Controls `r_offsetunits` in the renderer module. |
| [`r_overBrightBits`](/TaystJK/reference/cvars/r_overbrightbits-acf2388/) | cvar | renderer | Controls `r_overBrightBits` in the renderer module. |
| [`r_parallaxMapping`](/TaystJK/reference/cvars/r_parallaxmapping-2354566/) | cvar | renderer | Disable/enable parallax mapping |
| [`r_patchStitching`](/TaystJK/reference/cvars/r_patchstitching-1b7ebad/) | cvar | renderer | Enable stitching of neighbouring patch surfaces |
| [`r_picmip`](/TaystJK/reference/cvars/r_picmip-94fef1f/) | cvar | renderer | Controls `r_picmip` in the renderer module. |
| [`r_portalOnly`](/TaystJK/reference/cvars/r_portalonly-119fda0/) | cvar | renderer | Controls `r_portalOnly` in the renderer module. |
| [`r_primitives`](/TaystJK/reference/cvars/r_primitives-ee344cc/) | cvar | renderer | Controls `r_primitives` in the renderer module. |
| [`r_printShaders`](/TaystJK/reference/cvars/r_printshaders-de38905/) | cvar | renderer | Controls `r_printShaders` in the renderer module. |
| [`r_roofCeilFloorDist`](/TaystJK/reference/cvars/r_roofceilfloordist-8324544/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_roofCullCeilDist`](/TaystJK/reference/cvars/r_roofcullceildist-923eb04/) | cvar | renderer | Controls `r_roofCullCeilDist` in the renderer module. |
| [`r_roundImagesDown`](/TaystJK/reference/cvars/r_roundimagesdown-b41f9fd/) | cvar | renderer | Controls `r_roundImagesDown` in the renderer module. |
| [`r_screenshotJpegQuality`](/TaystJK/reference/cvars/r_screenshotjpegquality-b8e56fb/) | cvar | renderer | Controls `r_screenshotJpegQuality` in the renderer module. |
| [`r_sdlDriver`](/TaystJK/reference/cvars/r_sdldriver-c79955e/) | cvar | engine-shared | Controls `r_sdlDriver` in the engine-shared module. |
| [`r_shadowRange`](/TaystJK/reference/cvars/r_shadowrange-944ff5a/) | cvar | renderer | Controls `r_shadowRange` in the renderer module. |
| [`r_showcluster`](/TaystJK/reference/cvars/r_showcluster-3f0fbb6/) | cvar | renderer | Controls `r_showcluster` in the renderer module. |
| [`r_showFrameVariance`](/TaystJK/reference/cvars/r_showframevariance-a2a515e/) | cvar | renderer | Registered by the current source, but no user-facing behavior description has been verified. |
| [`r_showImages`](/TaystJK/reference/cvars/r_showimages-9a4938c/) | cvar | renderer | Controls `r_showImages` in the renderer module. |
| [`r_shownormals`](/TaystJK/reference/cvars/r_shownormals-452ef91/) | cvar | renderer | Controls `r_shownormals` in the renderer module. |
| [`r_showsky`](/TaystJK/reference/cvars/r_showsky-fbfd196/) | cvar | renderer | Controls `r_showsky` in the renderer module. |
| [`r_showtris`](/TaystJK/reference/cvars/r_showtris-29c5271/) | cvar | renderer | Controls `r_showtris` in the renderer module. |
| [`r_simpleMipMaps`](/TaystJK/reference/cvars/r_simplemipmaps-24e88c1/) | cvar | renderer | Controls `r_simpleMipMaps` in the renderer module. |
| [`r_singleShader`](/TaystJK/reference/cvars/r_singleshader-e4e6862/) | cvar | renderer | Controls `r_singleShader` in the renderer module. |
| [`r_skipBackEnd`](/TaystJK/reference/cvars/r_skipbackend-0e7b613/) | cvar | renderer | Controls `r_skipBackEnd` in the renderer module. |
| [`r_smartpicmip`](/TaystJK/reference/cvars/r_smartpicmip-88bba35/) | cvar | renderer | Applies r_picmip setting to map textures only. |
| [`r_speeds`](/TaystJK/reference/cvars/r_speeds-707e8db/) | cvar | renderer | Controls `r_speeds` in the renderer module. |
| [`r_stencilbits`](/TaystJK/reference/cvars/r_stencilbits-f1960ea/) | cvar | renderer | Controls `r_stencilbits` in the renderer module. |
| [`r_stereo`](/TaystJK/reference/cvars/r_stereo-899040b/) | cvar | renderer | Controls `r_stereo` in the renderer module. |
| [`r_subdivisions`](/TaystJK/reference/cvars/r_subdivisions-217daa3/) | cvar | renderer | Controls `r_subdivisions` in the renderer module. |
| [`r_surfaceSprites`](/TaystJK/reference/cvars/r_surfacesprites-19c6bde/) | cvar | renderer | Controls `r_surfaceSprites` in the renderer module. |
| [`r_surfaceWeather`](/TaystJK/reference/cvars/r_surfaceweather-42e08bb/) | cvar | renderer | Controls `r_surfaceWeather` in the renderer module. |
| [`r_swapInterval`](/TaystJK/reference/cvars/r_swapinterval-f4d114e/) | cvar | renderer | Controls `r_swapInterval` in the renderer module. |
| [`r_terrainTessellate`](/TaystJK/reference/cvars/r_terraintessellate-8b9ec30/) | cvar | renderer | Controls `r_terrainTessellate` in the renderer module. |
| [`r_terrainWaterOffset`](/TaystJK/reference/cvars/r_terrainwateroffset-0b046ea/) | cvar | renderer | Controls `r_terrainWaterOffset` in the renderer module. |
| [`r_texturebits`](/TaystJK/reference/cvars/r_texturebits-10d2b90/) | cvar | renderer | Controls `r_texturebits` in the renderer module. |
| [`r_texturebitslm`](/TaystJK/reference/cvars/r_texturebitslm-a3e9dd1/) | cvar | renderer | Controls `r_texturebitslm` in the renderer module. |
| [`r_textureMode`](/TaystJK/reference/cvars/r_texturemode-e53a999/) | cvar | renderer | Controls `r_textureMode` in the renderer module. |
| [`r_uifullscreen`](/TaystJK/reference/cvars/r_uifullscreen-9c735db/) | cvar | renderer | Controls `r_uifullscreen` in the renderer module. |
| [`r_vbo`](/TaystJK/reference/cvars/r_vbo-8ee14c4/) | cvar | renderer | Cache static world surfaces |
| [`r_vbo_models`](/TaystJK/reference/cvars/r_vbo_models-8579ecd/) | cvar | renderer | Cache ghoul2 and md3 model surfaces |
| [`r_verbose`](/TaystJK/reference/cvars/r_verbose-d91726d/) | cvar | renderer | Controls `r_verbose` in the renderer module. |
| [`r_vertexLight`](/TaystJK/reference/cvars/r_vertexlight-7001f2e/) | cvar | renderer | Controls `r_vertexLight` in the renderer module. |
| [`r_windAngle`](/TaystJK/reference/cvars/r_windangle-352ebf2/) | cvar | renderer | Controls `r_windAngle` in the renderer module. |
| [`r_windDampFactor`](/TaystJK/reference/cvars/r_winddampfactor-41a51c0/) | cvar | renderer | Controls `r_windDampFactor` in the renderer module. |
| [`r_windGust`](/TaystJK/reference/cvars/r_windgust-564e371/) | cvar | renderer | Controls `r_windGust` in the renderer module. |
| [`r_windPointForce`](/TaystJK/reference/cvars/r_windpointforce-a52b5e0/) | cvar | renderer | Controls `r_windPointForce` in the renderer module. |
| [`r_windPointX`](/TaystJK/reference/cvars/r_windpointx-7d8981c/) | cvar | renderer | Controls `r_windPointX` in the renderer module. |
| [`r_windPointY`](/TaystJK/reference/cvars/r_windpointy-b387ced/) | cvar | renderer | Controls `r_windPointY` in the renderer module. |
| [`r_windSpeed`](/TaystJK/reference/cvars/r_windspeed-85cb1e1/) | cvar | renderer | Controls `r_windSpeed` in the renderer module. |
| [`r_znear`](/TaystJK/reference/cvars/r_znear-eeed2b7/) | cvar | renderer | Controls `r_znear` in the renderer module. |
| [`r_zproj`](/TaystJK/reference/cvars/r_zproj-3cfee13/) | cvar | renderer | Controls `r_zproj` in the renderer module. |
| [`rate`](/TaystJK/reference/cvars/rate-1e01d21/) | cvar | engine-client | Data rate |
| [`rconAddress`](/TaystJK/reference/cvars/rconaddress-8180670/) | cvar | engine-client | Alternate server address to remotely access via rcon protocol |
| [`rconPassword`](/TaystJK/reference/cvars/rconpassword-39e4dc3/) | cvar | engine-client | Password for remote console access |
| [`restricts`](/TaystJK/reference/cvars/restricts-3fcd8e8/) | cvar | game | Controls `restricts` in the game module. |
| [`RMG`](/TaystJK/reference/cvars/rmg-7504210/) | cvar | game | Controls `RMG` in the game module. |
| [`s_allowDynamicMusic`](/TaystJK/reference/cvars/s_allowdynamicmusic-a2b0b0a/) | cvar | engine-client | Controls `s_allowDynamicMusic` in the engine-client module. |
| [`s_debugdynamic`](/TaystJK/reference/cvars/s_debugdynamic-6580034/) | cvar | engine-client | Controls `s_debugdynamic` in the engine-client module. |
| [`s_doppler`](/TaystJK/reference/cvars/s_doppler-affddec/) | cvar | engine-client | Controls `s_doppler` in the engine-client module. |
| [`s_initsound`](/TaystJK/reference/cvars/s_initsound-b12dffe/) | cvar | engine-client | Controls `cv` in the engine-client module. |
| [`s_khz`](/TaystJK/reference/cvars/s_khz-72a60cb/) | cvar | engine-client | Controls `s_khz` in the engine-client module. |
| [`s_language`](/TaystJK/reference/cvars/s_language-52bf4ed/) | cvar | engine-client | Sound language |
| [`s_mixahead`](/TaystJK/reference/cvars/s_mixahead-7da5a46/) | cvar | engine-client | Controls `s_mixahead` in the engine-client module. |
| [`s_mixPreStep`](/TaystJK/reference/cvars/s_mixprestep-e32c565/) | cvar | engine-client | Controls `s_mixPreStep` in the engine-client module. |
| [`s_mp3overhead`](/TaystJK/reference/cvars/s_mp3overhead-3e470ef/) | cvar | engine-client | Controls `cv_MP3overhead` in the engine-client module. |
| [`s_musicMult`](/TaystJK/reference/cvars/s_musicmult-418de4f/) | cvar | cgame | Registered by the current source, but no user-facing behavior description has been verified. |
| [`s_musicvolume`](/TaystJK/reference/cvars/s_musicvolume-61998a2/) | cvar | engine-client | Music volume |
| [`s_sdlBits`](/TaystJK/reference/cvars/s_sdlbits-5a722c9/) | cvar | engine-shared | Controls `s_sdlBits` in the engine-shared module. |
| [`s_sdlChannels`](/TaystJK/reference/cvars/s_sdlchannels-db8bbb9/) | cvar | engine-shared | Controls `s_sdlChannels` in the engine-shared module. |
| [`s_sdlDevSamps`](/TaystJK/reference/cvars/s_sdldevsamps-433b99c/) | cvar | engine-shared | Controls `s_sdlDevSamps` in the engine-shared module. |
| [`s_sdlMixSamps`](/TaystJK/reference/cvars/s_sdlmixsamps-d909425/) | cvar | engine-shared | Controls `s_sdlMixSamps` in the engine-shared module. |
| [`s_separation`](/TaystJK/reference/cvars/s_separation-ce56ff6/) | cvar | engine-client | Controls `s_separation` in the engine-client module. |
| [`s_show`](/TaystJK/reference/cvars/s_show-42944ff/) | cvar | engine-client | Controls `s_show` in the engine-client module. |
| [`s_soundpoolmegs`](/TaystJK/reference/cvars/s_soundpoolmegs-7f0c33e/) | cvar | engine-client | Controls `s_soundpoolmegs` in the engine-client module. |
| [`s_testsound`](/TaystJK/reference/cvars/s_testsound-a5efbf3/) | cvar | engine-client | Controls `s_testsound` in the engine-client module. |
| [`s_threshold1`](/TaystJK/reference/cvars/s_threshold1-e537283/) | cvar | engine-client | Controls `s_lip_threshold_1` in the engine-client module. |
| [`s_threshold2`](/TaystJK/reference/cvars/s_threshold2-c620de4/) | cvar | engine-client | Controls `s_lip_threshold_2` in the engine-client module. |
| [`s_threshold3`](/TaystJK/reference/cvars/s_threshold3-42c9ced/) | cvar | engine-client | Controls `s_lip_threshold_3` in the engine-client module. |
| [`s_threshold4`](/TaystJK/reference/cvars/s_threshold4-efb9d34/) | cvar | engine-client | Controls `s_lip_threshold_4` in the engine-client module. |
| [`s_UseOpenAL`](/TaystJK/reference/cvars/s_useopenal-edb5f99/) | cvar | engine-client | Controls `cv` in the engine-client module. |
| [`s_volume`](/TaystJK/reference/cvars/s_volume-b61560f/) | cvar | engine-client | Sound effects volume |
| [`s_volumeVoice`](/TaystJK/reference/cvars/s_volumevoice-44b8e79/) | cvar | engine-client | Voice channel volume |
| [`saber1`](/TaystJK/reference/cvars/saber1-5e6205e/) | cvar | engine-client | Player default right hand saber |
| [`saber2`](/TaystJK/reference/cvars/saber2-ee2ab5e/) | cvar | engine-client | Player left hand saber |
| [`scr_conspeed`](/TaystJK/reference/cvars/scr_conspeed-a681b39/) | cvar | engine-client | Console open/close speed |
| [`se_debug`](/TaystJK/reference/cvars/se_debug-6156cff/) | cvar | engine-shared | Controls `se_debug` in the engine-shared module. |
| [`se_language`](/TaystJK/reference/cvars/se_language-5545a01/) | cvar | engine-shared | Controls `se_language` in the engine-shared module. |
| [`sensitivity`](/TaystJK/reference/cvars/sensitivity-bb770a7/) | cvar | engine-client | Mouse sensitivity value |
| [`sex`](/TaystJK/reference/cvars/sex-68bb04b/) | cvar | engine-client | Player sex |
| [`showdrop`](/TaystJK/reference/cvars/showdrop-b56d343/) | cvar | engine-shared | Controls `showdrop` in the engine-shared module. |
| [`showevents`](/TaystJK/reference/cvars/showevents-fbb73ba/) | cvar | game | Controls `showEvents` in the game module. |
| [`showpackets`](/TaystJK/reference/cvars/showpackets-13ebc18/) | cvar | engine-shared | Controls `showpackets` in the engine-shared module. |
| [`snaps`](/TaystJK/reference/cvars/snaps-3c4a85c/) | cvar | engine-client | Client snapshots per second |
| [`sp_leet`](/TaystJK/reference/cvars/sp_leet-e15c4b2/) | cvar | engine-shared | Controls `sp_leet` in the engine-shared module. |
| [`sv_allowDownload`](/TaystJK/reference/cvars/sv_allowdownload-1f23be0/) | cvar | engine-server | Allow clients to download mod files via UDP from the server |
| [`sv_antiDST`](/TaystJK/reference/cvars/sv_antidst-09f18d9/) | cvar | engine-server | Attempts to detect and kick players injecting or using DST |
| [`sv_autoDemo`](/TaystJK/reference/cvars/sv_autodemo-9d9325d/) | cvar | engine-server | Automatically take server-side demos |
| [`sv_autoDemoBots`](/TaystJK/reference/cvars/sv_autodemobots-d25d8d2/) | cvar | engine-server | Record server-side demos for bots |
| [`sv_autoDemoMaxMaps`](/TaystJK/reference/cvars/sv_autodemomaxmaps-76728b7/) | cvar | engine-server | Controls `sv_autoDemoMaxMaps` in the engine-server module. |
| [`sv_autoRaceDemo`](/TaystJK/reference/cvars/sv_autoracedemo-b0d5159/) | cvar | game | Requires custom server executable with "svrecord" command. |
| [`sv_autoWhitelist`](/TaystJK/reference/cvars/sv_autowhitelist-7017003/) | cvar | engine-server | Save player IPs to allow them using server during DOS attack |
| [`sv_banFile`](/TaystJK/reference/cvars/sv_banfile-9b86cae/) | cvar | engine-server | File to use to store bans and exceptions |
| [`sv_cheats`](/TaystJK/reference/cvars/sv_cheats-a5d6021/) | cvar | engine-server | Allow cheats on server if set to 1 |
| [`sv_clientRate`](/TaystJK/reference/cvars/sv_clientrate-25c8382/) | cvar | engine-server | Controls `sv_clientRate` in the engine-server module. |
| [`sv_demoPreRecord`](/TaystJK/reference/cvars/sv_demoprerecord-e5a95c8/) | cvar | engine-server | Activate server demo pre-recording so demos can be retroactively recorded for duration sv_demoPreRecordTime (seconds) |
| [`sv_demoPreRecordKeyframeDistance`](/TaystJK/reference/cvars/sv_demoprerecordkeyframedistance-bd24c86/) | cvar | engine-server | A demo can only start with a gamestate and full non-delta snapshot. How often should we save such a gamestate message? The shorter the distance, the more precisely the pre-record duration will be kept, but also the higher the RAM usage and regularity of non-delta frames being sent to the clients. |
| [`sv_demoPreRecordTime`](/TaystJK/reference/cvars/sv_demoprerecordtime-66cfbf8/) | cvar | engine-server | How many seconds of past packets should be stored for server demo pre-recording? |
| [`sv_filterCommands`](/TaystJK/reference/cvars/sv_filtercommands-f4a9480/) | cvar | engine-server | Controls `sv_filterCommands` in the engine-server module. |
| [`sv_floodProtect`](/TaystJK/reference/cvars/sv_floodprotect-54347f5/) | cvar | engine-server | Protect against flooding of server commands |
| [`sv_fps`](/TaystJK/reference/cvars/sv_fps-1ec111f/) | cvar | engine-server | Server frames per second |
| [`sv_hibernateFPS`](/TaystJK/reference/cvars/sv_hibernatefps-4c1b1a1/) | cvar | engine-server | FPS during hibernation mode |
| [`sv_hibernateTime`](/TaystJK/reference/cvars/sv_hibernatetime-940437b/) | cvar | engine-server | Time after which server will enter hibernation mode |
| [`sv_hostname`](/TaystJK/reference/cvars/sv_hostname-fccbb15/) | cvar | engine-server | The name of the server that is displayed in the serverlist |
| [`sv_httpDownloads`](/TaystJK/reference/cvars/sv_httpdownloads-f79d64e/) | cvar | engine-server | Enable the server's JK2MV-derived HTTP auto-download path. |
| [`sv_httpServerPort`](/TaystJK/reference/cvars/sv_httpserverport-a8fe9d8/) | cvar | engine-server | Set the built-in HTTP download port or an external HTTP URL. |
| [`sv_killserver`](/TaystJK/reference/cvars/sv_killserver-7431ced/) | cvar | engine-server | Controls `sv_killserver` in the engine-server module. |
| [`sv_lanForceRate`](/TaystJK/reference/cvars/sv_lanforcerate-17e0934/) | cvar | engine-server | Controls `sv_lanForceRate` in the engine-server module. |
| [`sv_legacyFixes`](/TaystJK/reference/cvars/sv_legacyfixes-4f7fac8/) | cvar | engine-server | Controls `sv_legacyFixes` in the engine-server module. |
| [`sv_mapChecksum`](/TaystJK/reference/cvars/sv_mapchecksum-848ef8d/) | cvar | engine-server | Controls `ckSum` in the engine-server module. |
| [`sv_master1`](/TaystJK/reference/cvars/sv_master1-f9b0f7d/) | cvar | engine-server | Controls `sv_master1` in the engine-server module. |
| [`sv_master2`](/TaystJK/reference/cvars/sv_master2-5450788/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_master3`](/TaystJK/reference/cvars/sv_master3-14c7d89/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_master4`](/TaystJK/reference/cvars/sv_master4-1ef6bb9/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_master5`](/TaystJK/reference/cvars/sv_master5-79a049a/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_maxclients`](/TaystJK/reference/cvars/sv_maxclients-852a77d/) | cvar | engine-server | Max. connected clients |
| [`sv_maxOOBRate`](/TaystJK/reference/cvars/sv_maxoobrate-bbcc5ef/) | cvar | engine-server | Maximum rate of handling incoming server commands |
| [`sv_maxOOBRateIP`](/TaystJK/reference/cvars/sv_maxoobrateip-21dc800/) | cvar | engine-server | Maximum rate of handling incoming server commands per IP address |
| [`sv_maxPing`](/TaystJK/reference/cvars/sv_maxping-3bde469/) | cvar | engine-server | Controls `sv_maxPing` in the engine-server module. |
| [`sv_maxRate`](/TaystJK/reference/cvars/sv_maxrate-fc02171/) | cvar | engine-server | Max bandwidth rate allowed on server. Use 0 for unlimited. |
| [`sv_minPing`](/TaystJK/reference/cvars/sv_minping-8e1c6bb/) | cvar | engine-server | Controls `sv_minPing` in the engine-server module. |
| [`sv_newfloodProtect`](/TaystJK/reference/cvars/sv_newfloodprotect-e4e33fe/) | cvar | engine-server | Use new method of delaying commands with flood protection |
| [`sv_paused`](/TaystJK/reference/cvars/sv_paused-d622ecf/) | cvar | engine-shared | Controls `sv_paused` in the engine-shared module. |
| [`sv_pingFix`](/TaystJK/reference/cvars/sv_pingfix-3f9f4cd/) | cvar | engine-server | Improved scoreboard client ping calculation |
| [`sv_pluginKey`](/TaystJK/reference/cvars/sv_pluginkey-9d80ed4/) | cvar | game | Controls `sv_pluginKey` in the game module. |
| [`sv_privateClients`](/TaystJK/reference/cvars/sv_privateclients-4f65c02/) | cvar | engine-server | Number of reserved client slots available with password |
| [`sv_pure`](/TaystJK/reference/cvars/sv_pure-85107ab/) | cvar | engine-server | Pure server |
| [`sv_reconnectlimit`](/TaystJK/reference/cvars/sv_reconnectlimit-aaba884/) | cvar | engine-server | Controls `sv_reconnectlimit` in the engine-server module. |
| [`sv_running`](/TaystJK/reference/cvars/sv_running-2b14940/) | cvar | cgame | Is a server running? |
| [`sv_serverid`](/TaystJK/reference/cvars/sv_serverid-929cf16/) | cvar | engine-server | Controls `sv_serverid` in the engine-server module. |
| [`sv_showloss`](/TaystJK/reference/cvars/sv_showloss-545b07f/) | cvar | engine-server | Registered by the current source, but no user-facing behavior description has been verified. |
| [`sv_snapsMax`](/TaystJK/reference/cvars/sv_snapsmax-b20336c/) | cvar | engine-server | Sv_snapsMin <=> sv_fps |
| [`sv_snapsMin`](/TaystJK/reference/cvars/sv_snapsmin-7fe81b5/) | cvar | engine-server | 1 <=> sv_snapsMax |
| [`sv_snapsPolicy`](/TaystJK/reference/cvars/sv_snapspolicy-385ae5d/) | cvar | engine-server | Determines which policy of enforcement is used for client's \"snaps\" cvar |
| [`sv_timeout`](/TaystJK/reference/cvars/sv_timeout-2e15cf0/) | cvar | engine-server | Controls `sv_timeout` in the engine-server module. |
| [`sv_zombietime`](/TaystJK/reference/cvars/sv_zombietime-c069b6b/) | cvar | engine-server | Controls `sv_zombietime` in the engine-server module. |
| [`sys_lowmem`](/TaystJK/reference/cvars/sys_lowmem-8037c1f/) | cvar | engine-shared | Controls `sys_lowmem` in the engine-shared module. |
| [`teamoverlay`](/TaystJK/reference/cvars/teamoverlay-f842919/) | cvar | cgame | Controls `teamoverlay` in the cgame module. |
| [`timedemo`](/TaystJK/reference/cvars/timedemo-32d1727/) | cvar | engine-client | Controls `cl_timedemo` in the engine-client module. |
| [`timegraph`](/TaystJK/reference/cvars/timegraph-db7f449/) | cvar | engine-client | Controls `cl_timegraph` in the engine-client module. |
| [`timelimit`](/TaystJK/reference/cvars/timelimit-050b6ba/) | cvar | game | Controls `timelimit` in the game module. |
| [`timescale`](/TaystJK/reference/cvars/timescale-97bdf9f/) | cvar | cgame | Controls `timescale` in the cgame module. |
| [`ui_about_botminplayers`](/TaystJK/reference/cvars/ui_about_botminplayers-10e7331/) | cvar | cgame | Controls `ui_about_botminplayers` in the cgame module. |
| [`ui_about_capturelimit`](/TaystJK/reference/cvars/ui_about_capturelimit-98d5070/) | cvar | cgame | Controls `ui_about_capturelimit` in the cgame module. |
| [`ui_about_dmflags`](/TaystJK/reference/cvars/ui_about_dmflags-59c5610/) | cvar | cgame | Controls `ui_about_dmflags` in the cgame module. |
| [`ui_about_duellimit`](/TaystJK/reference/cvars/ui_about_duellimit-bce4d5b/) | cvar | cgame | Controls `ui_about_duellimit` in the cgame module. |
| [`ui_about_fraglimit`](/TaystJK/reference/cvars/ui_about_fraglimit-87f305c/) | cvar | cgame | Controls `ui_about_fraglimit` in the cgame module. |
| [`ui_about_gametype`](/TaystJK/reference/cvars/ui_about_gametype-da939aa/) | cvar | cgame | Controls `ui_about_gametype` in the cgame module. |
| [`ui_about_hostname`](/TaystJK/reference/cvars/ui_about_hostname-52cdc99/) | cvar | cgame | Controls `ui_about_hostname` in the cgame module. |
| [`ui_about_mapname`](/TaystJK/reference/cvars/ui_about_mapname-48214ba/) | cvar | cgame | Controls `ui_about_mapname` in the cgame module. |
| [`ui_about_maxclients`](/TaystJK/reference/cvars/ui_about_maxclients-7bbd8c0/) | cvar | cgame | Controls `ui_about_maxclients` in the cgame module. |
| [`ui_about_needpass`](/TaystJK/reference/cvars/ui_about_needpass-578f7b4/) | cvar | cgame | Controls `ui_about_needpass` in the cgame module. |
| [`ui_about_timelimit`](/TaystJK/reference/cvars/ui_about_timelimit-182983b/) | cvar | cgame | Controls `ui_about_timelimit` in the cgame module. |
| [`ui_actualNetGametype`](/TaystJK/reference/cvars/ui_actualnetgametype-70fb097/) | cvar | ui | Controls `ui_actualNetGametype` in the ui module. |
| [`ui_allowSaberSwitch`](/TaystJK/reference/cvars/ui_allowsaberswitch-6b40886/) | cvar | ui | Controls `ui_allowSaberSwitch` in the ui module. |
| [`ui_blueteam`](/TaystJK/reference/cvars/ui_blueteam-17a25d6/) | cvar | ui | Controls `ui_blueteam` in the ui module. |
| [`ui_blueteam1`](/TaystJK/reference/cvars/ui_blueteam1-340fe0d/) | cvar | ui | Controls `ui_blueteam1` in the ui module. |
| [`ui_blueteam2`](/TaystJK/reference/cvars/ui_blueteam2-ee938fb/) | cvar | ui | Controls `ui_blueteam2` in the ui module. |
| [`ui_blueteam3`](/TaystJK/reference/cvars/ui_blueteam3-e2e0895/) | cvar | ui | Controls `ui_blueteam3` in the ui module. |
| [`ui_blueteam4`](/TaystJK/reference/cvars/ui_blueteam4-7fa667e/) | cvar | ui | Controls `ui_blueteam4` in the ui module. |
| [`ui_blueteam5`](/TaystJK/reference/cvars/ui_blueteam5-fe0911a/) | cvar | ui | Controls `ui_blueteam5` in the ui module. |
| [`ui_blueteam6`](/TaystJK/reference/cvars/ui_blueteam6-9ab3444/) | cvar | ui | Controls `ui_blueteam6` in the ui module. |
| [`ui_blueteam7`](/TaystJK/reference/cvars/ui_blueteam7-b99b7a8/) | cvar | ui | Controls `ui_blueteam7` in the ui module. |
| [`ui_blueteam8`](/TaystJK/reference/cvars/ui_blueteam8-900a45c/) | cvar | ui | Controls `ui_blueteam8` in the ui module. |
| [`ui_browserShowEmpty`](/TaystJK/reference/cvars/ui_browsershowempty-68572ca/) | cvar | ui | Controls `ui_browserShowEmpty` in the ui module. |
| [`ui_browserShowFull`](/TaystJK/reference/cvars/ui_browsershowfull-6068674/) | cvar | ui | Controls `ui_browserShowFull` in the ui module. |
| [`ui_browserShowPasswordProtected`](/TaystJK/reference/cvars/ui_browsershowpasswordprotected-204880a/) | cvar | ui | Controls `ui_browserShowPasswordProtected` in the ui module. |
| [`ui_bypassMainMenuLoad`](/TaystJK/reference/cvars/ui_bypassmainmenuload-408ee1e/) | cvar | ui | Controls `ui_bypassMainMenuLoad` in the ui module. |
| [`ui_captureLimit`](/TaystJK/reference/cvars/ui_capturelimit-0eca7ff/) | cvar | ui | Controls `ui_captureLimit` in the ui module. |
| [`ui_cg_shadows`](/TaystJK/reference/cvars/ui_cg_shadows-b52e606/) | cvar | ui | Controls `ui_cg_shadows` in the ui module. |
| [`ui_char_anim`](/TaystJK/reference/cvars/ui_char_anim-09080f3/) | cvar | ui | Controls `ui_char_anim` in the ui module. |
| [`ui_char_color_blue`](/TaystJK/reference/cvars/ui_char_color_blue-28e01a4/) | cvar | ui | Controls `ui_char_color_blue` in the ui module. |
| [`ui_char_color_green`](/TaystJK/reference/cvars/ui_char_color_green-efefe4d/) | cvar | ui | Controls `ui_char_color_green` in the ui module. |
| [`ui_char_color_red`](/TaystJK/reference/cvars/ui_char_color_red-efed648/) | cvar | ui | Controls `ui_char_color_red` in the ui module. |
| [`ui_char_model`](/TaystJK/reference/cvars/ui_char_model-767a8b1/) | cvar | ui | Controls `ui_char_model` in the ui module. |
| [`ui_char_skin_head`](/TaystJK/reference/cvars/ui_char_skin_head-8f224b8/) | cvar | ui | Controls `ui_char_skin_head` in the ui module. |
| [`ui_char_skin_legs`](/TaystJK/reference/cvars/ui_char_skin_legs-76fbb98/) | cvar | ui | Controls `ui_char_skin_legs` in the ui module. |
| [`ui_char_skin_torso`](/TaystJK/reference/cvars/ui_char_skin_torso-0fe93fd/) | cvar | ui | Controls `ui_char_skin_torso` in the ui module. |
| [`ui_ctf_capturelimit`](/TaystJK/reference/cvars/ui_ctf_capturelimit-639898d/) | cvar | ui | Controls `ui_ctf_capturelimit` in the ui module. |
| [`ui_ctf_friendly`](/TaystJK/reference/cvars/ui_ctf_friendly-ff1dc3a/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_ctf_timelimit`](/TaystJK/reference/cvars/ui_ctf_timelimit-186b2d1/) | cvar | ui | Controls `ui_ctf_timelimit` in the ui module. |
| [`ui_currentMap`](/TaystJK/reference/cvars/ui_currentmap-27fc114/) | cvar | ui | Controls `ui_currentMap` in the ui module. |
| [`ui_currentNetMap`](/TaystJK/reference/cvars/ui_currentnetmap-81eb329/) | cvar | ui | Controls `ui_currentNetMap` in the ui module. |
| [`ui_currentOpponent`](/TaystJK/reference/cvars/ui_currentopponent-bbc3c11/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_dedicated`](/TaystJK/reference/cvars/ui_dedicated-c7593a0/) | cvar | ui | Controls `ui_dedicated` in the ui module. |
| [`ui_disableWeaponSway`](/TaystJK/reference/cvars/ui_disableweaponsway-e995888/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_ffa_fraglimit`](/TaystJK/reference/cvars/ui_ffa_fraglimit-5876427/) | cvar | ui | Controls `ui_ffa_fraglimit` in the ui module. |
| [`ui_ffa_timelimit`](/TaystJK/reference/cvars/ui_ffa_timelimit-ce6b60e/) | cvar | ui | Controls `ui_ffa_timelimit` in the ui module. |
| [`ui_findPlayer`](/TaystJK/reference/cvars/ui_findplayer-02ede1c/) | cvar | ui | Controls `ui_findPlayer` in the ui module. |
| [`ui_forcePowerDisable`](/TaystJK/reference/cvars/ui_forcepowerdisable-331521c/) | cvar | ui | Controls `ui_forcePowerDisable` in the ui module. |
| [`ui_fragLimit`](/TaystJK/reference/cvars/ui_fraglimit-178a086/) | cvar | ui | Controls `ui_fragLimit` in the ui module. |
| [`ui_freeSaber`](/TaystJK/reference/cvars/ui_freesaber-c23f8d2/) | cvar | ui | Controls `ui_freeSaber` in the ui module. |
| [`ui_gametype`](/TaystJK/reference/cvars/ui_gametype-a49b5f0/) | cvar | ui | Controls `ui_gametype` in the ui module. |
| [`ui_headCount`](/TaystJK/reference/cvars/ui_headcount-384f251/) | cvar | ui | Controls `ui_headCount` in the ui module. |
| [`ui_isJAPro`](/TaystJK/reference/cvars/ui_isjapro-9265944/) | cvar | ui | Controls `ui_isJAPro` in the ui module. |
| [`ui_joinGametype`](/TaystJK/reference/cvars/ui_joingametype-71f7a60/) | cvar | ui | Controls `ui_joinGametype` in the ui module. |
| [`ui_lastServerRefresh_0`](/TaystJK/reference/cvars/ui_lastserverrefresh_0-be69301/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_1`](/TaystJK/reference/cvars/ui_lastserverrefresh_1-14bcea1/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_2`](/TaystJK/reference/cvars/ui_lastserverrefresh_2-686148e/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_lastServerRefresh_3`](/TaystJK/reference/cvars/ui_lastserverrefresh_3-aa83713/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_mapIndex`](/TaystJK/reference/cvars/ui_mapindex-5cacf3a/) | cvar | ui | Controls `ui_mapIndex` in the ui module. |
| [`ui_menuFilesMP`](/TaystJK/reference/cvars/ui_menufilesmp-4fdfd20/) | cvar | ui | Controls `ui_menuFilesMP` in the ui module. |
| [`ui_myteam`](/TaystJK/reference/cvars/ui_myteam-fece47c/) | cvar | cgame | Controls `ui_myteam` in the cgame module. |
| [`ui_Name`](/TaystJK/reference/cvars/ui_name-9d84122/) | cvar | ui | Controls `ui_Name` in the ui module. |
| [`ui_netGametype`](/TaystJK/reference/cvars/ui_netgametype-273c08f/) | cvar | ui | Controls `ui_netGametype` in the ui module. |
| [`ui_netSource`](/TaystJK/reference/cvars/ui_netsource-7f47658/) | cvar | ui | Controls `ui_netSource` in the ui module. |
| [`ui_opponentName`](/TaystJK/reference/cvars/ui_opponentname-479d170/) | cvar | ui | Controls `ui_opponentName` in the ui module. |
| [`ui_password`](/TaystJK/reference/cvars/ui_password-5175d7a/) | cvar | ui | Controls `ui_password` in the ui module. |
| [`ui_PrecacheModels`](/TaystJK/reference/cvars/ui_precachemodels-5229eee/) | cvar | ui | Controls `ui_PrecacheModels` in the ui module. |
| [`ui_r_allowExtensions`](/TaystJK/reference/cvars/ui_r_allowextensions-8370712/) | cvar | ui | Controls `ui_r_allowExtensions` in the ui module. |
| [`ui_r_colorbits`](/TaystJK/reference/cvars/ui_r_colorbits-edf76e7/) | cvar | ui | Controls `ui_r_colorbits` in the ui module. |
| [`ui_r_depthbits`](/TaystJK/reference/cvars/ui_r_depthbits-60aa449/) | cvar | ui | Controls `ui_r_depthbits` in the ui module. |
| [`ui_r_detailtextures`](/TaystJK/reference/cvars/ui_r_detailtextures-3adef96/) | cvar | ui | Controls `ui_r_detailtextures` in the ui module. |
| [`ui_r_ext_compress_textures`](/TaystJK/reference/cvars/ui_r_ext_compress_textures-6b011e4/) | cvar | ui | Controls `ui_r_ext_compress_textures` in the ui module. |
| [`ui_r_fastSky`](/TaystJK/reference/cvars/ui_r_fastsky-ba5631d/) | cvar | ui | Controls `ui_r_fastSky` in the ui module. |
| [`ui_r_fullscreen`](/TaystJK/reference/cvars/ui_r_fullscreen-d65a208/) | cvar | ui | Controls `ui_r_fullscreen` in the ui module. |
| [`ui_r_glCustom`](/TaystJK/reference/cvars/ui_r_glcustom-8cde091/) | cvar | ui | Controls `ui_r_glCustom` in the ui module. |
| [`ui_r_inGameVideo`](/TaystJK/reference/cvars/ui_r_ingamevideo-7c28d4e/) | cvar | ui | Controls `ui_r_inGameVideo` in the ui module. |
| [`ui_r_lodbias`](/TaystJK/reference/cvars/ui_r_lodbias-7ae11a3/) | cvar | ui | Controls `ui_r_lodbias` in the ui module. |
| [`ui_r_mode`](/TaystJK/reference/cvars/ui_r_mode-c847d5b/) | cvar | ui | Controls `ui_r_mode` in the ui module. |
| [`ui_r_modified`](/TaystJK/reference/cvars/ui_r_modified-31a56f1/) | cvar | ui | Controls `ui_r_modified` in the ui module. |
| [`ui_r_picmip`](/TaystJK/reference/cvars/ui_r_picmip-643c4bd/) | cvar | ui | Controls `ui_r_picmip` in the ui module. |
| [`ui_r_subdivisions`](/TaystJK/reference/cvars/ui_r_subdivisions-a364fcd/) | cvar | ui | Controls `ui_r_subdivisions` in the ui module. |
| [`ui_r_texturebits`](/TaystJK/reference/cvars/ui_r_texturebits-548dadc/) | cvar | ui | Controls `ui_r_texturebits` in the ui module. |
| [`ui_r_texturemode`](/TaystJK/reference/cvars/ui_r_texturemode-a7e1e5d/) | cvar | ui | Controls `ui_r_texturemode` in the ui module. |
| [`ui_rankChange`](/TaystJK/reference/cvars/ui_rankchange-ccf6b2b/) | cvar | ui | Controls `ui_rankChange` in the ui module. |
| [`ui_recordSPDemo`](/TaystJK/reference/cvars/ui_recordspdemo-44187ba/) | cvar | ui | Controls `ui_recordSPDemo` in the ui module. |
| [`ui_recordSPDemoName`](/TaystJK/reference/cvars/ui_recordspdemoname-ee64901/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_redteam`](/TaystJK/reference/cvars/ui_redteam-6b35b92/) | cvar | ui | Controls `ui_redteam` in the ui module. |
| [`ui_redteam1`](/TaystJK/reference/cvars/ui_redteam1-70a336e/) | cvar | ui | Rww - these used to all default to 0 (closed).. I changed them to 1 (human) |
| [`ui_redteam2`](/TaystJK/reference/cvars/ui_redteam2-49de4e1/) | cvar | ui | Controls `ui_redteam2` in the ui module. |
| [`ui_redteam3`](/TaystJK/reference/cvars/ui_redteam3-5f1890f/) | cvar | ui | Controls `ui_redteam3` in the ui module. |
| [`ui_redteam4`](/TaystJK/reference/cvars/ui_redteam4-665ae9e/) | cvar | ui | Controls `ui_redteam4` in the ui module. |
| [`ui_redteam5`](/TaystJK/reference/cvars/ui_redteam5-7facc52/) | cvar | ui | Controls `ui_redteam5` in the ui module. |
| [`ui_redteam6`](/TaystJK/reference/cvars/ui_redteam6-216c2b4/) | cvar | ui | Controls `ui_redteam6` in the ui module. |
| [`ui_redteam7`](/TaystJK/reference/cvars/ui_redteam7-3764a86/) | cvar | ui | Controls `ui_redteam7` in the ui module. |
| [`ui_redteam8`](/TaystJK/reference/cvars/ui_redteam8-75f4165/) | cvar | ui | Controls `ui_redteam8` in the ui module. |
| [`ui_RGBSkin`](/TaystJK/reference/cvars/ui_rgbskin-9bfb7fc/) | cvar | ui | Controls `ui_RGBSkin` in the ui module. |
| [`ui_saber`](/TaystJK/reference/cvars/ui_saber-71ba6a0/) | cvar | ui | Controls `ui_saber` in the ui module. |
| [`ui_saber2`](/TaystJK/reference/cvars/ui_saber2-bf4c5fb/) | cvar | ui | Controls `ui_saber2` in the ui module. |
| [`ui_saber2_color`](/TaystJK/reference/cvars/ui_saber2_color-f8b16cc/) | cvar | ui | Controls `ui_saber2_color` in the ui module. |
| [`ui_saber_color`](/TaystJK/reference/cvars/ui_saber_color-b952b9a/) | cvar | ui | Controls `ui_saber_color` in the ui module. |
| [`ui_saber_type`](/TaystJK/reference/cvars/ui_saber_type-64a96ba/) | cvar | ui | Controls `ui_saber_type` in the ui module. |
| [`ui_scoreAccuracy`](/TaystJK/reference/cvars/ui_scoreaccuracy-5d5cf15/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreAssists`](/TaystJK/reference/cvars/ui_scoreassists-0c89a87/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreBase`](/TaystJK/reference/cvars/ui_scorebase-32f4ade/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreCaptures`](/TaystJK/reference/cvars/ui_scorecaptures-3988e53/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreDefends`](/TaystJK/reference/cvars/ui_scoredefends-b3729af/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreExcellents`](/TaystJK/reference/cvars/ui_scoreexcellents-2ff7ed1/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreGauntlets`](/TaystJK/reference/cvars/ui_scoregauntlets-72788c3/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreImpressives`](/TaystJK/reference/cvars/ui_scoreimpressives-f849016/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scorePerfect`](/TaystJK/reference/cvars/ui_scoreperfect-3cd27c8/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreScore`](/TaystJK/reference/cvars/ui_scorescore-3d05888/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreShutoutBonus`](/TaystJK/reference/cvars/ui_scoreshutoutbonus-07f5014/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreSkillBonus`](/TaystJK/reference/cvars/ui_scoreskillbonus-91d5bda/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreTeam`](/TaystJK/reference/cvars/ui_scoreteam-d324531/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreTime`](/TaystJK/reference/cvars/ui_scoretime-6f45bec/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_scoreTimeBonus`](/TaystJK/reference/cvars/ui_scoretimebonus-ba25d5e/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_screenshotType`](/TaystJK/reference/cvars/ui_screenshottype-77cec01/) | cvar | ui | Controls `ui_screenshotType` in the ui module. |
| [`ui_selectedModelIndex`](/TaystJK/reference/cvars/ui_selectedmodelindex-659d4e5/) | cvar | ui | Controls `ui_selectedModelIndex` in the ui module. |
| [`ui_serverFilterType`](/TaystJK/reference/cvars/ui_serverfiltertype-0e36b83/) | cvar | ui | Controls `ui_serverFilterType` in the ui module. |
| [`ui_serverStatusTimeOut`](/TaystJK/reference/cvars/ui_serverstatustimeout-133ca4a/) | cvar | ui | Controls `ui_serverStatusTimeOut` in the ui module. |
| [`ui_sha_a`](/TaystJK/reference/cvars/ui_sha_a-a8e4932/) | cvar | ui | Controls `ui_sha_a` in the ui module. |
| [`ui_sha_b`](/TaystJK/reference/cvars/ui_sha_b-0e69c90/) | cvar | ui | Controls `ui_sha_b` in the ui module. |
| [`ui_sha_g`](/TaystJK/reference/cvars/ui_sha_g-ac3139d/) | cvar | ui | Controls `ui_sha_g` in the ui module. |
| [`ui_sha_r`](/TaystJK/reference/cvars/ui_sha_r-2be1fbe/) | cvar | ui | Controls `ui_sha_r` in the ui module. |
| [`ui_showAllSkins`](/TaystJK/reference/cvars/ui_showallskins-069498a/) | cvar | ui | Controls `ui_showAllSkins` in the ui module. |
| [`ui_singlePlayerActive`](/TaystJK/reference/cvars/ui_singleplayeractive-d8349a1/) | cvar | ui | Controls `ui_singlePlayerActive` in the ui module. |
| [`ui_team_fraglimit`](/TaystJK/reference/cvars/ui_team_fraglimit-91b6e91/) | cvar | ui | Controls `ui_team_fraglimit` in the ui module. |
| [`ui_team_friendly`](/TaystJK/reference/cvars/ui_team_friendly-a4d19b4/) | cvar | ui | Registered by the current source, but no user-facing behavior description has been verified. |
| [`ui_team_timelimit`](/TaystJK/reference/cvars/ui_team_timelimit-23b0f17/) | cvar | ui | Controls `ui_team_timelimit` in the ui module. |
| [`ui_teamSize`](/TaystJK/reference/cvars/ui_teamsize-7d2c5d8/) | cvar | ui | Controls `ui_teamSize` in the ui module. |
| [`ui_tm1_c0_cnt`](/TaystJK/reference/cvars/ui_tm1_c0_cnt-6969d05/) | cvar | cgame | Controls `ui_tm1_c0_cnt` in the cgame module. |
| [`ui_tm1_c1_cnt`](/TaystJK/reference/cvars/ui_tm1_c1_cnt-adca072/) | cvar | cgame | Controls `ui_tm1_c1_cnt` in the cgame module. |
| [`ui_tm1_c2_cnt`](/TaystJK/reference/cvars/ui_tm1_c2_cnt-ffb7dfb/) | cvar | cgame | Controls `ui_tm1_c2_cnt` in the cgame module. |
| [`ui_tm1_c3_cnt`](/TaystJK/reference/cvars/ui_tm1_c3_cnt-19a03be/) | cvar | cgame | Controls `ui_tm1_c3_cnt` in the cgame module. |
| [`ui_tm1_c4_cnt`](/TaystJK/reference/cvars/ui_tm1_c4_cnt-dfd1642/) | cvar | cgame | Controls `ui_tm1_c4_cnt` in the cgame module. |
| [`ui_tm1_c5_cnt`](/TaystJK/reference/cvars/ui_tm1_c5_cnt-2faa522/) | cvar | cgame | Controls `ui_tm1_c5_cnt` in the cgame module. |
| [`ui_tm1_cnt`](/TaystJK/reference/cvars/ui_tm1_cnt-a83c5ab/) | cvar | cgame | Controls `ui_tm1_cnt` in the cgame module. |
| [`ui_tm2_c0_cnt`](/TaystJK/reference/cvars/ui_tm2_c0_cnt-0b18292/) | cvar | cgame | Controls `ui_tm2_c0_cnt` in the cgame module. |
| [`ui_tm2_c1_cnt`](/TaystJK/reference/cvars/ui_tm2_c1_cnt-bd46ba2/) | cvar | cgame | Controls `ui_tm2_c1_cnt` in the cgame module. |
| [`ui_tm2_c2_cnt`](/TaystJK/reference/cvars/ui_tm2_c2_cnt-ccda017/) | cvar | cgame | Controls `ui_tm2_c2_cnt` in the cgame module. |
| [`ui_tm2_c3_cnt`](/TaystJK/reference/cvars/ui_tm2_c3_cnt-02a4ab2/) | cvar | cgame | Controls `ui_tm2_c3_cnt` in the cgame module. |
| [`ui_tm2_c4_cnt`](/TaystJK/reference/cvars/ui_tm2_c4_cnt-e659b3d/) | cvar | cgame | Controls `ui_tm2_c4_cnt` in the cgame module. |
| [`ui_tm2_c5_cnt`](/TaystJK/reference/cvars/ui_tm2_c5_cnt-57587a0/) | cvar | cgame | Controls `ui_tm2_c5_cnt` in the cgame module. |
| [`ui_tm2_cnt`](/TaystJK/reference/cvars/ui_tm2_cnt-abb217e/) | cvar | cgame | Controls `ui_tm2_cnt` in the cgame module. |
| [`ui_tm3_cnt`](/TaystJK/reference/cvars/ui_tm3_cnt-f359456/) | cvar | cgame | Controls `ui_tm3_cnt` in the cgame module. |
| [`ui_username`](/TaystJK/reference/cvars/ui_username-1211939/) | cvar | ui | Controls `ui_username` in the ui module. |
| [`ui_vgs`](/TaystJK/reference/cvars/ui_vgs-6f63532/) | cvar | ui | Controls `ui_vgs` in the ui module. |
| [`ui_vidrestart`](/TaystJK/reference/cvars/ui_vidrestart-724a091/) | cvar | ui | Controls `ui_vidrestart` in the ui module. |
| [`username`](/TaystJK/reference/cvars/username-249ba36/) | cvar | engine-shared | Controls `username` in the engine-shared module. |
| [`version`](/TaystJK/reference/cvars/version-c692273/) | cvar | engine-shared | Registered by the current source, but no user-facing behavior description has been verified. |
| [`vid_xpos`](/TaystJK/reference/cvars/vid_xpos-617b8c0/) | cvar | engine-shared | Controls `vid_xpos` in the engine-shared module. |
| [`vid_ypos`](/TaystJK/reference/cvars/vid_ypos-a66867d/) | cvar | engine-shared | Controls `vid_ypos` in the engine-shared module. |
| [`vm_legacy`](/TaystJK/reference/cvars/vm_legacy-cfedd35/) | cvar | engine-shared | Controls `vm_legacy` in the engine-shared module. |
| [`volume`](/TaystJK/reference/cvars/volume-d387fc8/) | cvar | engine-client | Volume |
| [`+altattack`](/TaystJK/reference/commands/plusminus-altattack-60556a0/) | command | engine-client | Alternate Attack |
| [`+attack`](/TaystJK/reference/commands/plusminus-attack-4391cc3/) | command | engine-client | Primary Attack |
| [`+back`](/TaystJK/reference/commands/plusminus-back-e379d81/) | command | engine-client | Move backward |
| [`+button0`](/TaystJK/reference/commands/plusminus-button0-be7f4bb/) | command | engine-client | Button 0 |
| [`+button1`](/TaystJK/reference/commands/plusminus-button1-4df0ef3/) | command | engine-client | Button 1 |
| [`+button10`](/TaystJK/reference/commands/plusminus-button10-ff5ecaf/) | command | engine-client | Button 10 |
| [`+button11`](/TaystJK/reference/commands/plusminus-button11-2e62bb9/) | command | engine-client | Button 11 |
| [`+button12`](/TaystJK/reference/commands/plusminus-button12-c5794a4/) | command | engine-client | Button 12 |
| [`+button13`](/TaystJK/reference/commands/plusminus-button13-611ede2/) | command | engine-client | Button 13 |
| [`+button14`](/TaystJK/reference/commands/plusminus-button14-6bf4b10/) | command | engine-client | Button 14 |
| [`+button15`](/TaystJK/reference/commands/plusminus-button15-6428f06/) | command | engine-client | Button 15 |
| [`+button2`](/TaystJK/reference/commands/plusminus-button2-57692ae/) | command | engine-client | Button 2 |
| [`+button3`](/TaystJK/reference/commands/plusminus-button3-546d711/) | command | engine-client | Button 3 |
| [`+button4`](/TaystJK/reference/commands/plusminus-button4-30fce65/) | command | engine-client | Button 4 |
| [`+button5`](/TaystJK/reference/commands/plusminus-button5-1c34bdb/) | command | engine-client | Button 5 |
| [`+button6`](/TaystJK/reference/commands/plusminus-button6-6b3a068/) | command | engine-client | Button 6 |
| [`+button7`](/TaystJK/reference/commands/plusminus-button7-b0bdd34/) | command | engine-client | Button 7 |
| [`+button8`](/TaystJK/reference/commands/plusminus-button8-49c3c24/) | command | engine-client | Button 8 |
| [`+button9`](/TaystJK/reference/commands/plusminus-button9-2f04f45/) | command | engine-client | Button 9 |
| [`+duck`](/TaystJK/reference/commands/plusminus-duck-1aea248/) | command | cgame | Runs `CG_NorollDown_f` in the cgame module. |
| [`+force_drain`](/TaystJK/reference/commands/plusminus-force_drain-bdcd1dc/) | command | engine-client | Hold to use drain force power |
| [`+force_grip`](/TaystJK/reference/commands/plusminus-force_grip-93d6432/) | command | engine-client | Hold to use grip force power |
| [`+force_lightning`](/TaystJK/reference/commands/plusminus-force_lightning-f55d150/) | command | engine-client | Hold to use lightning force power |
| [`+forward`](/TaystJK/reference/commands/plusminus-forward-7866d6a/) | command | engine-client | Move forward |
| [`+left`](/TaystJK/reference/commands/plusminus-left-8bdd742/) | command | engine-client | Rotate camera left |
| [`+lookdown`](/TaystJK/reference/commands/plusminus-lookdown-5e25b23/) | command | engine-client | Tilt camera down |
| [`+lookup`](/TaystJK/reference/commands/plusminus-lookup-9bcaaf1/) | command | engine-client | Tilt camera up |
| [`+mlook`](/TaystJK/reference/commands/plusminus-mlook-03e60ef/) | command | engine-client | Hold to use mouse look |
| [`+movedown`](/TaystJK/reference/commands/plusminus-movedown-0be8661/) | command | engine-client | Crouch |
| [`+moveleft`](/TaystJK/reference/commands/plusminus-moveleft-f14058f/) | command | engine-client | Strafe left |
| [`+moveright`](/TaystJK/reference/commands/plusminus-moveright-511a14c/) | command | engine-client | Strafe right |
| [`+moveup`](/TaystJK/reference/commands/plusminus-moveup-b1f0103/) | command | engine-client | Jump |
| [`+right`](/TaystJK/reference/commands/plusminus-right-5e3b5dc/) | command | engine-client | Rotate camera right |
| [`+scores`](/TaystJK/reference/commands/plusminus-scores-d436431/) | command | cgame | Runs `CG_ScoresDown_f` in the cgame module. |
| [`+speed`](/TaystJK/reference/commands/plusminus-speed-d1ef0fc/) | command | engine-client | Walk or run |
| [`+strafe`](/TaystJK/reference/commands/plusminus-strafe-1e9bba6/) | command | engine-client | Hold to strafe |
| [`+use`](/TaystJK/reference/commands/plusminus-use-5cd9e39/) | command | engine-client | Use item |
| [`+useforce`](/TaystJK/reference/commands/plusminus-useforce-a05b10e/) | command | engine-client | Use selected force power |
| [`+zoom`](/TaystJK/reference/commands/plusminus-zoom-0eb4e7d/) | command | cgame | Runs `CG_ZoomDown_f` in the cgame module. |
| [`-altattack`](/TaystJK/reference/commands/minus-altattack-0273d3a/) | command | engine-client | Runs `IN_Button7Up` in the engine-client module. |
| [`-attack`](/TaystJK/reference/commands/minus-attack-e43abab/) | command | engine-client | Runs `IN_Button0Up` in the engine-client module. |
| [`-back`](/TaystJK/reference/commands/minus-back-9d738c1/) | command | engine-client | Runs `IN_BackUp` in the engine-client module. |
| [`-button0`](/TaystJK/reference/commands/minus-button0-0c59ac3/) | command | engine-client | Runs `IN_Button0Up` in the engine-client module. |
| [`-button1`](/TaystJK/reference/commands/minus-button1-1f0afc2/) | command | engine-client | Runs `IN_Button1Up` in the engine-client module. |
| [`-button10`](/TaystJK/reference/commands/minus-button10-ecaa3f2/) | command | engine-client | Runs `IN_Button10Up` in the engine-client module. |
| [`-button11`](/TaystJK/reference/commands/minus-button11-72100b7/) | command | engine-client | Runs `IN_Button11Up` in the engine-client module. |
| [`-button12`](/TaystJK/reference/commands/minus-button12-34f0dd4/) | command | engine-client | Runs `IN_Button12Up` in the engine-client module. |
| [`-button13`](/TaystJK/reference/commands/minus-button13-29fece4/) | command | engine-client | Runs `IN_Button13Up` in the engine-client module. |
| [`-button14`](/TaystJK/reference/commands/minus-button14-cc48ee5/) | command | engine-client | Runs `IN_Button14Up` in the engine-client module. |
| [`-button15`](/TaystJK/reference/commands/minus-button15-95d61e3/) | command | engine-client | Runs `IN_Button15Up` in the engine-client module. |
| [`-button2`](/TaystJK/reference/commands/minus-button2-09a0451/) | command | engine-client | Runs `IN_Button2Up` in the engine-client module. |
| [`-button3`](/TaystJK/reference/commands/minus-button3-d59f20f/) | command | engine-client | Runs `IN_Button3Up` in the engine-client module. |
| [`-button4`](/TaystJK/reference/commands/minus-button4-e553417/) | command | engine-client | Runs `IN_Button4Up` in the engine-client module. |
| [`-button5`](/TaystJK/reference/commands/minus-button5-ccc9730/) | command | engine-client | Runs `IN_Button5Up` in the engine-client module. |
| [`-button6`](/TaystJK/reference/commands/minus-button6-073c01d/) | command | engine-client | Runs `IN_Button6Up` in the engine-client module. |
| [`-button7`](/TaystJK/reference/commands/minus-button7-1028e4d/) | command | engine-client | Runs `IN_Button7Up` in the engine-client module. |
| [`-button8`](/TaystJK/reference/commands/minus-button8-44eb725/) | command | engine-client | Runs `IN_Button8Up` in the engine-client module. |
| [`-button9`](/TaystJK/reference/commands/minus-button9-70255ea/) | command | engine-client | Runs `IN_Button9Up` in the engine-client module. |
| [`-duck`](/TaystJK/reference/commands/minus-duck-e229dd0/) | command | cgame | Runs `CG_NorollUp_f` in the cgame module. |
| [`-force_drain`](/TaystJK/reference/commands/minus-force_drain-8150067/) | command | engine-client | Runs `IN_Button11Up` in the engine-client module. |
| [`-force_grip`](/TaystJK/reference/commands/minus-force_grip-e61faf8/) | command | engine-client | Runs `IN_Button6Up` in the engine-client module. |
| [`-force_lightning`](/TaystJK/reference/commands/minus-force_lightning-58e7bf3/) | command | engine-client | Runs `IN_Button10Up` in the engine-client module. |
| [`-forward`](/TaystJK/reference/commands/minus-forward-780292f/) | command | engine-client | Runs `IN_ForwardUp` in the engine-client module. |
| [`-grapple`](/TaystJK/reference/commands/minus-grapple-b7c9090/) | command | cgame | Runs `CG_GrappleUp_f` in the cgame module. |
| [`-left`](/TaystJK/reference/commands/minus-left-adf5fbd/) | command | engine-client | Runs `IN_LeftUp` in the engine-client module. |
| [`-lookdown`](/TaystJK/reference/commands/minus-lookdown-93d6cd0/) | command | engine-client | Runs `IN_LookdownUp` in the engine-client module. |
| [`-lookup`](/TaystJK/reference/commands/minus-lookup-8aa409f/) | command | engine-client | Runs `IN_LookupUp` in the engine-client module. |
| [`-mlook`](/TaystJK/reference/commands/minus-mlook-94b9765/) | command | engine-client | Runs `IN_MLookUp` in the engine-client module. |
| [`-movedown`](/TaystJK/reference/commands/minus-movedown-4fdaa04/) | command | engine-client | Runs `IN_DownUp` in the engine-client module. |
| [`-moveleft`](/TaystJK/reference/commands/minus-moveleft-b288f12/) | command | engine-client | Runs `IN_MoveleftUp` in the engine-client module. |
| [`-moveright`](/TaystJK/reference/commands/minus-moveright-7382f10/) | command | engine-client | Runs `IN_MoverightUp` in the engine-client module. |
| [`-moveup`](/TaystJK/reference/commands/minus-moveup-356a171/) | command | engine-client | Runs `IN_UpUp` in the engine-client module. |
| [`-right`](/TaystJK/reference/commands/minus-right-a838480/) | command | engine-client | Runs `IN_RightUp` in the engine-client module. |
| [`-scores`](/TaystJK/reference/commands/minus-scores-a8f4d4c/) | command | cgame | Runs `CG_ScoresUp_f` in the cgame module. |
| [`-speed`](/TaystJK/reference/commands/minus-speed-abca6cc/) | command | engine-client | Runs `IN_SpeedUp` in the engine-client module. |
| [`-strafe`](/TaystJK/reference/commands/minus-strafe-fd501b2/) | command | engine-client | Runs `IN_StrafeUp` in the engine-client module. |
| [`-use`](/TaystJK/reference/commands/minus-use-4c6096b/) | command | engine-client | Runs `IN_Button5Up` in the engine-client module. |
| [`-useforce`](/TaystJK/reference/commands/minus-useforce-92d91ec/) | command | engine-client | Runs `IN_Button9Up` in the engine-client module. |
| [`-zoom`](/TaystJK/reference/commands/minus-zoom-972df81/) | command | cgame | Runs `CG_ZoomUp_f` in the cgame module. |
| [`accountInfo`](/TaystJK/reference/commands/accountinfo-e041bfd/) | command | game | Runs `Svcmd_AccountInfo_f` in the game module. |
| [`addbot`](/TaystJK/reference/commands/addbot-fec764b/) | command | cgame | Forwards this command to the connected game server. |
| [`addFavorite`](/TaystJK/reference/commands/addfavorite-26823da/) | command | engine-client | Add server to favorites |
| [`addip`](/TaystJK/reference/commands/addip-5d88fb5/) | command | game | Runs `Svcmd_AddIP_f` in the game module. |
| [`afk`](/TaystJK/reference/commands/afk-aec4e2a/) | command | engine-client | Rename to or from afk |
| [`amBan`](/TaystJK/reference/commands/amban-ac16303/) | command | cgame | Forwards this command to the connected game server. |
| [`amBeg`](/TaystJK/reference/commands/ambeg-ab94735/) | command | cgame | EMOTE |
| [`amBeg2`](/TaystJK/reference/commands/ambeg2-b509e29/) | command | cgame | EMOTE |
| [`amBreakDance`](/TaystJK/reference/commands/ambreakdance-1ce554f/) | command | cgame | EMOTE |
| [`amBreakDance2`](/TaystJK/reference/commands/ambreakdance2-3aab390/) | command | cgame | EMOTE |
| [`amBreakDance3`](/TaystJK/reference/commands/ambreakdance3-e2c5a04/) | command | cgame | EMOTE |
| [`amBreakDance4`](/TaystJK/reference/commands/ambreakdance4-3f4d2e8/) | command | cgame | EMOTE |
| [`amCheer`](/TaystJK/reference/commands/amcheer-e272fa7/) | command | cgame | EMOTE |
| [`amColor`](/TaystJK/reference/commands/amcolor-c9ed5c5/) | command | cgame | Forwards this command to the connected game server. |
| [`amCower`](/TaystJK/reference/commands/amcower-649ad64/) | command | cgame | EMOTE |
| [`amDance`](/TaystJK/reference/commands/amdance-c348eaa/) | command | cgame | EMOTE |
| [`amForceTeam`](/TaystJK/reference/commands/amforceteam-7b44929/) | command | cgame | Forwards this command to the connected game server. |
| [`amFreeze`](/TaystJK/reference/commands/amfreeze-01cf6fd/) | command | cgame | Forwards this command to the connected game server. |
| [`amGrantAdmin`](/TaystJK/reference/commands/amgrantadmin-4e5383a/) | command | cgame | Forwards this command to the connected game server. |
| [`amHug`](/TaystJK/reference/commands/amhug-82335a1/) | command | cgame | EMOTE |
| [`amInfo`](/TaystJK/reference/commands/aminfo-b53555a/) | command | cgame | Forwards this command to the connected game server. |
| [`amKick`](/TaystJK/reference/commands/amkick-2f00271/) | command | cgame | Forwards this command to the connected game server. |
| [`amKillVote`](/TaystJK/reference/commands/amkillvote-267af5c/) | command | cgame | Forwards this command to the connected game server. |
| [`amListMaps`](/TaystJK/reference/commands/amlistmaps-f83ab3c/) | command | cgame | Forwards this command to the connected game server. |
| [`amLockTeam`](/TaystJK/reference/commands/amlockteam-01e4806/) | command | cgame | Forwards this command to the connected game server. |
| [`amLogin`](/TaystJK/reference/commands/amlogin-0aff778/) | command | cgame | Forwards this command to the connected game server. |
| [`amLogout`](/TaystJK/reference/commands/amlogout-da89c31/) | command | cgame | Forwards this command to the connected game server. |
| [`amLookup`](/TaystJK/reference/commands/amlookup-0f303d7/) | command | cgame | Forwards this command to the connected game server. |
| [`amMap`](/TaystJK/reference/commands/ammap-7644e0b/) | command | cgame | Forwards this command to the connected game server. |
| [`amMotd`](/TaystJK/reference/commands/ammotd-5b85bc2/) | command | cgame | Forwards this command to the connected game server. |
| [`amNoisy`](/TaystJK/reference/commands/amnoisy-fa20b9b/) | command | cgame | EMOTE |
| [`amPoint`](/TaystJK/reference/commands/ampoint-58ede89/) | command | cgame | EMOTE |
| [`ampSay`](/TaystJK/reference/commands/ampsay-c91ed51/) | command | cgame | Forwards this command to the connected game server. |
| [`amRage`](/TaystJK/reference/commands/amrage-79d8c3e/) | command | cgame | EMOTE |
| [`amRename`](/TaystJK/reference/commands/amrename-ad31e7c/) | command | cgame | Forwards this command to the connected game server. |
| [`amrun`](/TaystJK/reference/commands/amrun-373fdad/) | command | cgame | EMOTE |
| [`amSay`](/TaystJK/reference/commands/amsay-ef45240/) | command | cgame | Forwards this command to the connected game server. |
| [`amSit`](/TaystJK/reference/commands/amsit-9d81b85/) | command | cgame | EMOTE |
| [`amSit2`](/TaystJK/reference/commands/amsit2-752a391/) | command | cgame | EMOTE |
| [`amSit3`](/TaystJK/reference/commands/amsit3-0cc6070/) | command | cgame | EMOTE |
| [`amSit4`](/TaystJK/reference/commands/amsit4-7ab8b7e/) | command | cgame | EMOTE |
| [`amSit5`](/TaystJK/reference/commands/amsit5-3281f99/) | command | cgame | EMOTE |
| [`amSlap`](/TaystJK/reference/commands/amslap-620092e/) | command | cgame | EMOTE |
| [`amSleep`](/TaystJK/reference/commands/amsleep-18eb1b4/) | command | cgame | EMOTE |
| [`amSmack`](/TaystJK/reference/commands/amsmack-21e8460/) | command | cgame | EMOTE |
| [`amSurrender`](/TaystJK/reference/commands/amsurrender-6e03fd5/) | command | cgame | EMOTE |
| [`amTaunt`](/TaystJK/reference/commands/amtaunt-3b4f992/) | command | cgame | EMOTE |
| [`amTaunt2`](/TaystJK/reference/commands/amtaunt2-e7be334/) | command | cgame | EMOTE |
| [`amTele`](/TaystJK/reference/commands/amtele-cbff2a5/) | command | cgame | Forwards this command to the connected game server. |
| [`amTeleMark`](/TaystJK/reference/commands/amtelemark-456039e/) | command | cgame | Forwards this command to the connected game server. |
| [`amVictory`](/TaystJK/reference/commands/amvictory-d06d5b4/) | command | cgame | EMOTE |
| [`amVstr`](/TaystJK/reference/commands/amvstr-e948c7e/) | command | cgame | Forwards this command to the connected game server. |
| [`amWait`](/TaystJK/reference/commands/amwait-8bd0bc7/) | command | cgame | Forwards this command to the connected game server. |
| [`autoLogin`](/TaystJK/reference/commands/autologin-4739ac0/) | command | cgame | Runs `CG_Autologin_f` in the cgame module. |
| [`automap_button`](/TaystJK/reference/commands/automap_button-769f34b/) | command | engine-client | Show/hide automap |
| [`automap_toggle`](/TaystJK/reference/commands/automap_toggle-31a463a/) | command | engine-client | Show/hide radar |
| [`bind`](/TaystJK/reference/commands/bind-6bdd4db/) | command | engine-client | Bind a key to a console command |
| [`bindlist`](/TaystJK/reference/commands/bindlist-532bd8c/) | command | engine-client | Show all bindings in the console |
| [`blink`](/TaystJK/reference/commands/blink-dcae3a7/) | command | game | Change for admin? |
| [`botlist`](/TaystJK/reference/commands/botlist-5978b77/) | command | game | Runs `Svcmd_BotList_f` in the game module. |
| [`bow`](/TaystJK/reference/commands/bow-fa5bd38/) | command | engine-client | Bow |
| [`briefing`](/TaystJK/reference/commands/briefing-c8e5d02/) | command | cgame | Runs `CG_SiegeBriefing_f` in the cgame module. |
| [`callteamvote`](/TaystJK/reference/commands/callteamvote-308e1e5/) | command | cgame | Forwards this command to the connected game server. |
| [`callvote`](/TaystJK/reference/commands/callvote-1457e21/) | command | cgame | Forwards this command to the connected game server. |
| [`centerview`](/TaystJK/reference/commands/centerview-8b99a94/) | command | engine-client | Centers view on screen |
| [`changePassword`](/TaystJK/reference/commands/changepassword-3dfd458/) | command | cgame | Forwards this command to the connected game server. |
| [`changeVectors`](/TaystJK/reference/commands/changevectors-7f0e466/) | command | engine-shared | Runs `MSG_ReportChangeVectors_f` in the engine-shared module. |
| [`cinematic`](/TaystJK/reference/commands/cinematic-b85c601/) | command | engine-client | Play a cinematic video |
| [`clanAdmin`](/TaystJK/reference/commands/clanadmin-81aa5bc/) | command | cgame | Forwards this command to the connected game server. |
| [`clanCreate`](/TaystJK/reference/commands/clancreate-c8e06da/) | command | cgame | Forwards this command to the connected game server. |
| [`clandelete`](/TaystJK/reference/commands/clandelete-a4890f1/) | command | game | Runs `Svcmd_ClanDelete_f` in the game module. |
| [`clanInfo`](/TaystJK/reference/commands/claninfo-d03453d/) | command | cgame | Forwards this command to the connected game server. |
| [`clanInvite`](/TaystJK/reference/commands/claninvite-0b616bf/) | command | cgame | Forwards this command to the connected game server. |
| [`clanJoin`](/TaystJK/reference/commands/clanjoin-45d4991/) | command | cgame | Forwards this command to the connected game server. |
| [`clankick`](/TaystJK/reference/commands/clankick-2d626df/) | command | game | Runs `Svcmd_ClanKick_f` in the game module. |
| [`clanLeave`](/TaystJK/reference/commands/clanleave-4c3bb60/) | command | cgame | Forwards this command to the connected game server. |
| [`clanList`](/TaystJK/reference/commands/clanlist-0df1c7a/) | command | cgame | Forwards this command to the connected game server. |
| [`clanPass`](/TaystJK/reference/commands/clanpass-e0e73ba/) | command | cgame | Forwards this command to the connected game server. |
| [`clanSay`](/TaystJK/reference/commands/clansay-0ce04c4/) | command | cgame | Forwards this command to the connected game server. |
| [`clanWhoIs`](/TaystJK/reference/commands/clanwhois-fc4d7f9/) | command | cgame | Forwards this command to the connected game server. |
| [`clear`](/TaystJK/reference/commands/clear-168cbb2/) | command | engine-client | Clear console text |
| [`clearIP`](/TaystJK/reference/commands/clearip-92535a0/) | command | game | Runs `Svcmd_ClearIP_f` in the game module. |
| [`clearRemaps`](/TaystJK/reference/commands/clearremaps-10c3c32/) | command | renderer | Runs `R_ClearRemaps_f` in the renderer module. |
| [`clientinfo`](/TaystJK/reference/commands/clientinfo-7674ea7/) | command | engine-client | Prints the userinfo variables |
| [`clientkick`](/TaystJK/reference/commands/clientkick-1dcd5bb/) | command | engine-server | Kick a user from the server by userid |
| [`clientlist`](/TaystJK/reference/commands/clientlist-62d48a1/) | command | cgame | Displays a list of all connected clients and their real client numbers |
| [`cmd`](/TaystJK/reference/commands/cmd-abac361/) | command | engine-client | Forward command to server |
| [`cmdlist`](/TaystJK/reference/commands/cmdlist-2975226/) | command | engine-shared | List all commands to console |
| [`colorname`](/TaystJK/reference/commands/colorname-eccdd14/) | command | engine-client | Color name |
| [`colorstring`](/TaystJK/reference/commands/colorstring-ff62b1e/) | command | engine-client | Color say text |
| [`condump`](/TaystJK/reference/commands/condump-e7b2ba3/) | command | engine-client | Dump console text to file |
| [`configstrings`](/TaystJK/reference/commands/configstrings-3e1b95c/) | command | engine-client | Prints the configstrings list |
| [`connect`](/TaystJK/reference/commands/connect-f11a107/) | command | engine-client | Connect to a server |
| [`coop`](/TaystJK/reference/commands/coop-786e986/) | command | game | Runs `Cmd_Coop_f` in the game module. |
| [`cosmetics`](/TaystJK/reference/commands/cosmetics-01c96cf/) | command | cgame | Runs `CG_Cosmetics_f` in the cgame module. |
| [`crash`](/TaystJK/reference/commands/crash-2fc7f14/) | command | engine-shared | Runs `Com_Crash_f` in the engine-shared module. |
| [`cvar_modified`](/TaystJK/reference/commands/cvar_modified-57ded5d/) | command | engine-shared | Show all modified cvars |
| [`cvar_restart`](/TaystJK/reference/commands/cvar_restart-bad261f/) | command | engine-shared | Resetart the cvar sub-system |
| [`cvarlist`](/TaystJK/reference/commands/cvarlist-5cafd84/) | command | engine-shared | Show all cvars |
| [`DBInfo`](/TaystJK/reference/commands/dbinfo-c214d31/) | command | game | Runs `Svcmd_DBInfo_f` in the game module. |
| [`debugBMove_Back`](/TaystJK/reference/commands/debugbmove_back-8f2da3b/) | command | game | Runs `Cmd_BotMoveBack_f` in the game module. |
| [`debugBMove_Forward`](/TaystJK/reference/commands/debugbmove_forward-250e663/) | command | game | Runs `Cmd_BotMoveForward_f` in the game module. |
| [`debugBMove_Left`](/TaystJK/reference/commands/debugbmove_left-cccb2f7/) | command | game | Runs `Cmd_BotMoveLeft_f` in the game module. |
| [`debugBMove_Right`](/TaystJK/reference/commands/debugbmove_right-e2fea90/) | command | game | Runs `Cmd_BotMoveRight_f` in the game module. |
| [`debugBMove_Up`](/TaystJK/reference/commands/debugbmove_up-17c32c6/) | command | game | Runs `Cmd_BotMoveUp_f` in the game module. |
| [`deleteAccount`](/TaystJK/reference/commands/deleteaccount-1669172/) | command | game | Runs `Svcmd_DeleteAccount_f` in the game module. |
| [`deletedemo`](/TaystJK/reference/commands/deletedemo-4eee4c5/) | command | engine-client | Delete a demo |
| [`demo`](/TaystJK/reference/commands/demo-89e495e/) | command | engine-client | Playback a demo |
| [`demo_restart`](/TaystJK/reference/commands/demo_restart-af89885/) | command | engine-client | Restarts the current or last-played demo |
| [`devmap`](/TaystJK/reference/commands/devmap-504595a/) | command | engine-server | Load a new map with cheats enabled |
| [`devmapall`](/TaystJK/reference/commands/devmapall-afe3bf2/) | command | engine-server | Load a new map with cheats enabled |
| [`devmapmdl`](/TaystJK/reference/commands/devmapmdl-1c9f488/) | command | engine-server | Load a new map with cheats enabled |
| [`dir`](/TaystJK/reference/commands/dir-7ee737c/) | command | engine-shared | Lists a folder |
| [`disconnect`](/TaystJK/reference/commands/disconnect-573bb1c/) | command | engine-client | Disconnect from current server |
| [`do`](/TaystJK/reference/commands/do-eadcd9b/) | command | cgame | Runs `CG_Do_f` in the cgame module. |
| [`duelteam`](/TaystJK/reference/commands/duelteam-50e5f76/) | command | cgame | Forwards this command to the connected game server. |
| [`dumpuser`](/TaystJK/reference/commands/dumpuser-c611573/) | command | engine-server | Prints the userinfo for a given userid |
| [`echo`](/TaystJK/reference/commands/echo-b2d21e7/) | command | engine-shared | Print message to console |
| [`engage_duel`](/TaystJK/reference/commands/engage_duel-7d6992a/) | command | engine-client | Engage private duel |
| [`engage_fullforceduel`](/TaystJK/reference/commands/engage_fullforceduel-d16ab76/) | command | cgame | JAPRO - Serverside - Fullforce Duels |
| [`engage_gunduel`](/TaystJK/reference/commands/engage_gunduel-532ff54/) | command | cgame | JAPRO - Serverside - Fullforce Duels |
| [`entitylist`](/TaystJK/reference/commands/entitylist-f09e360/) | command | game | Runs `Svcmd_EntityList_f` in the game module. |
| [`error`](/TaystJK/reference/commands/error-11f9578/) | command | engine-shared | Runs `Com_Error_f` in the engine-shared module. |
| [`exec`](/TaystJK/reference/commands/exec-be62562/) | command | engine-shared | Execute a script file |
| [`execq`](/TaystJK/reference/commands/execq-48c51d3/) | command | engine-shared | Execute a script file without displaying a message |
| [`exit`](/TaystJK/reference/commands/exit-de3ac21/) | command | engine-shared | Exits the game |
| [`fdir`](/TaystJK/reference/commands/fdir-92fe679/) | command | engine-shared | Lists a folder with filters |
| [`flagAccount`](/TaystJK/reference/commands/flagaccount-eeeecbc/) | command | game | Runs `Svcmd_FlagAccount_f` in the game module. |
| [`flourish`](/TaystJK/reference/commands/flourish-21b9dd7/) | command | engine-client | Flourish |
| [`follow`](/TaystJK/reference/commands/follow-f7ac253/) | command | cgame | Forwards this command to the connected game server. |
| [`followFastest`](/TaystJK/reference/commands/followfastest-66908f6/) | command | cgame | Runs `CG_FollowFastest_f` in the cgame module. |
| [`follownext`](/TaystJK/reference/commands/follownext-a152e2f/) | command | cgame | Forwards this command to the connected game server. |
| [`followprev`](/TaystJK/reference/commands/followprev-c5dcaa8/) | command | cgame | Forwards this command to the connected game server. |
| [`fontlist`](/TaystJK/reference/commands/fontlist-83422e5/) | command | renderer | Runs `R_FontList_f` in the renderer module. |
| [`force_absorb`](/TaystJK/reference/commands/force_absorb-0b8047d/) | command | engine-client | Activate absorb force power |
| [`force_distract`](/TaystJK/reference/commands/force_distract-32b60fc/) | command | engine-client | Activate mind trick force power |
| [`force_forcepowerother`](/TaystJK/reference/commands/force_forcepowerother-7b26c1e/) | command | engine-client | Use team energize force power |
| [`force_heal`](/TaystJK/reference/commands/force_heal-cff3f13/) | command | engine-client | Use heal force power |
| [`force_healother`](/TaystJK/reference/commands/force_healother-9a5aae1/) | command | engine-client | Use team heal force power |
| [`force_protect`](/TaystJK/reference/commands/force_protect-f7b9159/) | command | engine-client | Activate protect force power |
| [`force_pull`](/TaystJK/reference/commands/force_pull-093ee7c/) | command | engine-client | Use pull force power |
| [`force_rage`](/TaystJK/reference/commands/force_rage-195552c/) | command | engine-client | Activate rage force power |
| [`force_seeing`](/TaystJK/reference/commands/force_seeing-8ebdec1/) | command | engine-client | Activate seeing force power |
| [`force_speed`](/TaystJK/reference/commands/force_speed-3cc9b2a/) | command | engine-client | Activate speed force power |
| [`force_throw`](/TaystJK/reference/commands/force_throw-bcc93db/) | command | engine-client | Use push force power |
| [`forcechanged`](/TaystJK/reference/commands/forcechanged-6b7cd08/) | command | cgame | Forwards this command to the connected game server. |
| [`forcenext`](/TaystJK/reference/commands/forcenext-f6f1a66/) | command | cgame | Runs `CG_NextForcePower_f` in the cgame module. |
| [`forcepowers`](/TaystJK/reference/commands/forcepowers-5f9594f/) | command | engine-client | Runs `CL_SetForcePowers_f` in the engine-client module. |
| [`forceprev`](/TaystJK/reference/commands/forceprev-2ea0d1f/) | command | cgame | Runs `CG_PrevForcePower_f` in the cgame module. |
| [`forceteam`](/TaystJK/reference/commands/forceteam-72a2634/) | command | game | Runs `Svcmd_ForceTeam_f` in the game module. |
| [`forcetoggle`](/TaystJK/reference/commands/forcetoggle-374647c/) | command | engine-server | Toggle g_forcePowerDisable bits |
| [`freeze`](/TaystJK/reference/commands/freeze-adcdee7/) | command | engine-shared | Runs `Com_Freeze_f` in the engine-shared module. |
| [`fs_openedList`](/TaystJK/reference/commands/fs_openedlist-9ff8bba/) | command | engine-client | Lists open pak files |
| [`fs_referencedList`](/TaystJK/reference/commands/fs_referencedlist-593622e/) | command | engine-client | Lists referenced pak files |
| [`fs_restart`](/TaystJK/reference/commands/fs_restart-205ee49/) | command | engine-shared | Restarts the filesystem if no module is currently using files from a pk3 |
| [`game_memory`](/TaystJK/reference/commands/game_memory-84c83cc/) | command | game | Runs `Svcmd_GameMem_f` in the game module. |
| [`gametype`](/TaystJK/reference/commands/gametype-d7c6fe6/) | command | game | Instantly changethe gametype of the server without having to reload the map |
| [`gc`](/TaystJK/reference/commands/gc-ec6d908/) | command | game | Runs `Cmd_GameCommand_f` in the game module. |
| [`gfxinfo`](/TaystJK/reference/commands/gfxinfo-5473f68/) | command | renderer | Runs `GfxInfo_f` in the renderer module. |
| [`gfxmeminfo`](/TaystJK/reference/commands/gfxmeminfo-491be17/) | command | renderer | Runs `GfxMemInfo_f` in the renderer module. |
| [`give`](/TaystJK/reference/commands/give-fa9f22e/) | command | cgame | Forwards this command to the connected game server. |
| [`giveother`](/TaystJK/reference/commands/giveother-c475c5c/) | command | game | Runs `Cmd_GiveOther_f` in the game module. |
| [`gloat`](/TaystJK/reference/commands/gloat-45e2110/) | command | engine-client | Gloat |
| [`globalservers`](/TaystJK/reference/commands/globalservers-ed6c115/) | command | engine-client | Query the masterserver for serverlist |
| [`god`](/TaystJK/reference/commands/god-21298df/) | command | cgame | Forwards this command to the connected game server. |
| [`haste`](/TaystJK/reference/commands/haste-08a06a9/) | command | game | Runs `Cmd_Haste_f` in the game module. |
| [`heartbeat`](/TaystJK/reference/commands/heartbeat-a7a5b07/) | command | engine-server | Sends a heartbeat to the masterserver |
| [`help`](/TaystJK/reference/commands/help-92005ec/) | command | cgame | Print command help |
| [`hide`](/TaystJK/reference/commands/hide-93c8c96/) | command | cgame | Forwards this command to the connected game server. |
| [`ignore`](/TaystJK/reference/commands/ignore-8ccbde8/) | command | cgame | [JAPRO - Serverside - All - Ignore] |
| [`ignoreVGS`](/TaystJK/reference/commands/ignorevgs-46dc77b/) | command | cgame | Runs `CG_IgnoreVGS_f` in the cgame module. |
| [`imagecacheinfo`](/TaystJK/reference/commands/imagecacheinfo-a198210/) | command | renderer | Runs `RE_RegisterImages_Info_f` in the renderer module. |
| [`imagelist`](/TaystJK/reference/commands/imagelist-4c06ba7/) | command | renderer | Runs `R_ImageList_f` in the renderer module. |
| [`in_restart`](/TaystJK/reference/commands/in_restart-b75c16f/) | command | engine-shared | Runs `IN_Restart` in the engine-shared module. |
| [`invnext`](/TaystJK/reference/commands/invnext-3271b96/) | command | cgame | Runs `CG_NextInventory_f` in the cgame module. |
| [`invprev`](/TaystJK/reference/commands/invprev-e6081df/) | command | cgame | Runs `CG_PrevInventory_f` in the cgame module. |
| [`jetpack`](/TaystJK/reference/commands/jetpack-806aec3/) | command | game | Runs `Cmd_Jetpack_f` in the game module. |
| [`jump`](/TaystJK/reference/commands/jump-271e9a5/) | command | cgame | Cmd_alive not needed but i think it resets on joingame cuz forcepoints? |
| [`kick`](/TaystJK/reference/commands/kick-eac6136/) | command | engine-server | Kick a user from the server |
| [`kickall`](/TaystJK/reference/commands/kickall-7a42f1a/) | command | engine-server | Kick all users from the server |
| [`kickbots`](/TaystJK/reference/commands/kickbots-9695bdf/) | command | engine-server | Kick all bots from the server |
| [`kicknum`](/TaystJK/reference/commands/kicknum-43bb6d1/) | command | engine-server | Kick a user from the server by userid |
| [`kill`](/TaystJK/reference/commands/kill-c80f5bc/) | command | cgame | Forwards this command to the connected game server. |
| [`killother`](/TaystJK/reference/commands/killother-c24ec29/) | command | game | Runs `Cmd_KillOther_f` in the game module. |
| [`killserver`](/TaystJK/reference/commands/killserver-41205ad/) | command | engine-server | Shuts the server down and disconnects all clients |
| [`launch`](/TaystJK/reference/commands/launch-f7c91fe/) | command | cgame | Forwards this command to the connected game server. |
| [`levelshot`](/TaystJK/reference/commands/levelshot-eb585e1/) | command | cgame | Forwards this command to the connected game server. |
| [`listAdmins`](/TaystJK/reference/commands/listadmins-135e048/) | command | game | Runs `Svcmd_ListAdmins_f` in the game module. |
| [`listip`](/TaystJK/reference/commands/listip-3cf3e51/) | command | game | Runs `Svcmd_ListIP_f` in the game module. |
| [`listRemaps`](/TaystJK/reference/commands/listremaps-ccb7058/) | command | cgame | Runs `CG_ListRemaps_f` in the cgame module. |
| [`loaddefered`](/TaystJK/reference/commands/loaddefered-b9476e3/) | command | cgame | Forwards this command to the connected game server. |
| [`loaddeferred`](/TaystJK/reference/commands/loaddeferred-a84ce37/) | command | cgame | Runs `CG_LoadDeferredPlayers` in the cgame module. |
| [`loadhud`](/TaystJK/reference/commands/loadhud-0e6c052/) | command | cgame | Runs `CG_LoadHud_f` in the cgame module. |
| [`localservers`](/TaystJK/reference/commands/localservers-05d352f/) | command | engine-client | Query LAN for local servers |
| [`login`](/TaystJK/reference/commands/login-2736fab/) | command | cgame | Forwards this command to the connected game server. |
| [`logout`](/TaystJK/reference/commands/logout-55525e1/) | command | cgame | Forwards this command to the connected game server. |
| [`lowjump`](/TaystJK/reference/commands/lowjump-5afc6c0/) | command | cgame | Runs `CG_Lowjump_f` in the cgame module. |
| [`map`](/TaystJK/reference/commands/map-37745ed/) | command | engine-server | Load a new map with cheats disabled |
| [`map_restart`](/TaystJK/reference/commands/map_restart-459d49e/) | command | engine-server | Restart the current map |
| [`mapents`](/TaystJK/reference/commands/mapents-8844ab0/) | command | game | Runs `Cmd_MapEnts_f` in the game module. |
| [`master`](/TaystJK/reference/commands/master-4f26aea/) | command | cgame | Forwards this command to the connected game server. |
| [`masterlist`](/TaystJK/reference/commands/masterlist-96e0292/) | command | cgame | Forwards this command to the connected game server. |
| [`meditate`](/TaystJK/reference/commands/meditate-3d54153/) | command | engine-client | Meditate |
| [`messagemode`](/TaystJK/reference/commands/messagemode-ac88b44/) | command | engine-client | Global Chat |
| [`messagemode2`](/TaystJK/reference/commands/messagemode2-a3239c0/) | command | engine-client | Team Chat |
| [`messagemode3`](/TaystJK/reference/commands/messagemode3-5125f31/) | command | engine-client | Private Chat with Target Player |
| [`messagemode4`](/TaystJK/reference/commands/messagemode4-e7ebdc0/) | command | engine-client | Private Chat with Last Attacker |
| [`minimize`](/TaystJK/reference/commands/minimize-0c3639c/) | command | engine-shared | Runs `GLimp_Minimize` in the engine-shared module. |
| [`mnext`](/TaystJK/reference/commands/mnext-858b638/) | command | engine-shared | Send the next-track media key on Windows. |
| [`model`](/TaystJK/reference/commands/model-1d06a0d/) | command | engine-client | Set the player model |
| [`modelcacheinfo`](/TaystJK/reference/commands/modelcacheinfo-86baf55/) | command | renderer | Runs `RE_RegisterModels_Info_f` in the renderer module. |
| [`modelist`](/TaystJK/reference/commands/modelist-5c7e939/) | command | engine-shared | Runs `R_ModeList_f` in the engine-shared module. |
| [`modellist`](/TaystJK/reference/commands/modellist-858000a/) | command | renderer | Runs `R_Modellist_f` in the renderer module. |
| [`modversion`](/TaystJK/reference/commands/modversion-73dac73/) | command | cgame | Runs `CG_ModVersion_f` in the cgame module. |
| [`move`](/TaystJK/reference/commands/move-379d6ce/) | command | cgame | Forwards this command to the connected game server. |
| [`mp3_calcvols`](/TaystJK/reference/commands/mp3_calcvols-80b9f54/) | command | engine-client | Runs `S_MP3_CalcVols_f` in the engine-client module. |
| [`mpause`](/TaystJK/reference/commands/mpause-640e429/) | command | engine-shared | Send the play/pause media key on Windows. |
| [`mprev`](/TaystJK/reference/commands/mprev-28fb883/) | command | engine-shared | Send the previous-track media key on Windows. |
| [`mstop`](/TaystJK/reference/commands/mstop-67745cd/) | command | engine-shared | Send the stop-media key on Windows. |
| [`music`](/TaystJK/reference/commands/music-3a01be1/) | command | engine-client | Plays a music file |
| [`net_restart`](/TaystJK/reference/commands/net_restart-defef06/) | command | engine-shared | Restart the networking sub-system |
| [`nextframe`](/TaystJK/reference/commands/nextframe-23b6320/) | command | cgame | Runs `CG_TestModelNextFrame_f` in the cgame module. |
| [`nextskin`](/TaystJK/reference/commands/nextskin-4ecdde3/) | command | cgame | Runs `CG_TestModelNextSkin_f` in the cgame module. |
| [`noclip`](/TaystJK/reference/commands/noclip-9bf6a6e/) | command | cgame | Change for admin? |
| [`notarget`](/TaystJK/reference/commands/notarget-ec14eef/) | command | cgame | Forwards this command to the connected game server. |
| [`NPC`](/TaystJK/reference/commands/npc-3b86d7d/) | command | cgame | Removed cheat for admin //meh let us npc kill all from spec |
| [`nudge`](/TaystJK/reference/commands/nudge-37e4ac9/) | command | game | Runs `Cmd_Nudge_f` in the game module. |
| [`pack`](/TaystJK/reference/commands/pack-6acd621/) | command | game | Runs `Cmd_TribesPack_f` in the game module. |
| [`path`](/TaystJK/reference/commands/path-3150ecd/) | command | engine-shared | Lists search paths |
| [`ping`](/TaystJK/reference/commands/ping-572982b/) | command | engine-client | Ping a server for info response |
| [`play`](/TaystJK/reference/commands/play-516626b/) | command | engine-client | Plays a sound fx file |
| [`playdemo`](/TaystJK/reference/commands/playdemo-eb741af/) | command | engine-client | Playback a demo |
| [`plugin`](/TaystJK/reference/commands/plugin-fd8c7c8/) | command | cgame | Runs `CG_PluginDisable_f` in the cgame module. |
| [`pluginDisable`](/TaystJK/reference/commands/plugindisable-98b2c24/) | command | cgame | Runs `CG_PluginDisable_f` in the cgame module. |
| [`practice`](/TaystJK/reference/commands/practice-e17674f/) | command | cgame | Forwards this command to the connected game server. |
| [`prevframe`](/TaystJK/reference/commands/prevframe-67fc671/) | command | cgame | Runs `CG_TestModelPrevFrame_f` in the cgame module. |
| [`prevskin`](/TaystJK/reference/commands/prevskin-d9924ca/) | command | cgame | Runs `CG_TestModelPrevSkin_f` in the cgame module. |
| [`print`](/TaystJK/reference/commands/print-6d0d587/) | command | engine-shared | Print cvar help |
| [`printStats`](/TaystJK/reference/commands/printstats-482f44d/) | command | cgame | Forwards this command to the connected game server. |
| [`quit`](/TaystJK/reference/commands/quit-f591187/) | command | engine-shared | Quits the game |
| [`r_atihack`](/TaystJK/reference/commands/r_atihack-d43dcf7/) | command | renderer | Runs `R_AtiHackToggle_f` in the renderer module. |
| [`r_cleardecals`](/TaystJK/reference/commands/r_cleardecals-243dbd7/) | command | renderer | Runs `RE_ClearDecals` in the renderer module. |
| [`r_we`](/TaystJK/reference/commands/r_we-8921bfa/) | command | renderer | Runs `R_WorldEffect_f` in the renderer module. |
| [`race`](/TaystJK/reference/commands/race-de4bedc/) | command | cgame | Forwards this command to the connected game server. |
| [`rCompare`](/TaystJK/reference/commands/rcompare-e6c9345/) | command | game | Runs `Cmd_DFCompare_f` in the game module. |
| [`rcon`](/TaystJK/reference/commands/rcon-d2ea1a2/) | command | engine-client | Execute commands remotely to a server |
| [`rebuildElo`](/TaystJK/reference/commands/rebuildelo-eed7ec9/) | command | game | Delete all Elo records and rebuild them from the duel records in the database. |
| [`rebuildRaces`](/TaystJK/reference/commands/rebuildraces-de93639/) | command | game | Runs `SV_RebuildRaceRanks_f` in the game module. |
| [`rebuildUnlocks`](/TaystJK/reference/commands/rebuildunlocks-9112329/) | command | game | Runs `SV_RebuildUnlocks_f` in the game module. |
| [`reconnect`](/TaystJK/reference/commands/reconnect-4804f69/) | command | engine-client | Reconnect to current server |
| [`record`](/TaystJK/reference/commands/record-275a700/) | command | engine-client | Record a demo |
| [`register`](/TaystJK/reference/commands/register-13a2828/) | command | cgame | Forwards this command to the connected game server. |
| [`remapShader`](/TaystJK/reference/commands/remapshader-5315061/) | command | cgame | Runs `CG_RemapShader_f` in the cgame module. |
| [`remapSky`](/TaystJK/reference/commands/remapsky-55c2535/) | command | renderer | Runs `R_RemapSkyShader_f` in the renderer module. |
| [`removeip`](/TaystJK/reference/commands/removeip-38af509/) | command | game | Runs `Svcmd_RemoveIP_f` in the game module. |
| [`renameAccount`](/TaystJK/reference/commands/renameaccount-3fd6fd7/) | command | game | Runs `Svcmd_RenameAccount_f` in the game module. |
| [`reset`](/TaystJK/reference/commands/reset-91ef0c1/) | command | engine-shared | Reset a cvar to default |
| [`resetScores`](/TaystJK/reference/commands/resetscores-5efac86/) | command | game | Reset all player/team scores without having to reload the map. |
| [`rFind`](/TaystJK/reference/commands/rfind-f2fd376/) | command | cgame | Forwards this command to the connected game server. |
| [`rHardest`](/TaystJK/reference/commands/rhardest-4250c13/) | command | cgame | Forwards this command to the connected game server. |
| [`rLatest`](/TaystJK/reference/commands/rlatest-fa0c7ce/) | command | cgame | Forwards this command to the connected game server. |
| [`rocketChange`](/TaystJK/reference/commands/rocketchange-f69e6d8/) | command | cgame | Forwards this command to the connected game server. |
| [`rPopular`](/TaystJK/reference/commands/rpopular-a69422f/) | command | cgame | Forwards this command to the connected game server. |
| [`rRank`](/TaystJK/reference/commands/rrank-4a8ddea/) | command | cgame | Forwards this command to the connected game server. |
| [`rTop`](/TaystJK/reference/commands/rtop-56f7fba/) | command | cgame | Forwards this command to the connected game server. |
| [`rWorst`](/TaystJK/reference/commands/rworst-00fab73/) | command | cgame | Forwards this command to the connected game server. |
| [`s_dynamic`](/TaystJK/reference/commands/s_dynamic-2255330/) | command | engine-client | Change dynamic music state |
| [`saber`](/TaystJK/reference/commands/saber-1b60697/) | command | cgame | Runs `CG_Saber_f` in the cgame module. |
| [`saberAttackCycle`](/TaystJK/reference/commands/saberattackcycle-697e64e/) | command | engine-client | Switch lightsaber attack styles |
| [`saberColor`](/TaystJK/reference/commands/sabercolor-78e6a36/) | command | cgame | Forwards this command to the connected game server. |
| [`say`](/TaystJK/reference/commands/say-dc01c6b/) | command | cgame | Forwards this command to the connected game server. |
| [`say_team`](/TaystJK/reference/commands/say_team-bae6793/) | command | cgame | Forwards this command to the connected game server. |
| [`say_team_mod`](/TaystJK/reference/commands/say_team_mod-1d67bc8/) | command | cgame | Forwards this command to the connected game server. |
| [`score`](/TaystJK/reference/commands/score-75ebcb3/) | command | game | Runs `Cmd_Score_f` in the game module. |
| [`screenshot`](/TaystJK/reference/commands/screenshot-754d2e9/) | command | renderer | Runs `R_ScreenShotJPEG_f` in the renderer module. |
| [`screenshot_png`](/TaystJK/reference/commands/screenshot_png-78032a6/) | command | renderer | Runs `R_ScreenShotPNG_f` in the renderer module. |
| [`screenshot_tga`](/TaystJK/reference/commands/screenshot_tga-0b6a900/) | command | renderer | Runs `R_ScreenShotTGA_f` in the renderer module. |
| [`sectorlist`](/TaystJK/reference/commands/sectorlist-5e02669/) | command | engine-server | Runs `SV_SectorList_f` in the engine-server module. |
| [`serverconfig`](/TaystJK/reference/commands/serverconfig-ee5ed61/) | command | cgame | Runs `CG_ServerConfig_f` in the cgame module. |
| [`serverinfo`](/TaystJK/reference/commands/serverinfo-f96dbe5/) | command | engine-server | Prints the serverinfo that is visible in the server browsers |
| [`serverstatus`](/TaystJK/reference/commands/serverstatus-c68767a/) | command | engine-client | Retrieve current or specified server's status |
| [`set`](/TaystJK/reference/commands/set-65c10dc/) | command | engine-shared | Set a cvar |
| [`seta`](/TaystJK/reference/commands/seta-003d6b2/) | command | engine-shared | Set a cvar and apply archive flag |
| [`sets`](/TaystJK/reference/commands/sets-d6c8220/) | command | engine-shared | Set a cvar and apply serverinfo flag |
| [`setu`](/TaystJK/reference/commands/setu-34f073a/) | command | engine-shared | Set a cvar and apply userinfo flag |
| [`setviewpos`](/TaystJK/reference/commands/setviewpos-9e094d1/) | command | cgame | Wow really?? |
| [`shaderlist`](/TaystJK/reference/commands/shaderlist-a425a58/) | command | renderer | Runs `R_ShaderList_f` in the renderer module. |
| [`showip`](/TaystJK/reference/commands/showip-b32e57a/) | command | engine-client | Shows local IP |
| [`showNet`](/TaystJK/reference/commands/shownet-4d0ae0e/) | command | cgame | Forwards this command to the connected game server. |
| [`siegeclass`](/TaystJK/reference/commands/siegeclass-3ba0852/) | command | cgame | Forwards this command to the connected game server. |
| [`siegeCompleteCvarUpdate`](/TaystJK/reference/commands/siegecompletecvarupdate-73dd2e9/) | command | cgame | Runs `CG_SiegeCompleteCvarUpdate_f` in the cgame module. |
| [`siegeCvarUpdate`](/TaystJK/reference/commands/siegecvarupdate-85c4442/) | command | cgame | Runs `CG_SiegeCvarUpdate_f` in the cgame module. |
| [`sizedown`](/TaystJK/reference/commands/sizedown-b787541/) | command | cgame | Runs `CG_SizeDown_f` in the cgame module. |
| [`sizeup`](/TaystJK/reference/commands/sizeup-fb872d7/) | command | cgame | Runs `CG_SizeUp_f` in the cgame module. |
| [`skinlist`](/TaystJK/reference/commands/skinlist-f37b889/) | command | renderer | Runs `R_SkinList_f` in the renderer module. |
| [`slot`](/TaystJK/reference/commands/slot-462854f/) | command | cgame | Runs `CG_WeaponSlot_f` in the cgame module. |
| [`snd_restart`](/TaystJK/reference/commands/snd_restart-2a53ec1/) | command | engine-client | Restart sound |
| [`soundinfo`](/TaystJK/reference/commands/soundinfo-489bbde/) | command | engine-client | Display information about the sound backend |
| [`soundlist`](/TaystJK/reference/commands/soundlist-c42d7c8/) | command | engine-client | Lists all cached sound and music files |
| [`soundstop`](/TaystJK/reference/commands/soundstop-6d48fc3/) | command | engine-client | Stops all sounds including music |
| [`speedometer`](/TaystJK/reference/commands/speedometer-b0e26e4/) | command | cgame | Runs `CG_SpeedometerSettings_f` in the cgame module. |
| [`spot`](/TaystJK/reference/commands/spot-9f4b527/) | command | cgame | Forwards this command to the connected game server. |
| [`startingWeapons`](/TaystJK/reference/commands/startingweapons-7252a71/) | command | game | Runs `Svcmd_ToggleStartingWeapons_f` in the game module. |
| [`startOrbit`](/TaystJK/reference/commands/startorbit-4e02c93/) | command | cgame | Runs `CG_StartOrbit_f` in the cgame module. |
| [`stats`](/TaystJK/reference/commands/stats-e350d5c/) | command | cgame | Rename to info? |
| [`status`](/TaystJK/reference/commands/status-48a3661/) | command | engine-server | Prints status of server and connected clients |
| [`stopmusic`](/TaystJK/reference/commands/stopmusic-38c05b1/) | command | engine-client | Stops all music |
| [`stoprecord`](/TaystJK/reference/commands/stoprecord-c5a4a3b/) | command | engine-client | Stop recording a demo |
| [`stopvideo`](/TaystJK/reference/commands/stopvideo-db7ecec/) | command | engine-client | Stop avi recording |
| [`strafeHelper`](/TaystJK/reference/commands/strafehelper-bdb34b4/) | command | cgame | Runs `CG_StrafeHelper_f` in the cgame module. |
| [`strafeTrail`](/TaystJK/reference/commands/strafetrail-dddd025/) | command | cgame | Runs `CG_AddStrafeTrail_f` in the cgame module. |
| [`stylePlayer`](/TaystJK/reference/commands/styleplayer-33ef966/) | command | cgame | Runs `CG_StylePlayer_f` in the cgame module. |
| [`sv_banaddr`](/TaystJK/reference/commands/sv_banaddr-5213a27/) | command | engine-server | Bans a user |
| [`sv_bandel`](/TaystJK/reference/commands/sv_bandel-d30e97f/) | command | engine-server | Removes a ban |
| [`sv_exceptaddr`](/TaystJK/reference/commands/sv_exceptaddr-8c8c6e0/) | command | engine-server | Adds a ban exception for a user |
| [`sv_exceptdel`](/TaystJK/reference/commands/sv_exceptdel-8577ae8/) | command | engine-server | Removes a ban exception |
| [`sv_flushbans`](/TaystJK/reference/commands/sv_flushbans-884a191/) | command | engine-server | Removes all bans and exceptions |
| [`sv_listbans`](/TaystJK/reference/commands/sv_listbans-720c4f8/) | command | engine-server | Lists bans |
| [`sv_listrecording`](/TaystJK/reference/commands/sv_listrecording-21f40d6/) | command | engine-server | Lists demos being recorded |
| [`sv_rehashbans`](/TaystJK/reference/commands/sv_rehashbans-6f9f69f/) | command | engine-server | Reloads banlist from file |
| [`sv_saberswitch`](/TaystJK/reference/commands/sv_saberswitch-575de87/) | command | engine-client | Holster/activate lightsaber |
| [`svdemoclearmeta`](/TaystJK/reference/commands/svdemoclearmeta-0b51781/) | command | engine-server | Clears metadata for server-side demos for one player. Call with clientnum. |
| [`svdemoclearprerecord`](/TaystJK/reference/commands/svdemoclearprerecord-4d3a794/) | command | engine-server | Clears pre-record data for a particular client. Call with clientnum. |
| [`svdemometa`](/TaystJK/reference/commands/svdemometa-0715ee6/) | command | engine-server | Sets a new metadata entry for server-side demos for one player. Call with clientnum, metakey, [data] |
| [`svrecord`](/TaystJK/reference/commands/svrecord-96937de/) | command | engine-server | Record a server-side demo |
| [`svrenamedemo`](/TaystJK/reference/commands/svrenamedemo-6d02cec/) | command | engine-server | Rename a server-side demo |
| [`svsay`](/TaystJK/reference/commands/svsay-f417790/) | command | engine-server | Broadcast server messages to clients |
| [`svstoprecord`](/TaystJK/reference/commands/svstoprecord-b9ffafa/) | command | engine-server | Stop recording a server-side demo |
| [`svtell`](/TaystJK/reference/commands/svtell-f8cd34e/) | command | engine-server | Private message from the server to a user |
| [`systeminfo`](/TaystJK/reference/commands/systeminfo-21ef9f0/) | command | engine-server | Prints the systeminfo variables that are replicated to clients |
| [`t_use`](/TaystJK/reference/commands/t_use-2d01a2e/) | command | game | Runs `Cmd_TargetUse_f` in the game module. |
| [`taunt`](/TaystJK/reference/commands/taunt-ad6071a/) | command | engine-client | Taunt |
| [`tcmd`](/TaystJK/reference/commands/tcmd-f9ee575/) | command | cgame | Runs `CG_TargetCommand_f` in the cgame module. |
| [`team`](/TaystJK/reference/commands/team-d25187d/) | command | cgame | Forwards this command to the connected game server. |
| [`teamtask`](/TaystJK/reference/commands/teamtask-e766c1c/) | command | cgame | Forwards this command to the connected game server. |
| [`teamvote`](/TaystJK/reference/commands/teamvote-7ffad1d/) | command | cgame | Forwards this command to the connected game server. |
| [`tell`](/TaystJK/reference/commands/tell-47b8015/) | command | cgame | Forwards this command to the connected game server. |
| [`tell_attacker`](/TaystJK/reference/commands/tell_attacker-317094f/) | command | cgame | Runs `CG_TellAttacker_f` in the cgame module. |
| [`tell_target`](/TaystJK/reference/commands/tell_target-5cabe4a/) | command | cgame | Runs `CG_TellTarget_f` in the cgame module. |
| [`testBSP`](/TaystJK/reference/commands/testbsp-22b895a/) | command | game | Runs `Cmd_TestBSP_f` in the game module. |
| [`testgun`](/TaystJK/reference/commands/testgun-3d13933/) | command | cgame | Runs `CG_TestGun_f` in the cgame module. |
| [`testmodel`](/TaystJK/reference/commands/testmodel-8452360/) | command | cgame | Runs `CG_TestModel_f` in the cgame module. |
| [`thedestroyer`](/TaystJK/reference/commands/thedestroyer-eb1d67f/) | command | game | Runs `Cmd_TheDestroyer_f` in the game module. |
| [`throwflag`](/TaystJK/reference/commands/throwflag-d12a8a7/) | command | game | Runs `Cmd_Throwflag_f` in the game module. |
| [`thrownade`](/TaystJK/reference/commands/thrownade-ab0fd85/) | command | game | Runs `Cmd_ThrowNade_f` in the game module. |
| [`toggle`](/TaystJK/reference/commands/toggle-f9c5942/) | command | engine-shared | Toggle a cvar between values |
| [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/) | command | game | Runs `Svcmd_ToggleAdmin_f` in the game module. |
| [`toggleallowvote`](/TaystJK/reference/commands/toggleallowvote-3e2cc73/) | command | game | Runs `Svcmd_ToggleAllowVote_f` in the game module. |
| [`toggleconsole`](/TaystJK/reference/commands/toggleconsole-6bc1984/) | command | engine-client | Show/hide console |
| [`togglemenu`](/TaystJK/reference/commands/togglemenu-8971d97/) | command | engine-client | Show/hide the menu |
| [`toggleuserinfovalidation`](/TaystJK/reference/commands/toggleuserinfovalidation-f54be87/) | command | game | Runs `Svcmd_ToggleUserinfoValidation_f` in the game module. |
| [`top`](/TaystJK/reference/commands/top-af2c7b4/) | command | cgame | Forwards this command to the connected game server. |
| [`touchFile`](/TaystJK/reference/commands/touchfile-c9c117f/) | command | engine-shared | Touches a file |
| [`trace`](/TaystJK/reference/commands/trace-d0fa554/) | command | game | Runs `Cmd_Trace_f` in the game module. |
| [`tweakWeapons`](/TaystJK/reference/commands/tweakweapons-fd5860d/) | command | game | Runs `Svcmd_ToggleTweakWeapons_f` in the game module. |
| [`ui_cache`](/TaystJK/reference/commands/ui_cache-3e1b71d/) | command | ui | Runs `UI_Cache_f` in the ui module. |
| [`ui_load`](/TaystJK/reference/commands/ui_load-b884bdc/) | command | ui | Runs `UI_Load` in the ui module. |
| [`ui_modversion`](/TaystJK/reference/commands/ui_modversion-a282cdc/) | command | ui | Runs `UI_Modversion_f` in the ui module. |
| [`ui_openmenu`](/TaystJK/reference/commands/ui_openmenu-e42ca8c/) | command | ui | Runs `UI_OpenMenu_f` in the ui module. |
| [`ui_opensiegemenu`](/TaystJK/reference/commands/ui_opensiegemenu-a05b9b7/) | command | ui | Runs `UI_OpenSiegeMenu_f` in the ui module. |
| [`ui_report`](/TaystJK/reference/commands/ui_report-71f7773/) | command | ui | Runs `UI_Report` in the ui module. |
| [`unbind`](/TaystJK/reference/commands/unbind-bd02d99/) | command | engine-client | Unbind a key |
| [`unbindall`](/TaystJK/reference/commands/unbindall-b3cc407/) | command | engine-client | Delete all key bindings |
| [`unset`](/TaystJK/reference/commands/unset-fff210f/) | command | engine-shared | Unset a user generated cvar |
| [`use_ammodisp`](/TaystJK/reference/commands/use_ammodisp-810eb71/) | command | engine-client | Use ammo dispenser item |
| [`use_bacta`](/TaystJK/reference/commands/use_bacta-7089dec/) | command | engine-client | Use bacta item |
| [`use_bactabig`](/TaystJK/reference/commands/use_bactabig-8fd2bb4/) | command | engine-client | Use big bacta item |
| [`use_cloak`](/TaystJK/reference/commands/use_cloak-c0010e3/) | command | engine-client | Use cloaking item |
| [`use_electrobinoculars`](/TaystJK/reference/commands/use_electrobinoculars-063880a/) | command | engine-client | Use electro binoculars item |
| [`use_eweb`](/TaystJK/reference/commands/use_eweb-6133779/) | command | engine-client | Use e-web item |
| [`use_field`](/TaystJK/reference/commands/use_field-f612ae1/) | command | engine-client | Use forcefield item |
| [`use_healthdisp`](/TaystJK/reference/commands/use_healthdisp-fb0fdc0/) | command | engine-client | Use health dispenser item |
| [`use_jetpack`](/TaystJK/reference/commands/use_jetpack-c2c0671/) | command | engine-client | Use jetpack item |
| [`use_seeker`](/TaystJK/reference/commands/use_seeker-703d2b8/) | command | engine-client | Use seeker drone item |
| [`use_sentry`](/TaystJK/reference/commands/use_sentry-d6cc429/) | command | engine-client | Use sentry gun item |
| [`useGivenForce`](/TaystJK/reference/commands/usegivenforce-9c1fc93/) | command | engine-client | Use specified force power |
| [`userinfo`](/TaystJK/reference/commands/userinfo-c0214b8/) | command | engine-client | Runs `CL_Clientinfo_f` in the engine-client module. |
| [`vbolist`](/TaystJK/reference/commands/vbolist-fe10c4e/) | command | renderer | Runs `R_VBOList_f` in the renderer module. |
| [`vgs_cmd`](/TaystJK/reference/commands/vgs_cmd-98de8a4/) | command | cgame | Vgs |
| [`vid_restart`](/TaystJK/reference/commands/vid_restart-46d32d0/) | command | engine-client | Restart the renderer - or change the resolution |
| [`video`](/TaystJK/reference/commands/video-ffbaf58/) | command | engine-client | Record demo to avi |
| [`viewpos`](/TaystJK/reference/commands/viewpos-f7d1e6b/) | command | cgame | Runs `CG_Viewpos_f` in the cgame module. |
| [`vkinfo`](/TaystJK/reference/commands/vkinfo-a9a6314/) | command | renderer | Runs `vk_info_f` in the renderer module. |
| [`voice_cmd`](/TaystJK/reference/commands/voice_cmd-3d7f601/) | command | cgame | Forwards this command to the connected game server. |
| [`voicechat`](/TaystJK/reference/commands/voicechat-a1c96f1/) | command | engine-client | Open voice chat menu |
| [`vote`](/TaystJK/reference/commands/vote-fd63f1e/) | command | cgame | Forwards this command to the connected game server. |
| [`vstr`](/TaystJK/reference/commands/vstr-aad114e/) | command | engine-shared | Execute the value of a cvar |
| [`wait`](/TaystJK/reference/commands/wait-daaad33/) | command | engine-shared | Pause command buffer execution |
| [`warp`](/TaystJK/reference/commands/warp-af58c70/) | command | cgame | Forwards this command to the connected game server. |
| [`warpList`](/TaystJK/reference/commands/warplist-c2ce9d3/) | command | cgame | Forwards this command to the connected game server. |
| [`weaplast`](/TaystJK/reference/commands/weaplast-837fa67/) | command | cgame | Runs `CG_LastWeapon_f` in the cgame module. |
| [`weapnext`](/TaystJK/reference/commands/weapnext-27bad9f/) | command | cgame | Runs `CG_NextWeapon_f` in the cgame module. |
| [`weapon`](/TaystJK/reference/commands/weapon-395d3b4/) | command | cgame | Runs `CG_Weapon_f` in the cgame module. |
| [`weaponclean`](/TaystJK/reference/commands/weaponclean-4f42615/) | command | cgame | Runs `CG_WeaponClean_f` in the cgame module. |
| [`weapontoggle`](/TaystJK/reference/commands/weapontoggle-7ca8872/) | command | engine-server | Toggle g_weaponDisable bits |
| [`weapprev`](/TaystJK/reference/commands/weapprev-e523eb8/) | command | cgame | Runs `CG_PrevWeapon_f` in the cgame module. |
| [`where`](/TaystJK/reference/commands/where-46148cc/) | command | cgame | Forwards this command to the connected game server. |
| [`which`](/TaystJK/reference/commands/which-ed04ff4/) | command | engine-shared | Determines which search path a file was loaded from |
| [`whitelistip`](/TaystJK/reference/commands/whitelistip-d79fc84/) | command | engine-server | Add IP to the whitelist |
| [`whois`](/TaystJK/reference/commands/whois-a93a167/) | command | cgame | Forwards this command to the connected game server. |
| [`write`](/TaystJK/reference/commands/write-e1d0c6c/) | command | engine-shared | Write the configuration to file |
| [`writeconfig`](/TaystJK/reference/commands/writeconfig-fd281f7/) | command | engine-shared | Write the configuration to file |
| [`ysal`](/TaystJK/reference/commands/ysal-49fb494/) | command | cgame | Forwards this command to the connected game server. |
| [`zone_details`](/TaystJK/reference/commands/zone_details-1f55083/) | command | engine-shared | Prints out full detailed zone memory info |
| [`zone_memrecovertest`](/TaystJK/reference/commands/zone_memrecovertest-0999822/) | command | engine-shared | Runs `Z_MemRecoverTest_f` in the engine-shared module. |
| [`zone_stats`](/TaystJK/reference/commands/zone_stats-890b1e1/) | command | engine-shared | Prints out zone memory stats |
| [`zoom`](/TaystJK/reference/commands/zoom-9229881/) | command | cgame | Use binoculars item |
