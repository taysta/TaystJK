---
title: "write"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `write`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Write the configuration to file

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `medium` |
| Added | 2019-03-21 in [`4ff81d3be`](https://github.com/taysta/TaystJK/commit/4ff81d3bece4378fe9c001e94ab890cb30229fcc) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `write <filename>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`4ff81d3bece4`](https://github.com/eternalcodes/EternalJK/commit/4ff81d3bece4378fe9c001e94ab890cb30229fcc) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-03-21`, integrated `2019-03-21`)
- Upstream registration evidence: [codemp/qcommon/common.cpp:1211](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/qcommon/common.cpp#L1211)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-03-21` | — | `2019-03-21` | [`4ff81d3bece4`](https://github.com/eternalcodes/EternalJK/commit/4ff81d3bece4378fe9c001e94ab890cb30229fcc) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-03-21` | — | `2019-03-21` | [`4ff81d3bece4`](https://github.com/taysta/TaystJK/commit/4ff81d3bece4378fe9c001e94ab890cb30229fcc) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-03-21` | — | `2019-03-21` | [`4ff81d3bece4`](https://github.com/videoP/jaPRO/commit/4ff81d3bece4378fe9c001e94ab890cb30229fcc) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-03-21` | — | `2019-03-21` | [`4ff81d3bece4`](https://github.com/JKSunny/EternalJK/commit/4ff81d3bece4378fe9c001e94ab890cb30229fcc) | Shared integration commit |

## Evidence

- registration: [codemp/qcommon/common.cpp:1423](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L1423) (Cmd_AddCommand)
- handler: [codemp/qcommon/common.cpp:1610](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L1610)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
