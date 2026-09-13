---
title: "Overview"
layout: reference
nav_order: 7
description: "How this documentation is organised, what jaPRO is, and how to read an entry in the generated console reference."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Start here</p>

# How this documentation works

<p class="page-lede">Four hand-written guides, one generated reference, and a glossary. This page explains which is which, and how to read the parts of an entry that are not obvious.</p>
</div>

## The guides and the reference

Five sections, written by different means:

- [**Install**](/TaystJK/install/), [**Host**](/TaystJK/server-hosting/), [**Features**](/TaystJK/features/) and
  [**Develop**](/TaystJK/development/) are written by hand. They explain how to do something,
  or how a feature works.
- [**Console reference**](/TaystJK/reference/) is generated from the source code. It has one
  page per cvar and console command — what it is, what it defaults to, where it is
  registered, and where it came from.

The split is deliberate. A cvar list cannot tell you why `.oshader` files exist or what a
movement style changes, and a hand-written page cannot stay accurate across two thousand
cvars. When a guide mentions a cvar it links to the reference rather than repeating its
default, because the reference is regenerated and the guide is not.

The [glossary](/TaystJK/glossary/) defines the terms both halves assume.

## What jaPRO is

jaPRO is a Jedi Academy mod, and the single largest source of what this client can do:
**458 of the 2,014** entries in the reference originate there, more than any project other
than the base game itself.

**TaystJK bundles both halves of jaPRO**, not just the client side. The build produces the
client-side gamecode (`cgame`) *and* the server-side gamecode (`jampgame`), along with the
UI and the engine
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L42)).
The split shows in the reference: of those 458 entries, 261 are in the `cgame` module and
**190 are in `game`** — the module that decides the rules.

| What you get | Where it lives | What it gives you |
|:--|:--|:--|
| Client-side gamecode | `cgame` | The HUD tools, movement helpers, cosmetics — present on every server you join |
| Server-side gamecode | `jampgame` | Race mode, the movement styles, Tribes, the admin system — when *you* host |
| Assets | `japro-assets.pk3` | The shaders, models and icons those features draw ([`codemp/CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/CMakeLists.txt#L81)) |

So a TaystJK dedicated server serves jaPRO-style gameplay out of the box, with nothing else
installed. That is why this site can cite `codemp/game/` for things like `/move` and the
Tribes classes: that code is in this tree.

**Joining someone else's server is the other case.** There, their game module decides the
rules and your bundled copy is not used at all — which is why the same feature can behave
differently from server to server. See
[mod compatibility](/TaystJK/mod-compatibility/).

**This matters when something is wrong.** Gameplay belongs to the game module, and that
code is maintained upstream at <https://github.com/videoP/jaPRO> and pulled down here — so
that is where a rules problem goes, even though a copy of the module ships with this client.
How the client renders, connects, binds keys or loads files belongs here. The reference's
**network scope** field is the quickest way to tell which side owns a given cvar.

## Reading an entry

Each reference entry carries fields whose meaning is not self-evident.

**Origin** says where an entry *first appeared* — not every fork that ships it. A cvar
inherited from Raven's code stays *Base Jedi Academy* even though every fork carries it,
and a cvar only registered by the Vulkan backend is not automatically Vulkan-originated;
the resolver checks the other upstream snapshots first. The full method, including how
ties are broken and what counts as evidence, is on
[sources and methodology](/TaystJK/reference/sources/).

**Needs review** means the entry is real and has registration evidence, but at least one
behaviour, option or attribution field could not be proven precisely enough to state as
fact. It is a label for uncertainty, not for a problem with the cvar.

**xdocs** and **menu** say whether the name already has an entry in the client's in-game
documentation, or appears in a shipped `.menu` file. Each detail page links the matching
source line.

**Network scope** distinguishes a purely local control from one the server owns or
negotiates. **Renderer scope** says which of the three backends registers a cvar, which is
why some entries do nothing until you switch renderer.

**Added** is a date, because there are no version numbers to quote. Compare it against the
date your build reports — `version` for the engine, `modversion` for the game module. If
your build is older than the date shown, it does not have that entry. The identifier beside
the date cannot be compared: `latest` is the same string on every release, and two short
hashes cannot be ranked against each other. A date marked *needs review* rests on an
attribution that could not be pinned exactly, so treat it as approximate.

## Where the data comes from

The reference is extracted from a single pinned commit of the source branch, not from a
running game. Every page states which commit it was generated from and when, and every
source link points into that commit, so a line number still means something months later.

Anything merged after that commit is not in the reference until it is regenerated. That is
the trade for having source links that do not rot.

The extraction, attribution and verification process is described in full on
[sources and methodology](/TaystJK/reference/sources/).
