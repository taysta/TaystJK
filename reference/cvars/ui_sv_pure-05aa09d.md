---
title: "ui_sv_pure"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_sv_pure`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>); it is internal UI/engine state, hidden from every cvar listing (<code>CVAR_INTERNAL</code>).</p>

Menu-only mirror of the connected server's `sv_pure` systeminfo value, refreshed by `UI_UpdateCurrentServerInfo` and rewritten only when it changes so the cvar update function runs on the following frame.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2019-06-12 in [`49e91d910`](https://github.com/taysta/TaystJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
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
| `0` | Disabled. | [codemp/ui/ui_cvar.c:103](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_cvar.c#L103) |
| `1` | Enabled. | [codemp/ui/ui_cvar.c:103](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_cvar.c#L103) |

## Flags

- `CVAR_INTERNAL`: internal UI/engine state
- `CVAR_NORESTART`: preserved across cvar restart
- `CVAR_ROM`: read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2019-06-13`, integrated `2019-06-13`)
- Upstream registration evidence: [codemp/ui/ui_xcvar.h:165](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_xcvar.h#L165)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/eternalcodes/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Ultimate origin |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/taysta/TaystJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/videoP/jaPRO/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2019-06-13` | — | `2019-06-13` | [`49e91d910266`](https://github.com/JKSunny/EternalJK/commit/49e91d910266ea4df300720e1b1cd24473de1e01) | Shared integration commit |

## Evidence

- registration: [codemp/ui/ui_xcvar.h:167](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xcvar.h#L167) (XCVAR_DEF)
- behavior: [codemp/ui/ui_cvar.c:103](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_cvar.c#L103)
- behavior: [codemp/ui/ui_main.c:8936](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8936)
- behavior: [codemp/ui/ui_main.c:8938](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8938)
- behavior: [codemp/ui/ui_main.c:8945](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L8945)
- behavior: [codemp/ui/ui_main.c:9829](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L9829)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
