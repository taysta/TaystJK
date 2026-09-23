---
title: "ui_raceMode"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_raceMode`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: no registration exists; every cited site only writes it with <code>Cvar_Set</code>, so a value you set is replaced the next time that code runs.</p>

Menu-only state the UI keeps while reading server info. `UI_UpdateCurrentServerInfo` clears it on every refresh and sets it to 1 when a jaPRO server advertises `JAPRO_CINFO2_RACEMODE` in its `jcinfo2` key. A value set by hand is replaced at the next refresh.

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-09-10 in [`dbfd735d1`](https://github.com/taysta/TaystJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | Yes: [ingame.menu:151](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame.menu#L151), [ingame.menu:184](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame.menu#L184), [ingame.menu:805](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/assets/japro/ui/jamp/ingame.menu#L805) |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | The server does not advertise race mode, or its info has not been read yet. | [codemp/ui/ui_main.c:629](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L629) |
| `1` | The connected jaPRO server advertises race mode. | [codemp/ui/ui_main.c:656](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L656) |

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

- registration: [codemp/ui/ui_main.c:629](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L629) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:656](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/ui/ui_main.c#L656) (implicit Cvar_Set)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
