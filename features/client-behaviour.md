---
title: "Client behaviour changes"
layout: reference
nav_order: 2
parent: "Features"
description: "Engine and client behaviour that differs from stock Jedi Academy: shader overrides, modifier binds, console editing, and widescreen assets."
toc: true
origin: taystjk
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Client behaviour changes

<p class="page-lede">Behaviour the console reference cannot express, because it is not controlled by a cvar. What changed, why, and what you have to provide to use it.</p>
</div>

## Override shaders: `.oshader`

Two mods that both patch a shader living in the same base `.shader` file used to be
impossible to combine. Each shipped its own copy of the whole file, so installing both meant
one silently replaced the other, and the only fix was merging them by hand.

TaystJK adds a second shader extension. The renderer lists `shaders/*.oshader` alongside
`shaders/*.shader`, and a shader defined in an `.oshader` file wins over every `.shader`
definition of the same name from any pk3, including the base assets.

It works because the renderer joins every shader file into one block of text before reading
it, and puts the `.oshader` files at the front
([`tr_shader.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vanilla/tr_shader.cpp#L4134)).
When it looks a shader up, it takes the **first** definition it finds
([`tr_shader.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vanilla/tr_shader.cpp#L3229)),
so an override always comes first.

All three renderers implement it:
[rd-vanilla](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vanilla/tr_shader.cpp#L3983),
[rd-rend2](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/shared/rd-rend2/tr_shader.cpp#L5037),
[rd-vulkan](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vulkan/tr_shader.cpp#L2902).

### Overriding one shader

Say a map's glass is drawn by `textures/example/glass`, defined in `shaders/example.shader`
inside the map's pk3, and you want it opaque without touching that pk3.

Create `shaders/myfixes.oshader` containing only the shader you are replacing:

```text
textures/example/glass
{
	{
		map textures/example/glass
		blendFunc GL_ONE GL_ZERO
	}
}
```

Package that file as `shaders/myfixes.oshader` inside your own pk3. You do not copy the
rest of `example.shader`, and you do not have to load after the map's pk3. The extension
alone decides. Every other shader in `example.shader` keeps working.

The count of loaded override files is printed at startup, so you can confirm yours was
found.

### Precedence between `.shader` files

`.oshader` does not change how ordinary `.shader` files are ordered; it goes in front of
them. That ordering is what it works around, so here it is.

Two pk3s that ship the **same file name**, say both with their own `shaders/gfx.shader`:
only one copy is read, from whichever pk3 has priority
([`files.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/qcommon/files.cpp#L2636)). That is why mods ship a whole copy of a
file to change one shader in it, and why installing two such mods loses one of them.

One shader **name** defined in two **differently named** files: this is the case that
surprises people, because the result is the reverse of normal file priority. Pk3s are
loaded in name order, so `zzz.pk3` normally beats `assets0.pk3`
([`files.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/qcommon/files.cpp#L3422)). The shader text, though, is joined
lowest priority first
([`tr_shader.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vanilla/tr_shader.cpp#L4147)), and the first definition
wins, so the lowest-priority file's definition is the one used.

So if `gfx/2d/charsgrid_med` is defined in `shaders/original.shader` inside the base assets
and again in `shaders/fonts.shader` inside your pk3, the base assets definition is the one
used. Naming your pk3 to load later does not change it. Within a single pk3 the order is
just the order of the entries in the archive, so do not rely on it either.

`.oshader` sidesteps all of this: override files go ahead of every `.shader` file, so they
win whichever pk3 they came from. Among `.oshader` files themselves the order is the normal
one
([`tr_shader.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vanilla/tr_shader.cpp#L4135)),
so between two overrides of the same shader the higher-priority pk3 wins, restoring normal
precedence.

## Binds

**Modifier combinations.** Every key holds a separate binding per modifier: plain, `alt+`,
`ctrl+` and `shift+`
([`keys.h`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/keys.h#L29)),
so `bind ctrl+x kill` leaves plain <kbd>X</kbd> alone. `bind` and `unbind` both take the
prefix
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_keys.cpp#L1317)).
A modifier key cannot be bound to itself with its own prefix.

**Right-side modifiers.** `RCTRL`, `RALT` and `RSHIFT` are their own key names and take
their own bindings
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_keys.cpp#L188)),
so `bind rctrl kill` affects only the right-hand key.

If the right-hand key has no binding of its own, the press falls back to the generic one
([`CL_ParseBinding`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_keys.cpp#L1609)).
So `bind ctrl +attack` gives you both Ctrl keys, and `bind rctrl kill` on top of it
overrides only the right one. There is no fallback in the other direction: `SHIFT`, `CTRL`
and `ALT` *are* the left-hand keys, and nothing you bind to `RCTRL` reaches them.

**Which modifier counts as held.** Only the left-hand modifier arms a `ctrl+` style binding
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_keys.cpp#L1619)).
Hold the **right** Ctrl and press <kbd>X</kbd> and you get plain <kbd>X</kbd>, not
`ctrl+x`. The right-hand keys can carry bindings, but they cannot act as modifiers for
another key. When more than one is held, the order is alt, then ctrl, then shift.

## Console and chat editing

Both the console and the chat prompt support word-wise editing. <kbd>Ctrl</kbd> plus
<kbd>Backspace</kbd>, <kbd>Delete</kbd>, <kbd>Left</kbd> or <kbd>Right</kbd> acts on a whole
word instead of a character, and adding <kbd>Shift</kbd> changes where the word boundary is
taken
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_keys.cpp#L565)).
Each shortcut accepts either the left or the right modifier.

[`con_height`](/TaystJK/reference/cvars/con_height-41c46da/) sets how far the console drops down.
[`con_datetime`](/TaystJK/reference/cvars/con_datetime-fb79998/) draws a date and time display in the console
([`cl_console.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_console.cpp#L1090)).
Use [`con_timestamps`](/TaystJK/reference/cvars/con_timestamps-2b4f0eb/) for per-line timestamps
([`cl_console.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/client/cl_console.cpp#L399)).
Look these up in the console reference for their defaults and flags.

## Widescreen assets

The client prefers widescreen art where an author provides it, and falls back to the 4:3
original otherwise. Nothing breaks if you supply neither.

| Provide | Used instead of | Where |
|:--|:--|:--|
| `levelshots_16_9/<mapname>` | `levelshots/<mapname>` | [loading screen](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_info.c#L149) and the [map list](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/ui/ui_main.c#L2132) |
| `menu/art/unknownmap_mp_16_9` | `menu/art/unknownmap_mp` | [map with no levelshot](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_info.c#L173) |
| `menu/splash_16_9` | `menu/splash` | [startup splash](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-vanilla/tr_init.cpp#L296) |

As a map author, add the widescreen levelshot to your pk3 under `levelshots_16_9/` using the
same name as the map. All three renderers load the splash image.

## Sharper fonts

`r_fontSharpness` scales glyph rendering with your vertical resolution instead of the
fixed 480-line reference
([`tr_font.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/rd-common/tr_font.cpp#L1171)).
It only helps where the font assets carry enough detail to scale up; with the retail fonts
there is nothing extra to reveal.
