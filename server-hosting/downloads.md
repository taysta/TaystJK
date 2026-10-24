---
title: "Downloads and PK3 references"
layout: reference
nav_order: 2
parent: "Server hosting"
description: "Serve required PK3s over HTTP or UDP, control which PK3s are offered with reflists, and see what sv_pure does and does not check."
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
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_main.cpp#L1548)), and if an HTTP download fails it
disconnects with a download error rather than retrying over UDP
([`cl_parse.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_parse.cpp#L749)). The UDP downloader serves clients
without HTTP support, such as OpenJK, EternalJK and the original game, and only while
`sv_allowDownload` is on
([`sv_client.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_client.cpp#L766)).

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

Do not put spaces or `@` in downloadable PK3 filenames. The download list sent to clients is one string with `@` between its entries, so the server leaves out any PK3 whose name contains one ([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L3607)), and a space splits the name in two. After changing downloadable content, restart the map and check the reference list before inviting players.

## PK3 referencing and reflists

Only referenced PK3s are offered to clients. The server works out which PK3s are referenced
each time it loads a map ([`sv_init.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_init.cpp#L724-L727)). Clients receive
the list when they connect and again at every map change, and download any listed PK3 they
lack before entering the game ([`cl_parse.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_parse.cpp#L632)). Nothing
downloads during a map.

TaystJK automatically references a PK3 when:

1. The current map's BSP is loaded from it. A map PK3 in `base` is offered once the server is on that map.
2. It holds a client module the engine looks for: `vm/cgame.qvm`, `vm/ui.qvm`, `cgamex86.dll` or `uix86.dll` ([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L1640)).
3. It is in a directory other than `base`. Every PK3 in the mod directory is offered on every map, whether or not anything loads from it ([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L3459)). The check compares only the first four letters, so a mod directory whose name starts with `base`, such as `base_enhanced`, counts as `base`.

Any other PK3 in `base`, such as a model or sound pack, is never offered unless it is on the
force list.

TaystJK does not run `cgame.qvm` or `ui.qvm`; its modules are native libraries, `.dll` on Windows, `.so` on Linux and `.dylib` on macOS. The check still looks for those four names because they are what stock clients load. A PK3 that holds only other module names, such as `cgamex86_64.dll`, or only client assets, is not referenced on its own; add it to `ref_forcelist.txt`.

Run `sv_referencedPakNames` in the server console to inspect the current result. Reflist files let you correct the automatic decision:

| File | Effect |
|:--|:--|
| `ref_forcelist.txt` | Offer each listed PK3 on every map. It only matters for PK3s in `base`, since the mod directory's PK3s are offered anyway. |
| `ref_blacklist.txt` | Never offer the listed PK3s, such as server-only files in the mod directory. |
| `ref_whitelist.txt` | Offer only the listed PK3s. While this file exists, every PK3 missing from it is never offered, maps included. |

A PK3 whose name starts with `noDL` is never offered either, without any list.

When a PK3 matches more than one rule, the first match in this order wins
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L3872-L3882)):

1. Not on the whitelist, when one exists: never offered.
2. On the blacklist: never offered.
3. Name starts with `noDL`: never offered.
4. On the force list: offered.

So a forced PK3 must also be on the whitelist if you use one, and a PK3 on both the force
list and the blacklist is not offered. A whitelist and blacklist together work, but the
blacklist can then only remove PK3s the whitelist allowed; use one or the other.

Blacklisting a map's PK3 also stops it being offered, so players who do not have that map
cannot join while the server runs it.

Place reflists in the server's mod directory, which is `taystjk/` unless you run another
mod, or in `base/`. Use one `game-directory/pak-name.pk3` path per line, with no leading
spaces; case does not matter:

```text
base/models-pack.pk3
base/sounds-pack.pk3
```

The server reads the lists when it loads a map
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L4021), [`sv_init.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_init.cpp#L595)),
so an edit applies from the next map change. A force list offers a file; it does not remove
the client's download confirmation. The [server config generator](/TaystJK/server-hosting/config-generator/)
can write the force list and blacklist for you.

The behavior is inherited from JK2MV; its wiki has useful background on [downloaded files](https://github.com/mvdevs/jk2mv/wiki/Downloaded-Files), [HTTP downloads](https://github.com/mvdevs/jk2mv/wiki/HTTP-Downloads), and [PK3 referencing](https://github.com/mvdevs/jk2mv/wiki/PK3-Referencing).

## What `sv_pure` checks

TaystJK's bundled `server.cfg` leaves `sv_pure` at `0`
([`server.cfg`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker/server.cfg#L30)),
and the [server config generator](/TaystJK/server-hosting/config-generator/) does not turn it
on. This section is for servers that already run it.

`sv_pure 1` checks the client's PK3 checksums against the server's expected files. The
module checks specifically look for `cgamex86.dll` and `uix86.dll` inside PK3s
([`sv_client.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/server/sv_client.cpp#L957)).

TaystJK loads native modules as loose libraries. Its build installs them that way
([cgame install rules](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/CMakeLists.txt#L162),
[UI install rules](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/ui/CMakeLists.txt#L105)). Before loading a module,
`FS_FindPureDLL` reads the corresponding legacy `x86.dll` so other platforms and
architectures can account for the expected pure-server PK3 checksums
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L1862),
[`vm.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/vm.cpp#L169)).

Loose native libraries do not fail these checks by themselves. If clients fail pure
validation, check that the server and clients have the expected PK3s, including
the legacy DLL entries used for these checks. Packing an x64 or ARM native library into a
PK3 does not satisfy a check for an `x86.dll` entry.

### `sv_pure` does not constrain TaystJK clients by default

TaystJK clients skip the pure restriction unless the player turns it off. The client-side
cvar [`cl_pureBaseBypass`](/TaystJK/reference/cvars/cl_purebasebypass-b099e31/) defaults to
`1` ([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_main.cpp#L3460)), and the client applies it on
every connection, whatever `gamename` your server reports
([`cl_parse.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_parse.cpp#L456)). Its own description speaks of "pure
base servers", which is the case it was written for, but the code does not check what the
server runs.

Two things happen at once. The client marks the base assets pak as referenced so the
checksums it reports back look like a stock client's
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L4169)), and it skips loading your pak list
altogether. This leaves it with no list to restrict against, so every pak it has is
treated as allowed
([`FS_PakIsPure`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L393)).

The effect is that the client authenticates as pure while still loading its own assets:
emoji, cosmetics, HUD files and any other PK3 the player has installed. This is deliberate:
it lets TaystJK's client-side additions work on pure servers, but it means
**`sv_pure` is not an asset-parity guarantee for TaystJK clients.** A player who sets
`cl_pureBaseBypass 0` gets the normal restriction again from their next connection. A server
cannot set it for them: it is an ordinary archived cvar, and the client discards server
values for those
([`Cvar_Server_Set`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cvar.cpp#L807)).
