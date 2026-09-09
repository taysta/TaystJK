---
title: "cosmetics"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cosmetics`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `CG_Cosmetics_f` in the cgame module.

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
| Syntax | `cosmetics` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-10-15`, integrated `2018-10-15`)
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2199](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2199)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-10-15` | — | `2018-10-15` | [`1e4377ef412f`](https://github.com/eternalcodes/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-10-15` | — | `2018-10-15` | [`1e4377ef412f`](https://github.com/taysta/TaystJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-10-15` | — | `2018-10-15` | [`1e4377ef412f`](https://github.com/videoP/jaPRO/commit/1e4377ef412feb0bdce70884035cb5b62f640293) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-10-15` | — | `2018-10-15` | [`1e4377ef412f`](https://github.com/JKSunny/EternalJK/commit/1e4377ef412feb0bdce70884035cb5b62f640293) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-10-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0b331bc16c5e`](https://github.com/eternalcodes/EternalJK/commit/0b331bc16c5ecbdb42571251f9ae6919918df506)<br>cringe cosmetic | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-11-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`81b34abb5846`](https://github.com/eternalcodes/EternalJK/commit/81b34abb584619349e45ee435e977f1457b5837b)<br>Register saberFlash shader and cosmetic models on startup | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-12-12` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc180aa113b3`](https://github.com/eternalcodes/EternalJK/commit/dc180aa113b3b4c7f07c2a6cbc39f3ad200b0772)<br>increase dropshadow distance to 512+misc fixes | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-12-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`328d55f0062f`](https://github.com/eternalcodes/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f)<br>Chatlog options configurable with /chatlog | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2020-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c4b88abcfd76`](https://github.com/eternalcodes/EternalJK/commit/c4b88abcfd7678f9186ebec0c20ac98dc986d6b5)<br>cosmetic unlock integration? (loda) | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_servercmds.c` | `medium` |
| `2022-04-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1dd571383a0d`](https://github.com/taysta/TaystJK/commit/1dd571383a0d16520e69ce209f8a2d21b2943a62)<br>Merge remote-tracking branch 'origin/master' | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-09-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d0baa5bc31c9`](https://github.com/taysta/TaystJK/commit/d0baa5bc31c9dda8c055f33455c6224049779f0f)<br>Updated cosmetics and voice chat memes | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2023-09-29` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`2bb6b055c60c`](https://github.com/taysta/TaystJK/commit/2bb6b055c60cf4e239c75ff83d71bb9f5e957949) · [PR #11](https://github.com/taysta/TaystJK/pull/11)<br>Merge pull request #11 from taysta/global-cosmetics | Changed the registered command handler. `codemp/cgame/cg_consolecmds.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2520](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L2520) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:1902](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L1902)
