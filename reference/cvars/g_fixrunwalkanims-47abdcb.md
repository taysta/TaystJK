---
title: "g_fixRunWalkAnims"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixRunWalkAnims`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixRunWalkAnims` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/bg_pmove.c:8121](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8121) |
| `1` | Enabled. | [codemp/game/bg_pmove.c:8121](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8121) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`1e8a7998ca2f`](https://github.com/JACoders/OpenJK/commit/1e8a7998ca2fe434daebb41d586ac3cd5296433a) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2024-02-20`, integrated `2024-02-20`)
- TaystJK integration evidence: [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d)
- Origin pull request: [#157](https://github.com/taysta/TaystJK/pull/157)
- Matching squash bullet: `remove BASE_COMPAT and BuildMPWithCompatMode, add g_fixRunWalkAnims`
- Upstream registration evidence: [codemp/game/g_xcvar.h:97](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L97)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-20` | — | `2024-02-20` | [`1e8a7998ca2f`](https://github.com/JACoders/OpenJK/commit/1e8a7998ca2fe434daebb41d586ac3cd5296433a) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-20` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-02-26` | [2024-02-23](https://github.com/taysta/TaystJK/pull/157) | `2024-02-26` | [`cd784cbf26da`](https://github.com/taysta/TaystJK/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-02-26` | — | `2024-02-26` | [`cd784cbf26da`](https://github.com/videoP/jaPRO/commit/cd784cbf26dac3fe0120ee2ec30654f17b5ab26d) | Other project appearance |

## Evidence

- registration: [codemp/game/g_xcvar.h:95](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L95) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:8121](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L8121)
- behavior: [codemp/game/g_cvar.c:631](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cvar.c#L631)
