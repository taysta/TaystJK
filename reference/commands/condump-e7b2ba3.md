---
title: "condump"
layout: reference
nav_exclude: true
search_exclude: false
---

# `condump`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Dump console text to file

## At a glance

| Field | Value |
|:--|:--|
| Category | Engine & diagnostics |
| Module | `engine-client` |
| Also registered in | `engine-client` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | No |
| Syntax | `condump [arguments]` |
| Cheat protected | No |

## Arguments and gating

No verified argument schema is available beyond the syntax shown above.

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/client/cl_console.cpp:245](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/client/cl_console.cpp#L245)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`161629e057eb`](https://github.com/JACoders/OpenJK/commit/161629e057ebdb2b071f193369817ab0dc35ea93)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed the registered command handler. `codemp/client/cl_console.cpp` | `high` |
| `2013-07-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`592b50aa3337`](https://github.com/JACoders/OpenJK/commit/592b50aa3337485dd743f5bd9438067746f227e6)<br>Fixed critical memory leak in Con_Dump_f. Moved success message in Con_Dump_f after opening of file. | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2013-08-15` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`55c2d54b3409`](https://github.com/JACoders/OpenJK/commit/55c2d54b34097448d9e5c8d8a62bcb35fe00391f)<br>Major improvements to command completion | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2013-11-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`ef124fd0fc48`](https://github.com/JACoders/OpenJK/commit/ef124fd0fc48af164581176a8f7901bf70c1aee2)<br>[MP] Don't allow condump with extensions besides .txt | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2014-01-30` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d3a6d2b9b9d2`](https://github.com/JACoders/OpenJK/commit/d3a6d2b9b9d2e967676dc2c9f738254b54524ab2)<br>[MP] Style: remove superfluous whitespace | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/client/cl_console.cpp` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/client/cl_console.cpp` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-jk2mv">JK2MV</span> | [`61b1b328accf`](https://github.com/taysta/TaystJK/commit/61b1b328accf2f186b1f97d363b3888873f9dbe3) · [PR #155](https://github.com/taysta/TaystJK/pull/155)<br>qol_console (#155) | Changed the registered command handler. `codemp/client/cl_console.cpp` | `medium` |

## Evidence

- registration: [codemp/client/cl_console.cpp:684](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L684) (Cmd_AddCommand)
- handler: [codemp/client/cl_console.cpp:345](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/cl_console.cpp#L345)
