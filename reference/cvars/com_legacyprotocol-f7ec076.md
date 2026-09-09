---
title: "com_legacyprotocol"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_legacyprotocol`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

1.00 protocol

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Default | `va("%i", PROTOCOL_LEGACY)` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`6107f5fbcf59`](https://github.com/eternalcodes/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-04-26`, integrated `2018-04-26`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3250](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3250)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/eternalcodes/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/taysta/TaystJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/videoP/jaPRO/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-26` | — | `2018-04-26` | [`6107f5fbcf59`](https://github.com/JKSunny/EternalJK/commit/6107f5fbcf594706f4d729052bda36e9cb208847) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2018-04-26` | — | `2020-04-02` | [`007750b49b3b`](https://github.com/jkanewmod/NewJK/commit/007750b49b3bfff586199e126ebdc4d90ba515d1) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3339](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_main.cpp#L3339) (Cvar_Get)
- behavior: [codemp/ui/ui_main.c:12393](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L12393)
- behavior: [codemp/ui/ui_main.c:12391](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L12391)
- behavior: [codemp/ui/ui_main.c:5587](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5587)
