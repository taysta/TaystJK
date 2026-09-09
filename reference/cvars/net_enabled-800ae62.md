---
title: "net_enabled"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_enabled`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `net_enabled` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bitmask` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0x01` | Enables the `NET_ENABLEV4` code path. | [codemp/qcommon/qcommon.h:116](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/qcommon.h#L116) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`cd5d3753f0a7`](https://github.com/JACoders/OpenJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-01-31`, integrated `2014-01-31`)
- Upstream registration evidence: [codemp/qcommon/net_ip.cpp:858](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/net_ip.cpp#L858)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/JACoders/OpenJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/eternalcodes/EternalJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/SomaZ/OpenJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/taysta/TaystJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/videoP/jaPRO/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/jkanewmod/NewJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-01-31` | — | `2014-01-31` | [`cd5d3753f0a7`](https://github.com/JKSunny/EternalJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-03-25` | — | `2016-03-28` | [`59313f7414a1`](https://github.com/mvdevs/jk2mv/commit/59313f7414a1b36711f04c54e4fdebcca51e1400) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/net_ip.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:874](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L874) (Cvar_Get)
- behavior: [codemp/qcommon/net_ip.cpp:844](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L844)
- behavior: [codemp/qcommon/net_ip.cpp:928](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L928)
- behavior: [codemp/qcommon/net_ip.cpp:971](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L971)
- behavior: [codemp/qcommon/net_ip.cpp:875](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L875)
- behavior: [codemp/qcommon/net_ip.cpp:876](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/net_ip.cpp#L876)
