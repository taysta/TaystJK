---
title: "Where to report"
layout: reference
nav_order: 2
parent: "Help"
description: "Which project owns a problem: the client, the server's game module, the Vulkan renderer, or a closed-source mod."
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
| How the game *plays*: movement, saber behaviour, scoring, admin commands, race and defrag | [videoP/jaPRO](https://github.com/videoP/jaPRO) |
| Something only wrong on the Vulkan renderer | [JKSunny/EternalJK](https://github.com/JKSunny/EternalJK) |
| Something only wrong on the rend2 renderer | [taysta/TaystJK](https://github.com/taysta/TaystJK); see [Renderers](/TaystJK/features/renderers/#where-a-renderer-bug-goes) |
| Something only wrong on a JA+ server | Nowhere; see below |

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
try again. If the problem disappears, it belongs to the renderer you were using, and if that
was Vulkan it belongs to JKSunny. If it persists on the default renderer it is not a
renderer bug. See [Renderers](/TaystJK/features/renderers/).

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

## The Vulkan renderer

The Vulkan backend is developed upstream by JKSunny and fixes flow from there to TaystJK, so
Vulkan-specific rendering problems belong at
<https://github.com/JKSunny/EternalJK>.

Check first that it really is Vulkan-specific by switching to `rd-taystjk`. "Only happens on
Vulkan" is the single most useful sentence such a report can contain.

## JA+

JA+ is a closed-source mod. Nobody outside its authors can fix its behaviour, and TaystJK
cannot work around what it does not have source for. If a problem happens only on JA+
servers, there is usually no project to report it to.

What *is* worth reporting here is the client failing to cope, such as crashing or mis-detecting
the server mod. That is our side of the boundary even when the trigger is JA+.

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
