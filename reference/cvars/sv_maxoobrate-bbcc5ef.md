---
title: "sv_maxOOBRate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_maxOOBRate`

<span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

Max out-of-bound requests handled per second. Increasing rate improves server responsiveness at the cost of higher CPU usage.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1000` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-jk2mv">JK2MV</span>

- Ultimate-origin introduction: [`050fbe5141b1`](https://github.com/mvdevs/jk2mv/commit/050fbe5141b1e571106ddfa646037a3177c273d4) in <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> (content authored `2017-08-16`, integrated `2017-08-18`)
- TaystJK integration evidence: [`fffc00dab968`](https://github.com/taysta/TaystJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)
- Upstream registration evidence: [src/server/sv_init.cpp:832](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/src/server/sv_init.cpp#L832)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2017-08-16` | — | `2017-08-18` | [`050fbe5141b1`](https://github.com/mvdevs/jk2mv/commit/050fbe5141b1e571106ddfa646037a3177c273d4) | Ultimate origin |
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
| `2020-05-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fffc00dab968`](https://github.com/eternalcodes/EternalJK/commit/fffc00dab96867fef0aad58ca3610cd7c5c2a78a)<br>Merge pull request #97 from aufau/ratelimiter | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/server.h`, `codemp/server/sv_init.cpp`, `codemp/server/sv_main.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1051](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1051) (Cvar_Get)
- behavior: [codemp/server/sv_main.cpp:753](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L753)
- behavior: [codemp/server/sv_main.cpp:754](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_main.cpp#L754)
- upstream-documentation: [CVARS.rst:589](https://github.com/mvdevs/jk2mv/blob/7d601454c3db68492289d4d4e3dc30bff39e4246/CVARS.rst#L589)
