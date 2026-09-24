---
title: "g_neutralFlagTimer"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_neutralFlagTimer`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Milliseconds a capture takes in the one-flag CTF modes of `g_neutralFlag`. In modes 4 and 5 the carrying team's progress rises while it holds the flag in a capture zone and falls while it does not; in mode 6 it counts from the moment a team's flag is placed at its base. `OneFlagCTFCheckTimers` updates the progress every 250 milliseconds and prints a countdown to every player. A negative value is treated as 0 for that countdown. The rabbit modes do not use it.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2024-01-03 in [`c644ae832`](https://github.com/taysta/TaystJK/commit/c644ae832bade9816a9a1a33240edd63614a28f4) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `10000` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-01-03`, integrated `2024-01-03`)
- Origin pull request: [#74](https://github.com/taysta/TaystJK/pull/74)
- Upstream registration evidence: [codemp/game/g_xcvar.h:191](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L191)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-03` | [2024-01-03](https://github.com/taysta/TaystJK/pull/74) | `2024-01-03` | [`c644ae832bad`](https://github.com/taysta/TaystJK/commit/c644ae832bade9816a9a1a33240edd63614a28f4) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-03` | — | `2024-01-03` | [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-05-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93c2c1a5b4ef`](https://github.com/videoP/jaPRO/commit/93c2c1a5b4efbea4e009e65fbdbf5148cd68771c) · [PR #201](https://github.com/taysta/TaystJK/pull/201)<br>Japro update (#201) | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:190](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_xcvar.h#L190) (XCVAR_DEF)
- behavior: [codemp/game/g_trigger.c:223](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L223)
- behavior: [codemp/game/g_trigger.c:227](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L227)
- behavior: [codemp/game/g_main.c:3448](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L3448)
- behavior: [codemp/game/g_main.c:3482](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_main.c#L3482)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
