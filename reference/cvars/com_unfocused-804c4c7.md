---
title: "com_unfocused"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_unfocused`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `com_unfocused` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2015-01-10`, integrated `2015-02-07`)
- Upstream registration evidence: [shared/sys/sys_main.cpp:159](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/shared/sys/sys_main.cpp#L159)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/eternalcodes/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/SomaZ/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/taysta/TaystJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/videoP/jaPRO/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/jkanewmod/NewJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-01-10` | — | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JKSunny/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared integration commit |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2015-03-19` | — | `2015-03-19` | [`907e53cc40d4`](https://github.com/mvdevs/jk2mv/commit/907e53cc40d4a9a3b0ea7cc9abf815221eef8e1a) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-03-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`65fe955170be`](https://github.com/JACoders/OpenJK/commit/65fe955170bebf5f146a8cdb6076fe065aaae3c3)<br>[Shared] Fix #629: Mute sound on window minimize | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2016-04-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6922b58dfc5`](https://github.com/eternalcodes/EternalJK/commit/f6922b58dfc5c2205303d5c122131d7c34bcd4e3)<br>Improved console timestamps, Added con_notifyname Setting con_notifyname to your name will highlight timestamps cyan if the name you set it to is mentioned to chat. If you have a short nickname like mine ("et"), you may want to set it to something like "@et" and tell every1 to say that if they want to contact you. If con_notifyname is set, the icon will flash if minimized or the window will flash if unfocused. (Only supported on Windows for now) Console now has proper indentation for all messages Repeated timestamps are replaced with "::::::::" Chat msgs have white timestamps instead of Grey User inputted commands have green timestamps Improved R_PrintLongString so that words aren't cut off | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/client/snd_dma.cpp` | `medium` |
| `2018-11-08` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7bc2134b98d4`](https://github.com/eternalcodes/EternalJK/commit/7bc2134b98d469a1a5d59ae6c7efff6d1b703ef8)<br>Minimized/unfocused chatbubble recode | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |
| `2019-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ba0a05b38b4a`](https://github.com/eternalcodes/EternalJK/commit/ba0a05b38b4a56946ba970902c0fd50970ce2e72)<br>snd_mute_losefocus | Changed an exact bound cvar-variable reference. `codemp/client/snd_dma.cpp` | `medium` |
| `2019-06-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`95bd6ae28589`](https://github.com/eternalcodes/EternalJK/commit/95bd6ae28589147d1f292e936fad2d42b0cffc41)<br>Fix non-raw-input option after 01081bc | Changed an exact bound cvar-variable reference. `shared/sdl/sdl_input.cpp` | `medium` |
| `2026-04-19` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86f04849f381`](https://github.com/taysta/TaystJK/commit/86f04849f3811cf7ddbc79a13d19377e5e783665) · [PR #302](https://github.com/taysta/TaystJK/pull/302)<br>[client] add option to toggle unfocused chat bubble behaviour via cl_chatBubbleUnfocused, as well as cl_chatBubbleSelf to disable ever bringing up chat bubble (#302) | Changed an exact bound cvar-variable reference. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [shared/sys/sys_main.cpp:169](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_main.cpp#L169) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1264](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_input.cpp#L1264)
- behavior: [codemp/client/snd_dma.cpp:1581](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L1581)
- behavior: [codemp/qcommon/common.cpp:1757](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1757)
- behavior: [shared/sdl/sdl_input.cpp:845](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L845)
- behavior: [shared/sdl/sdl_input.cpp:665](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sdl/sdl_input.cpp#L665)
