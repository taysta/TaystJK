---
title: "r_refractionChromaticAberration"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_refractionChromaticAberration`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_refractionChromaticAberration` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0.05` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- Ultimate-origin introduction: [`c062d953fb4c`](https://github.com/SomaZ/OpenJK/commit/c062d953fb4cd205437abcae5d792445c979e7f9) on `2026-07-17` in <span class="label ref-origin ref-origin-rend2">rend2</span>
- TaystJK integration evidence: [`aac7dcccc4e7`](https://github.com/taysta/TaystJK/commit/aac7dcccc4e72797666b42058e5d58a6805c1462)
- Pull request: [#350](https://github.com/taysta/TaystJK/pull/350)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1561](https://github.com/SomaZ/OpenJK/blob/788c19e97f02c0b68db29d63060305b6ad1580e5/codemp/rd-rend2/tr_init.cpp#L1561)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2026-07-17` | [`c062d953fb4c`](https://github.com/SomaZ/OpenJK/commit/c062d953fb4cd205437abcae5d792445c979e7f9) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-07-30` | [`aac7dcccc4e7`](https://github.com/taysta/TaystJK/commit/aac7dcccc4e72797666b42058e5d58a6805c1462) | Later project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1596](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1596) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_shade.cpp:1882](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1882)
- behavior: [codemp/rd-rend2/tr_init.cpp:1597](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1597)
