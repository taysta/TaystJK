---
title: "vm_legacy"
layout: reference
nav_exclude: true
search_exclude: false
---

# `vm_legacy`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `vm_legacy` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_TEMP` — temporary and not archived

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-02-08`, integrated `2014-02-10`)
- Upstream registration evidence: [codemp/qcommon/vm.cpp:61](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/vm.cpp#L61)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/JACoders/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/eternalcodes/EternalJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/SomaZ/OpenJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/taysta/TaystJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/videoP/jaPRO/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/jkanewmod/NewJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-02-08` | — | `2014-02-10` | [`beadbaa9f0a2`](https://github.com/JKSunny/EternalJK/commit/beadbaa9f0a2f238d95065ed71fd2c7b277fcd35) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-04-01` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6474d6681d8`](https://github.com/JACoders/OpenJK/commit/f6474d6681d8b080595fe18d4056c23b5cbfbffa)<br>[MP] Clean up VM handling | Changed an exact bound cvar-variable reference. `codemp/qcommon/vm.cpp` | `medium` |
| `2019-04-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d62c674f6332`](https://github.com/eternalcodes/EternalJK/commit/d62c674f6332a590fb14285d9910a5ef3032928e)<br>Remove _DEBUG define from vm_legacy cvar. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/vm.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/vm.cpp:58](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/vm.cpp#L58) (Cvar_Get)
- behavior: [codemp/qcommon/vm.cpp:153](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/vm.cpp#L153)
