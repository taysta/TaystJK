---
title: "ui_tribesMode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_tribesMode`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

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
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame.menu:72](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L72), [ingame.menu:86](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L86), [ingame.menu:898](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame.menu#L898) |
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

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`baa02905f40f`](https://github.com/videoP/jaPRO/commit/baa02905f40f33652a2ae326fe55ece2642169c1) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-02-03`, integrated `2024-02-27`)
- Origin pull request: [#130](https://github.com/taysta/TaystJK/pull/130)
- Upstream registration evidence: [codemp/ui/ui_main.c:630](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/ui/ui_main.c#L630)
- Attribution method: `introduction-commit-explicit-credit`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-03` | [2024-02-03](https://github.com/taysta/TaystJK/pull/130) | `2024-02-27` | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-03` | — | `2024-02-27` | [`baa02905f40f`](https://github.com/videoP/jaPRO/commit/baa02905f40f33652a2ae326fe55ece2642169c1) | Ultimate origin |

## Evidence

- registration: [codemp/ui/ui_main.c:630](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L630) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:659](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L659) (implicit Cvar_Set)
