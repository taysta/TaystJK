---
title: "chatlog"
layout: reference
nav_exclude: true
search_exclude: false
---

# `chatlog`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_ChatLogSettings_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Chat & social |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `chatlog [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`328d55f0062f`](https://github.com/eternalcodes/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-12-20`, integrated `2018-12-20`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2200](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2200)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-12-20` | — | `2018-12-20` | [`328d55f0062f`](https://github.com/eternalcodes/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-12-20` | — | `2018-12-20` | [`328d55f0062f`](https://github.com/taysta/TaystJK/commit/328d55f0062f745722046389d7b9744ec050d77f) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-12-20` | — | `2018-12-20` | [`328d55f0062f`](https://github.com/videoP/jaPRO/commit/328d55f0062f745722046389d7b9744ec050d77f) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-12-20` | — | `2018-12-20` | [`328d55f0062f`](https://github.com/JKSunny/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2521](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2521) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:1923](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1923)
