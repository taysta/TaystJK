---
title: "Downloads and PK3 references"
layout: reference
nav_order: 2
parent: "Server hosting"
description: "Serve required PK3s over HTTP or UDP, control which PK3s are referenced with reflists, and see what sv_pure does and does not check."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# Downloads and PK3 references

<p class="page-lede">How players get the files your server needs, and how the server decides which files those are.</p>
</div>

## Automatic PK3 downloads

TaystJK can serve required PK3 files over HTTP, and over the older UDP downloader for
clients that cannot use HTTP. The Docker image's [`server.cfg`](/TaystJK/server-hosting/bundled-configs/)
turns both on:

```cfg
seta sv_allowDownload 1
seta sv_httpDownloads 1
seta sv_httpServerPort 18200
```

A TaystJK client uses HTTP whenever the server advertises it
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_main.cpp#L1548)), and if an HTTP download fails it
disconnects with a download error rather than retrying over UDP
([`cl_parse.cpp`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_parse.cpp#L749)). The UDP downloader serves clients
without HTTP support, such as OpenJK, EternalJK and the original game, and only while
`sv_allowDownload` is on
([`sv_client.cpp`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_client.cpp#L766)).

### Built-in HTTP server

These settings enable HTTP on TCP `18200`. Forward that TCP port through NAT and allow it through the host firewall, independently of UDP `29070`. With `sv_httpServerPort 0`, the server selects the first free port from `18200` through `18215`; a fixed port is easier to expose from a container or router.

Clients need `cl_allowDownload 1`, which is the default. By default TaystJK asks before downloading, saves each download with a `dl_` prefix that is only loaded while a server references it, and adds a checksum to the name when a file of that name already exists, so content from one server does not silently replace content used elsewhere. See [a map I downloaded is missing everywhere else](/TaystJK/troubleshooting/#a-map-i-downloaded-is-missing-everywhere-else).

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
2. A recognized native client module marker, currently `cgamex86.dll` or `uix86.dll`, is loaded from it.
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

## What `sv_pure` checks

TaystJK's bundled `server.cfg` leaves `sv_pure` at `0`
([`server.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/server.cfg#L30)),
and the [server config generator](/TaystJK/server-hosting/config-generator/) does not turn it
on. This section is for servers that already run it.

`sv_pure 1` checks the client's PK3 checksums against the server's expected files. The
module checks specifically look for `cgamex86.dll` and `uix86.dll` inside PK3s
([`sv_client.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/server/sv_client.cpp#L957)).

TaystJK loads native modules as loose libraries. Its build installs them that way
([cgame install rules](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/CMakeLists.txt#L162),
[UI install rules](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/CMakeLists.txt#L105)). Before loading a module,
`FS_FindPureDLL` reads the corresponding legacy `x86.dll` so other platforms and
architectures can account for the expected pure-server PK3 checksums
([`files.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/files.cpp#L1862),
[`vm.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/vm.cpp#L169)).

Loose native libraries do not fail these checks by themselves. If clients fail pure
validation, check that the server and clients have the expected PK3s, including
the legacy DLL entries used for these checks. Packing an x64 or ARM native library into a
PK3 does not satisfy a check for an `x86.dll` entry.

### `sv_pure` does not constrain TaystJK clients by default

TaystJK clients skip the pure restriction unless the player turns it off. The client-side
cvar [`cl_pureBaseBypass`](/TaystJK/reference/cvars/cl_purebasebypass-b099e31/) defaults to
`1` ([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3460)), and the client applies it on
every connection, whatever `gamename` your server reports
([`cl_parse.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_parse.cpp#L456)). Its own description speaks of "pure
base servers", which is the case it was written for, but the code does not check what the
server runs.

Two things happen at once. The client marks the base assets pak as referenced so the
checksums it reports back look like a stock client's
([`files.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/files.cpp#L4169)), and it skips loading your pak list
altogether. This leaves it with no list to restrict against, so every pak it has is
treated as allowed
([`FS_PakIsPure`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/files.cpp#L393)).

The effect is that the client authenticates as pure while still loading its own assets:
emoji, cosmetics, HUD files and any other PK3 the player has installed. This is deliberate:
it lets TaystJK's client-side additions work on pure servers, but it means
**`sv_pure` is not an asset-parity guarantee for TaystJK clients.** A player who sets
`cl_pureBaseBypass 0` gets the normal restriction again from their next connection. A server
cannot set it for them: it is an ordinary archived cvar, and the client discards server
values for those
([`Cvar_Server_Set`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/cvar.cpp#L807)).
