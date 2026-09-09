---
title: "ui_r_customWidth"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_r_customWidth`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_r_customWidth` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_setup.menu:1141](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L1141) |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`e1abb59c8c45`](https://github.com/eternalcodes/EternalJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2015-06-21`, integrated `2015-06-21`)
- Upstream registration evidence: [codemp/ui/ui_main.c:6260](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_main.c#L6260)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-06-21` | — | `2015-06-21` | [`e1abb59c8c45`](https://github.com/eternalcodes/EternalJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-06-21` | — | `2015-06-21` | [`e1abb59c8c45`](https://github.com/taysta/TaystJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-06-21` | — | `2015-06-21` | [`e1abb59c8c45`](https://github.com/videoP/jaPRO/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-06-21` | — | `2015-06-21` | [`e1abb59c8c45`](https://github.com/JKSunny/EternalJK/commit/e1abb59c8c45e777bf89023b8215b23e7cc7adb3) | Shared integration commit |

## Evidence

- registration: [codemp/ui/ui_main.c:6345](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6345) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:5969](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5969)
- behavior: [codemp/ui/ui_main.c:5974](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5974)
- behavior: [codemp/ui/ui_main.c:5979](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5979)
- behavior: [codemp/ui/ui_main.c:5987](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5987)
- behavior: [codemp/ui/ui_main.c:5992](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L5992)
