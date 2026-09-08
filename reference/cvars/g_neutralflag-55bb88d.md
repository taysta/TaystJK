---
title: "g_neutralFlag"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_neutralFlag`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_neutralFlag` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `3` | Selects the code path tested for value 3. | [codemp/game/g_active.c:1783](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L1783) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) on `2024-01-03` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#74](https://github.com/taysta/TaystJK/pull/74)
- Matching squash bullet: `g_neutralflag 5 for other style of 1flagctf`
- Upstream registration evidence: [codemp/game/g_xcvar.h:190](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L190)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-03` | [`c644ae832bad`](https://github.com/taysta/TaystJK/commit/c644ae832bade9816a9a1a33240edd63614a28f4) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-03` | [`c644ae832bad`](https://github.com/videoP/jaPRO/commit/c644ae832bade9816a9a1a33240edd63614a28f4) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-04` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`cab839d15251`](https://github.com/videoP/jaPRO/commit/cab839d1525122e2b6b7c3194ca66359ca240acf) · [PR #77](https://github.com/taysta/TaystJK/pull/77)<br>Japro update (#77) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `high` |
| `2024-01-07` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`931f5d5c9044`](https://github.com/videoP/jaPRO/commit/931f5d5c90442d9f4d08c712d5e30537045416d3) · [PR #80](https://github.com/taysta/TaystJK/pull/80)<br>Japro update (#80) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2024-01-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a5c04e80d08f`](https://github.com/videoP/jaPRO/commit/a5c04e80d08fb4398d8ddc5fbcb9121bf4d7f8bd) · [PR #127](https://github.com/taysta/TaystJK/pull/127)<br>Japro updates (#127) | Changed an exact bound cvar-variable reference. `codemp/game/g_team.c` | `high` |
| `2024-03-13` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b4aeeea9c16c`](https://github.com/videoP/jaPRO/commit/b4aeeea9c16c907635bc933b6e3f4e81fb1dd88c) · [PR #176](https://github.com/taysta/TaystJK/pull/176)<br>Japro update (#176) | Changed an exact bound cvar-variable reference. `codemp/game/g_combat.c` | `high` |
| `2024-05-15` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`93c2c1a5b4ef`](https://github.com/videoP/jaPRO/commit/93c2c1a5b4efbea4e009e65fbdbf5148cd68771c) · [PR #201](https://github.com/taysta/TaystJK/pull/201)<br>Japro update (#201) | Changed an exact bound cvar-variable reference. `codemp/game/g_cvar.c`, `codemp/game/g_items.c`, `codemp/game/g_main.c` and 2 more | `high` |

## Evidence

- registration: [codemp/game/g_xcvar.h:189](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L189) (XCVAR_DEF)
- behavior: [codemp/game/g_active.c:1783](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L1783)
- behavior: [codemp/game/g_active.c:3791](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L3791)
- behavior: [codemp/game/g_cmds.c:5750](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L5750)
- behavior: [codemp/game/g_cmds.c:8447](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8447)
- behavior: [codemp/game/g_cmds.c:8592](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L8592)
