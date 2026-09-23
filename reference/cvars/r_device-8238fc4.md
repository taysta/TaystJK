---
title: "r_device"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_device`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Select physical device to render: 0+ - use explicit device index -1 - first discrete GPU -2 - first integrated GPU

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2013-04-08 in [`14cea1563`](https://github.com/taysta/TaystJK/commit/14cea1563762076974bee277afadbd5bf234c494) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `-1` |
| Value type | `enum` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0+` | Use explicit device index. | [codemp/rd-vulkan/tr_init.cpp:912](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L912) |
| `-1` | First discrete GPU. | [codemp/rd-vulkan/tr_init.cpp:912](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L912) |
| `-2` | First integrated GPU. | [codemp/rd-vulkan/tr_init.cpp:912](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L912) |

## Enforced ranges

- `-2` through `8` (integer; Cvar_CheckRange). Evidence: [codemp/rd-vulkan/tr_init.cpp:916](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L916)

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/mac/mac_glimp.c:701](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/mac/mac_glimp.c#L701)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/mac/mac_glimp.c` | `high` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h`, `codemp/rd-vulkan/vk_instance.cpp` | `high` |
| `2022-02-16` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`5ce497f25666`](https://github.com/JKSunny/EternalJK/commit/5ce497f2566623286479896ff9c01952cf0eb146)<br>Vulkan: linux & mac compiler warnings/errors cleanup. | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_init.cpp` | `high` |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:912](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L912) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_instance.cpp:946](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/vk_instance.cpp#L946)
- behavior: [codemp/rd-vulkan/tr_init.cpp:917](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L917)
- behavior: [codemp/rd-vulkan/tr_init.cpp:916](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L916)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
