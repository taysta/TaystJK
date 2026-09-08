---
title: "g_splashDamageScale"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_splashDamageScale`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_splashDamageScale` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) on `2023-12-11` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#55](https://github.com/taysta/TaystJK/pull/55)
- Upstream registration evidence: [codemp/game/g_xcvar.h:222](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L222)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-12-11` | [`9b57ee1b8566`](https://github.com/taysta/TaystJK/commit/9b57ee1b856693898de14daff824dcf111f94b57) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-12-11` | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-06` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`668338988def`](https://github.com/videoP/jaPRO/commit/668338988def7a28cb6cfbf9ffb8d3848a391662) · [PR #79](https://github.com/taysta/TaystJK/pull/79)<br>Japro update (#79) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-01-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) · [PR #95](https://github.com/taysta/TaystJK/pull/95)<br>Japro update (#95) | Changed an exact bound cvar-variable reference. `codemp/game/g_items.c`, `codemp/game/g_weapon.c` | `high` |
| `2024-01-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a5c04e80d08f`](https://github.com/videoP/jaPRO/commit/a5c04e80d08fb4398d8ddc5fbcb9121bf4d7f8bd) · [PR #127](https://github.com/taysta/TaystJK/pull/127)<br>Japro updates (#127) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |
| `2024-02-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`97cd4091c2ca`](https://github.com/videoP/jaPRO/commit/97cd4091c2cab5c5473a1caf8a33c543be24ab92) · [PR #129](https://github.com/taysta/TaystJK/pull/129)<br>Japro update (#129) | Changed an exact bound cvar-variable reference. `codemp/game/g_weapon.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:221](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L221) (XCVAR_DEF)
- behavior: [codemp/game/g_items.c:1511](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_items.c#L1511)
- behavior: [codemp/game/g_weapon.c:648](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_weapon.c#L648)
- behavior: [codemp/game/g_weapon.c:1341](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_weapon.c#L1341)
- behavior: [codemp/game/g_weapon.c:1781](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_weapon.c#L1781)
- behavior: [codemp/game/g_weapon.c:2657](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_weapon.c#L2657)
