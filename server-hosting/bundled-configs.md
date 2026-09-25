---
title: "Bundled server configs"
layout: reference
nav_order: 5
parent: "Server hosting"
description: "The server.cfg, game modes, vote options and ban list in the Docker image, written for TaystJK's bundled jaPRO game module."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# Bundled server configs

<p class="page-lede">The Docker image ships a complete server configuration for TaystJK's own game module: server settings, a gameplay baseline, game modes, vote options and a ban list.</p>
</div>

## For the bundled jaPRO game module only

These files configure TaystJK's bundled `jampgame`: the jaPRO-based game module in the
`taystjk` mod directory. They depend on its settings and commands, such as jaPRO's tweak
bitmasks, [`restricts`](/TaystJK/reference/cvars/restricts-3fcd8e8/), the
[`gametype`](/TaystJK/reference/commands/gametype-d7c6fe6/) command and vote options run
through `vstr`. Another mod's game module does not implement most of them.

The Docker image copies them into `basepath/taystjk/`
([`Dockerfile`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/Dockerfile#L60)).
A dedicated server looks for configs only in `base` and in the directory `fs_game` selects,
because dedicated builds leave `fs_forcegame` empty
([`files.cpp`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/qcommon/files.cpp#L3913)).
If you set `TJK_MOD` to another mod, none of these files load, and the server starts from
that mod's own configuration instead; see
[running another mod](/TaystJK/server-hosting/run-a-server/#run-the-taystjk-server-engine-with-another-mod).

Native releases do not include them. To use them outside Docker, copy the `.cfg` files
from [`scripts/docker/`](https://github.com/taysta/TaystJK/tree/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker)
in the source repository into your `taystjk/` directory, then launch with `+exec server.cfg`.

## What loads at startup

The server only runs `server.cfg` itself, and that file loads the rest:

| File | Holds |
|:--|:--|
| `server.cfg` | Identity, passwords, downloads, network, connection security, bots, voting rules, admin levels, accounts, logging and demo settings. It starts the server on `mp/ffa3` in FFA. |
| `bans.cfg` | IP bans. See [bans](#bans). |
| `votes.cfg` | The options players can vote for. See [vote options](#vote-options). |
| `default.cfg` | The gameplay baseline that every mode starts from. |
| One file per mode | The [game modes](#game-modes). |
| `pickups.cfg`, `nopickups.cfg`, `noboons.cfg` | [Add-ons](#pickup-add-ons) that switch pickups on or off. |
| `tribesbase.cfg` | Settings shared by the Tribes modes. It is not meant to be run on its own. |

`server.cfg` applies its own settings, then runs `exec bans`
([line 49](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/server.cfg#L49)),
`exec votes`
([line 52](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/server.cfg#L52))
and `exec default`
([line 110](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/server.cfg#L110)),
and finally loads the map
([line 122](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/server.cfg#L122)).

There is no map rotation. Each map load sets `nextmap` to restart the same map
([`sv_init.cpp`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/server/sv_init.cpp#L569)),
so when a match ends the current map restarts, and players change maps with
`callvote map`. If you want the server to move on by itself, set `g_autoMapCycle 1` in
`server.cfg`; the game then picks the next map for the current gametype from the arena
files
([`g_bot.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_bot.c#L232)).

## Server settings and gameplay are kept apart

`server.cfg` holds everything about running the server, and `default.cfg` holds only
gameplay. Every mode runs `default.cfg` again when it loads, so loading one never changes
your hostname, password, player limit or admin setup.

Four settings belong to the modes and go back to the baseline whenever a mode loads: which
votes are allowed ([`g_allowVote`](/TaystJK/reference/cvars/g_allowvote-fdda916/)) and the
time, frag and capture limits. Put a limit you want in the mode's file, or let players vote
for one.

The baseline also sets [`restricts`](/TaystJK/reference/cvars/restricts-3fcd8e8/) to 1550
([`default.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/default.cfg#L179)).
On TaystJK and jaPRO clients that hides the lead indicator, disables `/do`, and holds the
third-person camera angle at 0 while racing. Two of its bits are defined but never read, so
they do nothing.

`server.cfg` runs `exec default` before the first map for a second reason. On shutdown the
server saves most of these settings to `taystjk_server.cfg` and loads them again at the next
start (see [the server rewriting its config](/TaystJK/troubleshooting/#the-dedicated-server-keeps-rewriting-my-config)).
Without the reset, a restarted server would begin in FFA with the last mode's weapons and
force powers still applied.

## Passwords

`server.cfg` ships three passwords near the top, all empty. Fill them in:

```cfg
set rconpassword "replace-with-a-long-random-secret"
seta g_fullAdminPass "replace-with-another-secret"
seta g_juniorAdminPass "and-a-third"
```

An empty value disables that login. [jaPRO server setup](/TaystJK/server-hosting/japro-setup/#admins)
explains what the two admin logins grant and the other ways to give out admin rights.

Keep `rconpassword` in `server.cfg`, on a line that starts with `set` or `seta`. When Docker
stops the container, the run script sends `rcon quit` so the server shuts down cleanly
([`run.sh`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/run.sh#L24)),
and it finds the password only by reading that line of `server.cfg`
([`functions.sh`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/functions.sh#L62)).
Without it, the script has nothing to send, and Docker kills the server when its stop
timeout runs out.

## Game modes

Load a mode from the server console or with `rcon exec <mode>`, or let players vote for it
with `callvote vstr <mode>`. Every mode first runs `default.cfg`, then applies its own
settings, then reloads the map with `map_restart 0`
([for example](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/saberonly.cfg#L56)).
The reload is what makes the change complete: weapons and items on the map, and settings
the engine only applies on a map load, change then and not before. It also resets the
scores.

A mode that does not choose a gametype plays FFA, because `default.cfg` switches back to
FFA with `gametype 0`
([`default.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/default.cfg#L177)).
In the table, "force limited to jumping and saber skills" means
[`g_forcePowerDisable`](/TaystJK/reference/cvars/g_forcepowerdisable-370e0a6/) leaves only
levitation and saber offense and defense.

| Mode | Plays as |
|:--|:--|
| [`airshot`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/airshot.cfg#L1) | FFA with only the rocket launcher and no splash damage, so only direct hits count. Force limited to jumping and saber skills. |
| [`fftffa`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/fftffa.cfg#L1) | Team FFA with sabers only and no pickups. Friendly fire stays at the baseline's half damage, and team heal and team energize are disabled. |
| [`gungame`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/gungame.cfg#L1) | FFA gun game ([`g_gunGame`](/TaystJK/reference/cvars/g_gungame-0b95542/) 2) with no pickups, no self damage and no falling damage. Force limited to jumping and saber skills. |
| [`instagib`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/instagib.cfg#L1) | FFA with only the disruptor, at ten times weapon damage, and a faster run speed. Force limited to jumping and saber skills. |
| [`instagibrabbit`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/instagibrabbit.cfg#L1) | Sniper rabbit: the flag carrier gets a disruptor, everyone else fights with sabers at ten times saber damage. No health or armor pickups; frag limit 50. |
| [`jk2`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/jk2.cfg#L1) | FFA with JK2 1.02-style saber combat and force, single saber only. Weapons stay on the map. |
| [`jk2104`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/jk2104.cfg#L1) | FFA with the JK2 saber damage system and rescaled stances: yellow at half damage, red at 0.7. |
| [`lugorff`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/lugorff.cfg#L1) | FFA with single-player-style saber damage and jaPRO's saber and force tweaks turned off. |
| [`merc`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/merc.cfg#L1) | FFA with every weapon except the concussion rifle, no health or armor pickups, double saber damage and force at rank 1, limited to jumping, protect and saber skills. It sets a capture limit of 7 for playing it as CTF. |
| [`midair`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/midair.cfg#L1) | `tribesctf`, with projectiles also carrying the shooter's sideways movement ([`g_fullInheritance`](/TaystJK/reference/cvars/g_fullinheritance-fb4c838/)). |
| [`predator`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/predator.cfg#L1) | Team FFA with sabers only, no pickups and single-player-style saber damage. Force limited to jumping and saber skills. |
| [`predator2`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/predator2.cfg#L1) | `predator` with multiplayer saber damage doubled, backslashes at a hundred times damage, the JK2 lunge and no friendly fire. |
| [`prize`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/prize.cfg#L1) | FFA with sabers only: saber damage cut to a tenth, but backslashes at two hundred times damage. Race mode is off. |
| [`saberctf`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/saberctf.cfg#L1) | CTF with sabers, thermal detonators and trip mines, JK2-style saber combat and no pickups. Force limited to saber skills; capture limit 5. |
| [`saberonly`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/saberonly.cfg#L1) | Team FFA with sabers only, no pickups and single-player-style saber damage. Force limited to jumping and saber skills. |
| [`saberrabbit`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/saberrabbit.cfg#L1) | Rabbit where holding the flag scores points, with sabers at double damage, backslashes at a hundred times, the JK2 lunge and red DFA. Force limited to saber skills; 30-minute time limit and frag limit 200. |
| [`theone`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/theone.cfg#L1) | Rabbit with Q3 movement at a slow run speed and only the bowcaster, whose shots travel at a fifth of their normal speed. Frag limit 50. |
| [`tribes`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/tribes.cfg#L1) | [Tribes](/TaystJK/features/tribes/) movement, classes and weapons in FFA. |
| [`tribesctf`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/tribesctf.cfg#L1) | Tribes in CTF. |
| [`tribes1flag`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/tribes1flag.cfg#L1) | Tribes in one-flag CTF: carry the neutral flag into the other team's capture zone ([`g_neutralFlag`](/TaystJK/reference/cvars/g_neutralflag-55bb88d/) 5). |
| [`wswrabbit`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/wswrabbit.cfg#L1) | Rabbit with Warsow movement and sabers only, at double saber damage and four times backslash damage. Frag limit 50. |

The rabbit modes need a map with a neutral flag, and the one-flag modes also need capture
zones; the stock maps have neither. The [`g_neutralFlag`](/TaystJK/reference/cvars/g_neutralflag-55bb88d/)
entry describes each variant and what a map must provide.

The three Tribes modes share their settings through `tribesbase.cfg`
([`tribes.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/tribes.cfg#L1)),
so each reloads the map only once. Players need the client-side setup as well; see
[Tribes](/TaystJK/features/tribes/#setting-it-up).

### Pickup add-ons

`pickups`, `nopickups` and `noboons` switch groups of pickups on or off on top of whatever
is running:

| Config | Does |
|:--|:--|
| `nopickups` | Turns off health, armor, bacta, force boon, enlightenment and seeker pickups. |
| `pickups` | Turns the same group back on. |
| `noboons` | Turns off the force boon and both enlightenments only. |

They set `disable_<item>` cvars, which the game reads only when it spawns items
([`g_items.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_items.c#L3392)),
so follow one with `map_restart`, or the `restart` vote. The baseline in `default.cfg`
already leaves seekers, portable shields, light-side enlightenment and detpack pickups off.

## Vote options

`votes.cfg` defines what players can vote for. Each option is a cvar holding console
commands, and `callvote vstr <option>` runs them if the vote passes
([`votes.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/votes.cfg#L1)).
The baseline allows three kinds of vote: `map`, `vstr` and `poll`
([`default.cfg`](https://github.com/taysta/TaystJK/blame/60fcb9cf68d38c3fede638fac4a8e42eb1123eaf/scripts/docker/default.cfg#L12)).
`fftffa`, `merc`, `saberctf` and `saberonly` allow a few more, such as forcing a player to
spectate.

| Group | Options |
|:--|:--|
| Modes | Every mode above by name, plus `default`, `teamgungame` (gun game as team FFA without friendly fire), `pickups`, `nopickups`, `noboons` and `restart`. |
| Frag limit | `0`, `10`, `21`, `31`, `41`, `51` and `61`, and the same as `frag0` to `frag41`. |
| Capture limit | `cap0`, `cap3`, `cap5`, `cap7`. |
| Team size | `0v0` to `6v6`, which set [`sv_maxTeamSize`](/TaystJK/reference/cvars/sv_maxteamsize-8db6a18/). |
| Gametype | `ffa`, `tffa`, `ctf`, and `1flagctf` (CTF with `g_neutralFlag 6`). |
| [Movement style](/TaystJK/features/movement-styles/) | `jka`, `qw`, `cpm`, `q3`, `pjk`, `wsw`, `sp`, `slick`, `ocpm`. |
| Rabbit | `rabbit`, `bkrabbit` (holding the flag scores points), `norabbit`. |
| Loadout | `noguns`, `guns`, `all`, `togglefullhp`, `togglejetpack`. |
| On and off | `friendlyfire` and `nofriendlyfire`, `flagthrow` and `noflagthrow`, `fixflagsuicide` and `nofixflagsuicide`, `damagenumbers` and `nodamagenumbers`, `splat` and `nosplat`. |
| Other | `fastregen` (faster force regeneration), `race` (lets players enter race mode again), `kickbots`. |

`togglefullhp` and `togglejetpack` each flip one starting item with the
[`startingItems`](/TaystJK/reference/commands/startingitems-2ed82fa/) command and keep the
rest of the mode's items, so a second vote flips it back. The gametype options switch
without reloading the map
([`g_svcmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L634)),
while options that change weapons or pickups on the map take effect after a `restart` vote.

To add an option, put a `set` line in `votes.cfg`, for example `set mymode "exec mymode"`.

How voting works, including which votes the server allows and why a `vstr` vote can name
any server cvar, is covered in [jaPRO server setup](/TaystJK/server-hosting/japro-setup/#voting).

## Bans

`bans.cfg` holds two settings:

- [`g_filterBan`](/TaystJK/reference/cvars/g_filterban-1aadd85/) `1` blocks the listed
  addresses; `0` admits only the listed addresses, which makes a private server.
- [`g_banIPs`](/TaystJK/reference/cvars/g_banips-5693b4b/) is the list itself. It ships
  commented out.

Bans you add with `addip` or `amBan` are saved in `g_banIPs` and survive a restart; see
[bans](/TaystJK/server-hosting/japro-setup/#bans) for the commands and address ranges.

To keep the list in the file instead, uncomment the `g_banIPs` line. It then replaces the
saved list at every start, so copy any `addip` bans into it first. Separate the addresses
with spaces and end the list with a space: the game ignores a last address with nothing
after it
([`g_svcmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L221)).

```cfg
seta g_banIPs "1.2.3 203.0.113.7 "
```

## Change a file

Override any of these files the same way as `server.cfg`: copy it from the image into
`homepath/taystjk/`, where it takes priority over the image's copy and survives image
updates. For example, to edit the vote options:

```sh
docker compose cp \
  taystjk:/opt/taystjk/basepath/taystjk/votes.cfg \
  ./homepath/taystjk/votes.cfg
```

A mode's file is read again every time the mode loads, so an edited mode takes effect the
next time it runs. Run `rcon exec votes` to reload edited vote options, and restart the
server after changing `server.cfg`. On a native server, edit the copies in your `taystjk/`
directory.
