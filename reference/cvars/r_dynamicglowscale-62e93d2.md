---
title: "r_DynamicGlowScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_DynamicGlowScale`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_DynamicGlowScale` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-vanilla`, `rd-vulkan` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0.25` |
| Value type | `float` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0.25` | `renderer` | `rd-vanilla` | `always` |
| `0.25` | `renderer` | `rd-vulkan` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`f768a9d0b3b1`](https://github.com/eternalcodes/EternalJK/commit/f768a9d0b3b10086974b9c9a01b620549d13915e) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-03-29`, integrated `2018-03-29`)
- Upstream registration evidence: [codemp/rd-vanilla/tr_init.cpp:1622](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/rd-vanilla/tr_init.cpp#L1622)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-03-29` | — | `2018-03-29` | [`f768a9d0b3b1`](https://github.com/eternalcodes/EternalJK/commit/f768a9d0b3b10086974b9c9a01b620549d13915e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-03-29` | — | `2018-03-29` | [`f768a9d0b3b1`](https://github.com/taysta/TaystJK/commit/f768a9d0b3b10086974b9c9a01b620549d13915e) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-03-29` | — | `2018-03-29` | [`f768a9d0b3b1`](https://github.com/videoP/jaPRO/commit/f768a9d0b3b10086974b9c9a01b620549d13915e) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-03-29` | — | `2018-03-29` | [`f768a9d0b3b1`](https://github.com/JKSunny/EternalJK/commit/f768a9d0b3b10086974b9c9a01b620549d13915e) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vanilla/tr_init.cpp` | `high` |
| `2021-05-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d7d7ce3234e6`](https://github.com/taysta/TaystJK/commit/d7d7ce3234e6748d782d4579b58d2a108d1b42f1)<br>Added vanilla clone for code compare | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-vulkan/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-vanilla/tr_init.cpp:1650](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_init.cpp#L1650) (Cvar_Get)
- registration: [codemp/rd-vulkan/tr_init.cpp:802](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vulkan/tr_init.cpp#L802) (Cvar_Get)
- behavior: [codemp/rd-vanilla/tr_image.cpp:1548](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_image.cpp#L1548)
- behavior: [codemp/rd-vanilla/tr_image.cpp:1549](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-vanilla/tr_image.cpp#L1549)
