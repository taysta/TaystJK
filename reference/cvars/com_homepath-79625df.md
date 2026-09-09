---
title: "com_homepath"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_homepath`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_homepath` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Files & downloads |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-20`, integrated `2013-04-24`)
- Upstream registration evidence: [code/qcommon/common.cpp:1105](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/common.cpp#L1105)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/eternalcodes/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/SomaZ/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/taysta/TaystJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/videoP/jaPRO/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/jkanewmod/NewJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-20` | — | `2013-04-24` | [`f6cadd34c6ab`](https://github.com/JKSunny/EternalJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-07-19` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a1bbd5558365`](https://github.com/JACoders/OpenJK/commit/a1bbd55583652e9078ea58e555526f8c16120425)<br>Ported some filesystem changes from MP to SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `shared/sys/sys_unix.cpp`, `shared/sys/sys_win32.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1391](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1391) (Cvar_Get)
- behavior: [shared/sys/sys_unix.cpp:498](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L498)
- behavior: [shared/sys/sys_unix.cpp:517](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L517)
- behavior: [shared/sys/sys_unix.cpp:528](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L528)
- behavior: [shared/sys/sys_win32.cpp:201](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L201)
- behavior: [shared/sys/sys_unix.cpp:499](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L499)
