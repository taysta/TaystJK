---
title: "jaPRO server setup"
layout: reference
nav_order: 4
parent: "Server hosting"
description: "Set up TaystJK's bundled jaPRO game module: player accounts, admins, clans, voting, bans, race records and the tweak commands that shape gameplay."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Administrator guide</p>

# jaPRO server setup

<p class="page-lede">How to run TaystJK's bundled jaPRO game module: its player accounts, admins and clans, how voting and bans work, and the commands that shape gameplay.</p>
</div>

## Before you start

Everything on this page belongs to TaystJK's bundled `jampgame`, the jaPRO-based game module
in the `taystjk` mod directory, which is what the Docker image and a default native launch
run. If you load [another mod's game module](/TaystJK/server-hosting/run-a-server/#run-the-taystjk-server-engine-with-another-mod),
that mod brings its own admin and account system and none of this applies.

Commands marked as server commands run in the server console, or from a client through
`rcon` once you know the rcon password. The others are typed by players, with or without a
leading `/`.

If you run the Docker image, its [bundled server configs](/TaystJK/server-hosting/bundled-configs/)
already set most of this up. They also set many of these values again at every start and
whenever a game mode loads, so make lasting changes in those files; a change made only with
a command lasts until the next start or mode change.

## Player accounts

Accounts are stored in an SQLite database, `data.db`, in the mod directory under the
server's home path
([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L7319)). In Docker that is
`homepath/taystjk/data.db` on the mounted volume. Back it up; it also holds race records,
duel results and clans.

[`g_allowRegistration`](/TaystJK/reference/cvars/g_allowregistration-45f9f37/) decides what players may do
with accounts:

| Value | Players can |
|:--|:--|
| `0` | Not register ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3422)). Existing accounts can still log in. |
| `1` | Register an account. |
| `2` | Also join clans ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3544)). |
| `3` | Also create clans ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3773)). The bundled configs use this. |

Players create an account with [`register`](/TaystJK/reference/commands/register-13a2828/) `<name> <password>`,
which also logs them in, and later use [`login`](/TaystJK/reference/commands/login-2736fab/),
[`logout`](/TaystJK/reference/commands/logout-55525e1/) and [`changepassword`](/TaystJK/reference/commands/changepassword-3dfd458/).
What an account records for them is covered in
[racing](/TaystJK/features/racing/#accounts-and-leaderboards). Three rules are worth telling
your players:

- **One account per IP address.** Registering fails when the player's address already
  belongs to an account ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3473)), and logging in
  to a different account from that address fails too, unless the account is flagged
  Trusted ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2321)).
- **Passwords are stored as plain text** in `data.db`
  ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3498)) and compared without regard to case
  ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2338)). Players should not reuse a password
  from anywhere else, and you should treat `data.db` as sensitive.
- **Names are simplified.** Account names are lowercased and stripped of punctuation, and
  names and passwords are cut to 15 characters
  ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3412)).

### Managing accounts

These are server commands:

| Command | Does |
|:--|:--|
| [`register`](/TaystJK/reference/commands/register-13a2828/) `<name> <password>` | Creates an account for someone. |
| [`changepassword`](/TaystJK/reference/commands/changepassword-3dfd458/) `<name> <new password>` | Resets a password. |
| [`accountInfo`](/TaystJK/reference/commands/accountinfo-e041bfd/) `<name>` | Shows an account's details. |
| [`clearIP`](/TaystJK/reference/commands/clearip-92535a0/) `<name>` | Forgets the address an account last used, which frees that address for the one-account rule. |
| [`renameAccount`](/TaystJK/reference/commands/renameaccount-3fd6fd7/) `<name> <new name> confirm` | Renames an account, including its race and duel records. |
| [`deleteAccount`](/TaystJK/reference/commands/deleteaccount-1669172/) `<name> confirm` | Deletes an account and its race and duel records. |
| [`flagAccount`](/TaystJK/reference/commands/flagaccount-eeeecbc/) `<name>` | Lists an account's flags. See [account flags](#account-flags). |
| [`DBInfo`](/TaystJK/reference/commands/dbinfo-c214d31/) | Prints how many accounts, race records and duels the database holds. |

`renameAccount` and `deleteAccount` do nothing unless the last word is literally `confirm`
([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2620)).

### Account flags

