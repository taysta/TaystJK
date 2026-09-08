---
title: "r_parallaxMapping"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_parallaxMapping`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Disable/enable parallax mapping

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
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [shared/rd-rend2/tr_shade.cpp:1380](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1380) |
| `1` | Enabled. | [shared/rd-rend2/tr_shade.cpp:1380](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1380) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) on `2023-10-03` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919)
- Pull request: [#12](https://github.com/taysta/TaystJK/pull/12)
- Upstream registration evidence: [codemp/rd-rend2/tr_init.cpp:1497](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-rend2/tr_init.cpp#L1497)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2; fork-lineage order selects openjk. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-10-03` | [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-10-03` | [`be28b4edd6c7`](https://github.com/SomaZ/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-03` | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-03` | [`86c0756385ef`](https://github.com/videoP/jaPRO/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) | Later project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-10-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`86c0756385ef`](https://github.com/taysta/TaystJK/commit/86c0756385efd1e0c24b5c435739ccba3bee3919) · [PR #12](https://github.com/taysta/TaystJK/pull/12)<br>Rend2 (#12) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |
| `2025-07-05` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`80ee9361579f`](https://github.com/taysta/TaystJK/commit/80ee9361579f32063f0399d631f532d9e0b255d4) · [PR #249](https://github.com/taysta/TaystJK/pull/249)<br>Merge pull request #249 from taysta/rend2-update | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-rend2/tr_init.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-rend2/tr_init.cpp:1629](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-rend2/tr_init.cpp#L1629) (Cvar_Get)
- behavior: [shared/rd-rend2/tr_shade.cpp:1380](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1380)
- behavior: [shared/rd-rend2/tr_shade.cpp:1422](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1422)
- behavior: [shared/rd-rend2/tr_shade.cpp:1475](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1475)
- behavior: [shared/rd-rend2/tr_shade.cpp:1897](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_shade.cpp#L1897)
- behavior: [codemp/ui/ui_main.c:6250](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_main.c#L6250)
