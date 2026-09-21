---
title: "ui_cl_maxpackets"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `ui_cl_maxpackets`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

<p class="ref-notice"><strong>Engine-managed.</strong> The game maintains this value itself, so it is not a setting to change by hand: it is read-only after registration (<code>CVAR_ROM</code>); it is internal UI/engine state, hidden from every cvar listing (<code>CVAR_INTERNAL</code>); it is the menu's staging copy of <a href="/TaystJK/reference/cvars/cl_maxpackets-7b738c4/"><code>cl_maxPackets</code></a>, which the menu writes through when the change is applied and reads back when it is opened.</p>

Controls `ui_cl_maxpackets` in the ui module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Server & networking |
| Module | `ui` |
| Also registered in | `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2015-06-17 in [`d93386f34`](https://github.com/taysta/TaystJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) <span class="status-chip">needs review</span> — [how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has) |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_setup.menu:5230](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L5230) |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | No — the game writes this value. |
| Staging copy of | [`cl_maxPackets`](/TaystJK/reference/cvars/cl_maxpackets-7b738c4/) — [written through](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6430), [read back](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6436) |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INTERNAL` — internal UI/engine state
- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- Ultimate-origin introduction: [`d93386f34b71`](https://github.com/eternalcodes/EternalJK/commit/d93386f34b71fbf1eff27f198956e519918f45a0) in <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> (content authored `2015-06-17`, integrated `2015-06-17`)
- Upstream registration evidence: [codemp/ui/ui_main.c:6322](https://github.com/eternalcodes/EternalJK/blame/a40e793a802c8db8df6132b711eea2fc846e5dd1/codemp/ui/ui_main.c#L6322)
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

## Evidence

- registration: [codemp/ui/ui_main.c:6434](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6434) (Cvar_Register)
- behavior: [codemp/ui/ui_main.c:6430](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6430)
- behavior: [codemp/ui/ui_main.c:6436](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_main.c#L6436)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/6ff04c0baf588a89e5ec9361ad7a0992941d7655"><code>6ff04c0baf58</code></a> on 2026-09-09. Anything merged after that is not reflected here.</p>
