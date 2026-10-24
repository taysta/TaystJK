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

<p class="page-lede">Choose a game module, a gameplay preset, modes and votes, and download a set of config files. It all runs in your browser; nothing you enter, passwords included, is uploaded.</p>
</div>

<div class="cfg-nojs" markdown="1">
The generator needs JavaScript. Without it, start from the Docker image's own configs:
[bundled server configs](/TaystJK/server-hosting/bundled-configs/) describes each file, and
[`scripts/docker/`](https://github.com/taysta/TaystJK/tree/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/scripts/docker)
in the source repository holds them.
</div>

<div class="cfg-root" data-config-generator data-data-url="{{ '/assets/data/config-generator.json' | relative_url }}"></div>
<script defer src="{{ '/assets/js/config-generator.js' | relative_url }}"></script>

## What you get

| File | Holds |
|:--|:--|
| `server.cfg` | Server settings: name, passwords, listing, downloads, and the map to start on, or a rotation if you choose more than one. |
| `default.cfg` | The gameplay baseline. Every mode loads it first, so one mode's settings never carry into the next. |
| `bans.cfg` | IP bans. |
| `votes.cfg` | Vote options, for the jaPRO module. |
| `ref_forcelist.txt`, `ref_blacklist.txt` | PK3s to always or never offer for download, if you list any. See [reflists](/TaystJK/server-hosting/downloads/#pk3-referencing-and-reflists). |
| One file per mode | The modes you ticked. |
| `README.txt` | Where the files go and how to launch the server. |

Loading a mode never changes the server settings in `server.cfg`.

The jaPRO admin passwords are also saved to the server's `taystjk_server.cfg`, so keep that
file as private as `server.cfg`. Under Docker, leave `rconpassword` on its own `set` line: the
container [reads it from there](/TaystJK/server-hosting/bundled-configs/#passwords) to shut the
server down cleanly.

The generator writes configs, not game modules. For base rules or another mod, install that
mod's game module first, as [running another mod](/TaystJK/server-hosting/run-a-server/#run-the-taystjk-server-engine-with-another-mod)
describes, and [test every map and mode](/TaystJK/server-hosting/run-a-server/#verify-before-going-public)
before opening the server to the public.
