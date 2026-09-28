---
title: "flagRecord"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
description: "Flag, unflag or mark for deletion a player's race record."
---

# `flagRecord`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Marks a player's race record on this server's local database. Mode f flags it invalid, u clears that flag and d flags it for deletion. Write spaces in the course name as *, and use season -1 for every season before 5. Needs the database admin permission.

## At a glance

| Field | Value |
|:--|:--|
| Syntax | `flagRecord <username> <coursename> <style> <season> <f|u|d>` |
| Cheat protected | No |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Category | Demos & media |
| Module | `game` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-12-11 in [`9b57ee1b8`](https://github.com/taysta/TaystJK/commit/9b57ee1b856693898de14daff824dcf111f94b57) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Arguments and gating

Arguments: `username`, `coursename`, `style`, `season`, `mode`.
Gating: `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2023-12-11`, integrated `2023-12-11`)
- Origin pull request: [#55](https://github.com/taysta/TaystJK/pull/55)
- Matching squash bullet: `flagrecord`
- Upstream registration evidence: [codemp/game/g_cmds.c:8970](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_cmds.c#L8970)
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

- registration: [codemp/game/g_cmds.c:8972](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_cmds.c#L8972) (game command table)
- handler: [codemp/game/g_account.c:5389](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/game/g_account.c#L5389)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a"><code>c722804317d7</code></a> on 2026-09-28. Anything merged after that is not reflected here.</p>
