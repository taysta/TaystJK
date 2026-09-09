---
title: "cvar_usercreated"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cvar_usercreated`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Show all user created cvars

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `cvar_usercreated` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`28c72736b22b`](https://github.com/JACoders/OpenJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2017-07-30`, integrated `2017-07-30`)
- TaystJK integration evidence: [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)
- Upstream registration evidence: [code/qcommon/cvar.cpp:1387](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/code/qcommon/cvar.cpp#L1387)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The identifier's single-prefix squash feature group explicitly credits openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2017-07-30` | — | `2017-07-30` | [`28c72736b22b`](https://github.com/JACoders/OpenJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2017-07-30` | — | `2017-07-30` | [`28c72736b22b`](https://github.com/SomaZ/OpenJK/commit/28c72736b22bc2858ad2063828a0a3b616c0ac42) | Shared integration commit |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2017-07-30` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/eternalcodes/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2017-07-30` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2017-07-30` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/videoP/jaPRO/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2017-07-30` | — | `2017-08-31` | [`913e3cc57ec7`](https://github.com/JKSunny/EternalJK/commit/913e3cc57ec761400db576456e91d71e70a2485f) | Other project appearance |

## Evidence

- registration: [codemp/qcommon/cvar.cpp:1643](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1643) (Cmd_AddCommand)
- handler: [codemp/qcommon/cvar.cpp:1285](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/cvar.cpp#L1285)
