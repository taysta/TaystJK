---
title: "g_gunGame"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_gunGame`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_gunGame` in the game module. Consult the cited behavior reads before relying on values not listed here.

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

- Ultimate-origin introduction: [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) on `2023-12-11` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#55](https://github.com/taysta/TaystJK/pull/55)
- Upstream registration evidence: [codemp/game/g_xcvar.h:227](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L227)
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
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c`, `codemp/game/g_main.c` | `high` |
| `2024-01-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`7629ca86250a`](https://github.com/videoP/jaPRO/commit/7629ca86250aaeb5d50e6b2cd1c0bd47791a5e1b) · [PR #95](https://github.com/taysta/TaystJK/pull/95)<br>Japro update (#95) | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:226](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L226) (XCVAR_DEF)
- behavior: [codemp/game/ai_main.c:7380](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L7380)
- behavior: [codemp/game/ai_main.c:7434](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/ai_main.c#L7434)
- behavior: [codemp/game/g_active.c:4292](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L4292)
- behavior: [codemp/game/g_cmds.c:1005](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L1005)
- behavior: [codemp/game/g_cmds.c:5980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L5980)
