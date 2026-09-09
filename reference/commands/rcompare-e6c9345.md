---
title: "rCompare"
layout: reference
nav_exclude: true
search_exclude: false
---

# `rCompare`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_DFCompare_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `rCompare <username> <style (optional)> <current season (optional - example: s) <page (optional)>. This displays the courses that the specified user has defeated you on` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`90d3c68f2da9`](https://github.com/videoP/jaPRO/commit/90d3c68f2da918f353b24bff60e49066dd018806) in <span class="label ref-origin ref-origin-japro">jaPRO</span> (content authored `2024-01-10`, integrated `2024-01-10`)
- Origin pull request: [#84](https://github.com/taysta/TaystJK/pull/84)
- Matching squash bullet: `rCompare command`
- Upstream registration evidence: [codemp/game/g_cmds.c:9024](https://github.com/videoP/jaPRO/blame/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_cmds.c#L9024)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-10` | [2024-01-10](https://github.com/taysta/TaystJK/pull/84) | `2024-01-10` | [`90d3c68f2da9`](https://github.com/taysta/TaystJK/commit/90d3c68f2da918f353b24bff60e49066dd018806) | Shared integration commit |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-10` | — | `2024-01-10` | [`90d3c68f2da9`](https://github.com/videoP/jaPRO/commit/90d3c68f2da918f353b24bff60e49066dd018806) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-02-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`cf5f50918b74`](https://github.com/taysta/TaystJK/commit/cf5f50918b744e1f99f36241ca1df889ce0514b6) · [PR #125](https://github.com/taysta/TaystJK/pull/125)<br>Small fixes (#125) | Changed the registered command handler. `codemp/game/g_account.c` | `medium` |
| `2024-02-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`391790395694`](https://github.com/videoP/jaPRO/commit/391790395694e26a8ad9ab2ef6e2bd9f22710ecd) · [PR #145](https://github.com/taysta/TaystJK/pull/145)<br>Japro update (#145) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `high` |
| `2026-06-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`ca5625290071`](https://github.com/videoP/jaPRO/commit/ca5625290071860c03fbda26bf6082dfa47a0df0) · [PR #319](https://github.com/taysta/TaystJK/pull/319)<br>Merge pull request #319 from taysta/japro-up | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_cmds.c:9022](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_cmds.c#L9022) (game command table)
- handler: [codemp/game/g_account.c:5993](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L5993)
