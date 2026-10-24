---
title: "Shipped configs"
layout: reference
nav_order: 10
parent: "Features"
description: "The thirteen configuration files that ship with the client, what each one sets up, and how to apply one."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Shipped configs

<p class="page-lede">Ready-made settings that ship inside the client's asset pk3. Each is a plain list of cvars you can apply in one command, read, or copy from.</p>
</div>

## Applying one

```text
exec strafehelper_tayst
```

`exec` runs a config from the filesystem, so a shipped file works without installing
anything. They set cvars and nothing more: run one, and you can undo it by running another
or setting the cvars back by hand. Nothing here is locked in.

All thirteen live at the top level of `assets/japro/`, which the build packages into
`japro-assets.pk3` in your `taystjk/` directory. Read one before running it if you want to
know exactly what it will change. They are short.

## Strafe helper presets

Seven presets for the strafe helper and speedometer, which are bitmask cvars that are
awkward to set by hand. Pick the closest and adjust from there.

| Config | Sets |
|:--|:--|
| `strafehelper` | The general-purpose preset: helper, speedometer and movement keys, with a small crosshair and a steady third-person camera. |
| `strafehelper_off` | Turns the helper, speedometer and movement keys off, and puts the crosshair and camera back to normal. |
| `strafehelper_jk2` | Helper, speedometer and movement keys, with no crosshair and a steady third-person camera. |
| `strafehelper_loda` | Helper with shorter, thinner lines, a magenta crosshair, the speedometer and movement keys. |
| `strafehelper_source` | A more precise helper drawn on the optimal angle, the speedometer near the centre, and the race timer on the left. No movement keys. |
| `strafehelper_tayst` | Helper, the full speedometer with its jumps array, small movement keys at the crosshair, the race timer and start speed, in first person. |
| `strafehelper_tayst2` | Only the helper: more precise, drawn on the optimal angle, with faint lines. Nothing else changes. |

Most of them also change the crosshair and the third-person camera, so read one before you run
it if you have those set up the way you like.

Because these are bitmasks, `exec`ing one replaces the whole value rather than merging with
what you had. The `strafehelper` and `speedometer` commands print what each bit means; see
[HUD and movement tools](/TaystJK/features/hud-and-movement/).

## Gameplay and HUD presets

| Config | What it does |
|:--|:--|
| `japro_default` | A baseline HUD layout: positions for the movement keys, speedometer, team overlay and chat box, the race timer, and the strafe helper display turned off. |
| `japro_loda` | loda's own settings: client smoothing and screen shake off, hit, jump and roll sounds on, a smaller chat box and an FPS counter. |
| `hud_tayst` | The FPS counter and lagometer, the [centre timer](/TaystJK/features/hud-and-movement/#the-centre-timer-and-team-score) counting down with team scores, the team overlay, scoreboard deaths and clock, and the killfeed. |

## Motion sickness

TaystJK already starts with view bob and roll off: [`cg_runPitch`](/TaystJK/reference/cvars/cg_runpitch-db8b764/)
and its siblings default to `0`, and [`ui_disableWeaponSway`](/TaystJK/reference/cvars/ui_disableweaponsway-e995888/)
defaults to `1`. These two files switch between that and stock Jedi Academy's motion:

| Config | What it does |
|:--|:--|
| `restoreMotion` | Sets `cg_runPitch`, `cg_runRoll`, `cg_bobUp`, `cg_bobPitch` and `cg_bobRoll` to stock Jedi Academy's values and turns weapon sway back on ([`restoreMotion.cfg`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/assets/japro/restoreMotion.cfg#L1)). |
| `noMotion` | Resets the same cvars to TaystJK's defaults, so the view stops bobbing and rolling again ([`noMotion.cfg`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/assets/japro/noMotion.cfg#L1)). |

You only need `noMotion` after running `restoreMotion` or setting those cvars yourself. If
head-bob makes you unwell and you have never changed them, there is nothing to undo.

## Tribes

| Config | What it does |
|:--|:--|
| `japro_tribes` | Client-side setup for the Tribes movement style: the key binds the mode expects, including the number keys, and network settings for its fast movement. |

The server side is not a client config. The Docker image's
[bundled server configs](/TaystJK/server-hosting/bundled-configs/#game-modes), written for
TaystJK's jaPRO game module, include the Tribes modes. See [Tribes](/TaystJK/features/tribes/).

## Files that are not presets

`assets/japro/` contains other `.cfg` files that are not meant to be `exec`ed. Per-model
`sounds.cfg`, `animation.cfg` and `animevents_japlus.cfg` are asset descriptions the engine
reads on its own. Only the thirteen at the top level are user-facing presets.
