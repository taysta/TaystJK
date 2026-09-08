---
title: "g_restarted"
layout: reference
nav_exclude: true
search_exclude: false
---

# `g_restarted`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `g_restarted` in the game module. Consult the cited behavior reads before relying on values not listed here.

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_spawn.c:1560](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_spawn.c#L1560) |
| `1` | Enabled. | [codemp/game/g_spawn.c:1560](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_spawn.c#L1560) |

## Flags

- `CVAR_ROM` — read-only after registration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:242](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L242)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_main.c`, `codemp/game/g_xcvar.h` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c`, `codemp/game/g_spawn.c` | `medium` |
| `2014-08-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1abe445436b3`](https://github.com/JACoders/OpenJK/commit/1abe445436b322514c79e73269108e80a2de376f)<br>[MP] Force some cvars to update immediately. | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `medium` |
| `2014-12-22` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`1d3fdf37e955`](https://github.com/JACoders/OpenJK/commit/1d3fdf37e9553ec6a14b38bc3e6d82459a322b2d)<br>[MP] Update g_gravity and g_restarted immediately in SP_worldspawn.  Remove cvar set of "g_enableBreath", because it isn't used. | Changed an exact bound cvar-variable reference. `codemp/game/g_spawn.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:130](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L130) (XCVAR_DEF)
- behavior: [codemp/game/g_spawn.c:1560](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_spawn.c#L1560)
- behavior: [codemp/game/g_main.c:2760](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L2760)
- behavior: [codemp/game/g_main.c:2934](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L2934)
- behavior: [codemp/game/g_spawn.c:1561](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_spawn.c#L1561)
