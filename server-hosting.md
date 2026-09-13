---
title: "Server hosting"
layout: reference
nav_order: 3
description: "Run a TaystJK dedicated server with Docker Compose or a native binary, configure rotations, and serve PK3 downloads."
toc: true
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

The repository ships a [Docker image and `docker-compose.yml`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docker-compose.yml). Use that definition from a TaystJK source checkout when possible; it supports both pulling the published image and building the server locally.

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

Both services use the same ports, asset mount, homepath mount, architecture, and mod selection as TaystJK's checked-in definition; do not start both at once. The image already contains TaystJK's [shipped `server.cfg`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/scripts/docker/server.cfg), installs it under `basepath/taystjk/`, and automatically launches with `+exec server.cfg`. Start the container once with that configuration before changing it.

The remaining commands in this guide use the published-image service name, `taystjk`. Substitute `taystjk-build` when you are running the source-build profile.

To customize the exact configuration shipped by your image, copy it into the mounted homepath:

```bash
mkdir -p homepath/taystjk
docker compose cp \
  taystjk:/opt/taystjk/basepath/taystjk/server.cfg \
  ./homepath/taystjk/server.cfg
```

Edit the copied file, then apply it with `docker compose restart taystjk`. The homepath copy takes priority over the image's basepath copy and persists across image updates. Custom PK3s, reflists, logs, and configuration also belong under `homepath/taystjk/`. Use `docker compose down` to stop the server.

## Native dedicated server

Extract the server files and retain all libraries included with the release. Put the retail assets under `base/`, TaystJK assets under `taystjk/`, and customize the `server.cfg` supplied with TaystJK instead of replacing it with a minimal configuration. Then launch:

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

For Docker, put the mod and its configuration under the mounted `homepath/japlus/`, set `TJK_MOD=japlus`, and add `TJK_OPTS=+set vm_legacy 1` only for a legacy game module. The image does not include third-party mod files; supply and maintain them yourself. Test upgrades privately because a mod may depend on engine-specific behavior outside the standard module interface.

## Customize the shipped `server.cfg`

The supplied file already defines a working stock-map rotation. Change its example identity and access settings, then add download settings only if the server needs to distribute custom PK3s:

```cfg
// Identity and access
seta sv_hostname "My TaystJK server"
seta g_motd "Welcome — have fun"
seta rconPassword "replace-with-a-long-random-secret"

// Downloads: UDP fallback plus the built-in HTTP server
seta sv_allowDownload 1
seta sv_httpDownloads 1
seta sv_httpServerPort 18200
```

Edit the existing `d1`, `d2`, and subsequent rotation definitions rather than adding a second rotation beneath them. Changes to `sv_httpDownloads` and `sv_httpServerPort` are latched; restart the dedicated server after changing them.

## Automatic PK3 downloads

TaystJK can serve required PK3 files over fast HTTP and optionally fall back to the legacy UDP downloader.

### Built-in HTTP server

The settings above enable HTTP on TCP `18200`. Forward that TCP port through NAT and allow it through the host firewall, independently of UDP `29070`. With `sv_httpServerPort 0`, the server selects the first free port from `18200` through `18215`; a fixed port is easier to expose from a container or router.

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
2. A recognized native client module marker—currently `cgamex86.dll` or `uix86.dll`—is loaded from it.
3. It is in the active `fs_game` directory rather than `base`.

TaystJK does not currently execute `cgame.qvm` or `ui.qvm`. Its modules are native libraries: `.dll` on Windows, `.so` on Linux, and `.dylib` on macOS. Because the automatic PK3 check uses the two x86 Windows marker names for cross-platform pure-server bookkeeping, add a package explicitly to `ref_forcelist.txt` when it contains only another architecture's module names or client assets that do not otherwise trigger a reference.

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

## Running a pure server with a mod

`sv_pure 1` requires clients to load their client-side modules from a PK3 rather than from
loose files, and the server checks that its own `cgame` and `ui` are packed before it
validates anyone
([`sv_client.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L957)).

The practical consequence: if you run a mod whose `cgame` and `ui` libraries sit loose in
its `fs_game` directory, pure validation fails and clients are rejected. Either pack the
mod's client-side files into a PK3, or run that server with `sv_pure 0`. A stock TaystJK
server is unaffected because its modules ship inside the asset PK3s.

### `sv_pure` does not constrain TaystJK on a `basejka` server

If your server reports its `gamename` as exactly `basejka`, TaystJK clients bypass the pure
restriction ([`cl_parse.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_parse.cpp#L466)).

Two things happen at once. The client marks the base assets pak as referenced so the
checksums it reports back look like a stock client's
([`files.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4169)), and it skips loading your pak list
altogether — which leaves it with no list to restrict against, so every pak it has is
treated as allowed
([`FS_PakIsPure`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L393)).

The effect is that the client authenticates as pure while still loading its own assets:
emoji, cosmetics, HUD files and any other PK3 the player has installed. This is deliberate —
it is what lets TaystJK's client-side additions work on stock servers — but it means
**`sv_pure` is not an asset-parity guarantee for these clients.** If you are relying on pure
to ensure everyone sees identical content, a `basejka` gamename does not give you that.

Servers reporting any other `gamename`, including jaPRO and JA+, are unaffected and pure
behaves normally.

## Server-side demo recording

A dedicated server can record demos itself, independently of anything the players do. The
commands exist only in the dedicated build
([`sv_ccmds.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2343)):

| Command | Does |
|:--|:--|
| `svrecord` | Start recording |
| `svstoprecord` | Stop recording |
| `sv_listrecording` | List what is currently being recorded |
| `svrenamedemo` | Rename a recorded demo |
| `svdemometa` | Attach a metadata entry for one player: clientnum, key, value |
| `svdemoclearmeta` | Clear one player's metadata |
| `svdemoclearprerecord` | Discard one player's buffered pre-record data |

Demos are written under `demos/` in the server's game directory.

### Pre-recording

The problem with recording on demand is that the interesting thing has already happened by
the time you type the command. Pre-recording keeps a rolling buffer so a demo can be
started *retroactively*.

```text
seta sv_demoPreRecord 1
seta sv_demoPreRecordTime 15
```

`sv_demoPreRecordTime` is how many seconds are kept. A demo can only begin from a full
snapshot, so the server periodically stores one; `sv_demoPreRecordKeyframeDistance` controls
how often, in seconds. A larger gap costs less memory and coarsens how far back a demo can
actually start. `sv_demoPreRecordBots` extends the buffer to bots, which is off by default
because it is usually wasted work.

Buffering runs per connected client, so the memory cost scales with your player count as
well as with the time window. Raise `sv_demoPreRecordTime` deliberately.

`sv_demoWriteMeta` controls whether the metadata set by `svdemometa` — and by the game
module — is written into the demo. It is on by default and invisible to ordinary playback.

## Verify before going public

1. Join from a second machine or network, not only `localhost`.
2. Confirm UDP `29070` is reachable and the server appears in the expected master list.
3. Load every map in the rotation and watch the server console for missing files.
4. Run `sv_referencedPakNames`; make sure it contains every required client PK3 and no private or unnecessary archive.
5. Join with a clean client and accept the download prompt. Confirm the transfer uses HTTP and the downloaded map loads.
6. Test RCON, then keep the password out of screenshots, logs, and public configuration files.

Use the [console reference](/TaystJK/reference/?kind=cvar&network=server-authoritative) to inspect server-owned cvars and their exact source registrations.
