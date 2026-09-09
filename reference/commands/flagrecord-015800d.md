---
title: "flagRecord"
layout: reference
nav_exclude: true
search_exclude: false
---

# `flagRecord`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_InvalidateRace_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Demos & media |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `flagRecord <username> <coursename> <style> <season> <mode: f, u, d>. Use * in place of space in the coursename` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
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

- registration: [codemp/game/g_cmds.c:8968](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L8968) (game command table)
- handler: [codemp/game/g_account.c:5389](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L5389)
