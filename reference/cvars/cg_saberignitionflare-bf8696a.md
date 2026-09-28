---
title: "cg_saberIgnitionFlare"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cg_saberIgnitionFlare`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_saberIgnitionFlare` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Default | `1` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Manually settable | Yes |
| Cheat protected | No |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Category | Gameplay & combat |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-11-04 in [`66fe36b09`](https://github.com/taysta/TaystJK/commit/66fe36b094c3fbae2629049c48080c385f6d661a) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_players.c:6388](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_players.c#L6388) |
| `1` | Enabled. | [codemp/cgame/cg_players.c:6388](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_players.c#L6388) |

## Flags

- `CVAR_NONE`: fork/source-defined flag; see registration evidence

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`66fe36b094c3`](https://github.com/taysta/TaystJK/commit/66fe36b094c3fbae2629049c48080c385f6d661a)
- Origin pull request: [#43](https://github.com/taysta/TaystJK/pull/43)
- Attribution method: `introduction-commit-developer-lineage-credit`
- Attribution confidence: `high`
- Notes: Explicit Bucky developer credit identifies his unpublished EternalJK continuation as the origin; no public EternalJK registration is expected.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-10-20` | [2023-11-04](https://github.com/taysta/TaystJK/pull/43) | `2023-11-04` | [`66fe36b094c3`](https://github.com/taysta/TaystJK/commit/66fe36b094c3fbae2629049c48080c385f6d661a) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-10-20` | — | `2023-11-04` | [`66fe36b094c3`](https://github.com/videoP/jaPRO/commit/66fe36b094c3fbae2629049c48080c385f6d661a) | Other project appearance |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:175](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_xcvar.h#L175) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_players.c:6388](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_players.c#L6388)
- behavior: [codemp/cgame/cg_players.c:6630](https://github.com/taysta/TaystJK/blame/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a/codemp/cgame/cg_players.c#L6630)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/c722804317d7f9e3ce78b05a7ba67cd8e09b0c0a"><code>c722804317d7</code></a> on 2026-09-28. Anything merged after that is not reflected here.</p>