Each account carries a bitmask of flags. Bits 0 to 22 are the admin rights described
[below](#admins); bits 23 to 29 change how the account is treated:

| Bit | Flag | Effect |
|:--|:--|:--|
| 23 | IP Lock | The account can only log in from the address it last used ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2344)). |
| 24 | Trusted | Exempt from the one-account-per-address rule when logging in. |
| 25 | No Race | The player's race times do not count ([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L1299)). |
| 26 | No Duel | Duels involving the player are not recorded ([`g_active.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_active.c#L4491)). |
| 27 | All Cosmetics | Every cosmetic is unlocked ([`g_client.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_client.c#L2241)). |
| 28 | Entities | Allows the [`nearby`](/TaystJK/reference/commands/nearby-8809020/) and [`trace`](/TaystJK/reference/commands/trace-d0fa554/) inspection commands ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L7839)). |
| 29 | Database | Allows [`flagRecord`](/TaystJK/reference/commands/flagrecord-015800d/), which flags, unflags or deletes a race record ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L5400)). |

Toggle one with `flagAccount <name> <bit>`, for example `flagAccount alice 24`. The change
reaches the player at once if they are logged in.

## Admins

A player's admin rights are a bitmask with one bit per power, such as kick, ban, teleport or
change map; the [`g_fullAdminLevel`](/TaystJK/reference/cvars/g_fulladminlevel-baac21c/) entry lists every bit.
Every admin command checks the bit it needs
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L447)), and a player can check what they have with
[`amInfo`](/TaystJK/reference/commands/aminfo-b53555a/) ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L5698)). There are
three ways to hand rights out.

### Shared admin passwords

Set [`g_fullAdminPass`](/TaystJK/reference/cvars/g_fulladminpass-11858c2/) and
[`g_juniorAdminPass`](/TaystJK/reference/cvars/g_junioradminpass-f2dc6ae/). A player who types
[`amLogin`](/TaystJK/reference/commands/amlogin-0aff778/) `<password>` gets the rights in
[`g_fullAdminLevel`](/TaystJK/reference/cvars/g_fulladminlevel-baac21c/) or
[`g_juniorAdminLevel`](/TaystJK/reference/cvars/g_junioradminlevel-0881d19/), until they use
[`amLogout`](/TaystJK/reference/commands/amlogout-da89c31/) or leave. An empty password disables that login
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L4927)), and passwords are compared without regard
to case ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L4930)).

Change what each level grants with the server command [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/):
`toggleAdmin full` lists the full level's rights, and `toggleAdmin full 4` switches bit 4
(kick) on or off ([`g_svcmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L1332)). Use `junior` for the
junior level. [`g_fullAdminMsg`](/TaystJK/reference/cvars/g_fulladminmsg-a1df874/) and
[`g_juniorAdminMsg`](/TaystJK/reference/cvars/g_junioradminmsg-60177a9/) set what everyone sees when someone
logs in; leave one empty to log in quietly.

The bundled configs give the full level every right except Callvote, and the junior level
map changes, `amvstr`, map listing, `amwhois`, `amlookup` and reading admin chat.

### Admin rights on an account

Give an account admin bits with [`flagAccount`](/TaystJK/reference/commands/flagaccount-eeeecbc/), and the player
gets them whenever they log in to that account
([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2384)):

```text
flagAccount alice set full
flagAccount bob set junior
flagAccount carol 4
```

`set full` and `set junior` copy the current full or junior level, `set <number>` stores
that exact bitmask, and a bare bit number toggles one right. `set` replaces every flag on the
account, including Trusted and IP Lock, so set those again afterwards
([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L2971)). [`listAdmins`](/TaystJK/reference/commands/listadmins-135e048/)
lists the accounts that have the Read AmSay right, bit 22, which is the one jaPRO treats as
marking an admin account ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3011)).

Logging out of the account does not remove rights it granted; they last until the player
leaves the server ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3521)).

### Granting rights in game

An admin with the Grantadmin right can run [`amGrantAdmin`](/TaystJK/reference/commands/amgrantadmin-4e5383a/)
`<player>` to give another player the junior level's rights for the rest of their visit, or
`amGrantAdmin <player> none` to take every admin right away
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L5626)).

No admin command works on another player who holds the same right, so one admin with kick
rights cannot kick another ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L439)).

## Clans

jaPRO has two unrelated things called clans.

**Account clans** are stored in the database and need `g_allowRegistration` of at least 2 to
join and 3 to create. The player who runs [`clanCreate`](/TaystJK/reference/commands/clancreate-c8e06da/) `<name>`
owns the clan ([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L3864)) and manages it with
[`clanAdmin`](/TaystJK/reference/commands/clanadmin-81aa5bc/) `<clan> <kick|private|public|longname|tag>`
([`g_account.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_account.c#L4343)). A private clan can only be joined by
invitation, sent with [`clanInvite`](/TaystJK/reference/commands/claninvite-0b616bf/) `<clan> <account>`. Other
players use [`clanJoin`](/TaystJK/reference/commands/clanjoin-45d4991/), [`clanLeave`](/TaystJK/reference/commands/clanleave-4c3bb60/),
[`clanList`](/TaystJK/reference/commands/clanlist-0df1c7a/) and [`clanInfo`](/TaystJK/reference/commands/claninfo-d03453d/). From the
server console you can manage any clan with [`clancreate`](/TaystJK/reference/commands/clancreate-c8e06da/),
[`clandelete`](/TaystJK/reference/commands/clandelete-a4890f1/), [`clanjoin`](/TaystJK/reference/commands/clanjoin-45d4991/)
`<clan> <account>` and [`clankick`](/TaystJK/reference/commands/clankick-2d626df/) `<clan> <account>`.

**Clan chat** needs no account. Players who set the same [`clanPass`](/TaystJK/reference/commands/clanpass-e0e73ba/)
`<password>` can talk to each other with [`clanSay`](/TaystJK/reference/commands/clansay-0ce04c4/)
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L2156)), and
[`say_team_mod`](/TaystJK/reference/commands/say_team_mod-1d67bc8/) `clan` sends their team chat there instead.

