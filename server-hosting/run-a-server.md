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

<p class="page-lede">Start with a small, private server; confirm its settings and download list; then expose the game and HTTP ports to the internet.</p>
</div>

## What you need

- The retail `assets0.pk3`, `assets1.pk3`, `assets2.pk3`, and `assets3.pk3` files.
- UDP port `29070` for the game. Open a different UDP port if you change `net_port`.
- TCP port `18200` for the built-in HTTP download server, which the Docker image's `server.cfg` turns on; see [downloads](/TaystJK/server-hosting/downloads/).
- A strong `rconpassword` that is not committed to a public repository.

## Docker Compose

The repository ships a [Docker image and `docker-compose.yml`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/docker-compose.yml). Use that definition from a TaystJK source checkout when possible; it supports both pulling the published image and building the server locally.

For the published image, the relevant files are:

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

The checked-in Compose file defines the normal registry-backed service and an optional `build` profile. Its service definitions are:

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

  taystjk-build:
    build:
      context: .
      dockerfile: Dockerfile
      args:
        TAYSTJK_REF: master
        TAYSTJK_COMMIT: unknown
    profiles: ["build"]
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

To run the published image:

```bash
docker compose pull taystjk
docker compose up -d taystjk
docker compose logs -f taystjk
```

The `taystjk-build` service needs the repository's complete source checkout and `Dockerfile`. From that checkout, use the opt-in profile when you need an image built from the current source:

```bash
docker compose --profile build up -d --build taystjk-build
docker compose logs -f taystjk-build
```

