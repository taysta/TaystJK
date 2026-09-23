---
title: "r_mergeMultidraws"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `r_mergeMultidraws`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_mergeMultidraws` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-10-03 in [`86c075638`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/rd-vulkan/tr_ghoul2.cpp:3703](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_ghoul2.cpp#L3703) |
| `1` | Enabled. | [codemp/rd-vulkan/tr_ghoul2.cpp:3703](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_ghoul2.cpp#L3703) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) in <span class="label ref-origin ref-origin-rend2">rend2</span> (content authored `2018-05-11`, integrated `2023-10-03`)
- TaystJK integration evidence: [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919)
- Origin pull request: [#12](https://github.com/taysta/TaystJK/pull/12)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1600](https://github.com/SomaZ/OpenJK/blame/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1600)
- Attribution method: `shared-integration-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2018-05-11` | — | `2023-10-03` | [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2018-05-11` | — | `2023-10-03` | [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-03` | [2023-09-30](https://github.com/taysta/TaystJK/pull/12) | `2023-10-03` | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-03` | — | `2023-10-03` | [`86c0756385ef`](https://github.com/videoP/jaPRO/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed an exact bound cvar-variable reference. `shared/rd-rend2/tr_ghoul2.cpp`, `shared/rd-rend2/tr_local.h`, `shared/rd-rend2/tr_surface.cpp` | `medium` |
| `2025-08-08` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`cc93ec8c4139`](https://github.com/taysta/TaystJK/commit/cc93ec8c413928bdfb94db470566c1ec44d88903) · [PR #251](https://github.com/taysta/TaystJK/pull/251)<br>Merge pull request #251 from taysta/vk-update | Changed an exact bound cvar-variable reference. `codemp/rd-vulkan/tr_ghoul2.cpp`, `codemp/rd-vulkan/tr_surface.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1635](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-rend2/tr_init.cpp#L1635) (Cvar_Get)
- behavior: [codemp/rd-vulkan/tr_ghoul2.cpp:3703](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_ghoul2.cpp#L3703)
- behavior: [codemp/rd-vulkan/tr_ghoul2.cpp:3707](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_ghoul2.cpp#L3707)
- behavior: [codemp/rd-vulkan/tr_surface.cpp:2276](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_surface.cpp#L2276)
- behavior: [codemp/rd-vulkan/tr_surface.cpp:2280](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/rd-vulkan/tr_surface.cpp#L2280)
- behavior: [shared/rd-rend2/tr_ghoul2.cpp:3743](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/rd-rend2/tr_ghoul2.cpp#L3743)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
