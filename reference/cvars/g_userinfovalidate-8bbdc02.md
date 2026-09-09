---
title: "g_userinfoValidate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_userinfoValidate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_userinfoValidate` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-07`, integrated `2013-04-07`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:167](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L167)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/eternalcodes/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/SomaZ/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/taysta/TaystJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/videoP/jaPRO/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/jkanewmod/NewJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JKSunny/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_client.c`, `codemp/game/g_xcvar.h` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2014-01-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d63be8a74acc`](https://github.com/JACoders/OpenJK/commit/d63be8a74acc0af07f4fca0658ce9353c9e415a2)<br>[MP] Fix userinfo validation counting values as instances of keys | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`dc13e8c9235e`](https://github.com/JACoders/OpenJK/commit/dc13e8c9235ee4a8f37b7888fb40acab7b18e267)<br>[MP] Fix toggleuserinfovalidation to work if value was -1. | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`16ffb293eb64`](https://github.com/JACoders/OpenJK/commit/16ffb293eb6458a04793fa923590c83f7ad06bdf)<br>[MP] Fix operator precedence in toggleuserinfovalidation. | Changed an exact bound cvar-variable reference. `codemp/game/g_client.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `high` |
| `2018-09-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd)<br>Added jcinfo2 to allow UI to only show Race button when relevant | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:164](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L164) (XCVAR_DEF)
- behavior: [codemp/game/g_client.c:2129](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2129)
- behavior: [codemp/game/g_client.c:2133](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2133)
- behavior: [codemp/game/g_client.c:2153](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2153)
- behavior: [codemp/game/g_client.c:2169](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2169)
- behavior: [codemp/game/g_client.c:2177](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_client.c#L2177)
