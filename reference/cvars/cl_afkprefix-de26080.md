---
title: "cl_afkPrefix"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_afkPrefix`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Prefix to add to player name when AFK

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2020-05-15 in [`8e7c210be`](https://github.com/taysta/TaystJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `[AFK]` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`8e7c210be049`](https://github.com/eternalcodes/EternalJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2020-04-13`, integrated `2020-05-15`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3352](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3352)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2020-04-13` | — | `2020-05-15` | [`8e7c210be049`](https://github.com/eternalcodes/EternalJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2020-04-13` | — | `2020-05-15` | [`8e7c210be049`](https://github.com/taysta/TaystJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2020-04-13` | — | `2020-05-15` | [`8e7c210be049`](https://github.com/videoP/jaPRO/commit/8e7c210be049001869783f27373c4b68a4bb02eb) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2020-04-13` | — | `2020-05-15` | [`8e7c210be049`](https://github.com/JKSunny/EternalJK/commit/8e7c210be049001869783f27373c4b68a4bb02eb) | Shared integration commit |

## Evidence

- registration: [codemp/client/cl_main.cpp:3453](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3453) (Cvar_Get)
- behavior: [codemp/client/cl_main.cpp:2370](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L2370)
- behavior: [codemp/client/cl_main.cpp:2369](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L2369)
- behavior: [codemp/client/cl_main.cpp:3005](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/client/cl_main.cpp#L3005)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
