---
title: "g_tweakForce"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_tweakForce`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Set with <code>tweakForce</code>.</strong> Each bit is a separate option, so the command toggles one of them per use and leaves the rest alone. Setting a raw value by hand replaces every option at once.</p>

Configured with /tweakForce command.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2018-01-01 in [`d9d510063`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) <span class="status-chip">needs review</span> — [how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |
| Configure with | [`tweakForce`](/TaystJK/reference/commands/tweakforce-05bb9d3/) |

## Bits

Use [`tweakForce`](/TaystJK/reference/commands/tweakforce-05bb9d3/) to toggle one option at a time; see the command page for syntax. The value column is that bit on its own — [the labels come from the source table](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L987).

| Bit | Value | Meaning | Read by |
|:--|:--|:--|:--|
| 0 | `1` | No forcepower drain for crouch attack | — |
| 1 | `2` | Fix projectile force push dir | — |
| 2 | `4` | Can push/pull knocked down players | — |
| 3 | `8` | Fix grip absorb | — |
| 4 | `16` | Allow force combo | [codemp/game/g_local.h:251](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L251) |
| 5 | `32` | Fix pull strength | — |
| 6 | `64` | JK2 grip | — |
| 7 | `128` | Fast grip runspeed | [codemp/game/g_local.h:254](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L254) |
| 8 | `256` | Push/pull items | — |
| 9 | `512` | Smaller Drain COF | — |
| 10 | `1024` | JK2 push/pull knockdown | — |
| 11 | `2048` | JK2 style knockdown getup | — |
| 12 | `4096` | Allow push/pull during roll like JK2 | — |
| 13 | `8192` | Force drain does not give forcepoints to players using force absorb | — |
| 14 | `16384` | Allow grip during roll | — |
| 15 | `32768` | Weak force pull | — |
| 16 | `65536` | Nerfed weapon pull distance | — |
| 17 | `131072` | Force resistance while firing/charging weapon | — |
| 18 | `262144` | Stop rage from affecting firerate of weapons | [codemp/game/g_local.h:265](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L265) |
| 19 | `524288` | Don't break mindtrick on attack unless trickee is looking at you | — |
| 20 | `1048576` | Stronger / different Melee attack | [codemp/game/g_local.h:267](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_local.h#L267) |
| 21 | `2097152` | Drain takes 25% less force from target | — |
| 22 | `4194304` | Regen force while being gripped if mid jump | — |
| 23 | `8388608` | Drain level 3 is a line | — |
## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2015-04-17`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:210](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L210)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-04-17` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6e78add659de`](https://github.com/eternalcodes/EternalJK/commit/6e78add659de33e4919f25aefad3e61546599f3c)<br>Merge remote-tracking branch 'videoP/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_cmds.c`, `codemp/game/w_force.c` | `medium` |
| `2018-10-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`116fd88bcf51`](https://github.com/videoP/jaPRO/commit/116fd88bcf51c2c7e504191b5878cf04e50d6357)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2020-06-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`fb24d6a98965`](https://github.com/videoP/jaPRO/commit/fb24d6a989657d508aa3c722e53dc203d6327e69)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/ai_main.c`, `codemp/game/bg_pmove.c`, `codemp/game/g_cmds.c` and 3 more | `high` |
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2024-04-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`258031c97e93`](https://github.com/videoP/jaPRO/commit/258031c97e933f2293dc35c18af5ea16847f0241) · [PR #188](https://github.com/taysta/TaystJK/pull/188)<br>Japro update (#188) | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2024-05-02` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`13eac340e1ce`](https://github.com/videoP/jaPRO/commit/13eac340e1ce2e81ab6cbb47e21d984892a78c2a) · [PR #193](https://github.com/taysta/TaystJK/pull/193)<br>Japro update (#193) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2024-05-24` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`8188f06a4e61`](https://github.com/videoP/jaPRO/commit/8188f06a4e617f146c075888a885ab2dedeecd73) · [PR #204](https://github.com/taysta/TaystJK/pull/204)<br>Japro update (#204) | Changed an exact bound cvar-variable reference. `codemp/game/w_force.c` | `high` |
| `2024-05-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`55aceb66a04c`](https://github.com/videoP/jaPRO/commit/55aceb66a04ccbf948c3111148b9ab1116058867) · [PR #207](https://github.com/taysta/TaystJK/pull/207)<br>Japro update (#207) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/w_force.c` | `high` |
| `2024-09-22` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`100cdfc116b9`](https://github.com/videoP/jaPRO/commit/100cdfc116b94679dbdc41940a21b36acc492b7b) · [PR #212](https://github.com/taysta/TaystJK/pull/212)<br>Japro Update | Changed an exact bound cvar-variable reference. `codemp/game/g_cvar.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:209](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L209) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:8079](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/ai_main.c#L8079)
- behavior: [codemp/game/bg_pmove.c:11228](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L11228)
- behavior: [codemp/game/bg_pmove.c:12017](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L12017)
- behavior: [codemp/game/bg_pmove.c:12029](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L12029)
- behavior: [codemp/game/bg_pmove.c:14117](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L14117)
- documentation: [docs/japro_docs.md:29](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/docs/japro_docs.md#L29)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
