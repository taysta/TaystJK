---
title: "g_fixSaberDisarmBonus"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_fixSaberDisarmBonus`

<span class="label ref-origin ref-origin-taystjk">TaystJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixSaberDisarmBonus` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| `0` | Disabled. | [codemp/game/w_saber.c:7029](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_saber.c#L7029) |
| `1` | Enabled. | [codemp/game/w_saber.c:7029](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_saber.c#L7029) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-taystjk">TaystJK</span>

- Ultimate-origin introduction: [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) in <span class="label ref-origin ref-origin-taystjk">TaystJK</span> (content authored `2023-10-08`, PR opened `2023-10-28`, integrated `2023-10-29`)
- Origin pull request: [#29](https://github.com/taysta/TaystJK/pull/29)
- Upstream registration evidence: [codemp/game/g_xcvar.h:92](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L92)
- Attribution method: `earliest-authored-project-introduction`
- Attribution confidence: `high`
- Notes: The TaystJK integration evidence credits openjk as an immediate port source, but taystjk has an earlier dated introduction and remains the ultimate origin.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-08` | [2023-10-28](https://github.com/taysta/TaystJK/pull/29) | `2023-10-29` | [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) | Ultimate origin |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-08` | — | `2023-10-29` | [`530446764ef0`](https://github.com/videoP/jaPRO/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) | Shared integration commit |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-20` | — | `2024-02-20` | [`142e0b71cca8`](https://github.com/JACoders/OpenJK/commit/142e0b71cca84f53ddbe1eb74fb088db51ad8756) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-20` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

Immediate port-source credit: <span class="label ref-origin ref-origin-openjk">OpenJK</span>. The earlier dated project remains the ultimate origin.

## Evidence

- registration: [codemp/game/g_xcvar.h:92](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_xcvar.h#L92) (XCVAR_DEF)
- behavior: [codemp/game/w_saber.c:7029](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_saber.c#L7029)
- behavior: [codemp/game/w_saber.c:7120](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/w_saber.c#L7120)
