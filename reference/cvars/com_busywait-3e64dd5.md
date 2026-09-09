---
title: "com_busyWait"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_busyWait`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_busyWait` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/qcommon/common.cpp:1781](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1781) |
| `1` | Enabled. | [codemp/qcommon/common.cpp:1781](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1781) |

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`e8453d791c74`](https://github.com/JACoders/OpenJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2016-03-12`, integrated `2016-03-20`)
- TaystJK integration evidence: [`f5defc782a90`](https://github.com/taysta/TaystJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)
- Upstream registration evidence: [code/qcommon/common.cpp:1152](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/common.cpp#L1152)
- Attribution method: `shared-integration-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2016-03-12` | — | `2016-03-20` | [`e8453d791c74`](https://github.com/JACoders/OpenJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2016-03-12` | — | `2016-03-20` | [`e8453d791c74`](https://github.com/SomaZ/OpenJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-03-12` | — | `2016-03-20` | [`e8453d791c74`](https://github.com/jkanewmod/NewJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-12` | — | `2016-03-21` | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-12` | — | `2016-03-21` | [`f5defc782a90`](https://github.com/taysta/TaystJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-12` | — | `2016-03-21` | [`f5defc782a90`](https://github.com/videoP/jaPRO/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-12` | — | `2016-03-21` | [`f5defc782a90`](https://github.com/JKSunny/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Other project appearance |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-03-25` | — | `2016-03-28` | [`59313f7414a1`](https://github.com/mvdevs/jk2mv/commit/59313f7414a1b36711f04c54e4fdebcca51e1400) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1498](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1498) (Cvar_Get)
- behavior: [codemp/qcommon/common.cpp:1781](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1781)
- behavior: [shared/sys/sys_main.cpp:760](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L760)
