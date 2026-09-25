---
title: "Server hosting"
layout: reference
nav_order: 3
wide: true
description: "Host a TaystJK dedicated server: run it with Docker or natively, serve downloads, record demos, and set up TaystJK's bundled jaPRO game module."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# Host a TaystJK server

<p class="page-lede">A TaystJK server has two layers: the dedicated server engine, and the game module that decides how the game plays.</p>
</div>

The engine is `taystjkded`. It handles networking, downloads, demos and the server console,
whichever game module it loads. The game module is a `jampgame` library in the mod
directory that `fs_game` selects. TaystJK ships its own, based on jaPRO, in the `taystjk`
directory; it adds player accounts, admins, race mode, the movement styles and the gameplay
settings the bundled configs use. You can also run the TaystJK engine with
[another mod's game module](/TaystJK/server-hosting/run-a-server/#run-the-taystjk-server-engine-with-another-mod),
in which case only the engine pages apply.

Start with [run a server](/TaystJK/server-hosting/run-a-server/), then set up the game module
with [jaPRO server setup](/TaystJK/server-hosting/japro-setup/).

{% include browse-grid.html section="server-hosting" %}
