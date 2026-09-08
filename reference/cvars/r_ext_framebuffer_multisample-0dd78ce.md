---
title: "r_ext_framebuffer_multisample"
layout: reference
nav_exclude: true
search_exclude: false
---

# `r_ext_framebuffer_multisample`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `r_ext_framebuffer_multisample` in the renderer module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | `rd-rend2` |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `(float` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) on `2023-10-03` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69)
- Pull request: [#110](https://github.com/taysta/TaystJK/pull/110)
- Upstream registration evidence: [codemp/rd-rend2/tr_fbo.cpp:416](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/rd-rend2/tr_fbo.cpp#L416)
- Attribution method: `earliest-dated-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-10-03` | [`be28b4edd6c7`](https://github.com/JACoders/OpenJK/commit/be28b4edd6c7a97ff6484518099dfa72f13b783e) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-12-12` | [`3b7df7a57401`](https://github.com/SomaZ/OpenJK/commit/3b7df7a57401c0dee174f71f51514bbb7158f2c7) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-03` | [`0c789787f79c`](https://github.com/taysta/TaystJK/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-03` | [`0c789787f79c`](https://github.com/videoP/jaPRO/commit/0c789787f79c23c977ebb59cc96a6d4d97815f69) | Later project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2026-08-09` | [`686cbf9b649b`](https://github.com/jkanewmod/NewJK/commit/686cbf9b649bccf8d1a88df3b0ff72b0fc9ad177) | Later project appearance |

## Evidence

- registration: [shared/rd-rend2/tr_fbo.cpp:422](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L422) (implicit Cvar_SetValue)
- behavior: [shared/rd-rend2/tr_fbo.cpp:412](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L412)
- behavior: [shared/rd-rend2/tr_fbo.cpp:420](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L420)
- behavior: [shared/rd-rend2/tr_fbo.cpp:414](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/rd-rend2/tr_fbo.cpp#L414)
