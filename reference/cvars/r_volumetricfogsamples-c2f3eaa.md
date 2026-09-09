---
title: "r_volumetricFogSamples"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_volumetricFogSamples`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

How many ray samples to take

## At a glance

| Field | Value |
|:--|:--|
| Category | Audio & music |
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `48` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`3c0bc65b40ea`](https://github.com/SomaZ/OpenJK/commit/3c0bc65b40ea5e08b9b056560f34c9e991dc522e) in <span class="label ref-origin ref-origin-rend2">rend2</span> (content authored `2025-02-21`, integrated `2025-02-25`)
- TaystJK integration evidence: [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad)
- Origin pull request: [#217](https://github.com/taysta/TaystJK/pull/217)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1550](https://github.com/SomaZ/OpenJK/blame/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1550)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2025-02-21` | — | `2025-02-25` | [`3c0bc65b40ea`](https://github.com/SomaZ/OpenJK/commit/3c0bc65b40ea5e08b9b056560f34c9e991dc522e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-15` | [2025-04-07](https://github.com/taysta/TaystJK/pull/217) | `2025-04-15` | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-15` | — | `2025-04-15` | [`c98ecf977bd3`](https://github.com/videoP/jaPRO/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | — | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Other project appearance |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1585](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1585) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_glsl.cpp:383](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/rd-rend2/tr_glsl.cpp#L383)
- behavior: [codemp/rd-rend2/tr_init.cpp:1586](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/rd-rend2/tr_init.cpp#L1586)
