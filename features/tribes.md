---
title: "Tribes"
layout: reference
nav_order: 7
parent: "Features"
description: "The Tribes movement mode: skiing, jetpack, IFF markers, its own HUD and weapons. Experimental and lightly played."
origin: japro
status: experimental
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Tribes

<p class="page-lede">A movement style that replaces running with skiing and adds a jetpack, its own HUD and its own weapons. It is experimental, few servers run it, and it needs assets you may not have.</p>
</div>

Tribes is one of the nineteen [movement styles](/TaystJK/features/movement-styles/) — the
server chooses it. Unlike the others it comes with a substantial amount of client-side
machinery: a replacement HUD, team markers, a fuel display and its own weapon effects.

Almost everything below needs the Tribes assets. The client-side half is a bit in
`cg_stylePlayer` labelled "Tribes Clientside (Requires assets)"; without those files you
will see missing models and blank icons rather than a graceful fallback.

## Skiing

Holding the dash button removes ground friction, so instead of running you slide and keep
momentum across terrain
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L6051)).
That is the whole idea of the mode: you gain speed downhill and carry it, rather than
accelerating from a standstill.

Landing while skiing plays its own sound rather than the normal landing thud
([`cg_main.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_main.c#L869)).

The same button is also a dash, shared with the `wsw` style but behaving differently here:
in Tribes it spends force power and sets a much longer cooldown
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L5448)).
Bots ski by pressing the same button
([`ai_main.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L579)).

## Jetpack fuel

The jetpack has a fuel level from 0 to 100, drawn as a segmented bar with a numeric readout
that eases towards the true value rather than snapping to it
([`hud_tribes.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_tribes.c#L3)).
Skiing and jetpacking together is how you cross a map quickly.

## IFF markers

In team games the client floats a team-coloured sprite above other players so you can tell
friend from enemy at speed
([`cg_players.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L11059)).

The marker scales with distance — `4 + distance * 0.008` — so a distant player still gets a
readable icon rather than a dot. Friendly markers show at any range; **enemy markers only
appear within 7500 units**, so an unmarked player far away is not necessarily a teammate.
Nothing is drawn on the dead, on NPCs, or on yourself except in mirrors.

This is gated on the server advertising Tribes, not on your own settings.

## The Tribes HUD

The mode swaps in a different HUD entirely
([`hud_tribes.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_tribes.c#L762)):
a health bar, a weapon selector that greys out anything you cannot currently fire, a pack
display, and the fuel bar above.

The weapon selector's availability test is energy-based rather than counting rounds — a
weapon is selectable when you hold at least as much ammo as one shot costs
([`hud_tribes.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_tribes.c#L183)),
which is why the display talks in shots rather than in a raw ammo count.

`invfree` selects the next usable inventory item and is bound by the HUD's prompt
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2456)).

## Weapons and feedback

The mortar has its own projectile and explosion effects under `tribes/weapons/mortar/`
([`cg_weaponinit.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_weaponinit.c#L405)).

Kills play one of two sounds depending on whether the victim was airborne, so a midair hit
is audibly different from a ground kill
([`cg_event.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_event.c#L281)).

## Classes

The server tracks a class per player
([`g_active.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_active.c#L4296)),
which changes how that player behaves in the mode.

<!-- TODO: how a player picks their class was not found. tribesClass is read server-side in
     g_active.c but nothing in this tree sets it from a command or a menu, so the selection
     probably lives in jaPRO's own game module. Confirm against a live Tribes server. -->

## Setting it up

Two shipped configs, described on [shipped configs](/TaystJK/features/shipped-configs/):

- `japro_tribes` — client-side setup, including the binds the mode expects.
- `japro_tribes_server` — for whoever runs the server, including force-power restrictions.

Run the client one with `exec japro_tribes`. Read it first: it rebinds number keys.

## Expectations

This mode is experimental and lightly played. It carries more bespoke code than any other
movement style, some of it carrying the author's own notes about ground detection being
unreliable while skiing
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L5439)).
Treat rough edges as expected rather than as bugs worth reporting, and report gameplay
problems to [videoP/jaPRO](https://github.com/videoP/jaPRO) rather than here.
