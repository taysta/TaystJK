---
title: "Feature flags"
layout: reference
parent: "Development"
nav_order: 4
description: "The serverinfo key a game module uses to tell TaystJK clients which optional client-side features it supports."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Server mod author guide</p>

# Feature flags

<p class="page-lede">TaystJK gates some client-side features on recognising the server as JA+ or jaPRO. <code>taystJKinfo</code> is how any other game module opts in to them individually, without pretending to be either.</p>
</div>

## The problem it solves

Several client features need the server to behave compatibly because they change movement
prediction, or draw something the server also decides. Rather than run them everywhere and
desync, the client checks which mod the server is running and enables them only where it
knows they work. The ordering that check uses, and what it costs you, is described on
[mod compatibility](/TaystJK/install/mod-compatibility/).

If your module supports one of these features but is not JA+ or jaPRO, that check would
turn it off. `taystJKinfo` is the override.

## Setting it

Put the bitmask in your serverinfo under the key `taystJKinfo`. The client reads it once
per `gamestate`, alongside the rest of the server's configstring
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_servercmds.c#L246)):

```c
Info_SetValueForKey( info, "taystJKinfo", va( "%i", flags ) );
```

Set only the bits you have actually implemented. A client that trusts a flag you do not
honour will mispredict, which is worse for the player than the feature being absent.

## The bits

Defined in
[`bg_public.h`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/bg_public.h#L550):

| Bit | Value | Constant | Means |
|--:|--:|:--|:--|
| 0 | 1 | `TAYSTJK_INFO_RGBSABERS` | Sabers may use colours beyond the stock set. |
| 1 | 2 | `TAYSTJK_INFO_BLACKSABERS` | The black saber colour is permitted. |
| 2 | 4 | `TAYSTJK_INFO_FLIPKICK` | Flip kicks are supported. |
| 3 | 8 | `TAYSTJK_INFO_GRAPPLE` | The grapple hook behaves as JA+'s. |
| 4 | 16 | `TAYSTJK_INFO_FIXROLL_1` | Rolling while using force grip. |
| 5 | 32 | `TAYSTJK_INFO_FIXROLL_2` | The above, plus chaining rolls. |
| 6 | 64 | `TAYSTJK_INFO_FIXROLL_3` | JK2-style rolling. |

The three roll bits are alternatives rather than a progression to be combined. The client
tests them from 3 downwards and takes the first that matches
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/bg_pmove.c#L314)).

## How the client uses a flag

Each feature listed in the bit table accepts its flag in the client check. The grapple
check is representative
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/bg_pmove.c#L15402)): JA+, or jaPRO with its own grapple
option set, or your flag.

Flags can also change behaviour on recognised JA+ and jaPRO servers. For example, the
grapple flag enables the client path even when jaPRO's own grapple option is off. In the
roll selection above, `FIXROLL_3` is tested before the server's roll-2 or roll-1 option, so
advertising it takes precedence over either lower mode
([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/bg_pmove.c#L314)).
Keep the advertised flags consistent with the server's actual movement rules and options.

## Verifying it

Connect and run `serverinfo`. The key appears with the value you set, and the feature should
behave as it does on a jaPRO server. If the key is absent from that output, the client never
received it and nothing downstream of it will work. Fix that before looking at the feature
itself.
