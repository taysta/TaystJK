---
title: "unset_usercreated"
layout: reference
nav_exclude: true
search_exclude: false
---

# `unset_usercreated`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Unset all user generated cvars Use with caution!

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Syntax | `unset_usercreated` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`28c72736b22b`](https://github.com/JACoders/OpenJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42) on `2017-07-30` in <span class="label ref-origin ref-origin-openjk">OpenJK</span>
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [code/qcommon/cvar.cpp:1385](https://github.com/JACoders/OpenJK/blob/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cvar.cpp#L1385)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by openjk, rend2; fork-lineage order selects openjk. The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2017-07-30` | [`28c72736b22b`](https://github.com/JACoders/OpenJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2017-07-30` | [`28c72736b22b`](https://github.com/SomaZ/OpenJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/eternalcodes/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/videoP/jaPRO/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-08-31` | [`913e3cc57ec7`](https://github.com/JKSunny/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Later project appearance |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1641](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1641) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1384](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/cvar.cpp#L1384)
