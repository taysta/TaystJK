---
title: "cg_saberStaffMultiColor"
layout: reference
generated: true
nav_exclude: true
search_exclude: false
---

# `cg_saberStaffMultiColor`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_saberStaffMultiColor` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only`: Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Added | 2023-11-02 in [`31486bc3a`](https://github.com/taysta/TaystJK/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f) ([how to compare this against your build](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has)) |
| In-game xdocs | No |
| In-game menu | No |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |
| Player-settable | Yes |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_players.c:7541](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/cgame/cg_players.c#L7541) |
| `1` | Enabled. | [codemp/cgame/cg_players.c:7541](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/cgame/cg_players.c#L7541) |

## Flags

- `CVAR_ARCHIVE`: saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`31486bc3a398`](https://github.com/taysta/TaystJK/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f)
- Attribution method: `identifier-adjacent-developer-lineage-credit`
- Attribution confidence: `high`
- Notes: Explicit Bucky developer credit identifies his unpublished EternalJK continuation as the origin; no public EternalJK registration is expected.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-02` | — | `2023-11-02` | [`31486bc3a398`](https://github.com/taysta/TaystJK/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-02` | — | `2023-11-02` | [`31486bc3a398`](https://github.com/videoP/jaPRO/commit/31486bc3a398e25afc5b606c80d89f5f6dabf85f) | Other project appearance |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:98](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/cgame/cg_xcvar.h#L98) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_players.c:7541](https://github.com/taysta/TaystJK/blame/a15beafad337a07e6a965e5063053ed265a96fe2/codemp/cgame/cg_players.c#L7541)

<p class="page-provenance">Generated from source commit <a href="https://github.com/taysta/TaystJK/tree/a15beafad337a07e6a965e5063053ed265a96fe2"><code>a15beafad337</code></a> on 2026-09-24. Anything merged after that is not reflected here.</p>
