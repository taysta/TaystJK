---
title: "ui_cl_renderer"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_cl_renderer`

<span class="label ref-origin ref-origin-rend2">rend2</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>); it is internal UI/engine state, hidden from every cvar listing (<code>CVAR_INTERNAL</code>); it is the menu's staging copy of <a href="/TaystJK/reference/cvars/cl_renderer-dc9f64f/"><code>cl_renderer</code></a>, which the menu writes through when the change is applied and reads back when it is opened.</p>

Controls `ui_cl_renderer` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Graphics & rendering |
| Module | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-10-14 in [`aa48e28a7`](https://github.com/taysta/TaystJK/commit/aa48e28a7d4ffa414d33f0815542c29f8aae8d75) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame_setup.menu:866](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame_setup.menu#L866), [setup.menu:1037](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/setup.menu#L1037) |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |
| Staging copy of | [`cl_renderer`](/TaystJK/reference/cvars/cl_renderer-dc9f64f/); [written through](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6241), [read back](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6369) |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INTERNAL`: internal UI/engine state
- `CVAR_ROM`: read-only after registration

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

- registration: [codemp/ui/ui_main.c:6368](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6368) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:6242](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6242)
- behavior: [codemp/ui/ui_main.c:6370](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6370)
- behavior: [codemp/ui/ui_main.c:6413](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6413)
- behavior: [codemp/ui/ui_main.c:6241](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6241)
- behavior: [codemp/ui/ui_main.c:6369](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L6369)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
