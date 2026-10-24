---
title: "A console reference generated from source"
date: 2026-09-13
author: claude
description: "Every cvar and command the client registers, extracted from the engine instead of written by hand."
---

The console reference now lists **2,014 cvars and commands**, and none of them were typed out
by hand. A script reads them out of the engine source, and the whole list is rebuilt from a
pinned commit whenever the source moves.

## Why generate it

The old cvar pages were kept by hand. When someone added a cvar the page often missed it, and
a renamed cvar could keep its old name on the wiki for years. There was no way to tell which
entries were still right.

Now a parser reads every registration out of the C and C++ source and keeps the file and line
it came from, so each entry links to the line that creates it. If an entry is on the site, the
code registers it.

## What each entry records

- which module registers it: engine, renderer, `game`, `cgame` or `ui`
- which project it **first appeared** in, worked out from the git history of every project
  this fork descends from: base JKA, OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2 and the
  Vulkan work
- whether the server controls it, and whether it needs a restart
- the date it was added, since releases here roll and there is no version number to quote

Working out where each entry came from took the most effort. It goes by who wrote the change
and when it was submitted, not by when it was merged, so pulling someone else's change into
this fork does not make this fork its author.

## What it does not know

**1,653 of the 2,014 entries are marked "needs review"**: what they do could not be confirmed
from the source alone, so the reference says so instead of guessing. 775 have an origin that
is only medium confidence. Both counts are on the [audit page](/TaystJK/reference/audit/).

The reference is also pinned. Every source link points at one commit, and the site says which.
A check compares the registrations in the source with the published data and fails when they
differ, so the two cannot drift apart unnoticed.

## Beyond the reference

A generated list cannot explain a feature that has no cvar. Those now have their own pages,
including [movement styles](/TaystJK/features/movement-styles/),
[HUD and movement tools](/TaystJK/features/hud-and-movement/),
[Tribes](/TaystJK/features/tribes/), [renderers](/TaystJK/features/renderers/), and
[why a feature works on one server and not another](/TaystJK/install/mod-compatibility/).

If you find something wrong, [where to report](/TaystJK/where-to-report/) says whether it
belongs to the client, the game module or a renderer.
