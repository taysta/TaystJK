---
title: "migrateCheckpoints"
layout: reference
nav_exclude: true
search_exclude: false
---

# `migrateCheckpoints`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `SV_MigrateCheckpoints_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Category | Movement & race |
| Feature family | Checkpoints |
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `migrateCheckpoints` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- TaystJK integration evidence: [`8294d8bc3318`](https://github.com/taysta/TaystJK/commit/8294d8bc33182b19e70ebd87d4dd482917e46ca5)
- Origin pull request: [#351](https://github.com/taysta/TaystJK/pull/351)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2026-06-23` | [2026-07-30](https://github.com/taysta/TaystJK/pull/351) | `2026-07-30` | [`8294d8bc3318`](https://github.com/taysta/TaystJK/commit/8294d8bc33182b19e70ebd87d4dd482917e46ca5) | Other project appearance |

## Evidence

- registration: [codemp/game/g_svcmds.c:1683](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_svcmds.c#L1683) (game-console command table)
- handler: [codemp/game/g_account.c:1343](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/g_account.c#L1343)
