---
title: "cl_timeNudge"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_timeNudge`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_timeNudge` in the engine-client module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `cgame`, `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/cgame/cg_view.c:2627](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2627) |
| `1` | Enabled. | [codemp/cgame/cg_view.c:2627](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2627) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_TEMP` — temporary and not archived

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `engine-client` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_main.cpp:1218](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_main.cpp#L1218)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c`, `codemp/cgame/cg_view.c`, `codemp/cgame/cg_weapons.c` and 1 more | `high` |
| `2018-09-20` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`05fb3fc73fab`](https://github.com/eternalcodes/EternalJK/commit/05fb3fc73fab789f7673a9c3dcddd4b7a90ec609)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c` | `medium` |
| `2023-12-29` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`06c84155e1fb`](https://github.com/videoP/jaPRO/commit/06c84155e1fb0b3aecfdffd9488d910345d80ea1) · [PR #65](https://github.com/taysta/TaystJK/pull/65)<br>Japro fixup (#65) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c` | `high` |
| `2026-06-18` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`3828aac1b69f`](https://github.com/videoP/jaPRO/commit/3828aac1b69fa980be675d9455cf58a61e3cfe9f) · [PR #344](https://github.com/taysta/TaystJK/pull/344)<br>Merge pull request #344 from taysta/predict-knockback | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_localents.c` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:201](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L201) (XCVAR_DEF)
- registration: [codemp/client/cl_main.cpp:3320](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L3320) (Cvar_Get)
- behavior: [codemp/cgame/cg_view.c:2627](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2627)
- behavior: [codemp/client/cl_cgame.cpp:988](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L988)
- behavior: [codemp/cgame/cg_weapons.c:2440](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L2440)
- behavior: [codemp/cgame/cg_view.c:2607](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2607)
- behavior: [codemp/cgame/cg_localents.c:1030](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_localents.c#L1030)
