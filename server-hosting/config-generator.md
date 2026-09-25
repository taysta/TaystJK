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
[`scripts/docker/`](https://github.com/taysta/TaystJK/tree/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker)
in the source repository holds them.
</div>

<div class="cfg-root" data-config-generator data-data-url="{{ '/assets/data/config-generator.json' | relative_url }}"></div>
<script defer src="{{ '/assets/js/config-generator.js' | relative_url }}"></script>

## What it writes

| File | When | Holds |
|:--|:--|:--|
| `server.cfg` | Always | Identity, passwords, listing, downloads and the other server settings, then `exec bans`, `exec votes` and `exec default`, and the map last. |
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
  ([`cvar.cpp`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/cvar.cpp#L964)),
  and the game module's cvars do not exist until it loads with the first map. Passwords use
  `set`, so they stay out of the config the server saves on shutdown, and under Docker
  `rconpassword` stays on the `set` line that
  [`docker stop` reads](/TaystJK/server-hosting/bundled-configs/#passwords).
- Only settings the [console reference](/TaystJK/reference/) lists for the chosen target are
  written, and never ones the engine manages itself, such as
  [`sv_cheats`](/TaystJK/reference/cvars/sv_cheats-a5d6021/) and
  [`g_needpass`](/TaystJK/reference/cvars/g_needpass-d848438/). The base and other-mod targets
  only offer cvars that exist in base Jedi Academy.

## Where the presets come from

- **Bundled** is the Docker image's `default.cfg`, read from the same pinned commit as the
  mode files. It leaves out `disable_item_medpak`, which the image sets but which matches no
  item, so it does nothing.
- **Close to base** and **Close to JA+** come from comparing jaPRO's saber and force code
  with the Jedi Academy MP SDK, retail `jampded` and JA+ 2.4, with the values a base server
  and a JA+ server run. Each lists what no setting can match, such as JA+'s own MP damage
  table.
- **Saber team FFA** and the base modes come from a base server's configs.

The generator writes configs for a game module; it does not ship one. For base rules or
another mod, install that mod's `jampgame` library as
[running another mod](/TaystJK/server-hosting/run-a-server/#run-the-taystjk-server-engine-with-another-mod)
describes. Before opening the server to the public, load every map and mode you plan to run
and [check it](/TaystJK/server-hosting/run-a-server/#verify-before-going-public).
