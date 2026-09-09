---
title: "cl_aviFrameRate"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_aviFrameRate`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_aviFrameRate` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `25` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`66642f7cd25a`](https://github.com/JACoders/OpenJK/commit/66642f7cd25a88085f4ec88cc1b234fe99f8499e) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-13`, integrated `2013-04-13`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2759](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2759)
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

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-10-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b0d61035c755`](https://github.com/JACoders/OpenJK/commit/b0d61035c755ae1921291fd23abc5053e0eb4d2c)<br>[MP] Plausible fix from q3mme/ent for avi record sync issues. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp` | `medium` |
| `2013-10-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1520ebb09e32`](https://github.com/JACoders/OpenJK/commit/1520ebb09e32787b965bc6cf733e44d9e109952e)<br>[MP] Fixed audio desync with avi record. | Changed an exact bound cvar-variable reference. `codemp/client/snd_dma.cpp` | `medium` |
| `2013-11-02` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`22badd6b5cf9`](https://github.com/JACoders/OpenJK/commit/22badd6b5cf9e3a29b933b0f2b09d7c127d96506)<br>[MP] Try ioq3's version of the video record desync fix. Though technically its not any different. | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/client/snd_dma.cpp` | `medium` |
| `2015-02-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e6464f352161`](https://github.com/JACoders/OpenJK/commit/e6464f35216195f7b292a711470ebd9feb268279)<br>[Shared] Rename min/max macro to Q_min/Q_max | Changed an exact bound cvar-variable reference. `codemp/client/cl_main.cpp`, `codemp/client/snd_dma.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3328](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3328) (Cvar_Get)
- behavior: [codemp/client/cl_avi.cpp:343](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L343)
- behavior: [codemp/client/cl_main.cpp:2496](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2496)
- behavior: [codemp/client/cl_avi.cpp:361](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_avi.cpp#L361)
- behavior: [codemp/client/cl_main.cpp:2498](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L2498)
- behavior: [codemp/client/snd_dma.cpp:2854](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L2854)
