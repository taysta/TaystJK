---
title: "r_volumetricFog"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_volumetricFog`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Disable/enable lightgrid lighting on fog volumes

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `bool` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/rd-rend2/tr_backend.cpp:1504](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L1504) |
| `1` | Enabled. | [shared/rd-rend2/tr_backend.cpp:1504](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L1504) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`3c0bc65b40ea`](https://github.com/SomaZ/OpenJK/commit/3c0bc65b40ea5e08b9b056560f34c9e991dc522e) on `2025-02-25` in <span class="label ref-origin ref-origin-rend2">rend2</span>
- TaystJK integration evidence: [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad)
- Pull request: [#217](https://github.com/taysta/TaystJK/pull/217)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1548](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1548)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2025-02-25` | [`3c0bc65b40ea`](https://github.com/SomaZ/OpenJK/commit/3c0bc65b40ea5e08b9b056560f34c9e991dc522e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-15` | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-15` | [`c98ecf977bd3`](https://github.com/videoP/jaPRO/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Later project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1583](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1583) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_backend.cpp:1504](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L1504)
- behavior: [shared/rd-rend2/tr_backend.cpp:2443](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L2443)
- behavior: [shared/rd-rend2/tr_bsp.cpp:4200](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_bsp.cpp#L4200)
- behavior: [shared/rd-rend2/tr_bsp.cpp:4391](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_bsp.cpp#L4391)
- behavior: [shared/rd-rend2/tr_glsl.cpp:382](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_glsl.cpp#L382)
