---
title: "ui_r_tonemap"
layout: reference
nav_exclude: true
search_exclude: false
---

# `ui_r_tonemap`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `ui_r_tonemap` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_setup.menu:1753](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L1753), [setup.menu:1543](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/setup.menu#L1543) |
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

Origin: <span class="label ref-origin ref-origin-rend2">rend2</span>

- TaystJK integration evidence: [`aa48e28a7d4f`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75)
- Origin pull request: [#26](https://github.com/taysta/TaystJK/pull/26)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits rend2.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-14` | [2023-10-14](https://github.com/taysta/TaystJK/pull/26) | `2023-10-14` | [`aa48e28a7d4f`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-14` | — | `2023-10-14` | [`aa48e28a7d4f`](https://github.com/videoP/jaPRO/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) | Other project appearance |

## Evidence

- registration: [codemp/ui/ui_main.c:6372](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6372) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:6244](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6244)
- behavior: [codemp/ui/ui_main.c:6415](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6415)
