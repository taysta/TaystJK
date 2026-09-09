---
title: "r_cleardecals"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_cleardecals`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `RE_ClearDecals` in the renderer module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2`, `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `r_cleardecals` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`58c7d66abda5`](https://github.com/eternalcodes/EternalJK/commit/58c7d66abda5e2c2915dc5322e3509029aa2bbb9) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-11-30`, integrated `2018-11-30`)
- Upstream registration evidence: [codemp/rd-vanilla/tr_init.cpp:1578](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/rd-vanilla/tr_init.cpp#L1578)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-11-30` | — | `2018-11-30` | [`58c7d66abda5`](https://github.com/eternalcodes/EternalJK/commit/58c7d66abda5e2c2915dc5322e3509029aa2bbb9) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-11-30` | — | `2018-11-30` | [`58c7d66abda5`](https://github.com/taysta/TaystJK/commit/58c7d66abda5e2c2915dc5322e3509029aa2bbb9) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-11-30` | — | `2018-11-30` | [`58c7d66abda5`](https://github.com/videoP/jaPRO/commit/58c7d66abda5e2c2915dc5322e3509029aa2bbb9) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-11-30` | — | `2018-11-30` | [`58c7d66abda5`](https://github.com/JKSunny/EternalJK/commit/58c7d66abda5e2c2915dc5322e3509029aa2bbb9) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-vulkan/tr_decals.cpp`, `codemp/rd-vulkan/tr_init.cpp`, `codemp/rd-vulkan/tr_local.h` | `medium` |
| `2021-05-25` | <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | [`c4a9c87ef0e3`](https://github.com/JKSunny/EternalJK/commit/c4a9c87ef0e3171c80fd8c4e24df94e0fa1bcbe4)<br>Added vulkan renderer | Changed the registered command handler. `codemp/rd-vulkan/tr_local.h` | `high` |
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) · [PR #110](https://github.com/taysta/TaystJK/pull/110)<br>Rend2 updates (#110) | Changed the registered command handler. `shared/rd-rend2/tr_decals.cpp`, `shared/rd-rend2/tr_local.h` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1465](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1465) (renderer command table)
- registration: [codemp/rd-vanilla/tr_init.cpp:1604](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1604) (renderer command table)
- registration: [codemp/rd-vulkan/tr_init.cpp:755](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L755) (renderer command table)
- handler: [codemp/rd-vanilla/tr_decals.cpp:62](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_decals.cpp#L62)
