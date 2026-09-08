---
title: "cl_coloredTextShadows"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_coloredTextShadows`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Toggle JK2 1.02-style colored text shadows

## At a glance

| Field | Value |
|:--|:--|
| Module | `renderer` |
| Also registered in | `renderer` |
| Renderer | All / not renderer-specific |
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
| `0` | Disabled. | [codemp/rd-common/tr_font.cpp:1625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1625) |
| `1` | Enabled. | [codemp/rd-common/tr_font.cpp:1625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1625) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`82c74a03d641`](https://github.com/eternalcodes/EternalJK/commit/82c74a03d641380e7724758570852e848c97231e) on `2017-12-04` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/rd-common/tr_font.cpp:1740](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/rd-common/tr_font.cpp#L1740)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-12-04` | [`82c74a03d641`](https://github.com/eternalcodes/EternalJK/commit/82c74a03d641380e7724758570852e848c97231e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-12-04` | [`82c74a03d641`](https://github.com/taysta/TaystJK/commit/82c74a03d641380e7724758570852e848c97231e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-12-04` | [`82c74a03d641`](https://github.com/videoP/jaPRO/commit/82c74a03d641380e7724758570852e848c97231e) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-12-04` | [`82c74a03d641`](https://github.com/JKSunny/EternalJK/commit/82c74a03d641380e7724758570852e848c97231e) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-11-30` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`b02278460a3d`](https://github.com/eternalcodes/EternalJK/commit/b02278460a3dad1b378a0b24994958c621172848)<br>Register cl_coloredTextShadows in R_InitFonts | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/rd-common/tr_font.cpp` | `medium` |

## Evidence

- registration: [codemp/rd-common/tr_font.cpp:1844](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1844) (Cvar_Get)
- behavior: [codemp/rd-common/tr_font.cpp:1625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/rd-common/tr_font.cpp#L1625)
