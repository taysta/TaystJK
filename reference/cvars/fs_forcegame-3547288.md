---
title: "fs_forcegame"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_forcegame`

<span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

Folder to use for overriding of fs_game (can not be set by the server).

## At a glance

| Field | Value |
|:--|:--|
| Category | Files & downloads |
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Default | `` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `` | `engine-shared` | `—` | `defined(DEDICATED)` |
| `TAYSTJKGAME` | `engine-shared` | `—` | `else(defined(DEDICATED))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-eternaljk">EternalJK</span>

- TaystJK integration evidence: [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0)
- Origin pull request: [#52](https://github.com/taysta/TaystJK/pull/52)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: openjk retains origin because content authorship and PR submission predate the project that merged the work first. An identifier-adjacent source/commit/PR line explicitly credits eternaljk.

### Dated project introductions

Authored dates come from the exact registration's first content commit, PR dates identify when work was proposed to each project, and integration dates come from each first-parent mainline. A project merging first does not override earlier upstream authorship or submission.

| Project | Authored | PR opened | Integrated | Commit | Relationship |
|:--|:--|:--|:--|:--|:--|
| <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | `2019-02-17` | — | `2020-01-01` | [`d99db29e816a`](https://github.com/mvdevs/jk2mv/commit/d99db29e816a526986efe41769ee56fb3557fad5) | Other project appearance |
| <span class="label ref-origin ref-origin-newjk">NewJK / NewMod</span> | `2019-10-18` | — | `2019-10-18` | [`ca19cb761e35`](https://github.com/jkanewmod/NewJK/commit/ca19cb761e35a040fac8b4992c6221c4d5a1127b) | Other project appearance |
| <span class="label ref-origin ref-origin-openjk">OpenJK</span> | `2023-11-06` | [2023-11-07](https://github.com/JACoders/OpenJK/pull/1185) | `2024-04-07` | [`065d32955f56`](https://github.com/JACoders/OpenJK/commit/065d32955f56f595c93498a102c16a1d5a051672) | Other project appearance |
| <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | `2023-11-06` | [2023-11-27](https://github.com/taysta/TaystJK/pull/52) | `2023-11-28` | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-japro">jaPRO</span> | `2023-11-06` | — | `2023-11-28` | [`596ae40cc9aa`](https://github.com/videoP/jaPRO/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) | Other project appearance |
| <span class="label ref-origin ref-origin-rend2">rend2</span> | `2023-11-06` | — | `2024-04-09` | [`b688bdf3ea00`](https://github.com/SomaZ/OpenJK/commit/b688bdf3ea00319185f6b027ef61c6d7f506d36f) | Other project appearance |

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2024-01-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0da288606eb0`](https://github.com/taysta/TaystJK/commit/0da288606eb0ef10bc481321a3265faa0fdf1f71) · [PR #98](https://github.com/taysta/TaystJK/pull/98)<br>Make fs_forcegame and fs_basegame default to empty for dedicated servers. (#98) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`dbbea6b8a0bf`](https://github.com/taysta/TaystJK/commit/dbbea6b8a0bfb65a68e4e38c818bcfb0b49f929e) · [PR #31](https://github.com/taysta/TaystJK/pull/31)<br>Rename to TaystJK (#31) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `high` |
| `2026-06-16` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`07c65a6f01a8`](https://github.com/taysta/TaystJK/commit/07c65a6f01a8023f2977bc1255f62a08d6154e3a) · [PR #341](https://github.com/taysta/TaystJK/pull/341)<br>Merge pull request #341 from taysta/basegame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3913](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3913) (Cvar_Get); condition `defined(DEDICATED)`
- registration: [codemp/qcommon/files.cpp:3915](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3915) (Cvar_Get); condition `else(defined(DEDICATED))`
- behavior: [codemp/qcommon/files.cpp:3752](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3752)
- behavior: [codemp/qcommon/files.cpp:3753](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3753)
- behavior: [codemp/qcommon/files.cpp:3988](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3988)
- behavior: [codemp/qcommon/files.cpp:3989](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3989)
- behavior: [codemp/qcommon/files.cpp:4480](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L4480)
