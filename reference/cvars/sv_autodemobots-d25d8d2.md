---
title: "sv_autoDemoBots"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_autoDemoBots`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Record server-side demos for bots

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/server/sv_ccmds.cpp:2043](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2043) |
| `1` | Enabled. | [codemp/server/sv_ccmds.cpp:2043](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2043) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-01-29`, integrated `2014-02-10`)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1006](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1006)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/eternalcodes/EternalJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/SomaZ/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/taysta/TaystJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/videoP/jaPRO/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/jkanewmod/NewJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-29` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/JKSunny/EternalJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp`, `codemp/server/sv_snapshot.cpp` | `high` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1039](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1039) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_ccmds.cpp:2043](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2043)
- behavior: [codemp/server/sv_snapshot.cpp:1026](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_snapshot.cpp#L1026)
