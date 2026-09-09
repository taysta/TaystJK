---
title: "g_securityLog"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_securityLog`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_securityLog` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `1` | Selects the code path tested for value 1. | [codemp/game/g_main.c:292](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L292) |
| `2` | Selects the code path tested for value 2. | [codemp/game/g_main.c:294](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L294) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-04-07`, integrated `2013-04-07`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:150](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L150)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/eternalcodes/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/SomaZ/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/taysta/TaystJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/videoP/jaPRO/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/jkanewmod/NewJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-04-07` | — | `2013-04-07` | [`b319c52fd4ed`](https://github.com/JKSunny/EternalJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5) | Shared integration commit |

## Evidence

- registration: [codemp/game/g_xcvar.h:147](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L147) (XCVAR_DEF)
- behavior: [codemp/game/g_main.c:292](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L292)
- behavior: [codemp/game/g_main.c:294](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L294)
- behavior: [codemp/game/g_main.c:290](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_main.c#L290)
