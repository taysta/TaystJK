---
title: "fs_basegame"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fs_basegame`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `fs_basegame` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `baseGame` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_INIT` — initialization/command-line setting

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/qcommon/files.cpp:2952](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/qcommon/files.cpp#L2952)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2013-11-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2229f7cb1aba`](https://github.com/JACoders/OpenJK/commit/2229f7cb1aba359eed397f76f466fe4e2dcabae4)<br>[MP] Migrate files code to a single file. Use long instead of int in some file functions. Security to prevent mods from manipulating dll/so/dylib/pk3. Don't include client.h in every case. | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2015-11-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ef5d7214371`](https://github.com/taysta/TaystJK/commit/5ef5d7214371ff3d3d0d84544ad8bbbd975e6593)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2015-11-16` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b864bfdbe2b9`](https://github.com/videoP/jaPRO/commit/b864bfdbe2b959b0dd858893ce6a4ed42c104c3d)<br>fs_basegame changed to japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `high` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/files.cpp` | `medium` |
| `2016-07-31` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`d74e78e6cdd0`](https://github.com/eternalcodes/EternalJK/commit/d74e78e6cdd03e189fe2fe757fd23360db3a1b84)<br>fs_basegame changed to eternaljk | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `high` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2018-12-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`546dfb076f6f`](https://github.com/videoP/jaPRO/commit/546dfb076f6f12d4fc8ebedb8302e7cfa6aad54e)<br>OSX: Fix basepath (japro-assets) not loading from apppath? | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |
| `2019-07-08` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fea7b6aef4a4`](https://github.com/eternalcodes/EternalJK/commit/fea7b6aef4a4965f23855d122d90062042526402)<br>Fix mismatching case on basegame path/homepath on unix builds. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2023-11-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`596ae40cc9aa`](https://github.com/taysta/TaystJK/commit/596ae40cc9aa24600f282fdac79b79b2ebef0be0) · [PR #52](https://github.com/taysta/TaystJK/pull/52)<br>Merge pull request #52 from taysta/daggo-fs | Changed an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `medium` |
| `2023-12-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`9b57ee1b8566`](https://github.com/videoP/jaPRO/commit/9b57ee1b856693898de14daff824dcf111f94b57) · [PR #55](https://github.com/taysta/TaystJK/pull/55)<br>Japro update (#55) | Changed an exact bound cvar-variable reference. `codemp/game/g_account.c` | `high` |
| `2024-01-17` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`0da288606eb0`](https://github.com/taysta/TaystJK/commit/0da288606eb0ef10bc481321a3265faa0fdf1f71) · [PR #98](https://github.com/taysta/TaystJK/pull/98)<br>Make fs_forcegame and fs_basegame default to empty for dedicated servers. (#98) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`dbbea6b8a0bf`](https://github.com/taysta/TaystJK/commit/dbbea6b8a0bfb65a68e4e38c818bcfb0b49f929e) · [PR #31](https://github.com/taysta/TaystJK/pull/31)<br>Rename to TaystJK (#31) | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/files.cpp` | `high` |
| `2026-06-16` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`07c65a6f01a8`](https://github.com/taysta/TaystJK/commit/07c65a6f01a8023f2977bc1255f62a08d6154e3a) · [PR #341](https://github.com/taysta/TaystJK/pull/341)<br>Merge pull request #341 from taysta/basegame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/files.cpp` | `high` |

## Evidence

- registration: [codemp/qcommon/files.cpp:3919](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3919) (Cvar_Get)
- behavior: [codemp/qcommon/files.cpp:3753](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3753)
- behavior: [codemp/qcommon/files.cpp:3957](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3957)
- behavior: [codemp/qcommon/files.cpp:3989](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3989)
- behavior: [codemp/qcommon/files.cpp:3959](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3959)
- behavior: [codemp/qcommon/files.cpp:3962](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/files.cpp#L3962)
