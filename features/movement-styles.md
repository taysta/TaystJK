---
title: "Movement styles"
layout: reference
nav_order: 6
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
[`bg_public.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L560).
The descriptions below follow
[`docs/Defrag Mapping Guide.md`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/Defrag%20Mapping%20Guide.md),
which ships on the source branch. It is jaPRO's own guide, carried downstream with the
gamecode rather than written here. That makes it worth following because it is the
account of the person who built the styles.

## The styles

| Style | Derived from | How it plays |
|:--|:--|:--|
| `siege` | JKA siege mode | No air acceleration. Speed comes from rolling, ramps and wall-strafing. |
| `jka` | — | Default Jedi Academy movement. |
| `qw` | QuakeWorld | QuakeWorld turning with JKA force jump. Tighter turns without losing speed, plus ramp jumps. |
| `cpm` | CPM, via Q3 defrag | No force jumps, base speed 320, high air control, rampjumps, double jumps. |
| `q3` | Vanilla Q3 defrag | CPM without the increased air control. |
| `pjk` | CPM | CPM with force jump and normal JKA base speed. |
| `wsw` | Warsow / Warfork | CPM plus a dash and a walljump, which redirect your speed to any angle without losing it. Its ramp jump costs no horizontal speed either. |
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

## Choosing a style

Players pick their own style with `/move`, which the server implements
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L9004)):

```text
move <siege, jka, qw, cpm, q3, pjk, wsw, rjq3, rjcpm, swoop, jetpack,
      speed, sp, slick, botcpm, coop, ocpm, tribes, or surf>
```

Run it with no argument and it prints exactly that list, which is the quickest way to see
what your server accepts.

Four conditions must hold, and the command tells you which one you failed
([`Cmd_MovementStyle_f`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L6687)):

- The server must have race mode enabled (`g_raceMode`).
- You must be **in** racemode yourself, not just on a server that allows it.
- You must be alive, not dead or spectating.
- You must be **standing still**. Any velocity and it refuses.

That last one catches people out. Try it while you are still drifting and the style does
not change; the only sign is the refusal printed to your console.

Outside racemode there is no per-player choice: `g_movementStyle` picks the style for
everyone, clamped to the enum. Below the first style it falls back to `siege`, and at or
past the end of it to `jka`
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L445)).
In racemode your own `STAT_MOVEMENTSTYLE` wins instead, which is how one race server runs
different physics per player and keeps a leaderboard per style.

Style is a game-module concern, so what you can select depends on the server. The client
draws what it is told; see [the overview](/TaystJK/overview/) for where that boundary runs.
