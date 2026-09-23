---
title: "cp_cosmetics"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cp_cosmetics`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>cosmetics</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Controls `cp_cosmetics` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-09-08 in [`7778371e9`](https://github.com/taysta/TaystJK/commit/7778371e96142ef5afaea5c030ea863c9462d2aa) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`cosmetics`](/TaystJK/reference/commands/cosmetics-01c96cf/) |

## Bits

Use [`cosmetics`](/TaystJK/reference/commands/cosmetics-01c96cf/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own. [The labels come from the source table](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1591).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | Santa hat | — |
| 1 | `2` | Jack-o'-lantern | — |
| 2 | `4` | Bass Pro Shops baseball cap | — |
| 3 | `8` | Indiana Jones | — |
| 4 | `16` | Kane's Kringe Kap | — |
| 5 | `32` | Sombrero | — |
| 6 | `64` | Top hat | — |
| 7 | `128` | Mask | — |
| 8 | `256` | Graduation cap | — |
| 9 | `512` | Goose | — |
| 10 | `1024` | Black fedora | — |
| 11 | `2048` | Blue fedora | — |
| 12 | `4096` | Pimp hat | — |
| 13 | `8192` | Headcrab | — |
| 14 | `16384` | Vader Cape | — |
| 15 | `32768` | Shoulder Yoda | — |
| 16 | `65536` | Horns | — |
| 17 | `131072` | Metal Helm | — |
| 18 | `262144` | Afro | — |
| 19 | `524288` | AK47 | — |
| 20 | `1048576` | Bucket | — |
| 21 | `2097152` | Crowbar | — |
| 22 | `4194304` | Crown | — |
| 23 | `8388608` | Royal Cape | — |
| 24 | `16777216` | Beard | — |
| 25 | `33554432` | Grogu | — |
| 26 | `67108864` | Plague Mask | — |
| 27 | `134217728` | Glasses | — |
| 28 | `268435456` | Mario | — |
| 29 | `536870912` | Rocket Launcher | — |
| 30 | `1073741824` | Predator | — |
| 31 | `2147483648` | Super Saiyan | — |
## Flags

- `CVAR_ARCHIVE`: saved to the user configuration
- `CVAR_USERINFO`: sent in the client's userinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`7778371e9614`](https://github.com/eternalcodes/EternalJK/commit/7778371e96142ef5afaea5c030ea863c9462d2aa) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-09-09`, integrated `2018-09-09`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:178](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L178)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-09` | — | `2018-09-09` | [`7778371e9614`](https://github.com/eternalcodes/EternalJK/commit/7778371e96142ef5afaea5c030ea863c9462d2aa) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-09` | — | `2018-09-09` | [`7778371e9614`](https://github.com/taysta/TaystJK/commit/7778371e96142ef5afaea5c030ea863c9462d2aa) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-09` | — | `2018-09-09` | [`7778371e9614`](https://github.com/videoP/jaPRO/commit/7778371e96142ef5afaea5c030ea863c9462d2aa) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-09` | — | `2018-09-09` | [`7778371e9614`](https://github.com/JKSunny/EternalJK/commit/7778371e96142ef5afaea5c030ea863c9462d2aa) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`239adf14f0b0`](https://github.com/videoP/jaPRO/commit/239adf14f0b06a96f929e6f5a56ce4cb8ef9fd16)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `high` |
| `2018-10-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293)<br>cosmetics | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-10-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b331bc16c5e`](https://github.com/eternalcodes/EternalJK/commit/0b331bc16c5ecbdb42571251f9ae6919918df506)<br>cringe cosmetic | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-09-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d0baa5bc31c9`](https://github.com/taysta/TaystJK/commit/d0baa5bc31c9dda8c055f33455c6224049779f0f)<br>Updated cosmetics and voice chat memes | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:207](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_xcvar.h#L207) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_consolecmds.c:1639](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1639)
- behavior: [codemp/cgame/cg_consolecmds.c:1720](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1720)
- behavior: [codemp/cgame/cg_consolecmds.c:1731](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1731)
- behavior: [codemp/cgame/cg_consolecmds.c:1741](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1741)
- behavior: [codemp/cgame/cg_consolecmds.c:1746](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/cgame/cg_consolecmds.c#L1746)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
