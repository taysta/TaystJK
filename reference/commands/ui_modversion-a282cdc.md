---
title: "ui_modversion"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_modversion`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `UI_Modversion_f` in the ui module.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `ui_modversion` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`561b84ebefaf`](https://github.com/eternalcodes/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2016-02-05`, integrated `2016-02-05`)
- Upstream registration evidence: [codemp/ui/ui_atoms.c:319](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_atoms.c#L319)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2016-02-05` | — | `2016-02-05` | [`561b84ebefaf`](https://github.com/eternalcodes/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2016-02-05` | — | `2016-02-05` | [`561b84ebefaf`](https://github.com/taysta/TaystJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2016-02-05` | — | `2016-02-05` | [`561b84ebefaf`](https://github.com/videoP/jaPRO/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2016-02-05` | — | `2016-02-05` | [`561b84ebefaf`](https://github.com/JKSunny/EternalJK/commit/561b84ebefaf74a5ada68700a8c74b4c0ff2d419) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-04-19` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`1d5acfc05276`](https://github.com/eternalcodes/EternalJK/commit/1d5acfc05276cbb6032b5fd9ccd01a8d41233763)<br>Add /strafeHelper, /stylePlayer, and /speedometer commands to UI | Changed the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |
| `2024-01-04` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b4aae0d60465`](https://github.com/taysta/TaystJK/commit/b4aae0d604653021090c08f5a585c3959fcbdabe) · [PR #76](https://github.com/taysta/TaystJK/pull/76)<br>Merge pull request #76 from taysta/change | Changed the registered command handler. `codemp/ui/ui_atoms.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_atoms.c:110](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_atoms.c#L110) (ui command table)
- handler: [codemp/ui/ui_atoms.c:53](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_atoms.c#L53)
