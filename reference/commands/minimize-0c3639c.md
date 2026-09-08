---
title: "minimize"
layout: reference
nav_exclude: true
search_exclude: false
---

# `minimize`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `GLimp_Minimize` in the engine-shared module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `minimize` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`a7c43677a2bb`](https://github.com/JKSunny/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) on `2015-02-07` in <span class="label ref-origin ref-origin-vulkan">Vulkan</span>
- Upstream registration evidence: [shared/sdl/sdl_window.cpp:784](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/shared/sdl/sdl_window.cpp#L784)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits vulkan.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JACoders/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/eternalcodes/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/SomaZ/OpenJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/taysta/TaystJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/videoP/jaPRO/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/jkanewmod/NewJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-02-07` | [`a7c43677a2bb`](https://github.com/JKSunny/EternalJK/commit/a7c43677a2bbba956ac3c5f14f2bf869ea660230) | Ultimate origin |
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2016-03-28` | [`59313f7414a1`](https://github.com/mvdevs/jk2mv/commit/59313f7414a1b36711f04c54e4fdebcca51e1400) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-04-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f6922b58dfc5`](https://github.com/eternalcodes/EternalJK/commit/f6922b58dfc5c2205303d5c122131d7c34bcd4e3)<br>Improved console timestamps, Added con_notifyname Setting con_notifyname to your name will highlight timestamps cyan if the name you set it to is mentioned to chat. If you have a short nickname like mine ("et"), you may want to set it to something like "@et" and tell every1 to say that if they want to contact you. If con_notifyname is set, the icon will flash if minimized or the window will flash if unfocused. (Only supported on Windows for now) Console now has proper indentation for all messages Repeated timestamps are replaced with "::::::::" Chat msgs have white timestamps instead of Grey User inputted commands have green timestamps Improved R_PrintLongString so that words aren't cut off | Changed the registered command handler. `shared/sdl/sdl_window.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed the registered command handler. `shared/sdl/sdl_window.cpp` | `high` |

## Evidence

- registration: [shared/sdl/sdl_window.cpp:791](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L791) (Cmd_AddCommand)
- handler: [shared/sdl/sdl_window.cpp:146](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sdl/sdl_window.cpp#L146)
