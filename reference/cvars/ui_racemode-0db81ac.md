---
title: "ui_raceMode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_raceMode`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

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
| In-game menu | Yes — [ingame.menu:151](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L151), [ingame.menu:184](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L184), [ingame.menu:805](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L805) |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

No cvar flags are registered at the cited site.

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `ui` | `—` | `always` |
| `1` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-09-10`, integrated `2018-09-10`)
- Upstream registration evidence: [codemp/ui/ui_main.c:626](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_main.c#L626)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-09-10` | — | `2018-09-10` | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-09-10` | — | `2018-09-10` | [`dbfd735d1da2`](https://github.com/taysta/TaystJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-09-10` | — | `2018-09-10` | [`dbfd735d1da2`](https://github.com/videoP/jaPRO/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-09-10` | — | `2018-09-10` | [`dbfd735d1da2`](https://github.com/JKSunny/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) | Shared integration commit |

## Evidence

- registration: [codemp/ui/ui_main.c:629](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L629) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:656](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L656) (implicit Cvar_Set)
