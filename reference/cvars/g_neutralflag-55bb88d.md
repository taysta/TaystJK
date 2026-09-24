---
title: "g_neutralFlag"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `g_neutralFlag`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Selects a neutral-flag game mode. Values 1 to 3 are rabbit variants for FFA and team FFA; values 4 to 6 are one-flag CTF variants for the CTF gametype, and a value outside a gametype's range leaves that gametype's normal flags in place. Changing the value swaps the flags immediately through `CVU_Rabbit`, without a map restart. Every mode needs a map with a `team_CTF_neutralflag`, and the one-flag modes also need `trigger_multiple` capture zones: spawnflag 16384 for values 4 and 5, spawnflag 32768 for value 6. The stock maps have neither. `g_neutralFlagTimer` sets how long a capture takes.

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
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Off. The map's neutral flag is removed at load, and CTF keeps its red and blue flags. | [codemp/game/g_items.c:3160](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_items.c#L3160) |
| `1` | Rabbit, in FFA and team FFA: a neutral flag spawns and players fight to carry it. | [codemp/game/g_cvar.c:472](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cvar.c#L472) |
| `2` | Sniper rabbit: as 1, but picking up the flag leaves the carrier with only a disruptor and 300 ammo. | [codemp/game/g_team.c:1181](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_team.c#L1181) |
| `3` | Rabbit where the carrier scores a point for every five seconds they hold the flag. | [codemp/game/g_active.c:1783](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_active.c#L1783) |
| `4` | One-flag CTF: score by holding the neutral flag inside your own team's capture zone for `g_neutralFlagTimer`. | [codemp/game/g_trigger.c:212](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L212) |
| `5` | One-flag CTF: score by holding the neutral flag inside the other team's capture zone for `g_neutralFlagTimer`. | [codemp/game/g_trigger.c:214](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L214) |
| `6` | One-flag CTF with capture points: bringing the neutral flag into a team's capture point puts that team's flag at its base, and the team scores when `g_neutralFlagTimer` runs out unless the other team takes that flag first. | [codemp/game/g_trigger.c:234](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_trigger.c#L234) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-01-03`, integrated `2024-01-03`)
- Origin pull request: [#74](https://github.com/taysta/TaystJK/pull/74)
- Matching squash bullet: `g_neutralflag 5 for other style of 1flagctf`
- Upstream registration evidence: [codemp/game/g_xcvar.h:190](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L190)
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
| `2024-01-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cab839d15251`](https://github.com/videoP/jaPRO/commit/cab839d1525122e2b6b7c3194ca66359ca240acf) · [PR #77](https://github.com/taysta/TaystJK/pull/77)<br>Japro update (#77) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `high` |
| `2024-01-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`931f5d5c9044`](https://github.com/videoP/jaPRO/commit/931f5d5c90442d9f4d08c712d5e30537045416d3) · [PR #80](https://github.com/taysta/TaystJK/pull/80)<br>Japro update (#80) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2024-01-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a5c04e80d08f`](https://github.com/videoP/jaPRO/commit/a5c04e80d08fb4398d8ddc5fbcb9121bf4d7f8bd) · [PR #127](https://github.com/taysta/TaystJK/pull/127)<br>Japro updates (#127) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `high` |
| `2024-03-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b4aeeea9c16c`](https://github.com/videoP/jaPRO/commit/b4aeeea9c16c907635bc933b6e3f4e81fb1dd88c) · [PR #176](https://github.com/taysta/TaystJK/pull/176)<br>Japro update (#176) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2024-05-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93c2c1a5b4ef`](https://github.com/videoP/jaPRO/commit/93c2c1a5b4efbea4e009e65fbdbf5148cd68771c) · [PR #201](https://github.com/taysta/TaystJK/pull/201)<br>Japro update (#201) | Changed an exact bound cvar-variable reference. `codemp/game/g_cvar.c`, `codemp/game/g_items.c`, `codemp/game/g_main.c` and 2 more | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:189](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_xcvar.h#L189) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:1783](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_active.c#L1783)
- behavior: [codemp/game/g_active.c:3791](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_active.c#L3791)
- behavior: [codemp/game/g_cmds.c:5750](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L5750)
- behavior: [codemp/game/g_cmds.c:8447](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L8447)
- behavior: [codemp/game/g_cmds.c:8592](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/codemp/game/g_cmds.c#L8592)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/f4643281440c626cb7e30444c8c392606167a7f8"><code>f4643281440c</code></a> on 2026-09-23. Anything merged after that is not reflected here.</p>
