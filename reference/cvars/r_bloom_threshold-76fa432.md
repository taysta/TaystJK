---
title: "r_bloom_threshold"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_bloom_threshold`

<span class="label ref-origin ref-origin-vulkan">Vulkan</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Color level to extract to bloom texture, default is 0.05

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Feature family | Bloom |
| Module | `renderer` |
| Renderer | `rd-vulkan` |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2021-05-25 in [`c4a9c87ef`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0.05` |
| Value type | `float` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `0.01f` through `1` (numeric; Cvar_CheckRange). Evidence: [codemp/rd-vulkan/tr_init.cpp:941](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/rd-vulkan/tr_init.cpp#L941)

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created
- `CVAR_LATCH`: latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-vulkan">Vulkan</span>

- Ultimate-origin introduction: [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) in <span class="label ref-origin ref-origin-vulkan">Vulkan</span> (content authored `2021-05-25`, integrated `2021-05-25`)
- Upstream registration evidence: [codemp/rd-vulkan/tr_init.cpp:939](https://github.com/JKSunny/EternalJK/blame/878e4ad087779c379c5925fed27c9d56efdf3faa/codemp/rd-vulkan/tr_init.cpp#L939)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits vulkan.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/taysta/TaystJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/videoP/jaPRO/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2021-05-25` | — | `2021-05-25` | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4) | Ultimate origin |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-10-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`85114c9abfce`](https://github.com/taysta/TaystJK/commit/85114c9abfce0a2c70681224b30ef0bafac2a186)<br>Merge remote-tracking branch 'SunnyJK/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vulkan/tr_init.cpp:940](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/rd-vulkan/tr_init.cpp#L940) (Cvar_Get)
- behavior: [codemp/rd-vulkan/vk_pipelines.cpp:1522](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/rd-vulkan/vk_pipelines.cpp#L1522)
- behavior: [codemp/rd-vulkan/tr_init.cpp:941](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/rd-vulkan/tr_init.cpp#L941)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
