---
title: "cg_smoothClients"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_smoothClients`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_smoothClients` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `2` | Selects the code path tested for value 2. | [codemp/cgame/cg_ents.c:3935](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L3935) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:1032](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L1032)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2017-12-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`668821b03696`](https://github.com/eternalcodes/EternalJK/commit/668821b03696231dfcf06b1805102a776c1d7efe)<br>Merge remote-tracking branch 'origin/master' | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_xcvar.h` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_players.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2019-04-11` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`67b4932f35a5`](https://github.com/videoP/jaPRO/commit/67b4932f35a5fd4c9ff1f779c354e5f5c3d40e02)<br>Significantly improve jaPRO cgame performance | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `high` |
| `2019-05-05` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`67ac04f76a68`](https://github.com/eternalcodes/EternalJK/commit/67ac04f76a682be7339ccf70f831761e2daea376)<br>Refactor/cleanup cgame side server mod detection. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_players.c` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`848ce21a29dd`](https://github.com/taysta/TaystJK/commit/848ce21a29dde392d2be2e9289d061f38428b193)<br>Bucky's cg_smoothclients fix | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2023-09-25` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`e526df4c373c`](https://github.com/taysta/TaystJK/commit/e526df4c373c36a289fd3f6b03aa0a7ef53fc829)<br>Other part of smoothclients fix | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |
| `2023-12-14` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`0bf81a8695ce`](https://github.com/videoP/jaPRO/commit/0bf81a8695ceaa3768496dfd4fe4e3a157016086)<br>Since jaPRO added MV_OCPM and MV_TRIBES after MV_COOP_JKA, we have to shuffle some things around. MV_COOP was originally designed to support multiple additional physics than just jka, but this never panned out. Need to revert this change if that design ever makes a comeback. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `high` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_ents.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:351](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L351) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_ents.c:3598](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L3598)
- behavior: [codemp/cgame/cg_ents.c:3935](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L3935)
- behavior: [codemp/cgame/cg_players.c:10379](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L10379)
- behavior: [codemp/cgame/cg_ents.c:3525](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L3525)
- behavior: [codemp/cgame/cg_ents.c:3597](https://github.com/taysta/TaystJK/blob/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_ents.c#L3597)
