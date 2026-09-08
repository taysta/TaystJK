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
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Syntax | `chatlog [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`328d55f0062f`](https://github.com/eternalcodes/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f) on `2018-12-20` in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>
- Upstream registration evidence: [codemp/cgame/cg_consolecmds.c:2200](https://github.com/eternalcodes/EternalJK/blob/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_consolecmds.c#L2200)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-12-20` | [`328d55f0062f`](https://github.com/eternalcodes/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-12-20` | [`328d55f0062f`](https://github.com/taysta/TaystJK/commit/328d55f0062f745722046389d7b9744ec050d77f) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-12-20` | [`328d55f0062f`](https://github.com/videoP/jaPRO/commit/328d55f0062f745722046389d7b9744ec050d77f) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-12-20` | [`328d55f0062f`](https://github.com/JKSunny/EternalJK/commit/328d55f0062f745722046389d7b9744ec050d77f) | Shared earliest lineage |

## Evidence

- registration: [codemp/cgame/cg_consolecmds.c:2521](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L2521) (cgame command table)
- handler: [codemp/cgame/cg_consolecmds.c:1923](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1923)
