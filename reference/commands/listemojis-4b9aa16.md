---
title: "listEmojis"
layout: reference
nav_exclude: true
search_exclude: false
---

# `listEmojis`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_ListEmojis_f` in the cgame module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `listEmojis` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`0d34eb5a1d2c`](https://github.com/eternalcodes/EternalJK/commit/0d34eb5a1d2c230d28760132665486a0d46085be) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2021-02-11`, integrated `2021-02-11`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2218](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2218)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2021-02-11` | — | `2021-02-11` | [`0d34eb5a1d2c`](https://github.com/eternalcodes/EternalJK/commit/0d34eb5a1d2c230d28760132665486a0d46085be) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2021-02-11` | — | `2021-02-11` | [`0d34eb5a1d2c`](https://github.com/taysta/TaystJK/commit/0d34eb5a1d2c230d28760132665486a0d46085be) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2021-02-11` | — | `2021-02-11` | [`0d34eb5a1d2c`](https://github.com/videoP/jaPRO/commit/0d34eb5a1d2c230d28760132665486a0d46085be) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2021-02-11` | — | `2021-02-11` | [`0d34eb5a1d2c`](https://github.com/JKSunny/EternalJK/commit/0d34eb5a1d2c230d28760132665486a0d46085be) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2538](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2538) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:693](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L693)
