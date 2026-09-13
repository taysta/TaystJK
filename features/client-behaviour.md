---
title: "Client behaviour changes"
layout: reference
nav_order: 2
parent: "Features"
description: "Engine and client behaviour that differs from stock Jedi Academy: shader overrides, modifier binds, console editing, and widescreen assets."
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
definition of the same name — from any pk3, including the base assets.

The mechanism is worth knowing because it explains the guarantee. All shader files are
concatenated into one buffer before parsing, and `.oshader` contents are placed at the
front of it
([`tr_shader.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shader.cpp#L4134)).
Lookup walks the hash bucket and returns the **first** match it finds
([`FindShaderInShaderText`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shader.cpp#L3229)),
so whatever sits earliest in that buffer is what the game draws.

All three renderers implement it:
[rd-vanilla](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shader.cpp#L3983),
[rd-rend2](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_shader.cpp#L5035),
[rd-vulkan](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_shader.cpp#L2902).

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
rest of `example.shader`, and you do not have to load after the map's pk3 — the extension
alone decides. Every other shader in `example.shader` keeps working.

The count of loaded override files is printed at startup, so you can confirm yours was
found.

### Precedence between `.shader` files

Among ordinary `.shader` files, the one found **later** in the file list wins. The buffers
are concatenated in reverse list order
([`tr_shader.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_shader.cpp#L4147)),
which puts the later file earlier in the text, and first match wins. If
`gfx/2d/charsgrid_med` is defined in both `shaders/original.shader` and
`shaders/fonts.shader`, only one of them is used. An `.oshader` file beats both.

## Binds

**Modifier combinations.** Every key holds a separate binding per modifier — plain, `alt+`,
`ctrl+` and `shift+`
([`keys.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/keys.h#L29)) —
so `bind ctrl+x kill` leaves plain <kbd>X</kbd> alone. `bind` and `unbind` both take the
prefix
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L1317)).
A modifier key cannot be bound to itself with its own prefix.

**Right-side modifiers.** `RCTRL`, `RALT` and `RSHIFT` are their own key names and take
their own bindings
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L188)),
so `bind rctrl kill` affects only the right-hand key.

<!-- TODO: the retired hardcoded-changes page claimed that a right-side key with no binding
     of its own falls back to the generic binding, and that the left-side key always uses
     the generic one. Separate bindability is verified; the fallback is not. Find the
     press-time resolution before stating it. -->

## Console and chat editing

Both the console and the chat prompt support word-wise editing. <kbd>Ctrl</kbd> plus
<kbd>Backspace</kbd>, <kbd>Delete</kbd>, <kbd>Left</kbd> or <kbd>Right</kbd> acts on a whole
word instead of a character, and adding <kbd>Shift</kbd> changes where the word boundary is
taken
([`cl_keys.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_keys.cpp#L565)).
Each shortcut accepts either the left or the right modifier.

Two cvars change the console itself: [`con_height`](/TaystJK/reference/) sets how far it
drops down, and [`con_datetime`](/TaystJK/reference/) prefixes each line with a readable
date and time. Look both up in the console reference for their defaults and flags.

## Widescreen assets

The client prefers widescreen art where an author provides it, and falls back to the 4:3
original otherwise. Nothing breaks if you supply neither.

| Provide | Used instead of | Where |
|:--|:--|:--|
| `levelshots_16_9/<mapname>` | `levelshots/<mapname>` | [loading screen](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_info.c#L149) and the [map list](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L2132) |
| `menu/art/unknownmap_mp_16_9` | `menu/art/unknownmap_mp` | [map with no levelshot](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_info.c#L173) |
| `menu/splash_16_9` | `menu/splash` | [startup splash](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L296) |

As a map author, add the widescreen levelshot to your pk3 under `levelshots_16_9/` using the
same name as the map. All three renderers load the splash image.

## Sharper fonts

`r_fontSharpness` scales glyph rendering with your vertical resolution rather than the
fixed 480-line reference
([`tr_font.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-common/tr_font.cpp#L1171)).
It only helps where the font assets carry enough detail to scale up; with the retail fonts
there is nothing extra to reveal.
