---
title: "bot_team"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Force bots onto one team in team game types."
---

# `bot_team`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

In team game types, 1 puts bots on the blue team and 2 or higher puts them on red, overriding any team given to addbot. 0 keeps the team given to addbot and balances a bot added without one. Bots are placed again at every map change or restart: on the chosen team, or rebalanced across the teams when this is 0.

## At a glance

| Field | Value |
|:--|:--|
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `server-authoritative`: Owned or enforced by the server. |
| Category | Bots & AI |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-12-11 in [`9b57ee1b8`](https://github.com/taysta/TaystJK/commit/9b57ee1b856693898de14daff824dcf111f94b57) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Keep the team given to addbot, or balance a bot added without one. Bots are rebalanced at each map change or restart. | [codemp/game/g_bot.c:986](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_bot.c#L986) |
| `1` | Put bots on the blue team, overriding the team given to addbot. | [codemp/game/g_bot.c:980](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_bot.c#L980) |
| `>=2` | Put bots on the red team, overriding the team given to addbot. | [codemp/game/g_bot.c:982](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_bot.c#L982) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2023-12-11`, integrated `2023-12-11`)
- Origin pull request: [#55](https://github.com/taysta/TaystJK/pull/55)
- Upstream registration evidence: [codemp/game/g_xcvar.h:344](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L344)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-12-11` | [2023-12-11](https://github.com/taysta/TaystJK/pull/55) | `2023-12-11` | [`9b57ee1b8566`](https://github.com/taysta/TaystJK/commit/9b57ee1b856693898de14daff824dcf111f94b57) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-12-11` | — | `2023-12-11` | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) | Ultimate origin |

## Evidence

- registration: [codemp/game/g_xcvar.h:343](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_xcvar.h#L343) (XCVAR_DEF)
- behavior: [codemp/game/g_bot.c:980](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_bot.c#L980)
- behavior: [codemp/game/g_bot.c:982](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_bot.c#L982)
- behavior: [codemp/game/g_client.c:3055](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_client.c#L3055)
- behavior: [codemp/game/g_client.c:3059](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_client.c#L3059)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a"><code>c722804317d7</code></a> on 2026-09-28. Anything merged after that is not reflected here.</p>
