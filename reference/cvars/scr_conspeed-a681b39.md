---
title: "scr_conspeed"
layout: reference
nav_exclude: true
search_exclude: false
---

# `scr_conspeed`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Console open/close speed

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `3` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Enforced ranges

- `1.0f` through `100.0f` (numeric; Cvar_CheckRange) — [codemp/client/cl_console.cpp:653](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L653)

## Flags

No cvar flags are registered at the cited site.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_console.cpp:232](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_console.cpp#L232)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2014-05-23` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`20c2b225b678`](https://github.com/JACoders/OpenJK/commit/20c2b225b678926eaeba443c1d3ff57b8fad7f58)<br>[MP] Clamp scr_conspeed to be in the range 1-100 | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dc224787253a`](https://github.com/eternalcodes/EternalJK/commit/dc224787253a97d7dad70f9404d52e6c86891ba3)<br>clanp con_scale as it can crash, comments | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f57cbc3056a9`](https://github.com/eternalcodes/EternalJK/commit/f57cbc3056a9b8aa7cfefc66a972afb433468348)<br>ops | Changed an exact bound cvar-variable reference. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:652](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L652) (Cvar_Get)
- behavior: [codemp/client/cl_console.cpp:1251](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1251)
- behavior: [codemp/client/cl_console.cpp:1258](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L1258)
- behavior: [codemp/client/cl_console.cpp:653](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_console.cpp#L653)
