---
title: "Cosmetics"
layout: reference
nav_order: 3
parent: "Features"
description: "Hats and capes: how the cosmetics system works, how to add one, and the offsets format that positions it per model and per skin."
origin: taystjk
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Cosmetics

<p class="page-lede">Hats and capes drawn on player models, selected per player and positioned per model and skin by a small JSON file.</p>
</div>

## Choosing one

`cosmetics` with no arguments prints its usage and the available categories
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1770)):

```text
cosmetics <category/clear> [id]
```

The categories are `Hats` and `Capes`. Run `cosmetics hats` to list what your client
loaded, then `cosmetics hats <id>` to wear one. `cosmetics clear` removes both.

Your choice is stored in the `color1` cvar for a hat and `color2` for a cape — the client
reuses those two userinfo slots to carry the cosmetic name, which is why a cosmetic name is
limited to 14 characters
([`cg_local.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L323)).
A longer name is skipped with a warning.

On a jaPRO server the command is handed to the server instead of being handled locally
([`CG_Cosmetics_f`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1902)),
so what is available there is the server's business, not your client's.

## Seeing other players' cosmetics

Two settings change what you see, and neither affects what anyone else sees.

[`cg_forceCosmetics`](/TaystJK/reference/) has two states. Left at `0`, every player shows
the cosmetics they chose. Set to anything non-zero, **your** hat and cape are drawn on
everybody
([`cg_players.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L13195)).
There is no third mode; any non-zero value behaves the same way.

To hide cosmetics altogether, use bit 16 of `cg_stylePlayer`, "Hide player cosmetics".
Configure it with `stylePlayer`, which prints the full list of bits.

## Seasonal cosmetics

Seasonal cosmetics are not a separate system: they are bit 20 of the same `cg_stylePlayer`
bitmask, listed as "Seasonal Cosmetics"
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1429)).
Turn the bit on with `stylePlayer` to opt in.

<!-- TODO: the dates that decide which season is active are said to be hardcoded in the
     client, but the seasonal selection itself was not located in the tree — the only date
     handling found nearby is chat-token time formatting. Find where the bit is consumed
     before documenting which dates trigger what. -->

## Adding a cosmetic

A cosmetic is an `.md3` placed in one of two directories, with the file name becoming the
name you select
([`cg_local.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L325)):

```text
models/cosmetics/hats/<name>.md3
models/cosmetics/capes/<name>.md3
```

Keep `<name>` to 14 characters or fewer. The client checks the `.md3` exists before
offering it, so a name that appears in a listing is one it could actually load.

Package the model in a pk3 and everyone who wants to see it needs that pk3 — cosmetics are
drawn client-side from local files, so a player without your pk3 sees nothing.

Shaders for the shipped set live in
[`japro_hats.shader`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/shaders/japro_hats.shader)
and
[`japro_capes.shader`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/shaders/japro_capes.shader);
follow those when writing your own.

## Positioning: the `.cosmetic` file

One model does not wear a hat the same way another does. An optional JSON file gives a
cosmetic different offsets per player model, and per skin within a model:

```text
settings/cosmetics/hats/<name>.cosmetic
settings/cosmetics/capes/<name>.cosmetic
```

The name matches the `.md3`. With no file, all three offsets are zero — the cosmetic is
still drawn, just unpositioned.

TaystJK installs a worked example at `settings/cosmetics/hats/example.cosmetic`:

```json
{
    "desann": {
        "modelFallback": false,
        "xOffset": 30,
        "yOffset": 15,
        "zOffset": -24,
        "default": { "xOffset": 10, "yOffset": 20, "zOffset": 30 },
        "red":     { "xOffset": 40, "yOffset": 50, "zOffset": 60 },
        "blue":    { "xOffset": 20, "yOffset": 40, "zOffset": 50 }
    },
    "kyle": {
        "modelFallback": true,
        "xOffset": 30,
        "yOffset": 15,
        "zOffset": -24,
        "defa*": { "xOffset": 10, "yOffset": 20, "zOffset": 30 },
        "blue":  { "xOffset": 40, "yOffset": 50, "zOffset": 60 },
        "de*":   { "xOffset": 10, "yOffset": 20, "zOffset": 30 }
    }
}
```

Reading it key by key:

- **Top-level keys are player model names** — `desann`, `kyle`.
- **`xOffset`, `yOffset`, `zOffset` on the model** are that model's own offsets. They are
  used only when `modelFallback` allows it, below.
- **`modelFallback`** decides what happens to a skin with no entry of its own. It defaults
  to **false**, so writing it out is only necessary to turn it on.
- **Nested keys are skin names** — `default`, `red`, `blue`.

### How a match is chosen

Both levels resolve the same way
([`CG_LoadCustomCosmeticOffsets`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L1811)):

1. An exact, **case-sensitive** key wins.
2. Otherwise any key containing `*` is treated as a prefix, and the **longest** matching
   prefix wins. In the `kyle` block a skin named `default` matches both `defa*` and `de*`,
   and `defa*` wins because it is longer.
3. If neither matches at model level, the file contributes nothing and the offsets are zero.
4. If neither matches at skin level, `modelFallback` decides: `true` uses the model's own
   offsets, `false` leaves them at zero. `desann` above therefore gives an unlisted skin
   nothing, while `kyle` gives it `30, 15, -24`.

Two details worth knowing. All three offsets must be present and numeric or the whole entry
is rejected with a console warning and treated as zero — there is no partial application.
And the values are read as whole numbers, so a fractional offset is truncated.

### Testing without restarting

The file is read when the client parses a player's info
([`cg_players.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L2322)),
not once at startup. Re-issuing your `model` cvar makes the client re-read it, so you can
edit offsets and see the result without reconnecting. Watch the console: a malformed file
says so by name.
