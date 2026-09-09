---
title: "cl_aviMotionJpeg"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_aviMotionJpeg`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_aviMotionJpeg` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_avi.cpp:366](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L366) |
| `1` | Enabled. | [codemp/client/cl_avi.cpp:366](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L366) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-13`, integrated `2013-04-13`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2760](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2760)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/eternalcodes/EternalJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/SomaZ/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/taysta/TaystJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/videoP/jaPRO/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/jkanewmod/NewJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-13` | — | `2013-04-13` | [`66642f7cd25a`](https://github.com/JKSunny/EternalJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-09-06` | — | `2016-10-27` | [`bf4971ea0c0b`](https://github.com/mvdevs/jk2mv/commit/bf4971ea0c0bd55531047f8e8c4de709a0d64b56) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3329](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3329) (Cvar_Get)
- behavior: [codemp/client/cl_avi.cpp:366](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L366)
