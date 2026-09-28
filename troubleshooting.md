---
title: "Troubleshooting"
layout: reference
nav_order: 1
parent: "Help"
description: "Fixes for the problems players and server admins hit most often, listed by what you actually see."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Start here</p>

# Troubleshooting

<p class="page-lede">Listed by symptom: what you see, not what causes it. If your problem is that something behaves differently on one server than another, that is usually not a bug; see mod compatibility.</p>
</div>

## My server does not appear in the server list

Almost always one of three things, in this order.

**Your server is not set to public.** `dedicated 1` is LAN play; only `dedicated 2` sends
heartbeats to the master servers, and the source says so in as many words
([`sv_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_main.cpp#L257)).
A server on `dedicated 1` is working correctly and will never appear on the internet tab.
Check the local tab before assuming it is broken.

**You are waiting on the master.** The server sends its first heartbeat as soon as a map
loads ([`sv_init.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_init.cpp#L743)) and another every five minutes
after that ([`sv_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_main.cpp#L250)). If you think one was
missed, run `heartbeat` in the server console to send one immediately rather than
restarting the server.

**The default master is dead.** `sv_master1` still defaults to `masterjk3.ravensoft.com`,
Raven's original master, which has not answered in many years. The working ones are
`master.jkhub.org`, the default for `sv_master2`, and `master.ouned.de`, the default for
`sv_master3`. Leaving the dead one in place costs nothing. If you have overridden the master
cvars, make sure a live one is still in the list. Look each up in the
[console reference](/TaystJK/reference/?q=sv_master).

Beyond that: the game port is UDP and must be forwarded to the server. If you changed
`net_port`, forward the port you actually chose, not the default.

## The dedicated server keeps rewriting my config

It is doing what it was built to do. On shutdown the engine writes every archived cvar back
to its own generated config, `taystjk_server.cfg` on a dedicated server
([`common.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L1587)),
so anything you typed into that file by hand is replaced by the engine's own idea of the
current value.

Keep your settings in a file of your own and load it explicitly:

```text
+exec server.cfg
```

Your file is then the source of truth and the generated config is just a dump. Do not edit
the generated one. See [run a server](/TaystJK/server-hosting/run-a-server/#customize-the-shipped-servercfg).

The same dump explains a server that starts up with the previous game mode's weapons or force
powers still applied: the mode's settings were saved at shutdown and loaded again. The Docker
image's `server.cfg` avoids this by running `exec default` before the first map, which puts
gameplay back to its baseline; see
[bundled server configs](/TaystJK/server-hosting/bundled-configs/#server-settings-and-gameplay-are-kept-apart).

## The game will not open on macOS after an update

macOS re-applies the quarantine attribute to every fresh download, so an update quarantines
the new copy even though the previous one ran. The app is ad-hoc signed at release, so this
is not a signing problem and re-signing is not the fix.

Clearing the attribute is covered step by step on the
[install page](/TaystJK/install/). Follow it there rather than copying a command from
memory, because the guidance about when `sudo` is and is not appropriate matters.

Approving the app in System Settings is not a substitute for clearing the attribute, and
this is why an install that worked yesterday can fail today: it is the *replacement* that
is quarantined, not your original install.

If the client instead fails naming a library it could not load, that is not quarantine.
Take a current build first. That class of fault has been a packaging problem more than
once. If a current build still does it, report it.

## The client disconnects or crashes when joining a modded server

Three different things get reported this way, and only one of them is a crash. Work out
which you have before changing anything:

- **You stay connected, but the mod's HUD, menus or features are missing.** A mod module
  did not load and the client used its own. See
  [mod compatibility](/TaystJK/install/mod-compatibility/#first-check-whether-the-mods-modules-load).
- **You are dropped back to the menu with an error.**
- **The client closes**, with or without an error box.

An old mod's 32-bit libraries do not cause either of the last two by themselves. The client
asks only for the module name that matches its own architecture
([`cgame`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_cgameapi.cpp#L1703),
[`ui`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_uiapi.cpp#L1316))
and looks for it in the server's mod directory, then `taystjk`, then `base`
([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/shared/sys/sys_main.cpp#L404)).
A 64-bit Windows client asks for `cgamex86_64.dll` and never tries a `cgamex86.dll` sitting
beside it; it loads TaystJK's own `cgame` instead, which is the first case above. To use a
mod's own client libraries, they have to match your build; see
[running another client-side mod](/TaystJK/install/#mods-that-package-native-libraries-inside-a-pk3).

Reproduce it once and keep:

- The console output from joining. If the client closes before you can read it, launch
  with `+set logfile 2`, which writes `qconsole.log` unbuffered so it survives the exit
  ([`common.cpp`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/qcommon/common.cpp#L216)).
- The output of `arch`, which names your build's platform and architecture
  ([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/shared/sys/sys_main.cpp#L166)),
  and `version`.
- Which `cgame` and `ui` files the mod directory holds, loose or inside a PK3.
- For a client that closed, any crash report or stack trace your system produced.

Then read the console:

- **`Sys_LoadGameDll(<path>) failed: "<reason>"`** and the same from
  `Sys_LoadLegacyGameDll` are not errors on their own. The client prints one for every
  place it tried and could not load
  ([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/shared/sys/sys_main.cpp#L417)),
  then moves on to the next. The reason is the operating system's, so a line naming the mod
  directory with something other than a missing file means the mod has a library of that
  name that does not load on your system.
- **`VM_CreateLegacy on cgame failed`**, or `on ui`, drops you to the menu
  ([`cgame`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_cgameapi.cpp#L1932),
  [`ui`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_uiapi.cpp#L1490)).
  The first library the client could load has neither module interface, or none loaded at
  all. The `failed` lines above it show which paths were tried: either the mod directory
  holds a file of that name that is not a usable module, or TaystJK's own copy is
  missing and the install needs repairing.
- **`GetGameAPI failed on`** followed by a library name closes the client
  ([`cgame`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_cgameapi.cpp#L1921),
  [`ui`](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/client/cl_uiapi.cpp#L1475)).
  The library loaded but refused the engine's module API version. See
  [when to use `vm_legacy`](/TaystJK/install/#when-to-use-vm_legacy).
- **Anything else, or a crash with no error**, is not explained by the module search.
  Take a current build first, then check whether the same server and mod fail in another
  client. Report it with what you collected;
  [where to report](/TaystJK/where-to-report/#before-you-send-it-elsewhere) covers whether
  it belongs with the mod's author or here.

## A server's files will not download

Watch the console while you connect; each case says what it is.

**"Skipping downloads, because the server does not allow downloads."** The server has turned
downloads off, so you need to get the files some other way and install them yourself
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L1713)).

**"You are missing some files referenced by the server."** Your own client has downloads
off. Set `cl_allowDownload 1`, which is the default, and reconnect
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L1701)).

**Nothing happens and the connection waits.** The client is asking whether to download, and
the question is on screen, not in the console. `cl_downloadPrompt 0` skips the question in
future ([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L1594)).

**"Incorrect checksum for file."** The file the server sent is not the one it said it would
send. That is the server's to fix; tell its administrator
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L1622)).

Server operators: the setup, including HTTP downloads and reflists, is on
[Server hosting](/TaystJK/server-hosting/downloads/#automatic-pk3-downloads).

## A map I downloaded is missing everywhere else

Downloaded files are saved with a `dl_` prefix, as `dl_<name>.pk3` in the server's mod
directory ([`files.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/files.cpp#L3623)), and a `dl_` file is only loaded
while the server you are on references it
([`files.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/files.cpp#L3432)). So a map you downloaded from one server
does not appear in your own map list or on a server that does not use it. That stops one
server's content from changing what you see on the next.

If you want a downloaded pk3 everywhere, and you trust it, rename it to drop the `dl_`
prefix. It then loads like any other pk3 in that directory.

## No saber hum, or sound distances are wrong, on Linux

Update your build before anything else. Both symptoms have been caused by the same
regression in how non-Windows builds select their audio path, and that was reverted. On
a current build this should be gone.

If a current build still does it, it is something new. Say which build, and check the SDL
audio driver the client names at startup
([`sdl_sound.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/sdl/sdl_sound.cpp#L189)).