## Voting

[`g_allowVote`](/TaystJK/reference/cvars/g_allowvote-fdda916/) is a bitmask of the vote types players may
call. List and toggle them with the server command [`toggleVote`](/TaystJK/reference/commands/togglevote-397b6ff/),
or the older [`toggleallowvote`](/TaystJK/reference/commands/toggleallowvote-3e2cc73/), which does the same.
[`g_tweakVote`](/TaystJK/reference/cvars/g_tweakvote-97a7f7d/), set with [`tweakVote`](/TaystJK/reference/commands/tweakvote-97236e2/),
adjusts how voting behaves: whether spectators may vote, flood protection, a quiet period
after each map load, and whether abstainers count.
[`g_voteDelay`](/TaystJK/reference/cvars/g_votedelay-8d2f6a6/) is how many milliseconds a passed vote
waits before it takes effect ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L3318)), and
[`g_voteTimeout`](/TaystJK/reference/cvars/g_votetimeout-c55dafd/) holds back a player whose vote
failed: they wait that many seconds for each failed vote before they can call another
([`g_main.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L2980)).

Two things are easy to miss:

- **Admin-only voting.** If either admin level includes the Callvote right, bit 20, then only
  players who hold that right can call votes at all
  ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L3151)). The bundled levels leave it out.
- **`vstr` votes run commands.** `callvote vstr <name>` runs the console commands stored in
  the server cvar of that name. The vote only checks that the cvar has a value
  ([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L3011)), so players can name any server cvar, not
  only the ones you prepared. The bundled configs prepare a set of
  [vote options](/TaystJK/server-hosting/bundled-configs/#vote-options).

An admin with the Killvote right cancels a vote in progress with
[`amKillVote`](/TaystJK/reference/commands/amkillvote-267af5c/).

## Bans

Ban from the server console or through rcon with [`addip`](/TaystJK/reference/commands/addip-5d88fb5/) `<address>`,
and manage the list with [`removeip`](/TaystJK/reference/commands/removeip-38af509/) and
[`listip`](/TaystJK/reference/commands/listip-3cf3e51/). In game, an admin with the ban right uses
[`amBan`](/TaystJK/reference/commands/amban-ac16303/) `<player>`, which adds the player's address and kicks them
([`g_cmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L5441)).

- Leave numbers off the end to cover a range: `addip 1.2.3` bans every `1.2.3.x` address
  ([`g_svcmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L40)).
- The list lives in [`g_banIPs`](/TaystJK/reference/cvars/g_banips-5693b4b/), which the server saves, so bans
  survive a restart ([`g_xcvar.h`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_xcvar.h#L76)). If you set it in a
  config instead, separate the addresses with spaces and end with a space; the game ignores
  a last address with nothing after it ([`g_svcmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L221)).
- [`g_filterBan`](/TaystJK/reference/cvars/g_filterban-1aadd85/) `1` blocks the listed addresses; `0` admits
  only them, which makes a private server.

