---
title: "restricts"
layout: reference
nav_exclude: true
search_exclude: false
---

# `restricts`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `restricts` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `medium` |
| Default | `0` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_SERVERINFO` — published in serverinfo

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Ultimate-origin introduction: [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) on `2018-01-01` in <span class="label ref-origin ref-origin-japro">jaPRO</span>
- Upstream registration evidence: [codemp/game/g_xcvar.h:317](https://github.com/videoP/jaPRO/blob/33d1f1e22ac6db0c17beedbcc419ffef98bbe3c3/codemp/game/g_xcvar.h#L317)
- Attribution method: `squash-feature-group-explicit-credit`
- Attribution confidence: `medium`
- Notes: The earliest dated introduction is shared by eternaljk, taystjk, japro, vulkan; fork-lineage order selects eternaljk. The identifier's single-prefix squash feature group explicitly credits japro.

### Dated project introductions

These are first appearances on each project's current first-parent line. Later rows show ports or downstream availability; they do not replace the earliest origin.

| Project | Date | Commit | Relationship |
|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/eternalcodes/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/taysta/TaystJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Ultimate origin |
| <span class="label ref-origin ref-origin-vulkan">Vulkan</span> | `2018-01-01` | [`d9d510063ce6`](https://github.com/JKSunny/EternalJK/commit/d9d510063ce680639e6ba060021b6d40ee0c1419) | Shared earliest lineage |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_servercmds.c` and 2 more | `high` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2022-09-18` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`d0baa5bc31c9`](https://github.com/taysta/TaystJK/commit/d0baa5bc31c9dda8c055f33455c6224049779f0f)<br>Updated cosmetics and voice chat memes | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2024-02-08` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`c43219e502b9`](https://github.com/videoP/jaPRO/commit/c43219e502b96da39707d8ffaa9f2c35adb4f2f5) · [PR #136](https://github.com/taysta/TaystJK/pull/136)<br>Japro update - Surf Movement `/move surf` (#136) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `high` |
| `2025-04-26` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`44d85df90f4b`](https://github.com/taysta/TaystJK/commit/44d85df90f4bd424a141ae4e4e25fbe5c71c4885) · [PR #228](https://github.com/taysta/TaystJK/pull/228)<br>Update built in SDL version for windows to 2.32.4 (#228) | Changed an exact bound cvar-variable reference. `lib/SDL2/include/SDL_render.h` | `medium` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:316](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L316) (XCVAR_DEF)
- behavior: [lib/SDL2/include/SDL_render.h:853](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/lib/SDL2/include/SDL_render.h#L853)
- behavior: [codemp/cgame/cg_consolecmds.c:786](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L786)
- behavior: [codemp/cgame/cg_consolecmds.c:1002](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1002)
- behavior: [codemp/cgame/cg_consolecmds.c:1020](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1020)
- behavior: [codemp/cgame/cg_consolecmds.c:1032](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L1032)
