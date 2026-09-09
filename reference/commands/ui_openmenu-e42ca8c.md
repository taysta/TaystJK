---
title: "ui_openmenu"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_openmenu`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `UI_OpenMenu_f` in the ui module.

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
| Syntax | `ui_openmenu` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`f5c1b2ceb3ba`](https://github.com/JACoders/OpenJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-04`, integrated `2013-12-08`)
- Upstream registration evidence: [codemp/ui/ui_atoms.c:89](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/ui/ui_atoms.c#L89)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/JACoders/OpenJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/eternalcodes/EternalJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/SomaZ/OpenJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/taysta/TaystJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/videoP/jaPRO/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/jkanewmod/NewJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-04` | — | `2013-12-08` | [`f5c1b2ceb3ba`](https://github.com/JKSunny/EternalJK/commit/f5c1b2ceb3ba6fea65c0c5d64488adb12d4bafd1) | Shared integration commit |

## Evidence

- registration: [codemp/ui/ui_atoms.c:111](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_atoms.c#L111) (ui command table)
- handler: [codemp/ui/ui_atoms.c:84](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_atoms.c#L84)
