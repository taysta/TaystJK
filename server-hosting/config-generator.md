---
title: "Server config generator"
layout: reference
nav_order: 6
parent: "Server hosting"
wide: true
toc: true
description: "Build a server.cfg, a gameplay baseline, game modes and vote options for a TaystJK server in your browser, for the bundled jaPRO module, base game rules or another mod."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator tool</p>

# Server config generator

<p class="page-lede">Pick a game module, a gameplay preset, the modes and votes you want, and download a set of config files ready to run. Everything happens in this page: nothing you enter, passwords included, is uploaded.</p>
</div>

<div class="cfg-nojs" markdown="1">
The generator needs JavaScript. Without it, start from the Docker image's own configs:
[bundled server configs](/TaystJK/server-hosting/bundled-configs/) describes each file, and
[`scripts/docker/`](https://github.com/taysta/TaystJK/tree/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker)
in the source repository holds them.
</div>

<div class="cfg-root" data-config-generator data-data-url="{{ '/assets/data/config-generator.json' | relative_url }}"></div>
<script defer src="{{ '/assets/js/config-generator.js' | relative_url }}"></script>

## What it writes

| File | When | Holds |
|:--|:--|:--|
| `server.cfg` | Always | Identity, passwords, listing, downloads and the other server settings, then `exec bans`, `exec votes` and `exec default`, and last the map, or a map rotation if you pick more than one map. |
| `default.cfg` | jaPRO and base | The gameplay preset, the gametype and limits, and your fine-tuning. Every mode runs it first. |
| `bans.cfg` | If you keep bans | `g_filterBan`, with `g_banIPs` left commented unless you enter addresses, so bans added with `addip` are kept. |
| `votes.cfg` | jaPRO, with vote options | One option per ticked mode and add-on, and the groups you choose. |
| One file per mode | As ticked | jaPRO modes copied from the Docker image, with the files they run; base modes built from a base server's. |
| `README.txt` | Always | Where the files go, the launch options, and the maps they need. |

A few rules hold for every combination:

- Server settings go only in `server.cfg`, and gameplay only in `default.cfg` and the modes,
  so loading a mode never changes the hostname, passwords or player limit.
- `default.cfg` also resets every setting the chosen modes change, so one mode's settings
  never leak into the next.
- Every cvar is written with `set` or `seta`. A bare `name value` line only changes a cvar
  that already exists
  ([`cvar.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/cvar.cpp#L964)),
  and the game module's cvars do not exist until it loads with the first map.
- The join password, `g_password`, is written with `set`, so it is never saved anywhere
  else ([`g_xcvar.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_xcvar.h#L125)).
  jaPRO's `g_fullAdminPass` and `g_juniorAdminPass` are archived cvars
  ([`g_xcvar.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/g_xcvar.h#L264-L265)),
  so the server also copies them into its saved `taystjk_server.cfg`
  ([config writeback](/TaystJK/troubleshooting/#the-dedicated-server-keeps-rewriting-my-config)).
  The generator writes `rconpassword` with `set`; under Docker, keep it on the line that
  [`docker stop` reads](/TaystJK/server-hosting/bundled-configs/#passwords).
- Only settings the [console reference](/TaystJK/reference/) lists for the chosen target are
  written, and never ones the engine manages itself, such as
  [`sv_cheats`](/TaystJK/reference/cvars/sv_cheats-a5d6021/) and
  [`g_needpass`](/TaystJK/reference/cvars/g_needpass-d848438/). The base and other-mod targets
  only offer cvars that exist in base Jedi Academy.

## Map rotation

Pick more than one map and tick **Rotate through these maps**, and `server.cfg` ends with a
chain of `vstr` entries instead of a single `map` line. Each entry loads its map and points
`nextmap` at the next one, so when a match ends the server moves on, and after the last map
it starts again from the first. A base-game mode that loads its own map cannot be combined
with a rotation.

## Before you run it

The generator writes configs for a game module; it does not ship one. For base rules or
another mod, install that mod's `jampgame` library as
[running another mod](/TaystJK/server-hosting/run-a-server/#run-the-taystjk-server-engine-with-another-mod)
describes. Before opening the server to the public, load every map and mode you plan to run
and [check it](/TaystJK/server-hosting/run-a-server/#verify-before-going-public).
