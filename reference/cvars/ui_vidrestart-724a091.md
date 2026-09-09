---
title: "ui_vidrestart"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_vidrestart`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_vidrestart` in the ui module. Consult the cited behavior reads before relying on values not listed here.

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
| In-game menu | Yes — [ingame_setup.menu:882](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L882), [ingame_setup.menu:916](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L916), [ingame_setup.menu:953](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L953) |
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

- Ultimate-origin introduction: [`d93386f34b71`](https://github.com/eternalcodes/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2015-06-17`, integrated `2015-06-17`)
- Upstream registration evidence: [codemp/ui/ui_main.c:6283](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_main.c#L6283)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/eternalcodes/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/taysta/TaystJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/videoP/jaPRO/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2015-06-17` | — | `2015-06-17` | [`d93386f34b71`](https://github.com/JKSunny/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2023-10-14` | <span class="label ref-origin ref-origin-rend2">rend2</span> | [`aa48e28a7d4f`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) · [PR #26](https://github.com/taysta/TaystJK/pull/26)<br>Merge pull request #26 from taysta/rend2menu | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/ui/ui_main.c` | `medium` |

## Evidence

- registration: [codemp/ui/ui_main.c:6382](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6382) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:6256](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6256)
- behavior: [codemp/ui/ui_main.c:6258](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6258)
- behavior: [codemp/ui/ui_main.c:6426](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6426)
