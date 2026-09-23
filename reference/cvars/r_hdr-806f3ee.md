---
title: "r_hdr"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_hdr`

<span class="label ref-origin ref-origin-rend2">rend2</span>

Disable/enable rendering in HDR

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Renderer | `rd-rend2`, `rd-vulkan` |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Added | 2021-05-25 in [`c4a9c87ef`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame_setup.menu:1840](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame_setup.menu#L1840), [setup.menu:1630](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/setup.menu#L1630) |
| Default | `1` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/vk_instance.cpp:365](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/vk_instance.cpp#L365) |
| `1` | Enabled. | [codemp/rd-vulkan/vk_instance.cpp:365](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/vk_instance.cpp#L365) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `1` | `renderer` | `rd-rend2` | `always` |
| `1` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) in <span class="label ref-origin ref-origin-rend2">rend2</span> (content authored `2013-10-08`, integrated `2023-10-03`)
- TaystJK integration evidence: [`c4a9c87ef0e3`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1504](https://github.com/SomaZ/OpenJK/blame/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1504)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`
- Notes: rend2 retains origin because content authorship and PR submission predate the project that merged the work first. The TaystJK integration evidence credits vulkan as an immediate port source, but rend2 has an earlier dated introduction and remains the ultimate origin. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-10-08` | — | `2023-10-03` | [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-10-08` | — | `2023-10-03` | [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/videoP/jaPRO/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>. The earlier dated project remains the ultimate origin.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h`, `codemp/rd-vulkan/vk_instance.cpp` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2023-10-14` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`aa48e28a7d4f`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) · [PR #26](https://github.com/taysta/TaystJK/pull/26)<br>Merge pull request #26 from taysta/rend2menu | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_backend.cpp`, `shared/rd-rend2/tr_bsp.cpp`, `shared/rd-rend2/tr_glsl.cpp` and 3 more | `medium` |
| `2024-02-26` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) · [PR #157](https://github.com/taysta/TaystJK/pull/157)<br>Upstream update (#157) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_scene.cpp` | `medium` |
| `2024-03-22` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`76e492e67f08`](https://github.com/taysta/TaystJK/commit/76e492e67f08d26ebabe877ca68d24d18efb42c9) · [PR #183](https://github.com/taysta/TaystJK/pull/183)<br>Rend2 sync (#183) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_bsp.cpp`, `shared/rd-rend2/tr_image.cpp` | `medium` |
| `2024-05-02` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`8397d66511c4`](https://github.com/taysta/TaystJK/commit/8397d66511c43277ad953ea8554b3e0a9f10abe2) · [PR #192](https://github.com/taysta/TaystJK/pull/192)<br>Rend2 updates (#192) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_bsp.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1539](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-rend2/tr_init.cpp#L1539) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:927](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_init.cpp#L927) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_instance.cpp:365](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/vk_instance.cpp#L365)
- behavior: [shared/rd-rend2/tr_backend.cpp:2063](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_backend.cpp#L2063)
- behavior: [shared/rd-rend2/tr_backend.cpp:3030](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_backend.cpp#L3030)
- behavior: [shared/rd-rend2/tr_backend.cpp:3218](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_backend.cpp#L3218)
- behavior: [shared/rd-rend2/tr_bsp.cpp:922](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_bsp.cpp#L922)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
