---
title: "sv_autoWhitelist"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_autoWhitelist`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Automatically add IPs of players to a whitelist. Whitelisted IPs are can still access the server while it's under a DOS attack and they are stored in ipwhitelist.dat file. Collecting IP addresses without consent may be against European Union's General Data Protection Regulation.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_client.cpp:586](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L586) |
| `1` | Enabled. | [codemp/server/sv_client.cpp:586](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L586) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`8045afb65e1e`](https://github.com/mvdevs/jk2mv/commit/8045afb65e1e231f42e28c786f86476fadfe127b) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2018-06-10`, integrated `2018-06-10`)
- TaystJK integration evidence: [`fffc00dab968`](https://github.com/taysta/TaystJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)
- Upstream registration evidence: [src/server/sv_init.cpp:888](https://github.com/mvdevs/jk2mv/blame/7d601454c3db68492289d4d4e3dc30bff39e4246/src/server/sv_init.cpp#L888)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2018-06-10` | — | `2018-06-10` | [`8045afb65e1e`](https://github.com/mvdevs/jk2mv/commit/8045afb65e1e231f42e28c786f86476fadfe127b) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/taysta/TaystJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/videoP/jaPRO/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-04-27` | — | `2020-05-15` | [`fffc00dab968`](https://github.com/JKSunny/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2020-08-21` | — | `2020-08-21` | [`962f3198371a`](https://github.com/JACoders/OpenJK/commit/962f3198371a9c44093253cd04999155ac6a657f) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2020-08-21` | — | `2020-08-21` | [`962f3198371a`](https://github.com/SomaZ/OpenJK/commit/962f3198371a9c44093253cd04999155ac6a657f) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)<br>Merge pull request #97 from aufau/ratelimiter | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/server.h`, `codemp/server/sv_client.cpp`, `codemp/server/sv_init.cpp` and 1 more | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1053](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1053) (Cvar_Get)
- behavior: [codemp/server/sv_client.cpp:586](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_client.cpp#L586)
- upstream-documentation: [CVARS.rst:537](https://github.com/mvdevs/jk2mv/blame/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L537)
