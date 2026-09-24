---
title: "ui_allowRegistration"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_allowRegistration`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: no registration exists; every cited site only writes it with <code>Cvar_Set</code>, so a value you set is replaced the next time that code runs.</p>

Menu-only state the UI keeps while reading server info. `UI_UpdateCurrentServerInfo` clears it on every refresh and sets it to 1 when a jaPRO server advertises `JAPRO_CINFO2_REGISTRATION` in its `jcinfo2` key, which is what offers account registration in the menus.

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
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No; the game writes this value. |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | The server does not advertise account registration, or its info has not been read yet. | [codemp/ui/ui_main.c:631](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/ui/ui_main.c#L631) |
| `1` | The connected jaPRO server accepts account registration. | [codemp/ui/ui_main.c:662](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/ui/ui_main.c#L662) |

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
- Upstream registration evidence: [codemp/ui/ui_main.c:627](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_main.c#L627)
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

- registration: [codemp/ui/ui_main.c:631](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/ui/ui_main.c#L631) (implicit Cvar_Set)
- registration: [codemp/ui/ui_main.c:662](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/ui/ui_main.c#L662) (implicit Cvar_Set)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
