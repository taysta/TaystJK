---
title: "com_affinity"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_affinity`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_affinity` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`d3ecd6191c5b`](https://github.com/JACoders/OpenJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-04-04`, integrated `2014-04-04`)
- Upstream registration evidence: [code/qcommon/common.cpp:1151](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/common.cpp#L1151)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/JACoders/OpenJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/eternalcodes/EternalJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/SomaZ/OpenJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/taysta/TaystJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/videoP/jaPRO/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/jkanewmod/NewJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-04-04` | — | `2014-04-04` | [`d3ecd6191c5b`](https://github.com/JKSunny/EternalJK/commit/d3ecd6191c5b92509a6491f10eac74cabf8a8daa) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-04-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`4210551db101`](https://github.com/JACoders/OpenJK/commit/4210551db101eb0f6e1cc69a79ef4e51924a4a3f)<br>[SP] Added com_affinity bit-flag to force which cores can be used | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2014-04-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7ba1d94fc7e6`](https://github.com/JACoders/OpenJK/commit/7ba1d94fc7e6a1ce23ac6aff563ced7d89a29b17)<br>[MP] Move processor affinity code to platform-specific files. Check return value of getcwd on Unix systems | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `codemp/qcommon/qcommon.h` | `medium` |
| `2014-04-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d13b8a96094a`](https://github.com/JACoders/OpenJK/commit/d13b8a96094ac466aaa779fc51039f85377a2f6b)<br>[MP] Fix bad merge for processor affinity code on Windows | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `shared/sys/sys_unix.cpp`, `shared/sys/sys_win32.cpp` | `medium` |
| `2015-03-08` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`73d5136d1b49`](https://github.com/JACoders/OpenJK/commit/73d5136d1b49cd7ada6f6beab7828764c3482edd)<br>[Shared] Set CPU affinity on com_affinity modify | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp`, `codemp/qcommon/common.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `medium` |
| `2024-01-14` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ae65327ce26e`](https://github.com/taysta/TaystJK/commit/ae65327ce26e305173e49801d575c8cf6402638c) · [PR #90](https://github.com/taysta/TaystJK/pull/90)<br>Merge pull request #90 from taysta/fix-win64-warnings | Changed an exact bound cvar-variable reference. `shared/sys/sys_win32.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/common.cpp:1494](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1494) (Cvar_Get)
- behavior: [shared/sys/sys_unix.cpp:545](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L545)
- behavior: [shared/sys/sys_win32.cpp:235](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L235)
- behavior: [codemp/qcommon/common.cpp:1895](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1895)
- behavior: [codemp/qcommon/common.cpp:1897](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1897)
