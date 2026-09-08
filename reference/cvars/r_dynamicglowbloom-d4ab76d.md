---
title: "r_dynamicGlowBloom"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_dynamicGlowBloom`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls the rend2 dynamic-glow bloom strength. Zero skips the bloom pass; positive values up to the enforced maximum of 2 are passed to the high-pass shader as bloom strength.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0.0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disable the dynamic-glow bloom pass. | [shared/rd-rend2/tr_backend.cpp:3131](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3131) |
| `>0` | Use this positive value, up to 2, as the shader's bloom strength. | [shared/rd-rend2/tr_backend.cpp:3140](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3140) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`cd5d0ede0fd3`](https://github.com/SomaZ/OpenJK/commit/cd5d0ede0fd3db612a6c4f37f8fb91baefca69fd) on `2025-01-05` in <span class="label ref-origin ref-origin-rend2">rend2</span>
- TaystJK integration evidence: [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad)
- Pull request: [#217](https://github.com/taysta/TaystJK/pull/217)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1480](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1480)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2025-01-05` | [`cd5d0ede0fd3`](https://github.com/SomaZ/OpenJK/commit/cd5d0ede0fd3db612a6c4f37f8fb91baefca69fd) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2025-04-15` | [`c98ecf977bd3`](https://github.com/taysta/TaystJK/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2025-04-15` | [`c98ecf977bd3`](https://github.com/videoP/jaPRO/commit/c98ecf977bd3b652b1a7974cd21ee1f80a1b7aad) | Later project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1514](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1514) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_backend.cpp:3131](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3131)
- behavior: [shared/rd-rend2/tr_backend.cpp:3140](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_backend.cpp#L3140)
- behavior: [codemp/rd-rend2/tr_init.cpp:1515](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1515)
