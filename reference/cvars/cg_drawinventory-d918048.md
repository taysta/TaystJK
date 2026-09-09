---
title: "cg_drawInventory"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawInventory`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_drawInventory` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_draw.c:6862](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6862) |
| `1` | Enabled. | [codemp/cgame/cg_draw.c:6862](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6862) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`1b560444bb13`](https://github.com/eternalcodes/EternalJK/commit/1b560444bb137d03a94ab490d29778f2ad785b6b) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-09-26`, integrated `2018-09-26`)
- Upstream registration evidence: [codemp/cgame/cg_xcvar.h:135](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/cgame/cg_xcvar.h#L135)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-26` | — | `2018-09-26` | [`1b560444bb13`](https://github.com/eternalcodes/EternalJK/commit/1b560444bb137d03a94ab490d29778f2ad785b6b) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-26` | — | `2018-09-26` | [`1b560444bb13`](https://github.com/taysta/TaystJK/commit/1b560444bb137d03a94ab490d29778f2ad785b6b) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-26` | — | `2018-09-26` | [`1b560444bb13`](https://github.com/videoP/jaPRO/commit/1b560444bb137d03a94ab490d29778f2ad785b6b) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-26` | — | `2018-09-26` | [`1b560444bb13`](https://github.com/JKSunny/EternalJK/commit/1b560444bb137d03a94ab490d29778f2ad785b6b) | Shared integration commit |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:163](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L163) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:6862](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6862)
- behavior: [codemp/cgame/cg_draw.c:6851](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6851)
- behavior: [codemp/cgame/cg_draw.c:6856](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6856)
- behavior: [codemp/cgame/cg_draw.c:6960](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L6960)
