---
title: "vkinfo"
layout: reference
nav_exclude: true
search_exclude: false
---

# `vkinfo`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `vk_info_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `vkinfo` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`bd3a458a8bb2`](https://github.com/JKSunny/EternalJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5) on `2021-10-24` in <span class="label ref-origin ref-origin-vulkan">Vulkan</span>
- Matching squash bullet: `Added /vkinfo which shows Vulkan stats`
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:758](https://github.com/JKSunny/EternalJK/blob/b50059618803346a918f57220f856f1d0651dc39/codemp/rd-vulkan/tr_init.cpp#L758)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro, vulkan; fork-lineage order selects taystjk. An identifier-adjacent source/commit/PR line explicitly credits vulkan.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2021-10-24` | [`bd3a458a8bb2`](https://github.com/taysta/TaystJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2021-10-24` | [`bd3a458a8bb2`](https://github.com/videoP/jaPRO/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2021-10-24` | [`bd3a458a8bb2`](https://github.com/JKSunny/EternalJK/commit/bd3a458a8bb29a0348177f586389b98b5f7592a5) | Ultimate origin |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`f2d91900f16d`](https://github.com/taysta/TaystJK/commit/f2d91900f16d4db283e580386b9597c3ab0808d5) · [PR #135](https://github.com/taysta/TaystJK/pull/135)<br>Merge vulkan updates + jaPRO typo fix (#135) | Changed the registered command handler. `codemp/rd-vulkan/vk_info.cpp` | `medium` |
| `2025-08-08` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`cc93ec8c4139`](https://github.com/taysta/TaystJK/commit/cc93ec8c413928bdfb94db470566c1ec44d88903) · [PR #251](https://github.com/taysta/TaystJK/pull/251)<br>Merge pull request #251 from taysta/vk-update | Changed the registered command handler. `codemp/rd-vulkan/vk_info.cpp` | `medium` |
| `2026-06-01` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`22e66aeb32fc`](https://github.com/taysta/TaystJK/commit/22e66aeb32fca7ac91de70bc3474e4d23f38a8fa) · [PR #315](https://github.com/taysta/TaystJK/pull/315)<br>Merge pull request #315 from taysta/vk-up | Changed the registered command handler. `codemp/rd-vulkan/vk_info.cpp` | `medium` |
| `2026-07-30` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`e83cfff13d8d`](https://github.com/taysta/TaystJK/commit/e83cfff13d8de8eade347c143a22830c9e0d41c5) · [PR #352](https://github.com/taysta/TaystJK/pull/352)<br>Merge pull request #352 from taysta/vk-update | Changed the registered command handler. `codemp/rd-vulkan/vk_info.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:758](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/tr_init.cpp#L758) (renderer command table)
- handler: [codemp/rd-vulkan/vk_info.cpp:456](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-vulkan/vk_info.cpp#L456)
