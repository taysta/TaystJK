---
title: "Movement styles"
layout: reference
nav_order: 7
parent: "Features"
description: "The nineteen movement styles a server can select, what each is derived from, and how each one plays."
toc: true
origin: japro
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Movement styles

<p class="page-lede">A movement style is a complete set of movement physics. It changes acceleration, air control, jumping and what tricks exist, and race records are kept separately for each one.</p>
</div>

There are nineteen, defined as the `MV_*` enum in
[`bg_public.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_public.h#L565).
The descriptions below follow
[`docs/Defrag Mapping Guide.md`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/docs/Defrag%20Mapping%20Guide.md),
which ships on the source branch. It is jaPRO's own guide, written by the person who built
the styles and carried downstream with the gamecode.

## The styles

| # | Style | Derived from | How it plays |
|--:|:--|:--|:--|
| 0 | `siege` | JKA siege mode | No air acceleration. Speed comes from rolling, ramps and wall-strafing. |
| 1 | `jka` | — | Default Jedi Academy movement. |
| 2 | `qw` | QuakeWorld | QuakeWorld turning with JKA force jump. Tighter turns without losing speed, plus ramp jumps. |
| 3 | `cpm` | CPM, via Q3 defrag | No force jumps, base speed 320, high air control, rampjumps, double jumps. |
| 4 | `q3` | Vanilla Q3 defrag | CPM without the increased air control. |
| 5 | `pjk` | CPM | CPM with force jump and normal JKA base speed. |
| 6 | `wsw` | Warsow / Warfork | CPM plus a dash and a walljump, which redirect your speed to any angle without losing it. Its ramp jump costs no horizontal speed either. |
| 7 | `rjq3` | Q3 | Q3 with a rocket launcher, moving by self-knockback. |
| 8 | `rjcpm` | RJQ3 | RJQ3 with air control. |
| 9 | `swoop` | — | Riding a swoop bike, with a gravity-boost option. |
| 10 | `jetpack` | — | Jetpack with its own physics, plus a swinging grapple and detpacks for self-boost. |
| 11 | `speed` | JKA | JKA at force-speed base speed, with 50 non-regenerating force. |
| 12 | `sp` | Jedi Academy single-player | Higher air acceleration; landing halves your speed unless you land lower than you took off. |
| 13 | `slick` | — | No ground friction and very fast ground acceleration. No force jump. |
| 14 | `botcpm` | CPM | CPM with a button that makes your strafe angles perfect. |
| 15 | `coop` | JKA | Two-player mode with weapons that boost each other. |
| 16 | `ocpm` | CPM, via Q3 defrag | CPM made closer to Q3 defrag's: 125 fps physics and velocity snapping. |
| 17 | `tribes` | Tribes | Skiing and jetpacking, a self-boost gun and a thrust pack. See [Tribes](/TaystJK/features/tribes/). |
| 18 | `surf` | Counter-Strike 1.6 | For surf and bhop maps. |

The number is the style's value for `g_movementStyle`. `jka` is the base game's own
movement, and jaPRO's guide does not say what `swoop`, `jetpack` and `slick` were modelled on.

Race records in `ocpm` are not saved at the moment: jaPRO switches them off for that style
([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_trigger.c#L1296)).

## Choosing a style

Players pick their own style with `/move`, which the server implements
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_cmds.c#L9008)):

```text
move <siege, jka, qw, cpm, q3, pjk, wsw, rjq3, rjcpm, swoop, jetpack,
      speed, sp, slick, botcpm, coop, ocpm, tribes, or surf>
```

Run it with no argument and it prints exactly that list, which is the quickest way to see
what your server accepts.

Four conditions must hold, and the command tells you which one you failed
([`Cmd_MovementStyle_f`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_cmds.c#L6687)):

- The server must have race mode enabled (`g_raceMode`).
- You must be **in** racemode yourself, not just on a server that allows it.
- You must be alive, not dead or spectating.
- You must be **standing still**. Any velocity and it refuses.

The last one is easy to miss: try it while you are still drifting and the style does not
change; the only sign is the refusal printed to your console.

Outside racemode there is no per-player choice: `g_movementStyle` picks the style for
everyone, using the numbers in the table. Only some styles can be chosen this way: `siege`
through `wsw` (0 to 6), `sp`, `slick`, `ocpm` and `tribes`. Any other number, including the
rocket, swoop, jetpack, speed, botcpm, coop and surf styles, falls back to `jka`
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_pmove.c#L445)).
Those are racemode-only. In racemode each player's own choice wins instead, which is how one
race server runs different physics per player and keeps a leaderboard per style. [Racing on
jaPRO](/TaystJK/features/racing/) covers the rest of a race server: practice mode, accounts,
leaderboards and strafe trails.

Style is a game-module concern, so what you can select depends on the server. The client
draws what it is told; see [the overview](/TaystJK/overview/) for where that boundary runs.
