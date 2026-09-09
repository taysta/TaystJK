---
title: "ui_disableWeaponSway"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_disableWeaponSway`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Registered by the current source, but no user-facing behavior description has been verified. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_setup.menu:5095](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L5095), [ingame_setup.menu:5101](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L5101), [ingame_setup.menu:5132](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L5132) |
| Default | `1` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_INTERNAL` — internal UI/engine state

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`60132754c617`](https://github.com/eternalcodes/EternalJK/commit/60132754c61719a97f300fa62cc77e55061f4c1e) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2018-01-12`, integrated `2018-01-12`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:81](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L81)
- Attribution method: `introduction-commit-developer-lineage-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-01-12` | — | `2018-01-12` | [`60132754c617`](https://github.com/eternalcodes/EternalJK/commit/60132754c61719a97f300fa62cc77e55061f4c1e) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-01-12` | — | `2018-01-12` | [`60132754c617`](https://github.com/taysta/TaystJK/commit/60132754c61719a97f300fa62cc77e55061f4c1e) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-01-12` | — | `2018-01-12` | [`60132754c617`](https://github.com/videoP/jaPRO/commit/60132754c61719a97f300fa62cc77e55061f4c1e) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-01-12` | — | `2018-01-12` | [`60132754c617`](https://github.com/JKSunny/EternalJK/commit/60132754c61719a97f300fa62cc77e55061f4c1e) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_xcvar.h` | `medium` |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:83](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L83) (XCVAR_DEF)
