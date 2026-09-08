---
title: "net_dropsim"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_dropsim`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `net_dropsim` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_TEMP` — temporary and not archived

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`e8453d791c74`](https://github.com/JACoders/OpenJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) on `2016-03-20` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`f5defc782a90`](https://github.com/taysta/TaystJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)
- Upstream registration evidence: [codemp/qcommon/net_ip.cpp:894](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/qcommon/net_ip.cpp#L894)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2, newjk; fork-lineage order selects openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2016-03-20` | [`e8453d791c74`](https://github.com/JACoders/OpenJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2016-03-20` | [`e8453d791c74`](https://github.com/SomaZ/OpenJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-03-20` | [`e8453d791c74`](https://github.com/jkanewmod/NewJK/commit/e8453d791c746cf10be9312cf52dd82421d74aa0) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-03-21` | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-03-21` | [`f5defc782a90`](https://github.com/taysta/TaystJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-03-21` | [`f5defc782a90`](https://github.com/videoP/jaPRO/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-03-21` | [`f5defc782a90`](https://github.com/JKSunny/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc) | Later project appearance |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-03-28` | [`59313f7414a1`](https://github.com/mvdevs/jk2mv/commit/59313f7414a1b36711f04c54e4fdebcca51e1400) | Later project appearance |

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:910](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L910) (Cvar_Get)
- behavior: [codemp/qcommon/net_ip.cpp:1035](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L1035)
- behavior: [codemp/qcommon/net_ip.cpp:1038](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L1038)
