---
title: "migrateCheckpoints"
layout: reference
generated: true
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
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support`: Sent to, or only useful with, a supporting game server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2026-07-30 in [`8294d8bc3`](https://github.com/taysta/TaystJK/commit/8294d8bc33182b19e70ebd87d4dd482917e46ca5) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
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

- registration: [codemp/game/g_svcmds.c:1683](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_svcmds.c#L1683) (game-console command table)
- handler: [codemp/game/g_account.c:1343](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/game/g_account.c#L1343)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
