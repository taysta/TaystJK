---
title: "remapSky"
layout: reference
nav_exclude: true
search_exclude: false
---

# `remapSky`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `R_RemapSkyShader_f` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `remapSky <new>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`9e7eaec5c4cf`](https://github.com/eternalcodes/EternalJK/commit/9e7eaec5c4cf17d9edf4c1d9e3fea57e49fb7658) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-03-21`, integrated `2019-03-21`)
- Upstream registration evidence: [codemp/rd-vanilla/tr_init.cpp:1579](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/rd-vanilla/tr_init.cpp#L1579)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-21` | — | `2019-03-21` | [`9e7eaec5c4cf`](https://github.com/eternalcodes/EternalJK/commit/9e7eaec5c4cf17d9edf4c1d9e3fea57e49fb7658) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-21` | — | `2019-03-21` | [`9e7eaec5c4cf`](https://github.com/taysta/TaystJK/commit/9e7eaec5c4cf17d9edf4c1d9e3fea57e49fb7658) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-21` | — | `2019-03-21` | [`9e7eaec5c4cf`](https://github.com/videoP/jaPRO/commit/9e7eaec5c4cf17d9edf4c1d9e3fea57e49fb7658) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-21` | — | `2019-03-21` | [`9e7eaec5c4cf`](https://github.com/JKSunny/EternalJK/commit/9e7eaec5c4cf17d9edf4c1d9e3fea57e49fb7658) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `high` |
| `2021-06-10` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9d252184aa3b`](https://github.com/taysta/TaystJK/commit/9d252184aa3bdc2ba7e83ee8606a6c343007c510)<br>Pointer asterisk repositioning and spacing for readability | Changed the registered command handler. `codemp/rd-vulkan/tr_init.cpp` | `medium` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1466](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1466) (renderer command table)
- registration: [codemp/rd-vanilla/tr_init.cpp:1605](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1605) (renderer command table)
- registration: [codemp/rd-vulkan/tr_init.cpp:756](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L756) (renderer command table)
- handler: [codemp/rd-rend2/tr_init.cpp:1421](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1421)
