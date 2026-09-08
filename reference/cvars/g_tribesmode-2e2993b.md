---
title: "g_tribesMode"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_tribesMode`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_tribesMode` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) on `2024-01-15` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#95](https://github.com/taysta/TaystJK/pull/95)
- Matching squash bullet: `[jaPRO clientside] CG_Missile tweaks`
- Upstream registration evidence: [codemp/game/g_xcvar.h:374](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L374)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-15` | [`7629ca86250a`](https://github.com/taysta/TaystJK/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-15` | [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cfe93fa637b5`](https://github.com/videoP/jaPRO/commit/cfe93fa637b5410c77a8cdd9e3b69eb7bbdc1705) · [PR #97](https://github.com/taysta/TaystJK/pull/97)<br>Japro update (#97) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c` | `high` |
| `2024-01-21` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`1caa28c184c3`](https://github.com/videoP/jaPRO/commit/1caa28c184c35fb57332b669a1cfcc9c9f7deb8c) · [PR #103](https://github.com/taysta/TaystJK/pull/103)<br>Japro update (#103) | Changed an exact bound cvar-variable reference. `codemp/game/bg_slidemove.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2024-03-20` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`fd60c90af33d`](https://github.com/taysta/TaystJK/commit/fd60c90af33defecee04566f23d593542b85a911)<br>bot cap routes | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:373](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L373) (XCVAR_DEF)
- behavior: [codemp/game/g_client.c:2269](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2269)
- behavior: [codemp/game/g_client.c:2542](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L2542)
- behavior: [codemp/game/g_client.c:4201](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_client.c#L4201)
- behavior: [codemp/game/g_combat.c:5089](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_combat.c#L5089)
- behavior: [codemp/game/g_cvar.c:570](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cvar.c#L570)
