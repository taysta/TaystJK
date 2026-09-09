---
title: "Server hosting"
layout: reference
nav_order: 3
description: "Run a TaystJK dedicated server with Docker Compose or a native binary, configure rotations, and serve PK3 downloads."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# Host a TaystJK server

<p class="page-lede">Start with a small, private server; confirm its map rotation and download list; then expose the game and HTTP ports to the internet.</p>
</div>

## What you need

- The retail `assets0.pk3`, `assets1.pk3`, `assets2.pk3`, and `assets3.pk3` files.
- UDP port `29070` for the game. Open a different UDP port if you change `net_port`.
- TCP port `18200` when you use the built-in HTTP download server with the configuration below.
- A strong `rconPassword` that is not committed to a public repository.

## Docker Compose

The repository ships a [Docker image and Compose definition](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docker-compose.yml). This is the shortest repeatable setup on a Linux host with Docker installed.

Create this directory structure:

```text
taystjk-server/
├── compose.yaml
├── base/
│   ├── assets0.pk3
│   ├── assets1.pk3
│   ├── assets2.pk3
│   └── assets3.pk3
└── homepath/
    └── taystjk/
        └── server.cfg
```

Use this `compose.yaml`:

```yaml
services:
  taystjk:
    image: ghcr.io/taysta/taystjk:latest
    ports:
      - "29070:29070/udp"
      - "18200:18200/tcp"
    volumes:
      - ./base:/opt/taystjk/cdpath/base:ro
      - ./homepath:/opt/taystjk/homepath
    environment:
      TJK_MOD: taystjk
      TJK_ARCH: x86_64
      TJK_OPTS: +exec server.cfg
    restart: unless-stopped
```

From that directory, run:

```bash
docker compose pull
docker compose up -d
docker compose logs -f taystjk
```

Use `docker compose down` to stop it. Custom PK3s, reflists, logs, and `server.cfg` persist under `homepath/taystjk/`.

## Native dedicated server

Extract the server files and retain all libraries included with the release. Put the retail assets under `base/`, TaystJK assets and configuration under `taystjk/`, then launch:

```bash
./taystjkded.x86_64 \
  +set dedicated 2 \
  +set net_port 29070 \
  +set fs_game taystjk \
  +exec server.cfg
```

On Windows, use the `.exe` dedicated-server binary from the release. A service manager such as systemd or Docker should restart a public server after a crash or host reboot.

## A useful `server.cfg`

Save this as `taystjk/server.cfg` and replace the example values:

```cfg
// Identity and access
seta sv_hostname "My TaystJK server"
seta g_motd "Welcome — have fun"
seta sv_maxclients 16
seta g_password ""
seta rconPassword "replace-with-a-long-random-secret"

// Network and consistency
seta sv_maxRate 90000
seta sv_fps 40

// Downloads: UDP fallback plus the built-in HTTP server
seta sv_allowDownload 1
seta sv_httpDownloads 1
seta sv_httpServerPort 18200

// Two-map FFA rotation
set d1 "set g_gametype 0; map mp/ffa3; set nextmap vstr d2"
set d2 "set g_gametype 0; map mp/ffa5; set nextmap vstr d1"
vstr d1
```

Changes to `sv_httpDownloads` and `sv_httpServerPort` are latched; restart the map or server after changing them. The [checked-in sample configuration](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/scripts/docker/server.cfg) contains a longer stock-map rotation.

## Automatic PK3 downloads

TaystJK can serve required PK3 files over fast HTTP and optionally fall back to the legacy UDP downloader.

### Built-in HTTP server

The sample above enables HTTP on TCP `18200`. Forward that TCP port through NAT and allow it through the host firewall, independently of UDP `29070`. With `sv_httpServerPort 0`, the server selects the first free port from `18200` through `18215`; a fixed port is easier to expose from a container or router.

Clients need `cl_allowDownload 1`. By default TaystJK asks before downloading and stores conflicting downloads with a `dl_` name plus a checksum so content from one server does not silently replace content used elsewhere.

### External HTTP server

Instead of the built-in server, set `sv_httpServerPort` to an `http://` URL that points at a web root laid out like `GameData`:

```cfg
seta sv_httpDownloads 1
seta sv_httpServerPort "http://downloads.example.org/jka"
```

For a referenced file named `taystjk/maps-pack.pk3`, the web server must therefore serve `http://downloads.example.org/jka/taystjk/maps-pack.pk3`. The current implementation accepts `http://`, not `https://`; put a compatible HTTP endpoint in front of the files if you use an external host.

Do not put spaces or `@` in downloadable PK3 filenames. After changing downloadable content, restart the map and check the reference list before inviting players.

## PK3 referencing and reflists

Only referenced PK3s are offered to clients. TaystJK automatically references a PK3 when:

1. A BSP map is loaded from it.
2. `cgame.qvm` or `ui.qvm` is loaded from it.
3. It is in the active `fs_game` directory rather than `base`.

Run `sv_referencedPakNames` in the server console to inspect the current result. Reflist files let you correct the automatic decision:

| File | Effect |
|:--|:--|
| `ref_forcelist.txt` | Always reference each listed PK3; useful for client assets such as sounds or skins. |
| `ref_blacklist.txt` | Never reference the listed PK3s. |
| `ref_whitelist.txt` | Allow only the listed PK3s to be referenced. |

Place reflists in `base/` or the active `taystjk/` directory. Use one `game-directory/pak-name.pk3` path per line:

```text
base/ffa_custom.pk3
taystjk/community-assets.pk3
```

You may combine a force list with a whitelist or blacklist. Avoid using whitelist and blacklist together: the result is difficult to reason about, and a whitelist is already a complete allow-list. A force list offers a file; it does not remove the client's download confirmation.

The behavior is inherited from JK2MV; its wiki has useful background on [downloaded files](https://github.com/mvdevs/jk2mv/wiki/Downloaded-Files), [HTTP downloads](https://github.com/mvdevs/jk2mv/wiki/HTTP-Downloads), and [PK3 referencing](https://github.com/mvdevs/jk2mv/wiki/PK3-Referencing).

## Verify before going public

1. Join from a second machine or network, not only `localhost`.
2. Confirm UDP `29070` is reachable and the server appears in the expected master list.
3. Load every map in the rotation and watch the server console for missing files.
4. Run `sv_referencedPakNames`; make sure it contains every required client PK3 and no private or unnecessary archive.
5. Join with a clean client and accept the download prompt. Confirm the transfer uses HTTP and the downloaded map loads.
6. Test RCON, then keep the password out of screenshots, logs, and public configuration files.

Use the [console reference](/TaystJK/reference/?kind=cvar&network=server-authoritative) to inspect server-owned cvars and their exact source registrations.
