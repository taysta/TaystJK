---
title: "sv_autoDemoMaxMaps"
layout: reference
nav_exclude: true
search_exclude: false
---

# `sv_autoDemoMaxMaps`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `sv_autoDemoMaxMaps` in the engine-server module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `engine-server` |
| Also registered in | `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
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
| `0` | Disabled. | [codemp/server/sv_ccmds.cpp:2049](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2049) |
| `1` | Enabled. | [codemp/server/sv_ccmds.cpp:2049](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2049) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-01-29`, integrated `2014-02-10`)
- Upstream registration evidence: [codemp/server/sv_init.cpp:1007](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/server/sv_init.cpp#L1007)
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
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/server/sv_ccmds.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/server/sv_init.cpp` | `medium` |

## Evidence

- registration: [codemp/server/sv_init.cpp:1040](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_init.cpp#L1040) (Cvar_Get); condition `defined(DEDICATED)`
- behavior: [codemp/server/sv_ccmds.cpp:2049](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2049)
- behavior: [codemp/server/sv_ccmds.cpp:2055](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/server/sv_ccmds.cpp#L2055)