The Docker image keeps these settings in [`bans.cfg`](/TaystJK/server-hosting/bundled-configs/#bans).

## Tweak commands

Much of jaPRO's gameplay is controlled by bitmask cvars, one option per bit. Each has a
server command that shows the options and switches them one at a time, so you never have to
work out the number yourself:

```text
tweakWeapons
tweakWeapons 21
```

The first line lists every weapon option with `[X]` beside the ones that are on. The second
switches option 21, fast weapon switching, and prints its new state.

| Command | Sets | Controls |
|:--|:--|:--|
| [`tweakWeapons`](/TaystJK/reference/commands/tweakweapons-fd5860d/) | [`g_tweakWeapons`](/TaystJK/reference/cvars/g_tweakweapons-7f0cd05/) | Weapon behaviour, damage and spread |
| [`tweakSaber`](/TaystJK/reference/commands/tweaksaber-e5f1b57/) | [`g_tweakSaber`](/TaystJK/reference/cvars/g_tweaksaber-7ff08dd/) | Saber combat, such as JK2-style swings and damage |
| [`tweakForce`](/TaystJK/reference/commands/tweakforce-05bb9d3/) | [`g_tweakForce`](/TaystJK/reference/cvars/g_tweakforce-d616b7a/) | Force power behaviour |
| [`tweakVote`](/TaystJK/reference/commands/tweakvote-97236e2/) | [`g_tweakVote`](/TaystJK/reference/cvars/g_tweakvote-97a7f7d/) | Voting rules |
| [`startingWeapons`](/TaystJK/reference/commands/startingweapons-7252a71/) | [`g_startingWeapons`](/TaystJK/reference/cvars/g_startingweapons-ba463fc/) | Weapons players spawn with |
| [`startingItems`](/TaystJK/reference/commands/startingitems-2ed82fa/) | [`g_startingItems`](/TaystJK/reference/cvars/g_startingitems-8ece828/) | Items players spawn with |
| [`saberDisable`](/TaystJK/reference/commands/saberdisable-cf2b094/) | [`g_saberDisable`](/TaystJK/reference/cvars/g_saberdisable-8b0544d/) | Saber styles and types players cannot use |
| [`toggleEmotes`](/TaystJK/reference/commands/toggleemotes-c7d169a/) | [`g_emotesDisable`](/TaystJK/reference/cvars/g_emotesdisable-8df1bb9/) | Emotes players cannot use |
| [`toggleVote`](/TaystJK/reference/commands/togglevote-397b6ff/) | [`g_allowVote`](/TaystJK/reference/cvars/g_allowvote-fdda916/) | Vote types players may call |
| [`toggleAdmin`](/TaystJK/reference/commands/toggleadmin-b7c3f7b/) | [`g_fullAdminLevel`](/TaystJK/reference/cvars/g_fulladminlevel-baac21c/), [`g_juniorAdminLevel`](/TaystJK/reference/cvars/g_junioradminlevel-0881d19/) | Admin rights for each password level |

Each cvar's reference entry lists what every bit does. To keep a combination, print the
cvar's value, for example by typing `g_tweakWeapons`, and put that number in your config.

Other server commands help run a match: [`gametype`](/TaystJK/reference/commands/gametype-d7c6fe6/) `<number>`
switches gametype without reloading the map
([`g_svcmds.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_svcmds.c#L634)),
[`resetScores`](/TaystJK/reference/commands/resetscores-5efac86/) clears the scores,
[`forceteam`](/TaystJK/reference/commands/forceteam-72a2634/) moves a player, and [`pause`](/TaystJK/reference/commands/pause-ef8d299/)
pauses the match for up to [`g_pauseTime`](/TaystJK/reference/cvars/g_pausetime-f946ba0/) seconds.

## Race records

Race times only count while the server meets jaPRO's conditions for a fair run
([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L1341)). If players report that their times are
not being saved, check these first:

- [`sv_cheats`](/TaystJK/reference/cvars/sv_cheats-a5d6021/) is `0`.
- [`sv_fps`](/TaystJK/reference/cvars/sv_fps-1ec111f/) is `20`, `30` or `40`
  ([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L1351)); the bundled configs use `40`.
- [`timescale`](/TaystJK/reference/cvars/timescale-97bdf9f/) is `1`,
  [`g_stepSlideFix`](/TaystJK/reference/cvars/g_stepslidefix-9d644c1/) and
  [`g_smoothClients`](/TaystJK/reference/cvars/g_smoothclients-6772924/) are on,
  [`g_jediVmerc`](/TaystJK/reference/cvars/g_jedivmerc-0e45262/) is off, and
  [`g_debugMelee`](/TaystJK/reference/cvars/g_debugmelee-cf2d02e/) is below `2`.
- [`g_knockback`](/TaystJK/reference/cvars/g_knockback-bd8fbb6/) is `1000` for the rocket-jump and Tribes
  styles ([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L1301)).
- The player is logged in and their account does not have the No Race flag.
- If [`sv_pluginKey`](/TaystJK/reference/cvars/sv_pluginkey-9d80ed4/) is set, logged-in players also need a
  client that proves itself with that key when it logs in
  ([`g_trigger.c`](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L1355)). Leave it at `0` unless you use a
  client plugin that supports it.

Courses can add their own conditions, such as a required force jump level, and tell the
player when a run does not count.
