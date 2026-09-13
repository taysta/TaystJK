---
title: "Troubleshooting"
layout: reference
nav_order: 9
description: "Fixes for the problems players and server admins hit most often, listed by what you actually see."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Start here</p>

# Troubleshooting

<p class="page-lede">Listed by symptom — what you see, not what causes it. If your problem is that something behaves differently on one server than another, that is usually not a bug; see mod compatibility.</p>
</div>

## My server does not appear in the server list

Almost always one of three things, in this order.

**Your server is not set to public.** `dedicated 1` is LAN play; only `dedicated 2` sends
heartbeats to the master servers, and the source says so in as many words
([`sv_main.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L257)).
A server on `dedicated 1` is working correctly and will never appear on the internet tab.
Check the local tab before assuming it is broken.

**You are waiting on the heartbeat.** Heartbeats go out every five minutes, so a server that
just started is not listed yet. Wait rather than restarting it repeatedly.

**The default master is dead.** `sv_master1` still defaults to `masterjk3.ravensoft.com`,
Raven's original master, which has not answered in many years. The working ones are
`sv_master2` (`master.jkhub.org`) and `sv_master3` (`master.ouned.de`), and all three are
polled, so leaving the dead one alone costs nothing — but if you have overridden the master
cvars, make sure a live one is still in the list. Look each up in the
[console reference](/TaystJK/reference/).

Beyond that: the game port is UDP and must be forwarded to the server. If you changed
`net_port`, forward the port you actually chose, not the default.

## The dedicated server keeps rewriting my config

It is doing what it was built to do. On shutdown the engine writes every archived cvar back
to its own generated config
([`common.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1587)),
so anything you typed into that file by hand is replaced by the engine's own idea of the
current value.

Keep your settings in a file of your own and load it explicitly:

```text
+exec server.cfg
```

Your file is then the source of truth and the generated config is just a dump. Do not edit
the generated one. See [Server hosting](/TaystJK/server-hosting/).

## The game will not open on macOS after an update

macOS re-applies the quarantine attribute to every fresh download, so an update quarantines
the new copy even though the previous one ran. The app is ad-hoc signed at release, so this
is not a signing problem and re-signing is not the fix.

Clearing the attribute is covered step by step on the
[install page](/TaystJK/install/) — follow it there rather than copying a command from
memory, because the guidance about when `sudo` is and is not appropriate matters.

Approving the app in System Settings is not a substitute for clearing the attribute, and
this is why an install that worked yesterday can fail today: it is the *replacement* that
is quarantined, not your original install.

If the client instead fails naming a library it could not load, that is not quarantine.
Take a current build first — that class of fault has been a packaging problem more than
once — and if a current build still does it, report it.

## The client crashes when joining a modded server

Usually an architecture mismatch rather than a crash in the client.

Game modules are loaded by a filename that includes the architecture
([`sv_gameapi.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_gameapi.cpp#L2849)),
so a mod directory holding 32-bit `cgame` and `ui` libraries cannot be loaded by a 64-bit
client. If a mod was installed years ago alongside a 32-bit build, it will still be sitting
in `GameData` and the client will try to use it.

What you see is a crash or an immediate disconnect on joining a server that sets `fs_game`
to that directory, while everything else works. Either install the matching build of the
mod, or remove the stale mod directory. The [install guide](/TaystJK/install/) covers
keeping TaystJK separate from an older installation. The common case is a 32-bit JA+ `ui`
library against a 64-bit client: run the 32-bit build if you want that mod's client-side
pieces.

**If the architecture already matches and it still crashes**, the mod is probably built
against the older module API. The giveaway is that the client dies on the first console
command you type. The fix is `vm_legacy`, set on the command line before the modules load;
the install guide explains which bits to use for which module in
[when to use `vm_legacy`](/TaystJK/install/#when-to-use-vm_legacy). Nothing detects this for
you.

A third cause is the mod's own assets rather than its code — an oversized texture can
exhaust a 32-bit client's memory while loading. If a single mod fails everywhere and others
are fine, that belongs with the mod's author; see
[where to report](/TaystJK/where-to-report/).

If the client connects but a *feature* is missing rather than crashing, that is a different
question — see [mod compatibility](/TaystJK/mod-compatibility/).

## No saber hum, or sound distances are wrong, on Linux

Update your build before anything else. Both symptoms have been caused by the same
regression in how non-Windows builds select their audio path, and that was reverted — so on
a current build this should be gone.

If a current build still does it, it is something new. Say which build, and check the SDL
audio driver the client names at startup
([`sdl_sound.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_sound.cpp#L189)).
