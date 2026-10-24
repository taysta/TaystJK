---
title: "Run a server"
layout: reference
nav_order: 1
parent: "Server hosting"
description: "Run a TaystJK dedicated server with Docker Compose or a native binary, or with another mod's game module, and check it before opening it to the public."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# Run a server

<p class="page-lede">Get the server running privately first, check its settings and download list, and only then list it publicly and open its ports.</p>
</div>

## What you need

- The retail `assets0.pk3`, `assets1.pk3`, `assets2.pk3`, and `assets3.pk3` files.
- UDP port `29070` for the game.
- TCP port `18200` for the built-in HTTP download server, which the shipped `server.cfg` turns on; see [downloads](/TaystJK/server-hosting/downloads/).
- A strong `rconpassword` that is not committed to a public repository.

`dedicated 2` lists the server with the master servers, so it shows up in everyone's server
browser. `dedicated 1` keeps it to your local network. Use `1` while you set it up.

## Choose how to run it

Both run the same dedicated server and the same game module; they differ in how you install,
update and restart it. Your selection is saved on this device.

<section class="platform-guide" data-hosting-guide>
  <div class="platform-selector-shell">
    <p class="platform-selector-label">Run the server with</p>
    <div class="platform-selector" role="tablist" aria-label="How to run the server">
      <button type="button" id="hosting-tab-docker" role="tab" aria-controls="hosting-panel-docker" aria-selected="false" tabindex="-1" data-hosting-choice="docker">Docker Compose</button>
      <button type="button" id="hosting-tab-dedicated" role="tab" aria-controls="hosting-panel-dedicated" aria-selected="false" tabindex="-1" data-hosting-choice="dedicated">Dedicated server</button>
    </div>
  </div>

  <section class="platform-panel" id="hosting-panel-docker" role="tabpanel" aria-labelledby="hosting-tab-docker" tabindex="0" data-hosting-panel="docker" markdown="1">
## Docker Compose

