---
title: "g_voteDelay"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_voteDelay`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_voteDelay` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| Default | `3000` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_NONE` — fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`872159cb6796`](https://github.com/JACoders/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2013-10-24`, integrated `2013-10-24`)
- Upstream registration evidence: [codemp/game/g_xcvar.h:169](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L169)
- Attribution method: `shared-earliest-commit-lineage-order`
- Attribution confidence: `medium`
- Notes: The earliest authored/submitted introduction is shared by openjk, eternaljk, rend2, taystjk, japro, newjk, vulkan; fork-lineage order selects openjk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/JACoders/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821) | Ultimate origin |
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/eternalcodes/EternalJK/commit/872159cb6796e09bcd1065e318453e5358f52821) | Shared integration commit |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/SomaZ/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821) | Shared integration commit |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/taysta/TaystJK/commit/872159cb6796e09bcd1065e318453e5358f52821) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/videoP/jaPRO/commit/872159cb6796e09bcd1065e318453e5358f52821) | Shared integration commit |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/jkanewmod/NewJK/commit/872159cb6796e09bcd1065e318453e5358f52821) | Shared integration commit |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2013-10-24` | — | `2013-10-24` | [`872159cb6796`](https://github.com/JKSunny/EternalJK/commit/872159cb6796e09bcd1065e318453e5358f52821) | Shared integration commit |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-10-25` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`99f68a293fef`](https://github.com/JACoders/OpenJK/commit/99f68a293fef762f6c6cf8ee76e2b0e21811c7c3)<br>[MP] Fixed a few issues with vote code from previous commits. Tweaked the team vote code to be a simplified but similar version of the new callvote code. Added g_allowTeamVote, defaulted to 1 cvar to toggle team voting. | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:166](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L166) (XCVAR_DEF)
- behavior: [codemp/game/g_cmds.c:3318](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3318)
- behavior: [codemp/game/g_cmds.c:3323](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3323)
- behavior: [codemp/game/g_cmds.c:3079](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L3079)
