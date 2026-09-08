---
title: "net_socksPort"
layout: reference
nav_exclude: true
search_exclude: false
---

# `net_socksPort`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `net_socksPort` in the engine-shared module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-shared` |
| Also registered in | `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `1080` |
| Value type | `int` |
| Restart | Yes; the value is latched. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE_ND` — saved to configuration without marking the cvar as user-created
- `CVAR_LATCH` — latched until the relevant subsystem or map is restarted

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/win32/win_net.cpp:1055](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/win32/win_net.cpp#L1055)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-01-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cd5d3753f0a7`](https://github.com/JACoders/OpenJK/commit/cd5d3753f0a75b3cde603080fb770a600540e13c)<br>[MP] Removed net_noudp in favor of net_enabled. Currently only 0 or 1, but it will be supported via bitmask later. Some other minor cleanups and merges from ioq3 in net_ip. | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_ip.cpp` | `medium` |
| `2016-07-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cd9a5be34933`](https://github.com/taysta/TaystJK/commit/cd9a5be349338ea7df597fde50116ff9b976e7d0)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed an exact bound cvar-variable reference. `codemp/qcommon/net_ip.cpp` | `medium` |
| `2017-08-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`913e3cc57ec7`](https://github.com/taysta/TaystJK/commit/913e3cc57ec761400db576456e91d71e70a2485f)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK.git | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/net_ip.cpp` | `medium` |

## Evidence

- registration: [codemp/qcommon/net_ip.cpp:898](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L898) (Cvar_Get)
- behavior: [codemp/qcommon/net_ip.cpp:533](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L533)
- behavior: [codemp/qcommon/net_ip.cpp:899](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L899)
- behavior: [codemp/qcommon/net_ip.cpp:900](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/net_ip.cpp#L900)
