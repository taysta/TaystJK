---
title: "Shipped configs"
layout: reference
nav_order: 10
parent: "Features"
description: "The fourteen configuration files that ship with the client, what each one sets up, and how to apply one."
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

All fourteen live at the top level of `assets/japro/`, which the build packages into
`japro-assets.pk3` in your `taystjk/` directory. Read one before running it if you want to
know exactly what it will change. They are short.

## Strafe helper presets

Seven presets for the strafe helper and speedometer, which are bitmask cvars that are
awkward to set by hand. They differ in which display modes they turn on and how they are
tuned; pick one and adjust from there.

| Config | Sets |
|:--|:--|
| `strafehelper` | The general-purpose preset. |
| `strafehelper_off` | Turns the helper's display bits off again. |
| `strafehelper_jk2` | A JK2-flavoured setup. |
| `strafehelper_loda` | Preset with the speedometer enabled. |
| `strafehelper_source` | Source-engine-flavoured setup, with the speedometer. |
| `strafehelper_tayst` | The maintainer's own preset. |
| `strafehelper_tayst2` | A variant, with the helper's precision raised. |

Because these are bitmasks, `exec`ing one replaces the whole value rather than merging with
what you had. The `strafehelper` and `speedometer` commands print what each bit means; see
[HUD and movement tools](/TaystJK/features/hud-and-movement/).

## Gameplay and HUD presets

| Config | What it does |
|:--|:--|
| `japro_default` | A broad baseline touching movement keys and general client settings. The longest of the set. |
| `japro_loda` | An alternative baseline, including client smoothing settings. |
| `hud_tayst` | A HUD layout preset with an FPS display, timers and placement. |

## Motion sickness

Two very short files that exist as a pair:

| Config | What it does |
|:--|:--|
| `noMotion` | Resets the view-movement cvars, including `cg_runPitch` and its siblings, so the view stops bobbing and rolling. |
| `restoreMotion` | Puts them back to their stock values. |

Run `noMotion` if head-bob makes you unwell; `restoreMotion` undoes it exactly, which is why
they ship together.

## Tribes

| Config | What it does |
|:--|:--|
| `japro_tribes` | Client-side setup for the Tribes movement style, including the key binds the mode expects. |
| `japro_tribes_server` | Server-side settings for hosting Tribes, including force-power restrictions. |

The second is for whoever runs the server, not for players. See
[Tribes](/TaystJK/features/tribes/).

## Files that are not presets

`assets/japro/` contains other `.cfg` files that are not meant to be `exec`ed. Per-model
`sounds.cfg`, `animation.cfg` and `animevents_japlus.cfg` are asset descriptions the engine
reads on its own. Only the fourteen at the top level are user-facing presets.
