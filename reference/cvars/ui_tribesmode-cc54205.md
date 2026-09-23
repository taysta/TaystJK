---
title: "ui_tribesMode"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_tribesMode`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: no registration exists; every cited site only writes it with <code>Cvar_Set</code>, so a value you set is replaced the next time that code runs.</p>

Menu-only state the UI keeps while reading server info. `UI_UpdateCurrentServerInfo` clears it on every refresh and sets it to 1 when a jaPRO server advertises `JAPRO_CINFO2_WTTRIBES` in its `jcinfo2` key; the in-game tribes menu reads it to offer the class and pack pages. A value set by hand is replaced at the next refresh.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2024-02-28 in [`baa02905f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame.menu:72](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/assets/japro/ui/jamp/ingame.menu#L72), [ingame.menu:86](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/assets/japro/ui/jamp/ingame.menu#L86), [ingame.menu:898](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/assets/japro/ui/jamp/ingame.menu#L898) |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | The server does not advertise tribes mode, or its info has not been read yet. | [codemp/ui/ui_main.c:630](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_main.c#L630) |
| `1` | The connected jaPRO server advertises tribes mode. | [codemp/ui/ui_main.c:659](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_main.c#L659) |

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

- registration: [codemp/ui/ui_main.c:630](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_main.c#L630) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:659](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/ui/ui_main.c#L659) (implicit Cvar_Set)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
