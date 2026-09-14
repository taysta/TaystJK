---
title: "Licensing and attribution"
layout: reference
nav_order: 13
description: "The licence TaystJK is distributed under, the projects it descends from, and what that means if you want to reuse any of it."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Reference</p>

# Licensing and attribution

<p class="page-lede">TaystJK is free software under the GNU General Public License, version 2, and so is everything it is built from.</p>
</div>

## The licence

TaystJK is distributed under **GPLv2**, inherited from the Raven source release that
OpenJK and every Jedi Academy fork descend from. The full text ships with the source as
[`LICENSE.txt`](https://github.com/taysta/TaystJK/blob/master/LICENSE.txt).

In practice this means you may use, study, modify and redistribute it, and that anything
you distribute built from it carries the same licence and the same source-availability
obligation. It is not a permissive licence: shipping a closed-source client built on this
code is not permitted.

## Who wrote what

TaystJK is a fork several generations deep, and almost nothing here originated with it.
The [console reference](/TaystJK/reference/) records an **origin** for every one of its
2,014 entries — the project where that cvar or command first appeared, resolved from commit
history rather than assumed:

| Origin | Entries |
|:--|--:|
| Base Jedi Academy | 1,024 |
| jaPRO | 458 |
| OpenJK | 167 |
| EternalJK | 148 |
| rend2 | 90 |
| TaystJK | 79 |
| Vulkan | 24 |
| JK2MV | 14 |
| NewJK / NewMod | 10 |

The method, including how attribution is decided when a change moved between projects, is
on [sources and methodology](/TaystJK/reference/sources/). Origin means *first appeared
there*, not *only exists there*.

Two of those deserve naming beyond a row in a table. **jaPRO** supplies both halves of the
gamecode this client bundles — see [the overview](/TaystJK/overview/) — and is developed at
[videoP/jaPRO](https://github.com/videoP/jaPRO). The **Vulkan renderer** is maintained
downstream by JKSunny at
[JKSunny/EternalJK](https://github.com/JKSunny/EternalJK), and derives from
[Quake3e](https://github.com/ec-/Quake3e).

## Assets

The licence covers code. It does not cover Jedi Academy's own game assets, which you must
own a copy of the game to obtain — TaystJK ships no Raven assets and cannot be played
without them. The [install guide](/TaystJK/install/) covers what you need.

Assets that *do* ship with the client — the cosmetics, emoji, HUD and shader files under
`assets/japro/` — come from the jaPRO project and contributors credited in the source
history. A few are noted individually where a page describes them.

## This documentation

The pages on this site are written for TaystJK and generated from its source. Where a page
leans on someone else's documentation it says so and links it, rather than absorbing it —
the [movement styles](/TaystJK/features/movement-styles/) page follows jaPRO's own mapping
guide, for instance.

Parts of this site were written with AI assistance, which is disclosed in full on
[AI disclosure](/TaystJK/ai-disclosure/).
