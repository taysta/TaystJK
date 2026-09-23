---
title: "cl_mouseAccelOffset"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_mouseAccelOffset`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Mouse acceleration offset for style 1

## At a glance

| Field | Value |
|:--|:--|
| Category | Input & controls |
| Module | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2014-05-15 in [`ae0f733b9`](https://github.com/taysta/TaystJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `5` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND`: saved to configuration without marking the cvar as user-created

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`ae0f733b9635`](https://github.com/JACoders/OpenJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2014-05-15`, integrated `2014-05-15`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:2783](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/client/cl_main.cpp#L2783)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/JACoders/OpenJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/eternalcodes/EternalJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/SomaZ/OpenJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/taysta/TaystJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/videoP/jaPRO/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/jkanewmod/NewJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-05-15` | — | `2014-05-15` | [`ae0f733b9635`](https://github.com/JKSunny/EternalJK/commit/ae0f733b9635c7e17c8fc644ea1133ffb399ae37) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_main.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_main.cpp:3360](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3360) (Cvar_Get)
- behavior: [codemp/client/cl_input.cpp:1142](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_input.cpp#L1142)
- behavior: [codemp/client/cl_input.cpp:1143](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_input.cpp#L1143)
- behavior: [codemp/client/cl_input.cpp:1151](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_input.cpp#L1151)
- behavior: [codemp/client/cl_input.cpp:1152](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_input.cpp#L1152)
- behavior: [codemp/client/cl_input.cpp:1156](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_input.cpp#L1156)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
