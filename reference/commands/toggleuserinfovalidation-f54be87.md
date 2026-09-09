---
title: "toggleuserinfovalidation"
layout: reference
nav_exclude: true
search_exclude: false
---

# `toggleuserinfovalidation`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Svcmd_ToggleUserinfoValidation_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `toggleuserinfovalidation [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-23`, integrated `2013-04-24`)
- Upstream registration evidence: [codemp/game/g_svcmds.c:492](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_svcmds.c#L492)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/eternalcodes/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/SomaZ/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/taysta/TaystJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/videoP/jaPRO/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/jkanewmod/NewJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-23` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JKSunny/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed the registered command handler. `codemp/game/g_local.h` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed the registered command handler. `codemp/game/g_client.c` | `medium` |
| `2013-11-21` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`03e8231c183e`](https://github.com/JACoders/OpenJK/commit/03e8231c183ef3208e54acaccb73288d33a14de1)<br>[MP] Make g_svcmds use bsearch method for commands. Improve listip command. Improve ded server say cmd. | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/game/g_svcmds.c` | `medium` |
| `2014-01-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d63be8a74acc`](https://github.com/JACoders/OpenJK/commit/d63be8a74acc0af07f4fca0658ce9353c9e415a2)<br>[MP] Fix userinfo validation counting values as instances of keys | Changed the registered command handler. `codemp/game/g_client.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dc13e8c9235e`](https://github.com/JACoders/OpenJK/commit/dc13e8c9235ee4a8f37b7888fb40acab7b18e267)<br>[MP] Fix toggleuserinfovalidation to work if value was -1. | Changed the registered command handler. `codemp/game/g_client.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`bb3ed393a5fb`](https://github.com/JACoders/OpenJK/commit/bb3ed393a5fb8c3b280f4ae9a12b3fb9d04ee4a5)<br>[MP] Add toggleallowvote server command for easy toggling of g_allowVote bit options. | Changed the registered command handler. `codemp/game/g_local.h` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16ffb293eb64`](https://github.com/JACoders/OpenJK/commit/16ffb293eb6458a04793fa923590c83f7ad06bdf)<br>[MP] Fix operator precedence in toggleuserinfovalidation. | Changed the registered command handler. `codemp/game/g_client.c` | `medium` |

## Evidence

- registration: [codemp/game/g_svcmds.c:1712](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1712) (game-console command table)
- handler: [codemp/game/g_client.c:2125](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2125)