Both services use the same ports, asset mount, homepath mount, architecture, and mod selection as TaystJK's checked-in definition; do not start both at once. The image already contains TaystJK's [shipped `server.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/server.cfg) and the game-mode, vote and ban configs that go with it, installs them under `basepath/taystjk/`, and automatically launches with `+exec server.cfg`. They are written for TaystJK's bundled jaPRO game module; [bundled server configs](/TaystJK/server-hosting/bundled-configs/) describes each file. Start the container once with that configuration before changing it.

The remaining commands in this guide use the published-image service name, `taystjk`. Substitute `taystjk-build` when you are running the source-build profile.

To customize the configuration shipped by your image, copy the file you want to change into the mounted homepath:

```bash
mkdir -p homepath/taystjk
docker compose cp \
  taystjk:/opt/taystjk/basepath/taystjk/server.cfg \
  ./homepath/taystjk/server.cfg
```

Edit the copied file, then apply it with `docker compose restart taystjk`. The homepath copy takes priority over the image's basepath copy and persists across image updates. The same works for `bans.cfg`, `votes.cfg`, `default.cfg` and the mode files. Custom PK3s, reflists, logs, and configuration also belong under `homepath/taystjk/`. Use `docker compose down` to stop the server.

## Native dedicated server

Extract the server files and retain all libraries included with the release. Put the retail assets under `base/` and TaystJK assets under `taystjk/`. Native releases do not include a `server.cfg`: copy the Docker image's configs from [`scripts/docker/`](https://github.com/taysta/TaystJK/tree/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker) into `taystjk/`, as [bundled server configs](/TaystJK/server-hosting/bundled-configs/) explains, or write your own. Then launch:

```bash
./taystjkded.x86_64 \
  +set dedicated 2 \
  +set net_port 29070 \
  +set fs_game taystjk \
  +exec server.cfg
```

On Windows, use the `.exe` dedicated-server binary from the release. A service manager such as systemd or Docker should restart a public server after a crash or host reboot.

## Run the TaystJK server engine with another mod

The dedicated executable and the server-side game rules are separate. You can use the TaystJK dedicated engine while loading another mod's native `jampgame` library, such as JA+ or JA++. In this arrangement TaystJK supplies engine features, networking, and server administration, while the selected mod supplies gameplay. TaystJK game-module commands and cvars are unavailable unless the other mod implements them too.

Install the mod exactly as its own documentation requires, in a directory beside `base/`. The library must match the dedicated executable's operating system and architecture. For example, a 64-bit Linux server needs a compatible `japlus/jampgamex86_64.so`; it cannot load a 32-bit `jampgamei386.so`. If a mod is available only as a 32-bit library, use the matching 32-bit TaystJK dedicated build and its runtime dependencies.

Dedicated builds default `fs_forcegame` to an empty string so that `fs_game` can select the server mod. Leave it empty and launch a modern JA++ server module with:

```bash
./taystjkded.x86_64 \
  +set dedicated 2 \
  +set net_port 29070 \
  +set fs_game japlus \
  +exec server.cfg
```

JA+ and some older or custom mod builds use the legacy native `dllEntry`/`vmMain` interface. Force that interface for the game-module slot by adding `+set vm_legacy 1`:

```bash
./taystjkded.x86_64 \
  +set dedicated 2 \
  +set net_port 29070 \
  +set fs_game japlus \
  +set vm_legacy 1 \
  +exec server.cfg
```

`vm_legacy 1` still loads a native `.dll`, `.so`, or `.dylib`; it does not load a QVM. Omit it for a mod that implements the newer `GetModuleAPI` interface. On a successful legacy start, the console reports `VM_CreateLegacy: jampgame... succeeded`. Also check `path` to confirm that `japlus/` is active and inspect the mod's version cvar before opening the server publicly.

For Docker, put the mod and its configuration under the mounted `homepath/japlus/`, set `TJK_MOD=japlus`, and for a legacy game module set `TJK_OPTS=+exec server.cfg +set vm_legacy 1`. Keep `+exec server.cfg` in that value: the image's default `TJK_OPTS` is just that command ([`Dockerfile`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/Dockerfile#L69)), and setting the variable replaces it. The image's bundled configs live in `taystjk/`, so they do not load for another mod; supply that mod's own `server.cfg`. The image does not include third-party mod files; supply and maintain them yourself. Test upgrades privately because a mod may depend on engine-specific behavior outside the standard module interface.

## Customize the shipped `server.cfg`

The supplied file starts the server on one map, `mp/ffa3` in FFA, and already turns on
downloads: the built-in HTTP server on TCP `18200`, and the UDP downloader for clients that
cannot use HTTP.
Change its example identity and fill in the passwords, which ship empty:

```cfg
// Identity
seta sv_hostname "My TaystJK server"
seta g_motd "Welcome! Have fun"

// Passwords. Keep rconpassword on a "set" line: docker stop reads it from here.
set rconpassword "replace-with-a-long-random-secret"
seta g_fullAdminPass "replace-with-another-secret"
seta g_juniorAdminPass "and-a-third"
```

Keep server settings in this file and gameplay in `default.cfg` and the mode files, so that
loading a mode never changes them. [Bundled server configs](/TaystJK/server-hosting/bundled-configs/)
covers the game modes and vote options, and what to do if you want the map to change by
itself. [jaPRO server setup](/TaystJK/server-hosting/japro-setup/) covers accounts, admins,
voting and bans.

Changes to `sv_httpDownloads` and `sv_httpServerPort` are latched; restart the dedicated
server after changing them. Clients connect to the port number the server advertises, so
keep the same number on both sides of the Compose port mapping: to use `18300`, publish
`18300:18300/tcp` and set `sv_httpServerPort 18300`.

## Verify before going public

1. Join from a second machine or network, not only `localhost`.
2. Confirm UDP `29070` is reachable and the server appears in the expected master list.
3. Load every map you plan to run, and every game mode you plan to offer, and watch the server console for missing files.
4. Run `sv_referencedPakNames`; make sure it contains every required client PK3 and no private or unnecessary archive.
5. Join with a clean client and accept the download prompt. Confirm the transfer uses HTTP and the downloaded map loads.
6. Test RCON, then keep the password out of screenshots, logs, and public configuration files.

Use the [console reference](/TaystJK/reference/?kind=cvar&network=server-authoritative) to inspect server-owned cvars and their exact source registrations.

If the server does not appear in the list, or it keeps rewriting your config, both have
their own entries on [troubleshooting](/TaystJK/troubleshooting/). They are the two things
that go wrong most often here.
