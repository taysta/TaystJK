---
title: "g_redDamageScale"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_redDamageScale`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_redDamageScale` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Added | 2018-01-01 in [`d9d510063`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) <span class="status-chip">needs review</span> ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2014-11-26`, integrated `2018-01-01`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:205](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L205)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2014-11-26` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2014-11-26` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2014-11-26` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2014-11-26` | — | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared integration commit |

## Evidence

- registration: [codemp/game/g_xcvar.h:204](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_xcvar.h#L204) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:8311](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_cmds.c#L8311)
- behavior: [codemp/game/g_cmds.c:8312](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/g_cmds.c#L8312)
- behavior: [codemp/game/w_saber.c:4457](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/w_saber.c#L4457)
- behavior: [codemp/game/w_saber.c:4459](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/w_saber.c#L4459)
- behavior: [codemp/game/w_saber.c:4480](https://github.com/taysta/TaystJK/blame/b35ed06fec41c53644352743c6b199a5d5d500f3/codemp/game/w_saber.c#L4480)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/b35ed06fec41c53644352743c6b199a5d5d500f3"><code>b35ed06fec41</code></a> on 2026-09-27. Anything merged after that is not reflected here.</p>
