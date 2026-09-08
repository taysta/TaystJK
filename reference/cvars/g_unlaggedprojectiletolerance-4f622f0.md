---
title: "g_unlaggedProjectileTolerance"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_unlaggedProjectileTolerance`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_unlaggedProjectileTolerance` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `135` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`41c7e75be47a`](https://github.com/videoP/jaPRO/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) on `2023-12-21` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#57](https://github.com/taysta/TaystJK/pull/57)
- Upstream registration evidence: [codemp/game/g_xcvar.h:278](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L278)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-12-21` | [`41c7e75be47a`](https://github.com/taysta/TaystJK/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-12-21` | [`41c7e75be47a`](https://github.com/videoP/jaPRO/commit/41c7e75be47a14426fe6ec5dd479edc5aa77a310) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9e120086add8`](https://github.com/videoP/jaPRO/commit/9e120086add83f23befd7186ece215c286b943c8) · [PR #71](https://github.com/taysta/TaystJK/pull/71)<br>Japro update (#71) | Changed an exact bound cvar-variable reference. `codemp/game/g_missile.c` | `high` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:277](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L277) (XCVAR_DEF)
- behavior: [codemp/game/g_missile.c:385](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_missile.c#L385)
- behavior: [codemp/game/g_missile.c:1439](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_missile.c#L1439)
- behavior: [codemp/game/g_missile.c:386](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_missile.c#L386)
- behavior: [codemp/game/g_missile.c:1440](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_missile.c#L1440)
- behavior: [codemp/cgame/cg_weapons.c:2476](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L2476)
