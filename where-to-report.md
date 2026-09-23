---
title: "Where to report"
layout: reference
nav_order: 2
parent: "Help"
description: "Which project owns a problem: the client, the server's game module, the Vulkan or rend2 renderer, or a closed-source mod."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Start here</p>

# Where to report a problem

<p class="page-lede">TaystJK is a client. A lot of what you see while playing belongs to the server's game module or to a renderer maintained elsewhere, and reports sent to the wrong project sit unanswered.</p>
</div>

## The short version

| What is wrong | Where it goes |
|:--|:--|
| The client crashes, will not start, will not connect, mis-renders, or mishandles files, keys or configs | [taysta/TaystJK](https://github.com/taysta/TaystJK) |
| How the game *plays*: movement, saber behaviour, scoring, admin commands, race and defrag | [videoP/jaPRO](https://github.com/videoP/jaPRO), if it also happens without TaystJK |
| Something only wrong on the Vulkan renderer | [JKSunny/EternalJK](https://github.com/JKSunny/EternalJK), if it also happens on EternalJK |
| Something only wrong on the rend2 renderer | [SomaZ/OpenJK](https://github.com/SomaZ/OpenJK), if it also happens on SomaZ's build |
| Any of those, but only in TaystJK | [taysta/TaystJK](https://github.com/taysta/TaystJK) |
| Something only wrong on a JA+ server | Nowhere; see below |

## Before you send it elsewhere

Every time this site tells you to report something to another project, the same condition
applies: **reproduce it there first.** TaystJK carries its own copy of jaPRO's game code and
of both renderers, and changes them and the engine around them, so a bug that looks like
theirs can be one TaystJK introduced. The sections below say how to check for each project.

If it happens in their own build too, report it to them. If it only happens in TaystJK, it
is ours: report it at <https://github.com/taysta/TaystJK/issues>, and say that you checked.

## How to tell which

The distinction is not obvious from inside the game, so use these tests rather than
guessing.

**Does it happen on every server, or only some?** A problem that follows you from server to
server is the client's. One that appears only on particular servers is almost certainly the
game module those servers run. The rules live there, not in your client. The
[overview](/TaystJK/overview/) explains that split, and
[mod compatibility](/TaystJK/install/mod-compatibility/) explains why a feature can work on one
server and silently do nothing on another.

**Does it survive switching renderer?** Run `cl_renderer rd-taystjk` then `vid_restart` and
try again. If the problem disappears, it belongs to the renderer you were using: if that
was Vulkan see [the Vulkan renderer](#the-vulkan-renderer), and if rend2,
[the rend2 renderer](#the-rend2-renderer).
If it persists on the default renderer it is not a renderer bug. See
[Renderers](/TaystJK/features/renderers/).

**Is it drawn, or is it decided?** Broadly: if the client got it wrong on screen it is ours;
if the outcome itself was wrong, the server decided it.

## The game module

Most of what players think of as "the game" (how movement feels, what a saber does, whether
a shot registered, how a race is timed, what an admin command does) is the server's game
module. On a jaPRO server that is jaPRO's code, and it is developed at
<https://github.com/videoP/jaPRO>.

TaystJK bundles jaPRO's gamecode on both sides: the client-side `cgame` and the
server-side `jampgame`. That is why the two are easy to confuse. Bundling a copy is not
the same as owning it: the code is maintained upstream and pulled down here, and when you
join someone else's server it is *their* module running, not yours. See
[the overview](/TaystJK/overview/).

This is the most common misrouting, and it catches out things that feel client-side: a
truncated warp list, an emote that does not animate, a missing admin command, which force
powers a duel gives you. All of those are rules. Fixes made in jaPRO reach TaystJK when it
is pulled downstream, so filing in the right place is also the faster route.

Before filing with jaPRO, check it happens without TaystJK: for a player on the same server
using another client, and, if you host with TaystJK's bundled game module, on a server
running jaPRO's own build. If it only happens with TaystJK, it is ours.

## The Vulkan renderer

The Vulkan backend is developed upstream by JKSunny, and fixes flow from there to TaystJK.
Check two things before filing:

1. It does not happen on `rd-taystjk`, so it really is Vulkan. "Only happens on Vulkan" is
   the single most useful sentence such a report can contain.
2. It also happens on JKSunny's own EternalJK build with its Vulkan renderer.

If both hold, report it at <https://github.com/JKSunny/EternalJK/issues>. If it only happens
in TaystJK, it is ours.

## The rend2 renderer

rend2 is developed upstream by SomaZ, on the `rend2-unified-wip` branch of SomaZ's OpenJK
fork, and fixes are ported down from there. Check two things before filing:

1. It does not happen on `rd-taystjk`, so it really is rend2.
2. It also happens on a build of SomaZ's
   [`rend2-unified-wip`](https://github.com/SomaZ/OpenJK/tree/rend2-unified-wip) branch.

If both hold, report it at <https://github.com/SomaZ/OpenJK/issues>. If it only happens in
TaystJK, it is ours.

## JA+

JA+ is a closed-source mod. Nobody outside its authors can fix its behaviour, and TaystJK
cannot work around what it does not have source for. If a problem happens only on JA+
servers, there is usually no project to report it to.

What *is* worth reporting here is the client failing to cope, such as crashing or mis-detecting
the server mod. That is our side of the boundary even when the trigger is JA+. The same check
tells them apart: if another client copes with the same JA+ server, the fault is TaystJK's.

Moderation is the usual example. Chat and bans are handled by the game module rather than
the engine, so on a JA+ server the tools you want are in code nobody else can change. The
realistic answer is an open-source server mod, not a client change.

## What makes a report useful

Whichever project you file with:

- the output of `version` and `modversion`, pasted rather than summarised; see
  [builds and versioning](/TaystJK/install/builds-and-versioning/)
- your operating system and whether the build is 32- or 64-bit
- which renderer, and whether switching changes anything
- the server and the mod it runs
- what you did, what happened, and what you expected instead