The published image contains the 64-bit and 32-bit Linux dedicated servers and the
[bundled server configs](/TaystJK/server-hosting/bundled-configs/). Compose restarts the
server when it stops
([`docker-compose.yml`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/docker-compose.yml#L36)),
and everything you change lives in a mounted directory that survives image updates. You
need Docker on the host.

Make a directory for the server, download the repository's
[`docker-compose.yml`](https://github.com/taysta/TaystJK/blob/master/docker-compose.yml)
into it, and put the game's assets in `base/`:

```sh
mkdir -p taystjk-server/base taystjk-server/homepath
cd taystjk-server
curl -fLO https://raw.githubusercontent.com/taysta/TaystJK/master/docker-compose.yml
cp /path/to/GameData/base/assets*.pk3 base/
```

That gives you:

```text
taystjk-server/
├── docker-compose.yml
├── base/
│   ├── assets0.pk3
│   ├── assets1.pk3
│   ├── assets2.pk3
│   └── assets3.pk3
└── homepath/
```

The service you run is `taystjk`:

```yaml
services:
  taystjk:
    image: ghcr.io/taysta/taystjk:latest
    ports:
      - "29070:29070/udp"
      - "18200:18200/tcp"
    volumes:
      - ./base:/opt/taystjk/cdpath/base
      - ./homepath:/opt/taystjk/homepath
    environment:
      - TJK_MOD=taystjk
      - TJK_ARCH=x86_64
    restart: unless-stopped
```

Start it and follow the log:

```sh
docker compose pull taystjk
docker compose up -d taystjk
docker compose logs -f taystjk
```

The image launches the server with `dedicated 2`. To keep it unlisted while you set it up,
add `TJK_OPTS=+set dedicated 1 +exec server.cfg` under `environment`, and remove it when you
are ready.

The image already contains TaystJK's [shipped `server.cfg`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker/server.cfg)
and the game-mode, vote and ban configs that go with it, under `basepath/taystjk/`, and
starts with `+exec server.cfg`. They are written for TaystJK's bundled jaPRO game module;
[bundled server configs](/TaystJK/server-hosting/bundled-configs/) describes each file. Start
the container once with them before changing anything.

To change a shipped file, copy it into the mounted homepath:

```sh
mkdir -p homepath/taystjk
docker compose cp \
  taystjk:/opt/taystjk/basepath/taystjk/server.cfg \
  ./homepath/taystjk/server.cfg
```

Edit the copy, then apply it with `docker compose restart taystjk`. The homepath copy takes
priority over the image's and survives image updates. The same works for `bans.cfg`,
`votes.cfg`, `default.cfg` and the mode files. Custom PK3s, reflists and logs also belong
under `homepath/taystjk/`. Use `docker compose down` to stop the server.

**Change ports on the host side.** Inside the container the server always listens on UDP
`29070`: the run script sets it, and both the health check and the clean shutdown sent when
the container stops go to that port
([`run.sh`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker/run.sh#L13),
[`functions.sh`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker/functions.sh#L11)).
To run on `29071`, publish `29071:29070/udp` and leave `net_port` alone. The image's health
check asks the server for its status every ten seconds
([`Dockerfile`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/Dockerfile#L72)),
so `docker compose ps` shows whether it is answering.

The compose file also has a `taystjk-build` service, behind the `build` profile, that builds
the image from a full source checkout instead of pulling it:
`docker compose --profile build up -d --build taystjk-build`. It uses the same ports and
mounts, so do not run both at once, and use `taystjk-build` in place of `taystjk` in the
commands on this page.
  </section>

  <section class="platform-panel" id="hosting-panel-dedicated" role="tabpanel" aria-labelledby="hosting-tab-dedicated" tabindex="0" data-hosting-panel="dedicated" markdown="1">
## Dedicated server

The dedicated server, `taystjkded`, is in the same release archive as the client. You start
it yourself, and you look after its files, its configuration and restarting it.

Extract the whole archive, keeping its libraries and its `taystjk/` directory, which holds
TaystJK's game module and `japro-assets.pk3`. Put the retail assets in `base/`. Native
releases do not include a `server.cfg`: copy the Docker image's configs from
[`scripts/docker/`](https://github.com/taysta/TaystJK/tree/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker)
into `taystjk/`, as [bundled server configs](/TaystJK/server-hosting/bundled-configs/)
explains, build a set with the [config generator](/TaystJK/server-hosting/config-generator/),
or write your own. Then launch it on Linux with:

```sh
./taystjkded.x86_64 \
  +set dedicated 1 \
  +set net_port 29070 \
  +set fs_game taystjk \
  +exec server.cfg
```

On Windows the executable is `taystjkded.x86_64.exe`, and the options are the same:

```bat
taystjkded.x86_64.exe +set dedicated 1 +set net_port 29070 +set fs_game taystjk +exec server.cfg
```

The 32-bit builds name it `taystjkded.i386` on Linux and `taystjkded.x86.exe` on Windows. The
universal macOS archive's is plain `taystjkded`. Change `dedicated 1` to `2` when you are
ready to list the server, and if you change `net_port`, forward that port instead.

A public server should restart after a crash or a reboot. On Linux, a systemd unit does that;
adjust the user and paths:

```ini
# /etc/systemd/system/taystjk.service
[Unit]
Description=TaystJK dedicated server
After=network-online.target

[Service]
User=taystjk
WorkingDirectory=/opt/taystjk
ExecStart=/opt/taystjk/taystjkded.x86_64 +set dedicated 2 +set net_port 29070 +set fs_game taystjk +exec server.cfg
Restart=on-failure

[Install]
WantedBy=multi-user.target
```

Enable it with `sudo systemctl enable --now taystjk`, and read its output with
`journalctl -u taystjk -f`.
  </section>

</section>

## Run the TaystJK server engine with another mod

The dedicated executable and the server-side game rules are separate. You can run the TaystJK
dedicated engine with another mod's native `jampgame` library, such as JA+ or JA++. TaystJK
then supplies the engine features, networking and server administration, and the mod
supplies the gameplay. TaystJK's game-module commands and cvars are not available unless the
other mod has them too.

Install the mod as its own documentation says, in a directory beside `base/`. The library
must match the dedicated executable's operating system and architecture: a 64-bit Linux
server needs a `japlus/jampgamex86_64.so` and cannot load a 32-bit `jampgamei386.so`. If a
mod only comes as a 32-bit library, use the 32-bit TaystJK dedicated server. JA+ 2.4 is one:
it ships only `jampgamei386.so` for Linux, so it needs `taystjkded.i386`.

Linux mods ship the server library loose, as JA+ 2.4's `jampgamei386.so` is, but Windows
mods often pack `jampgamex86.dll` in a PK3; JA+ 2.4 ships it only in `jampgamex86.pk3`. The
Windows dedicated server loads it from there with `+set com_unpackLibraries 1` on the command
line, or you can extract it beside the PK3 as
[mods that package native libraries inside a PK3](/TaystJK/install/mod-compatibility/#mods-that-package-native-libraries-inside-a-pk3)
describes. Linux and macOS servers never unpack a library from a PK3
([`sys_unix.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_unix.cpp#L566)).

When the mod directory has no library the server can load, the engine falls back to TaystJK's
own jaPRO module in `taystjk/`
([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L421)),
so before opening the server run `serverinfo` in its console and check that `gamename` is the
mod's.

Dedicated builds leave `fs_forcegame` empty so that `fs_game` can select the server mod.
Leave it empty and launch a 64-bit JA++ server module with:

```sh
./taystjkded.x86_64 \
  +set dedicated 1 \
  +set net_port 29070 \
  +set fs_game japlus \
  +exec server.cfg
```

or JA+ 2.4 on the 32-bit server with:

```sh
./taystjkded.i386 \
  +set dedicated 1 \
  +set net_port 29070 \
  +set fs_game japlus \
  +exec server.cfg
```

The engine loads either module interface by itself. It looks for the newer `GetModuleAPI`
entry point first and, when a library does not export one, falls back to the older
`dllEntry`/`vmMain` interface that JA+ and other older modules use
([`sv_gameapi.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_gameapi.cpp#L3182)).
`serverinfo` shows which one it used: `sv_legacyGameAPI` is `1` for the older interface and
`0` for `GetModuleAPI`
([`sv_gameapi.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_gameapi.cpp#L2845)).
You do not need `vm_legacy` for this; it only forces the older interface on a library that
has both ([when to use `vm_legacy`](/TaystJK/install/mod-compatibility/#when-to-use-vm_legacy)).
Run `path` to confirm that `japlus/` is active, and check the mod's own version cvar before
opening the server.

### Another mod under Docker

Put the mod and its configuration under the mounted `homepath/japlus/` and set
`TJK_MOD=japlus`. For a 32-bit module such as JA+ 2.4, also set `TJK_ARCH=i386`: the image
has both the `x86_64` and `i386` dedicated servers and runs the one `TJK_ARCH` names
([`run.sh`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker/run.sh#L14)).

- The image's bundled configs live in `taystjk/`, so they do not load for another mod.
  Supply that mod's own `server.cfg`, or build one from base Jedi Academy's settings with the
  [server config generator](/TaystJK/server-hosting/config-generator/).
- If you set `TJK_OPTS`, keep `+exec server.cfg` in it. The image's default `TJK_OPTS` is just
  that command
  ([`Dockerfile`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/Dockerfile#L69)),
  and setting the variable replaces it.
- The image does not include third-party mod files; you supply and update them.

Test upgrades privately, because a mod may rely on engine behaviour outside the standard
module interface.

## Customize the shipped `server.cfg`

The shipped file starts the server on one map, `mp/ffa3` in FFA, and already turns on
downloads: the built-in HTTP server on TCP `18200`, and the UDP downloader for clients that
cannot use HTTP. Change its example identity and fill in the passwords, which ship empty:

```cfg
// Identity
seta sv_hostname "My TaystJK server"
seta g_motd "Welcome! Have fun"

// Passwords. Keep rconpassword on a "set" line: docker stop reads it from here.
set rconpassword "replace-with-a-long-random-secret"
seta g_fullAdminPass "replace-with-another-secret"
seta g_juniorAdminPass "and-a-third"
```

To start from a full set with these already filled in, build it with the
[server config generator](/TaystJK/server-hosting/config-generator/) instead.

Keep server settings in this file and gameplay in `default.cfg` and the mode files, so that
loading a mode never changes them. [Bundled server configs](/TaystJK/server-hosting/bundled-configs/)
covers the game modes and vote options, and how to make the map change by itself.
[jaPRO server setup](/TaystJK/server-hosting/japro-setup/) covers accounts, admins, voting
and bans.

Changes to `sv_httpDownloads` and `sv_httpServerPort` are latched; restart the dedicated
server after changing them. Clients connect to the port number the server advertises, so
keep the same number on both sides of the Compose port mapping: to use `18300`, publish
`18300:18300/tcp` and set `sv_httpServerPort 18300`.

## Verify before going public

1. Join from a second machine or network, not only `localhost`.
2. Load every map you plan to run, and every game mode you plan to offer, and watch the server console for missing files.
3. Run `sv_referencedPakNames`; make sure it contains every required client PK3 and no private or unnecessary archive.
4. Join with a clean client and accept the download prompt. Confirm the transfer uses HTTP and the downloaded map loads.
5. Test RCON, then keep the password out of screenshots, logs, and public configuration files.
6. Switch to `dedicated 2`, open UDP `29070` and TCP `18200`, and check the server appears in the server browser's internet list.

Use the [console reference](/TaystJK/reference/?kind=cvar&network=server-authoritative) to inspect server-owned cvars and their exact source registrations.

If the server does not appear in the list, or it keeps rewriting your config,
[troubleshooting](/TaystJK/troubleshooting/) has an entry for each. They are the two things
that go wrong most often here.
