---
title: "Mod compatibility"
layout: reference
nav_order: 11
description: "Why a client feature works on one server and silently does nothing on another, which mod the client thinks you are on, and how a server turns features back on."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Mod compatibility

<p class="page-lede">Several client features are switched off unless the server's game module is known to support them. Nothing tells you this has happened — the feature simply does nothing — so this page explains what the client decides and why.</p>
</div>

## What the client decides

On connecting, the client reads the server's `gamename` and classifies it into one of six
kinds
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L248)):

| `gamename` starts with | Treated as |
|:--|:--|
| `JA+`, `^4U^3A^5Galaxy`, `AbyssMod` | JA+ |
| `japro` | jaPRO |
| `smU` | OpenJK-alt |
| `base_enhanced`, `base_entranced` | Base Enhanced |
| `basejk` | Base JKA |
| `Lugormod`, `^5L^7ugormod ^5v3` | Lugormod |

Anything else is treated as base JKA, and so is any server on a pre-1.01 protocol
regardless of its name. The match is on the start of the string, so a server that renames
itself loses the classification and the features that depend on it.

## Why that ordering matters

The six kinds are an **ordered** enum, not a set
([`cg_local.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_local.h#L201)):

```text
basejka  <  base_enhanced  <  ojkalt  <  lugormod  <  ja+  <  japro
```

Most feature checks are written as *at least JA+* rather than as a named list. A feature
guarded that way is on for JA+ and jaPRO and off for everything to the left, including
Lugormod. This is why the practical answer to "does my client do X here" is usually just
"are you on a JA+ or jaPRO server".

## What is actually gated

Not everything. The client's own display settings — the HUD tools, cosmetics you see
locally, console behaviour — do not care what the server runs. What is gated is behaviour
the **server has to agree with**, because the client is predicting movement or drawing
something the server also has an opinion about.

| Feature | Needs |
|:--|:--|
| RGB sabers | JA+ or jaPRO, or the server advertising it ([`cg_players.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6061)) |
| Black sabers | the same, and not disabled by plugin settings ([`cg_players.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L6053)) |
| Flipkick | the server advertising it ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L272)) |
| Grapple | JA+, or jaPRO with its grapple set, or the server advertising it ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L15402)) |
| Roll fixes 1–3 | JA+ or jaPRO with the matching option, or the server advertising it ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L314)) |
| The `plugin` command | JA+ or above; it returns silently otherwise ([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1292)) |
| Force column on the team overlay | jaPRO, which is what supplies the data |

Lugormod is a special case throughout: it is recognised on its own and several movement
paths branch specifically for it, because it moves players in ways the stock prediction
gets wrong.

## Base Enhanced and Base Entranced: use NewJK

If you play on **base_enhanced** or **base_entranced** servers, the recommended client is
not this one. Use [NewJK/NewMod](https://jkanewmod.github.io/) instead.

Those server mods and NewMod share an author, and NewMod is built for them specifically —
it supports their features properly rather than approximately. TaystJK recognises
base_enhanced well enough not to break, but it is not trying to replace that pairing and
should not be treated as a substitute for it.

This is a recommendation about which client to run, not a limitation you can configure
around.

## `taystJKinfo`: how a server turns these on

A server does not have to be JA+ or jaPRO. Any game module can advertise the individual
capabilities it supports by putting a bitmask in the `taystJKinfo` serverinfo key, which
the client reads on connect
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_servercmds.c#L246)).

Every gated feature above accepts this as an alternative to being recognised as JA+ or
jaPRO. The bits are listed on
[the feature flags spec](/TaystJK/development/feature-flags/).

If you run a server on something other than JA+ or jaPRO and your players report that RGB
sabers or flipkick do nothing, this key is the answer.

## Telling which you are on

`serverinfo` prints the keys described here, including `gamename` and `taystJKinfo` if the
server sets it. That is the quickest way to check whether a feature is missing because of
your client or because of the server.

A feature that behaves differently between two servers is not a client bug — see
[where to report](/TaystJK/where-to-report/).
