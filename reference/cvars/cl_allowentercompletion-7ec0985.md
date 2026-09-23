---
title: "cl_allowEnterCompletion"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cl_allowEnterCompletion`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Enables autocomplete when pressing enter

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
| Added | 2016-08-04 in [`d23425fac`](https://github.com/taysta/TaystJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_keys.cpp#L858) |
| `1` | Enabled. | [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_keys.cpp#L858) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`d23425fac341`](https://github.com/eternalcodes/EternalJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-08-04`, integrated `2016-08-04`)
- Upstream registration evidence: [codemp/client/cl_main.cpp:3275](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/client/cl_main.cpp#L3275)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-08-04` | — | `2016-08-04` | [`d23425fac341`](https://github.com/eternalcodes/EternalJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-08-04` | — | `2016-08-04` | [`d23425fac341`](https://github.com/taysta/TaystJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-08-04` | — | `2016-08-04` | [`d23425fac341`](https://github.com/videoP/jaPRO/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-08-04` | — | `2016-08-04` | [`d23425fac341`](https://github.com/JKSunny/EternalJK/commit/d23425fac341e069713ca2e49b6eeb87eceeb312) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2016-08-04` | — | `2017-03-09` | [`acb5bdd2c483`](https://github.com/jkanewmod/NewJK/commit/acb5bdd2c483c02cf23e98d7d2703645b2b4edff) | Other project appearance |

## Evidence

- registration: [codemp/client/cl_main.cpp:3366](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_main.cpp#L3366) (Cvar_Get)
- behavior: [codemp/client/cl_keys.cpp:858](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/client/cl_keys.cpp#L858)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
