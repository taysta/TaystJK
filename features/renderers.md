---
title: "Renderers"
layout: reference
nav_order: 6
parent: "Features"
description: "The three renderer backends, what each is for, how to switch between them, and where renderer bugs belong."
toc: true
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
| `rd-rend2t` | `shared/rd-rend2` | The modern feature-rich backend, [labelled experimental in the build](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/CMakeLists.txt#L45). |
| `rd-vulkant` | `codemp/rd-vulkan` | A Vulkan backend derived from [Quake3e](https://github.com/ec-/Quake3e)'s, developed upstream by JKSunny. |

**The names you type are not the directory names.** The library names are set in
[`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/CMakeLists.txt#L179),
and `cl_renderer` is used verbatim to build the library filename
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L2748)).
`cl_renderer rd-vanilla` will not find anything.

## Switching

```text
cl_renderer rd-rend2t
vid_restart
```

[`cl_renderer`](/TaystJK/reference/cvars/cl_renderer-dc9f64f/) is latched, so nothing happens until `vid_restart` or
a restart. The menu exposes the same choice.

If the library you named cannot be loaded, the client says so, resets `cl_renderer` to the
default and loads that instead rather than failing outright
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L2750)).
If you switch and end up back on the default, that is what happened. Usually the build
does not include that renderer.

## What differs in practice

**Settings are not shared.** Many `r_` cvars are registered by one backend only, so a
setting that works under one does nothing under another. The console reference records this
as *renderer scope* on each entry; anything listed for a backend you are not running is
inert. The menu follows the same rule and hides the rend2 options unless `cl_renderer` is
exactly `rd-rend2t`
([`ui_main.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6242)).

**Bloom is Vulkan-only, and needs the framebuffer path.** [`r_bloom`](/TaystJK/reference/cvars/r_bloom-656b99d/)
is registered by the Vulkan backend and its own description says it requires
[`r_fbo 1`](/TaystJK/reference/cvars/r_fbo-022d66e/)
([`tr_init.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L938)).
Both are latched, so set both and then `vid_restart`.

**Override shaders work everywhere.** `.oshader` files are implemented in all three
backends, so a shader override does not depend on your choice. See
[client behaviour changes](/TaystJK/features/client-behaviour/).

**Memory.** rend2 is the heaviest of the three. On a 32-bit build that can matter; the
[install guide](/TaystJK/install/) covers the practical consequences.

## Where a renderer bug goes

The Vulkan backend is developed upstream by JKSunny, and fixes flow from there to TaystJK. Report
Vulkan-specific rendering problems to
<https://github.com/JKSunny/EternalJK>, not here.

Anything you can also reproduce on `rd-taystjk` is not a Vulkan bug. Switch backends before
reporting. It is the single most useful thing you can say in the report.

rend2 is also developed upstream. `rd-rend2t` is built from SomaZ's rend2, on the
[`rend2-unified-wip`](https://github.com/SomaZ/OpenJK/tree/rend2-unified-wip) branch of
SomaZ's OpenJK fork, not from the older rend2 in OpenJK itself, and its fixes are written
there and ported down. A rend2-only problem belongs at
[SomaZ/OpenJK](https://github.com/SomaZ/OpenJK/issues) only if it also happens on a build
of that branch. If it happens only in TaystJK, TaystJK introduced it; report it at
[taysta/TaystJK](https://github.com/taysta/TaystJK/issues). Either way, check first that it
does not happen on `rd-taystjk`.
