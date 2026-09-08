---
title: "-force_drain"
layout: reference
nav_exclude: true
search_exclude: false
---

# `-force_drain`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Runs `IN_Button11Up` in the engine-client module.

## At a glance

| Field | Value |
|:--|:--|
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Syntax | `-force_drain` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_input.cpp:1071](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_input.cpp#L1071)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-10-31` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`e5ca528e414e`](https://github.com/JACoders/OpenJK/commit/e5ca528e414e72d777c54856f614654521cd8ebb)<br>[SP] Fix button binds for JK2 mode. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_input.cpp` | `medium` |
| `2014-03-09` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9f4c8a0ad7df`](https://github.com/JACoders/OpenJK/commit/9f4c8a0ad7dfc5a49bc57c6e1aee523c1450ce6e)<br>Got rid of com_jk2 since that's a separate executable now. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_input.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_input.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and the registered command handler. `codemp/client/cl_input.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_input.cpp:1748](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1748) (input command table)
- handler: [codemp/client/cl_input.cpp:788](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L788)
