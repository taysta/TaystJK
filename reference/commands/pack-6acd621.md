---
title: "pack"
layout: reference
nav_exclude: true
search_exclude: false
---

# `pack`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `Cmd_TribesPack_f` in the game module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `needs-server-support` — Sent to, or only useful with, a supporting game server. |
| Derivation | `documented` |
| Confidence | `high` |
| Syntax | `pack <shield, thrust, blink, or overdrive. Bind +force_lightning to activate.>` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.
Gating: `CMD_NOINTERMISSION`.

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`cd07288a30a6`](https://github.com/videoP/jaPRO/commit/cd07288a30a6aa276afdb11f1ae81e5e338134c3) on `2024-01-25` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Pull request: [#116](https://github.com/taysta/TaystJK/pull/116)
- Upstream registration evidence: [codemp/game/g_cmds.c:9018](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_cmds.c#L9018)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `high`
- Notes: The earliest dated introduction is shared by taystjk, japro; fork-lineage order selects taystjk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2024-01-25` | [`cd07288a30a6`](https://github.com/taysta/TaystJK/commit/cd07288a30a6aa276afdb11f1ae81e5e338134c3) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2024-01-25` | [`cd07288a30a6`](https://github.com/videoP/jaPRO/commit/cd07288a30a6aa276afdb11f1ae81e5e338134c3) | Ultimate origin |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-31` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`a5c04e80d08f`](https://github.com/videoP/jaPRO/commit/a5c04e80d08fb4398d8ddc5fbcb9121bf4d7f8bd) · [PR #127](https://github.com/taysta/TaystJK/pull/127)<br>Japro updates (#127) | Changed the registered command handler. `codemp/game/g_cmds.c` | `high` |

## Evidence

- registration: [codemp/game/g_cmds.c:9016](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L9016) (game command table)
- handler: [codemp/game/g_cmds.c:7048](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L7048)
