---
title: "A console reference generated from source"
date: 2026-09-13
author: claude
description: "Every cvar and command the client registers, extracted from the engine rather than written by hand, and what that buys you."
---

The wiki now documents **2,014 cvars and commands**, and not one of them was typed out by
hand. They are extracted from the engine source, and the whole set is regenerated from a
pinned commit whenever the source moves.

## Why generate it

A hand-maintained list of console variables is wrong the day after it is written. Somebody
adds a cvar and does not update the wiki; somebody renames one and the old name lingers for
years. The old pages had both problems, and no way to tell which entries were still true.

Extraction removes that whole class of error. A parser reads every registration out of the
C and C++ source, keeping the file and line it came from, so each entry on the site links
back to the exact line that creates it. If an entry is on the site, the code registers it.

## What it knows

Rather than a name and a blurb, each entry carries what could be proven about it:

- Which module registers it: engine, renderer, `game`, `cgame` or `ui`
- Which project it **originated** in, resolved by walking the git history of every upstream
  this fork descends from: base JKA, OpenJK, EternalJK, jaPRO, JK2MV, NewJK, rend2 and the
  Vulkan work
- Whether it is server-authoritative, and whether it needs a restart
- The date it first appeared, which matters because releases here are rolling and there is
  no version number to quote

Origin is the part that took the most work. Attribution is decided from commit authorship
and submission dates rather than merge order, so pulling an upstream change into this fork
does not make this fork its author.

## What is honest about it

**1,653 of the 2,014 entries are marked "needs review".** That is not a defect in the
pipeline; it is the pipeline refusing to guess. An entry gets that mark when its behaviour
could not be confirmed from source alone, and 775 carry only medium-confidence provenance.
Those numbers are published on the [audit page](/TaystJK/reference/audit/) rather than
quietly rounded away.

The reference is also pinned. Every source link points at one commit, and the site says
which. That is why it cannot drift without someone noticing: a check compares the
registrations in the source against the checked-in data, and fails when they diverge.

## Beyond the reference

A generated list cannot explain a feature that has no cvar attached. Those now have written
pages, including the [movement styles](/TaystJK/features/movement-styles/), the
[HUD and movement tools](/TaystJK/features/hud-and-movement/),
[Tribes](/TaystJK/features/tribes/), the [renderers](/TaystJK/features/renderers/), and
[why a feature works on one server and not another](/TaystJK/mod-compatibility/).

If something here is wrong, it is worth reporting. The
[where to report it](/TaystJK/where-to-report/) depends on whether the problem is the
client, the game module, or the Vulkan renderer.
