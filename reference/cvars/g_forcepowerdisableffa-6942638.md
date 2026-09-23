---
title: "g_forcePowerDisableFFA"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_forcePowerDisableFFA`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_forcePowerDisableFFA` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-07-22 in [`fae0fd307`](https://github.com/taysta/TaystJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`fae0fd307416`](https://github.com/videoP/jaPRO/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2018-04-09`, integrated `2018-07-22`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:102](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L102)
- Attribution method: `shared-earliest-commit-module-lineage`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; module lineage selects japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-04-09` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-04-09` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/taysta/TaystJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-04-09` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/videoP/jaPRO/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-04-09` | — | `2018-07-22` | [`fae0fd307416`](https://github.com/JKSunny/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a) | Shared integration commit |

## Evidence

- registration: [codemp/game/g_xcvar.h:101](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/g_xcvar.h#L101) (XCVAR_DEF)
- behavior: [codemp/game/w_force.c:743](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/game/w_force.c#L743)
- behavior: [codemp/cgame/cg_main.c:3378](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/cgame/cg_main.c#L3378)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/77d84176b3b94356d189a4420e1bc5e68c88e1ea"><code>77d84176b3b9</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
