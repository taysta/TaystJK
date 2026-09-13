---
title: "Renderers"
layout: reference
nav_order: 5
parent: "Features"
description: "The three renderer backends, what each is for, how to switch between them, and where renderer bugs belong."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Renderers

<p class="page-lede">TaystJK ships three renderer backends. Which one you run changes performance, which settings do anything, and who fixes a bug.</p>
</div>

## The three backends

| You type | Built from | What it is |
|:--|:--|:--|
| `rd-taystjk` | `codemp/rd-vanilla` | The default. The original renderer, kept as the compatibility baseline. |
| `rd-rend2t` | `shared/rd-rend2` | The modern feature-rich backend, [labelled experimental in the build](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L45). |
| `rd-vulkant` | `codemp/rd-vulkan` | A Vulkan backend derived from [Quake3e](https://github.com/ec-/Quake3e)'s, maintained downstream by JKSunny. |

**The names you type are not the directory names.** The library names are set in
[`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L179),
and `cl_renderer` is used verbatim to build the library filename
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2746)).
`cl_renderer rd-vanilla` will not find anything.

## Switching

```text
cl_renderer rd-rend2t
vid_restart
```

[`cl_renderer`](/TaystJK/reference/) is latched, so nothing happens until `vid_restart` or
a restart. The menu exposes the same choice.

If the library you named cannot be loaded, the client says so, resets `cl_renderer` to the
default and loads that instead rather than failing outright
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2748)).
If you switch and end up back on the default, that is what happened — usually the build
does not include that renderer.

## What differs in practice

**Settings are not shared.** Many `r_` cvars are registered by one backend only, so a
setting that works under one does nothing under another. The console reference records this
as *renderer scope* on each entry; anything listed for a backend you are not running is
inert. The menu follows the same rule and hides the rend2 options unless `cl_renderer` is
exactly `rd-rend2t`
([`ui_main.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6242)).

**Bloom is Vulkan-only, and needs the framebuffer path.** [`r_bloom`](/TaystJK/reference/)
is registered by the Vulkan backend and its own description says it requires
[`r_fbo 1`](/TaystJK/reference/)
([`tr_init.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L938)).
Both are latched, so set both and then `vid_restart`.

**Override shaders work everywhere.** `.oshader` files are implemented in all three
backends, so a shader override does not depend on your choice — see
[client behaviour changes](/TaystJK/features/client-behaviour/).

**Memory.** rend2 is the heaviest of the three. On a 32-bit build that can matter; the
[install guide](/TaystJK/install/) covers the practical consequences.

## Where a renderer bug goes

The Vulkan backend is developed downstream by JKSunny, and fixes flow from there. Report
Vulkan-specific rendering problems to
<https://github.com/JKSunny/EternalJK>, not here.

Anything you can also reproduce on `rd-taystjk` is not a Vulkan bug. Switch backends before
reporting — it is the single most useful thing you can say in the report.

## Switching used to freeze on macOS

`vid_restart` — which is how you switch renderer — could freeze the client on Apple Silicon,
leaving audio running and the pointer spinning
([#343](https://github.com/taysta/TaystJK/issues/343)).

The cause was `glConfig` being null on a restart, and it was fixed in
[#367](https://github.com/taysta/TaystJK/pull/367), which is the commit this reference is
generated from. If you are on an older build and switching renderers hangs on macOS, that is
this bug and updating fixes it.
