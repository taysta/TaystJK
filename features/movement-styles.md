---
title: "Movement styles"
layout: reference
nav_order: 6
parent: "Features"
description: "The nineteen movement styles a server can select, what each is derived from, and how each one plays."
origin: japro
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Movement styles

<p class="page-lede">A movement style is a complete set of movement physics. It changes acceleration, air control, jumping and what tricks exist, and race records are kept separately for each one.</p>
</div>

There are nineteen, defined as the `MV_*` enum in
[`bg_public.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L560).
The descriptions below follow
[`docs/Defrag Mapping Guide.md`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/Defrag%20Mapping%20Guide.md)
on the source branch, which is the maintainer's own account of what each style is for.

## The styles

| Style | Derived from | How it plays |
|:--|:--|:--|
| `siege` | JKA siege mode | No air acceleration. Speed comes from rolling, ramps and wall-strafing. |
| `jka` | — | Default Jedi Academy movement. |
| `qw` | QuakeWorld | QuakeWorld turning with JKA force jump. Tighter turns without losing speed, plus ramp jumps. |
| `cpm` | CPM, via Q3 defrag | No force jumps, base speed 320, high air control, rampjumps, double jumps. |
| `q3` | Vanilla Q3 defrag | CPM without the increased air control. |
| `pjk` | CPM | CPM with force jump and normal JKA base speed. |
| `wsw` | Warsow / Warfork | CPM plus a dash and a walljump; see below. |
| `rjq3` | Q3 | Q3 with a rocket launcher, moving by self-knockback. |
| `rjcpm` | RJQ3 | RJQ3 with air control. |
| `swoop` | — | Riding a swoop bike, with a gravity-boost option. |
| `jetpack` | — | Jetpack with its own physics, plus a swinging grapple and detpacks for self-boost. |
| `speed` | JKA | JKA at force-speed base speed, with 50 non-regenerating force. |
| `sp` | Jedi Academy single-player | Higher air acceleration; landing halves your speed unless you land lower than you took off. |
| `slick` | — | No ground friction and very fast ground acceleration. No force jump. |
| `botcpm` | CPM | CPM with a button that makes your strafe angles perfect. |
| `coop` | JKA | Two-player mode with weapons that boost each other. |
| `ocpm` | CPM, via Q3 defrag | CPM made closer to Q3 defrag's: 125 fps physics and velocity snapping. |
| `tribes` | Tribes | Skiing and jetpacking, a self-boost gun and a thrust pack. See [Tribes](/TaystJK/features/tribes/). |
| `surf` | Counter-Strike 1.6 | For surf and bhop maps. |

Four rows carry no lineage because none is stated anywhere in the tree. `jka` is the base
game's own movement and needs none; `swoop`, `jetpack` and `slick` are described by what
they do rather than what they were modelled on. Rather than invent an inspiration for them,
they are left as the guide states them.

## WSW is a CPM-family style, not part of Tribes

`wsw` takes its movement from Warsow, and from Warfork, the actively developed continuation
that carries the same movement — that is the name most players will know it by now.

It is easy to mistake for Tribes because both have a dash. They are separate styles and the
resemblance is one button.

WSW sits in the CPM family. It shares the double-jump path with CPM, RJCPM, SLICK and
BOTCPM
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L1212)),
and it has its own acceleration constants —
`pm_wsw_accelerate` is `12.0` and `pm_wsw_duckScale` is `0.3125`
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L101)).

Its ramp jump is deliberately weaker than the CPM group's, and takes its own branch in the
code
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L4521)),
because the style loses no speed when redirecting — the guide is explicit that its ramp jump
"does not reduce your horizontal speed at all".

**What the two actually share** is the dash. The dash routine returns immediately unless the
style is WSW or Tribes
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L5430)),
and even then they behave differently: Tribes spends force power and sets a much longer dash
timer. Tribes additionally uses the same button to gate its slick-friction path
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L6051)),
which is what makes skiing work. WSW does none of that.

## Choosing a style

The style in force is server-side: `g_movementStyle` selects it, and a value at or beyond
the end of the enum is rejected
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L451)).
Each player also carries their own current style in `STAT_MOVEMENTSTYLE`, which is how a
race server lets different players run different physics at once and keeps a separate
leaderboard per style.

<!-- TODO: no player-facing command for choosing your own style exists in this tree.
     codemp/game is the game module and its command table has "race" but nothing for style,
     and STAT_MOVEMENTSTYLE is only ever read during movement, never set by a command here.
     A jaPRO race server presumably provides one; name it only after confirming against a
     live server or jaPRO's own source. -->

Style is a game-module concern, so what you can select depends on the server. The client
draws what it is told; see [the overview](/TaystJK/overview/) for where that boundary runs.
