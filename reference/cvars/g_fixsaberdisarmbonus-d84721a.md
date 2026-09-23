---
title: "g_fixSaberDisarmBonus"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_fixSaberDisarmBonus`

<span class="label ref-origin ref-origin-openjk">OpenJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_fixSaberDisarmBonus` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-10-29 in [`530446764`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/w_saber.c:7029](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/w_saber.c#L7029) |
| `1` | Enabled. | [codemp/game/w_saber.c:7029](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/w_saber.c#L7029) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-openjk">OpenJK</span>

- Ultimate-origin introduction: [`142e0b71cca8`](https://github.com/JACoders/OpenJK/commit/142e0b71cca84f53ddbe1eb74fb088db51ad8756) in <span class="label ref-origin ref-origin-openjk">OpenJK</span> (content authored `2024-02-20`, PR opened `2023-10-08`, integrated `2024-02-20`)
- TaystJK integration evidence: [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a)
- Origin pull request: [#1178](https://github.com/JACoders/OpenJK/pull/1178)
- TaystJK integration pull request: [#29](https://github.com/taysta/TaystJK/pull/29)
- Upstream registration evidence: [codemp/game/g_xcvar.h:95](https://github.com/JACoders/OpenJK/blame/1a6a643427aa347553e9073dac5570b33337c4d9/codemp/game/g_xcvar.h#L95)
- Attribution method: `curated-historical-attribution`
- Attribution confidence: `high`
- Notes: Razish introduced g_fixSaberDisarmBonus in OpenJK PR #1178 on 2023-10-08; TaystJK PR #29 imported the still-open OpenJK work later that month. The cvar optionally restores Base JKA behavior but is not itself present in the Base JKA source snapshot.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-08` | — | `2023-10-29` | [`530446764ef0`](https://github.com/taysta/TaystJK/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-08` | — | `2023-10-29` | [`530446764ef0`](https://github.com/videoP/jaPRO/commit/530446764ef05a4c0cff2b29b9eb2b514c5c2b2a) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2024-02-20` | [2023-10-08](https://github.com/JACoders/OpenJK/pull/1178) | `2024-02-20` | [`142e0b71cca8`](https://github.com/JACoders/OpenJK/commit/142e0b71cca84f53ddbe1eb74fb088db51ad8756) | Ultimate origin |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2024-02-20` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

## Evidence

- registration: [codemp/game/g_xcvar.h:92](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_xcvar.h#L92) (XCVAR_DEF)
- behavior: [codemp/game/w_saber.c:7029](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/w_saber.c#L7029)
- behavior: [codemp/game/w_saber.c:7120](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/w_saber.c#L7120)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
