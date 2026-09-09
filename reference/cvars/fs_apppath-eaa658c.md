---
title: "fs_apppath"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_apppath`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

(Read Only) Location of OSX .app bundle

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `Sys_DefaultAppPath()` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting
- `CVAR_PROTECTED` — protected from unsafe remote changes

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-06-29`, integrated `2013-11-12`)
- Upstream registration evidence: [code/qcommon/files.cpp:2906](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/files.cpp#L2906)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/eternalcodes/EternalJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/SomaZ/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/taysta/TaystJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/videoP/jaPRO/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/jkanewmod/NewJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-06-29` | — | `2013-11-12` | [`2229f7cb1aba`](https://github.com/JKSunny/EternalJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-01-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`c00c4904efbe`](https://github.com/JACoders/OpenJK/commit/c00c4904efbeca1152d105f386a8584d4b76ecb8)<br>[SP] Refactored files code to single file. Breaks compat with older jagame/jospgame modules and older renderer modules for SP/JKS2SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2015-02-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230)<br>Merge pull request #613 from JACoders/sdl2-windows-port | Changed an exact bound cvar-variable reference. `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp`, `shared/sys/sys_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2018-01-07` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`bc1b6d1d879b`](https://github.com/eternalcodes/EternalJK/commit/bc1b6d1d879b9992c6b07399fd78e6d4761959ad)<br>Remove LoadSPGameDll | Changed an exact bound cvar-variable reference. `shared/sys/sys_main.cpp` | `medium` |
| `2018-12-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`546dfb076f6f`](https://github.com/videoP/jaPRO/commit/546dfb076f6f12d4fc8ebedb8302e7cfa6aad54e)<br>OSX: Fix basepath (japro-assets) not loading from apppath? | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3942](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3942) (Cvar_Get); condition `defined(MACOS_X)`
- behavior: [codemp/qcommon/files.cpp:3944](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3944)
- behavior: [codemp/qcommon/files.cpp:3965](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3965)
- behavior: [codemp/qcommon/files.cpp:3945](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3945)
- behavior: [codemp/qcommon/files.cpp:3966](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3966)
- behavior: [codemp/qcommon/files.cpp:3816](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3816)
